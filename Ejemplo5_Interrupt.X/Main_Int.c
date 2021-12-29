/* 
 * File:   Main_Int.c
 * Author: LENOVO
 *
 * Created on 24 de septiembre de 2021, 08:49 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <math.h>
#include <dsp.h>
#include "Configuracion.h"
#include <libpic30.h>
#include "LCD_dspic.h"
#include "Interrupciones.h"


#define Pase_Autos      0b00001100
#define Pase_Personas   0b00100001
#define Ambar           0b00010010


uint8_t i = 0,personas =0,autos=0;
char Str_personas[12],Str_autos[12];


void __attribute__((interrupt,no_auto_psv))_INT0Interrupt(void){
//    for(i=0;i<=5;i++){
//    
//        LATC = 0x0F;
//        __delay_ms(300);
//        LATC = 0xF0;
//         __delay_ms(300);
//    }
//    LATC = 0X00;
    autos++;
    sprintf(Str_autos,"Autos:%03u",autos);
    LCD_dsPIC_SetCursor(0,FILA1);
    LCD_dsPIC_Print_String(Str_autos);
IFS0bits.INT0IF = 0;//limpio la bandera
}
void __attribute__((interrupt,no_auto_psv))_INT1Interrupt(void){

//    for(i=0;i<=8;i++){
//        LATC = pow(2,i)-1;
//        __delay_ms(100);
//    }
//    for(i=7;i>0;i--){
//        LATC = pow(2,i)-1;
//        __delay_ms(100);
//    }
//    LATC = 0X00;
    personas++;
    sprintf(Str_personas,"Personas:%03u",personas);
    LCD_dsPIC_SetCursor(0,FILA2);
    LCD_dsPIC_Print_String(Str_personas);
    
IFS1bits.INT1IF = 0;//limpio la bandera
}
void __attribute__((interrupt,no_auto_psv))_INT2Interrupt(void){
//    for(i=0;i<=8;i++){
//    
//        LATC = 0xFF;
//        __delay_ms(300);
//        LATC = 0x00;
//         __delay_ms(300);
//    }
//LATC = 0X00;
    
    LATAbits.LATA10 =!LATAbits.LATA10;
    
IFS1bits.INT2IF = 0;//limpio la bandera
}

int main(int argc, char** argv) {
    TRISC = 0X00;
    TRISA &= ~(1<<10);
    LATAbits.LATA10=0;
//    Interrup_Config();
    LCD_dsPIC_Init();
    Interrupcion_Externa(INT1,Bajada,4);
    Interrupcion_Externa(INT2,Subida,6);
    Interrupcion_Externa(INT0,Subida,5);
     
    sprintf(Str_autos,"Autos:%03u",autos);
    sprintf(Str_personas,"Personas:%03u",personas);
    
    LCD_dsPIC_SetCursor(0,FILA1);
    LCD_dsPIC_Print_String(Str_autos);
    LCD_dsPIC_SetCursor(0,FILA2);
    LCD_dsPIC_Print_String(Str_personas);
    
    
    for(;;){
    
        LATC = Pase_Autos;
        __delay_ms(500);
        LATC =  Ambar;
         __delay_ms(500);
        LATC = Pase_Personas;
         __delay_ms(500);
        LATC  = Ambar;
        __delay_ms(500);
    
    }
    
    
    return (EXIT_SUCCESS);
}

//void Interrup_Config(void){
////INT0
//   IEC0bits.INT0IE = 1;//Habilito el INT0
//   IPC0bits.INT0IP = 0b011;//prioridad 1
//   IFS0bits.INT0IF = 0;//limpio la bandera
//   INTCON2bits.INT0EP = 0;//Flanco de Subida
//   TRISB |= (1<<7);//Definimos como entrada al bit B7
// 
////INT1
//   IEC1bits.INT1IE = 1;//Habilito el INT1
//   IPC5bits.INT1IP = 0b001;//prioridad 2
//   IFS1bits.INT1IF= 0;//limpio la bandera
//   INTCON2bits.INT1EP = 0;//Flanco de Subida
//   TRISB |= (1<<15);//Definimos como entrada al bit B15
//   RPINR0bits.INT1R = 0XF;//definimos al pinRB15 como INT1
//
//
////INT2   
//   IEC1bits.INT2IE = 1;//Habilito el INT2
//   IPC7bits.INT2IP = 0b010;//prioridad 3
//   IFS1bits.INT2IF = 0;//limpio la bandera
//   INTCON2bits.INT2EP = 0;//Flanco de Subida
//   TRISB |= (1<<14);//Definimos como entrada al bit B14
//   RPINR1bits.INT2R = 0xE ;//definimos al pinRB14 como INT2
//
//
//
//
//}
//


