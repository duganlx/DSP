#include<reg51.h>
#include<intrins.h> //ʹ��_nop_();
#include<string.h>

/*
* �궨��
*/
// RSΪ�Ĵ���ѡ��,�ߵ�ƽʱѡ��Ĵ���,�͵�ƽʱѡ��ָ��Ĵ���
sbit RS = P2^0;
// RWΪ��д�ź���,�ߵ�ƽʱ���ж�����,�͵�ƽʱ����д���� 
sbit RW = P2^1;
// ENΪʹ�ܶˣ���EN���ɸߵ�ƽ����ɵ͵�ƽʱ��Һ��ģ��ִ������
sbit EN = P2^2;

/*
* ��ʱ(��׼ȷ��ʱ)
*
* @param ms
* @return  
*/
void delay_ms(int ms)
{
	while(ms--){
		int i = 100;
		while(i--){}
	}
}

/*
* ���BF(busy flag)λ״̬
* 
* @return
*/
void test_BF()
{
	unsigned char LCD_status;
	do{
		P0 = 0xFF; // LCD1602��ȡ״̬���ݣ�������һ��������ƽ
		EN = 0; RS = 0; RW = 1; // RSΪ0ʱ��P0������Ϊ����
		EN=1;// ��RS��RW������Ч
		LCD_status = P0;
		_nop_(); _nop_();
		EN = 0;
	}while(LCD_status&0x80); // 1000 0000 æµ״̬
}

/*
* д���ݣ�һλһλ��д��
*
* @param data8 ��λ����
* @return
*/
void write_data(unsigned char data8)
{
	test_BF();
	EN = 0; RS = 1; RW = 0;
	P0 = data8;
	EN = 1; _nop_(); EN = 0;
}

/*
* д����
*
* @param cmd8 ��λ����
* @return
*/
void write_cmd(unsigned char cmd8)
{
	test_BF();
	EN = 0; RS = 0; RW = 0;
	P0 = cmd8;
	EN = 1; _nop_(); EN = 0;
}

/**
* д�ַ���
*
* @param r row
* @param c column
* @param str �ַ���
* @return
*/
void write_str(int r, int c, char *str)
{
	int i=0;	
	unsigned char Addressx[] = {0x80, 0xC0};
	unsigned char StartAdd = (Addressx[r] | c);//��λ��

	write_cmd(StartAdd);
	
	for(i = 0; i < 16; i++){
		if(str[i]==0) break;
		write_data(str[i]);
	}
	// �������16λ���ÿո����
	for(;i < 16; i++){
		write_data(' '); 	
	}
}

/**
* LCD��ʼ��
*
* @return
*/
void init()
{
	 /*
	  0011_1000 �ù���
 	  DL=1 --> 8λ����
	  N=0  --> ������ʾ
	  F=0  -->	��ʾ5x7�ĵ����ַ�
	*/	
	write_cmd(0x38);
	/*
	  0000_0001 ����ʾ
	  ָ����01H,��긴λ����ַ00Hλ��
	*/ 
	write_cmd(0x01);
	/*
	  0000_0110 ������ģʽ
	  I/D=1 --> �������
	  S=0   --> ��Ļ�������������ƻ�����
	*/
	write_cmd(0x06);
	/*
	  0000_1100	��ʾ��/�ؿ���
	  D=1 --> ����ʾ
	  C=0 --> �޹��
	  B=0 --> ��겻��˸
	*/
	write_cmd(0x0C);
}






