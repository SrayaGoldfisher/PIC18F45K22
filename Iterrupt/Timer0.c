//Program that causes RC2 to flash half a second on "1" and half a second on "0"
//The program is executed using the interrupt of timer 0
//[1/32M(osc.)]*4(internal instruction)*64(prescaler)*(2^16)(TMR0) = 0.524[sec]

void interrupt() {
     if (TMR0IF_bit) {
        RC2_bit =~ RC2_bit;
     }
     TMR0IF_bit = 0;
}

void main() {
     ANSELC  = 0;
     TRISC = 0;
     PORTC = 0;
     INTCON = 0b11100000;
     TMR0IP_bit = 1;
     T0CON = 0b10010101;      //Enables Timer0, 16-bit, CLKOUT, T0CKI on high-o-low, Prescaler is assigned, 1:64 prescale value
     TMR0IE_bit = 1;
}
