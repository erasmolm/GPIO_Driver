/**
  ******************************************************************************
  * @file    button.c
  * @author  Pierluigi,Alfonso,Erasmo
  * @version V1.0
  * @date    04-May-2017
  * @brief   Questo file implementa le principali funzioni di gestione dei bottoni      
  ********************************************************************************
  */

/* Includes -------------------------------------------------------------------*/
#include "button.h"

/**
  * @brief  abilita tutti i bottoni
  * @param 	self: puntatore alla struttura
  */
void BTN_enable(btn_t* self){
	APE_writeValue32(self->base_addr,APE_EN_REG,0x0);
}

/**
  * @brief  disabilita tutti i bottoni
  * @param 	self: puntatore alla struttura
  */
void BTN_disable(btn_t* self){
	APE_writeValue32(self->base_addr,APE_EN_REG,0xF);
}

/**
  * @brief  legge il valore dei bottoni
  * @param 	self: puntatore alla struttura
  */
uint32_t BTN_readStatus(btn_t* self){
	return APE_readValue32(self->base_addr,APE_RD_REG);
}

/**
  * @brief  inizializzazione della struttura
  * @param 	self: puntatore alla struttura
  */
void BTN_Init(btn_t* self){
	self->base_addr = (uint32_t*)BASE_ADDRESS;
	self->enable = &BTN_enable;
	self->disable = &BTN_disable;
	self->readStatus = &BTN_readStatus;
}

