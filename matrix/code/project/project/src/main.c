/*

Digital2 project 
Professor Jahani
Author Sarina Ziraksima

NOTE: Please set ATMEGA32's frequency to int.RC 8MHZ for avoiding blinks thus having a smooth 8*8 matrix screen in your running Proteus file.
 
 */

//modes contain 00 for data collection. 01 for row and coulum checking. 10 for checking conection from row0 to row8
#include <asf.h>
#include <avr/io.h>
#include <util/delay.h>

int checkerbox[8][8]={0};
int inputarray[100]={0};
int box[8]={0};
int variabl=0;
int variabl2=0;
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
	PORTD=0b00000010;//setting out put

	while (1)
	{	
		mode = 0b00000011&PINB;
				
		while(mode==0){
			datasetter();
			data();
			printer();
			mode = 0b00000011&PINB;	
			
					
		}
		while (mode==1)
		{
			checker();
			printer();
			
			
			mode = 0b00000011&PINB;
		}
		while (mode==2)
		{
			
			actiontaker();
			mode = 0b00000011&PINB;
			
		}
	

	}
	
	
}









void datasetter(void){		
		while(((0b00001000&PINA)==0b00001000) & ((0b10000000&PINA)==0b10000000))
		{
			
			inputarray[counter] = PINA;
			x[(0b01110000&PINA)>>4][0b00000111-(0b00000111&PINA)] = 1;
			
			_delay_ms(50);
			if(inputarray[counter] != PINA)
			{
				counter++;
			}
		}	
}





void checker(void){
	while((0b00001000&PINA)==0b00001000)
	{	
			variabl=0b0000111-(0b00000111&PINA);
			printer();
			_delay_ms(50);
			if (x[0][variabl]*x[1][variabl]*x[2][variabl]*x[3][variabl]*x[4][variabl]*x[5][variabl]*x[6][variabl]*x[7][variabl]==1)
			{
				x[0][variabl]=0;
				x[1][variabl]=0;
				x[2][variabl]=0;
				x[3][variabl]=0;
				x[4][variabl]=0;
				x[5][variabl]=0;
				x[6][variabl]=0;
				x[7][variabl]=0;
				data();
				printer();
				_delay_ms(50);
				x[0][variabl]=1;
				x[1][variabl]=1;
				x[2][variabl]=1;
				x[3][variabl]=1;
				x[4][variabl]=1;
				x[5][variabl]=1;
				x[6][variabl]=1;
				x[7][variabl]=1;
				data();
				printer();
				
				
			}
	
	}
	
	while((0b10000000&PINA)==0b10000000){
		variabl=(0b01110000&PINA)>>4;
		printer();
		_delay_ms(50);
		if (box[variabl]==0xff)
		{
			PORTD =0xff;
			box[variabl]=0;
			printer();
			_delay_ms(50);
			box[variabl]=0xff;
			
		}
		
	}
	
}





void actiontaker(void){
	
	checkerbox[0][0]=1;
	checkerbox[0][1]=1;
	checkerbox[0][2]=1;
	checkerbox[0][3]=1;
	checkerbox[0][4]=1;
	checkerbox[0][5]=1;
	checkerbox[0][6]=1;
	checkerbox[0][7]=1;
	for (int i=0;i<7;i++)
	{
		
		if ((x[i][0]==1)&(checkerbox[i][0]==1))
		{
			checkerbox[i+1][0]=1;
			checkerbox[i+1][1]=1;
			
		}
		if ((x[i][1]==1)&(checkerbox[i][1]==1))
		{
			checkerbox[i+1][0]=1;
			checkerbox[i+1][1]=1;
			checkerbox[i+1][2]=1;	
			
		}
		if ((x[i][2]==1)&(checkerbox[i][2]==1))
		{
			checkerbox[i+1][1]=1;
			checkerbox[i+1][2]=1;
			checkerbox[i+1][3]=1;
		}
		if ((x[i][3]==1)&(checkerbox[i][3]==1))
		{
			checkerbox[i+1][2]=1;
			checkerbox[i+1][3]=1;
			checkerbox[i+1][4]=1;
		}
		if ((x[i][4]==1)&(checkerbox[i][4]==1))
		{
			checkerbox[i+1][3]=1;
			checkerbox[i+1][4]=1;
			checkerbox[i+1][5]=1;
		}
		if ((x[i][5]==1)&(checkerbox[i][5]==1))
		{
			checkerbox[i+1][4]=1;
			checkerbox[i+1][5]=1;
			checkerbox[i+1][6]=1;
		}
		if ((x[i][6]==1)&(checkerbox[i][6]==1))
		{
			checkerbox[i+1][5]=1;
			checkerbox[i+1][6]=1;
			checkerbox[i+1][7]=1;
		}
		if ((x[i][7]==1)&(checkerbox[i][7]==1))
		{
			checkerbox[i+1][6]=1;
			checkerbox[i+1][7]=1;
			
		}
		
	}
	variabl=7;
	if ((((checkerbox[variabl][0]&x[variabl][0])||(checkerbox[variabl][1]&x[variabl][1]))||((checkerbox[variabl][2]&x[variabl][2])||(checkerbox[variabl][3]&x[variabl][3])))||(((checkerbox[variabl][4]&x[variabl][4])||(checkerbox[variabl][5]&x[variabl][5]))||((checkerbox[variabl][6]&x[variabl][6])||(checkerbox[variabl][7]&x[variabl][7])))){
		PORTD=0b10000000;
		_delay_ms(10000);
	}
	printer();
	
	
	
}


void printer(void){
	
	
	for (int i=0;i<8;i++)
	{
		PORTD =i;
		PORTC = box[i];
		
		
		_delay_ms(50);
		
	}
	
}
	
void nothing(void){
	
}

void data(void){
	
	variabl2=0b00000001;
	for (int i=0;i<8;i++)
	{
		box[i]=x[i][0]+2*x[i][1]+4*x[i][2]+8*x[i][3]+16*x[i][4]+32*x[i][5]+64*x[i][6]+128*x[i][7];
		
	}
	
}









