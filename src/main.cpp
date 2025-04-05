#include <avr/io.h>
#define F_CPU 16000000Ul
#include <util/delay.h>


int main(void){

  DDRD &= ~(0x08);
  DDRD |= 0x40;
  DDRD |= 0x80;
  char a=0;
  PORTD|=0x80;
  PORTD|=0X40;

  while(1){

    if(PIND&0X08){
      _delay_ms(500);
      switch(a){
        case 0: 
        PORTD&=~(0X80);
        a=1;
        break;
        case 1:
        PORTD|=0x80;
        _delay_ms(50);       
        PORTD&=~(0X40);
        a=2;
        break;
        case 2:
        PORTD&=~(0X80);
        a=0;
        break;

 
      }


    }



  }

return 0;

}