void main() {
     PORTA = PORTB = 0;
     TRISA = 0xFF;
     TRISB = 0;
     ANSELB = 0;
     ANSELA = 255;
     ADCON2 = 0b00101111;
     while(1) {
              ADCON0 = 0b00000101;
              delay_ms(50);
              GO_DONE_bit = 1;
              while(GO_DONE_bit);
              if(ADRESH >= 127) {
                        LATB0_bit = 1;
                        LATB1_bit = 0;
              }
              else {
                   LATB1_bit = 1;
                   LATB0_bit = 0;
              }
              ADON_bit = 0;
     }
}