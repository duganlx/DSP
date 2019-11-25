#include<reg51.h>
#include<stdio.h>

#define INT8U unsigned char
#define INT16U unsigned int

extern void lcd1602_init();
extern void lcd1602_write_str(int r, int c, char *str);
extern INT8U ds18b20_read_temperature();
extern INT8U temperature_value[];
extern void delay_ms(INT16U x);

sbit wind_MA=P1^0; 
sbit wind_MB=P1^1;
sbit light_MA=P1^2;
sbit light_MB=P1^3;
//按钮低电平有效
sbit wind_button=P1^5;
sbit light_button=P1^6;
sbit water_button=P1^7;

static int count = 0;
INT8U buffer[17];
float temperature;

void main()
{
	lcd1602_init();
	lcd1602_write_str(0, 0, "Greenhouse Test");
	lcd1602_write_str(1, 0, "TEMP:");
	ds18b20_read_temperature();
	delay_ms(1500);
	
	TMOD=0x01; //定时器16位 65535
	EA = 1; //总开关
	ET0 = 1; //分开关
	TR0 = 1; //定时器开关
	
	while(1);
}

void T0_interrupt() interrupt 1 
{
	count++;
	TL0 = ((INT16U)(65536-(INT16U)(11.0592/12*500)))%256; //t0 low delay->500us
	TH0 = ((INT16U)(65536-(INT16U)(11.0592/12*500)))%256; //t0 high
	if(count==10)		//增加延时 -> 50ms
	{
		count=0;
		
		if(ds18b20_read_temperature())
		{
			count=0;
			temperature=(((int)temperature_value[1]<<8)|((int)temperature_value[0]))*0.0625;
			sprintf(buffer, "TEMP:  %5.2f\xDF\x43", temperature);  
			lcd1602_write_str(1, 0, buffer);
			
			if(wind_button==0)
			{
				wind_MA=1;
				wind_MB=0;
			}
			else
			{
				wind_MA=0;
				wind_MB=0;
			}
			
			if(light_button==0)
			{
				light_MA=1;
				light_MB=0;
			}
			else
			{
				light_MA=0;
				light_MB=0;
			}			
		}
		else
			lcd1602_write_str(1, 0, "INIT ERROR");
	}
}
