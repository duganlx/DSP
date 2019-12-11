
/****************************************************************************
*
*文件名：DSP28_PieCtrl.c
*
*功  能：对PIE中断的控制寄存器进行初始化
*
*作  者: likyo from hellodsp
*
****************************************************************************/

#include "DSP28_Device.h"

/****************************************************************************
*
*名    称：InitPieCtrl()
*
*功    能：PIE中断控制器初始化函数        
*
*入口参数：无
*
*出口参数：无
*
****************************************************************************/

void InitPieCtrl(void)
{
	// 禁止PIE模块
	PieCtrl.PIECRTL.bit.ENPIE = 0;

	// 禁止PIE所有中断
	PieCtrl.PIEIER1.all = 0;
	PieCtrl.PIEIER2.all = 0;
	PieCtrl.PIEIER3.all = 0;	
	PieCtrl.PIEIER4.all = 0;
	PieCtrl.PIEIER5.all = 0;
	PieCtrl.PIEIER6.all = 0;
	PieCtrl.PIEIER7.all = 0;
	PieCtrl.PIEIER8.all = 0;
	PieCtrl.PIEIER9.all = 0;
	PieCtrl.PIEIER10.all = 0;
	PieCtrl.PIEIER11.all = 0;
	PieCtrl.PIEIER12.all = 0;

	// 清除所有PIEIFR的中断标志位
	PieCtrl.PIEIFR1.all = 0;
	PieCtrl.PIEIFR2.all = 0;
	PieCtrl.PIEIFR3.all = 0;	
	PieCtrl.PIEIFR4.all = 0;
	PieCtrl.PIEIFR5.all = 0;
	PieCtrl.PIEIFR6.all = 0;
	PieCtrl.PIEIFR7.all = 0;
	PieCtrl.PIEIFR8.all = 0;
	PieCtrl.PIEIFR9.all = 0;
	PieCtrl.PIEIFR10.all = 0;
	PieCtrl.PIEIFR11.all = 0;
	PieCtrl.PIEIFR12.all = 0;

	// 使能PIE模块
	PieCtrl.PIECRTL.bit.ENPIE = 1;
	PieCtrl.PIEACK.all = 0xFFFF;
}	

//===========================================================================
// No more.
//===========================================================================
