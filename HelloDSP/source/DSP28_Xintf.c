
/****************************************************************************
*
*文件名：DSP28_Xintf.c
*
*功  能：初始化2812外部接口
*
*作  者: likyo from hellodsp
*
****************************************************************************/

#include "DSP28_Device.h"

/****************************************************************************
*
*名    称：InitXintf()
*
*功    能：初始化外部接口。
*
*入口参数：无
*
*出口参数：无
*
****************************************************************************/

void InitXintf(void)
{

	#if  F2812
   
   //选择建立、激活和跟踪的定时转换操作的基本时钟
    XintfRegs.XINTCNF2.bit.XTIMCLK = 0x0000;
    
    // Zone 0:
	XintfRegs.XTIMING0.bit.XWRTRAIL = 3;    //写周期的跟踪时间为3个XTIMCLK周期
	XintfRegs.XTIMING0.bit.XWRACTIVE = 7;   //写周期的激活等待时间为7个XTIMCLK周期
	XintfRegs.XTIMING0.bit.XWRLEAD = 3;     //写周期的建立时间为3个XTIMCLK周期
	XintfRegs.XTIMING0.bit.X2TIMING = 0;
	
	// Zone 2
	XintfRegs.XTIMING2.bit.USEREADY = 0;    //区访问时，忽略XREADY信号
	XintfRegs.XTIMING2.bit.XRDLEAD = 3;     //读周期的建立时间为6个XTIMCLK周期
	XintfRegs.XTIMING2.bit.XWRACTIVE = 7;   //写周期的激活等待时间为14个XTIMCLK周期
	XintfRegs.XTIMING2.bit.XRDTRAIL = 3;    //读周期的跟踪时间为6个XTIMCLK
	XintfRegs.XTIMING2.bit.X2TIMING = 1;    

    XintfRegs.XBANK.bit.BANK = 2; //2区的存储体转换有效
    XintfRegs.XBANK.bit.BCYC = 3; 
	
	#endif
}	
	
//===========================================================================
// No more.
//===========================================================================
