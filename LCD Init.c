#include "TM4C123.h" // Device header
void LCD_init(void);
void LCD_Cmd(unsigned char command);
int main(){
LCD_init();
/*while(1)
{

}*/
}
void LCD_init()
{
	SYSCTL_RCGCGPIO_R |= 0x01; // Enable clock for ports
	while ((SYSCTL_PRGPIO_R & 0x00000002)==0){};  //wait til ports are activated
	GPIO_PORTA_DIR_R |=0xE0; //PORTA controls RS,E and R/W
	GPIO_PORTA_DEN_R |=0xE0;
	//portB
	GPIO_PORTB_DIR_R |=0xFF; //PORTB D0-D7
	GPIO_PORTB_DEN_R |=0xFF; //PORTB D0-D7
	//LCD
	LCD_Cmd(0x38); //8-bits,2 display lines, 5x7 font
	LCD_Cmd(0x06); //increments automatically
	LCD_Cmd(0x0F); //Turn on display
	LCD_Cmd(0x01); //clear display
}
 
void LCD_Cmd(unsigned char command)
{
	GPIO_PORTA_DATA_R = 0x00; //RS=0, E=0, RW=0
	GPIO_PORTA_DATA_R =command;
	GPIO_PORTA_DATA_R =0x80; //E=1 to secure command
	delay_micro(0);
	GPIO_PORTA_DATA_R =0x00;
	if(command <4) 
	{
		//delay_milli(2);
	}	
	else
	{	
		//delay_micro(37); 
	}
} 
