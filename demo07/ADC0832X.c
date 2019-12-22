#include<reg51.h>	   
#include<intrins.h>   
#include<string.h>     
#include<stdio.h>

#define INT8U  unsigned char
#define INT16U unsigned int
#define INT32U unsigned long

sbit CS=P0^2;	  
sbit CLK=P0^1;	     
sbit DIO=P0^0;

INT8U Get_AD_Result()
{	 
	INT8U i=0,dat1=0x00,dat2=0x00;
	CS=0;//片选
	CLK=0;_nop_();_nop_();
	DIO=1;//启动0832
	CLK=1;_nop_();_nop_();	


	CLK=0;_nop_();_nop_();
	DIO=1;//选择单通道还是双通道
	CLK=1;_nop_();_nop_();

	CLK=0;_nop_();_nop_();
	DIO=0;//选择0还是1通道
	CLK=1;_nop_();_nop_();

	CLK=0; DIO=1;_nop_();_nop_(); //释放总线，准备采集
	for(i=0;i<8;i++)//下降沿采集数据，从高位到低位
	{
		CLK=1;_nop_();_nop_(); 
		CLK=0; _nop_();_nop_();
		dat1=(dat1<<1)|((INT8U)DIO);
	}	
	for(i=0;i<8;i++)//下降沿采集数据，从低位到高位
	{
		dat2=(dat2)|(((INT8U)DIO)<<i);	
		CLK=1;_nop_();_nop_(); 
		CLK=0; _nop_();_nop_();
	}
	_nop_();_nop_();
	CS=1;//0832片选结束
	if(dat2==dat1)	//如果两个数据相等，就输出
		return dat1;
	else
		return 0;
}//5v 255	126 3.24 324
/*
INT16U Digit_Convert_Analog(INT8U dat)
{
	INT16U AnalogValue=0x0000;//   x*500/256=y
	AnalogValue=(INT16U)((dat*500.0)/256.0);
	return AnalogValue;
}
*/