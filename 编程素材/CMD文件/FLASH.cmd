MEMORY
{
PAGE 0 : 
   OTP         : origin = 0x3D7800, length = 0x000800
   FLASHJ      : origin = 0x3D8000, length = 0x002000
   FLASHI      : origin = 0x3DA000, length = 0x002000
   FLASHH      : origin = 0x3DC000, length = 0x004000 
   FLASHG      : origin = 0x3E0000, length = 0x004000
   FLASHF      : origin = 0x3E4000, length = 0x004000
   FLASHE      : origin = 0x3E8000, length = 0x004000 
   FLASHD      : origin = 0x3EC000, length = 0x004000
   FLASHC      : origin = 0x3F0000, length = 0x004000
   FLASHB      : origin = 0x3F4000, length = 0x002000 
   FLASHA      : origin = 0x3F6000, length = 0x001FF6
   BEGIN       : origin = 0x3F7FF6, length = 0x000002
   PASSWDS     : origin = 0x3F7FF8, length = 0x000008
   ROM         : origin = 0x3FF000, length = 0x000FC0
   VECTORS     : origin = 0x3FFFC2, length = 0x00003E
         
PAGE 1 : 
   /* SARAM                     */     
   RAMM0M1    : origin = 0x000000, length = 0x000800

   /* Peripheral Frame 0:   */
   DEV_EMU    : origin = 0x000880, length = 0x000180
   FLASH_REGS : origin = 0x000A80, length = 0x000060
   CSM        : origin = 0x000AE0, length = 0x000010
   XINTF      : origin = 0x000B20, length = 0x000020
   CPU_TIMER0 : origin = 0x000C00, length = 0x000008
   CPU_TIMER1 : origin = 0x000C08, length = 0x000008		 
   CPU_TIMER2 : origin = 0x000C10, length = 0x000008		 
   PIE_CTRL   : origin = 0x000CE0, length = 0x000020
   PIE_VECT   : origin = 0x000D00, length = 0x000100

   /* Peripheral Frame 1:   */
   ECAN_A     : origin = 0x006000, length = 0x000100
   ECAN_AMBOX : origin = 0x006100, length = 0x000100

   /* Peripheral Frame 2:   */
   SYSTEM     : origin = 0x007010, length = 0x000020
   SPI_A      : origin = 0x007040, length = 0x000010
   SCI_A      : origin = 0x007050, length = 0x000010
   XINTRUPT   : origin = 0x007070, length = 0x000010
   GPIOMUX    : origin = 0x0070C0, length = 0x000020
   GPIODAT    : origin = 0x0070E0, length = 0x000020
   ADC        : origin = 0x007100, length = 0x000020
   EV_A       : origin = 0x007400, length = 0x000040
   EV_B       : origin = 0x007500, length = 0x000040
   SPI_B      : origin = 0x007740, length = 0x000010
   SCI_B      : origin = 0x007750, length = 0x000010
   MCBSP_A    : origin = 0x007800, length = 0x000040

   /* CSM Password Locations */
   CSM_PWL    : origin = 0x3F7FF8, length = 0x000008

   /* SARAM                    */     
   RAML0L1    : origin = 0x008000, length = 0x002000
   RAMH0      : origin = 0x3F8000, length = 0x002000        
}
 
 
SECTIONS
{
   /* Allocate program areas: */
   .reset              : > BEGIN       PAGE = 0
   vectors             : > VECTORS     PAGE = 0
   .cinit              : > FLASHJ      PAGE = 0
   .text               : > FLASHA       PAGE = 0

   /* Allocate data areas: */
   .stack              : > RAMM0M1     PAGE = 1
   .bss                : > RAML0L1     PAGE = 1
   .ebss               : > RAML0L1     PAGE = 1
   .const:			load = 	FLASHB PAGE 0, run = RAML0L1 PAGE 1
	{
	    /* Get Run Address	*/
	    __const_run = .;
	    /* Mark Load Address*/
	    *(.c_mark)
	    /* Allocate .const	*/
	    *(.const)
	    /* Compute Length	*/
	    __const_length = .-__const_run;
	}  
   
   .econst:			load = 	FLASHB PAGE 0, run = RAML0L1 PAGE 1
	{
	    /* Get Run Address	*/
	    __econst_run = .;
	    /* Mark Load Address*/
	    *(.ec_mark)
	    /* Allocate .const	*/
	    *(.econst)
	    /* Compute Length	*/
	    __econst_length = .-__econst_run;
	}    
   .sysmem             : > RAMH0       PAGE = 1

   /* Allocate IQ math areas: */
   IQmath              : > FLASHI      PAGE = 0   /* Math Code */
   IQmathFastTables    : > FLASHI      PAGE = 0   /* Math Tables in fast memory */
   IQmathTables        : > ROM         PAGE = 0   /* Math Tables In ROM */
      
   /* Allocate Peripheral Frame 0 Register Structures:   */
   DevEmuRegsFile      : > DEV_EMU     PAGE = 1
   FlashRegsFile       : > FLASH_REGS  PAGE = 1
   CsmRegsFile         : > CSM         PAGE = 1
   XintfRegsFile       : > XINTF       PAGE = 1
   CpuTimer0RegsFile   : > CPU_TIMER0  PAGE = 1      
   CpuTimer1RegsFile   : > CPU_TIMER1  PAGE = 1      
   CpuTimer2RegsFile   : > CPU_TIMER2  PAGE = 1      
   PieCtrlRegsFile     : > PIE_CTRL    PAGE = 1      
   PieVectTable        : > PIE_VECT    PAGE = 1

   /* Allocate Peripheral Frame 2 Register Structures:   */
   ECanaRegsFile       : > ECAN_A      PAGE = 1   
   ECanaMboxesFile     : > ECAN_AMBOX  PAGE = 1

   /* Allocate Peripheral Frame 1 Register Structures:   */
   SysCtrlRegsFile     : > SYSTEM      PAGE = 1
   SpiaRegsFile        : > SPI_A       PAGE = 1
   SciaRegsFile        : > SCI_A       PAGE = 1
   XIntruptRegsFile    : > XINTRUPT    PAGE = 1
   GpioMuxRegsFile     : > GPIOMUX     PAGE = 1
   GpioDataRegsFile    : > GPIODAT     PAGE = 1
   AdcRegsFile         : > ADC         PAGE = 1
   EvaRegsFile         : > EV_A        PAGE = 1
   EvbRegsFile         : > EV_B        PAGE = 1
   ScibRegsFile        : > SCI_B       PAGE = 1
   McbspaRegsFile      : > MCBSP_A     PAGE = 1

   /* CSM Password Locations */
   CsmPwlFile          : > CSM_PWL     PAGE = 1

}
