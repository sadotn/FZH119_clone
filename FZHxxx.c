#include "FZHxxx.h"
#include "intrins.h"
#include "my_iic.h"
 
 
 
 
uint8_t  fzh_light_grade = 0x8c;
 
int8_t fzh_WriteSram( uint8_t cmd1,uint8_t cmd2,uint8_t* str,uint8_t len,uint8_t cmd3 ) {
    if( ( len==0 )||( len>16 ) ) {
        return -1;
    }
    I2c_cmdSend( cmd1 );
    I2c_nbByte(cmd2,str,len );
    I2c_cmdSend( cmd3 );
    return 0;
}
 
/** 
	* @brief fzh_WriteREyeSram
 
	*/
//机器人眼睛FZH119顺序
//len 输入 16
int8_t fzh_WriteREyeSram( uint8_t cmd1,uint8_t cmd2,uint8_t* str,uint8_t len,uint8_t cmd3 ) {
 
    I2c_cmdSend( cmd1 );		//显示方式设置
    I2c_nbREyeByte(cmd2,str,len );
    I2c_cmdSend( cmd3 );		//显示ON,显示亮度
    return 0;
}
 
int8_t fzh_cmdWrite( uint8_t cmd ) {
    I2c_cmdSend( cmd );
    return 0;
}
 
int8_t fzh_cmdWriteDat( uint8_t cmd,uint8_t dat ) {
    I2c_nbByte( cmd,&dat,1 );
    return 0;
}
 
 
void fzh_SetLightGrade(uint8_t grade,uint8_t onff){
	if(grade>7)grade=7;
	fzh_light_grade = 0;
	if(onff!=0){
     	fzh_light_grade = FZH_CMD_ON|grade;
	}else {
	   fzh_light_grade = FZH_CMD_FF;
	}
}
 
void fzh_Init(void){
    I2C_init();
    fzh_SetLightGrade(USAER_CMD_CYCLE_11_16,USAER_CMD_SHOW_ON);
}
