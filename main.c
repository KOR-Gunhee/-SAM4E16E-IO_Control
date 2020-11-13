#include "main.h"

uint8_t sw_status=0;

void test2(uint8_t a)
{
	PINLOW(LATPIN);
	PINHIGH(DATAPIN);
	Clk();
	
	for(int i=0;i<a;i++)
	{
		PINLOW(DATAPIN);
		Clk();
	}
}

void BoardInit()
{
	WDT->WDT_MR=WDT_MR_WDDIS;
	
	SystemInit();
	
	__disable_irq();
	
	PIOInit();

	PMCInit();
	
	USARTInit();
		
	__enable_irq();
}

int main(void)
{
    /* Initialize the SAM system */
    BoardInit();
	init();
		
	Start();
	
    /* Replace with your application code */
    while (1) 
    {	
		
	}
}
