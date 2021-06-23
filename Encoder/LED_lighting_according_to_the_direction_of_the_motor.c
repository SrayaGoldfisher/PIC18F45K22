//A program that turns on a green LED when the engine is rotating in one direction 
//and a red LED when the engine is rotating in the opposite direction


sbit RED_LED at RD0_bit;
sbit GREEN_LED at RD1_bit;

void interrupt() {
     if(TMR0IF_bit) {
                    LATC++;
                    TMR0L = 255;
                    if(RB0_bit) {
                                RED_LED = 1;
                                GREEN_LED = 0;
                    }
                    else {
                         GREEN_LED = 1;
                         RED_LED = 0;
                    }
     }
     TMR0IF_bit = 0;
}

void main() {
     PORTA = PORTB = PORTC = PORTD = 0;
     ANSELA = ANSELB = ANSELC = ANSELD = 0;
     TRISA = TRISB = 0xFF;
     TRISC = TRISD = 0;
     INTCON = 0b11101000;     //Enables Timer0, 8-bit, Transition on RA4/T0CKI pin
     T0CON = 0b11101000;      //Increment on low-to-high, TImer0 prescaler is NOT assigned
     TMR0L = 255;
     TMR0IF_bit = 0;
     Delay_ms(50);
     while(1);
}
