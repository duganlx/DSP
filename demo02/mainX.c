#include<reg51.h>
#include<string.h>
#include<intrins.h>

#define Uint unsigned int
#define Uchar unsigned char

sbit CS=P1^0; // chip select
sbit CLK=P1^1; // clock
sbit DIO=P1^2; // data input and output
sbit RS=P2^0; // data register status register
sbit RW=P2^1; // read/write
sbit EN=P2^2; // enable

Uchar disp_buff1[]="VOLTAGE:  0.00V";
Uchar disp_buff2[16];

/*
* 延时
*  
* @param x 时间（不精确）
* @return
*/
void delay_ms(Uint x)
{
	Uchar t;
	while(x--)
		for(t=0; t<120; t++);
}

/*
* 延时2微秒
* 
* @return
*/
void delay2us()
{
	_nop_();
	_nop_();
}

/*
* 检测BF(busy flag)位状态
* 
* @return
*/
bit test_BF()
{
	Uchar LCD_status;
	P0=0xFF;
	EN=0;RS=0;RW=1;
	EN=1;delay2us();LCD_status=P0;
	EN=0;
	return (LCD_status&0x80)?1:0;
}

/*
* 写命令
*
* @param cmd 八位命令
* @return
*/
void write_CMD(Uchar cmd)
{
	while(test_BF());
	EN=0; RS=0; RW=0;
	P0=cmd;
	EN=1; _nop_(); EN=0;
}

/*
* 写数据（一位一位的写）
*
* @param data8 八位数据
* @return
*/
void write_Data(Uchar data8)
{
	while(test_BF());
	EN=0; RS=1; RW=0;
	P0=data8;
	EN=1; _nop_(); EN=0;
}

/*
* 初始化
*
* @return
*/
void init()
{
	write_CMD(0x38);delay_ms(1);
	write_CMD(0x01);delay_ms(1);
	write_CMD(0x06);delay_ms(1);
	write_CMD(0x0C);delay_ms(1);
}

/*
* 写字符串
*
* @param r row
* @param c column
* @param str 字符串
* @return
*/
void write_Str(int r, int c, char *str)
{
	int i=0;	
	unsigned char Addressx[] = {0x80, 0xC0};
	unsigned char StartAdd = (Addressx[r] | c);//按位或

	write_CMD(StartAdd);
	
	for(i = 0; i < 16; i++){
		if(str[i]==0) break;
		write_Data(str[i]);
	}
	// 如果不够16位，用空格填充
	for(;i < 16; i++){
		write_Data(' '); 	
	}
}

/*
* AD转换
*
* @return 输出数据
*/
Uchar get_AD_Res()
{
	Uchar i, data1=0, data2=0;
	CS=0;
	//第一个周期：转换开始
	CLK=0;DIO=1;delay2us();
	CLK=1;delay2us();
	
	//第二个周期：选择单通道还是双通道 DIO=0双通道差分 或 DIO=1单通道
	CLK=0;DIO=1;delay2us(); 
	CLK=1;delay2us();
	
	//第三个周期：DIO选择CH1-->如果DIO=0 选择CH0
	CLK=0;DIO=0;delay2us();
	CLK=1;delay2us();
	
	//等待
	CLK=0;DIO=1;delay2us(); 
	
	//先进来的为最高位，后进来为最低位
	for(i=0; i<8; i++)
	{
		CLK=1;delay2us();
		CLK=0;delay2us();
		/*
		* 0000_0000|0000_000想=0000_000想
		* 0000_00想0|0000_000翔=0000_00想翔
		* 0000_0想翔0|0000_000子=0000_0想翔子
		*/
		data1=(data1<<1)|(Uchar)DIO; 
	}
	
	//先进来的为最低位，后进来为最高位
	for(i=0; i<8; i++)
	{
		/*
		* 0000_0000|0000_000子=0000_000子
		* 0000_000子|0000_00翔0=0000_00翔子
		* 0000_00翔子|0000_0想00=0000_0想翔子
		*/
		data2= data2|(Uchar)DIO<<i;
		CLK=1;delay2us();
		CLK=0;delay2us();
		 
	}
	
	//禁止片选
	CS=1;
	
	return (data1==data2)?data1:0;
}

void main()
{
	Uchar i=0,AD=0;
	Uint d=0;
	init();
	
	while(1)
	{
		AD=get_AD_Res(); 
		d=(AD*500.0/256.0);
		
		disp_buff1[10]=d/100+'0';
		disp_buff1[12]=(d/10)%10+'0';
		disp_buff1[13]=d%10+'0';
		
		write_Str(0,0,disp_buff1);
		
		//填充实心和空心的框框
		i=(Uint)AD*16/256;
		memset(disp_buff2,'\xFF',i);
		memset(disp_buff2+i,'\xDB',16-i);
		write_Str(1,0,disp_buff2);
	}
	
}

