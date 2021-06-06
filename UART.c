#include "tm4c123gh6pm.h"

//UART INIT
	// when connecting wires to TIVA we didnot find A0 or A1 so we used D6 and D7(UART2)
void UART2Init(void)
	{
	SYSCTL_RCGCUART_R |= SYSCTL_RCGCUART_R2 ;// provide clock to UART2 
	SYSCTL_RCGCGPIO_R |= 0x08; // Enable clock for PORT D
	UART2_CTL_R &=~UART_CTL_UARTEN; // disable UART2 
	UART2_IBRD_R =104; // 16MHz/16=1MHz, 1MHz/104=9600 baud rate 
	UART2_FBRD_R =11; // fraction part
	UART2_CC_R = UART_CC_CS_SYSCLK; // use system clock (default)
	UART2_LCRH_R =(UART_LCRH_FEN | UART_LCRH_WLEN_8 ); // UART Enable FIFOs and  8 bits
	UART2_CTL_R |=(UART_CTL_UARTEN | UART_CTL_RXE| UART_CTL_TXE);// UART Enable , UART Transmit Enable , UART Receive Enable
	GPIO_PORTD_AFSEL_R |= 0xC0; // Enable serial 
	GPIO_PORTD_PCTL_R =( GPIO_PORTA_PCTL_R &~ 0xFF)| 0x11000000; //  Enable to U0RX on PA0,U0TX on D6 D7
  GPIO_PORTD_DEN_R |= 0xC0;		
}
