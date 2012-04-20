/*
 * main.c
 *
 *  Created on: Apr 17, 2012
 *      Author: mikko
 */
#include <avr/io.h>
#include <util/delay.h>

void start_2000us(){
int i;
for(i=0; i<80; i++)
	{
		/* Create 40kHz signal to PD0 
        -This is tuned with scope, difference miht be caused by internal RC-oscilator
        */
        PORTD |=_BV(PD0);
        _delay_us(9);
        PORTD &=~(_BV(PD0));
        _delay_us(10);
	}

}



/*
16*25us --> 400us
**/
void pulse_400us(){
int i;
for(i=0; i<15; i++)
	{
		/* Create 40kHz signal to PD0 
        -This is tuned with scope, difference miht be caused by internal RC-oscilator
        */
        PORTD |=_BV(PD0);
        _delay_us(9);
        PORTD &=~(_BV(PD0));
        _delay_us(10);
	}
}


int main(void){
DDRD = 0xFF;
    
    	start_2000us();
    	_delay_ms(27);
    	_delay_us(415);
    	_delay_us(415);
    	pulse_400us();
    	_delay_ms(1);
    	_delay_us(580);
    	pulse_400us();
    	_delay_ms(3);
    	_delay_us(580);
    	pulse_400us();
    	/* Second round after small break */
    	_delay_ms(63);
    	
    	start_2000us();
    	_delay_ms(27);
    	_delay_us(415);
    	_delay_us(415);
    	pulse_400us();
    	_delay_ms(1);
    	_delay_us(580);
    	pulse_400us();
    	_delay_ms(3);
    	_delay_us(580);
    	pulse_400us();
    
return 0;
}

