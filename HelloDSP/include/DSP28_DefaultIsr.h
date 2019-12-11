
/****************************************************************************
*
*文件名：DSP28_DefaultIsr.h
*
*功  能：2812 默认中断服务程序的定义
*
*作  者: HELLODSP
*
****************************************************************************/

#ifndef DSP28_DEFAULT_ISR_H
#define DSP28_DEFAULT_ISR_H

// 下面的函数说明是PIE向量表里用到的2812默认的中断服务程序。
// PIE向量表在DSP28_PieVect.h内

// 非外设中断:
interrupt void INT13_ISR(void);     // XINT13 or CPU-Timer 1
interrupt void INT14_ISR(void);     // CPU-Timer2
interrupt void DATALOG_ISR(void);   // Datalogging interrupt
interrupt void RTOSINT_ISR(void);   // RTOS interrupt
interrupt void EMUINT_ISR(void);    // Emulation interrupt
interrupt void NMI_ISR(void);       // Non-maskable interrupt
interrupt void ILLEGAL_ISR(void);   // Illegal operation TRAP
interrupt void USER0_ISR(void);     // User Defined trap 0
interrupt void USER1_ISR(void);     // User Defined trap 1
interrupt void USER2_ISR(void);     // User Defined trap 2
interrupt void USER3_ISR(void);     // User Defined trap 3
interrupt void USER4_ISR(void);     // User Defined trap 4
interrupt void USER5_ISR(void);     // User Defined trap 5
interrupt void USER6_ISR(void);     // User Defined trap 6
interrupt void USER7_ISR(void);     // User Defined trap 7
interrupt void USER8_ISR(void);     // User Defined trap 8
interrupt void USER9_ISR(void);     // User Defined trap 9
interrupt void USER10_ISR(void);    // User Defined trap 10
interrupt void USER11_ISR(void);    // User Defined trap 11

// PIE模块组1中的中断服务程序:
interrupt void  PDPINTA_ISR(void);   // EV-A
interrupt void  PDPINTB_ISR(void);   // EV-B
interrupt void  XINT1_ISR(void);     
interrupt void  XINT2_ISR(void);
interrupt void  ADCINT_ISR(void);    // ADC
interrupt void  TINT0_ISR(void);     // Timer 0
interrupt void  WAKEINT_ISR(void);   // WD

// PIE模块组2中的中断服务程序:
interrupt void CMP1INT_ISR(void);   // EV-A
interrupt void CMP2INT_ISR(void);   // EV-A
interrupt void CMP3INT_ISR(void);   // EV-A
interrupt void T1PINT_ISR(void);    // EV-A
interrupt void T1CINT_ISR(void);    // EV-A
interrupt void T1UFINT_ISR(void);   // EV-A
interrupt void T1OFINT_ISR(void);   // EV-A
      
// PIE模块组3中的中断服务程序：
interrupt void T2PINT_ISR(void);    // EV-A
interrupt void T2CINT_ISR(void);    // EV-A
interrupt void T2UFINT_ISR(void);   // EV-A
interrupt void T2OFINT_ISR(void);   // EV-A
interrupt void CAPINT1_ISR(void);   // EV-A
interrupt void CAPINT2_ISR(void);   // EV-A
interrupt void CAPINT3_ISR(void);   // EV-A
      
// PIE模块组4中的中断服务程序:
interrupt void CMP4INT_ISR(void);   // EV-B
interrupt void CMP5INT_ISR(void);   // EV-B
interrupt void CMP6INT_ISR(void);   // EV-B
interrupt void T3PINT_ISR(void);    // EV-B
interrupt void T3CINT_ISR(void);    // EV-B
interrupt void T3UFINT_ISR(void);   // EV-B
interrupt void T3OFINT_ISR(void);   // EV-B
     
// PIE模块组5中的中断服务程序:
interrupt void T4PINT_ISR(void);    // EV-B
interrupt void T4CINT_ISR(void);    // EV-B
interrupt void T4UFINT_ISR(void);   // EV-B
interrupt void T4OFINT_ISR(void);   // EV-B
interrupt void CAPINT4_ISR(void);   // EV-B
interrupt void CAPINT5_ISR(void);   // EV-B
interrupt void CAPINT6_ISR(void);   // EV-B

// PIE模块组6中的中断服务程序:
interrupt void SPIRXINTA_ISR(void);   // SPI
interrupt void SPITXINTA_ISR(void);    // SPI
interrupt void MRINTA_ISR(void);    // McBSP
interrupt void MXINTA_ISR(void);    // McBSP
 
   
// PIE模块组9中的中断服务程序:
interrupt void SCIRXINTA_ISR(void); // SCI-A
interrupt void SCITXINTA_ISR(void); // SCI-A
interrupt void SCIRXINTB_ISR(void); // SCI-B
interrupt void SCITXINTB_ISR(void); // SCI-B
interrupt void ECAN0INTA_ISR(void); // eCAN
interrupt void ECAN1INTA_ISR(void); // eCAN


// 保留的测试用程序:
interrupt void PIE_RESERVED(void);       // Reserved for test
interrupt void rsvd_ISR(void);           // for test

#endif    // end of DSP28_DEFAULT_ISR_H definition

