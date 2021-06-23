//A program that transmits the data to the terminal via serial communication - UART


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
     INTCON = 0b11101000;     //Enables Timer0, 8-bit, Transition on RA4/T0CKI pin
     T0CON = 0b11101000;      //Increment on low-to-high, TImer0 prescaler is NOT assigned     
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
