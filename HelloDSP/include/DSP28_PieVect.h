
/****************************************************************************
*
*文件名：DSP28_PieVect.h
*
*功  能：2812 PIE向量表的定义
*
*作  者: HELLODSP
*
****************************************************************************/

#ifndef DSP28_PIE_VECT_H
#define DSP28_PIE_VECT_H

// 定义一个名称为PINT的指针，指向中断:

typedef interrupt void(*PINT)(void);

// 定义中断向量表:
struct PIE_VECT_TABLE {

//中断向量表起始地址为0x3FFFC0, 在BOOT ROM还是XINTF ZONE7 取决于引脚XMP/MC的状态
//当XMP/MC=0时，向量表在BOOT ROM内；当XMP/MC=1,向量表在XINTF ZONE7内

      PINT     PIE1_RESERVED;  
      PINT     PIE2_RESERVED;
      PINT     PIE3_RESERVED;
      PINT     PIE4_RESERVED;
      PINT     PIE5_RESERVED;
      PINT     PIE6_RESERVED;
      PINT     PIE7_RESERVED;
      PINT     PIE8_RESERVED;
      PINT     PIE9_RESERVED;
      PINT     PIE10_RESERVED;
      PINT     PIE11_RESERVED;
      PINT     PIE12_RESERVED;
      PINT     PIE13_RESERVED;

// 非外设中断:
      PINT     XINT13;    // XINT13
      PINT     TINT2;     // CPU-Timer2
      PINT     DATALOG;   // Datalogging interrupt
      PINT     RTOSINT;   // RTOS interrupt
      PINT     EMUINT;    // Emulation interrupt
      PINT     XNMI;      // Non-maskable interrupt
      PINT     ILLEGAL;   // Illegal operation TRAP
      PINT     USER0;     // User Defined trap 0
      PINT     USER1;     // User Defined trap 1
      PINT     USER2;     // User Defined trap 2
      PINT     USER3;     // User Defined trap 3
      PINT     USER4;     // User Defined trap 4
      PINT     USER5;     // User Defined trap 5
      PINT     USER6;     // User Defined trap 6
      PINT     USER7;     // User Defined trap 7
      PINT     USER8;     // User Defined trap 8
      PINT     USER9;     // User Defined trap 9
      PINT     USER10;    // User Defined trap 10
      PINT     USER11;    // User Defined trap 11
      
// PIE组1外设中断向量:
      PINT     PDPINTA;   // EV-A
      PINT     PDPINTB;   // EV-B
      PINT     rsvd1_3;
      PINT     XINT1;     
      PINT     XINT2;
      PINT     ADCINT;    // ADC
      PINT     TINT0;     // Timer 0
      PINT     WAKEINT;   // WD
           
// PIE组2外设中断向量:
      PINT     CMP1INT;   // EV-A
      PINT     CMP2INT;   // EV-A
      PINT     CMP3INT;   // EV-A
      PINT     T1PINT;    // EV-A
      PINT     T1CINT;    // EV-A
      PINT     T1UFINT;   // EV-A
      PINT     T1OFINT;   // EV-A
      PINT     rsvd2_8;
      
// PIE组3外设中断向量:
      PINT     T2PINT;    // EV-A
      PINT     T2CINT;    // EV-A
      PINT     T2UFINT;   // EV-A
      PINT     T2OFINT;   // EV-A
      PINT     CAPINT1;   // EV-A
      PINT     CAPINT2;   // EV-A
      PINT     CAPINT3;   // EV-A
      PINT     rsvd3_8;
      
// PIE组4外设中断向量:
      PINT     CMP4INT;   // EV-B
      PINT     CMP5INT;   // EV-B
      PINT     CMP6INT;   // EV-B
      PINT     T3PINT;    // EV-B
      PINT     T3CINT;    // EV-B
      PINT     T3UFINT;   // EV-B
      PINT     T3OFINT;   // EV-B
      PINT     rsvd4_8;      
     
// PIE组5外设中断向量:
      PINT     T4PINT;    // EV-B
      PINT     T4CINT;    // EV-B
      PINT     T4UFINT;   // EV-B
      PINT     T4OFINT;   // EV-B
      PINT     CAPINT4;   // EV-B
      PINT     CAPINT5;   // EV-B
      PINT     CAPINT6;   // EV-B
      PINT     rsvd5_8;      

// PIE组6外设中断向量:
      PINT     SPIRXINTA; // SPI-A
      PINT     SPITXINTA; // SPI-A
      PINT     rsvd6_3;
      PINT     rsvd6_4;
      PINT     MRINTA;    // McBSP-A
      PINT     MXINTA;    // McBSP-A
      PINT     rsvd6_7;
      PINT     rsvd6_8;
      
// PIE组7外设中断向量:
      PINT     rsvd7_1;
      PINT     rsvd7_2;
      PINT     rsvd7_3;
      PINT     rsvd7_4;
      PINT     rsvd7_5;
      PINT     rsvd7_6;
      PINT     rsvd7_7;
      PINT     rsvd7_8;

// PIE组8外设中断向量:
      PINT     rsvd8_1;
      PINT     rsvd8_2;
      PINT     rsvd8_3;
      PINT     rsvd8_4;
      PINT     rsvd8_5;
      PINT     rsvd8_6;
      PINT     rsvd8_7;
      PINT     rsvd8_8; 

// PIE组9外设中断向量: 
      PINT     RXAINT;    // SCI-A
      PINT     TXAINT;    // SCI-A
      PINT     RXBINT;    // SCI-B
      PINT     TXBINT;    // SCI-B
      PINT     ECAN0INTA; // eCAN
      PINT     ECAN1INTA; // eCAN
      PINT     rsvd9_7;
      PINT     rsvd9_8;

// PIE组10外设中断向量:
      PINT     rsvd10_1;
      PINT     rsvd10_2;
      PINT     rsvd10_3;
      PINT     rsvd10_4;
      PINT     rsvd10_5;
      PINT     rsvd10_6;
      PINT     rsvd10_7;
      PINT     rsvd10_8;
            
// PIE组11外设中断向量:
      PINT     rsvd11_1;
      PINT     rsvd11_2;
      PINT     rsvd11_3;
      PINT     rsvd11_4;
      PINT     rsvd11_5;
      PINT     rsvd11_6;
      PINT     rsvd11_7;
      PINT     rsvd11_8;

// PIE组12外设中断向量:
      PINT     rsvd12_1;
      PINT     rsvd12_2;
      PINT     rsvd12_3;
      PINT     rsvd12_4;
      PINT     rsvd12_5;
      PINT     rsvd12_6;
      PINT     rsvd12_7;
      PINT     rsvd12_8;
};


extern struct PIE_VECT_TABLE PieVectTable;


#endif  

//===========================================================================
// No more.
//===========================================================================

