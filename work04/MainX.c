#include<reg51.h>
#include<stdio.h>
#include<intrins.h>
#include<string.h>
#include<stdlib.h>

#define INT8U unsigned char
#define INT16U unsigned int

INT8U temp_buff[17];
extern INT8U temperature_value[];
extern void delay_ms(INT16U x);
extern void LCD_Initialize();
extern void LCD_String(INT8U r,INT8U c,INT8U *str);
extern INT8U ds18b20_read_temperature();

void main()
{
	float tempV = 0.0;
	LCD_Initialize();
	LCD_String(0, 0, " DS18B20 Project");
	LCD_String(1, 0, "    waiting.....");
	ds18b20_read_temperature();
	delay_ms(1000);
	
	//LCD_String(1, 0, "    cccting.....");
	
	while(1)
	{
		if(ds18b20_read_temperature())
		{
			//LCD_String(1, 0, "    dddting.....");
			tempV =(((int)temperature_value[1]<<8)|((int)temperature_value[0]))*0.0625;
			sprintf(temp_buff, "  temp: %5.2f\xDF\x43", tempV);
			LCD_String(1, 0, temp_buff);
		}
		delay_ms(50);
	}
}