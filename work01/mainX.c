#include<reg51.h>
#include<intrins.h>
#include<string.h>
#include<stdlib.h>
#include<stdio.h>

sbit switch1 = P3^0;
sbit switch2 = P3^1;
sbit switch3 = P3^2;
sbit switch4 = P3^3;

unsigned char *strCode="                I Love You!";

/*
  引入外部方法
*/
extern void delay_ms(int ms);
extern void init();
extern void write_CMD(unsigned char cmd8);
extern void write_Str(int r, int c, char *str);
extern void write_Data(unsigned char data8);

/**
* 水平滚动文字
*
* @return
*/
void h_Scroll_Words()
{
	int i;
	init();
	write_Str(0,0, "    Example-1   ");
	while(1)
	{
		/*
		  fun1
		*/
		for(i = 0; i<strlen(strCode); i++)
		{
			write_Str(1, 0, strCode + i);
			delay_ms(100);
		}
		
		if(switch1 != 0) break;

		/*
		  fun2
		*/
//		for(i = 0; i < 16; i++){
//			write_Str(1, i, "I Love You!");	
//			delay_ms(100);
//			write_Str(1, 0, "                ");
//		}
	}

}

/**
* 随机数相加
*
* @return
*/
void random_words()
{
	int a,b,i;
	unsigned char tempStr[17];

	init();
	write_CMD(0x0F);
	write_Str(0,0, "    Example-2   ");

	while(1)
	{
		//srand(TH0);
		a = rand()%10;
		b = rand()%10;
		sprintf(tempStr, "%d+%d=%d", a, b, a+b);
		write_CMD(0xC0|0x05);
		for(i = 0; i < 11; i++)
		{
			if(tempStr[i]) write_Data(tempStr[i]); 
			else write_Data(' ');
			delay_ms(150);
		}
		write_Str(1, 0, "           ");
		delay_ms(150);
		if(switch2 != 0) break;
	}

}

/**
* 全码显示
*
* @return
*/
void all_StrCode()
{
 	int i,j;
	init();
	write_CMD(0x0F);//0000_1111:显示开/关控制 
	write_Str(0,0, "    Example-3   "); 	
	while(1)
	{
		write_CMD(0xC0);
		for(i = 0x20; i <= 0xFF; i++)
		{
			if(switch3) return;
			if(i >= 0x80 && i < 0xa0) continue;

			if((++j) == 16)
			{
				write_Str(1, 0, "           ");
				j = 0;
				//如果命令让它从第二行写，就重置到第二行第一个地址
				write_CMD(0xC0);
			}
			//if(i == 0xFF) i = 0x20;
			write_Data(i);
			delay_ms(50);
		}
	
	}

}

/**
* 自定义字符显示
*
* @return
*/
void character_StrCode()
{
  	int i = 0;
  	unsigned char CC[] = {0x1F,0x11,0x1F,0x11,0x1F,0x11,0x1F,0x00};
  	init();
	write_CMD(0x0F); // 0000_1111:显示开关控制
	write_Str(0, 0, "    Example-4   ");
	write_CMD(0x40); //0100_0000:置字符发生存贮器地址
	for(i = 0; i < 8; i++)
	{
		// 通过上面write_LCD_CMD(0x40); 把数组写到CGRAM
		write_Data(CC[i]);	
	}
	while(1)
	{
		write_CMD(0xC0);
		for(i = 0; i < 16; i++)
		{
			if(switch4) return;
			write_Data(0);
			delay_ms(50);
		}
		//当满行显示后清屏
		write_Str(1, 0, "                ");
		delay_ms(150);
	}
	

}

/**
* 主函数 
*/
void main()
{
	while(1)
	{
		if(switch1 == 0)
		{
			h_Scroll_Words();
		}
		else if(switch2 == 0)
		{
			random_words();
		}
		else if(switch3 == 0)
		{
			all_StrCode();
		}
		else if(switch4 == 0)
		{
			character_StrCode();
		}
	}
}
