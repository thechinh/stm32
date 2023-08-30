#ifndef __DS1307_H__
#define __DS1307_H__

#include "stm32f4xx_hal.h"

#define DS1307_ADDRESS 0x68 << 1
#define DS1307_REG_TIME 0x00

typedef struct {
  uint8_t seconds;
  uint8_t minutes;
  uint8_t hours;
  uint8_t day;
  uint8_t date;
  uint8_t month;
  uint8_t year;
  uint8_t mode12h;
  uint8_t pm;
} DS1307_Time_t;

uint8_t bcd2dec(uint8_t bcd);
uint8_t dec2bcd(uint8_t dec);

void DS1307_ReadTime(I2C_HandleTypeDef* hi2c, DS1307_Time_t *time);
int DS1307_WriteTime(I2C_HandleTypeDef* hi2c, DS1307_Time_t *time);

#endif // __DS1307_H__