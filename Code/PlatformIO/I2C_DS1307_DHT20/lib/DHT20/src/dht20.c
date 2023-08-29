#include "dht20.h"
#include "stm32f4xx_hal.h"
#include "stm32f4xx_hal_i2c.h"

int DHT20_Init(I2C_HandleTypeDef* hi2c) {
  HAL_Delay(100); // Wait for DHT20 to start up
  
  // Step 1: Check status register
  uint8_t status;
  HAL_I2C_Mem_Read(hi2c, DHT20_ADDR, (uint16_t)0x71, I2C_MEMADD_SIZE_8BIT, &status, 1, 100);
  
  if ((status & 0x18) == 0x18) {
    return HAL_OK;
  }
  else {  
    // Initialize 0x1B, 0x1C, 0x1E registers
    return HAL_ERROR;
  }
}

DHT20_Data_t DHT20_ReadData(I2C_HandleTypeDef* hi2c) {
    DHT20_Data_t dht20_data = {0, 0};
    
    // Step 2: Trigger measurement
    HAL_Delay(10);
    uint8_t data[3];
    data[0] = 0xAC;
    data[1] = 0x33;
    data[2] = 0x00;
    HAL_I2C_Master_Transmit(hi2c, DHT20_ADDR, data, 3, 100);

    // Step 3: Wait for measurement to finish. If the status register bit 7 is 0, measurement is done
    HAL_Delay(80);
    uint8_t buffer[7];
    uint32_t tmp = 0;

    HAL_I2C_Master_Receive(hi2c, DHT20_ADDR, buffer, 7, 100);  
    if ((buffer[0] & 0b10000000) == 0) {
      // Step 4: Check CRC (skipped)
      
      // Step 5: Calculate humidity and temperature
      // Humidity
      tmp = buffer[1];
      tmp = tmp << 8;
      tmp += buffer[2];
      tmp = tmp << 8;
      tmp += buffer[3];
      tmp = tmp >> 4;
      // tmp = ((tmp | buffer[1]) << 12) | ((tmp | buffer[2]) << 4) | ((tmp | buffer[3]) >> 4); // another way to do it
      dht20_data.humidity = (float)tmp*100/1048576;

      // Temperature
      tmp = buffer[3] & 0x0F;
      tmp = tmp << 8;
      tmp += buffer[4];
      tmp = tmp << 8;
      tmp += buffer[5];
      dht20_data.temperature = (float)tmp*200/1048576 - 50;
    }
    else {
      // not ready
    //   sprintf(debug_msg, "Not ready\r\n");
    //   HAL_UART_Transmit(&huart2, (uint8_t *)debug_msg, strlen(debug_msg), 100);
    }
  
  return dht20_data;
}