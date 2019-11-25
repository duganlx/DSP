#include<reg51.h>
#include<intrins.h>
#include<string.h>

#define INT8U unsigned char
#define INT16U unsigned int

sbit RS = P2^0;
sbit RW = P2^1;
sbit EN = P2^2;

void lcd1602_test_bf()
{
	INT8U lcd_status;
	do
	{
		P0 = 0xFF; //1111_1111
		EN = 0; RS = 0; RW = 1;
		EN = 1;
		lcd_status = P0;
		_nop_(); _nop_();
		EN = 0;
	}while(lcd_status&0x80);
}

void lcd1602_write_data(INT8U data8)
{
	lcd1602_test_bf();
	EN = 0; RS = 1; RW = 0;
	P0 = data8;
	EN = 1; _nop_(); EN = 0;
}

void lcd1602_write_cmd(INT8U cmd8)
{
	lcd1602_test_bf();
	EN = 0; RS = 0; RW = 0;
	P0 = cmd8;
	EN = 1; _nop_(); EN = 0;
}

void lcd1602_write_str(int r, int c, char *str)
{
	int i = 0;
	INT8U Addressx[] = {0x80, 0xC0};
	INT16U startAddress = (Addressx[r] | c);
	
	lcd1602_write_cmd(startAddress);
	
	for(i=0; i<16; i++)
	{
		if(str[i] == 0) break;
		lcd1602_write_data(str[i]);
	}
	
	for(; i<16; i++)
	{
		lcd1602_write_data(' ');
	}
}

void lcd1602_init()
{
	/*
	  0011_1000	置功能
 	  DL=1 --> 	8位总线
	  N=0  --> 	单行显示
	  F=0  -->	显示5x7的点阵字符
	*/
	lcd1602_write_cmd(0x38);
	/*
	  0000_0001 清显示
	  指令码01H,光标复位到地址00H位置
	*/
	lcd1602_write_cmd(0x01);
	/*
	  0000_0110 置输入模式
	  I/D=1 --> 光标右移
	  S=0   --> 屏幕上所有文字左移或右移
	*/
	lcd1602_write_cmd(0x06);
	/*
	  0000_1100	显示开/关控制
	  D=1 --> 开显示
	  C=0 --> 无光标
	  B=0 --> 光标不闪烁
	*/
	lcd1602_write_cmd(0x0C);
}