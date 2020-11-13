#ifndef ISR_H_
#define ISR_H_

#define ISR_SZ_US1_BUFF 32

extern uint8_t status;


extern uint8_t a;



typedef struct{
	uint32_t  Head;
	uint32_t  Tail;
	uint8_t   Buff[ISR_SZ_US1_BUFF];
}ISR_ST_USART_FIFO;



extern ISR_ST_USART_FIFO volatile ISR_Usart1_Buff;


#endif /* ISR_H_ */