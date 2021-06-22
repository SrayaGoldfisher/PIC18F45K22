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
     INTCON = 0b11101000;
     T0CON = 0b11101000;
     TMR0L = 255;
     TMR0IF_bit = 0;
     Delay_ms(50);
     while(1);
}