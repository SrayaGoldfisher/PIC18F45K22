void interrupt() {
     if(TMR0IF_bit) {
                    LATC++;
                    TMR0L = 255;
     }
     TMR0IF_bit = 0;
}

void main() {
     PORTA = PORTC = 0;
     ANSELA = ANSELC = 0;
     TRISA = 0xFF;
     TRISC = 0;
     INTCON = 0b11101000;
     T0CON = 0b11101000;
     TMR0L = 255;
     TMR0IF_bit = 0;
     Delay_ms(50);
     while(1);
}