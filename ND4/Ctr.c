#include ".\cpu.h"

//digitalWrite(dataPin, !!(val & (1 << (7 - i))));

DATA_BUFF_FIFO volatile DATA_Buff;

void GET_BUFF(uint8_t num)
{
	if(DATA_Buff.Tail>=DATA_BUFF){DATA_Buff.Tail=0;}
	DATA_Buff.Buff[DATA_Buff.Tail++]=num;
}

void SCRIN()
{
	char data[33 + 1];
	
// 	for (int j=0;j<DATA_Buff.Tail;j++)
// 	{
// 		msg[j]=DATA_Buff.Buff[j];
// 	}
// 	
	for (int i=0;i<DATA_Buff.Tail;i++)
	{
		//US_SendByte(atoi(DATA_Buff.Buff[i]));
		
		US_SendString(itoa(DATA_Buff.Buff[i], data, 10));
		US_SendString("\r\n");
	}
	
	DATA_Buff.Tail=0;

}
void init()
{
	PINLOW(LATPIN);
	for (int i=0;i<80;i++)
	{
		PINLOW(DATAPIN);
		Clk();
	}
	PINHIGH(LATPIN);
}


void Clk()
{
	PINHIGH(CLKPIN);
	PINLOW(CLKPIN);
}

void Clk2(int cnt)
{
	PINHIGH(CLKPIN);
	PINLOW(CLKPIN);
	PINLOW(DATAPIN);
	for(int i=0;i<cnt;i++)
	{	
		PINHIGH(CLKPIN);
		PINLOW(CLKPIN);
	}
}

void Latch()
{
	PINHIGH(LATPIN);
	MyDelay2(1000,10000);
	PINLOW(LATPIN);
}

void jump()
{
	PINLOW(LATPIN);
	Clk();
	PINHIGH(LATPIN);
}

void MyDelay(volatile uint32_t delay)
{
	while(delay)
	{
		delay--;
	}
}

void MyDelay2(volatile uint32_t delay1,volatile uint32_t delay2)
{
	while(delay1)
	{
		MyDelay(delay2);
		delay1--;
	}
}

void Shift72()
{
	int i;
	uint32_t pioa_status;
	uint32_t piob_status;
	uint32_t pioc_status;
	uint32_t piod_status;
	
	
	US_SendString("---------------72Pin Start-------------\r\n");
	a=0;
	for(i=0;i<80;i++)
	{
		init();
		if (i==18||i==19||i==38||i==39||i==58||i==59||i==78||i==79)
		{
			PINLOW(LATPIN);
			Clk();
		}
		else
		{
			PINLOW(LATPIN);
			PINHIGH(DATAPIN);
			Clk2(i);
			PINHIGH(LATPIN);
									
			MyDelay2(100,10000);
			
			pioa_status = PIOA->PIO_PDSR;
			piob_status = PIOB->PIO_PDSR;
			pioc_status = PIOC->PIO_PDSR;
			piod_status = PIOD->PIO_PDSR;
			
			if (i==0){if (!((pioa_status&PIO_PDSR_P4)==PIO_PDSR_P4)){US_SendString("A1");US_SendString("\r\n");}}
			if (i==1){if ((pioa_status&(1<<5))!=(1<<5)){US_SendString("A2");US_SendString("\r\n");}}
			if (i==2){if ((pioa_status&(1<<6))!=(1<<6)){US_SendString("A3");US_SendString("\r\n");}}
			if (i==3){if ((pioa_status&(1<<7))!=(1<<7)){US_SendString("A4");US_SendString("\r\n");}}
			if (i==4){if ((pioa_status&(1<<8))!=(1<<8)){US_SendString("A5");US_SendString("\r\n");}}
			if (i==5){if ((pioa_status&(1<<9))!=(1<<9)){US_SendString("A6");US_SendString("\r\n");}}
			if (i==6){if ((pioa_status&(1<<10))!=(1<<10)){US_SendString("A7");US_SendString("\r\n");}}
			if (i==7){if ((pioa_status&(1<<15))!=(1<<15)){US_SendString("A8");US_SendString("\r\n");}}
			if (i==8){if ((pioa_status&(1<<16))!=(1<<16)){US_SendString("A9");US_SendString("\r\n");}}
			if (i==9){if ((pioa_status&(1<<17))!=(1<<17)){US_SendString("A10");US_SendString("\r\n");}}
			
			if (i==10){if ((pioa_status&(1<<18))!=(1<<18)){US_SendString("A11");US_SendString("\r\n");}}
			if (i==11){if ((pioa_status&(1<<19))!=(1<<19)){US_SendString("A12");US_SendString("\r\n");}}
			if (i==12){if ((pioa_status&(1<<20))!=(1<<20)){US_SendString("A13");US_SendString("\r\n");}}
			if (i==13){if ((pioa_status&(1<<23))!=(1<<23)){US_SendString("A14");US_SendString("\r\n");}}
			if (i==14){if ((pioa_status&(1<<24))!=(1<<24)){US_SendString("A15");US_SendString("\r\n");}}
			if (i==15){if ((pioa_status&(1<<25))!=(1<<25)){US_SendString("A16");US_SendString("\r\n");}}
			if (i==16){if ((pioa_status&(1<<26))!=(1<<26)){US_SendString("A17");US_SendString("\r\n");}}
			if (i==17){if ((pioa_status&(1<<27))!=(1<<27)){US_SendString("A18");US_SendString("\r\n");}}
			if (i==20){if ((pioa_status&(1<<28))!=(1<<28)){US_SendString("B1");US_SendString("\r\n");}}
			if (i==21){if ((pioa_status&(1<<29))!=(1<<29)){US_SendString("B2");US_SendString("\r\n");}}
			if (i==22){if ((pioa_status&(1<<30))!=(1<<30)){US_SendString("B3");US_SendString("\r\n");}}
			
			if (i==23){if ((pioa_status&(1<<31))!=(1<<31)){US_SendString("B4");US_SendString("\r\n");}}
			if (i==24){if ((piob_status&(1<<0))!=(1<<0)){US_SendString("B5");US_SendString("\r\n");}}
			if (i==25){if ((piob_status&(1<<1))!=(1<<1)){US_SendString("B6");US_SendString("\r\n");}}
			if (i==26){if ((piob_status&(1<<2))!=(1<<2)){US_SendString("B7");US_SendString("\r\n");}}
			if (i==27){if ((piob_status&(1<<3))!=(1<<3)){US_SendString("B8");US_SendString("\r\n");}}
			if (i==28){if ((piob_status&(1<<10))!=(1<<10)){US_SendString("B9");US_SendString("\r\n");}}
			if (i==29){if ((piob_status&(1<<11))!=(1<<11)){US_SendString("B10");US_SendString("\r\n");}}
			if (i==30){if ((piob_status&(1<<13))!=(1<<13)){US_SendString("B11");US_SendString("\r\n");}}
			if (i==31){if ((piob_status&(1<<14))!=(1<<14)){US_SendString("B12");US_SendString("\r\n");}}
			if (i==32){if ((pioc_status&(1<<0))!=(1<<0)){US_SendString("B13");US_SendString("\r\n");}}
			
			if (i==33){if ((pioc_status&(1<<1))!=(1<<1)){US_SendString("B14");US_SendString("\r\n");}}
			if (i==34){if ((pioc_status&(1<<2))!=(1<<2)){US_SendString("B15");US_SendString("\r\n");}}
			if (i==35){if ((pioc_status&(1<<3))!=(1<<3)){US_SendString("B16");US_SendString("\r\n");}}
			if (i==36){if ((pioc_status&(1<<4))!=(1<<4)){US_SendString("B17");US_SendString("\r\n");}}
			if (i==37){if ((pioc_status&(1<<5))!=(1<<5)){US_SendString("B18");US_SendString("\r\n");}}
			if (i==40){if ((pioc_status&(1<<6))!=(1<<6)){US_SendString("C1");US_SendString("\r\n");}}
			if (i==41){if ((pioc_status&(1<<7))!=(1<<7)){US_SendString("C2");US_SendString("\r\n");}}
			if (i==42){if ((pioc_status&(1<<8))!=(1<<8)){US_SendString("C3");US_SendString("\r\n");}}
			if (i==43){if ((pioc_status&(1<<9))!=(1<<9)){US_SendString("C4");US_SendString("\r\n");}}
			if (i==44){if ((pioc_status&(1<<10))!=(1<<10)){US_SendString("C5");US_SendString("\r\n");}}
			
			if (i==45){if ((pioc_status&(1<<11))!=(1<<11)){US_SendString("C6");US_SendString("\r\n");}}
			if (i==46){if ((pioc_status&(1<<12))!=(1<<12)){US_SendString("C7");US_SendString("\r\n");}}
			if (i==47){if ((pioc_status&(1<<13))!=(1<<13)){US_SendString("C8");US_SendString("\r\n");}}
			if (i==48){if ((pioc_status&(1<<14))!=(1<<14)){US_SendString("C9");US_SendString("\r\n");}}
			if (i==49){if ((pioc_status&(1<<15))!=(1<<15)){US_SendString("C10");US_SendString("\r\n");}}
			if (i==50){if ((pioc_status&(1<<16))!=(1<<16)){US_SendString("C11");US_SendString("\r\n");}}
			if (i==51){if ((pioc_status&(1<<17))!=(1<<17)){US_SendString("C12");US_SendString("\r\n");}}
			if (i==52){if ((pioc_status&(1<<18))!=(1<<18)){US_SendString("C13");US_SendString("\r\n");}}
			if (i==53){if ((pioc_status&(1<<19))!=(1<<19)){US_SendString("C14");US_SendString("\r\n");}}
			if (i==54){if ((pioc_status&(1<<20))!=(1<<20)){US_SendString("C15");US_SendString("\r\n");}}
			
			if (i==55){if ((pioc_status&(1<<21))!=(1<<21)){US_SendString("C16");US_SendString("\r\n");}}
			if (i==56){if ((pioc_status&(1<<22))!=(1<<22)){US_SendString("C17");US_SendString("\r\n");}}
			if (i==57){if ((pioc_status&(1<<23))!=(1<<23)){US_SendString("C18");US_SendString("\r\n");}}
			if (i==60){if ((pioc_status&(1<<24))!=(1<<24)){US_SendString("D1");US_SendString("\r\n");}}
			if (i==61){if ((pioc_status&(1<<25))!=(1<<25)){US_SendString("D2");US_SendString("\r\n");}}
			if (i==62){if ((pioc_status&(1<<26))!=(1<<26)){US_SendString("D3");US_SendString("\r\n");}}
			if (i==63){if ((pioc_status&(1<<27))!=(1<<27)){US_SendString("D4");US_SendString("\r\n");}}
			if (i==64){if ((pioc_status&(1<<28))!=(1<<28)){US_SendString("D5");US_SendString("\r\n");}}
			if (i==65){if ((pioc_status&(1<<29))!=(1<<29)){US_SendString("D6");US_SendString("\r\n");}}
			if (i==66){if ((pioc_status&(1<<30))!=(1<<30)){US_SendString("D7");US_SendString("\r\n");}}
			
			if (i==67){if ((pioc_status&(1<<31))!=(1<<31)){US_SendString("D8");US_SendString("\r\n");}}
			if (i==68){if ((piod_status&(1<<0))!=(1<<0)){US_SendString("D9");US_SendString("\r\n");}}
			if (i==69){if ((piod_status&(1<<1))!=(1<<1)){US_SendString("D10");US_SendString("\r\n");}}
			if (i==70){if ((piod_status&(1<<2))!=(1<<2)){US_SendString("D11");US_SendString("\r\n");}}
			if (i==71){if ((piod_status&(1<<3))!=(1<<3)){US_SendString("D12");US_SendString("\r\n");}}
			if (i==72){if ((piod_status&(1<<4))!=(1<<4)){US_SendString("D13");US_SendString("\r\n");}}
			if (i==73){if ((piod_status&(1<<5))!=(1<<5)){US_SendString("D14");US_SendString("\r\n");}}
			if (i==74){if ((piod_status&(1<<6))!=(1<<6)){US_SendString("D15");US_SendString("\r\n");}}
			if (i==75){if ((piod_status&(1<<7))!=(1<<7)){US_SendString("D16");US_SendString("\r\n");}}
			
			if (i==76){if ((piod_status&(1<<8))!=(1<<8)){US_SendString("D17");US_SendString("\r\n");}}
			if (i==77){if ((piod_status&(1<<9))!=(1<<9)){US_SendString("D18");US_SendString("\r\n");}}
		}	
	}
	US_SendString("---------------end-------------\r\n");	
}

void Shift60()
{
	uint32_t i;
	uint32_t pioa_status;
	uint32_t piob_status;
	uint32_t pioc_status;
	uint32_t piod_status;
	
	US_SendString("---------------60Pin Start-------------\r\n");
	a=0;
	for(i=0;i<80;i++)
	{
		init();
		if (i==0||i==11||i==16||i==17||i==18||i==19||i==36||i==37||i==38||i==39||i==56||i==57||i==58||i==59||i==64||i==75||i==76||i==77||i==78||i==79)
		{
			PINLOW(LATPIN);
			Clk();
		}
		else
		{
			PINLOW(LATPIN);
			PINHIGH(DATAPIN);
			Clk2(i);
			PINHIGH(LATPIN);
			
			MyDelay2(100,10000);
			
			pioa_status = PIOA->PIO_PDSR;
			piob_status = PIOB->PIO_PDSR;
			pioc_status = PIOC->PIO_PDSR;
			piod_status = PIOD->PIO_PDSR;
			
			if (i==0){if (!((pioa_status&PIO_PDSR_P4)==PIO_PDSR_P4)){US_SendString("A1");US_SendString("\r\n");}}
			if (i==1){if ((pioa_status&(1<<5))!=(1<<5)){US_SendString("A2");US_SendString("\r\n");}}
			if (i==2){if ((pioa_status&(1<<6))!=(1<<6)){US_SendString("A3");US_SendString("\r\n");}}
			if (i==3){if ((pioa_status&(1<<7))!=(1<<7)){US_SendString("A4");US_SendString("\r\n");}}
			if (i==4){if ((pioa_status&(1<<8))!=(1<<8)){US_SendString("A5");US_SendString("\r\n");}}
			if (i==5){if ((pioa_status&(1<<9))!=(1<<9)){US_SendString("A6");US_SendString("\r\n");}}
			if (i==6){if ((pioa_status&(1<<10))!=(1<<10)){US_SendString("A7");US_SendString("\r\n");}}
			if (i==7){if ((pioa_status&(1<<15))!=(1<<15)){US_SendString("A8");US_SendString("\r\n");}}
			if (i==8){if ((pioa_status&(1<<16))!=(1<<16)){US_SendString("A9");US_SendString("\r\n");}}
			if (i==9){if ((pioa_status&(1<<17))!=(1<<17)){US_SendString("A10");US_SendString("\r\n");}}
			
			if (i==10){if ((pioa_status&(1<<18))!=(1<<18)){US_SendString("A11");US_SendString("\r\n");}}
			if (i==11){if ((pioa_status&(1<<19))!=(1<<19)){US_SendString("A12");US_SendString("\r\n");}}
			if (i==12){if ((pioa_status&(1<<20))!=(1<<20)){US_SendString("A13");US_SendString("\r\n");}}
			if (i==13){if ((pioa_status&(1<<23))!=(1<<23)){US_SendString("A14");US_SendString("\r\n");}}
			if (i==14){if ((pioa_status&(1<<24))!=(1<<24)){US_SendString("A15");US_SendString("\r\n");}}
			if (i==15){if ((pioa_status&(1<<25))!=(1<<25)){US_SendString("A16");US_SendString("\r\n");}}
			if (i==16){if ((pioa_status&(1<<26))!=(1<<26)){US_SendString("A17");US_SendString("\r\n");}}
			if (i==17){if ((pioa_status&(1<<27))!=(1<<27)){US_SendString("A18");US_SendString("\r\n");}}
			if (i==20){if ((pioa_status&(1<<28))!=(1<<28)){US_SendString("B1");US_SendString("\r\n");}}
			if (i==21){if ((pioa_status&(1<<29))!=(1<<29)){US_SendString("B2");US_SendString("\r\n");}}
			if (i==22){if ((pioa_status&(1<<30))!=(1<<30)){US_SendString("B3");US_SendString("\r\n");}}
			
			if (i==23){if ((pioa_status&(1<<31))!=(1<<31)){US_SendString("B4");US_SendString("\r\n");}}
			if (i==24){if ((piob_status&(1<<0))!=(1<<0)){US_SendString("B5");US_SendString("\r\n");}}
			if (i==25){if ((piob_status&(1<<1))!=(1<<1)){US_SendString("B6");US_SendString("\r\n");}}
			if (i==26){if ((piob_status&(1<<2))!=(1<<2)){US_SendString("B7");US_SendString("\r\n");}}
			if (i==27){if ((piob_status&(1<<3))!=(1<<3)){US_SendString("B8");US_SendString("\r\n");}}
			if (i==28){if ((piob_status&(1<<10))!=(1<<10)){US_SendString("B9");US_SendString("\r\n");}}
			if (i==29){if ((piob_status&(1<<11))!=(1<<11)){US_SendString("B10");US_SendString("\r\n");}}
			if (i==30){if ((piob_status&(1<<13))!=(1<<13)){US_SendString("B11");US_SendString("\r\n");}}
			if (i==31){if ((piob_status&(1<<14))!=(1<<14)){US_SendString("B12");US_SendString("\r\n");}}
			if (i==32){if ((pioc_status&(1<<0))!=(1<<0)){US_SendString("B13");US_SendString("\r\n");}}
			
			if (i==33){if ((pioc_status&(1<<1))!=(1<<1)){US_SendString("B14");US_SendString("\r\n");}}
			if (i==34){if ((pioc_status&(1<<2))!=(1<<2)){US_SendString("B15");US_SendString("\r\n");}}
			if (i==35){if ((pioc_status&(1<<3))!=(1<<3)){US_SendString("B16");US_SendString("\r\n");}}
			if (i==36){if ((pioc_status&(1<<4))!=(1<<4)){US_SendString("B17");US_SendString("\r\n");}}
			if (i==37){if ((pioc_status&(1<<5))!=(1<<5)){US_SendString("B18");US_SendString("\r\n");}}
			if (i==40){if ((pioc_status&(1<<6))!=(1<<6)){US_SendString("C1");US_SendString("\r\n");}}
			if (i==41){if ((pioc_status&(1<<7))!=(1<<7)){US_SendString("C2");US_SendString("\r\n");}}
			if (i==42){if ((pioc_status&(1<<8))!=(1<<8)){US_SendString("C3");US_SendString("\r\n");}}
			if (i==43){if ((pioc_status&(1<<9))!=(1<<9)){US_SendString("C4");US_SendString("\r\n");}}
			if (i==44){if ((pioc_status&(1<<10))!=(1<<10)){US_SendString("C5");US_SendString("\r\n");}}
			
			if (i==45){if ((pioc_status&(1<<11))!=(1<<11)){US_SendString("C6");US_SendString("\r\n");}}
			if (i==46){if ((pioc_status&(1<<12))!=(1<<12)){US_SendString("C7");US_SendString("\r\n");}}
			if (i==47){if ((pioc_status&(1<<13))!=(1<<13)){US_SendString("C8");US_SendString("\r\n");}}
			if (i==48){if ((pioc_status&(1<<14))!=(1<<14)){US_SendString("C9");US_SendString("\r\n");}}
			if (i==49){if ((pioc_status&(1<<15))!=(1<<15)){US_SendString("C10");US_SendString("\r\n");}}
			if (i==50){if ((pioc_status&(1<<16))!=(1<<16)){US_SendString("C11");US_SendString("\r\n");}}
			if (i==51){if ((pioc_status&(1<<17))!=(1<<17)){US_SendString("C12");US_SendString("\r\n");}}
			if (i==52){if ((pioc_status&(1<<18))!=(1<<18)){US_SendString("C13");US_SendString("\r\n");}}
			if (i==53){if ((pioc_status&(1<<19))!=(1<<19)){US_SendString("C14");US_SendString("\r\n");}}
			if (i==54){if ((pioc_status&(1<<20))!=(1<<20)){US_SendString("C15");US_SendString("\r\n");}}
			
			if (i==55){if ((pioc_status&(1<<21))!=(1<<21)){US_SendString("C16");US_SendString("\r\n");}}
			if (i==56){if ((pioc_status&(1<<22))!=(1<<22)){US_SendString("C17");US_SendString("\r\n");}}
			if (i==57){if ((pioc_status&(1<<23))!=(1<<23)){US_SendString("C18");US_SendString("\r\n");}}
			if (i==60){if ((pioc_status&(1<<24))!=(1<<24)){US_SendString("D1");US_SendString("\r\n");}}
			if (i==61){if ((pioc_status&(1<<25))!=(1<<25)){US_SendString("D2");US_SendString("\r\n");}}
			if (i==62){if ((pioc_status&(1<<26))!=(1<<26)){US_SendString("D3");US_SendString("\r\n");}}
			if (i==63){if ((pioc_status&(1<<27))!=(1<<27)){US_SendString("D4");US_SendString("\r\n");}}
			if (i==64){if ((pioc_status&(1<<28))!=(1<<28)){US_SendString("D5");US_SendString("\r\n");}}
			if (i==65){if ((pioc_status&(1<<29))!=(1<<29)){US_SendString("D6");US_SendString("\r\n");}}
			if (i==66){if ((pioc_status&(1<<30))!=(1<<30)){US_SendString("D7");US_SendString("\r\n");}}
			
			if (i==67){if ((pioc_status&(1<<31))!=(1<<31)){US_SendString("D8");US_SendString("\r\n");}}
			if (i==68){if ((piod_status&(1<<0))!=(1<<0)){US_SendString("D9");US_SendString("\r\n");}}
			if (i==69){if ((piod_status&(1<<1))!=(1<<1)){US_SendString("D10");US_SendString("\r\n");}}
			if (i==70){if ((piod_status&(1<<2))!=(1<<2)){US_SendString("D11");US_SendString("\r\n");}}
			if (i==71){if ((piod_status&(1<<3))!=(1<<3)){US_SendString("D12");US_SendString("\r\n");}}
			if (i==72){if ((piod_status&(1<<4))!=(1<<4)){US_SendString("D13");US_SendString("\r\n");}}
			if (i==73){if ((piod_status&(1<<5))!=(1<<5)){US_SendString("D14");US_SendString("\r\n");}}
			if (i==74){if ((piod_status&(1<<6))!=(1<<6)){US_SendString("D15");US_SendString("\r\n");}}
			if (i==75){if ((piod_status&(1<<7))!=(1<<7)){US_SendString("D16");US_SendString("\r\n");}}
			
			if (i==76){if ((piod_status&(1<<8))!=(1<<8)){US_SendString("D17");US_SendString("\r\n");}}
			if (i==77){if ((piod_status&(1<<9))!=(1<<9)){US_SendString("D18");US_SendString("\r\n");}}
		}
	}
	US_SendString("---------------end-------------\r\n");
}

void Start()
{
	if (((PIOD->PIO_PDSR&PIO_PDSR_P18)==PIO_PDSR_P18))
	{
		Shift72();
	}
	else
	{
		Shift60();
	}
}
