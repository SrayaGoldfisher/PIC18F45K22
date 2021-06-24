void main() {
     PORTA = 0;
     TRISA = 0b11001111;
     ANSELA = 0b10010000;
     CM1CON0 = 0b11101000;
     while(1) {
              RA5_bit =~ RA4_bit;
     }
}