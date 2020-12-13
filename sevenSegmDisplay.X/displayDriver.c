
// PIC16F877A Configuration Bit Settings

// 'C' source line config statements

// CONFIG
#pragma config FOSC = XT        // Oscillator Selection bits (XT oscillator)
#pragma config WDTE = OFF       // Watchdog Timer Enable bit (WDT disabled)
#pragma config PWRTE = OFF      // Power-up Timer Enable bit (PWRT disabled)
#pragma config BOREN = ON       // Brown-out Reset Enable bit (BOR enabled)
#pragma config LVP = ON         // Low-Voltage (Single-Supply) In-Circuit Serial Programming Enable bit (RB3/PGM pin has PGM function; low-voltage programming enabled)
#pragma config CPD = OFF        // Data EEPROM Memory Code Protection bit (Data EEPROM code protection off)
#pragma config WRT = OFF        // Flash Program Memory Write Enable bits (Write protection off; all program memory may be written to by EECON control)
#pragma config CP = OFF         // Flash Program Memory Code Protection bit (Code protection off)

// #pragma config statements should precede project file includes.
// Use project enums instead of #define for ON and OFF.
#define _XTAL_FREQ 4000000

#include <xc.h>
#include <pic16f877a.h>
#include "displayDriver.h"
#include <math.h>
#include <stdio.h>

char countTillNine[10] = {0xC0, 0xF9, 0xA4, 0xB0, 0x99, 0x92, 0x82, 0xF8, 0x80, 0x90};

// 0b0111 0101 = 0x75  A = 10 B = 11 ... F

void countToNine(char port){
    char count = 0;
    while(1){
        if (count > 9) count = 0;
        switch(port){
            case 'A':
                PORTA = countTillNine[count];
                break;
            case 'B':
                PORTB = countTillNine[count];
                break;
            case 'C':
                PORTC = countTillNine[count];
                break;
            case 'D':
                PORTD = countTillNine[count];
                break;
        }
        __delay_ms(500);
        count ++;
    }
}
void allOfThemOut(char port){
    switch(port){
        case 'A':
            TRISA = 0x00;
            PORTA = 0x00;
        break;
        case 'B':
            TRISB = 0x00;
            PORTB = 0x00;
            break;
        case 'C':
            TRISC = 0x00;
            PORTC = 0x00;
            break;
        case 'D':
            TRISD = 0x00;
            PORTD = 0x00;
            break;
    }
}

void setInput(int numberOfElement, int *inputPins, char port){
    
    unsigned int total = 0;
    for (int i = 0 ; i < numberOfElement ; i++){
        total += pow(2, inputPins[i]);// 5 ve 0
    }
    
    switch(port){
        case 'A':
            TRISA = 0x00 || total;   // 0b0001 0001  ==  2^5+2^0 = 33 => TRUE
            break;
        case 'B':
            TRISB = 0x00 || total;   
            break;
        case 'C':
            TRISC = 0x00 || total;
            break;
        case 'D':
            TRISD = 0x00 || total;
            break;
    }
    
}


