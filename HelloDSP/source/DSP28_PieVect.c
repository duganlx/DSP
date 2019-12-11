
/****************************************************************************
*
*文件名：DSP28_PieVect.c
*
*功  能：对2812中断向量表进行初始化功能
*
*作  者: likyo from hellodsp
*
****************************************************************************/

#include "DSP28_Device.h"

const struct PIE_VECT_TABLE PieVectTableInit = {

      PIE_RESERVED,  // 保留的空间
      PIE_RESERVED,   
      PIE_RESERVED,   
      PIE_RESERVED,   
      PIE_RESERVED,   
      PIE_RESERVED,   
      PIE_RESERVED,   
      PIE_RESERVED,   
      PIE_RESERVED,   
      PIE_RESERVED,   
      PIE_RESERVED,   
      PIE_RESERVED,   
      PIE_RESERVED,   


      // 非外设中断向量
      INT13_ISR,     // XINT13或者CPU定时器1中断
      INT14_ISR,     // CPU定时器2中断
      DATALOG_ISR,   // CPU数据记录中断
      RTOSINT_ISR,   // CPU实时OS中断
      EMUINT_ISR,    // CPU仿真中断
      NMI_ISR,       // 外部非屏蔽中断
      ILLEGAL_ISR,   // 非法操作
      USER0_ISR,     // 用户定义软中断0
      USER1_ISR,     // 用户定义软中断1
      USER2_ISR,     // 用户定义软中断2
      USER3_ISR,     // 用户定义软中断3
      USER4_ISR,     // 用户定义软中断4
      USER5_ISR,     // 用户定义软中断5
      USER6_ISR,     // 用户定义软中断6
      USER7_ISR,     // 用户定义软中断7
      USER8_ISR,     // 用户定义软中断8
      USER9_ISR,     // 用户定义软中断9
      USER10_ISR,    // 用户定义软中断10
      USER11_ISR,    // 用户定义软中断11

      // PIE 组1向量
      PDPINTA_ISR,   // EV-A的功率驱动保护中断
      PDPINTB_ISR,   // EV-B的功率驱动保护中断
      rsvd_ISR,      // 保留
      XINT1_ISR,     // 外部接口（XINT1）中断   
      XINT2_ISR,     // 外部接口（XINT2）中断
      ADCINT_ISR,    // ADC中断
      TINT0_ISR,     // CPU定时器0中断
      WAKEINT_ISR,   // WD中断

      // PIE 组2向量
      CMP1INT_ISR,   // 比较单元1比较中断
      CMP2INT_ISR,   // 比较单元2比较中断
      CMP3INT_ISR,   // 比较单元3比较中断
      T1PINT_ISR,    // 通用定时器1周期中断
      T1CINT_ISR,    // 通用定时器1比较中断
      T1UFINT_ISR,   // 通用定时器1下溢中断
      T1OFINT_ISR,   // 通用定时器1上溢中断
      rsvd_ISR,      // 保留
      
      // PIE 组3向量
      T2PINT_ISR,    // 通用定时器2周期中断
      T2CINT_ISR,    // 通用定时器2比较中断
      T2UFINT_ISR,   // 通用定时器2下溢中断
      T2OFINT_ISR,   // 通用定时器2上溢中断
      CAPINT1_ISR,   // 捕获单元1捕获中断
      CAPINT2_ISR,   // 捕获单元2捕获中断
      CAPINT3_ISR,   // 捕获单元3捕获中断
      rsvd_ISR,
      
      // PIE 组4向量
      CMP4INT_ISR,   // 比较单元4比较中断
      CMP5INT_ISR,   // 比较单元5比较中断
      CMP6INT_ISR,   // 比较单元6比较中断
      T3PINT_ISR,    // 通用定时器3周期中断
      T3CINT_ISR,    // 通用定时器3比较中断
      T3UFINT_ISR,   // 通用定时器3下溢中断
      T3OFINT_ISR,   // 通用定时器3上溢中断
      rsvd_ISR,      // 保留
     
      // PIE 组5向量
      T4PINT_ISR,    // 通用定时器4周期中断
      T4CINT_ISR,    // 通用定时器4比较中断
      T4UFINT_ISR,   // 通用定时器4下溢中断
      T4OFINT_ISR,   // 通用定时器4上溢中断
      CAPINT4_ISR,   // 捕获单元4捕获中断
      CAPINT5_ISR,   // 捕获单元5捕获中断
      CAPINT6_ISR,   // 捕获单元6捕获中断
      rsvd_ISR,      // 保留  

      // PIE 组6向量
      SPIRXINTA_ISR, // SPI-A接收中断
      SPITXINTA_ISR, // SPI-A发送中断
      rsvd_ISR,      // 保留
      rsvd_ISR,
      MRINTA_ISR,    // McBSP-A接收中断
      MXINTA_ISR,    // McBSP-A发送中断
      rsvd_ISR,      //保留
      rsvd_ISR,
      
      // PIE 组7向量
      rsvd_ISR,   
      rsvd_ISR,   
      rsvd_ISR,   
      rsvd_ISR,   
      rsvd_ISR,   
      rsvd_ISR,   
      rsvd_ISR,   
      rsvd_ISR,   

      // PIE 组8向量
      rsvd_ISR,   
      rsvd_ISR,   
      rsvd_ISR,   
      rsvd_ISR,   
      rsvd_ISR,   
      rsvd_ISR,   
      rsvd_ISR,   
      rsvd_ISR,   
      
      // PIE 组9向量    
      SCIRXINTA_ISR, // SCI-A接收中断
      SCITXINTA_ISR, // SCI-A发送中断
      SCIRXINTB_ISR, // SCI-B接收中断
      SCITXINTB_ISR, // SCI-B发送中断
      ECAN0INTA_ISR, // eCAN0中断
      ECAN1INTA_ISR, // eCAN1中断
      rsvd_ISR,   
      rsvd_ISR,   
      
      // PIE 组10向量
      rsvd_ISR,   
      rsvd_ISR,   
      rsvd_ISR,   
      rsvd_ISR,   
      rsvd_ISR,   
      rsvd_ISR,   
      rsvd_ISR,   
      rsvd_ISR,   
            
      // PIE 组11向量
      rsvd_ISR,   
      rsvd_ISR,   
      rsvd_ISR,   
      rsvd_ISR,   
      rsvd_ISR,   
      rsvd_ISR,   
      rsvd_ISR,   
      rsvd_ISR,   

      // PIE 组12向量
      rsvd_ISR,   
      rsvd_ISR,   
      rsvd_ISR,   
      rsvd_ISR,   
      rsvd_ISR,   
      rsvd_ISR,   
      rsvd_ISR,   
      rsvd_ISR,   
};


/****************************************************************************
*
*名    称：InitPieVectTable()
*
*功    能：该函数对PIE中断向量表进行初始化，在上电引导后被执行
*
*入口参数：无
*
*出口参数：无
*
****************************************************************************/

void InitPieVectTable(void)
{
	int16	i;
	Uint32 *Source = (void *) &PieVectTableInit;
	Uint32 *Dest = (void *) &PieVectTable;
		
	EALLOW;	
	for(i=0; i < 128; i++)
		*Dest++ = *Source++;	
	EDIS;

	// 使能PIE向量表
	PieCtrl.PIECRTL.bit.ENPIE = 1;	
			
}

//===========================================================================
// No more.
//===========================================================================
