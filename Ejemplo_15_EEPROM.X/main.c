/* 
 * File:   main_i2c.c
 * Author: HP
 *
 * Created on 22 de octubre de 2021, 10:06 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include "Configuracion.h"
#include <libpic30.h>
#include "I2C_dspic.h"

#include "Uart_dspic.h"
#include <string.h>
/*
 * 
 */
#define EEPROM_DIR1 0XA6  
#define EEPROM_DIR2 0XA0  
#define EEPROM_DIR3 0XA2 

uint8_t Display_7Seg_A[10] = {0XC0,0XF9,0XA4,0XB0,0X99,0X92,0X82,0XF8,0X80,0X90};

void EEPROM_Byte_Write(uint8_t DIR,uint16_t add_EE,char c);
void EEPROM_PAGE_Write(uint8_t DIR,uint16_t add_EE,char *c);
void EEPROM_RANDOM_READ(uint8_t DIR,uint16_t add_EE,uint8_t *dato);

uint16_t var1;
float var2;
char var3;
char trama_eeprom[100];
char STR_1[5],STR_2[5],STR_3[5];
char cadena1[] = "Sensor a1: ",cadena2[] = " Sensor a2: ",cadena3[] =  " Sensor a3: ";
uint8_t DATO_i2c;
int main(int argc, char** argv) {
//    var1 = 38;
//    var2 = 15.50;
//    var3 = 'G';
//    
    
//    sprintf(STR_1,"%u",var1);
//    sprintf(STR_2,"%0.2f",var2);
//    sprintf(STR_3,"%c",var3);
//    
//    strcat(trama_eeprom,cadena1);
//    strcat(trama_eeprom,STR_1);
//    strcat(trama_eeprom,cadena2);
//    strcat(trama_eeprom,STR_2);
//    strcat(trama_eeprom,cadena3);
//    strcat(trama_eeprom,STR_3);
   I2C_Init(100);

    UART_dsPIC_Init(9600,one_bit_Stop,Ocho_D_SP,2);
    
    UART_Tx_String("INICIANDO\n\r");

    //EEPROM_Byte_Write(EEPROM_DIR1,0x34F8,'J');
     asm("nop");
     
     
//     EEPROM_PAGE_Write(EEPROM_DIR1,0x0014,trama_eeprom);
//     EEPROM_PAGE_Write(EEPROM_DIR2,0x0014,"Bienvenidos a la Especilizacion en dsPIC");
//     EEPROM_PAGE_Write(EEPROM_DIR3,0x0014,"Finalizando el Modulo 1");
//     
     EEPROM_RANDOM_READ(EEPROM_DIR1,0X0032,&DATO_i2c);
     printf("%c",(char)DATO_i2c);
     
    for(;;){

        
        
    }
    
    
    return (EXIT_SUCCESS);
}

/*tarea sorpresa*/
//LEEER UNA CADENA POR I2C 
void EEPROM_RANDOM_READ(uint8_t DIR,uint16_t add_EE,uint8_t *dato){
    I2C_Start();//iniciamos la comunicacion
    I2C_Write_Address_Slave(DIR,I2C_WRITE);//direccion del eeeprom
    I2C_Write_Data_Slave(add_EE>>8);
    I2C_Write_Data_Slave((uint8_t)add_EE);
    I2C_Restart();
    I2C_Write_Address_Slave(DIR,I2C_READ);
    I2C_Read_Data(dato,I2C_nACK);
    I2C_Stop();

}
void EEPROM_PAGE_Write(uint8_t DIR,uint16_t add_EE,char *str){

    char *ptr;
    ptr = str;
    I2C_Start();//iniciamos la comunicacion
    I2C_Write_Address_Slave(DIR,I2C_WRITE);//direccion del eeeprom
    I2C_Write_Data_Slave(add_EE>>8);
    I2C_Write_Data_Slave((uint8_t)add_EE);
    while(*ptr)
        I2C_Write_Data_Slave(*ptr++);
    I2C_Stop();
    
    

}
void EEPROM_Byte_Write(uint8_t DIR,uint16_t add_EE,char c){

    I2C_Start();//iniciamos la comunicacion
    I2C_Write_Address_Slave(DIR,I2C_WRITE);//direccion del eeeprom
    I2C_Write_Data_Slave(add_EE>>8);
    I2C_Write_Data_Slave((uint8_t)add_EE);
    I2C_Write_Data_Slave(c);
    I2C_Stop();
    
}