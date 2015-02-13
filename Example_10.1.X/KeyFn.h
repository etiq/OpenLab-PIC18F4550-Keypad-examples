/*
 * File name            : KeyFn.h
 * Compiler             : MPLAB XC8/ MPLAB C18 compiler
 * IDE                  : Microchip  MPLAB X IDE v1.90/ MPLAB IDE v8
 * Author               : Etiq Technologies
 * Description          : Example_10.1 Keypad
 *                      : Created on November 4, 2013, 4:30 PM
 *                      : Keypad Functions header file
 */

#ifndef KEYFN_H
#define	KEYFN_H

/*__________________________________________Keypad entry detecting function header____________________________________________*/

void Get_key(void);

/*
 * Include          :       KeyFn.h
 * Description      :       Detects the key press
 * Arguments        :       None
 * Returns          :       None
 */
 
unsigned char Print_key(unsigned char element, unsigned char a);

/*
 * Include          :       KeyFn.h
 * Description      :       Identifies the key and prints the corresponding character
 * Arguments        :       None
 * Returns          :       None
 */
 
#endif	/* KEYFN_H */

