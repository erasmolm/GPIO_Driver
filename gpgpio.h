/**
  ******************************************************************************
  * @file    gpgpio.h
  * @author  Pierluigi,Alfonso,Erasmo
  * @version V1.0
  * @date    04-May-2017
  * @brief   Questo file definisce le principali funzioni di accesso ad una
  *			 generica periferica GPIO         
  ******************************************************************************
  */

#ifndef SRC_GPGPIO_H_
#define SRC_GPGPIO_H_

/* Includes ------------------------------------------------------------------*/
#include <inttypes.h>
#include "xparameters.h"


#define APE_EN_REG	0 	/*!< offset registro enable*/
#define APE_WR_REG	4	/*!< offset registro write*/
#define APE_RD_REG	8	/*!< offset registro read*/

/**
  * @brief selezione parte del registro per indirizzamento
  *		   a 16 bit a partire da destra
 */
#define L	0	/*!<parte meno significativa*/
#define H	1	/*!<parte più significativa*/

/**
  * @brief selezione parte del registro per indirizzamento
  *		   a 8 bit a partire da destra
 */
#define LL	0	/*!<primo byte*/
#define LH	1	/*!<secondo byte*/
#define HL	2	/*!<terzo byte*/
#define HH	3	/*!<quarto byte*/


typedef enum { false, true } bool;

/**
  * @brief firme delle funzioni
 */
void APE_writeValue32(uint32_t*,int,uint32_t);
void APE_writeValue16(uint32_t*,int,uint16_t,int);
void APE_writeValue8(uint32_t*,int,uint8_t,int);
uint32_t APE_readValue32(uint32_t*,int);
uint16_t APE_readValue16(uint32_t*,int,int);
uint8_t APE_readValue8(uint32_t*,int,int);
void APE_setBit(uint32_t*,int,bool,int);
void APE_toggleBit(uint32_t*,int,int);

#endif /* SRC_GPGPIO_H_ */
