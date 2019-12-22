#include<reg51.h>	   
#include<intrins.h>   
#include<string.h>     
#include<stdio.h>

#define INT8U  unsigned char
#define INT16U unsigned int
#define INT32U unsigned long
#define MC 1388
#define BC -5
#define KC 2

INT8U code segment7[] = {0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f};
INT8U numstr[4];
sbit beeppin = P1^0;

extern INT8U Get_AD_Result();
extern void serialInputData(INT8U dat);
extern void paralledOutputData();

void beep()
{
	INT8U i=0, j=150;
	beeppin = 1;
	for(i=0; i<60; i++)
	{
		beeppin = !beeppin;
		j=150;
		while(j--);
	}
}

float getDistance()
{
	float d=0.00, sum=0, avg=0;
	INT8U i=0;
	
	for(i=0; i<10; i++)
	{
		sum = sum + Get_AD_Result();
	}
	avg = (INT8U)(sum/10.0);
	d = ( (MC*1.0) / ((avg+BC)*1.0) ) - (KC*1.0);
	return d;
}

void distance2numstr(float d)
{
	INT16U dis = (INT16U)(d*10); 
	numstr[0] = dis/100+'0';
	numstr[1] = ((dis/10)%10)+'0';
	numstr[2] = dis%10+'0';
}

void main()
{
	float dis = 0;
	while(1)
	{
		dis = getDistance();
		if(dis<30)
			beep();
		distance2numstr(dis);
		serialInputData(~segment7[numstr[2]-'0']);
		serialInputData((~segment7[numstr[1]-'0'])&0x7F);
		serialInputData(~segment7[numstr[0]-'0']);
		paralledOutputData();
	}
}