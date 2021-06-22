char tmp = 0, i = 0, j = 0;

void interrupt() {
     if(RBIF_bit) {
                  if(RB5_bit) {			//Push-button to read data from eeprom
                              j++;
                  }
                  RBIF_bit = 0;
     }
}

void main() {
     ANSELB = ANSELC = ANSELD = 0;
     C1ON_bit = C2ON_bit = 0;
     PORTB = PORTC = PORTD = 0;
     TRISB = 0xFF;
     TRISC = TRISD = 0;
     UART1_Init(9600);					//Initialize hardware UART1 and establish communication at 9600 bps
     INTCON = 0b11001000;				//Enable Global Interrupt, Peripheral Interrupt and Port B Interrupt-On-Change
     IOCB5_bit = 1;						//Enable Interrupt-On-Change at RB5_bit

     while(1) {
              while(i < 6) {						//Write and show data to 0-7 first address in the eeprom
                      Delay_ms(1000);
                      tmp = UART1_Read();			//Save the data to variable tmp
                      EEPROM_Write(0x00+i, tmp);	//Write the data to the eeprom
                      UART1_Write(i);				//Show which adress the data write
                      i++;
                      Delay_ms(250);
              }
              i = 0;
              if(j > 0) {							//Enter if was click on the push-button by the interrupt RBIF
                   LATD = EEPROM_Read(0x00+j);		//Show the data from the eeprom
                   j = 0;
                   Delay_ms(1000);
              }
     }
}