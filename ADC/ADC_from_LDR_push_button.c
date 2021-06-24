int flag1, flag2;
void main() {
     PORTA = PORTB = PORTC = PORTD = 0;
     TRISA = TRISC = 0xFF;
     TRISB = TRISD = 0;
     ANSELD = ANSELB = ANSELC = 0;
     ANSELA = 255;
     ADCON2 = 0b00000111;
     flag1 = flag2 = 0;
     UART1_Init(9600);
     UART1_Write(RA1_bit);
     while(1) {
              if(!flag1 && RC0_bit) {
                        flag1 = 1;
              }
              if(flag1 && !RC0_bit) {
                       ADCON0 = 0b00000101;
                       delay_ms(50);
                       GO_DONE_bit = 1;
                       while(GO_DONE_bit);
                       LATB = ADRESH;
                       ADON_bit = 0;
                       flag1 = flag2 = 0;
              }
              if(!flag2 && RC1_bit) {
                        flag2 = 1;
              }
              if(flag2 && !RC1_bit) {
                       ADCON0 = 0b00001001;
                       delay_ms(50);
                       GO_DONE_bit = 1;
                       while(GO_DONE_bit);
                       PORTD = ADRESH;
                       ADON_bit = 0;
                       flag1 = flag2 = 0;
              }
     }
}