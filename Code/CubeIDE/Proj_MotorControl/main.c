#include <param.h>
#define ZERO_DAC         2049
#define MAX_OUTPUT       4096
#define MIN_OUTPUT       0
#define COUNT_4_DISPLAY  3000
#define MAX_DIV_MODE     7
#define ZERO_QEI         0x80000000
#define ZERO_HIGH        0x8000
#define MIN_QEI          0x08008000
#define MAX_QEI          0xF8008000
#define MIN_QEI_H        0x0800
#define MIN_QEI_L        0x8000
#define MAX_QEI_H        0xF800
#define MAX_QEI_L        0x8000
#define MAX_ERR          32000;

#define BT_PRESSED       0
#define BT_RELEASED      1
#define NUM_OF_PARA      6
#define NUM_OF_LED       5

#define MODE_BUTTON      input(PIN_B15)
#define UP_BUTTON        input(PIN_B14)
#define POS_BUTTON       input(PIN_B13)
#define DATA_BUTTON      input(PIN_B12)
#define ALL_BUTTON       input(PIN_F0)
#define WRITE_SIZE       getenv("FLASH_WRITE_SIZE")
#define FLS_ADDRESS      0x2000
#define ENA_CTR          (input(PIN_D5) == 0)

unsigned int16 oldValue;
unsigned long curOrigin, setOrigin;
long setPos, curPos;
long err;
long kp;
long sum;
long sumMax;
long countTi;
long setTi;
long oldNumber;
long maxError;
char runDir;
boolean stableMode;
//long saveSet1 = 0;
//long saveSet2 = 0;

BYTE data[7];
BYTE saveData[7];
int modePara;
int modeParaOld;
int1 selectMode;
unsigned long parameter[NUM_OF_PARA + 1];
unsigned long maximumValue[NUM_OF_PARA] = 
    {99999, 99999, 99999, 99999, 11111, 11111};
unsigned long minimumValue[NUM_OF_PARA] = 
    {  100,     1,   200,     1,     0, 00000};

unsigned int paraCharArray[NUM_OF_PARA];
unsigned int maximumArray[NUM_OF_PARA];
int curInputPosition = 0;
int paraEnterMode = 0;
int countButton = 0;
int1 InternalEnable = 0;
int1 normalBit;
int1 firstRun;

void sendNumber (long i);
void writeTo5Leds();
void setupQEI1();
void setupQEI2();
void initPid ();
void paramPid();
void pidCal ();
void Num2CharArray(unsigned long number, unsigned long maximum);
int1 difI2CData ();
void saveOldData ();
void updateLeds();
void ReadParaFromFLS() ;
void SaveParaEnter(unsigned int mode);
void WritePara2FLS();
void correctBits (unsigned long paramIndex);

#INT_TIMER2
void timer2ISR(){
   disable_interrupts(INT_TIMER2);
   if (paraEnterMode == 0) sendNumber(curPos);
   updateLeds();
   set_timer2(0);
   clear_interrupt(INT_TIMER2);
   enable_interrupts(INT_TIMER2);
}

#INT_EXT1
void butonPress(){
   disable_interrupts(INT_EXT1);
   if (paraEnterMode == 1) {
        if (MODE_BUTTON == BT_PRESSED) {
            modePara++;
            if (modePara >= (NUM_OF_PARA)) modePara = 0;
            data[0] = 15;
            data[1] = 0;
            data[2] = 0;
            data[3] = 0;
            data[4] = modePara;
            data[5] = NUM_OF_LED + 1;
            data[6] = NUM_OF_LED + 1;
            updateLeds();
        } 
        else if (UP_BUTTON == BT_PRESSED) {
            paraCharArray[curInputPosition]++;
            if (paraCharArray[curInputPosition] > maximumArray[curInputPosition]) paraCharArray[curInputPosition] = 0;
        } 
        else if (POS_BUTTON == BT_PRESSED) {
            curInputPosition++;
            if (curInputPosition >= NUM_OF_LED) curInputPosition = 0;
        } 
        else if (DATA_BUTTON == BT_PRESSED) {
            selectMode = ~selectMode;
            if (selectMode == 0) {
               SaveParaEnter(modePara);
            }
        }
        updateLeds();
        while (ALL_BUTTON == BT_PRESSED);
        delay_ms(10);
        enable_interrupts(INT_EXT1);
    }
    clear_interrupt(INT_EXT1);

}

void updateLeds(){
   if (difI2CData() == 1){
      writeTo5Leds();
      saveOldData();
   }
}

void main()
{
   //flash_address = FLS_ADDRESS;
   output_bit(PIN_A7, 1);
   set_pullup(TRUE,PIN_B5);
   set_pullup(TRUE,PIN_B12);
   set_pullup(TRUE,PIN_B13);
   set_pullup(TRUE,PIN_B14);
   set_pullup(TRUE,PIN_B15);
   set_pullup(TRUE,PIN_D5);
   set_pullup(TRUE,PIN_F0);

   output_bit(PIN_D8, 1);
   i2c_init(500000);
   sendNumber(0);
   
   delay_ms(2000);
   paramPid();
   initPid();

   paraEnterMode = 0;
   while(TRUE)
   {
      if (paraEnterMode == 0) {
         pidCal();
         if ((MODE_BUTTON == BT_PRESSED) && (DATA_BUTTON == BT_PRESSED)) {
             countButton++;
             if (countButton >= 3000) {
                 paraEnterMode = 1;
                 modePara = 0;
                 output_bit(PIN_A7, 1);
      
                 data[0] = 15;
                 data[1] = 0;
                 data[2] = 0;
                 data[3] = 0;
                 data[4] = modePara;
                 data[5] = NUM_OF_LED + 1;
                 data[6] = NUM_OF_LED + 1;
                 curInputPosition = 0;
                 updateLeds();
                 while (ALL_BUTTON == BT_PRESSED);
                 delay_ms(5);
                 clear_interrupt(INT_EXT1);
                 ext_int_edge(1, H_TO_L);
                 enable_interrupts(INT_EXT1);
             }
         } 
         else {
             countButton = 0;
         }
     } 
     else {
         while (paraEnterMode) {

             data[0] = 15;
             data[1] = 0;
             data[2] = 0;
             data[3] = 0;
             data[4] = modePara;
             data[5] = NUM_OF_LED + 1;
             data[6] = NUM_OF_LED + 1;
             updateLeds();
             modeParaOld = modePara;
            
             while (modePara == modeParaOld) {
                 selectMode = 0;
                 while (selectMode == 0) {
                     if (modePara != modeParaOld) break;
                 }
                 Num2CharArray(parameter[modePara], maximumValue[modePara]);
                 curInputPosition = 0;
                 while (selectMode == 1) {
                     data[0] = paraCharArray[4];
                     data[1] = paraCharArray[3];
                     data[2] = paraCharArray[2];
                     data[3] = paraCharArray[1];
                     data[4] = paraCharArray[0];
                     data[5] = NUM_OF_LED + 1;
                     data[6] = curInputPosition;
                     updateLeds();
                     if (modePara != modeParaOld) break;
                     if (selectMode == 0) break;
                }
                modeParaOld = modePara - 1;
            }
         }
      }
   }
}

void paramPid() {  
    ReadParaFromFLS();
    if (parameter[5] %10 == 0){  
        if (parameter[0] < 100)  parameter[0] = 100;
        if (parameter[1] < 1)    parameter[1] = 1;
        if (parameter[2] < 1000) parameter[2] = 1000;
        if (parameter[3] < 1000) parameter[3] = 1000;
        correctBits(4);
    }
    else {
      parameter[0] = 500;
      parameter[1] = 800;
      parameter[2] = 30000;
      parameter[3] = 10000;
      parameter[4] = 0;
    }
    correctBits(5);
    kp = (long) parameter[0];
    setTi = (long) parameter[1];
    sumMax = (long) parameter[2];
    maxError = (long) parameter[3];
    InternalEnable = (parameter[4] % 10);
    runDir = (parameter[4] / 10 % 10);
}
void initPid (){
   oldValue = 0;
   oldNumber = 0;
   sum = 0;
   countTi = 0; 
   stableMode = 0;
   normalBit = 1;
   firstRun = 0;
   
   sendNumber(0);
   setupQEI1();
   setupQEI2();

   spi_xfer(ZERO_DAC);
   output_bit(PIN_A7, 0); 
   
   setup_timer2(TMR_INTERNAL | TMR_DIV_BY_64, 2000);  
   enable_interrupts(INT_TIMER2);
   enable_interrupts(GLOBAL);
}
void pidCal () {
   long pid, pidlong;
   unsigned int16 value = 0;
   
   curOrigin = qei_get_count(1);
   setOrigin = qei_get_count(2);

   if ((curOrigin < MIN_QEI) || (curOrigin > MAX_QEI)){
      MCU_POS1CNTH = ZERO_HIGH;
      MCU_POS2CNTH = ZERO_HIGH;
   }
   
   if ((setOrigin < MIN_QEI) || (setOrigin > MAX_QEI)){
      MCU_POS1CNTH = ZERO_HIGH;
      MCU_POS2CNTH = ZERO_HIGH;
   }
   
   curPos = (long)(curOrigin - ZERO_QEI);
   setPos = (long)(setOrigin - ZERO_QEI);
   
   if ((ENA_CTR || InternalEnable) && normalBit) {
   
      if (firstRun == 0) {
          firstRun = 1;
          oldValue = 0;
          oldNumber = 0;
          sum = 0;
          countTi = 0; 
          stableMode = 0;
          normalBit = 1;
          
          sendNumber(0);
          qei_set_count(2, ZERO_QEI); 
          qei_set_count(1, ZERO_QEI); 
          spi_xfer(ZERO_DAC);
          output_bit(PIN_A7, 0);
          curPos = (long)(0);
          setPos = (long)(0);
          
      }

      err = setPos - curPos;
      
      if (runDir == 0){
         err = err * (-1);
      }
      if ((err > maxError) || (err < -maxError)){
         spi_xfer(ZERO_DAC);
         output_bit(PIN_D8, 0);
         output_bit(PIN_A7, 1);
         normalBit = 0;
      }
      else {
         countTi++;
         if (countTi >= setTi){
            /*
            if ((stableMode == 0) && (setPos == saveSet1) && (saveSet1 == saveSet2)){
               stableMode = 1;
               sum = 0;
            }
            else if ((setPos != saveSet1) || (saveSet1 != saveSet2)){
               stableMode = 0;
            }
            saveSet2 = saveSet1;
            saveSet1 = setPos;
            */
            sum = sum + err;
            if (sum > sumMax) {
               sum = sumMax;
            }
            else if (sum < -sumMax){
               sum = -sumMax;
            }
            countTi = 0;
         }
         pid = (kp * err + sum)/ 1000;
         pidlong = pid + ZERO_DAC;
      
         if (pidlong > MAX_OUTPUT) {
            pidlong = MAX_OUTPUT;
         }
         else if (pidlong < MIN_OUTPUT) {
            pidlong = MIN_OUTPUT;
         }
         else {
         }
         value = (unsigned int16) pidlong;
         if (value != oldValue){
            spi_xfer(value);
            oldValue = value;
         }
      }
   }
   else {
      firstRun = 0;
   }
}

void setupQEI1(){ 
   setup_qei(1, QEI_MODE_X4, QEI_FILTER_DIV_2);
   qei_set_count(1, ZERO_QEI); 
}

void setupQEI2(){
   setup_qei(2, QEI_MODE_TIMER_EXTERNAL_UPDOWN_EXTERNAL, QEI_FILTER_DIV_2);
   qei_set_count(2, ZERO_QEI);
}

void sendNumber (long i){
    unsigned long temp;
    if (i > 0) {
        temp = i;
    } else {
        temp = -i;
    }
   data[0] = (temp/10000)%10;
   data[1] = (temp/1000)%10;
   data[2] = (temp/100)%10;
   data[3] = (temp/10)%10;
   data[4] = (temp%10);
   data[5] = 6;
   data[6] = 6;
   if (i < 0) {
      data[5] = 4;
   }
}
void writeTo5Leds(){
   i2c_start();
   i2c_write(0x30);
   i2c_write(data[0]);
   i2c_write(data[1]);
   i2c_write(data[2]);
   i2c_write(data[3]);
   i2c_write(data[4]);
   i2c_write(data[5]);
   i2c_write(data[6]);
   i2c_stop();
}
void Num2CharArray(unsigned long number, unsigned long maximum) {
    paraCharArray[4] = (char)((number / 10000) % 10);
    paraCharArray[3] = (char)((number / 1000) % 10);
    paraCharArray[2] = (char)((number / 100) % 10);
    paraCharArray[1] = (char)((number / 10) % 10);
    paraCharArray[0] = (char)(number % 10);

    maximumArray[4] = (char)((maximum / 10000) % 10);
    maximumArray[3] = (char)((maximum / 1000) % 10);
    maximumArray[2] = (char)((maximum / 100) % 10);
    maximumArray[1] = (char)((maximum / 10) % 10);
    maximumArray[0] = (char)(maximum % 10);
}
void correctBits (unsigned long paramIndex){
    paraCharArray[4] = (char)((parameter[paramIndex] / 10000) % 10);
    paraCharArray[3] = (char)((parameter[paramIndex] / 1000) % 10);
    paraCharArray[2] = (char)((parameter[paramIndex] / 100) % 10);
    paraCharArray[1] = (char)((parameter[paramIndex] / 10) % 10);
    paraCharArray[0] = (char)(parameter[paramIndex] % 10);
    
   if (paraCharArray[4] > 1) paraCharArray[4] = 1;
   if (paraCharArray[3] > 1) paraCharArray[3] = 1;
   if (paraCharArray[2] > 1) paraCharArray[2] = 1;
   if (paraCharArray[1] > 1) paraCharArray[1] = 1;
   if (paraCharArray[0] > 1) paraCharArray[0] = 1;
   
   parameter[paramIndex] = paraCharArray[4] * 10000 + paraCharArray[3] * 1000 
        + paraCharArray[2] * 100 + paraCharArray[1] * 10 + paraCharArray[0];
}
int1 difI2CData (){
   int1 returnVal = 0;
   if ((saveData[0] != data[0])
   || (saveData[1] != data[1])
   || (saveData[2] != data[2])
   || (saveData[3] != data[3])
   || (saveData[4] != data[4])
   || (saveData[5] != data[5])
   || (saveData[6] != data[6])){
      returnVal = 1;
   }
   return returnVal;
}
void saveOldData (){
   memcpy(saveData, data, 7);
}
//-------------------------------------
void ReadParaFromFLS() {
    unsigned int8 dataByte[128];
    unsigned int forIndex;
    unsigned long baseAddress;
    
    read_program_memory(FLS_ADDRESS, &dataByte[0], 128);
    
    for (forIndex = 0; forIndex < (NUM_OF_PARA); forIndex++) {
      baseAddress = forIndex * 8;
      parameter[forIndex] = (dataByte[baseAddress + 4]<< 24) + (dataByte[baseAddress + 2]<< 16) 
      + (dataByte[baseAddress + 1]<< 8) + dataByte[baseAddress + 0];
    }
}
void SaveParaEnter(unsigned int mode) {
    unsigned long enterNumber = 0;
    enterNumber = paraCharArray[4] * 10000 + paraCharArray[3] * 1000 
        + paraCharArray[2] * 100 + paraCharArray[1] * 10 + paraCharArray[0];
        
    if (enterNumber <= minimumValue[mode]) {
        parameter[mode] = minimumValue[mode];
    } 
    else if (enterNumber > maximumValue[mode]) {
        parameter[mode] = maximumValue[mode];
    } 
    else {
        parameter[mode] = enterNumber;
    }
    if (mode >= 4) correctBits(mode);
    if (mode < 5) parameter[5] = 0;
    WritePara2FLS();
}
void WritePara2FLS() {
   unsigned int8 dataByte[128];
   disable_interrupts(GLOBAL);  
   dataByte[44] = (unsigned int8) (parameter[5] >> 24);
   dataByte[42] = (unsigned int8) (parameter[5] >> 16);
   dataByte[41] = (unsigned int8) (parameter[5] >> 8);
   dataByte[40] = (unsigned int8) (parameter[5]);
   dataByte[36] = (unsigned int8) (parameter[4] >> 24);
   dataByte[34] = (unsigned int8) (parameter[4] >> 16);
   dataByte[33] = (unsigned int8) (parameter[4] >> 8);
   dataByte[32] = (unsigned int8) (parameter[4]);
   dataByte[28] = (unsigned int8) (parameter[3] >> 24);
   dataByte[26] = (unsigned int8) (parameter[3] >> 16);
   dataByte[25] = (unsigned int8) (parameter[3] >> 8);
   dataByte[24] = (unsigned int8) (parameter[3]);
   dataByte[20] = (unsigned int8) (parameter[2] >> 24);
   dataByte[18] = (unsigned int8) (parameter[2] >> 16);
   dataByte[17] = (unsigned int8) (parameter[2] >> 8);
   dataByte[16] = (unsigned int8) (parameter[2]);
   dataByte[12] = (unsigned int8) (parameter[1] >> 24);
   dataByte[10] = (unsigned int8) (parameter[1] >> 16);
   dataByte[9] = (unsigned int8) (parameter[1] >> 8);
   dataByte[8] = (unsigned int8) (parameter[1]);
   dataByte[4] = (unsigned int8) (parameter[0] >> 24);
   dataByte[2] = (unsigned int8) (parameter[0] >> 16);
   dataByte[1] = (unsigned int8) (parameter[0] >> 8);
   dataByte[0] = (unsigned int8) (parameter[0]);
   write_program_memory(FLS_ADDRESS, &dataByte[0], 128); 
   enable_interrupts(GLOBAL);
}



