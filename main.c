/* 
 * File:   main.c
 * Author: Bruno
 *
 * Created on 10 février 2015, 21:00
 */

#include <xc.h>

#include "ascii.h"
#include "conf.h"

#define KBD_TRIS_DATA   TRISA4
#define KBD_TRIS_CLOCK   TRISA2

#define KBD_DATA    RA4
#define KBD_CLOCK   RA2

#define INT RA5

#define interrupt_assert()      INT = 0
#define interrupt_disassert()   INT = 1

#define kbd_data_low()  KBD_TRIS_DATA = 0
#define kbd_clock_low() KBD_TRIS_CLOCK = 0

#define kbd_data_release()  KBD_TRIS_DATA = 1
#define kbd_clock_release() KBD_TRIS_CLOCK = 1

#define START_BIT   0
#define PARITY_BIT  9
#define STOP_BIT    10

#define SHIFT_LEFT      0x12
#define SHIFT_RIGTH     0x59
#define EXTENDED_KEY    0xE0
#define KEY_RELEASED    0xF0
#define ALT             0x11
#define CAPS_LOCK       0x58

#define TRUE    0x01
#define FALSE   0x00

volatile unsigned char buffer;
unsigned char shift, caps_lock, alt;
unsigned char ascii;

void interrupt interrupt_handler() {
    static unsigned char i;
    static unsigned char data;

    INTF = 0;

    if (i == START_BIT) {
        data = 0;
        i++;
    }
    else if (i == PARITY_BIT) {
        i++;
    }
    else if (i == STOP_BIT) {
        i = 0;
        buffer = data;
    }
    else {
        data |= (KBD_DATA<<(i-1));
        i++;
    }
}

unsigned char get_ASCII(unsigned char data) {
    if (data <= LOOKUP_TABLE_SIZE) {
        if (alt == TRUE)
            return altered[data];
        else if (caps_lock == TRUE)
            return shifted[data];
        else if (shift == TRUE)
            return shifted[data];
        else
            return unshifted[data];
    }
    else return 0x00;
}

void send_ascii(unsigned char ascii) {
    SSPBUF = ascii;
    interrupt_assert();
    while (!BF);
    SSPBUF;
    interrupt_disassert();
}

int main(void) {
    // CLOCK 16 MHz
    OSCCON = 0b01111000; // 4x PLL is disabled; 16 MHz HF; Clock determined by FOSC<2:0> in Configuration Word 1

    // Disable analog pins
    ANSELA = 0x00;
    ANSELC = 0x00;

    // LATCH
    LATA2 = 0;
    LATA4 = 0;
    LATA5 = 1;

    // TRIS
    TRISA2 = 1;
    TRISA4 = 1;
    TRISA5 = 0;

    buffer = 0x00;

    // Interrupt
    INTEDG = 0; // Interrupt on falling edge of RB0/INT pin
    INTF = 0;
    INTE = 1; // Enables the INT external interrupt
    GIE = 1; // Enables all active interrupts
    
    // SPI
    TRISC1 = 1; // SDI configured as input
    TRISC2 = 0; // SDO configured as output
    TRISC0 = 1; // SCK configured as input
    TRISC3 = 1; // SS configured as input

    /* Init SSP
     * SSPEN = 1 : Enables serial port and configures SCK, SDO and SDI as serial port pins
     * CKP = 0 : Clock Polarity Select bit = Idle state for clock is a low level
     * Synchronous Serial Port Mode : Master Mode FOSC/4 (4 MHz)
     * SMP=0; CKE=1; CKP=0
     */
    SSP1CON1bits.SSPM = 0b0100; // SPI Slave mode, clock = SCK pin, SS pin control enabled
    SSP1CON1bits.CKP = 0; // Idle state for clock is a low level
    SSP1STATbits.CKE = 1;
    SSP1STATbits.SMP = 0;
    SSP1CON1bits.SSPEN = 1;

    shift = FALSE;
    caps_lock = FALSE;
    alt = FALSE;

    while(1) {
        while (buffer == 0);
        if (buffer == KEY_RELEASED) {
            buffer = 0x00;
            while (buffer == 0);
            if (buffer == SHIFT_LEFT) shift = FALSE;
            else if (buffer == SHIFT_RIGTH) shift = FALSE; 
            else if (buffer == ALT) alt = FALSE;
            buffer = 0x00;
        }
        else {
            ascii = get_ASCII(buffer);
            if (ascii != 0) send_ascii(ascii);
            else if (buffer == SHIFT_LEFT) shift = TRUE;
            else if (buffer == SHIFT_RIGTH) shift = TRUE;
            else if (buffer == CAPS_LOCK) caps_lock = ((caps_lock==TRUE)?FALSE:TRUE);
            else if (buffer == ALT) alt = TRUE;
            buffer = 0x00;
        }
    }
}

