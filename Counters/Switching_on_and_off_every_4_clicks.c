//A program that receives input from a push-button
//After the fourth press, an LED will light in RD3
//The next fourth click will turn off the LED


sbit LED at RD3_bit;

void interrupt() {
     if(TMR0IF_bit) {
          TMR0L = 252;
          LED =~ LED;
     }
     TMR0IF_bit = 0;
}

void main() {
     PORTA = PORTD = 0;
     ANSELA = ANSELD = 0;
     TRISA = 0xFF;
     TRISD = 0;
     INTCON = 0b11100000;
     T0CON = 0b11101000;
     TMR0L = 252;
     Delay_ms(50);
     while(1);
}
