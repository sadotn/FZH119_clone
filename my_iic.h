#ifndef __MY_IIC_H
#define __MY_IIC_H
#include <STC15F2K60S2.H>
#include "intrins.h"
 
sbit I2C_SDA = P3^7;
sbit I2C_SCL = P3^6;
 
void I2C_init(void);
void I2C_Start(void);
void I2C_Stop(void);
void I2C_SendByte(unsigned char Byte);
void I2c_nbByte(unsigned char cmd,unsigned char* str,unsigned char len);
void I2c_cmdSend(signed char cmd);
void I2c_nbREyeByte(unsigned char cmd,unsigned char* str,unsigned char len);
 
#endif
