#include <STC15F2K60S2.H>
#include "intrins.h"
#include "FZHxxx.h"
 
unsigned char fangkuang1[]={0x10,0xFE,0x92,0x92,0xFE,0x92,0x10,0x10,0xFF,0xFD,0x91,0xFD,0x9D,0xFD,0x81,0xFF};
unsigned char fangkuang2[]={0x24,0x7E,0xFF,0xFF,0xFF,0x7E,0x3C,0x18,0x24,0x7E,0xFF,0xFF,0xFF,0x7E,0x3C,0x18};
 
void Delay5000ms()		//@11.0592MHz
{
	unsigned char i, j, k;
 
	_nop_();
	i = 36;
	j = 5;
	k = 211;
	do
	{
		do
		{
			while (--k);
		} while (--j);
	} while (--i);
}
 
 
 
 
//上电时，地址默认设为C0H，grid1
int main(void){
  fzh_Init();
 
	while(1){
		fzh_SetLightGrade(USAER_CMD_CYCLE_14_16,USAER_CMD_SHOW_ON);
	 	//0x40:地址自动加一	
		//grid1：从grid1开始
		fzh_WriteREyeSram( 0x40,grid1,fangkuang1,16,FZH_CMD_ON|USAER_CMD_CYCLE_11_16); 
		Delay5000ms();	
		Delay5000ms();
		fzh_WriteREyeSram( 0x40,grid1,fangkuang2,16,FZH_CMD_ON|USAER_CMD_CYCLE_2_16); 
		Delay5000ms();	
		Delay5000ms();
		
/*    
//fzh_WriteSram是正常顺序输出的函数，显示乱码
		fzh_WriteSram( 0x40,grid1,fangkuang1,16,FZH_CMD_ON|USAER_CMD_CYCLE_14_16); 
		Delay5000ms();	
		Delay5000ms();
		fzh_WriteSram( 0x40,grid1,fangkuang2,16,FZH_CMD_ON|USAER_CMD_CYCLE_2_16); 
		Delay5000ms();	
		Delay5000ms();
*/
 }
	return 1;
}
