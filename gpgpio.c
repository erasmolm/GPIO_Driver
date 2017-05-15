/**
  ******************************************************************************
  * @file    gpgpio.c
  * @author  Pierluigi,Alfonso,Erasmo
  * @version V1.0
  * @date    04-May-2017
  * @brief   Questo file implementa le principali funzioni di accesso ad una
  *			 generica periferica GPIO         
  ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
#include <assert.h>
#include "gpgpio.h"

/**
  * @brief  scrive un valore di 32 bit in un registro
  * @param 	addr: indirizzo base del registro
  * @param  offset: offset sommato all'indirizzo base.
  *   Questo parametro può assumere i seguenti valori:
  *     @arg APE_EN_REG
  *     @arg APE_WR_REG
  *     @arg APE_RD_REG
  * @param 	value: valore da scrivere nel registro
  */
void APE_writeValue32(uint32_t* addr,int offset,uint32_t value){
	assert(((uint32_t)addr)%4 == 0);
	addr[offset/4] = value;
}

/**
  * @brief  scrive un valore di 16 bit in un registro
  * @param 	addr: indirizzo base del registro
  * @param  offset: offset sommato all'indirizzo base.
  *   Questo parametro può assumere i seguenti valori:
  *     @arg APE_EN_REG
  *     @arg APE_WR_REG
  *     @arg APE_RD_REG
  * @param 	value: valore da scrivere nel registro
  * @param  part: sottoparte del registro selezionata
  *   Questo parametro può assumere i seguenti valori:
  *     @arg L
  *     @arg H
  */
void APE_writeValue16(uint32_t* addr,int offset,uint16_t value,int part){
	assert(((uint32_t)addr)%4 == 0);
	uint32_t val_32 = (uint32_t)value<<(16*part);
	addr[offset/4] = val_32;
}

/**
  * @brief  scrive un valore di 8 bit in un registro
  * @param 	addr: indirizzo base del registro
  * @param  offset: offset sommato all'indirizzo base.
  *   Questo parametro può assumere i seguenti valori:
  *     @arg APE_EN_REG
  *     @arg APE_WR_REG
  *     @arg APE_RD_REG
  * @param 	value: valore da scrivere nel registro
  * @param  part: sottoparte del registro selezionata.
  *   Questo parametro può assumere i seguenti valori:
  *     @arg LL
  *     @arg LH
  *     @arg HL
  *     @arg HH
  */
void APE_writeValue8(uint32_t* addr,int offset,uint8_t value,int part){
	assert(((uint32_t)addr)%4 == 0);
	uint32_t val_32 = (uint32_t)value<<(8*part);
	addr[offset/4] = val_32;
}

/**
  * @brief  legge un valore di 32 bit da un registro
  * @param 	addr: indirizzo base del registro
  * @param  offset: offset sommato all'indirizzo base.
  *   Questo parametro può assumere i seguenti valori:
  *     @arg APE_EN_REG
  *     @arg APE_WR_REG
  *     @arg APE_RD_REG
  */
uint32_t APE_readValue32(uint32_t* addr,int offset){
	assert(((uint32_t)addr)%4 == 0);
	return addr[offset/4];
}


/**
  * @brief  legge un valore di 16 bit da un registro
  * @param 	addr: indirizzo base del registro
  * @param  offset: offset sommato all'indirizzo base.
  *   Questo parametro può assumere i seguenti valori:
  *     @arg APE_EN_REG
  *     @arg APE_WR_REG
  *     @arg APE_RD_REG
  * @param  part: sottoparte del registro selezionata.
  *    Questo parametro può assumere i seguenti valori:
  *     @arg L
  *     @arg H
  */
uint16_t APE_readValue16(uint32_t* addr,int offset, int part){
	assert(((uint32_t)addr)%4 == 0);
	uint32_t val_32 = addr[offset/4];
	val_32=val_32>>(16*part);
	return (uint16_t)val_32;
}

/**
  * @brief  legge un valore di 8 bit da un registro
  * @param 	addr: indirizzo base del registro
  * @param  offset: offset sommato all'indirizzo base.
  *   Questo parametro può assumere i seguenti valori:
  *     @arg APE_EN_REG
  *     @arg APE_WR_REG
  *     @arg APE_RD_REG
  * @param  part: sottoparte del registro selezionata
  * @param  part: sottoparte del registro selezionata.
  *   Questo parametro può assumere i seguenti valori:
  *     @arg LL
  *     @arg LH
  *     @arg HL
  *     @arg HH
  */
uint8_t APE_readValue8(uint32_t* addr,int offset, int part){
	assert(((uint32_t)addr)%4 == 0);
	uint32_t val_32 = addr[offset/4];
	val_32=val_32>>(8*part);
	return (uint8_t)val_32;
}

/**
  * @brief  imposta un bit ad un determinato valore in una 
  * 		particolare posizione di un registro
  * @param 	addr: indirizzo base del registro
  * @param  offset: offset sommato all'indirizzo base.
  *   Questo parametro può assumere i seguenti valori:
  *     @arg APE_EN_REG
  *     @arg APE_WR_REG
  *     @arg APE_RD_REG
  * @param 	val: valore da impostare
  * @param 	pos: posizione in cui impostare il valore
  */
void APE_setBit(uint32_t* addr,int offset,bool val,int pos){
	uint32_t mask = 0x1 << pos;
	assert(((uint32_t)addr)%4 == 0);

	if(val){
		APE_writeValue32(addr,offset,APE_readValue32(addr,offset) | mask);
	}else{
		APE_writeValue32(addr,offset,APE_readValue32(addr,offset) & ~mask);
	}
}

/**
  * @brief  funzione di toggle per uno specifico bit
  * @param 	addr: indirizzo base del registro
  * @param  offset: offset sommato all'indirizzo base.
  *   Questo parametro può assumere i seguenti valori:
  *     @arg APE_EN_REG
  *     @arg APE_WR_REG
  *     @arg APE_RD_REG
  * @param 	pos: posizione in cui impostare il valore
  */
void APE_toggleBit(uint32_t* addr,int offset,int pos){
	uint32_t mask = 0x1 << pos;
	assert(((uint32_t)addr)%4 == 0);

	APE_writeValue32(addr,offset,APE_readValue32(addr,offset) ^ mask);

}
