/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main progrpm body
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
#include "i2c.h"
#include "i2s.h"
#include "spi.h"
#include "usart.h"
#include "usb_host.h"
#include "gpio.h"
#include <stdio.h>
#include <string.h>

/* Private includes ----------------------------------------------------------*/
#include "ds1307.h"
#include "dht20.h"
#include "lcd1602_i2c.h"

/* Private typedef -----------------------------------------------------------*/

/* Private define ------------------------------------------------------------*/
// CONFIGURATION
#define SLAVE_ADDRESS_LCD 0x21 << 1     // Ohstem PCF8574T with AO=1, A1=0, A2=0 => 0x21. By default, the address is 0x27
#define SET_TIME 0                      // Set time to DS1307
#define DISPLAY 1                       // UART = 0, LCD = 1

/* Private macro -------------------------------------------------------------*/

/* Private variables ---------------------------------------------------------*/
DS1307_Time_t time;
const char weekday[7][10] = {"Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"};
DHT20_Data_t dht20_data;
char debug_msg[50] = {};

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
void PeriphCommonClock_Config(void);
void MX_USB_HOST_Process(void);

/* Private user code ---------------------------------------------------------*/

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
  MX_I2C1_Init();
  MX_I2S2_Init();
  MX_I2S3_Init();
  MX_SPI1_Init();
  MX_USB_HOST_Init();
  MX_USART2_UART_Init();

  /* USER CODE BEGIN 2 */
  #if SET_TIME == 1
    // Change time here
    time.year = 23;
    time.month = 8;
    time.date = 30;
    time.day = 4;
    time.hours = 6;
    time.minutes = 33;
    time.seconds = 40;
    time.mode12h = 1;
    time.pm = 1;
    
    // Write time to DS1307
    if (DS1307_WriteTime(&hi2c1, &time) == -1) {
      char error[] = "Error: Invalid time\r\n";
      HAL_UART_Transmit(&huart2, (uint8_t *)error, strlen(error), 100);
      return -1;
    }
  #endif

  int ret = DHT20_Init(&hi2c1);
  if (ret == HAL_ERROR)
    return -1;

  #if DISPLAY == 1 // LCD
    char msg[16];
    lcd_init(&hi2c1, SLAVE_ADDRESS_LCD);
  #endif

  /* USER CODE END 2 */

  /* Infinite loop */
  while (1)
  {
    MX_USB_HOST_Process();

    // DHT20
    dht20_data = DHT20_ReadData(&hi2c1);

    // DS1307
    DS1307_ReadTime(&hi2c1, &time);
    
    // Convert to string for printing only
    char hum_str[10];
    uint8_t hum_int = (uint8_t)dht20_data.humidity;
    uint8_t hum_dec = (uint8_t)((dht20_data.humidity - hum_int)*10);
    sprintf(hum_str, "%d.%1d", hum_int, hum_dec);
    char temp_str[10];
    uint8_t temp_int = (uint8_t)dht20_data.temperature;
    uint8_t temp_dec = (uint8_t)((dht20_data.temperature - temp_int)*10);
    sprintf(temp_str, "%d.%1d", temp_int, temp_dec);
    
    // #if DISPLAY == 0
      char uart_msg[80];
      sprintf(uart_msg, "%s %02d/%02d/20%02d - Time: %02d:%02d:%02d %s || Humidity: %s%% - Temperature: %soC \r\n", 
        weekday[time.day-1] ,time.date, time.month, time.year, time.hours, time.minutes, time.seconds, (time.mode12h)==1 ? ((time.pm == 1) ? "pm" : "am") : "", hum_str, temp_str);
      HAL_UART_Transmit(&huart2, (uint8_t *)uart_msg, strlen(uart_msg), 100);
    // #else
      lcd_goto_XY(0, 0);
      // sprintf(msg, "%s %02d/%02d/%02d", weekday[time.day-1] ,time.date, time.month, time.year);
      sprintf(msg, "%02d/%01d  %02d:%02d:%02d%s", time.date, time.month, time.hours, time.minutes, time.seconds, (time.mode12h)==1 ? ((time.pm == 1) ? "pm" : "am") : "");
      lcd_send_string(msg);
      lcd_goto_XY(1, 0);
      sprintf(msg, "%s%% %soC", hum_str, temp_str);
      lcd_send_string(msg);
    // #endif
    
    HAL_GPIO_TogglePin(LD3_GPIO_Port, LD3_Pin); // Heartbeat decoration
    HAL_Delay(1000);
  }
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

  /** Initializes the RCC Oscillators according to the specified parpmeters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_ON;
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
  * @brief  Reports the npme of the source file and the source line number
  *         where the assert_parpm error has occurred.
  * @parpm  file: pointer to the source file npme
  * @parpm  line: assert_parpm error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file npme and line number,
     ex: printf("Wrong parpmeters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */
