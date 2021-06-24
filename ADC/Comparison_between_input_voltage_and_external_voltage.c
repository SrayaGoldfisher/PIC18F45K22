//A program that compares using the comparator module in the controller
//between input voltage from a potentiometer and a constant external voltage of 2.5V supplied to the controller
//If the input voltage from the potentiometer is greater - a green LED will turn on in RA4
//If the voltage obtained from the constant voltage source is greater - a red LED will turn on in RA5


void main() {
     PORTA = 0;
     TRISA = 0b11001111;
     ANSELA = 0b10010000;
     CM1CON0 = 0b11101000;         //Comparator C1 is enabled, (C1OUT = 1 when CxVIN+ > CxVIN-) & (C1OUT = 0 when CxVIN+ < CxVIN-), 
                                   //C1OUT is present on the C1OUT pin, C1OUT logic is not inverted, C1 operates in Normal-Power Higher Speed mode, 
                                   //C1VIN+ connects to C12IN+ pin, C12IN0- pin of C1 connects to C1VIN-
     while(1) {
              RA5_bit =~ RA4_bit;
     }
}
