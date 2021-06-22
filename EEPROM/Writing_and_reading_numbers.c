char i = 0, Write = 0, Read = 0, flag = 0;

void interrupt() {
     if(RB4_bit) {					//Push-button to write data to eeprom
                 Write = 1;
                 flag = 1;
     }
     if(RB5_bit) {					//Push-button to read data from eeprom
                 Read = 1;
     }
     RBIF_bit = 0;
}

void main() {
     ANSELB = ANSELC = ANSELD = 0;
     C1ON_bit = C2ON_bit = 0;
     PORTB = PORTC = PORTD = 0;
     TRISB = 0xFF;
     TRISC = TRISD = 0;
     INTCON = 0b11001000;			//Enable Global Interrupt, Peripheral Interrupt and Port B Interrupt-On-Change
     IOCB4_bit = IOCB5_bit = 1;		//Enable Interrupt-On-Change at RB4_bit and RB5_bit
     
     while(1) {
              if(Write) {
                        while(i <= 10) {					//Write 10 numbers to eeprom
                              EEPROM_Write(0x00+i, i);
                              i++;
                        }
                        i = 0;
                        Delay_ms(1000);
              }
              if(Read && flag) {							//Show the numbers from the eeprom
                      PORTC = 0xFF;							//LED indication
                      Delay_ms(1000);
                      PORTC = 0x00;
                      Delay_ms(1000);
                      for(i = 0; i <= 10; i++) {
                            PORTD = EEPROM_Read(0x00+i);
                            Delay_ms(1000);
                      }
              }
     }
}