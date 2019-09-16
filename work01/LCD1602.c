#include<reg51.h>
#include<intrins.h> //使用_nop_();
#include<string.h>

/*
* 宏定义
*/
// RS为寄存器选择,高电平时选择寄存器,低电平时选择指令寄存器
sbit RS = P2^0;
// RW为读写信号线,高电平时进行读操作,低电平时进行写操作 
sbit RW = P2^1;
// EN为使能端，当EN端由高电平跳变成低电平时，液晶模块执行命令
sbit EN = P2^2;

/*
* 延时(不准确延时)
*
* @param ms
* @return  
*/
void delay_ms(int ms){
	while(ms--){
		int i = 100;
		while(i--){}
	}
}

/*
* 检测BF(busy flag)位状态
* 
* @return
*/
void test_BF(){
	unsigned char LCD_status;
	do{
		P0 = 0xFF; // LCD1602读取状态数据，必须有一个上拉电平
		EN = 0; RS = 0; RW = 1; // RS为0时，P0的数据为命令
		EN=1;// 让RS和RW设置有效
		LCD_status = P0;
		_nop_(); _nop_();
		EN = 0;
	}while(LCD_status&0x80); // 1000 0000 忙碌状态
}

/*
* 写数据
*
* @param data8 八位数据
* @return
*/
void write_LCD_Data(unsigned char data8){
	test_BF();
	EN = 0; RS = 1; RW = 0;
	P0 = data8;
	EN = 1; _nop_(); EN = 0;
}

/*
* 写命令
*
* @param cmd8 八位命令
* @return
*/
void write_LCD_CMD(unsigned char cmd8){
	test_BF();
	EN = 0; RS = 0; RW = 0;
	P0 = cmd8;
	EN = 1; _nop_(); EN = 0;
}

/**
* 写字符串
*
* @param r row
* @param c column
* @param str 字符串
* @return
*/
void write_String(int r, int c, char *str){
	int i=0;	
	unsigned char Addressx[] = {0x80, 0xC0};
	unsigned char StartAdd = (Addressx[r] | c);//按位或

	write_LCD_CMD(StartAdd);
	
	for(i = 0; i < 16; i++){
		if(str[i]==0) break;
		write_LCD_Data(str[i]);
	}
	// 如果不够16位，用空格填充
	for(;i < 16; i++){
		write_LCD_Data(' '); 	
	}
}

/**
* LCD初始化
*
* @return
*/
void initialize_LCD(){
	 /*
	  0011_1000 置功能
 	  DL=1 --> 8位总线
	  N=0  --> 单行显示
	  F=0  -->	显示5x7的点阵字符
	*/	
	write_LCD_CMD(0x38);
	/*
	  0000_0001 清显示
	  指令码01H,光标复位到地址00H位置
	*/ 
	write_LCD_CMD(0x01);
	/*
	  0000_0110 置输入模式
	  I/D=1 --> 光标右移
	  S=0   --> 屏幕上所有文字左移或右移
	*/
	write_LCD_CMD(0x06);
	/*
	  0000_1100	显示开/关控制
	  D=1 --> 开显示
	  C=0 --> 无光标
	  B=0 --> 光标不闪烁
	*/
	write_LCD_CMD(0x0C);
}







