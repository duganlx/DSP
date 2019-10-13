#include<reg51.h>
#include<stdio.h>
#include<stdlib.h>
#include<intrins.h>
#include<string.h>

sbit ADDC=P1^6;
sbit ADDB=P1^5;
sbit ADDA=P1^4;

sbit CLK=P1^3; //clock
sbit ST=P1^2; //start transformation
sbit EOC=P1^1; //end of conversion
sbit OE=P1^0; //output enable

unsigned char code SEG7[]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f,0x00};

void delay_ms(int i)
{
	int j=0;
	while(i--)
	{
		for(j=0;j<120;j++);
	}
}

void display(unsigned char ADx)
{
	int AD = ADx*500.0/255.0;
	P2=0xFD; P0=SEG7[AD/100]; delay_ms(5);//1111_1101 
	P2=0xFB; P0=SEG7[(AD/10)%10]; delay_ms(5);//1111_1011
	P2=0xF7; P0=SEG7[AD%10]; delay_ms(5);//1111_0111
}

void init()
{
	// ABC=110选择第三通道
	ADDC=0;
	ADDB=1;
	ADDA=1;
	
	CLK=0;
	ST=1;
	EOC=1;
	OE=0;
}

void main()
{
	init();
	
	// 开始计数
	TMOD=0x02;
	TH0=200; 
	TL0=200;
	EA=1;
	ET0=1;
	TR0=1;
	
	while(1)
	{
		ST=0;_nop_();ST=1;_nop_();ST=0;
		while(EOC==0);
		OE=1;
		display(P3);
		OE=0;
	}
	
}

/*
* 中断
*
* @return
*/
void t0() interrupt 1
{
	CLK=!CLK;
}