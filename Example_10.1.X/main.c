/*
 * File name            : main.c
 * Compiler             : MPLAB XC8/ MPLAB C18 compiler
 * IDE                  : Microchip  MPLAB X IDE v1.90/ MPLAB IDE v8
 * Author               : Etiq Technologies
 * Description          : Example_10.1 Keypad_1
 *                      : Created on November 4, 2013, 4:30 PM
 *                      : Example code for detecting a keypad entry and displaying the input through UART (PULL DOWN mode)
 */

/*_____________________________________________________________________________________________________________________*/
#if defined(__XC)
    #include <xc.h>        /* XC8 General Include File      */
    #include <plib\usart.h>
#elif defined(HI_TECH_C)
    #include <htc.h>       /* HiTech General Include File   */
#elif defined(__18CXX)
    #include <p18cxxx.h>   /* C18 General Include File      */
	#include <usart.h>
#endif

#if defined(__XC) || defined(HI_TECH_C)
#include <stdint.h>        /* For uint8_t definition        */
#include <stdbool.h>       /* For true/false definition     */
#endif

#if defined(__XC) || defined(__18CXX)
#include "config.h"
#include "delay.h"
#include "KeyFn.h"
#include "uart.h"
#endif

#ifndef _XTAL_FREQ
#define _XTAL_FREQ 20000000
#endif
#define Fosc 20000000                                                 /* External crystal frequency                              */
#define baud 9600                                                     /* UART baud rate                                          */
#define config_2 ((Fosc/baud/64)-1)

unsigned char config_1 = USART_TX_INT_OFF & USART_RX_INT_OFF & USART_ASYNCH_MODE & USART_EIGHT_BIT & USART_CONT_RX & USART_BRGH_LOW;
/*
  CONTROL PORT
  ------------
  PORTD/ PORTB (Define PORTB_CTRL/ PORTD_CTRL in KeyFn.c for selecting desired CONTROL PORT)

 */

void main(void)
    {
    TRISD = 0XF0;                                                   /* Direction of PORTD as Output                     */
    TRISB = 0x00;
    ConfigUSART(config_1, config_2);                                /* Invoking UART configuration function             */
       Get_key();                                                   /* Key press detection function invoke              */

    }