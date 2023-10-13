#ifndef __FIFO_H__
#define __FIFO_H__

#include <stdint.h>

void Fifo_Init(void);
void Fifo_Read_Reset();
void Fifo_Write_Reset();
void Fifo_Write_Enable();
void Fifo_Write_Disable();
uint8_t Fifo_Read_Byte();
void Fifo_Read_Bytes(uint8_t *buffer, uint8_t length);
// void Fifo_Skip_Byte();

#endif // __FIFO_H__