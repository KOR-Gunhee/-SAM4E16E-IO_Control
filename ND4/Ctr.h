/*
 * Ctr.h
 *
 * Created: 2019-02-07 오후 4:57:43
 *  Author: ghhan
 */ 


#ifndef CTR_H_
#define CTR_H_

#define CLKPIN 0
#define DATAPIN 11
#define LATPIN 1
#define OEPIN 2
#define RSTPIN 3

#define PINHIGH(pin) PIOA->PIO_SODR=(1<<pin)
#define PINLOW(pin) PIOA->PIO_CODR=(1<<pin)

#define DATA_BUFF 80

typedef struct{
	uint32_t  Head;
	uint32_t  Tail;
	uint8_t   Buff[DATA_BUFF];
}DATA_BUFF_FIFO;

extern char data[32];

void init();
void Clk();
void Clk2(int cnt);
void Latch();
void jump();
void Shift72();
void Shift60();
void Start();
void MyDelay(volatile uint32_t delay);
void MyDelay2(volatile uint32_t delay1,volatile uint32_t delay2);

#endif /* CTR_H_ */