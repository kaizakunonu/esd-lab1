/*
 * File:   kidoncho1main.c
 * Author: kaizakunonu
 *
 * Created on 28 January 2024, 07:53
 */

// CONFIG
#pragma config FOSC = HS        // Oscillator Selection bits (HS oscillator)
#pragma config WDTE = ON      // Watchdog Timer Enable bit (WDT disabled)
#pragma config PWRTE = OFF      // Power-up Timer Enable bit (PWRT disabled)
#pragma config BOREN = ON       // Brown-out Reset Enable bit (BOR enabled)
#pragma config LVP = OFF        // Low-Voltage (Single-Supply) In-Circuit Serial Programming Enable bit (RB3 is digital I/O, HV on MCLR must be used for programming)
#pragma config CPD = OFF        // Data EEPROM Memory Code Protection bit (Data EEPROM code protection off)
#pragma config WRT = OFF        // Flash Program Memory Write Enable bits (Write protection off; all program memory may be written to by EECON control)
#pragma config CP = OFF         // Flash Program Memory Code Protection bit (Code protection off)


#include <xc.h>

#define _XTAL_FREQ 16000000 // Set the oscillator frequency to 16 MGz
#define Input RD0 

void main(void) {
    
   TRISA3 = 0; // Port A pin 3 is an output.
   TRISB0 = 0; // Port B pin 0 is an output. 
   TRISD0 = 1; // Port D pin 0 is an input.
   TRISC1 = 0; // Port C pin 1 is an output.
   TRISD2 = 0; // Port D pin 2 is an output.
   TRISE0 = 0; // Port E pin 0 is an output.

   RA3 = 0; // Initialise pin RA3 in off state.
   RB0 = 0; // Initialise pin RB0 in off state.
   RC1 = 0; // Initialise pin RC1 in off state.
   RD2 = 0; // Initialise pin RD2 in off state. 
   RE0 = 0; // Initialise pin RE0 in off state.
    
    while(1){
        
        if(RD0){  // Check input signal
            
            RA3 = 1; // Set pin RA3 in on state. 
            RB0 = 1; // Set pin RB0 in on state. 
            RC1 = 1; // Set pin RC1 in on state. 
            RD2 = 1;  // Set pin RD2 in on state.
            RE0 = 1;  // Set pin RE0 in on state.
        }
        
        else
            
        {   RA3 = 0; // Set pin RA3 in off state.
            RB0 = 0; // Set pin RB0 in off state.
            RC1 = 0; // Set pin RC1 in off state.
            RD2 = 0; // Set pin RD2 in off state.
            RE0 = 0; // Set pin RE0 in off state.
        }
    }
    return;
}
