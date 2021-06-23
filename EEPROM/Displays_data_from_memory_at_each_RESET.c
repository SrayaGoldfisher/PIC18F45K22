//A program that takes the latest data stored in the EEPROM memory and displays it in each RESET on PORTD for 3 seconds


void main() {
     ANSELB = 0xFF;
     ANSELC = ANSELD = 0;
     C1ON_bit = C2ON_bit = 0;
     PORTB = PORTC = PORTD = 0;
     TRISB = 0xFF;
     TRISC = TRISD = 0;
     ADC_Init();
     PORTD = EEPROM_Read(0x00);		//Show the last data from the eeprom 3 sec
     Delay_ms(3000);
     PORTD = 0;

     while(1) {
              PORTC = 0xFF;			//LED indication
              Delay_ms(1000);
              PORTC = 0x00;
              Delay_ms(1000);
              EEPROM_Write(0x00, ADC_Read(12));		//Read analog data from AN12(RB0_bit) to eeprom
              Delay_ms(250);
     }
}
