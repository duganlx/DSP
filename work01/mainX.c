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
  �����ⲿ����
*/
extern void delay_ms(int ms);
extern void initialize_LCD();
extern void write_LCD_CMD(unsigned char cmd8);
extern void write_String(int r, int c, char *str);
extern void write_LCD_Data(unsigned char data8);

/**
* ˮƽ��������
*
* @return
*/
void h_Scroll_Words(){
	int i;
	initialize_LCD();
	write_String(0,0, "    Example-1   ");
	while(1){
		/*
		  fun1
		*/
		for(i = 0; i<strlen(strCode); i++){
			write_String(1, 0, strCode + i);
			delay_ms(100);
		}
		
		if(switch1 != 0) break;

		/*
		  fun2
		*/
//		for(i = 0; i < 16; i++){
//			write_String(1, i, "I Love You!");	
//			delay_ms(100);
//			write_String(1, 0, "                ");
//		}
	}

}

/**
* ��������
*
* @return
*/
void random_words(){
	int a,b,i;
	unsigned char tempStr[17];

	initialize_LCD();
	write_LCD_CMD(0x0F);
	write_String(0,0, "    Example-2   ");

	while(1){
		srand(TH0);
		a = rand()%10;
		b = rand()%10;
		sprintf(tempStr, "%d+%d=%d", a, b, a+b);
		write_LCD_CMD(0xC0|0x05);
		for(i = 0; i < 11; i++){
			if(tempStr[i]) write_LCD_Data(tempStr[i]); 
			else write_LCD_Data(' ');
			delay_ms(150);
		}
		write_String(1, 0, "           ");
		delay_ms(150);
		if(switch2 != 0) break;
	}

}

/**
* ȫ����ʾ
*
* @return
*/
void all_StrCode(){
 	int i,j;
	initialize_LCD();
	write_LCD_CMD(0x0F); 
	write_String(0,0, "    Example-3   ");
	while(1){
		if(switch3) break;
		write_LCD_CMD(0xC0);
		for(i = 0x20; i <= 0xFF; i++){
			
			if(i >= 0x80 && i <= 0x90) continue;
			if((++j) == 16){
				write_String(1, 0, "           ");
				j = 0;
				//������������ӵڶ���д�������õ��ڶ��е�һ����ַ
				write_LCD_CMD(0xC0);
			}
			//if(i == 0xFF) i = 0x20;
			write_LCD_Data(i);
			delay_ms(150);
		}
	
	}

}

/**
* �Զ����ַ���ʾ
*
* @return
*/
void character_StrCode(){
  	int i = 0;
  	unsigned char CC[] = {0x1F,0x11,0x1F,0x11,0x1F,0x11,0x1F,0x00};
  	initialize_LCD();
	write_LCD_CMD(0x0F); 
	write_String(0, 0, "    Example-4   ");
	write_LCD_CMD(0x40);
	for(i = 0; i < 8; i++){
		// ͨ������write_LCD_CMD(0x40); ������д��CGRAM
		write_LCD_Data(CC[i]);	
	}
	while(1){
		if(switch4) break;
		write_LCD_CMD(0xC0);
		for(i = 0; i < 16; i++){
			write_LCD_Data(0);
			delay_ms(150);
		}
	}
	write_String(1, 0, "                ");
	delay_ms(150);

}

/**
* ������ 
*/
void main(){
	while(1){
		if(switch1 == 0){
			h_Scroll_Words();
		}else if(switch2 == 0){
			random_words();
		}else if(switch3 == 0){
			all_StrCode();
		}else if(switch4 == 0){
			character_StrCode();
		}
	}
}