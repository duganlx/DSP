
/****************************************************************************
*
*文件名：DSP28_Device.h
*
*功  能：2812设备的相关定义
*
*作  者: HELLODSP
*
****************************************************************************/

#ifndef DSP28_DEVICE_H
#define DSP28_DEVICE_H

#define	TARGET	1
//---------------------------------------------------------------------------
// 您可以选择目标芯片:

#define	F2812   TARGET
#define	F2810   0

//---------------------------------------------------------------------------
// 通用的CPU定义:

extern cregister volatile unsigned int IFR;
extern cregister volatile unsigned int IER;
#define  EINT   asm(" clrc INTM")
#define  DINT   asm(" setc INTM")
#define  ERTM   asm(" clrc DBGM")
#define  DRTM   asm(" setc DBGM")
#define	 EALLOW	asm(" EALLOW")
#define	 EDIS	asm(" EDIS")
#define  ESTOP0 asm(" ESTOP0")
#define  NOP asm(" NOP")

#define	M_INT1		0x0001
#define	M_INT2		0x0002
#define	M_INT3		0x0004
#define	M_INT4		0x0008
#define	M_INT5		0x0010
#define	M_INT6		0x0020
#define	M_INT7		0x0040
#define	M_INT8		0x0080
#define	M_INT9		0x0100
#define	M_INT10		0x0200
#define	M_INT11		0x0400
#define	M_INT12		0x0800
#define	M_INT13		0x1000
#define	M_INT14		0x2000
#define	M_DLOG		0x4000
#define	M_RTOS		0x8000

#define	BIT0		0x0001
#define	BIT1		0x0002
#define	BIT2		0x0004
#define	BIT3		0x0008
#define	BIT4		0x0010
#define	BIT5		0x0020
#define	BIT6		0x0040
#define	BIT7		0x0080
#define	BIT8		0x0100
#define	BIT9		0x0200
#define	BIT10		0x0400
#define	BIT11		0x0800
#define	BIT12		0x1000
#define	BIT13		0x2000
#define	BIT14		0x4000
#define	BIT15		0x8000

//---------------------------------------------------------------------------
// 为了具有更好的可移植性，建议您定义变量时使用下面的数据类型
// 16位和32位的有符号和无符号数据类型的定义如下:
//

typedef int  		int16;
typedef long 		int32;
typedef unsigned int  	Uint16;
typedef unsigned long 	Uint32;

//---------------------------------------------------------------------------
// 包含所有的头文件:
//

#include "DSP28_GlobalPrototypes.h"   // 源文件中全局函数的原型

#include "DSP28_SysCtrl.h"         // 系统控制
#include "DSP28_DevEmu.h"          // 仿真寄存器
#include "DSP28_Xintf.h"           // 外部接口寄存器
#include "DSP28_CpuTimers.h"       // 32位CPU定时器
#include "DSP28_PieCtrl.h"         // PIE控制寄存器
#include "DSP28_PieVect.h"         // PIE向量表
#include "DSP28_DefaultIsr.h"      // PIE中断函数
#include "DSP28_Spi.h"             // SPI 寄存器
#include "DSP28_Sci.h"             // SCI 寄存器
#include "DSP28_Mcbsp.h"           // McBSP 寄存器
#include "DSP28_ECan.h"            // 增强型 eCAN 寄存器
#include "DSP28_Gpio.h"            // 通用I/O模块寄存器
#include "DSP28_Ev.h"              // 事件管理器寄存器
#include "DSP28_Adc.h"             // ADC 寄存器
#include "DSP28_XIntrupt.h"        // 外部中断
#include "DSP28_Globalvariable.h"  // 全局变量

#endif  


//===========================================================================
// No more.
//===========================================================================
