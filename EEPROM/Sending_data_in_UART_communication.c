//A program that sends data to a microcontroller via serial communication
//The data will be stored in the EEPROM memory
//The data will be stored each time in a different memory cell


char i = 0;

void main() {
     ANSELB = ANSELC = ANSELD = 0;
     C1ON_bit = C2ON_bit = 0;
     PORTB = PORTC = PORTD = 0;
     TRISB = 0xFF;
     TRISC = TRISD = 0;
     UART1_Init(9600);		// Initialize hardware UART1 and establish communication at 9600 bps

     PORTC = 0xFF;			//LED indication
     Delay_ms(1000);
     PORTC = 0x00;
     Delay_ms(1000);
     while(1) {
              while(i < 6) {									//write and show data to 0-7 first address in the eeprom
                      EEPROM_Write(0x00+i, UART1_Read());		//Write numbers to eeprom from the UART
                      Delay_ms(250);
                      PORTD = EEPROM_Read(0x00+i);				//Show the data from the eeprom
                      Delay_ms(1000);
                      PORTC = 0xFF;								//LED indication
                      Delay_ms(100);
                      PORTC = 0x00;
                      Delay_ms(100);
                      i++;
              }
              i = 0;
     }
}
