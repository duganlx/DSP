#include<reg51.h>
#include<intrins.h>
#include<string.h>

sbit Switch=P3^0;

unsigned char *strCode="                I Love You!";

/*
  引入外部方法
*/
extern void delay_ms(int ms);
extern void initialize_LCD();
extern void write_String(int r, int c, char *str);

/**
* 水平滚动文字
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
		
		if(Switch != 0) break;

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
* 主函数 
*/
void main(){
	while(1){
		if(Switch == 0){
			h_Scroll_Words();
		}
	}
}
