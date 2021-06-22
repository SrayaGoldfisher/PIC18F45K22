void main() {
     ANSELB = 0xFF;
     ANSELC = ANSELD = 0;
     C1ON_bit = C2ON_bit = 0;
     PORTB = PORTC = PORTD = 0;
     TRISB = 0xFF;
     TRISC = TRISD = 0;
     ADC_Init();

     while(1) {
              PORTC = 0xFF;							//LED indication
              Delay_ms(1000);
              PORTC = 0x00;
              Delay_ms(1000);
              EEPROM_Write(0x00, ADC_Read(12));		//Read analog data from AN12(RB0_bit) to eeprom
              Delay_ms(250);
              PORTD = EEPROM_Read(0x00);			//Show the data from the eeprom
     }
}