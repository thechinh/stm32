#include "fifo_camera.h"
#include "fifo.h"

extern I2C_HandleTypeDef hi2c1;

static const int ADDR = 0x42 << 1; // 0x42 for write, 0x43 for read. In HAL, the address is shifted left by 1

static const int REG_GAIN = 0x00;
static const int REG_BLUE = 0x01;
static const int REG_RED = 0x02;
static const int REG_COM1 = 0x04;
static const int REG_VREF = 0x03;
static const int REG_COM4 = 0x0d;
static const int REG_COM5 = 0x0e;
static const int REG_COM6 = 0x0f;
static const int REG_AECH = 0x10;
static const int REG_CLKRC = 0x11;
static const int REG_COM7 = 0x12;
static const int COM7_RGB = 0x04;
static const int REG_COM8 = 0x13;
static const int COM8_FASTAEC = 0x80;    // Enable fast AGC/AEC
static const int COM8_AECSTEP = 0x40;    // Unlimited AEC step size
static const int COM8_BFILT = 0x20;    // Band filter enable
static const int COM8_AGC = 0x04;    // Auto gain enable
static const int COM8_AWB = 0x02;    // White balance enable
static const int COM8_AEC = 0x0;
static const int REG_COM9 = 0x14;
static const int REG_COM10 = 0x15;
static const int REG_COM14 = 0x3E;
static const int REG_SCALING_DCWCTR = 0x72;
static const int REG_SCALING_PCLK_DIV = 0x73;
static const int REG_COM11 = 0x3B;
static const int COM11_NIGHT = 0x80;
static const int COM11_NMFR = 0x60;
static const int COM11_HZAUTO = 0x10;
static const int COM11_50HZ = 0x08;
static const int COM11_EXP = 0x0;
static const int REG_TSLB = 0x3A;
static const int REG_RGB444 = 0x8C;
static const int REG_COM15 = 0x40;
static const int COM15_RGB565 = 0x10;
static const int COM15_R00FF = 0xc0;
static const int REG_HSTART = 0x17;
static const int REG_HSTOP = 0x18;
static const int REG_HREF = 0x32;
static const int REG_VSTART = 0x19;
static const int REG_VSTOP = 0x1A;
static const int REG_COM3 = 0x0C;
static const int REG_MVFP = 0x1E;
static const int REG_COM13 = 0x3d;
static const int COM13_UVSAT = 0x40;
static const int SCALING_DCWCTR = 0x72;
static const int SCALING_PCLK_DIV = 0x73;
static const int REG_BD50MAX = 0xa5;
static const int REG_BD60MAX = 0xab;
static const int REG_AEW = 0x24;
static const int REG_AEB = 0x25;
static const int REG_VPT = 0x26;
static const int REG_HAECC1 = 0x9f;
static const int REG_HAECC2 = 0xa0;
static const int REG_HAECC3 = 0xa6;
static const int REG_HAECC4 = 0xa7;
static const int REG_HAECC5 = 0xa8;
static const int REG_HAECC6 = 0xa9;
static const int REG_HAECC7 = 0xaa;
static const int REG_COM12 = 0x3c;
static const int REG_GFIX = 0x69;
static const int REG_COM16 = 0x41;
static const int COM16_AWBGAIN = 0x08;
static const int REG_EDGE = 0x3f;
static const int REG_REG76 = 0x76;
static const int ADCCTR0 = 0x20;

void Camera_Init() {
    Fifo_Init();
    uint8_t data = 0x80;
    HAL_I2C_Mem_Write(&hi2c1, ADDR, REG_COM7, I2C_MEMADD_SIZE_8BIT, &data, 1, 100); // reset to default values
}

void Camera_Test_Image() {
    uint8_t data = 0x35 | 0x80;
    HAL_I2C_Mem_Write(&hi2c1, ADDR, 0x71, I2C_MEMADD_SIZE_8BIT, &data, 1, 100);
}

void Camera_Prepare_Capture() {
    Fifo_Write_Reset();
}

void Camera_Start_Capture() {
    Fifo_Write_Enable();
}

void Camera_Stop_Capture() {
    Fifo_Write_Disable();
}

void Camera_Read_Frame(uint8_t *frame, const uint16_t xres, const uint16_t yres, const uint8_t bytes_per_pixel) {
    Fifo_Read_Reset();
    uint8_t i = 0;
    for(uint8_t y = 0; y < yres; y++) 
        for(uint8_t x = 0; x < xres; x++)
            for(uint8_t b = 0; b < bytes_per_pixel; b++)
                frame[i++] = Fifo_Read_Byte();
}

void Camera_Read_Frame_Only_Second_Byte(uint8_t *frame, const uint16_t xres, const uint16_t yres) {
    Fifo_Read_Reset();
    uint8_t i = 0;
    for(uint8_t y = 0; y < yres; y++) 
        for(uint8_t x = 0; x < xres; x++) {
            Fifo_Skip_Byte();
            frame[i++] = Fifo_Read_Byte();
        }
}

// TODO: double check
// void writeRegisters(const uint8_t data[][2])
// {
//     for(int i = 0; data[i][0] != 0xff; i++)
//       HAL_I2C_Mem_Write(&hi2c1, ADDR, data[i][0], I2C_MEMADD_SIZE_8BIT, data[i][1], 1, 100);
// }

void saturation(int s) { // -2..2
    //color matrix values
    uint8_t data = 0x80 + 0x20 * s;
    HAL_I2C_Mem_Write(&hi2c1, ADDR, 0x4f, I2C_MEMADD_SIZE_8BIT, &data, 1, 100);
    HAL_I2C_Mem_Write(&hi2c1, ADDR, 0x50, I2C_MEMADD_SIZE_8BIT, &data, 1, 100);
    data = 0x00;
    HAL_I2C_Mem_Write(&hi2c1, ADDR, 0x51, I2C_MEMADD_SIZE_8BIT, &data, 1, 100);
    data = 0x22 + (0x11 * s) / 2;
    HAL_I2C_Mem_Write(&hi2c1, ADDR, 0x52, I2C_MEMADD_SIZE_8BIT, &data, 1, 100);
    data = 0x5e + (0x2f * s) / 2;
    HAL_I2C_Mem_Write(&hi2c1, ADDR, 0x53, I2C_MEMADD_SIZE_8BIT, &data, 1, 100);
    data = 0x80 + 0x20 * s;
    HAL_I2C_Mem_Write(&hi2c1, ADDR, 0x54, I2C_MEMADD_SIZE_8BIT, &data, 1, 100);
    data = 0x9e;
    HAL_I2C_Mem_Write(&hi2c1, ADDR, 0x58, I2C_MEMADD_SIZE_8BIT, &data, 1, 100);  //matrix signs
}

void frameControl(int hStart, int hStop, int vStart, int vStop)
{
    uint8_t data = hStart >> 3;
    HAL_I2C_Mem_Write(&hi2c1, ADDR, REG_HSTART, I2C_MEMADD_SIZE_8BIT, &data, 1, 100);
    data = hStop >> 3;
    HAL_I2C_Mem_Write(&hi2c1, ADDR, REG_HSTOP, I2C_MEMADD_SIZE_8BIT, &data, 1, 100);
    data = ((hStop & 0b111) << 3) | (hStart & 0b111);
    HAL_I2C_Mem_Write(&hi2c1, ADDR, REG_HREF, I2C_MEMADD_SIZE_8BIT, &data, 1, 100);

    data = vStart >> 2;
    HAL_I2C_Mem_Write(&hi2c1, ADDR, REG_VSTART, I2C_MEMADD_SIZE_8BIT, &data, 1, 100);
    data = vStop >> 2;
    HAL_I2C_Mem_Write(&hi2c1, ADDR, REG_VSTOP, I2C_MEMADD_SIZE_8BIT, &data, 1, 100);
    data = ((vStop & 0b11) << 2) | (vStart & 0b11);
    HAL_I2C_Mem_Write(&hi2c1, ADDR, REG_VREF, I2C_MEMADD_SIZE_8BIT, &data, 1, 100);
}

void QQVGA()
{
    //160x120 (1/4)
    uint8_t data = 0x1a;
    HAL_I2C_Mem_Write(&hi2c1, ADDR, REG_COM14, I2C_MEMADD_SIZE_8BIT, &data, 1, 100); //pixel clock divided by 4, manual scaling enable, DCW and PCLK controlled by register
    data = 0x22;
    HAL_I2C_Mem_Write(&hi2c1, ADDR, SCALING_DCWCTR, I2C_MEMADD_SIZE_8BIT, &data, 1, 100); //downsample by 4
    data = 0xf2;
    HAL_I2C_Mem_Write(&hi2c1, ADDR, SCALING_PCLK_DIV, I2C_MEMADD_SIZE_8BIT, &data, 1, 100); //pixel clock divided by 4
}

void Camera_QQVGARGB565()
  {
    uint8_t data = 0b10000000;
    HAL_I2C_Mem_Write(&hi2c1, ADDR, REG_COM7, I2C_MEMADD_SIZE_8BIT, &data, 1, 100);  //all registers default

    data = 0b10000000;    
    HAL_I2C_Mem_Write(&hi2c1, ADDR, REG_CLKRC, I2C_MEMADD_SIZE_8BIT, &data, 1, 100); //double clock
    data = 0b1000 | 0b10;
    HAL_I2C_Mem_Write(&hi2c1, ADDR, REG_COM11, I2C_MEMADD_SIZE_8BIT, &data, 1, 100); //enable auto 50/60Hz detect + exposure timing can be less...
    data = 0b100;
    HAL_I2C_Mem_Write(&hi2c1, ADDR, REG_TSLB, I2C_MEMADD_SIZE_8BIT, &data, 1, 100); //sequence UYVY

    data = 0b100;
    HAL_I2C_Mem_Write(&hi2c1, ADDR, REG_COM7, I2C_MEMADD_SIZE_8BIT, &data, 1, 100); //RGB
    data = 0b11000000 | 0b010000;
    HAL_I2C_Mem_Write(&hi2c1, ADDR, REG_COM15, I2C_MEMADD_SIZE_8BIT, &data, 1, 100); //RGB565

    frameControl(192, 48, 8, 488); //no clue why horizontal needs such strange values, vertical works ok
    
    data = 0x02;
    HAL_I2C_Mem_Write(&hi2c1, ADDR, REG_COM10, I2C_MEMADD_SIZE_8BIT, &data, 1, 100); //VSYNC negative
    data = 0x04;
    HAL_I2C_Mem_Write(&hi2c1, ADDR, REG_COM3, I2C_MEMADD_SIZE_8BIT, &data, 1, 100);  //DCW enable
    data = 0x2b;
    HAL_I2C_Mem_Write(&hi2c1, ADDR, REG_MVFP, I2C_MEMADD_SIZE_8BIT, &data, 1, 100);  //mirror flip

    QQVGA();
    
    data = 0x84;
    HAL_I2C_Mem_Write(&hi2c1, ADDR, 0xb0, I2C_MEMADD_SIZE_8BIT, &data, 1, 100);// no clue what this is but it's most important for colors
    saturation(0);
    data = 0xe7;
    HAL_I2C_Mem_Write(&hi2c1, ADDR, 0x13, I2C_MEMADD_SIZE_8BIT, &data, 1, 100); //AWB on
    data = 0x9f;
    HAL_I2C_Mem_Write(&hi2c1, ADDR, 0x6f, I2C_MEMADD_SIZE_8BIT, &data, 1, 100); // Simple AWB
  }