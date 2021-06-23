void main() {
     int i;
     PORTB = 0;
     TRISB = 0;
     TRISC.F6 = 0;
     TRISC.F7 = 1;
     ANSELB = ANSELC = 0;
     SPBRG = 51;
     TXSTA = 0b00100010;
     RCSTA = 0b10010000;
     TXREG = 0;
     do {
        TXREG++;
        while (!TRMT_bit);
        while (!RCIF_bit);
        LATB = RCREG;
        if(RCREG == 255) {
                 TXREG = 0;
        }
        for (i = 0;  i < 30000;  i++);
     }
     while(1);
}