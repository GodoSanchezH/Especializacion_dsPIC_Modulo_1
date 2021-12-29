/* 
 * File:   Main_Keypad.c
 * Author: LENOVO
 *
 * Created on 24 de septiembre de 2021, 07:23 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include "Configuracion.h"
#include <libpic30.h>
#include "Keypad_dsPIC.h"
#include "LCD_dspic.h"
/*
 * 
 */
char Caracter_K ;

int main(int argc, char** argv) {
    LCD_dsPIC_Init();
    keypad_init();
    
    
    for(;;){
    
        Caracter_K = keypad_read();
        LCD_dsPIC_SetCursor(0,FILA1);
        
        if(Caracter_K != KEYPAD_ERROR){
        __delay_ms(300);
        
        LCD_dsPIC_Print_String("Tecla Pulsada->");
        LCD_dsPIC_Print_Char(Caracter_K);
        
        }
        
    }
    
    return (EXIT_SUCCESS);
}

