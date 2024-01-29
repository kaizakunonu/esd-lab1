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

void main(void) {
    
    TRISA3 = 0; // port A pin 3 is an output
    TRISB0 = 0; // port B pin 0 is an output    
    TRISC1 = 0; // port C pin 1 is an output
    TRISD2 = 0; // port D pin 2 is an output
    TRISE0 = 0; // port E pin 0 is an output
    
    while(1){
        
        RA3 = 1; // Put power in port A pin 3
        RB0 = 1; // Put power in port B pin 0
        RC1 = 1; // Put power in port C pin 1
        RD2 = 1; // Put power in port D pin 2
        RE0 = 1; // Put power in port E pin 0
        
        __delay_ms(1000); // Retain the powered status of pins for 1s
        
        RA3 = 0; // Deny power to port A pin 3
        RB0 = 0; // Deny power in port B pin 0
        RC1 = 0; // Deny power in port C pin 1
        RD2 = 0; // Deny power in port D pin 2
        RE0 = 0; // Deny power in port E pin 0
        
        __delay_ms(1000); // Retain the power off status of pins for 1s
    }
    return;
}
