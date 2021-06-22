char tmp = 0;

void main() {
     TRISD = 0;
     TRISA = 255;
     ANSELD = 0;
     ANSELA = 1;
     PORTD = 0;
     PORTA = 0;
     WDTCON = 1;

     while(1) {
              asm SLEEP;
              if(RA0_bit >= RA1_bit) {
                         tmp = RA0_bit;
              }
              else {
                   tmp = RA1_bit;
              }
              EEPROM_Write(0, tmp);
              EEPROM_Read(0);
              asm CLRWDT;
     }
}