#include "my_iic.h"
#include "intrins.h"
 
int	grid_sq[]={1,3,0,4,6,7,5,2,8,11,9,10,13,15,14,12};
unsigned char seg_sq[]={0x08,0x20,0x40,0x80,0x04,0x10,0x02,0x01};
 
 
//2微秒
void delay(void)
{
/*	_nop_();
;*/
}
 
 
/**
  * @brief	I2C初始化
  * @param	无
  * @retval	无
	* 
  */
void I2C_init(void)
{
	I2C_SDA = 1;	//
	delay();
	I2C_SCL = 1;
	delay();
}
 
 
/**
  * @brief	I2C起始信号
  * @param	无
  * @retval	无
	* 起始条件：SCL高电平期间，SDA从高电平切换到低电平
  */
void I2C_Start(void)
{
	I2C_SDA = 1;	//拼接其他块，确保默认是1
	I2C_SCL = 1;
	delay();
	I2C_SDA = 0;	//时序上先拉低
	delay();
	I2C_SCL = 0;
}
 
/**
  * @brief	I2C停止信号
  * @param	无
  * @retval	无
	* 终止条件：SCL高电平期间，SDA从低电平切换到高电平
  */
void I2C_Stop(void)
{
	I2C_SDA = 0;	//确保默认0，保证由低电平拉高至高电平
	I2C_SCL = 1;
	delay();
	I2C_SDA = 1;
}
 
 
/**
  * @brief	I2C发送一个字节数据
  * @param	Byte 要发送的字节
  * @retval	无
	* 微处理器的数据通过两线总线接口和 FZH119 通信，在输入数据时当 CLK 是高电平时，DIN 上的信号
		必须保持不变；只有 CLK 上的时钟信号为低电平时，DIN 上的信号才能改变。数据的输入总是低位在前,高位
		在后传输.数据输入的开始条件是 CLK 为高电平时，DIN 由高变低；结束条件是 CLK 为高时，DIN 由低电平
		变为高电平。
  */
void I2C_SendByte(unsigned char Byte)
{
	unsigned char i;
	for (i = 0; i < 8; i ++)
	{		
		I2C_SDA = Byte&0x01;		//数据的输入总是低位在前,高位在后传输
		Byte=Byte>>1;
		I2C_SCL = 1;
		I2C_SCL = 0;
	}
}
 
/**
	* @brief I2C_SendReyeByte
	* IIC发送机器人眼睛段信息，数据顺序不常规
	* 机器人眼睛段地址顺序：
	* unsigned char seg_sq[]={0x08,0x20,0x40,0x80,0x04,0x10,0x20,0x01};
	* 时钟下降沿发送数据
	*/
void I2C_SendREyeByte(unsigned char Byte)
{
	unsigned char i;
	for (i = 0; i < 8; i ++)
	{		
		I2C_SDA=Byte&seg_sq[i];
		I2C_SCL = 1;
		I2C_SCL = 0;
	}
}
 
 
 
/**
* @brief 发送多个字节
	*  start -> command2 -> data1-dataN ->end
*/
void I2c_nbByte(unsigned char cmd,unsigned char* str,unsigned char len)
	
{
	unsigned char i;
	I2C_Start();//start
	I2C_SendByte(cmd);//command2
	for(i=0;i<len;i++){
		I2C_SendByte(str[i]);
	}//data1-dataN
	I2C_Stop();//end
}
 
 
/**
	* @brief I2c_nbREyeByte
	* IIC发送机器人眼睛位信息，数据顺序不常规
	* 机器人眼睛位地址顺序：
	* int grid_sq[]={1,3,0,4,6,7,5,2,9,11,8,12,14,15,13,10};
	* 时钟下降沿发送数据
  * len设置16
	*/
void I2c_nbREyeByte(unsigned char cmd,unsigned char* str,unsigned char len)
{
	unsigned char i;
	I2C_Start();//start
	I2C_SendByte(cmd);//command2
	for(i=0;i<len;i++){
			I2C_SendREyeByte(str[grid_sq[i]]);	//变化了顺序
	}//data1-dataN
	
	I2C_Stop();//end
}
 
/**
* @brief 发送命令
	* start -> command ->end
*/
 
void I2c_cmdSend(signed char cmd)
{
	I2C_Start();//start
	I2C_SendByte(cmd);//command
	I2C_Stop();//end
}
