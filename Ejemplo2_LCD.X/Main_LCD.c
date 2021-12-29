/* 
 * File:   Main_LCD.c
 * Author: LENOVO
 *
 * Created on 20 de septiembre de 2021, 07:24 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "Configuracion.h"
#include <libpic30.h>
#include "LCD_dspic.h"


//uint8_t Corazon[8] = {0x0A,0x1F,0x1F,0x1F,0x0E,0x04,0x00,0x00};

#define Izquierda 0
#define Derecha 1
void Corrimiento_LCD_dsPIC(bool Modo);
uint8_t i = 0;

int main(int argc, char** argv) {
    
    LCD_dsPIC_Init();
    LCD_dsPIC_New_Char(1,0x0A,0x1F,0x1F,0x1F,0x0E,0x04,0x00,0x00);//Corazon
    LCD_dsPIC_New_Char(2,0x0E,0x1F,0x15,0x1F,0x0E,0x0E,0x00,0x00);//kull
    LCD_dsPIC_New_Char(3,0x0E,0x0E,0x04,0x1F,0x04,0x04,0x04,0x0SA);//Humano
    
    //    LCD_dsPIC_SetCursor(1,FILA1);
//    LCD_dsPIC_Print_Char('2');
//    LCD_dsPIC_SetCursor(1,FILA2);
//    LCD_dsPIC_Print_Char('0');
//    LCD_dsPIC_SetCursor(1,FILA3);
//    LCD_dsPIC_Print_Char('2');
//    LCD_dsPIC_SetCursor(1,FILA4);
//    LCD_dsPIC_Print_Char('1');

//    LCD_dsPIC_SetCursor(1,FILA1);
//    LCD_dsPIC_Print_String("Bienvenidos a la");
//    LCD_dsPIC_Write_New_Char(2);
//    LCD_dsPIC_SetCursor(1,FILA2);
//    LCD_dsPIC_Print_String("Especializacion"); 
//    LCD_dsPIC_Write_New_Char(3);
//    LCD_dsPIC_SetCursor(1,FILA3);
//    LCD_dsPIC_Print_String("en dsPIC");
//    LCD_dsPIC_Write_New_Char(1);
//    LCD_dsPIC_SetCursor(1,FILA4);
//    LCD_dsPIC_Print_String("Muchas Gracias");
    
    for(;;){
    
    Corrimiento_LCD_dsPIC(Derecha);
    
    }
    
    return (EXIT_SUCCESS);
}

void Corrimiento_LCD_dsPIC(bool Modo){

    if(Modo == Izquierda){
        for(i=20;i>0;i--){
            LCD_dsPIC_SetCursor(i,FILA1);
            LCD_dsPIC_Print_String("dsPIC MMJ");
            LCD_dsPIC_Write_New_Char(1);//Heart
            __delay_ms(100);
            LCD_dsPIC_Clear();
            LCD_dsPIC_Home();
        }     
        for(i=20;i>0;i--){
            LCD_dsPIC_SetCursor(i,FILA2);
            LCD_dsPIC_Print_String("dsPIC MMJ");
            LCD_dsPIC_Write_New_Char(1);//Heart
            __delay_ms(100);
          LCD_dsPIC_Clear();
          LCD_dsPIC_Home();
        }
        for(i=20;i>0;i--){
            LCD_dsPIC_SetCursor(i,FILA3);
            LCD_dsPIC_Print_String("dsPIC MMJ");
            LCD_dsPIC_Write_New_Char(1);//Heart
            __delay_ms(100);
          LCD_dsPIC_Clear();
          LCD_dsPIC_Home();
        }
        for(i=20;i>0;i--){
            LCD_dsPIC_SetCursor(i,FILA4);
            LCD_dsPIC_Print_String("dsPIC MMJ");
            LCD_dsPIC_Write_New_Char(1);//Heart
            __delay_ms(100);
          LCD_dsPIC_Clear();
          LCD_dsPIC_Home();
        }
        
        
    }
    
    if(Modo == Derecha ){
            for(i=0;i<19;i++){
            LCD_dsPIC_SetCursor(i,FILA1);
            LCD_dsPIC_Print_String("dsPIC MMJ");
            LCD_dsPIC_Write_New_Char(1);//Heart
            __delay_ms(100);
            LCD_dsPIC_Clear();
            LCD_dsPIC_Home();
        }     
        for(i=0;i<19;i++){
            LCD_dsPIC_SetCursor(i,FILA2);
            LCD_dsPIC_Print_String("dsPIC MMJ");
            LCD_dsPIC_Write_New_Char(1);//Heart
            __delay_ms(100);
          LCD_dsPIC_Clear();
          LCD_dsPIC_Home();
        }
        for(i=0;i<19;i++){
            LCD_dsPIC_SetCursor(i,FILA3);
            LCD_dsPIC_Print_String("dsPIC MMJ");
            LCD_dsPIC_Write_New_Char(1);//Heart
            __delay_ms(100);
          LCD_dsPIC_Clear();
          LCD_dsPIC_Home();
        }
        for(i=0;i<19;i++){
            LCD_dsPIC_SetCursor(i,FILA4);
            LCD_dsPIC_Print_String("dsPIC MMJ");
            LCD_dsPIC_Write_New_Char(1);//Heart
            __delay_ms(100);
          LCD_dsPIC_Clear();
          LCD_dsPIC_Home();
        }
        
    
    }


}