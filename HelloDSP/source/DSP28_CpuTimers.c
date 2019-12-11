
/****************************************************************************
*
*文件名：DSP28_CpuTimers.c
*
*功  能：初始化32位CPU定时器
*
*作  者: likyo from hellodsp
*
****************************************************************************/

#include "DSP28_Device.h"

struct CPUTIMER_VARS CpuTimer0; //对用户开放的CPU定时器只有CpuTimer0，CpuTimer1
struct CPUTIMER_VARS CpuTimer1; //和CpuTimer2被保留用作实习操作系统OS（例如DSP
struct CPUTIMER_VARS CpuTimer2; //BIOS）

/****************************************************************************
*
*名    称：InitCpuTimers()
*
*功    能：初始化CpuTimer0。
*
*入口参数：无
*
*出口参数：无
*
****************************************************************************/

void InitCpuTimers(void)
{
	CpuTimer0.RegsAddr = &CpuTimer0Regs; //使得CpuTimer0.RegsAddr 指向定时器寄存器
	
	CpuTimer0Regs.PRD.all  = 0xFFFFFFFF; //初始化CpuTimer0的周期寄存器

	CpuTimer0Regs.TPR.all  = 0;          //初始化定时器预定标计数器
	CpuTimer0Regs.TPRH.all = 0;
	
	CpuTimer0Regs.TCR.bit.TSS = 1;       //停止定时器       

	CpuTimer0Regs.TCR.bit.TRB = 1;       //将周期寄存器PRD中的值装入计数器寄存器TIM中           
	
	CpuTimer0.InterruptCount = 0;        //初始化定时器中断计数器
}	
	
/****************************************************************************
*
*名    称：ConfigCpuTimer()
*
*功    能：此函数将使用Freq和Period两个参数来对CPU定时器进行配置。Freq以MHz
*          为单位，Period以us作为单位。
*
*入口参数：*Timer（指定的定时器），Freq，Period
*
*出口参数：无
*
****************************************************************************/

void ConfigCpuTimer(struct CPUTIMER_VARS *Timer, float Freq, float Period)
{
	Uint32 	temp;
	
	Timer->CPUFreqInMHz = Freq;
	Timer->PeriodInUSec = Period;
	temp = (long) (Freq * Period);
	Timer->RegsAddr->PRD.all = temp;  //给定时器周期寄存器赋值

	Timer->RegsAddr->TPR.all  = 0;    //给定时器预定标寄存器赋值
	Timer->RegsAddr->TPRH.all  = 0;
	
	// 初始化定时器控制寄存器:
	Timer->RegsAddr->TCR.bit.TIF=1;   //清除中断标志位
	Timer->RegsAddr->TCR.bit.TSS = 1; //停止定时器 
	Timer->RegsAddr->TCR.bit.TRB = 1; //定时器重装，将定时器周期寄存器的值装入定时器计数器寄存器
	Timer->RegsAddr->TCR.bit.SOFT = 1;
	Timer->RegsAddr->TCR.bit.FREE = 1;     
	Timer->RegsAddr->TCR.bit.TIE = 1; //使能定时器中断
	
	Timer->InterruptCount = 0;        //初始化定时器中断计数器
}

//===========================================================================
// No more.
//===========================================================================
