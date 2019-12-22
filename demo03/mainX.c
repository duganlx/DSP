#include<reg51.h>
#include<stdio.h>
#include<stdlib.h>
#include<intrins.h>
#include<string.h>

//地址锁存
sbit ADDC=P1^6;
sbit ADDB=P1^5;
sbit ADDA=P1^4;

sbit CLK=P1^3; //clock
sbit ST=P1^2; //start (转换启动信号)
sbit EOC=P1^1; //end of conversion (转换结束信号)
sbit OE=P1^0; //output enable (输出允许信号,用于)

//0~9
unsigned char code SEG7[]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f,0x00};

/*
* 延时
*  
* @param x 时间（不精确）
* @return
*/
void delay_ms(int i)
{
	int j=0;
	while(i--)
	{
		for(j=0;j<120;j++);
	}
}

/*
* 显示
* 
* @param ADx AD转换过后的八位数值
* @return
*/
void display(unsigned char ADx)
{
	int AD = ADx*500.0/255.0;
	P2=0xFD; P0=SEG7[AD/100]; delay_ms(5);//1111_1101 -> P2^1 
	P2=0xFB; P0=SEG7[(AD/10)%10]; delay_ms(5);//1111_1011 -> P2^2
	P2=0xF7; P0=SEG7[AD%10]; delay_ms(5);//1111_0111 -> P2^3
}

/*
* 初始化
*
* @return
*/
void init()
{
	// ABC=110选择第三通道
	ADDC=0;
	ADDB=1;
	ADDA=1;
	
	CLK=0;
	ST=1; //内部寄存器清零
	EOC=1; // 转换结束(未开始)
	OE=0; 
}

void main()
{
	init();
	
	//TMOD(定时器)
	TMOD=0x02; //0000_0010 8位 0~255
	/*
	 对定时器T0来说是分成两个寄存器：TH0为高八位，TL0为低八位，组成了16位的定时器，
	 当低位TL0计满就向高位TH0移一个数，然后清零
	 TH0和TL0决定采样频率(数值越大，频率越高)
	*/
	TH0=200; 
	TL0=200; 
	EA=1; // 总中断开关
	ET0=1; // T0定时器总中断开关
	TR0=1; // 启动T0的开定时器位
	
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