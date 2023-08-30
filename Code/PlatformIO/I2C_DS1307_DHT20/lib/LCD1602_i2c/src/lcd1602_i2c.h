#ifndef __LCD1602_I2C_H__
#define __LCD1602_I2C_H__

#include "stm32f4xx_hal.h"

#define SLAVE_ADDRESS_LCD 0x21 << 1     // Ohstem, otherwise 0x27 << 1 or 0x3F << 1

void I2C_Scan(void); // scan i2c bus

void lcd_init(void); // initialize lcd

void lcd_send_cmd(char cmd);  // send command to the lcd

void lcd_send_data(char data);  // send data to the lcd

void lcd_send_string(char *str);  // send string to the lcd

void lcd_clear_display(void);	//clear display lcd

void lcd_goto_XY(int row, int col); //set proper location on screen

#endif // __LCD1602_I2C_H__