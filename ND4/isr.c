#include ".\cpu.h"

ISR_ST_USART_FIFO volatile ISR_Usart1_Buff;

uint8_t status=0;
uint8_t a=0;

void PIOD_Handler()
{
	uint32_t piod_status;
	piod_status = PIOD->PIO_PDSR;
	
	if ((piod_status&PIO_PDSR_P19)==PIO_PDSR_P19)
	{
		Start();
	}
}