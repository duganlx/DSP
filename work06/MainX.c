#include<reg51.h>
#include<intrins.h>
#include<string.h>
#include<stdlib.h>
#include<stdio.h>
#define INT8U unsigned char
#define INT16U unsigned int

extern void delay_ms(INT16U x);
extern void LCD_Initialize();
extern void LCD_String(INT8U r,INT8U c,INT8U *str);
extern INT8U Temp_Value[];
extern void delayx(INT16U x);
extern INT8U Read_temperature();

sbit MA=P1^0;//直流电机A端 
sbit MB=P1^1;//直流电机B端 
sbit PWM=P1^2;//pulse width modification 脉冲宽度调制 功能调速

static int count = 0;
float tempv;
INT8U buff[17];

void T0_interrupt() interrupt 1 //INT0 0, T0 1, INT1 2, T1 3, Serial T 4 
{
	count++;
	TL0 = ((INT16U)(65536-(INT16U)(11.0592/12*500)))%256; //t0 low delay->500us
	TH0 = ((INT16U)(65536-(INT16U)(11.0592/12*500)))%256; //t0 high
	if(count==10)		//增加延时 -> 50ms
	{
		count=0;
		
		if(Read_temperature()==1) //顺序程序设计会把执行语句作为延时
		{
			count=0;
			tempv=(((int)Temp_Value[1]<<8)|((int)Temp_Value[0]))*0.0625;
			sprintf(buff,"temp:  %5.1f\xDF\x43",tempv);  
			LCD_String(1,0,buff);
			if(tempv>=75)
				tempv=75;//正转75度是全速了  temp speed
			if(tempv<=0)
				tempv=0;//反转0度是全速了
			if(tempv>=45)
			{   
				MA=1;
				MB=0;
				if(tempv==45)
					PWM=0;
				else if(tempv==75)
					PWM=1;
				else
				{   
					PWM=1;delay_ms(tempv-45); //给力
					PWM=0;delay_ms(75-tempv);//不给力
				}
			}
			else if(tempv<=10)
			{   
				MA=0;
				MB=1;
				if(tempv==10) 
					PWM=0;
				else if(tempv==0)  
					PWM=1;
				else
				{   
					PWM=1;delay_ms(10-tempv); //给力
					PWM=0;delay_ms(tempv-0);//不给力
				}

			}
			else
			{   
				MA=0;
				MB=0;
			}
		}
	}
		
	
	
}

void main()
{ 
	LCD_Initialize();	
	LCD_String(0,0,"  recent temp");
	LCD_String(1,0,"  Waiting.......");
	Read_temperature();
	delay_ms(1500);
	TMOD=0x01; //定时器16位 65535
	EA = 1; //总开关
	ET0 = 1; //分开关
	TR0 = 1; //定时器开关
	
	while(1);//避免跑飞
}