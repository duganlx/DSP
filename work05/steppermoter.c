#include<reg51.h>
#include<string.h>
#include<stdio.h>
#include<intrins.h>
#include<stdlib.h>

#define INT8U unsigned char
#define INT16U unsigned int

sbit FFW_KEY=P3^0;
sbit REV_KEY=P3^1;
sbit STOP_KEY=P3^2;

//0000_0001 A->AB->B->BC->C->CD->D->AD
INT8U code FFW_ARR[]={0x01,0x03,0x02,0x06,0x04,0x0C,0x08,0x09}; 
//0000_1001 AD->D->CD->C->BC->B->AB->A
INT8U code REV_ARR[]={0x09,0x08,0x0C,0x04,0x06,0x02,0x03,0x01};

/**
*延时
*
*@param x 延时时间
*@return
*/
void delay_ms(INT16U x)
{
	INT8U t=120;
	while(x--)
		while(t--);
}

/**
*瞬时间旋转
*
*@param n 旋转圈数
*@return
*/
void STEP_FFW(INT8U n)
{
	INT8U i,j;
	
	for(i=0; i<5*n; i++)
	{
		for(j=0; j<8; j++) //8*9=72
		{
			P1=FFW_ARR[j];
			delay_ms(60);
			
			if(STOP_KEY==0) 
				return;
		}
	}
}

/**
*逆时间旋转
*
*@param n 旋转圈数
*@return
*/
void STEP_REV(INT8U n)
{
	INT8U i,j;
	
	for(i=0; i<5*n; i++)
	{
		for(j=0; j<8; j++)
		{
			P1=REV_ARR[j];
			delay_ms(60);
			
			if(STOP_KEY==0) 
				return;
		}
	}
}

void main()
{
	INT8U n = 1;
	
	while(1)
	{
		if(FFW_KEY==0)
		{
			P0=0xFE; // 1111_1110
			STEP_FFW(n);
		}
		else if(REV_KEY==0)
		{
			P0=0xFD; // 1111_1101
			STEP_REV(n);
		}
		else
		{
			P0=0xFB; // 1111_1011
		}
	}
}



