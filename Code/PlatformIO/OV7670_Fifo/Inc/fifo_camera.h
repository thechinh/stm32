#ifndef __FIFO_CAMERA_H__
#define __FIFO_CAMERA_H__

#include "stm32f4xx_hal.h"

void Camera_Init();
void Camera_Test_Image();
void Camera_Prepare_Capture();
void Camera_Start_Capture();
void Camera_Stop_Capture();
void Camera_Read_Frame(uint8_t *frame, const uint16_t xres, const uint16_t yres, const uint8_t bytes_per_pixel);
void Camera_Read_Frame_Only_Second_Byte(uint8_t *frame, const uint16_t xres, const uint16_t yres);
void Camera_QQVGARGB565();

#endif