sbit RED_LED at RD0_bit;
sbit GREEN_LED at RD1_bit;
int two_press = 0;
int K;
int three_press = 0;

void interrupt() {
     if(TMR0IF_bit) {
                    TMR0L = 254;
                    two_press = 1;
     }
     TMR0IF_bit = 0;
     
     if(RB5_bit) {
                 three_press++;
                 K = PORTB;
     }
     RBIF_bit = 0;
}

void main() {
     PORTA = PORTD = PORTB = 0;
     PORTC = 10;
     ANSELA = ANSELD = ANSELC = ANSELB = 0;
     TRISA = TRISB = 0xFF;
     TRISD = TRISC = 0;
     INTCON = 0b11101000;
     IOCB5_bit = 1;
     T0CON = 0b11101000;
     TMR0L = 254;
     Delay_ms(50);
     while(1) {
              while((LATC > 0) && (two_press) && (three_press != 3)) {
                          Delay_ms(1000);
                          LATC--;
              }
              if(!LATC) {
                        RED_LED = 1;
                        Delay_ms(1000);
                        RED_LED = 0;
                        PORTC = 10;
                        two_press = 0;
              }
              if(three_press == 3) {
                             two_press = 0;
                             K = PORTB;
                             GREEN_LED = 1;
                             Delay_ms(1000);
                             GREEN_LED = 0;
                             three_press = 0;
                             PORTC = 10;
              }
     }
}