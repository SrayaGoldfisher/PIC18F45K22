void interrupt() {
     if (INT0IF_bit) {
        if(RB0_bit){
                    LATC++;
        }
     }
     INT0IF_bit = 0;
}

void main() {
     ANSELB = ANSELC = 0;
     TRISC = 0;
     PORTC = 0;
     TRISB = 0xFF;
     PORTB = 0;
     INTCON = 0b11010000;
     INT0IF_bit = 0;
     Delay_ms(100);
     while(1);
}