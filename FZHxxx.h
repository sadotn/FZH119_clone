#ifndef __FZHXXX_H
#define __FZHXXX_H
#define cmdData      //010000
 
 
typedef signed char        int8_t;
typedef unsigned char      uint8_t;
typedef unsigned short     uint16_t;
 
enum GRID{
	grid1=0xc0,
	grid2,
	grid3,
	grid4,
	grid5,
	grid6,
	grid7,
	grid8,
	grid9,
	grid10,
	grid11,
	grid12,
	grid13,
	grid14,
	grid15,
	grid16
};
 
#define FZH_CMD_ON 0x88 
#define FZH_CMD_FF 0x80  
#define USAER_CMD_CYCLE_1_16  0
#define USAER_CMD_CYCLE_2_16  1
#define USAER_CMD_CYCLE_4_16  2
#define USAER_CMD_CYCLE_10_16 3
#define USAER_CMD_CYCLE_11_16 4
#define USAER_CMD_CYCLE_12_16 5
#define USAER_CMD_CYCLE_13_16 6
#define USAER_CMD_CYCLE_14_16 7
 
 
#define USAER_CMD_SHOW_ON     1
#define USAER_CMD_SHOW_OFF    0
 
 
//与硬件连接相关设置
#define START_SRAM    grid1      //是定开始扫描地址地址
 
	
int8_t fzh_WriteSram(uint8_t cmd1,uint8_t cmd2,uint8_t *str,uint8_t len,uint8_t cmd3 );
 
int8_t fzh_cmdWrite(uint8_t cmd);
int8_t fzh_cmdWriteDat(uint8_t cmd,uint8_t dat);
/***********************************************************************************************
*
*函数名 ：void fzh_SetLightGrade(uint8_t grade,uint8_t onff)
*函数功能描述 :亮度设置
*函数参数 ：grade：亮度等级 支持7个等级 参考宏定义USAER_CMD_CYCLE_  onff 0：关闭显示 其它：显示
*函数返回值 ：无
*作者 ：SY
*函数创建日期 ：20211007
*
***********************************************************************************************/
void fzh_SetLightGrade(uint8_t grade,uint8_t onff);
/***********************************************************************************************
*
*函数名 ：void fzh_Init(void)
*函数功能描述 :数码管初始化数码管显示驱动 并设为等亮度 默认显示
*函数参数 ：无
*函数返回值 ：无
*作者 ：SY
*函数创建日期 ：20211007
*
***********************************************************************************************/
void fzh_Init(void);
int8_t fzh_WriteREyeSram( uint8_t cmd1,uint8_t cmd2,uint8_t* str,uint8_t len,uint8_t cmd3 );
#endif
