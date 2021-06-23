//Using the COUNTER module I wrote a program that receives input from a push-button
//When the system detects 2 clicks it performs a countdown on the PORTC from 10 to 0
//When the count is complete the system will turn on LED at RD0


sbit RED_LED at RD0_bit;
int two_press = 0;

void interrupt() {
     if(TMR0IF_bit) {
          TMR0L = 254;
          two_press = 1;
     }
     TMR0IF_bit = 0;
}

void main() {
     PORTA = PORTD = 0;
     PORTC = 10;
     ANSELA = ANSELD = ANSELC = 0;
     TRISA = 0xFF;
     TRISD = TRISC = 0;
     INTCON = 0b11101000;
     T0CON = 0b11101000;
     TMR0L = 254;
     Delay_ms(50);
     while(1) {
          while((LATC > 0) && (two_press)) {
               Delay_ms(1000);
               LATC--;
          }
          if(!LATC) {
               RED_LED = 1;
               Delay_ms(1000);
               RED_LED = 0;
               PORTC = 10;
               two_press = 0;
          }
     }
}
