/*

digital2 project 
professor Jahani
author Sarina Ziraksima


 
 */

//modes contain 00 for data collection. 01 for row and coulum checking. 10 for checking conection from row0 to row8
#include <asf.h>
#include <avr/io.h>
#include <util/delay.h>
int a[7]={0};
int inputarray[100]={0};
int y[64]={0};
int variabl=0;
int variabl2=0;
int box[8]={0};



int x[8][8]={0};
int mode;
int counter=0;
int flag=1;

void data(void);
void datasetter(void);
void checker(void);
void actiontaker(void);
void nothing(void);
void printer(void);


int main (void)
{
	PORTA = 0xFF;
	DDRA = 0;
	PORTB = 0xFF;
	DDRB = 0;
	DDRC = 0xFF;
	PORTC = 0;
	DDRD = 0xFF;
	PORTD = 0;
	
	x[0][0]=1;
	x[7][7]=1;
	x[5][5]=1;
	while(1){
		data();
		printer();
	}
	
}














void printer(void){
	
	
		
		for (int i=0;i<8;i++)
		{
			PORTD =i;
			PORTC = box[i];
			
			
			_delay_ms(50);
			
		}
		
		_delay_ms(50);
	
}
	
	

void data(void){
	
	variabl2=0b00000001;
	for (int i=0;i<8;i++)
	{
		box[i]=x[i][0]+2*x[i][1]+4*x[i][2]+8*x[i][3]+16*x[i][4]+32*x[i][5]+64*x[i][6]+128*x[i][7];
		
	}
	
	
}









