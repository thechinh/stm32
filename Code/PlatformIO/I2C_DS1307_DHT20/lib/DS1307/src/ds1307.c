#include "ds1307.h"


uint8_t bcd2dec(uint8_t bcd) {
  return (bcd >> 4) * 10 + (bcd & 0x0F);
}

uint8_t dec2bcd(uint8_t dec) {
  return ((dec/10)<<4 | (dec % 10));
}

void DS1307_ReadTime(I2C_HandleTypeDef* hi2c, DS1307_Time_t *time) {
  uint8_t data[7];
  HAL_I2C_Mem_Read(hi2c, DS1307_ADDRESS, DS1307_REG_TIME, I2C_MEMADD_SIZE_8BIT, data, 7, 100);
  time->seconds = bcd2dec(data[0]);
  time->minutes = bcd2dec(data[1]);
  
  time->mode12h = (data[2] & 0x40) >> 6;
  if (time->mode12h == 1) {
    time->hours = bcd2dec(data[2] & 0x1F);
    time->pm = (data[2] & 0x20) >> 5;
  } else {
    time->hours = bcd2dec(data[2] & 0x3F);
  }

  time->day = bcd2dec(data[3]);
  time->date = bcd2dec(data[4]);
  time->month = bcd2dec(data[5]);
  time->year = bcd2dec(data[6]);
}

int DS1307_WriteTime(I2C_HandleTypeDef* hi2c, DS1307_Time_t *time) {
  uint8_t data[7];
  data[0] = dec2bcd(time->seconds);
  data[1] = dec2bcd(time->minutes);
  
  if (time->mode12h == 1) {
      data[2] = dec2bcd(time->hours) | 0x40;
      if (time->pm == 1)
        data[2] |= 0x20;
  } 
  else {
    data[2] = dec2bcd(time->hours);
  }
  
  data[3] = dec2bcd(time->day);
  data[4] = dec2bcd(time->date);
  data[5] = dec2bcd(time->month);
  data[6] = dec2bcd(time->year);

  // Error checking
  if (time->month > 12 || time->date > 31 || time->day > 7 || time->year > 99) {
    return -1;
  }
  if (time->hours > 23 || time->minutes > 59 || time->seconds > 59) {
    return -1;
  }
    // 12h mode: hour must be between 1 and 12
  if (time->mode12h == 1 && (time->hours > 12 || time->hours == 0)) {
    return -1;
  }

  HAL_I2C_Mem_Write(hi2c, DS1307_ADDRESS, DS1307_REG_TIME, I2C_MEMADD_SIZE_8BIT, data, 7, 100);
  return 0;
}