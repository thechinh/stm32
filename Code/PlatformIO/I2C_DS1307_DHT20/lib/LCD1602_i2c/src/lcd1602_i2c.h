#ifndef __LCD1602_I2C_H__
#define __LCD1602_I2C_H__

#include "stm32f4xx_hal.h"

void I2C_Scan(UART_HandleTypeDef* huart);
void lcd_init(I2C_HandleTypeDef* hi2c1_param, uint8_t slave_address_lcd); // initialize lcd
void lcd_send_cmd(char cmd);  // send command to the lcd
void lcd_send_data(char data);  // send data to the lcd
void lcd_send_string(char *str);  // send string to the lcd
void lcd_clear_display(void);	//clear display lcd
void lcd_goto_XY(int row, int col); //set proper location on screen

#endif // __LCD1602_I2C_H__