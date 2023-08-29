//////////// Standard Header file for the DSPIC33EP128GM306 device ////////////////
///////////////////////////////////////////////////////////////////////////
////        (C) Copyright 1996, 2013 Custom Computer Services          ////
//// This source code may only be used by licensed users of the CCS C  ////
//// compiler.  This source code may only be distributed to other      ////
//// licensed users of the CCS C compiler.  No other use, reproduction ////
//// or distribution is permitted without written permission.          ////
//// Derivative programs created using this software in object code    ////
//// form are not restricted in any way.                               ////
///////////////////////////////////////////////////////////////////////////
#device DSPIC33EP128GM306

#nolist
//////// Program memory: 43766x24  Data RAM: 16384  Stack: 31
//////// I/O: 61   Analog s: 30
//////// Fuses: ICSP3,ICSP2,ICSP1,NOJTAG,JTAG,DEBUG,NODEBUG,CINA_ALT
//////// Fuses: T5G_IS_T5G,ALTI2C1,NOALTI2C1,ALTI2C2,NOALTI2C2,WDTWIN_75%
//////// Fuses: WDTWIN_50%,WDTWIN_37%,WDTWIN_25%,WPOSTS1,WPOSTS2,WPOSTS3
//////// Fuses: WPOSTS4,WPOSTS5,WPOSTS6,WPOSTS7,WPOSTS8,WPOSTS9,WPOSTS10
//////// Fuses: WPOSTS11,WPOSTS12,WPOSTS13,WPOSTS14,WPOSTS15,WPOSTS16
//////// Fuses: WPRES32,WPRES128,NOPLLWAIT,PLLWAIT,NOWINDIS,WINDIS,NOWDT,WDT
//////// Fuses: EC,XT,HS,NOPR,OSCIO,NOOSCIO,NOIOL1WAY,IOL1WAY,CKSFSM
//////// Fuses: CKSNOFSM,NOCKSNOFSM,FRC,FRC_PLL,PR,PR_PLL,LPRC,FRC_PS
//////// Fuses: NOPWMLOCK,PWMLOCK,NOIESO,IESO,WRT,NOWRT,PROTECT,NOPROTECT
//////// 
#if (!defined(__PCD__)||defined(__ISNT_CCS__))
#define _bif
#define int8 char
#define int16 int
#define int32 long
#define int48 long
#define int64 long long
#define float32 float
#define float48 float
#define float64 double
#define int1 char

#endif
////////////////////////////////////////////////////////////////// I/O
// Discrete I/O Functions: SET_TRIS_x(), OUTPUT_x(), INPUT_x(),
//                         SET_PULLUP(), INPUT(),
//                         OUTPUT_LOW(), OUTPUT_HIGH(),
//                         OUTPUT_FLOAT(), OUTPUT_BIT()
// Discrete I/O Prototypes:
_bif void set_tris_a(unsigned int16 value);  
_bif void set_tris_b(unsigned int16 value);  
_bif void set_tris_c(unsigned int16 value);  
_bif void set_tris_d(unsigned int16 value);  
_bif void set_tris_f(unsigned int16 value);  
_bif void set_tris_g(unsigned int16 value);  
_bif unsigned int16 get_tris_a(void);  
_bif unsigned int16 get_tris_b(void);  
_bif unsigned int16 get_tris_c(void);  
_bif unsigned int16 get_tris_d(void);  
_bif unsigned int16 get_tris_f(void);  
_bif unsigned int16 get_tris_g(void);  
_bif void output_a(unsigned int16 value);  
_bif void output_b(unsigned int16 value);  
_bif void output_c(unsigned int16 value);  
_bif void output_d(unsigned int16 value);  
_bif void output_f(unsigned int16 value);  
_bif void output_g(unsigned int16 value);  
_bif unsigned int16 input_a(void);  
_bif unsigned int16 input_b(void);  
_bif unsigned int16 input_c(void);  
_bif unsigned int16 input_d(void);  
_bif unsigned int16 input_f(void);  
_bif unsigned int16 input_g(void);  
_bif int1 input_change_a(void);  
_bif int1 input_change_b(void);  
_bif int1 input_change_c(void);  
_bif int1 input_change_d(void);  
_bif int1 input_change_f(void);  
_bif int1 input_change_g(void);  
_bif void set_pullup(int1 state);
_bif void set_pullup(int1 state, unsigned int16 pin);
_bif void set_pulldown(int1 state);
_bif void set_pulldown(int1 state, unsigned int16 pin);
_bif int1 input(unsigned int16 pin);
_bif int1 input_state(unsigned int16 pin);
_bif void output_low(unsigned int16 pin);
_bif void output_high(unsigned int16 pin);
_bif void output_toggle(unsigned int16 pin);
_bif void output_bit(unsigned int16 pin, int1 level);
_bif void output_float(unsigned int16 pin);
_bif void output_drive(unsigned int16 pin);
// Constants used to identify pins in the above are:

#define PIN_A0  28688
#define PIN_A1  28689
#define PIN_A4  28692
#define PIN_A7  28695
#define PIN_A8  28696
#define PIN_A9  28697
#define PIN_A10  28698
#define PIN_A11  28699
#define PIN_A12  28700

#define PIN_B0  28816
#define PIN_B1  28817
#define PIN_B2  28818
#define PIN_B3  28819
#define PIN_B4  28820
#define PIN_B5  28821
#define PIN_B6  28822
#define PIN_B7  28823
#define PIN_B8  28824
#define PIN_B9  28825
#define PIN_B10  28826
#define PIN_B11  28827
#define PIN_B12  28828
#define PIN_B13  28829
#define PIN_B14  28830
#define PIN_B15  28831

#define PIN_C0  28944
#define PIN_C1  28945
#define PIN_C2  28946
#define PIN_C3  28947
#define PIN_C4  28948
#define PIN_C5  28949
#define PIN_C6  28950
#define PIN_C7  28951
#define PIN_C8  28952
#define PIN_C9  28953
#define PIN_C10  28954
#define PIN_C11  28955
#define PIN_C12  28956
#define PIN_C13  28957
#define PIN_C15  28959

#define PIN_D5  29077
#define PIN_D6  29078
#define PIN_D8  29080

#define PIN_E12  29212
#define PIN_E13  29213
#define PIN_E14  29214
#define PIN_E15  29215

#define PIN_F0  29328
#define PIN_F1  29329

#define PIN_G6  29462
#define PIN_G7  29463
#define PIN_G8  29464
#define PIN_G9  29465

////////////////////////////////////////////////////////////////// Useful defines
#define FALSE 0
#define TRUE 1

#define BYTE unsigned int8
#define BOOLEAN int1

#define getc getch
#define fgetc getch
#define getchar getch
#define putc putchar
#define fputc putchar
#define fgets gets
#define fputs puts

////////////////////////////////////////////////////////////////// UART
// UART Prototypes:
_bif void setup_uart(unsigned int32 baud);
_bif void setup_uart(unsigned int32 baud, unsigned int8 stream);
_bif void setup_uart(unsigned int32 baud, unsigned int8 stream, unsigned int32 clock);
_bif void set_uart_speed(unsigned int32 baud);
_bif void set_uart_speed(unsigned int32 baud, unsigned int8 stream);
_bif void set_uart_speed(unsigned int32 baud, unsigned int8 stream, unsigned int32 clock);
// Constants used in setup_uart() are:
// FALSE - Turn UART off
// TRUE  - Turn UART on
#define UART_ADDRESS           2
#define UART_DATA              4
#define UART_AUTODETECT        8
#define UART_AUTODETECT_NOWAIT 9
#define UART_WAKEUP_ON_RDA     10
#define UART_SEND_BREAK        13

////////////////////////////////////////////////////////////////// WDT
// Watch Dog Timer Functions: SETUP_WDT() and RESTART_WDT()
// WDT Prototypes:
_bif void setup_wdt(unsigned int8 mode);
_bif void restart_wdt(void);
// Constants used for SETUP_WDT() are:
#define WDT_ON      1
#define WDT_OFF     0

#define  WDT_1MS    0x002
#define  WDT_2MS    0x003
#define  WDT_4MS    0x004
#define  WDT_8MS    0x005
#define  WDT_16MS    0x006
#define  WDT_32MS    0x007
#define  WDT_64MS    0x008
#define  WDT_128MS    0x009
#define  WDT_256MS    0x00A
#define  WDT_512MS    0x00B
#define  WDT_1S    0x00C
#define  WDT_2S    0x00D
#define  WDT_4S    0x00E
#define  WDT_8S    0x00F
#define  WDT_16S    0x010
#define  WDT_33S    0x011
#define  WDT_65S    0x030
#define  WDT_131S    0x031

////////////////////////////////////////////////////////////////// Control
// Control Functions:  RESET_CPU(), SLEEP(), RESTART_CAUSE()
// Prototypes:
_bif unsigned int8 restart_cause(void);
_bif void reset_cpu(void);
_bif void sleep(void);
_bif void sleep(unsigned int8 mode);
// Constants passed into RESTART_CAUSE() are:
#define RESTART_POWER_UP      0
#define RESTART_BROWNOUT      1
#define RESTART_WATCHDOG      4
#define RESTART_SOFTWARE      6
#define RESTART_MCLR          7
#define RESTART_ILLEGAL_OP    14
#define RESTART_TRAP_CONFLICT 15
//
// Constants passed into SLEEP() are:
#define SLEEP_FULL      0  // Default
#define SLEEP_IDLE      1  // Clock and peripherals don't stop

////////////////////////////////////////////////////////////////// INTERNAL RC
// Oscillator Prototypes:
_bif void setup_oscillator(unsigned int8 type, unsigned int32 target);
_bif void setup_oscillator(unsigned int8 type, unsigned int32 target, unsigned int32 source);
// Constants used in setup_oscillator() are:
#define OSC_INTERNAL     32
#define OSC_CRYSTAL       1
#define OSC_CLOCK         2
#define OSC_RC            3
#define OSC_SECONDARY    16

////////////////////////////////////////////////////////////////// Timer
// Timer Functions: SETUP_TIMERx, GET_TIMERx, GET_TIMERxy,
// SET_TIMERx, SET_TIMERxy
// Timer x Prototypes:
_bif void setup_timer1(unsigned int16 mode);
_bif void setup_timer1(unsigned int16 mode, unsigned int16 period);
_bif unsigned int16 get_timer1(void);
_bif void set_timer1(unsigned int16 value);
_bif void setup_timer2(unsigned int16 mode);  
_bif void setup_timer2(unsigned int16 mode, unsigned int16 period);  
_bif unsigned int16 get_timer2(void);  
_bif void set_timer2(unsigned int16 value);  
_bif void setup_timer3(unsigned int16 mode);  
_bif void setup_timer3(unsigned int16 mode, unsigned int16 period);  
_bif unsigned int16 get_timer3(void);  
_bif void set_timer3(unsigned int16 value);  
_bif unsigned int32 get_timer23(void);  
_bif void set_timer23(unsigned int32 value);  
_bif void setup_timer4(unsigned int16 mode);  
_bif void setup_timer4(unsigned int16 mode, unsigned int16 period);  
_bif unsigned int16 get_timer4(void);  
_bif void set_timer4(unsigned int16 value);  
_bif void setup_timer5(unsigned int16 mode);  
_bif void setup_timer5(unsigned int16 mode, unsigned int16 period);  
_bif unsigned int16 get_timer5(void);  
_bif void set_timer5(unsigned int16 value);  
_bif unsigned int32 get_timer45(void);  
_bif void set_timer45(unsigned int32 value);  
_bif void setup_timer6(unsigned int16 mode);  
_bif void setup_timer6(unsigned int16 mode, unsigned int16 period);  
_bif unsigned int16 get_timer6(void);  
_bif void set_timer6(unsigned int16 value);  
_bif void setup_timer7(unsigned int16 mode);  
_bif void setup_timer7(unsigned int16 mode, unsigned int16 period);  
_bif unsigned int16 get_timer7(void);  
_bif void set_timer7(unsigned int16 value);  
_bif unsigned int32 get_timer67(void);  
_bif void set_timer67(unsigned int32 value);  
_bif void setup_timer8(unsigned int16 mode);  
_bif void setup_timer8(unsigned int16 mode, unsigned int16 period);  
_bif unsigned int16 get_timer8(void);  
_bif void set_timer8(unsigned int16 value);  
_bif void setup_timer9(unsigned int16 mode);  
_bif void setup_timer9(unsigned int16 mode, unsigned int16 period);  
_bif unsigned int16 get_timer9(void);  
_bif void set_timer9(unsigned int16 value);  
_bif unsigned int32 get_timer89(void);  
_bif void set_timer89(unsigned int32 value);  
// Constants used for SETUP_TIMERx() are:
//      (or (via |) together constants from each group)
#define TMR_DISABLED 0x0000
#define TMR_INTERNAL 0x8000
#define TMR_EXTERNAL 0x8002
#define TMR_GATE     0x0040 

#define TMR_DIV_BY_1   0x0000
#define TMR_DIV_BY_8   0x0010
#define TMR_DIV_BY_64  0x0020
#define TMR_DIV_BY_256 0x0030
#define TMR_32_BIT     0x0008 // Only for even numbered timers

#define TMR_HALT_IDLE      0x2000
#define TMR_CONTINUE_IDLE  0x0000

#define T1_EXTERNAL_SYNC  0x8006 //This only applies to Timer1
#define T1_EXTERNAL_RTC   0xC002 //This only applies to Timer1
/////////////////////////////////////////////////////////// INPUT CAPTURE
// Functions: SETUP_CAPTURE, GET_CAPTURE, GET_CAPTURE32
// IC Prototypes:
_bif void setup_capture(unsigned int8 module, unsigned int32 mode);
_bif unsigned int16 get_capture(unsigned int8 module);
_bif unsigned int16 get_capture(unsigned int8 module, int1 wait);
_bif unsigned int32 get_capture32(unsigned int8 module);
_bif unsigned int32 get_capture32(unsigned int8 module, int1 wait);
// Constants used for SETUP_CAPTURE() are:
#define CAPTURE_OFF                 0x0000  // Capture OFF
#define CAPTURE_EE                  0x0001  // Capture Every Edge
#define CAPTURE_FE                  0x0002  // Capture Falling Edge
#define CAPTURE_RE                  0x0003  // Capture Rising Edge
#define CAPTURE_DIV_4               0x0004  // Capture Every 4th Rising Edge
#define CAPTURE_DIV_16              0x0005  // Capture Every 16th Rising Edge
#define CAPTURE_INTERRUPT_ONLY      0x0007  // Interrupt on Rising Edge when in Sleep or Idle

// The following defines can be ORed | with above to configure interrupts
#define INTERRUPT_EVERY_CAPTURE     0x0000  // Interrupt on every capture event
#define INTERRUPT_SECOND_CAPTURE    0x0020  // Interrupt on every second capture event
#define INTERRUPT_THIRD_CAPTURE     0x0040  // Interrupt on every third capture event
#define INTERRUPT_FOURTH_CAPTURE    0x0060  // Interrupt on every fourth capture event

// The following defines can be ORed | with above to select timer
#define CAPTURE_TIMER1              0x1000
#define CAPTURE_TIMER2              0x0400
#define CAPTURE_TIMER3              0x0000
#define CAPTURE_TIMER4              0x0800
#define CAPTURE_TIMER5              0x0C00
#define CAPTURE_SYSTEM_CLOCK        0x1C00

// The following defines can be ORed | with above to select idle operation mode
#define CAPTURE_HALT_IDLE           0x2000  // Capture module halts during idle mode
#define CAPTURE_CONTINUE_IDLE       0x0000  // Capture module continues during idle mode

// The following defines can be ORed | with above to select # of bits
#define CAPTURE_32_BIT              0x01000000  //Only used with odd number capture units
#define CAPTURE_16_BIT                       0

// The following defines can be ORed | with above and determines whether the next block
// of defines are the capture unit's trigger or syncronize source
#define CAPTURE_TRIGGER             0x00800000
#define CAPTURE_SYNCHRONIZE                  0

// The following defines can be ORed | with above and selects the capture unit's
// trigger or synchronization source
#define CAPTURE_TRIG_SYNC_OC1       0x00010000
#define CAPTURE_TRIG_SYNC_OC2       0x00020000
#define CAPTURE_TRIG_SYNC_OC3       0x00030000
#define CAPTURE_TRIG_SYNC_OC4       0x00040000
#define CAPTURE_TRIG_SYNC_PTGOx     0x000A0000 
#define CAPTURE_TRIG_SYNC_TIMER1    0x000B0000
#define CAPTURE_TRIG_SYNC_TIMER2    0x000C0000
#define CAPTURE_TRIG_SYNC_TIMER3    0x000D0000
#define CAPTURE_TRIG_SYNC_TIMER4    0x000E0000
#define CAPTURE_TRIG_SYNC_TIMER5    0x000F0000
#define CAPTURE_TRIG_SYNC_IC1       0x00100000
#define CAPTURE_TRIG_SYNC_IC2       0x00110000
#define CAPTURE_TRIG_SYNC_IC3       0x00120000
#define CAPTURE_TRIG_SYNC_IC4       0x00130000
#define CAPTURE_TRIG_SYNC_COMP1     0x00180000  //Trigger Source only
#define CAPTURE_TRIG_SYNC_COMP2     0x00190000  //Trigger Source only
#define CAPTURE_TRIG_SYNC_COMP3     0x001A0000  //Trigger Source only
#define CAPTURE_TRIG_SYNC_ADC       0x001B0000  //Trigger Source only
#define CAPTURE_TRIG_SYNC_CTMU      0x001C0000  //Trigger Source only 
#define CAPTURE_TRIG_SYNC_NONE               0

/////////////////////////////////////////////////////////// OUTPUT COMPARE
// Functions: SETUP_COMPARE, SET_PWM_DUTY, SET_COMPARE_TIME
// OC Prototypes:
_bif void setup_compare(unsigned int8 module, unsigned int32 mode);
_bif void set_pwm_duty(unsigned int8 module, unsigned int16 duty);
_bif void set_compare_time(unsigned int8 module, unsigned int16 ocr);
_bif void set_compare_time(unsigned int8 module, unsigned int16 ocr, unsigned int16 ocrs);
// Constants used for SETUP_COMPARE() are:
#define COMPARE_OFF               0x0000  // Compare OFF
#define COMPARE_SET_ON_MATCH      0x0001  // Pin from low to high on match
#define COMPARE_CLR_ON_MATCH      0x0002  // Pin from high to low on match
#define COMPARE_TOGGEL            0x0003  // Pin will toggle on every match occurrence
#define COMPARE_SINGLE_PULSE      0x0004  // Pin will generate single pulse on first match
#define COMPARE_CONT_PULSE        0x0005  // Pin will pulse for every match
#define COMPARE_PWM_EDGE          0x0006
#define COMPARE_PWM_CENTER        0x0007

// One of the following defines maybe ORed | with above
#define COMPARE_TIMER2            0x0000
#define COMPARE_TIMER3            0x0400
#define COMPARE_TIMER4            0x0800
#define COMPARE_TIMER5            0x0C00
#define COMPARE_TIMER1            0x1000
#define COMPARE_SYSTEM_CLOCK      0x1C00

// The following defines maybe ORed | with above
#define COMPARE_FAULTA            0x0080
#define COMPARE_FAULTB            0x0100

// The following defines maybe ORed | with above
#define COMPARE_FAULT_CLEARED_SW  0x80000000
#define COMPARE_HIGH_ON_FAULT     0x40000000
#define COMPARE_LOW_ON_FAULT      0x00000000
#define COMPARE_TRISTATE_ON_FAULT 0x20000000
#define COMPARE_INVERT_OUTPUT     0x10000000
#define COMPARE_32_BIT            0x01000000
#define COMPARE_TRIGGER           0x00800000
#define COMPARE_SYNCHRONIZE       0x00000000
#define COMPARE_OUTPUT_TRISTATED  0x00200000

// One of the following maybe ORed | with above
#define COMPARE_TRIG_SYNC_INT2    0x001E0000
#define COMPARE_TRIG_SYNC_INT1    0x001D0000
#define COMPARE_TRIG_SYNC_CTMU    0x001C0000 
#define COMPARE_TRIG_SYNC_ADC1    0x001B0000
#define COMPARE_TRIG_SYNC_COMP3   0x001A0000
#define COMPARE_TRIG_SYNC_COMP2   0x00190000
#define COMPARE_TRIG_SYNC_COMP1   0x00180000
#define COMPARE_TRIG_SYNC_IC8     0x00170000 
#define COMPARE_TRIG_SYNC_IC7     0x00160000 
#define COMPARE_TRIG_SYNC_IC6     0x00150000 
#define COMPARE_TRIG_SYNC_IC5     0x00140000 
#define COMPARE_TRIG_SYNC_IC4     0x00130000
#define COMPARE_TRIG_SYNC_IC3     0x00120000
#define COMPARE_TRIG_SYNC_IC2     0x00110000
#define COMPARE_TRIG_SYNC_IC1     0x00100000
#define COMPARE_TRIG_SYNC_TIMER5  0x000F0000
#define COMPARE_TRIG_SYNC_TIMER4  0x000E0000
#define COMPARE_TRIG_SYNC_TIMER3  0x000D0000
#define COMPARE_TRIG_SYNC_TIMER2  0x000C0000
#define COMPARE_TRIG_SYNC_TIMER1  0x000B0000
#define COMPARE_TRIG_SYNC_PTGOx   0x000A0000 
#define COMPARE_TRIG_SYNC_OC8     0x00080000 
#define COMPARE_TRIG_SYNC_OC7     0x00070000 
#define COMPARE_TRIG_SYNC_OC6     0x00060000 
#define COMPARE_TRIG_SYNC_OC5     0x00050000 
#define COMPARE_TRIG_SYNC_OC4     0x00040000
#define COMPARE_TRIG_SYNC_OC3     0x00030000
#define COMPARE_TRIG_SYNC_OC2     0x00020000
#define COMPARE_TRIG_SYNC_OC1     0x00010000
#define COMPARE_TRIG_SYNC_NONE    0x00000000

////////////////////////////////////////////////////////////////// SPI
// SPI Functions: SETUP_SPI, SPI_WRITE, SPI_READ, SPI_DATA_IN
// SPI Prototypes:
_bif void setup_spi(unsigned int16 mode);
_bif void spi_write(unsigned int8 data);
_bif unsigned int8 spi_read(void);
_bif unsigned int8 spi_read(unsigned int8 data);
_bif int1 spi_data_in(void);
_bif void setup_spi2(unsigned int16 mode);  
_bif void spi_write2(unsigned int8 data);  
_bif unsigned int8 spi_read2(void);  
_bif unsigned int8 spi_read2(unsigned int8 data);  
_bif int1 spi_data_in2(void);  
_bif void setup_spi3(unsigned int16 mode);  
_bif void spi_write3(unsigned int8 data);  
_bif unsigned int8 spi_read3(void);  
_bif unsigned int8 spi_read3(unsigned int8 data);  
_bif int1 spi_data_in3(void);  
// Constants used in SETUP_SPI() are:
//      (or (via |) together constants from each group)
#define SPI_MASTER                 0x0020
#define SPI_SLAVE                  0x0000

#define SPI_SCK_IDLE_HIGH          0x0040
#define SPI_SCK_IDLE_LOW           0x0000

#define SPI_XMIT_L_TO_H            0x0100
#define SPI_XMIT_H_TO_L            0x0000

#define SPI_MODE_16B               0x0400
#define SPI_MODE_8B                0x0000

#define SPI_SAMPLE_AT_END          0x0200
#define SPI_SAMPLE_AT_MIDDLE       0x0000

#define SPI_SS_ENABLED             0x0000
#define SPI_SS_DISABLED            0x0080

//or (via |) one of the following when operating as MASTER 
#define SPI_CLK_DIV_1              0x001F
#define SPI_CLK_DIV_2              0x001B
#define SPI_CLK_DIV_3              0x0017
#define SPI_CLK_DIV_4              0x001E
#define SPI_CLK_DIV_5              0x000F
#define SPI_CLK_DIV_6              0x000B
#define SPI_CLK_DIV_7              0x0007
#define SPI_CLK_DIV_8              0x0003
#define SPI_CLK_DIV_12             0x0016
#define SPI_CLK_DIV_16             0x001D
#define SPI_CLK_DIV_20             0x000E
#define SPI_CLK_DIV_24             0x000A
#define SPI_CLK_DIV_28             0x0006
#define SPI_CLK_DIV_32             0x0002
#define SPI_CLK_DIV_48             0x0015
#define SPI_CLK_DIV_64             0x001C
#define SPI_CLK_DIV_80             0x000D
#define SPI_CLK_DIV_96             0x0009
#define SPI_CLK_DIV_112            0x0005
#define SPI_CLK_DIV_128            0x0001
#define SPI_CLK_DIV_192            0x0014
#define SPI_CLK_DIV_256            0x0010
#define SPI_CLK_DIV_320            0x000C
#define SPI_CLK_DIV_384            0x0008
#define SPI_CLK_DIV_448            0x0004
#define SPI_CLK_DIV_512            0x0000

//The following defines are provided for compatibility
#define SPI_L_TO_H         SPI_SCK_IDLE_LOW
#define SPI_H_TO_L         SPI_SCK_IDLE_HIGH

////////////////////////////////////////////////////////////////// ADC
// ADC Functions: SETUP_ADC(), SETUP_ADC_PORTS()
//                SET_ADC_CHANNEL(), READ_ADC()
// ADC Prototypes:
_bif void setup_adc(unsigned int32 mode);
_bif void setup_adc_ports(unsigned int32 pins);
_bif void setup_adc_ports(unsigned int32 pins, unsigned int16 reference);
_bif void set_adc_channel(unsigned int8);
_bif unsigned int16 read_adc(void);
_bif unsigned int16 read_adc(unsigned int8 mode);
_bif int1 adc_done(void);
_bif void setup_adc2(unsigned int32 mode);  
_bif void setup_adc_ports2(unsigned int32 pins);  
_bif void setup_adc_ports2(unsigned int32 pins, unsigned int16 reference);  
_bif void set_adc_channel2(unsigned int8);  
_bif unsigned int16 read_adc2(void);  
_bif unsigned int16 read_adc2(unsigned int8 mode);  
_bif int1 adc_done2(void);  
// Constants used for SETUP_ADC() are:
// Clock is at ADCS<5:0> of ADCON3 Reg. (0x02A4)
// Tad = (Tcy/2)*(ADCS<5:0>+1)
#define ADC_OFF           0x10000
#define ADC_CLOCK          0x0000
#define ADC_CLOCK_DIV_2    0x0001
#define ADC_CLOCK_DIV_4    0x0003
#define ADC_CLOCK_DIV_8    0x0007
#define ADC_CLOCK_DIV_16   0x000F
#define ADC_CLOCK_DIV_32   0x001F
#define ADC_CLOCK_DIV_64   0x003F
#define ADC_CLOCK_DIV_128  0x007F   
#define ADC_CLOCK_DIV_256  0x00FF   
#define ADC_CLOCK_INTERNAL 0x8000     // Internal

// The following may be OR'ed in with the above using |
// Auto-Sample Time bits
#define ADC_TAD_MUL_0      0x1F00
#define ADC_TAD_MUL_2      0x1D00
#define ADC_TAD_MUL_4      0x1B00
#define ADC_TAD_MUL_8      0x1700
#define ADC_TAD_MUL_16     0x0F00
#define ADC_TAD_MUL_31     0x0000

// Constants used in READ_ADC() are:
#define ADC_START_AND_READ 0x07
#define ADC_START_ONLY     0x01
#define ADC_READ_ONLY      0x06

// Constants used in SETUP_ADC_PORTS() are:
// First argument:
// OR together desired pins
#define NO_ANALOGS      0           // None
#define ALL_ANALOG      0xFFFFFFFFFFFFFFFF  // All
#define sAN0      0x0000000000000001 //| A0
#define sAN1      0x0000000000000002 //| A1
#define sAN2      0x0000000000000004 //| B0
#define sAN3      0x0000000000000008 //| B1
#define sAN4      0x0000000000000010 //| B2
#define sAN5      0x0000000000000020 //| B3
#define sAN6      0x0000000000000040 //| C0
#define sAN7      0x0000000000000080 //| C1
#define sAN8      0x0000000000000100 //| C2
#define sAN9      0x0000000000000200 //| A11
#define sAN10      0x0000000000000400 //| A12
#define sAN11      0x0000000000000800 //| C11
#define sAN12      0x0000000000001000 //| E12
#define sAN13      0x0000000000002000 //| E13
#define sAN14      0x0000000000004000 //| E14
#define sAN15      0x0000000000008000 //| E15
#define sAN16      0x0000000000010000 //| G9
#define sAN17      0x0000000000020000 //| G8
#define sAN18      0x0000000000040000 //| G7
#define sAN19      0x0000000000080000 //| G6
#define sAN24      0x0000000001000000 //| A4
#define sAN25      0x0000000002000000 //| B7
#define sAN26      0x0000000004000000 //| B8
#define sAN27      0x0000000008000000 //| B9
#define sAN28      0x0000000010000000 //| A9
#define sAN29      0x0000000020000000 //| C3
#define sAN30      0x0000000040000000 //| C4
#define sAN31      0x0000000080000000 //| C5
#define sAN48      0x0001000000000000 //| C10
#define sAN49      0x0002000000000000 //| C12

// Optional Second argument:
#define VSS_VDD            0x0000 // Range 0-Vdd
#define VREF_VREF          0x6000 // Range VrefL-VrefH
#define VREF_VDD           0x4000 // Range VrefL-Vdd
#define VSS_VREF           0x2000 // Range 0-VrefH

////////////////////////////////////////////////////////////////// COMP
// Comparator Functions: SETUP_COMPARATOR(), SETUP_COMPARATOR_FILTER(),
//                       SETUP_COMPARATOR_MASK()
// Comparator Prototypes:
_bif void setup_comparator(unsigned int8 comparator, unsigned int16 mode);
_bif void setup_comparator_filter(unsigned int8 comparator, unsigned int16 mode);
_bif void setup_comparator_mask(unsigned int8 comparator, unsigned int16 mode);
_bif void setup_comparator_mask(unsigned int8 comparator, unsigned int16 mode, unsigned int16 input1);
_bif void setup_comparator_mask(unsigned int8 comparator, unsigned int16 mode, unsigned int16 input1, unsigned int16 input2);
_bif void setup_comparator_mask(unsigned int8 comparator, unsigned int16 mode, unsigned int16 input1, unsigned int16 input2, unsigned int16 input3);
// Constants used in SETUP_COMPARATOR() second param are: - first param is the comparator number.
#define NC_NC                 0x0000
#define CXIN2_CXIN1           0x8000
#define CXIN1_CXIN1           0x8001
#define CXIN3_CXIN1           0x8002
#define CXIN4_CXIN1           0x8003 
#define CXIN2_VREF            0x8010
#define CXIN1_VREF            0x8011
#define CXIN3_VREF            0x8012
#define CXIN4_VREF            0x8013 
      // OR in any of the following
#define COMP_ENABLE_OPAMP     0x0400   // Enable OPAMP on CxIN1- and CxIN1+ pins (comparators 1,2,3 and 5 only) 
#define COMP_INVERT           0x2000   // Invert output
#define COMP_OUTPUT           0x4000   // Output on pin
#define COMP_INTR             0x0040   // Generate interrupt on high
#define COMP_INTR_INV         0x0080   // Generate interrupt on low
#define COMP_INTR_CHANGE      0x00C0   // Generate interrupt on change

// Constants used in SETUP_COMPARATOR_FILTER() second param are: - first param is the comparator number.
#define COMP_FILTER_DISABLE         0x0000
#define COMP_FILTER_ENABLE          0x0008
      // OR in one of the following
#define COMP_FILTER_CLK_T5          0x0070
#define COMP_FILTER_CLK_T4          0x0060
#define COMP_FILTER_CLK_T3          0x0050
#define COMP_FILTER_CLK_T2          0x0040
#define COMP_FILTER_CLK_SYNCO2      0x0030
#define COMP_FILTER_CLK_SYNCO1      0x0020
#define COMP_FILTER_CLK_FOSC        0x0010
#define COMP_FILTER_CLK_INTERNAL    0x0000
      // OR in one of the following
#define COMP_FILTER_CLK_DIV_BY_128  0x0007
#define COMP_FILTER_CLK_DIV_BY_64   0x0006
#define COMP_FILTER_CLK_DIV_BY_32   0x0005
#define COMP_FILTER_CLK_DIV_BY_16   0x0004
#define COMP_FILTER_CLK_DIV_BY_8    0x0003
#define COMP_FILTER_CLK_DIV_BY_4    0x0002
#define COMP_FILTER_CLK_DIV_BY_2    0x0001
#define COMP_FILTER_CLK_DIV_BY_1    0x0000

// Constants used in SETUP_COMPARATOR_MASK() second param are: - first param is the comparator number.
#define COMP_MASK_COMP_HIGH                      0x0000
#define COMP_MASK_COMP_LOW                       0x8000
      // OR in any of the following
#define COMP_MASK_MCI_CONNECTED_TO_OR            0x2000
#define COMP_MASK_INVERTED_MCI_CONNECTED_TO_OR   0x1000
#define COMP_MASK_MBI_CONNECTED_TO_OR            0x0800
#define COMP_MASK_INVERTED_MBI_CONNECTED_TO_OR   0x0400
#define COMP_MASK_MAI_CONNETED_TO_OR             0x0200
#define COMP_MASK_INVERTED_MAI_CONNECTED_TO_OR   0x0100
#define COMP_MASK_INVERTED_ANDI_CONNECTED_TO_OR  0x0080
#define COMP_MASK_ANDI_CONNECTED_TO_OR           0x0040
#define COMP_MASK_MCI_CONNECTED_TO_AND           0x0020
#define COMP_MASK_INVERTED_MCI_CONNECTED_TO_AND  0x0010
#define COMP_MASK_MBI_CONNECTED_TO_AND           0x0008
#define COMP_MASK_INVERTED_MBI_CONNECTED_TO_AND  0x0004
#define COMP_MASK_MAI_CONNECTED_TO_AND           0x0002
#define COMP_MASK_INVERTED_MAI_CONNECTED_TO_AND  0x0001
// Constants used in SETUP_COMPARATOR_MASK() third, forth and fifth param are:
#define COMP_MASK_INPUT_FLT4                     0x000F
#define COMP_MASK_INPUT_FLT2                     0x000E
#define COMP_MASK_INPUT_PTGO19                   0x000D 
#define COMP_MASK_INPUT_PTGO18                   0x000C 
#define COMP_MASK_INPUT_PWM6H                    0x000B
#define COMP_MASK_INPUT_PWM6L                    0x000A
#define COMP_MASK_INPUT_PWM5H                    0x0009
#define COMP_MASK_INPUT_PWM5L                    0x0008
#define COMP_MASK_INPUT_PWM4H                    0x0007
#define COMP_MASK_INPUT_PWM4L                    0x0006
#define COMP_MASK_INPUT_PWM3H                    0x0005
#define COMP_MASK_INPUT_PWM3L                    0x0004
#define COMP_MASK_INPUT_PWM2H                    0x0003
#define COMP_MASK_INPUT_PWM2L                    0x0002
#define COMP_MASK_INPUT_PWM1H                    0x0001
#define COMP_MASK_INPUT_PWM1L                    0x0000

#bit C1OUT = 0xA84.8
#bit C1ENV = 0xA84.9  // User must clear
#bit C2OUT = 0xA8C.8
#bit C2ENV = 0xA8C.9  // User must clear
#bit C3OUT = 0xA94.8
#bit C3ENV = 0xA94.9  // User must clear
#bit C4OUT = 0xA9C.8
#bit C4ENV = 0xA9C.9  // User must clear
#bit C5OUT = 0xAA4.8
#bit C5ENV = 0xAA4.9  // User must clear

////////////////////////////////////////////////////////////////// VREF
// VREF Prototypes:
_bif void setup_vref(unsigned int16 mode);
// Constants used in setup_vref() are:
#define VREF_DISABLED        0x0000
#define VREF_VSS_VDD         0x0080
#define VREF_ANALOG          0x0090
// One of the following maybe OR'ed in with the above using |
#define VREF_HIGH            0x0080
#define VREF_LOW             0x00A0
// The following maybe OR'ed in with the above using |
#define VREF_CVREF_IS_VREF   0x0400  // CVref+ = VREF+
#define VREF_OUTPUT          0x0040
#define VREF_OUTPUT_CVREF2   0x04000 // (AVDD - AVSS)/2 is connected to the CVREF2O pin
// OR a number 0-15 with the above using |

////////////////////////////////////////////////////////////////// PMP
// PMP Functions: setup_pmp(), pmp_address(), psp_read(), pmp_read(),
// psp_write(), pmp_write(), psp_output_full(),psp_input_full(),
// psp_overflow(), pmp_output_full(), pmp_input_full(),
// pmp_overflow()
// PMP Prototypes:
_bif void setup_pmp(unsigned int32 mode, unsigned int16 address_mask);
_bif void pmp_address(unsigned int16 address);
_bif unsigned int8 pmp_read(void);
_bif void pmp_write(unsigned int8 data);
_bif int1 pmp_output_full(void);
_bif int1 pmp_input_full(void);
_bif int1 pmp_overflow(void);
_bif void setup_psp(unsigned int32 mode, unsigned int16 address_mask);
_bif unsigned int8 psp_read(void);
_bif unsigned int8 psp_read(unsigned int16 address);
_bif void psp_write(unsigned int8 data);
_bif void psp_write(unsigned int8 data, unsigned int16 address);
_bif int1 psp_output_full(void);
_bif int1 psp_input_full(void);
_bif int1 psp_overflow(void);
// Constants used in SETUP_PMP() and SETUP_PSP() are:
#define PAR_ENABLE                0x8000
#define PAR_DISABLE               0x0000    // Module enable/disable options
#define PAR_STOP_IN_IDLE          0x2000
#define PAR_CONTINUE_IN_IDLE      0x0000
#define PAR_ADDR_NOT_MULTIPLEXED  0x0000    // Address multiplexing options
#define PAR_LOW_ADDR_MULTIPLEXED  0x0800    // Address multiplexing options
#define PAR_FULL_ADDR_MULTIPLEXED 0x1000    // Address multiplexing options
#define PAR_PTBEEN_ENABLE         0x0400  // Byte Enable Port Enable bit
#define PAR_PTWREN_ENABLE         0x0200  // Write Enable Strobe bit
#define PAR_PTRDEN_ENABLE         0x0100  // Read/Write Strobe Port bit
#define PAR_ALP_ACTIVE_HIGH       0x0020 // Address latch polarity high
#define PAR_BEP_ACTIVE_HIGH       0x0004 // Byte Enable Polarity
#define PAR_WRSP_ACTIVE_HIGH      0x0002 // Write strobe Polarity bit
#define PAR_RDSP_ACTIVE_HIGH      0x0001 // Read strobe Polarity bit
#define PAR_CS_XX                 0x0000   // Chip select pins used for address
#define PAR_CS_X1                 0x0008   // Chip select pin 1 used, active high
#define PAR_CS_X0                 0x0000   // Chip select pin 1 used, active low
#define PAR_CS_1X                 0x0050   // Chip select pin 2 used, active high
#define PAR_CS_0X                 0x0040   // Chip select pin 2 used, active low
#define PAR_CS_00                 0x0080   // Chip select pins 1,2 used, active low
#define PAR_CS_11                 0x0098   // Chip select pins 1,2 used, active high
#define PAR_CS_10                 0x0090   // Chip select pins 1,2 used, 1 is active low, 2 is high
#define PAR_CS_01                 0x0088   // Chip select pins 1,2 used, 1 is active high, 2 is low
#define PAR_INTR_ON_RW                0x20000000  // Interrupt on read write
#define PAR_NO_INTR_STALL_ACTIVATED   0x40000000  // No interrupt, processor stall activated
#define PAR_INTR_ON_3_RW_BUF          0x60000000 // Interrupt on write to Buffer 3 or read from Buffer 3
#define PAR_PSP_AUTO_INC              0x18000000 // Read write buffers auto increment
#define PAR_DEC_ADDR                  0x10000000 // Increment the address
#define PAR_INC_ADDR                  0x08000000 // Decrement the address
#define PAR_MASTER_MODE_1             0x03000000  // Master mode 1
#define PAR_MASTER_MODE_2             0x02000000  // Master mode 2
#define PAR_WAITB1                    0x00000000 // 1 Tcy Wait state for data setup R/W
#define PAR_WAITB2                    0x00400000 // 2 Tcy Wait state for data setup R/W
#define PAR_WAITB3                    0x00800000 // 3 Tcy Wait state for data setup R/W
#define PAR_WAITB4                    0x00C00000 // 4 Tcy Wait state for data setup R/W
#define PAR_WAITM0                    0x00000000 // 0 wait state for Read to byte
#define PAR_WAITM1                    0x00040000 // 1 Tcy wait state for Read to byte
#define PAR_WAITM2                    0x00080000 // 2 Tcy wait state for Read to byte
#define PAR_WAITM3                    0x000C0000 // 3 Tcy wait state for Read to byte
#define PAR_WAITM15                   0x003C0000 // 15 wait states
#define PAR_WAITE1                    0x00000000  // 1 Tcy Wait for data hold after strobe
#define PAR_WAITE2                    0x00010000 // 2 Tcy Wait for data hold after strobe
#define PAR_WAITE3                    0x00020000 // 3 Tcy Wait for data hold after strobe
#define PAR_WAITE4                    0x00030000 // 4 Tcy Wait for data hold after strobe

////////////////////////////////////////////////////////////////// CRC
// CRC Functions: setup_crc(), crc_init(), crc_calc32(),
//                crc_calc16(), crc_calc8()
// CRC Prototypes:
_bif void setup_crc(unsigned int8 poly_terms, ...);
_bif void crc_init(unsigned int32 value);
_bif unsigned int32 crc_calc32(unsigned int32 data);
_bif unsigned int32 crc_calc32(unsigned int32 data, unsigned int8 width);
_bif unsigned int32 crc_calc32(unsigned int32 *ptr, unsigned int16 count);
_bif unsigned int32 crc_calc32(unsigned int32 *ptr, unsigned int16 count, unsigned int8 width);
_bif unsigned int16 crc_calc16(unsigned int16 data);
_bif unsigned int16 crc_calc16(unsigned int16 data, unsigned int8 width);
_bif unsigned int16 crc_calc16(unsigned int16 *ptr, unsigned int16 count);
_bif unsigned int16 crc_calc16(unsigned int16 *ptr, unsigned int16 count, unsigned int8 width);
_bif unsigned int8 crc_calc8(unsigned int8 data);
_bif unsigned int8 crc_calc8(unsigned int8 data, unsigned int8 width);
_bif unsigned int8 crc_calc8(unsigned int8 *ptr, unsigned int16 count);
_bif unsigned int8 crc_calc8(unsigned int8 *ptr, unsigned int16 count, unsigned int8 width);
_bif unsigned int16 crc_calc(unsigned int16 data);
_bif unsigned int16 crc_calc(unsigned int16 data, unsigned int8 width);
_bif unsigned int16 crc_calc(unsigned int16 *ptr, unsigned int16 count);
_bif unsigned int16 crc_calc(unsigned int16 *ptr, unsigned int16 count, unsigned int8 width);
// Constants used in setup_crc() are:
#define CRC_LITTLE_ENDIAN    128

////////////////////////////////////////////////////////////////// RTC
// RTC Functions: setup_rtc(), setup_rtc_alarm(), rtc_read(),
//                rtc_write(), rtc_alarm_read(), rtc_alarm_write()
// Structure used in read and write functions (pass pointer):
typedef struct {
   unsigned int8 tm_year;
   unsigned int8 tm_temp;  // Not used by built in functions, place holder only do not use
   unsigned int8 tm_mday;
   unsigned int8 tm_mon;
   unsigned int8 tm_hour;
   unsigned int8 tm_wday;
   unsigned int8 tm_sec;
   unsigned int8 tm_min;
   unsigned int8 tm_isdst; // Not used by built in functions
} rtc_time_t;
// RTC Protoyptes:
_bif void setup_rtc(unsigned int16 mode, unsigned int8 calibration);
_bif void setup_rtc_alarm(unsigned int16 mode, unsigned int16 mask, unsigned int8 repeat);
_bif void rtc_read(rtc_time_t *time);
_bif void rtc_write(rtc_time_t *time);
_bif void rtc_read_alarm(rtc_time_t *time);
_bif void rtc_write_alarm(rtc_time_t *time);
// Constants used in setup_rtc() are:  // Second param is calibration
#define RTC_ENABLE           0x8000
#define RTC_DISABLE          0
#define RTC_OUTPUT_SECONDS   0x20400
#define RTC_OUTPUT_ALARM     0x00400
//
// Constants used in setup_rtc_alarm() first param are:  
#define RTC_ALARM_ENABLE     0x8000
#define RTC_ALARM_DISABLE    0
#define RTC_CHIME_ENABLE     0x4000
#define RTC_CHIME_DISABLE    0
// Constants used in setup_rtc_alarm() second param are:  // Third param is repeat#
#define RTC_ALARM_HALFSECOND 0x0000
#define RTC_ALARM_SECOND     0x0400
#define RTC_ALARM_10_SECONDS 0x0800
#define RTC_ALARM_MINUTE     0x0C00
#define RTC_ALARM_10_MINUTES 0x1000
#define RTC_ALARM_HOUR       0x1400
#define RTC_ALARM_DAY        0x1800
#define RTC_ALARM_WEEK       0x1C00
#define RTC_ALARM_MONTH      0x2000
#define RTC_ALARM_YEAR       0x2400

////////////////////////////////////////////////////////////////// QEI
// QEI Functions: setup_qei(), qei_set_count(), qei_get_count(),
//                qei_status(), qei_set_index_count(), qei_get_index_count(),
//                qei_get_velocity_count(), qei_get_interval_count(),
//                qei_get_capture()
// QEI Prototypes:
_bif void setup_qei(unsigned int32 mode, unsigned int16 filter, unsigned int16 interrupt_settings, unsigned int16 lte_value, unsigned int16 gte_value);
_bif void setup_qei(unsigned int8 unit, unsigned int32 mode, unsigned int16 filter, unsigned int16 interrupt_settings, unsigned int16 lte_value, unsigned int16 gte_value);
_bif void qei_set_count(unsigned int32 count);
_bif void qei_set_count(unsigned int8 unit, unsigned int32 count);
_bif unsigned int32 qei_get_count(void);
_bif unsigned int32 qei_get_count(unsigned int8 unit);
_bif unsigned int32 qei_status(void);
_bif unsigned int32 qei_status(unsigned int8 unit);
_bif void qei_set_index_count(unsigned int32 count);
_bif void qei_set_index_connt(unsigned int8 unit, unsigned int32 count);
_bif unsigned int32 qei_get_index_count(void);
_bif unsigned int32 qei_get_index_count(unsigned int8 unit);
_bif unsigned int16 qei_get_velocity_count(void);
_bif unsigned int16 qei_get_velocity_count(unsigned int8 unit);
_bif unsigned int32 qei_get_interval_count(void);
_bif unsigned int32 qei_get_interval_count(unsigned int8 unit);
_bif unsigned int32 qei_get_capture(void);
_bif unsigned int32 qei_get_capture(unsigned int8 unit);
// Constants used in setup_qei() first param are:
#define QEI_DISABLED                            0x10000
#define QEI_MODE_X4                             0x20000
#define QEI_MODE_TIMER_EXTERNAL_UPDOWN_EXTERNAL 0x20001
#define QEI_MODE_TIMER_EXTERNAL                 0x20002
#define QEI_MODE_TIMER_INTERNAL                 0x20003
#define QEI_TIMER_GATED                         0x20004
#define QEI_COUNT_NEGATIVE                      0x20008
#define QEI_TIMER_DIV_1                         0x20000
#define QEI_TIMER_DIV_2                         0x20010
#define QEI_TIMER_DIV_4                         0x20020
#define QEI_TIMER_DIV_8                         0x20030
#define QEI_TIMER_DIV_16                        0x20040
#define QEI_TIMER_DIV_32                        0x20050
#define QEI_TIMER_DIV_64                        0x20060
#define QEI_TIMER_DIV_256                       0x20070
#define QEI_IDX_WHEN_A1_B0                      0x20100 // for 4X mode
#define QEI_IDX_WHEN_A0_B1                      0x20200 // for 4X mode
#define QEI_IDX_WHEN_A1_B1                      0x20300 // for 4X mode
#define QEI_RESET_WHEN_IDX                      0x20400
#define QEI_INITIALIZE_ON_NEXT_IDX              0x20800
#define QEI_INITIALIZE_ON_FIRST_IDX_AFTER_HOME  0x20C00
#define QEI_INITIALIZE_ON_SECOND_IDX_AFTER_HOME 0x21000
#define QEI_RESET_WHEN_EQUAL                    0x21400
#define QEI_MODULO_COUNT_MODE                   0x21800
#define QEI_STOP_WHEN_IDLE                      0x22000
// Constants used in setup_qei() second param are:
#define QEI_QEA_INVERTED                        0x0010
#define QEI_QEB_INVERTED                        0x0020
#define QEI_IDX_INVERTED                        0x0040
#define QEI_HOME_INVERTED                       0x0080
#define QEI_SWAP_AB                             0x0100
#define QEI_OUTPUT_DISABLED                     0x0000
#define QEI_OUTPUT_HIGH_GE                      0x0200 // when POSxCNT >= QEIxGEC
#define QEI_OUTPUT_HIGH_LE                      0x0400 // when POSxCNT <= QEIxLEC
#define QEI_OUTPUT_HIGH_LE_GE                   0x0600 // when QEIxLEC >= POSxCNT >= QEIxGEC
#define QEI_FILTER_DIV_1                        0x0000
#define QEI_FILTER_DIV_2                        0x0800
#define QEI_FILTER_DIV_4                        0x1000
#define QEI_FILTER_DIV_8                        0x1800
#define QEI_FILTER_DIV_16                       0x2000
#define QEI_FILTER_DIV_32                       0x2800
#define QEI_FILTER_DIV_64                       0x3000
#define QEI_FILTER_DIV_256                      0x3800
#define QEI_FILTER_ENABLED                      0x4000
#define QEI_HOME_TRIGGERS_CAPTURE               0x8000
// Constants used in setup_qei() third param are: //Forth param is less then or equal compare value, Fifth param is greater then or equal compare value, Sixth param is initilization value
#define QEI_IDX_INT_ENABLED                     0x0001
#define QEI_HOME_INT_ENABLED                    0x0004
#define QEI_VELOCITY_INT_ENABLED                0x0010
#define QEI_POS_HOMING_INT_ENABLED              0x0040
#define QEI_POS_OVERFLOW_INT_ENABLED            0x0100
#define QEI_POS_LE_INT_ENABLED                  0x0400
#define QEI_POS_GE_INT_ENABLED                  0x1000
// Constants returned from qei_status() are:
#define QEI_IDX_INT                             0x0002
#define QEI_HOME_INT                            0x0008
#define QEI_VELOCITY_OVERFLOW_INT               0x0020
#define QEI_POS_REINITIALIZED_INT               0x0080
#define QEI_POS_OVERFLOW_INT                    0x0200
#define QEI_POS_LE_INT                          0x0800 // POSxCNT <= QEIxLEC
#define QEI_POS_GE_INT                          0x2000 // POSxCNT >= QEIxGEC
#define QEI_QEA_HIGH                           0x10000
#define QEI_QEB_HIGH                           0x20000
#define QEI_INDEX_HIGH                         0x40000
#define QEI_HOME_HIGH                          0x80000

////////////////////////////////////////////////////////////////// DCI
// DCI Functions: setup_dci(), dci_start(), dci_read(), dci_write(),
//                dci_data_received(), dci_transmit_ready()
// DCI Prototypes:
_bif void setup_dci(unsigned int16 mode, unsigned int16 size, unsigned int16 receive_slot, unsigned int16 transmit_slot, unsigned int16 sample_rate);
_bif void dci_start(void);
_bif signed int16 dci_read(void);
_bif void dci_write(signed int16);
_bif int1 dci_data_received(void);
_bif int1 dci_transmit_ready(void);
// Constants used in setup_dci() first param are:
#define MULTICHANNEL_MODE  0x0000
#define I2S_MODE           0x0001
#define AC97_16BIT_MODE    0x0002
#define AC97_20BIT_MODE    0x0003

#define JUSTIFY_DATA       0x0020 //Start data transmission on the same clock cycle as COFS pulses (multichannel)
#define MULTI_DEVICE_BUS   0x0040 //Tri-states the CSDO pin during unused time slots, normally drives '0'

#define UNDERFLOW_LAST     0x0080 //Transmits the last written value to the dci when data underflow occurs. Default is undeflow silence.
#define UNDERFLOW_SILENCE  0x0000 //Transmit '0's on data undeflow. This will cause a clicking noise if you are underflowing data while outputing to a codec.

#define DCI_SLAVE          0x0100 //Default is master
#define DCI_MASTER         0x0000 

#define SAMPLE_FALLING_EDGE 0x0000 //Default is Sample on the rising edge of the clock
#define SAMPLE_RISING_EDGE 0x0200

#define DCI_CLOCK_INPUT    0x0400 //SCLK is an input (supplied by codec or external source)
#define DCI_CLOCK_OUTPUT   0x0000 //Default is clock output

#define ENABLE_LOOPBACK    0x0800 //Connect the CSDI/CSDO internally; loops all of the sound back onto the bus

#define CODEC_MULTICHANNEL  0x0000  //enables multichannel (generic) codec support
#define CODEC_I2S           0x0001  //enables the I2S protocol
#define CODEC_AC16          0x0002  //enables the AC-16 protocol, setupCodecTransmission has no effect
#define CODEC_AC20          0x0003  //enables the AC-20 protocol, setupCodecTransmission has no effect

#define BUS_MASTER          0x0000  //designates this device as the bus master
#define BUS_SLAVE           0x0300  //designates this device as a slave on a bus controlled by another codec

#define TRISTATE_BUS        0x0040        //when in master mode, the module will be in high impedance 
                                    //during disabled frames (default drives 0's onto bus)
#define SYNC_COFS_DATA_PULSE 0x0020 //signifies that data starts transmitting on the same SCK pulse as the edge of the COFS pulse
                                    //(default data starts on the clock after the rising edge of COFS             
/* Determines when a sample is taken */
#define SAMPLE_RISING        0x0200 //sample data on the rising edge of the clock
#define SAMPLE_FALLING       0x0000 //sample data on the falling edge of the clock

// Constants used in setup_dci() second param are:
#define DCI_4BIT_WORD      0x0003
#define DCI_5BIT_WORD      0x0004
#define DCI_6BIT_WORD      0x0005
#define DCI_7BIT_WORD      0x0006
#define DCI_8BIT_WORD      0x0007
#define DCI_9BIT_WORD      0x0008
#define DCI_10BIT_WORD     0x0009
#define DCI_11BIT_WORD     0x000A
#define DCI_12BIT_WORD     0x000B
#define DCI_13BIT_WORD     0x000C
#define DCI_14BIT_WORD     0x000D
#define DCI_15BIT_WORD     0x000E
#define DCI_16BIT_WORD     0x000F

#define DCI_1WORD_FRAME    0x0000
#define DCI_2WORD_FRAME    0x0010 << 1
#define DCI_3WORD_FRAME    0x0020 << 1
#define DCI_4WORD_FRAME    0x0030 << 1
#define DCI_5WORD_FRAME    0x0040 << 1
#define DCI_6WORD_FRAME    0x0050 << 1
#define DCI_7WORD_FRAME    0x0060 << 1
#define DCI_8WORD_FRAME    0x0070 << 1
#define DCI_9WORD_FRAME    0x0080 << 1
#define DCI_10WORD_FRAME   0x0090 << 1
#define DCI_11WORD_FRAME   0x00A0 << 1
#define DCI_12WORD_FRAME   0x00B0 << 1
#define DCI_13WORD_FRAME   0x00C0 << 1
#define DCI_14WORD_FRAME   0x00D0 << 1
#define DCI_15WORD_FRAME   0x00E0 << 1
#define DCI_16WORD_FRAME   0x00F0 << 1

#define DCI_1WORD_INTERRUPT 0x0000
#define DCI_2WORD_INTERRUPT 0x0400
#define DCI_3WORD_INTERRUPT 0x0800
#define DCI_4WORD_INTERRUPT 0x0C00

// Constants used in setup_dci() third param are:
#define RECEIVE_NONE    0x0000
#define RECEIVE_ALL     0xFFFF
#define RECEIVE_SLOT0   0x0001
#define RECEIVE_SLOT1   0x0002
#define RECEIVE_SLOT2   0x0004
#define RECEIVE_SLOT3   0x0008
#define RECEIVE_SLOT4   0x0010
#define RECEIVE_SLOT5   0x0020
#define RECEIVE_SLOT6   0x0040
#define RECEIVE_SLOT7   0x0080
#define RECEIVE_SLOT8   0x0100
#define RECEIVE_SLOT9   0x0200
#define RECEIVE_SLOT10  0x0400
#define RECEIVE_SLOT11  0x0800
#define RECEIVE_SLOT12  0x1000
#define RECEIVE_SLOT13  0x2000
#define RECEIVE_SLOT14  0x4000
#define RECEIVE_SLOT15  0x8000

// Constants used in setup_dci() forth param are:
#define TRANSMIT_NONE   0x0000
#define TRANSMIT_ALL    0xFFFF
#define TRANSMIT_SLOT0  0x0001
#define TRANSMIT_SLOT1  0x0002
#define TRANSMIT_SLOT2  0x0004
#define TRANSMIT_SLOT3  0x0008
#define TRANSMIT_SLOT4  0x0010
#define TRANSMIT_SLOT5  0x0020
#define TRANSMIT_SLOT6  0x0040
#define TRANSMIT_SLOT7  0x0080
#define TRANSMIT_SLOT8  0x0100
#define TRANSMIT_SLOT9  0x0200 
#define TRANSMIT_SLOT10 0x0400
#define TRANSMIT_SLOT11 0x0800
#define TRANSMIT_SLOT12 0x1000
#define TRANSMIT_SLOT13 0x2000 
#define TRANSMIT_SLOT14 0x4000
#define TRANSMIT_SLOT15 0x8000


////////////////////////////////////////////////////////////////// DMA
// DMA Functions: setup_dma(), dma_start(), dma_status()
// DMA Prototypes:
_bif void setup_dma(unsigned int8 channel, unsigned int32 pheripheral, unsigned int8 mode);
_bif void dma_start(unsigned int8 channel, unsigned int16 mode, unsigned int16 addressa);
_bif void dma_start(unsigned int8 channel, unsigned int16 mode, unsigned int16 addressa, unsigned int16 count);
_bif void dma_start(unsigned int8 channel, unsigned int16 mode, unsigned int16 addressa, unsigned int16 addressb);
_bif void dma_start(unsigned int8 channel, unsigned int16 mode, unsigned int16 addressa, unsigned int16 addressb, unsigned int16 count);
_bif unsigned int8 dma_status(unsigned int8 channel);
// Constants used in setup_dma() second param are:
#define DMA_IN_SPI1      (0x0A0000|getenv("sfr:SPI1BUF"))
#define DMA_OUT_SPI1     (0x8A0000|getenv("sfr:SPI1BUF"))
#define DMA_IN_SPI2      (0x210000|getenv("sfr:SPI2BUF"))
#define DMA_OUT_SPI2     (0xA10000|getenv("sfr:SPI2BUF"))
#define DMA_IN_UART1     (0x0B0000|getenv("sfr:U1RXREG"))
#define DMA_OUT_UART1    (0x8C0000|getenv("sfr:U1TXREG"))
#define DMA_IN_UART2     (0x1E0000|getenv("sfr:U2RXREG"))
#define DMA_OUT_UART2    (0x9F0000|getenv("sfr:U2TXREG"))
#define DMA_IN_ADC1      (0x0D0000|getenv("sfr:ADC1BUF0"))
#define DMA_IN_ADC2      (0x150000|getenv("sfr:ADC2BUF0"))
#define DMA_IN_ECAN1     (0x220000|getenv("sfr:C1RXD"))
#define DMA_OUT_ECAN1    (0xC60000|getenv("sfr:C1TXD"))
#define DMA_INT0         0x000000 // or in direction and perif address
#define DMA_IC1          0x010000 // or in direction and perif address
#define DMA_IC2          0x050000 // or in direction and perif address
#define DMA_OC1          0x020000 // or in direction and perif address
#define DMA_OC2          0x060000 // or in direction and perif address
#define DMA_TIMER2       0x070000 // or in direction and perif address
#define DMA_TIMER3       0x080000 // or in direction and perif address
#define DMA_OUT_DCI      (0xBC0000|getenv("sfr:TXBUF0"))
#define DMA_IN_DCI       (0x3C0000|getenv("sfr:RXBUF0"))
#define DMA_IN          0x00
#define DMA_OUT         0x800000
// Constants used in setup_dma() third param are:
#define DMA_BYTE        0x40
#define DMA_WORD        0x00  // default
#define DMA_HALF_INT    0x10  // interrupt when half full
#define DMA_WRITE_NULL  0x08
// Constants used in dma_start() second param are:
#define DMA_CONTINOUS   0x00
#define DMA_ONE_SHOT    0x01
#define DMA_PING_PONG   0x02
#define DMA_NO_INC      0x10
#define DMA_PERIF_ADDR  0x20 // Device supplies address
#define DMA_FORCE_NOW  0x100
// Constants returned from dma_status() are:
#define DMA_IN_ERROR    0x01
#define DMA_OUT_ERROR   0x02
#define DMA_B_SELECT    0x04

////////////////////////////////////////////////////////////////// BIF
// Built In Functions Prototypes
//
// Math Prototypes:
_bif signed int8 abs(signed int8 x);
_bif signed int16 abs(signed int16 x);
_bif signed int32 abs(signed int32 x);
_bif float32 abs(float32 x);
_bif unsigned int16 _mul(unsigned int8, unsigned int8);
_bif signed int16 _mul(signed int8, signed int8);
_bif unsigned int32 _mul(unsigned int16, unsigned int16);
_bif signed int32 _mul(signed int16, signed int16);
_bif signed int48 abs(signed int48 x);
_bif signed int64 abs(signed int64 x);
_bif float48 abs(float48 x);
_bif float64 abs(float64 x);
_bif unsigned int64 _mul(unsigned int32, unsigned int32);
_bif signed int64 _mul(signed int32, signed int32);
_bif unsigned int64 _mul(unsigned int48, unsigned int48);
_bif signed int64 _mul(signed int48, signed int48);

// Memory Manipulation Prototypes:
_bif void strcpy(char* dest, char* src);
_bif void strcopy(char* dest, char* src);
_bif void memset(unsigned int8* destination, unsigned int8 value, unsigned int16 num);
_bif void memcpy(unsigned int8* destination, unsigned int8* source, unsigned int16 num);

// Data Manipulators Prototypes:
_bif int1 shift_left(unsigned int8* address, unsigned int8 bytes, int1 value);
_bif int1 shift_right(unsigned int8* address, unsigned int8 bytes, int1 value);
_bif void rotate_left(unsigned int8* address, unsigned int8 bytes);
_bif void rotate_right(unsigned int8* address, unsigned int8 bytes);
_bif void swap(unsigned int8 value);
_bif unsigned int8 make8(unsigned int16 var, unsigned int8 offset);
_bif unsigned int8 make8(unsigned int32 var, unsigned int8 offset);
_bif unsigned int16 make16(unsigned int8 varhigh, unsigned int8 varlow);
_bif unsigned int32 make32(unsigned int16 var1);
_bif unsigned int32 make32(unsigned int16 var1, unsigned int16 var2);
_bif unsigned int32 make32(unsigned int16 var1, unsigned int8 var2);
_bif unsigned int32 make32(unsigned int16 var1, unsigned int8 var2, unsigned int8 var3);
_bif unsigned int32 make32(unsigned int8 var1);
_bif unsigned int32 make32(unsigned int8 var1, unsigned int8 var2);
_bif unsigned int32 make32(unsigned int8 var1, unsigned int8 var2, unsigned int8 var3);
_bif unsigned int32 make32(unsigned int8 var1, unsigned int8 var2, unsigned int8 var3, unsigned int8 var4);
_bif unsigned int32 make32(unsigned int8 var1, unsigned int16 var2);
_bif unsigned int32 make32(unsigned int8 var1, unsigned int16 var2, unsigned int8 var3);
_bif unsigned int32 make32(unsigned int8 var1, unsigned int8 var2, unsigned int16 var3);
_bif void bit_set(unsigned int8 var, unsigned int8 bit);
_bif void bit_set(unsigned int16 var, unsigned int8 bit);
_bif void bit_set(unsigned int32 var, unsigned int8 bit);
_bif void bit_clear(unsigned int8 var, unsigned int8 bit);
_bif void bit_clear(unsigned int16 var, unsigned int8 bit);
_bif void bit_clear(unsigned int32 var, unsigned int8 bit);
_bif int1 bit_test(unsigned int8 var, unsigned int8 bit);
_bif int1 bit_test(unsigned int16 var, unsigned int8 bit);
_bif int1 bit_test(unsigned int32 var, unsigned int8 bit);
_bif void bit_set(unsigned int48 var, unsigned int8 bit);
_bif void bit_set(unsigned int64 var, unsigned int8 bit);
_bif void bit_clear(unsigned int48 var, unsigned int8 bit);
_bif void bit_clear(unsigned int64 var, unsigned int8 bit);
_bif int1 bit_test(unsigned int48 var, unsigned int8 bit);
_bif int1 bit_test(unsigned int64 var, unsigned int8 bit);
_bif unsigned int8 bit_first(int1 value, unsigned int16 var);
_bif unsigned int8 bit_last(int16 var);
_bif unsigned int8 bit_last(int1 value, int16 var);

// #use delay() Prototypes:
_bif void delay_cycles(unsigned int16 count);
_bif void delay_ms(unsigned int16 time);
_bif void delay_us(unsigned int16 time);

// #use rs232() Prototypes:
_bif void putchar(char cdata);
_bif void putchar(char cdata, unsigned int8 stream);
_bif void puts(char* string);
_bif void puts(char* string, unsigned int8 stream);
_bif char getch(void);
_bif char getch(unsigned int8 stream);
_bif void gets(char* string);
_bif void gets(char* string, unsigned int8 stream);
_bif int1 kbhit(void);
_bif int1 kbhit(unsigned int8 stream);
_bif void printf(char* string, ...);
_bif void fprintf(unsigned int8 stream, char* string, ...);
_bif void putc_send(void);
_bif void fputc_send(unsigned int8 stream);
_bif int1 rcv_buffer_full(void);
_bif int1 rcv_buffer_full(unsigned int8 stream);
_bif unsigned int16 rcv_buffer_bytes(void);
_bif unsigned int16 rcv_buffer_bytes(unsigned int8 stream);
_bif int1 tx_buffer_full(void);
_bif int1 tx_buffer_full(unsigned int8 stream);
_bif unsigned int16 tx_buffer_bytes(void);
_bif unsigned int16 tx_buffer_bytes(unsigned int8 stream);

// #use i2c() Prototypes:
_bif unsigned int8 i2c_read(void);
_bif unsigned int8 i2c_read(unsigned int8 stream);
_bif unsigned int8 i2c_read(unsigned int8 stream, int1 ack);
_bif int1 i2c_write(unsigned int8 data);
_bif int1 i2c_write(unsigned int8 stream, unsigned int8 data);
_bif void i2c_start(void);
_bif void i2c_start(unsigned int8 stream);
_bif void i2c_start(unsigned int8 stream, unsigned int8 restart);
_bif void i2c_stop(void);
_bif void i2c_stop(unsigned int8 stream);
_bif int8 i2c_isr_state(void);
_bif void i2c_slaveaddr(unsigned int8 addr);
_bif void i2c_slaveaddr(unsigned int8 stream, unsigned int8 addr);
_bif int1 i2c_poll(void);
_bif int1 i2c_poll(unsigned int8 stream);
_bif void i2c_init(unsigned int32 baud);
_bif void i2c_init(unsigned int8 stream, unsigned int32 baud);

// #use spi() Prototypes:
_bif unsigned int8 spi_xfer(void);
_bif unsigned int16 spi_xfer(void);
_bif unsigned int32 spi_xfer(void);
_bif unsigned int8 spi_xfer(unsigned int8 data);
_bif unsigned int16 spi_xfer(unsigned int16 data);
_bif unsigned int32 spi_xfer(unsigned int32 data);
_bif unsigned int8 spi_xfer(unsigned int8 stream, unsigned int8 data);
_bif unsigned int16 spi_xfer(unsigned int8 stream, unsigned int16 data);
_bif unsigned int32 spi_xfer(unsigned int8 stream, unsigned int32 data);
_bif unsigned int8 spi_xfer(unsigned int8 stream, unsigned int8 data, unsigned int8 bits);
_bif unsigned int16 spi_xfer(unsigned int8 stream, unsigned int16 data, unsigned int8 bits);
_bif unsigned int32 spi_xfer(unsigned int8 stream, unsigned int32 data, unsigned int8 bits);
_bif void spi_init(unsigned int32 baud);
_bif void spi_init(unsigned int8 stream, unsigned int32 baud);
_bif void spi_speed(unsigned int32 baud);
_bif void spi_speed(unsigned int8 stream, unsigned int32 baud);
_bif void spi_speed(unsigned int8 stream, unsigned int32 baud, unsigned int32 clock);
_bif void spi_prewrite(unsigned int8 data);
_bif void spi_prewrite(unsigned int16 data);
_bif void spi_prewrite(unsigned int32 data);
_bif void spi_prewrite(unsigned int8, unsigned int8 data);
_bif void spi_prewrite(unsigned int8, unsigned int16 data);
_bif void spi_prewrite(unsigned int8, unsigned int32 data);
_bif unsigned int8 spi_xfer_in(void);
_bif unsigned int16 spi_xfer_in(void);
_bif unsigned int32 spi_xfer_in(void);
_bif unsigned int8 spi_xfer_in(unsigned int8 bits);
_bif unsigned int16 spi_xfer_in(unsigned int8 bits);
_bif unsigned int32 spi_xfer_in(unsigned int8 bits);
_bif unsigned int8 spi_xfer_in(unsigned int8 stream, unsigned int8 bits);
_bif unsigned int16 spi_xfer_in(unsigned int8 stream, unsigned int8 bits);
_bif unsigned int32 spi_xfer_in(unsigned int8 stream, unsigned int8 bits);

// #use rtos() Prototypes:
_bif void rtos_run(void);
_bif void rtos_yield(void);
_bif void rtos_enable(unsigned int8 task);
_bif void rtos_disable(unsigned int8 task);
_bif void rtos_terminate(void);
_bif void rtos_await(int1 flag);
_bif void rtos_wait(unsigned int8 sem);
_bif void rtos_signal(unsigned int8 sem);
_bif void rtos_msg_send(unsigned int8 task, unsigned int8 msg);
_bif unsigned int8 rtos_msg_read(void);
_bif unsigned int8 rtos_msg_poll(void);
_bif int1 rtos_overrun(unsigned int8 task);
_bif void rtos_stats(unsigned int8 task, unsigned int8* stat);

// #use timer() Prototypes:
_bif unsigned int8 get_ticks(void);
_bif unsigned int16 get_ticks(void);
_bif unsigned int32 get_ticks(void);
_bif unsigned int64 get_ticks(void);
_bif unsigned int8 get_ticks(unsigned int8 stream);
_bif unsigned int16 get_ticks(unsigned int8 stream);
_bif unsigned int32 get_ticks(unsigned int8 stream);
_bif unsigned int64 get_ticks(unsigned int8 stream);
_bif void set_ticks(unsigned int8 value);
_bif void set_ticks(unsigned int16 value);
_bif void set_ticks(unsigned int32 value);
_bif void set_ticks(unsigned int64 value);
_bif void set_ticks(unsigned int8 stream, unsigned int8 value);
_bif void set_ticks(unsigned int8 stream, unsigned int16 value);
_bif void set_ticks(unsigned int8 stream, unsigned int32 value);
_bif void set_ticks(unsigned int8 stream, unsigned int64 value);

// #use pwm() Prototypes:
_bif void pwm_on(void);
_bif void pwm_on(unsigned int8 stream);
_bif void pwm_off(void);
_bif void pwm_off(unsigned int8 stream);
_bif void pwm_set_duty(unsigned int16 duty);
_bif void pwm_set_duty(unsigned int8 stream, unsigned int16 duty);
_bif void pwm_set_duty_percent(unsigned int16 percent);
_bif void pwm_set_duty_percent(unsigned int8 stream, unsigned int16 percent);
_bif void pwm_set_frequency(unsigned int32 frequency);
_bif void pwm_set_frequency(unsigned int8 stream, unsigned int32 frequency);

// #use capture() Prototypes:
_bif unsigned int16 get_capture_time(void);
_bif unsigned int16 get_capture_time(unsigned int8 stream);
_bif int1 get_capture_event(void);
_bif int1 get_capture_event(unsigned int8 stream);

// Enviroment Prototypes:
//_bif unsigned int8 getenv(char* cstring);

// Address Prototypes:
#ifndef __ADDRESS__
 typedef unsigned int32 __ADDRESS__;
#endif
_bif void goto_address(__ADDRESS__ address);
_bif __ADDRESS__ label_address(__ADDRESS__ label);

// Program Memory Prototypes:
_bif void read_program_memory(__ADDRESS__ address, unsigned int8* dataptr, unsigned int16 count);
_bif void erase_program_memory(__ADDRESS__ address);
_bif void write_program_memory(__ADDRESS__ address, unsigned int8* dataptr, unsigned int16 count);
_bif void read_configuration_memory(unsigned int8* dataptr, unsigned int8 count);
_bif void write_configuration_memory(unsigned int8* dataptr, unsigned int8 count);

// #use touchpad() Prototypes:
_bif void touchpad_state(unsigned int8 state);
_bif char touchpad_getc(void);
_bif int1 touchpad_hit(void);
////////////////////////////////////////////////////////////////// INT
// Interrupt Functions: ENABLE_INTERRUPTS(), DISABLE_INTERRUPTS(),
//                      CLEAR_INTERRUPT(), INTERRUPT_ACTIVE(),
//                      EXT_INT_EDGE()
// INT Prototypes:
_bif void enable_interrupts(unsigned int16 interrupt);
_bif void disable_interrupts(unsigned int16 interrupt);
_bif void clear_interrupt(unsigned int16 interrupt);
_bif int1 interrupt_active(unsigned int16 interrupt);
_bif int1 interrupt_enabled(unsigned int16 interrupt);
_bif void ext_int_edge(unsigned int8 source, unsigned int8 edge);
_bif void jump_to_isr(unsigned int16 address);
// Constants used in EXT_INT_EDGE() are:
#define L_TO_H              0x40
#define H_TO_L                 0
//
// Constants used in other interrupt functions are:
#define INTR_GLOBAL               0x400
#define GLOBAL                    0x400  // For compatibility with PIC16/18
#define INTR_LEVEL0               0x500
#define INTR_LEVEL1               0x501
#define INTR_LEVEL2               0x502
#define INTR_LEVEL3               0x503
#define INTR_LEVEL4               0x504
#define INTR_LEVEL5               0x505
#define INTR_LEVEL6               0x506
#define INTR_LEVEL7               0x507

#define INTR_CN_PIN              0x8000  // or in a PIN_xx constant

#define INT_STACKERR              3
#define INT_MATHERR               4
#define INT_DMAERR                5
#define INT_EXT0                  6
#define INT_IC1                   7
#define INT_OC1                   8
#define INT_TIMER1                9
#define INT_DMA0                  69
#define INT_IC2                   70
#define INT_OC2                   71
#define INT_TIMER2                72
#define INT_TIMER3                73
#define INT_SPI1E                 74
#define INT_SPI1                  75
#define INT_RDA                   76
#define INT_TBE                   77
#define INT_ADC1                  78
#define INT_DMA1                  79
#define INT_SI2C                  81
#define INT_MI2C                  82
#define INT_CNI                   84
#define INT_EXT1                  85
#define INT_ADC2                  86
#define INT_IC7                   87
#define INT_IC8                   88
#define INT_DMA2                  89
#define INT_OC3                   90
#define INT_OC4                   91
#define INT_TIMER4                92
#define INT_TIMER5                93
#define INT_EXT2                  94
#define INT_RDA2                  95
#define INT_TBE2                  96
#define INT_SPI2E                 97
#define INT_SPI2                  98
#define INT_DMA3                  101
#define INT_IC3                   102
#define INT_IC4                   103
#define INT_IC5                   104
#define INT_IC6                   105
#define INT_OC5                   106
#define INT_OC6                   107
#define INT_OC7                   108
#define INT_OC8                   109
#define INT_TIMER6                112
#define INT_TIMER7                113
#define INT_SI2C2                 114
#define INT_MI2C2                 115
#define INT_TIMER8                116
#define INT_TIMER9                117
#define INT_EXT3                  118
#define INT_EXT4                  119
#define INT_QEI                   123
#define INT_DCIE                  124
#define INT_DCI                   125
#define INT_UART1E                130
#define INT_UART2E                131
#define INT_QEI2                  132
#define INT_SPI3                  137
#define INT_UART3E                141
#define INT_RDA3                  142
#define INT_TBE3                  143
#define INT_UART4E                144
#define INT_RDA4                  145
#define INT_TBE4                  146
#define INT_COMP                  152
#define INT_PWMSEM                154
#define INT_PWM1                  155
#define INT_PWM2                  156
#define INT_PWM3                  157
#define INT_PWM4                  158
#define INT_PMP                   164
#define INT_SPI3E                 172
#define INT_RTC                   173
#define INT_CRC                   174
#define INT_CTMU                  176
#define INT_PWM5                  180
#define INT_PWM6                  181
#define INT_SOFTWARE              193
#define INT_GENERIC               217
#define INT_OSCFAIL               218
#define INT_ADDRERR               219
#define INT_PTGSTEP               220
#define INT_PTGWDT                221
#define INT_PTG0                  222
#define INT_PTG1                  223
#define INT_PTG2                  224
#define INT_PTG3                  225

#list
