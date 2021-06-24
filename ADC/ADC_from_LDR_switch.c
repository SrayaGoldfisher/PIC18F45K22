//A program that activates a switch in RC0 performs an analog reading from a potentiometer in AN1
//The data is converted to digital and displayed in PORTB (without LSB)
//When a switch is activated in RC1, an analog reading is performed from an LDR sensor in AN2
//The data is converted to digital and displayed in PORTD


void main() {
     PORTA = PORTB = PORTC = PORTD = 0;
     TRISA = TRISC = 0xFF;
     TRISB = TRISD = 0;
     ANSELD = ANSELB = ANSELC = 0;
     ANSELA = 255;
     ADCON2 = 0b00101111;
     UART1_Init(9600);
     UART1_Write(RA1_bit);
     while(1) {
              while(RC0_bit) {
                             ADCON0 = 0b00000101;
                             delay_ms(50);
                             GO_DONE_bit = 1;
                             while(GO_DONE_bit);
                             LATB = ADRESH;
                             ADON_bit = 0;
              }
              while(RC1_bit) {
                             ADCON0 = 0b00001001;
                             delay_ms(50);
                             GO_DONE_bit = 1;
                             while(GO_DONE_bit);
                             LATD = ADRESH;
                             ADON_bit = 0;
              }
     }
}
