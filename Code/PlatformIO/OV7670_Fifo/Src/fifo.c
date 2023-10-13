#include "fifo.h"
#include "main.h"

void Fifo_Init() {
    HAL_GPIO_WritePin(WR_GPIO_Port, WR_Pin, GPIO_PIN_SET);
    HAL_GPIO_WritePin(RRST_GPIO_Port, RRST_Pin, GPIO_PIN_SET);
    HAL_GPIO_WritePin(WRST_GPIO_Port, WRST_Pin, GPIO_PIN_SET);
}

void Fifo_Read_Reset() {
    HAL_GPIO_WritePin(RRST_GPIO_Port, RRST_Pin, GPIO_PIN_RESET);
    HAL_Delay_us(1);
    HAL_GPIO_WritePin(RCK_GPIO_Port, RCK_Pin, GPIO_PIN_RESET);
    HAL_Delay_us(1);
    HAL_GPIO_WritePin(RCK_GPIO_Port, RCK_Pin, GPIO_PIN_SET);
    HAL_Delay_us(1);
    HAL_GPIO_WritePin(RRST_GPIO_Port, RRST_Pin, GPIO_PIN_SET);
}

void Fifo_Write_Reset() {
    HAL_GPIO_WritePin(WRST_GPIO_Port, WRST_Pin, GPIO_PIN_RESET);
    HAL_Delay_us(1);
    // HAL_GPIO_WritePin(WCK_GPIO_Port, WCK_Pin, GPIO_PIN_RESET);
    // HAL_Delay_us(1);
    // HAL_GPIO_WritePin(WCK_GPIO_Port, WCK_Pin, GPIO_PIN_SET);
    // HAL_Delay_us(1);
    HAL_GPIO_WritePin(WRST_GPIO_Port, WRST_Pin, GPIO_PIN_SET);
}

void Fifo_Write_Enable() {
    HAL_GPIO_WritePin(WR_GPIO_Port, WR_Pin, GPIO_PIN_RESET);
}

void Fifo_Write_Disable() {
    HAL_GPIO_WritePin(WR_GPIO_Port, WR_Pin, GPIO_PIN_SET);
}

uint8_t Fifo_Read_Byte() {
    HAL_GPIO_WritePin(RCK_GPIO_Port, RCK_Pin, GPIO_PIN_SET);
    // read D0-D7 (PA1-PA8)
    // uint8_t data = HAL_GPIO_ReadPin(D0_GPIO_Port, D0_Pin) |
    //                HAL_GPIO_ReadPin(D1_GPIO_Port, D1_Pin) << 1 |
    //                HAL_GPIO_ReadPin(D2_GPIO_Port, D2_Pin) << 2 |
    //                HAL_GPIO_ReadPin(D3_GPIO_Port, D3_Pin) << 3 |
    //                HAL_GPIO_ReadPin(D4_GPIO_Port, D4_Pin) << 4 |
    //                HAL_GPIO_ReadPin(D5_GPIO_Port, D5_Pin) << 5 |
    //                HAL_GPIO_ReadPin(D6_GPIO_Port, D6_Pin) << 6 |
    //                HAL_GPIO_ReadPin(D7_GPIO_Port, D7_Pin) << 7;
    // alternatively, read whole port A then right shift 1 and save the first byte only
    uint8_t data = (uint8_t)((D0_GPIO_Port->IDR >> 1) & 0xFF);

    HAL_GPIO_WritePin(RCK_GPIO_Port, RCK_Pin, GPIO_PIN_RESET);
    return data;
}

void Fifo_Read_Bytes(uint8_t *buffer, uint8_t length) {
    for (uint8_t i = 0; i < length; i++) {
        buffer[i] = Fifo_Read_Byte();
    }
}

// void Fifo_Skip_Byte() {
//     HAL_GPIO_WritePin(RCK_GPIO_Port, RCK_Pin, GPIO_PIN_SET);
//     HAL_GPIO_WritePin(RCK_GPIO_Port, RCK_Pin, GPIO_PIN_SET); // just for delay
//     HAL_GPIO_WritePin(RCK_GPIO_Port, RCK_Pin, GPIO_PIN_RESET);
//     HAL_GPIO_WritePin(RCK_GPIO_Port, RCK_Pin, GPIO_PIN_RESET); // needed if more skips in a row
// }