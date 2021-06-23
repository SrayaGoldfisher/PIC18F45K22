//A program that detects axis rotations by an encoder and transmits the data to the PORTC via a Counter interrupt


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
     INTCON = 0b11101000;     //Enables Timer0, 8-bit, Transition on RA4/T0CKI pin
     T0CON = 0b11101000;      //Increment on low-to-high, TImer0 prescaler is NOT assigned
     TMR0L = 255;
     TMR0IF_bit = 0;
     Delay_ms(50);
     while(1);
}
