//A program that receives data from a potentiometer, converts the data to digital and displays the 8 largest bits in PORTC


void main() {
     PORTA = PORTC = 0;
     TRISA = 0xFF;
     TRISC = 0;
     ANSELC = 0;
     ANSELA = 255;
     ADCON2 = 0b00101111;
     while(1) {
              ADCON0 = 0b00000001;           //Analog Channe-AN0, A/D conversion completed/not in progress, ADC is enabled
              delay_ms(50);
              GO_DONE_bit = 1;
              while(GO_DONE_bit);
              LATC = ADRESH;
              ADON_bit = 0;
     }
}
