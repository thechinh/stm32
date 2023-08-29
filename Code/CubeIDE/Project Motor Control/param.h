#include <33EP128GM306.h>
#include <P33EP128GM306_registers.h>

#FUSES NOWDT                    //No Watch Dog Timer
#FUSES NOJTAG                   //JTAG disabled
#FUSES CKSFSM                   //Clock Switching is enabled, fail Safe clock monitor is enabled
#FUSES HS
#FUSES PR_PLL
#FUSES PROTECT                   // Code protect from read
///////////
#device ICSP=1
#use delay (clock = 48000000)

#use FIXED_IO(A_outputs=PIN_A7)
#use FIXED_IO(D_outputs=PIN_D8)
#use STANDARD_IO(F)

#pin_select QEA1=PIN_D6
#pin_select QEB1=PIN_C9

#pin_select QEA2=PIN_B5
#pin_select QEB2=PIN_B6

//#use rs232(UART2, baud=9600, stream=UART_PORT2)
#use spi(MASTER, CLK=PIN_F1, DI=PIN_G9, DO=PIN_B10, MODE=0, BITS=16, ENABLE=PIN_B11, MSB_FIRST, stream=SPI_PORT1)

#define Device_SDA PIN_A8
#define Device_SLC PIN_B4
  
#use I2C(MASTER,I2C2, FAST = 400000, NOINIT)
#pin_select INT1 = PIN_F0



 



