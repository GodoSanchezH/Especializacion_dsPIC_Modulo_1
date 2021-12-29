/* 
 * File:   LCD_dspic.h
 * Author: LENOVO
 *
 * Created on 20 de septiembre de 2021, 07:29 PM
 */

#ifndef LCD_DSPIC_H
#define	LCD_DSPIC_H

#include <stdint.h>
#include <xc.h>


#define E  LATBbits.LATB10
#define RS LATBbits.LATB11
#define D4 LATBbits.LATB12
#define D5 LATBbits.LATB13
#define D6 LATBbits.LATB14
#define D7 LATBbits.LATB15

typedef enum{
    FILA1 = 1,
    FILA2,        
    FILA3 ,
    FILA4 
}Ubicacion;

void LCD_dsPIC_Cmd(uint8_t a);
void LCD_dsPIC_DataBus(uint8_t a);
void LCD_dsPIC_Init(void);
void LCD_dsPIC_SetCursor(uint8_t x , uint8_t y);
void LCD_dsPIC_Print_Char(char a);
void LCD_dsPIC_Print_String(char *a);
void LCD_dsPIC_New_Char(uint8_t a,uint8_t b,uint8_t c,uint8_t d,uint8_t e,uint8_t f,uint8_t g,uint8_t h,uint8_t i);
void LCD_dsPIC_Write_New_Char(uint8_t a);
void LCD_dsPIC_Clear(void);
void LCD_dsPIC_Home(void);

#endif	/* LCD_DSPIC_H */

