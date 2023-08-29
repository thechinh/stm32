#ifndef __DHT20_H__
#define __DHT20_H__

#include "stm32f4xx_hal.h"

#define DHT20_ADDR 0x38 << 1

typedef struct {
  float humidity;
  float temperature;
} DHT20_Data_t;

int DHT20_Init(I2C_HandleTypeDef* hi2c);
DHT20_Data_t DHT20_ReadData(I2C_HandleTypeDef* hi2c);


#endif // __DHT20_H__