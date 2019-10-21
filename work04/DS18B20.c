#include<reg51.h>
#include<stdio.h>
#include<intrins.h>
#include<string.h>
#include<stdlib.h>

#define INT8U unsigned char
#define INT16U unsigned int

sbit DQ = P3^4; //special bit
INT8U tempValue[]={0x00, 0x00};
extern void delay_ms(INT16U x);

/**
* 延时函数 针对12Mhz的晶振
* _nop_()相当于一个机器周期（12个振荡周期） --> 1us
*
*@param x 延时时间（单位us）
*@return
*/
void delay_us(INT16U x)
{
	while(x--)
		_nop_();
}


/**
* 精确延时函数
* delay(0):延时518us 误差:518-2*256=6
* delay(1):延时7us
* delay(10):延时25us    误差:25-20=5
* delay(20):延时45us    误差:45-40=5
* delay(100):延时205us 误差:205-200=5
* delay(200):延时405us 误差:405-400=5
*
*@param x 延时时间
*@return 
*/
void delay(INT16U x)
{
	while(--x);
}

/**
* 初始化
* 拉低电平需要保持480us，高电平需要保持15us
*
*@return 0：初始化成功 ，1：初始化失败 
*/
INT8U init()
{
	INT8U status;
	DQ = 1; delay_us(15);	
	DQ = 0; delay_us(450);	
	DQ = 1; delay_us(15);
	status = DQ;
	delay_ms(100); 
	
	return status;
}

/**
* 读取DQ中的数据
*
* @return 八位数据
*/
INT8U read_byte()
{
	INT8U i, dat=0x00;
	
	for(i=0x01; i!=0x00; i<<=1) // 从低到高读
	{
		DQ=0; delay_us(1);
		DQ=1; delay_us(7);
		if(DQ)
			dat = dat|i;
		delay_us(25); //此延时不能少，确保读时序的长度60us。
	}
	
	return dat;
}

/**
*写数据
*
*@dat 八位数据
*@return
*/
void write(INT8U dat)
{
	INT8U i;
	
	for(i=0; i<8; i++)
	{
		DQ=0; delay_us(1);
		dat = dat>>1; //把最低位移到PSW的进/借位CY
		DQ = CY;
		delay(8);
		DQ = 1;
	}
}

/**
*读取温度数据值
*
*@return 1：成功，0：失败
*/
INT8U read_temp()
{
	if(init()) return 0;
	else
	{
		write(0xCC); //单点连线 
		write(0x44); //启动温度转换
		write(0xBE); //读取温度数字值
		tempValue[0] = read_byte(); //读取RAM里低8位
		tempValue[1] = read_byte(); //读取RAM里高8位
		return 1;
	}
}