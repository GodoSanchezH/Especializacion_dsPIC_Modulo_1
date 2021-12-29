/* 
 * File:   Keypad_dsPICç+.h
 * Author: LENOVO
 *
 * Created on 15 de agosto de 2021, 04:19 PM
 */

#ifndef KEYPAD_DSPIC__H
#define	KEYPAD_DSPIC__H

#include <stdint.h>
#include <xc.h>
#include "Configuracion.h"
#include <libpic30.h>

//pines para las filas
#define R1_TRIS     TRISBbits.TRISB0
#define R1_LAT      LATBbits.LATB0
#define R2_TRIS     TRISBbits.TRISB1
#define R2_LAT      LATBbits.LATB1
#define R3_TRIS     TRISBbits.TRISB2
#define R3_LAT      LATBbits.LATB2
#define R4_TRIS     TRISBbits.TRISB3
#define R4_LAT      LATBbits.LATB3
//pines para las columnas
#define C1_TRIS     TRISBbits.TRISB4
#define C1_PORT     PORTBbits.RB4
#define C2_TRIS     TRISBbits.TRISB5
#define C2_PORT     PORTBbits.RB5
#define C3_TRIS     TRISBbits.TRISB6
#define C3_PORT     PORTBbits.RB6
#define C4_TRIS     TRISBbits.TRISB7
#define C4_PORT     PORTBbits.RB7

//DEFINICION DE MACROS GENERICOS

#define KEYPAD_ERROR    -1

/*************************DEFINICION DE PROTOTIPO DE FUNCIONES*****************/
void keypad_init(void);
int8_t keypad_read(void);



#endif	/* KEYPAD_DSPICÇ__H */

