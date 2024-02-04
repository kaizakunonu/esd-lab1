/*
 * File:   Lab1_io2.c
 * Author: kaizakunonu
 *
 * Created on 28 January 2024, 07:53
 */

#include <xc.h>

// Configuration settings
#pragma config FOSC = HS        // HS oscillator
#pragma config WDTE = OFF       // Watchdog Timer disabled
#pragma config PWRTE = ON       // Power-up Timer enabled
#pragma config BOREN = ON       // Brown-out Reset enabled
#pragma config LVP = OFF        // Low-Voltage Programming disabled

// Define constants for pins
#define ALED_PIN RA3 // Pin connected to the LED
#define BLED_PIN RB0 // Pin connected to the LED
#define CLED_PIN RC1 // Pin connected to the LED
#define BUTTON_PIN  RD0 // Pin connected to the push button
#define DLED_PIN RD2 // Pin connected to the LED
#define ELED_PIN RE0 // Pin connected to the LED

// Variable to store LED state
unsigned char led_state = 0;    // 0 for OFF, 1 for ON

// Function prototypes
void setup();

// Main function
void main() {
    
    setup();

    while(1) {
        
        if (BUTTON_PIN == 0) { // Check if the push button is pressed.
            
            led_state = !led_state; // Toggle the LED state.
            
            ALED_PIN = led_state; // Update the LED based on the new state.
            BLED_PIN = led_state; // Update the LED based on the new state. 
            CLED_PIN = led_state; // Update the LED based on the new state.
            DLED_PIN = led_state; // Update the LED based on the new state.
            ELED_PIN = led_state; // Update the LED based on the new state.
            
            while (BUTTON_PIN == 0);  // Wait for button release to avoid multiple toggles.
        }
    }
}

// Initialise function implementation
void setup() {
    
    TRISA3 = 0; // Set RA3 pin as output
    TRISB0 = 0; // Set RB0 pin as output
    TRISC1 = 0; // Set RC1 pin as output
    TRISD0 = 1; // Set RD0 pin as input
    TRISD2 = 0; // Set RD2 pin as output
    TRISE0 = 0; // Set RE0 pin as output
    
    PORTA = 0x00; // Initialise PORTA
    PORTB = 0x00; // Initialise PORTB
    PORTC = 0x00; // Initialise PORTC
    PORTD = 0x00; // Initialise PORTD
    PORTE = 0x00; // Initialise PORTE 
    
}
