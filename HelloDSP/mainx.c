#include "DSP28_Device.h"

void main()
{
	int kk=0;

	InitSysChrl();

	DINT;


	while(1)
	{
		GpioDataRegs.GPFCLEAR.bit.GPIOF14=1;
		for(kk=0; kk<100; kk++)
			delay_loop();
		
		GpioDataRegs.GPFSET.bit.GPIOF14=1;
		for(kk=0; kk<100; kk++)
			delay_loop();
	}
}

void delay_loop()
{
	short i;
	for(i=0; i<30000; i++){}
}