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

sbit MA=P1^0; //直流电机A端
sbit MB=P1^1; //直流电机B端
sbit PWM=P1^2; //pulse width modification 脉冲宽度调制 功能调速

void main()
{
	float tempv = 0.0;
	INT8U temp_buff[17];
	
	LCD_Initialize();
	LCD_String(0, 0, "  RECENT TEMP   ");
	LCD_String(1, 0, "     WAITING....");
	Read_temperature();
	delay_ms(500);
	
	while(1)
	{
		if(Read_temperature())
		{
			tempv = (((int)Temp_Value[1]<<8) | (int)Temp_Value[0]) * 0.0625;
			sprintf(temp_buff, "TEMP:  %5.1f\xDF\x43", tempv);
			LCD_String(1, 0, temp_buff);
			
			if(tempv>=75) tempv = 75;
			if(tempv<=0) tempv = 0;
			
			if(tempv>=45)
			{
				MA = 1;
				MB = 0;
				
				if(tempv==45) PWM = 0;
				else if(tempv==75) PWM = 1;
				else
				{
					PWM = 1; delay_ms(tempv-45);
					PWM = 0; delay_ms(75-tempv);
				}
			}
			else if(tempv<=10)
			{
				MA = 0;
				MB = 1;
				
				if(tempv==10) PWM = 0;
				else if(tempv==0) PWM = 1;
				else
				{
					PWM = 1; delay_ms(10-tempv);
					PWM = 0; delay_ms(tempv);
				}
			}
			else
			{
				MA = 0;
				MB = 0;
				PWM = 0;
			}
			
		}
		delay_ms(50);
	}
	
}
