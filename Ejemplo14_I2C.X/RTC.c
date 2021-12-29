#include <stdint.h>
#include <string.h>
#include "RTC.h"
#include "I2C_dsPIC.h"

/*********************************************************************
 * Function:        void DS1307_init(void)
 *
 * PreCondition:    None
 *
 * Input:           None
 *
 * Output:          None
 *
 * Side Effects:    Inicaliza el RTC
 *
 * Overview:        None
 *
 * Note:            Comunicacion i2c
 ********************************************************************/
void DS1307_init(void){
    I2C_Start();
    I2C_Write_Data_Slave(0XD0);
}

/*********************************************************************
 * Function:        void DS1307_Write_Hours_12(uint8_t horas,uint8_t minutos,uint8_t segundos)
 *
 * PreCondition:    None
 *
 * Input:           3 -> horas , minutos , segundos -> uin8_T
 *
 * Output:          None
 *
 * Side Effects:    None
 *
 * Overview:        None
 *
 * Note:            Escribir en el RTC en formato 12 horas
 ********************************************************************/
void DS1307_Write_Hours_12(uint8_t horas,uint8_t minutos,uint8_t segundos,uint8_t formato) {

    uint8_t Seg_ds,Min_ds,Hor_ds = 0;
    
    Seg_ds = ((segundos/10)<<4) | (segundos%10);
    Min_ds = ((minutos/10)<<4) | (minutos%10);
    
    if(formato == AM){
            Hor_ds = (((horas/10)<<4) | (horas%10)) | 0b01000000;
    }
    else{
            Hor_ds = (((horas/10)<<4) | (horas%10))| 0b01100000;
    }  
    I2C_Write_Data_Slave(0X00);
    I2C_Write_Data_Slave(Seg_ds);
    I2C_Write_Data_Slave(Min_ds);
    I2C_Write_Data_Slave(Hor_ds);
    I2C_Stop();
    
}

/*********************************************************************
 * Function:        void DS1307_Write_Hours_24(uint8_t horas,uint8_t minutos,uint8_t segundos)
 *
 * PreCondition:    None
 *
 * Input:           None
 *
 * Output:          None
 *
 * Side Effects:    None
 *
 * Overview:        None
 *
 * Note:            None
 ********************************************************************/
void DS1307_Write_Hours_24(uint8_t horas,uint8_t minutos,uint8_t segundos) {
 uint8_t Seg_ds,Min_ds,Hor_ds = 0;
    
    Seg_ds = ((segundos/10)<<4) | (segundos%10);
    Min_ds = ((minutos/10)<<4) | (minutos%10);
    Hor_ds = ((horas/10)<<4) | (horas%10);
   
    I2C_Write_Data_Slave(0X00);
    I2C_Write_Data_Slave(Seg_ds);
    I2C_Write_Data_Slave(Min_ds);
    I2C_Write_Data_Slave(Hor_ds);
    I2C_Stop();
    
}

/*********************************************************************
 * Function:        void DS1307_Write_Date(uint8_t dia_mes,uint8_t mes ,uint8_t year,uint8_t dia_semana)
 *
 * PreCondition:    None
 *
 * Input:           None
 *
 * Output:          None
 *
 * Side Effects:    None
 *
 * Overview:        None
 *
 * Note:            None
 ********************************************************************/
void DS1307_Write_Date(uint8_t dia_mes,uint8_t mes ,uint8_t year,uint8_t dia_semana) {

    
    dia_mes = ((dia_mes/10)<<4) | (dia_mes%10);
    mes = ((mes/10)<<4) | (mes%10);
    year = ((year/10)<<4) | (year%10);
    dia_semana = ((dia_semana/10)<<4) | (dia_semana%10);
    
    I2C_Start();
    I2C_Write_Data_Slave(0XD0);//modo escritura
    I2C_Write_Data_Slave(0x03);
    I2C_Write_Data_Slave(dia_semana);
    I2C_Write_Data_Slave(dia_mes);
    I2C_Write_Data_Slave(mes);
    I2C_Write_Data_Slave(year);
    
    I2C_Stop();
    
}


 void DS1307_Read_H_24(uint8_t *horas ,uint8_t *minutos,uint8_t *segundos){
     
     
     I2C_Start();
     I2C_Write_Data_Slave(0XD0);//COMUNICAMOS CON EL RTC
     I2C_Write_Data_Slave(0X00); // NOS UBICAMOS EN LA 1ERA DIRECCION
     I2C_Restart();
     I2C_Write_Data_Slave(0XD1);//MODO LECTURA
     I2C_Read_Data(segundos,I2C_ACK);
     I2C_Read_Data(minutos,I2C_ACK);
     I2C_Read_Data(horas,I2C_nACK);
     I2C_Stop();
     
     *segundos = ((*segundos & 0xF0)>>4)*10 + (*segundos & 0x0F);
     *minutos = ((*minutos & 0xF0)>>4)*10 + (*minutos & 0x0F);
     *horas = ((*horas & 0xF0)>>4)*10 + (*horas & 0x0F);
     
 }
 
  void DS1307_Read_Date(uint8_t *year ,uint8_t *mes,uint8_t *dia_mes ,uint8_t *dia_semana){
     
     
     I2C_Start();
     I2C_Write_Data_Slave(0XD0);//COMUNICAMOS CON EL RTC
     I2C_Write_Data_Slave(0X03); // NOS UBICAMOS EN LA 1ERA DIRECCION
     I2C_Restart();
     I2C_Write_Data_Slave(0XD1);//MODO LECTURA
     I2C_Read_Data(dia_semana,I2C_ACK);
     I2C_Read_Data(dia_mes,I2C_ACK);
     I2C_Read_Data(mes,I2C_ACK);
     I2C_Read_Data(year,I2C_nACK);
     I2C_Stop();
     
     *dia_semana = ((*dia_semana & 0xF0)>>4)*10 + (*dia_semana & 0x0F);
     *dia_mes = ((*dia_mes & 0xF0)>>4)*10 + (*dia_mes & 0x0F);
     *mes = ((*mes & 0xF0)>>4)*10 + (*mes & 0x0F);
     *year = ((*year & 0xF0)>>4)*10 + (*year & 0x0F);
 }
 