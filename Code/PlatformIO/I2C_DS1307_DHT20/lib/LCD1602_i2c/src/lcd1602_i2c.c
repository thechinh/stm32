#include "lcd1602_i2c.h"
#include <string.h>
#include <stdio.h>

extern I2C_HandleTypeDef hi2c1;

extern UART_HandleTypeDef huart2;

void I2C_Scan() {
    char info[] = "Scanning I2C bus...\r\n";
    HAL_UART_Transmit(&huart2, (uint8_t*)info, strlen(info), HAL_MAX_DELAY);

    HAL_StatusTypeDef res;
    for(uint16_t i = 0; i < 128; i++) {
        res = HAL_I2C_IsDeviceReady(&hi2c1, i << 1, 1, 10);
        if(res == HAL_OK) {
            char msg[64];
            snprintf(msg, sizeof(msg), "0x%02X", i);
            HAL_UART_Transmit(&huart2, (uint8_t*)msg, strlen(msg), HAL_MAX_DELAY);
        } else {
            HAL_UART_Transmit(&huart2, (uint8_t*)".", 1, HAL_MAX_DELAY);
        }
    }

    HAL_UART_Transmit(&huart2, (uint8_t*)"\r\n", 2, HAL_MAX_DELAY);
}

void lcd_send_cmd (char cmd)
{
  char data_u, data_l;
	uint8_t data_t[4];
	data_u = (cmd&0xf0);
	data_l = ((cmd<<4)&0xf0);
	data_t[0] = data_u|0x0C;  //en=1, rs=0
	data_t[1] = data_u|0x08;  //en=0, rs=0
	data_t[2] = data_l|0x0C;  //en=1, rs=0
	data_t[3] = data_l|0x08;  //en=0, rs=0
	HAL_I2C_Master_Transmit (&hi2c1, SLAVE_ADDRESS_LCD,(uint8_t *) data_t, 4, 100);
}

void lcd_send_data (char data)
{
	char data_u, data_l;
	uint8_t data_t[4];
	data_u = (data&0xf0);
	data_l = ((data<<4)&0xf0);
	data_t[0] = data_u|0x0D;  //en=1, rs=0
	data_t[1] = data_u|0x09;  //en=0, rs=0
	data_t[2] = data_l|0x0D;  //en=1, rs=0
	data_t[3] = data_l|0x09;  //en=0, rs=0
	HAL_I2C_Master_Transmit (&hi2c1, SLAVE_ADDRESS_LCD,(uint8_t *) data_t, 4, 100);
}

void lcd_init (void)
{
	lcd_send_cmd (0x33); /* set 4-bits interface */
	lcd_send_cmd (0x32);
	HAL_Delay(50);
	lcd_send_cmd (0x28); /* start to set LCD function */
	HAL_Delay(50);
	lcd_send_cmd (0x01); /* clear display */
	HAL_Delay(50);
	lcd_send_cmd (0x06); /* set entry mode */
	HAL_Delay(50);
	lcd_send_cmd (0x0c); /* set display to on */	
	HAL_Delay(50);
	lcd_send_cmd (0x02); /* move cursor to home and set data address to 0 */
	HAL_Delay(50);
	lcd_send_cmd (0x80);
}

void lcd_send_string (char *str)
{
	while (*str) lcd_send_data (*str++);
}

void lcd_clear_display (void)
{
	lcd_send_cmd (0x01); //clear display
}

void lcd_goto_XY (int row, int col)
{
	uint8_t pos_Addr;
	row = row + 1;
	
	if(row == 1) 
	{
		pos_Addr = 0x80 + row - 1 + col;
	}
	else
	{
		pos_Addr = 0x80 | (0x40 + col);
	}
	lcd_send_cmd(pos_Addr);
}
