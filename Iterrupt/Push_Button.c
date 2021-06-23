void interrupt() {
     if (RBIF_bit) {
        if(RB5_bit){
                    RC2_bit =~ RC2_bit;
        }
     }
     RBIF_bit = 0;
}

void main() {
     ANSELB  =  ANSELC =  0;
     TRISC = 0;
     PORTC = 0;
     TRISB = 0xFF;
     PORTB = 0;
     INTCON = 0b11001000;
     GIE_bit = 1;
     RBIE_bit = 1;
     IOCB5_bit = 1;
     Delay_ms(100);
     while(1);
}
