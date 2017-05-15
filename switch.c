/**
  ******************************************************************************
  * @file    switch.c
  * @author  Pierluigi,Alfonso,Erasmo
  * @version V1.0
  * @date    04-May-2017
  * @brief   Questo file implementa le principali funzioni di gestione degli switch      
  ********************************************************************************
  */

/* Includes -------------------------------------------------------------------*/
#include "switch.h"

/**
  * @brief  abilita tutti gli switch
  * @param 	self: puntatore alla struttura
  */
void SW_enable(switch_t* self){
	APE_writeValue32(self->base_addr,APE_EN_REG,0x0);
}

/**
  * @brief  disabilita tutti gli switch
  * @param 	self: puntatore alla struttura
  */
void SW_disable(switch_t* self){
	APE_writeValue32(self->base_addr,APE_EN_REG,0xF);
}

/**
  * @brief  legge il valore degli switch
  * @param 	self: puntatore alla struttura
  */
uint32_t SW_readStatus(switch_t* self){
	return APE_readValue32(self->base_addr,APE_RD_REG);
}

/**
  * @brief  inizializzazione della struttura
  * @param 	self: puntatore alla struttura
  */
void SW_Init(switch_t* self){
	self->base_addr = (uint32_t*)BASE_ADDRESS;
	self->enable = &SW_enable;
	self->disable = &SW_disable;
	self->readStatus = &SW_readStatus;
}
