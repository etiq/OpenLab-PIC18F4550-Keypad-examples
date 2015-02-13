/*
 * File name            : KeyFn.c
 * Compiler             : XC8 compiler
 * IDE                  : Microchip MPLAB X IDE v1.90
 * Author               : Etiq Technologies
 * Description          : Example_10.1 Keypad
 *                      : Created on November 4, 2013, 4:30 PM
 *                      : Keypad function definitions
 */

#if defined(__XC)
    #include <xc.h>        /* XC8 General Include File */
#elif defined(__18CXX)
    #include <p18cxxx.h>   /* C18 General Include File */
#endif

#if defined(__XC) || defined(__18CXX)
#include "delay.h"
#include "uart.h"
#endif

/*__________________________ Uncomment for desired Control port ________________________________________*/

#define PORTB_CTRL
//#define PORTD_CTRL                                            /* pull down mode */


#if defined PORTB_CTRL

#define CTRL_PORT PORTB
#define CTRL_PORT_DIR TRISB

#define A00 (PORTBbits.RB7)&&(PORTBbits.RB3)
#define A01 (PORTBbits.RB6)&&(PORTBbits.RB3)
#define A02 (PORTBbits.RB5)&&(PORTBbits.RB3)
#define A03 (PORTBbits.RB4)&&(PORTBbits.RB3)

#define A10 (PORTBbits.RB7)&&(PORTBbits.RB2)
#define A11 (PORTBbits.RB6)&&(PORTBbits.RB2)
#define A12 (PORTBbits.RB5)&&(PORTBbits.RB2)
#define A13 (PORTBbits.RB4)&&(PORTBbits.RB2)

#define A20 (PORTBbits.RB7)&&(PORTBbits.RB1)
#define A21 (PORTBbits.RB6)&&(PORTBbits.RB1)
#define A22 (PORTBbits.RB5)&&(PORTBbits.RB1)
#define A23 (PORTBbits.RB4)&&(PORTBbits.RB1)

#define A30 (PORTBbits.RB7)&&(PORTBbits.RB0)
#define A31 (PORTBbits.RB6)&&(PORTBbits.RB0)
#define A32 (PORTBbits.RB5)&&(PORTBbits.RB0)
#define A33 (PORTBbits.RB4)&&(PORTBbits.RB0)

#elif defined PORTD_CTRL

#define CTRL_PORT PORTD
#define CTRL_PORT_DIR TRISD

#define A00 (PORTDbits.RD7)&&(PORTDbits.RD3)
#define A01 (PORTDbits.RD6)&&(PORTDbits.RD3)
#define A02 (PORTDbits.RD5)&&(PORTDbits.RD3)
#define A03 (PORTDbits.RD4)&&(PORTDbits.RD3)

#define A10 (PORTDbits.RD7)&&(PORTDbits.RD2)
#define A11 (PORTDbits.RD6)&&(PORTDbits.RD2)
#define A12 (PORTDbits.RD5)&&(PORTDbits.RD2)
#define A13 (PORTDbits.RD4)&&(PORTDbits.RD2)

#define A20 (PORTDbits.RD7)&&(PORTDbits.RD1)
#define A21 (PORTDbits.RD6)&&(PORTDbits.RD1)
#define A22 (PORTDbits.RD5)&&(PORTDbits.RD1)
#define A23 (PORTDbits.RD4)&&(PORTDbits.RD1)

#define A30 (PORTDbits.RD7)&&(PORTDbits.RD0)
#define A31 (PORTDbits.RD6)&&(PORTDbits.RD0)
#define A32 (PORTDbits.RD5)&&(PORTDbits.RD0)
#define A33 (PORTDbits.RD4)&&(PORTDbits.RD0)

#endif

                       /*      Function to get a key press and assigning a value        */

 unsigned char arr[4][4] = {{'1', '2', '3', 'A'},
                            {'4', '5', '6', 'B'},
                            {'7' ,'8', '9', 'C'},
                            {'*', '0', '#', 'D'}
                          };

unsigned char Print_key(unsigned char element, unsigned char a)
{
        if(element)
        {
                 delay_ms(10);                                               /* Delay for 10 micro seconds                                    */
                 if (element)                                                /* Confirming again the above condition                          */
                 {
                 delay_ms(10);
                 if (element)                                               /* Confirming again the above condition                          */
                 { 
                 Write(a);                                                  /* Assigning a value for the above condition, writing to UART    */
                 return(1);                                                 /* Exit from first internal loop                                 */
                 }
                 }
        }
                return(0);
}
                                      /*      Function to get a key press and assigning a value        */

void Get_key(void)
 {
 unsigned char row;
 CTRL_PORT_DIR = 0xF0;                               /*      loop for releasing any unwanted key press initially      */

 do
       {
        CTRL_PORT = 0X0F;
        row = CTRL_PORT;
        row &= 0xF0;
       }while(row!=0x00);
#if defined PORTB_CTRL      
       delay_ms(100);
#elif defined PORTD_CTRL
       delay_ms(50);
#endif
            /*                          Waiting for any key press                                                   */
  do
          {
          CTRL_PORT = 0X0F;
          row = CTRL_PORT;
          row &= 0xF0;
          }while(row==0x00);

            /*        Identifying the key press and assigning the values by scanning the coulmns    */
     while(1)
         {
     CTRL_PORT = 0X08;
   if(Print_key(A00,arr[0][0]))
          break;
   else if(Print_key(A01, arr[0][1]))
          break;
   else if(Print_key(A02, arr[0][2]))
          break;
   else if(Print_key(A03, arr[0][3]))
          break;

     CTRL_PORT = 0X04;
            if(Print_key(A10, arr[1][0]))
          break;
   else if(Print_key(A11, arr[1][1]))
          break;
   else if(Print_key(A12, arr[1][2]))
          break;
   else if(Print_key(A13, arr[1][3]))
          break;

     CTRL_PORT = 0X02;
        if(Print_key(A20, arr[2][0]))
          break;
   else if(Print_key(A21, arr[2][1]))
          break;
   else if(Print_key(A22, arr[2][2]))
          break;
   else if(Print_key(A23, arr[2][3]))
          break;

     CTRL_PORT = 0X01;
        if(Print_key(A30, arr[3][0]))
          break;
   else if(Print_key(A31, arr[3][1]))
          break;
   else if(Print_key(A32, arr[3][2]))
          break;
   else if(Print_key(A33, arr[3][3]))
          break;
        }
  }