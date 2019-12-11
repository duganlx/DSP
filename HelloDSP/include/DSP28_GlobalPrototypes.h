
/****************************************************************************
*
*文件名：DSP28_GlobalPrototypes.h
*
*功  能：2812全局函数声明文件
*
*作  者: HELLODSP
*
****************************************************************************/


#ifndef EXAMPLE_H
#define EXAMPLE_H

/*---- 全局函数声明 -----------------------------------*/
extern void InitAdc(void);
extern void InitDevEmu(void);
extern void InitDevice(void);
extern void InitECana(void);
extern void InitEv(void);
extern void InitGpio(void);
extern void InitMcbsp(void);
extern void InitPieCtrl(void);
extern void InitPieVectTable(void);
extern void InitPeripherals(void);
extern void InitSci(void);
extern void InitSpi(void);
extern void InitSysCtrl(void);
extern void InitXintf(void);
extern void InitXIntrupt(void);

extern void KickDog(void);

#endif   

//===========================================================================
// No more.
//===========================================================================

