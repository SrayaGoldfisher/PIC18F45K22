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
     T0CON = 0b10010101;
     TMR0IE_bit = 1;
}