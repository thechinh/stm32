/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2023 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "dma.h"
#include "i2c.h"
#include "i2s.h"
#include "rtc.h"
#include "spi.h"
#include "usb_host.h"
#include "gpio.h"
#include "usart.h"
#include <stdio.h>
#include <string.h>

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
#define SET_TIME 0
#define UART_BUFFER_SIZE 30
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */
RTC_DateTypeDef sDate;
RTC_TimeTypeDef sTime;
RTC_AlarmTypeDef sAlarm;
char debug_msg[50];

unsigned char rxByte = 0;
char rxBuffer[UART_BUFFER_SIZE] = {0};
uint16_t rxSize = 0;
int alarm_repeat = 0;

const char weekdayTable[7][4] = {"MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"};
/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
void PeriphCommonClock_Config(void);
void MX_USB_HOST_Process(void);

/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

// Alarm A callback
void HAL_RTC_AlarmAEventCallback(RTC_HandleTypeDef *hrtc)
{
  HAL_GPIO_TogglePin(LD3_GPIO_Port, LD3_Pin);
  sprintf(debug_msg, "Alarm triggered! \r\n");
  HAL_UART_Transmit(&huart2, (uint8_t*)debug_msg, strlen(debug_msg), 100);
  
  if (alarm_repeat == 0) {
    // Disable alarm
    HAL_RTC_DeactivateAlarm(hrtc, RTC_ALARM_A);
  }
}

// UART IDLE Rx callback
void HAL_UARTEx_RxEventCallback(UART_HandleTypeDef *huart, uint16_t Size) {
  char time[9];
  char weekday[4];
  char repeat[7];
  uint8_t date, month, year;

  HAL_UARTEx_ReceiveToIdle_DMA(&huart2, (uint8_t *)rxBuffer, UART_BUFFER_SIZE);
  rxSize = Size;

  // Parse command. Format: "SET_TIME 19:20:00" or "SET_DATE 10/09/23 SUN" or "SET_ALARM 10:15:15 repeat SAT MON|TUE|WED|THU|FRI|SAT|SUN"
  if (strncmp(rxBuffer, "SET_TIME", 8) == 0) {
    if (sscanf(rxBuffer, "SET_TIME %d:%d:%d", &sTime.Hours, &sTime.Minutes, &sTime.Seconds) == 3) {
      HAL_RTC_SetTime(&hrtc, &sTime, RTC_FORMAT_BIN);
    }
  }
  else if (strncmp(rxBuffer, "SET_DATE", 8) == 0) {      
    if (sscanf(rxBuffer, "SET_DATE %d/%d/%d %3s", &date, &month, &year, weekday) == 4) { // %hhu for uint8_t doesn't work
      for (int i = 0; i < 7; i++) {
        if (strncmp(weekday, weekdayTable[i], 3) == 0) {
          sDate.WeekDay = i + 1;
        }
      }
      sDate.Date = date;
      sDate.Month = month;
      sDate.Year = year;

      HAL_RTC_SetDate(&hrtc, &sDate, RTC_FORMAT_BIN);
    }

  }
  else if (strncmp(rxBuffer, "SET_ALARM", 9) == 0) {
    int parsed = sscanf(rxBuffer, "SET_ALARM %s %s %s", time, repeat, weekday);

    if (parsed >= 1) {
      sscanf(time, "%u:%u:%u", &sAlarm.AlarmTime.Hours, &sAlarm.AlarmTime.Minutes, &sAlarm.AlarmTime.Seconds);
      
      // Time + repeat
      if (parsed >= 3 && strncmp(repeat, "repeat", 6) == 0) {
        
        for (int i = 0; i < 7; i++) {
          if (strncmp(weekday, weekdayTable[i], 3) == 0) {
            sAlarm.AlarmDateWeekDay = i + 1;
            break;
          }
        }
        alarm_repeat = 1;
        // TODO: handle invalid weekday
      } 
      else {
        // Time only, no repeat. Alarm will be triggered once at the next time match
        // if current time is sooner than alarm time, set alarm date to today, otherwise set to tomorrow
        if (sTime.Hours < sAlarm.AlarmTime.Hours || (sTime.Hours == sAlarm.AlarmTime.Hours && sTime.Minutes < sAlarm.AlarmTime.Minutes) || (sTime.Hours == sAlarm.AlarmTime.Hours && sTime.Minutes == sAlarm.AlarmTime.Minutes && sTime.Seconds < sAlarm.AlarmTime.Seconds)) {
          sAlarm.AlarmDateWeekDay = sDate.WeekDay;
        }
        else {
          sAlarm.AlarmDateWeekDay = sDate.WeekDay + 1;
          if (sAlarm.AlarmDateWeekDay > 7) {
            sAlarm.AlarmDateWeekDay = 1;
          }
        }
        alarm_repeat = 0;
      }
    }

    // Default values
    sAlarm.Alarm = RTC_ALARM_A;
    sAlarm.AlarmTime.DayLightSaving = RTC_DAYLIGHTSAVING_NONE;
    sAlarm.AlarmTime.StoreOperation = RTC_STOREOPERATION_RESET;      
    sAlarm.AlarmDateWeekDaySel = RTC_ALARMDATEWEEKDAYSEL_WEEKDAY;
    HAL_RTC_SetAlarm_IT(&hrtc, &sAlarm, RTC_FORMAT_BIN);

    sprintf(debug_msg, "OK - Alarm is set. \r\n");
    HAL_UART_Transmit(&huart2, (uint8_t*)debug_msg, strlen(debug_msg), 100);
  }

  HAL_UART_Receive_IT(&huart2, &rxByte, 1);
}

/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

/* Configure the peripherals common clocks */
  PeriphCommonClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_DMA_Init();
  MX_I2C1_Init();
  MX_I2S2_Init();
  MX_I2S3_Init();
  MX_SPI1_Init();
  MX_USB_HOST_Init();
  MX_RTC_Init();
  MX_USART2_UART_Init();
  /* USER CODE BEGIN 2 */
  HAL_UARTEx_ReceiveToIdle_DMA(&huart2, (uint8_t *)rxBuffer, UART_BUFFER_SIZE);
  __HAL_DMA_DISABLE_IT(&hdma_usart2_rx, DMA_IT_HT); // Disable half-transfer interrupt
  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
    /* USER CODE END WHILE */
    MX_USB_HOST_Process();

    HAL_RTC_GetTime(&hrtc, &sTime, RTC_FORMAT_BIN);
    HAL_RTC_GetDate(&hrtc, &sDate, RTC_FORMAT_BIN);
    sprintf(debug_msg, "%3s %02d/%02d/%02d %02d:%02d:%02d\r\n", weekdayTable[sDate.WeekDay-1], sDate.Date, sDate.Month, 2000 + sDate.Year, sTime.Hours, sTime.Minutes, sTime.Seconds);
    HAL_UART_Transmit(&huart2, (uint8_t*)debug_msg, strlen(debug_msg), 100);
    HAL_Delay(1000);

    /* USER CODE BEGIN 3 */
  }
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Configure the main internal regulator output voltage
  */
  __HAL_RCC_PWR_CLK_ENABLE();
  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE1);

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_LSI|RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_ON;
  RCC_OscInitStruct.LSIState = RCC_LSI_ON;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLM = 4;
  RCC_OscInitStruct.PLL.PLLN = 192;
  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV4;
  RCC_OscInitStruct.PLL.PLLQ = 8;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV4;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_3) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief Peripherals Common Clock Configuration
  * @retval None
  */
void PeriphCommonClock_Config(void)
{
  RCC_PeriphCLKInitTypeDef PeriphClkInitStruct = {0};

  /** Initializes the peripherals clock
  */
  PeriphClkInitStruct.PeriphClockSelection = RCC_PERIPHCLK_I2S;
  PeriphClkInitStruct.PLLI2S.PLLI2SN = 200;
  PeriphClkInitStruct.PLLI2S.PLLI2SM = 5;
  PeriphClkInitStruct.PLLI2S.PLLI2SR = 2;
  if (HAL_RCCEx_PeriphCLKConfig(&PeriphClkInitStruct) != HAL_OK)
  {
    Error_Handler();
  }
}

/* USER CODE BEGIN 4 */

/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */
