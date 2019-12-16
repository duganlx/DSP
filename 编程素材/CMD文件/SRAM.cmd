
MEMORY
{
PAGE 0 : 
   PRAMH0     : origin = 0x3f8000, length = 0x001000       
         
PAGE 1 : 
   /* SARAM                     */     
   RAMM0    : origin = 0x000000, length = 0x000400
   RAMM1    : origin = 0x000400, length = 0x000400

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
   DRAMH0     : origin = 0x3f9000, length = 0x001000         
}
 
 
SECTIONS
{
   /* Allocate program areas: */
   .reset           : > PRAMH0,      PAGE = 0
   .text            : > PRAMH0,      PAGE = 0
   .cinit           : > PRAMH0,      PAGE = 0

   /* Allocate data areas: */
   .stack           : > RAMM1,       PAGE = 1
   .bss             : > DRAMH0,      PAGE = 1
   .ebss            : > DRAMH0,      PAGE = 1
   .const           : > DRAMH0,      PAGE = 1
   .econst          : > DRAMH0,      PAGE = 1      
   .sysmem          : > DRAMH0,      PAGE = 1
   
   /* Allocate Peripheral Frame 0 Register Structures:   */
   DevEmuRegsFile    : > DEV_EMU,    PAGE = 1
   FlashRegsFile     : > FLASH_REGS, PAGE = 1
   CsmRegsFile       : > CSM,        PAGE = 1
   XintfRegsFile     : > XINTF,      PAGE = 1
   CpuTimer0RegsFile : > CPU_TIMER0, PAGE = 1      
   CpuTimer1RegsFile : > CPU_TIMER1, PAGE = 1      
   CpuTimer2RegsFile : > CPU_TIMER2, PAGE = 1      
   PieCtrlRegsFile   : > PIE_CTRL,   PAGE = 1      
   PieVectTable      : > PIE_VECT,   PAGE = 1

   /* Allocate Peripheral Frame 2 Register Structures:   */
   ECanaRegsFile     : > ECAN_A,      PAGE = 1   
   ECanaMboxesFile   : > ECAN_AMBOX   PAGE = 1

   /* Allocate Peripheral Frame 1 Register Structures:   */
   SysCtrlRegsFile   : > SYSTEM,     PAGE = 1
   SpiaRegsFile      : > SPI_A,      PAGE = 1
   SciaRegsFile      : > SCI_A,      PAGE = 1
   XIntruptRegsFile  : > XINTRUPT,   PAGE = 1
   GpioMuxRegsFile   : > GPIOMUX,    PAGE = 1
   GpioDataRegsFile  : > GPIODAT     PAGE = 1
   AdcRegsFile       : > ADC,        PAGE = 1
   EvaRegsFile       : > EV_A,       PAGE = 1
   EvbRegsFile       : > EV_B,       PAGE = 1
   ScibRegsFile      : > SCI_B,      PAGE = 1
   McbspaRegsFile    : > MCBSP_A,    PAGE = 1

   /* CSM Password Locations */
   CsmPwlFile      : > CSM_PWL,     PAGE = 1

}
