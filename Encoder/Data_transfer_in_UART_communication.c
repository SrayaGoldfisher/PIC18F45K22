void interrupt() {
     if(TMR0IF_bit) {
                    LATD++;
                    TMR0L = 255;
     }
     TMR0IF_bit = 0;
}

void main() {
     PORTA = PORTB = PORTC = PORTD = 0;
     ANSELA = ANSELB = ANSELC = ANSELD = 0;
     TRISA = TRISB = 0xF7;
     TRISC = TRISD = 0;
     INTCON = 0b11101000;
     T0CON = 0b11101000;
     TMR0L = 255;
     TMR0IF_bit = 0;
     Delay_ms(50);
     UART1_Init(9600);
     Delay_ms(100);
     UART1_Write_Text("start");
     while(1) {
              LATA3_bit = 1;
              UART1_Write(LATD);
              Delay_ms(1000);
     }
}