/**
  ******************************************************************************
  * @file    led.c
  * @author  Pierluigi,Alfonso,Erasmo
  * @version V1.0
  * @date    04-May-2017
  * @brief   Questo file implementa le principali funzioni di accesso ad una
  *			 generica periferica GPIO         
  ******************************************************************************
  */

/* Includes -------------------------------------------------------------------*/
#include "led.h"

/**
  * @brief  abilita tutti i led
  * @param 	self: puntatore alla struttura
  */
void LED_enable(led_t* self){
	APE_writeValue32(self->base_addr,APE_EN_REG,0xF);
}

/**
  * @brief  disabilita tutti i led
  * @param 	self: puntatore alla struttura
  */
void LED_disable(led_t* self){
	APE_writeValue32(self->base_addr,APE_EN_REG,0x0);
}

/**
  * @brief  legge il valore dei led
  * @param 	self: puntatore alla struttura
  */
uint32_t LED_readStatus(led_t* self){
	return APE_readValue32(self->base_addr,APE_RD_REG);
}

/**
  * @brief  accende un led in una data posizione
  * @param 	self: puntatore alla struttura
  * @param 	pos: posizione del led da accendere 
  */
void LED_setOn(led_t* self,int pos){
	APE_setBit(self->base_addr,APE_WR_REG,1,pos);
}

/**
  * @brief  spegne un led in una data posizione
  * @param 	self: puntatore alla struttura
  * @param 	pos: posizione del led da spegnere 
  */
void LED_setOff(led_t* self,int pos){
	APE_setBit(self->base_addr,APE_WR_REG,0,pos);
}

/**
  * @brief  fa il toggle di un led in una data posizione
  * @param 	self: puntatore alla struttura
  * @param 	pos: posizione del led 
  */
void LED_toggle(led_t* self,int pos){
	APE_toggleBit(self->base_addr,APE_WR_REG,pos);
}

/**
  * @brief  accende i led in base ad una maschera
  * @param 	self: puntatore alla struttura
  * @param 	mask: maschera dei led da accendere 
  */
void LED_setLeds(led_t* self,uint32_t mask){
	APE_writeValue32(self->base_addr,APE_WR_REG,mask);
}

/**
  * @brief  inizializzazione della struttura
  * @param 	self: puntatore alla struttura
  */
void LED_Init(led_t* self){
	self->base_addr = (uint32_t*)BASE_ADDRESS;
	self->enable = &LED_enable;
	self->disable = &LED_disable;
	self->readStatus = &LED_readStatus;
	self->setOn = &LED_setOn;
	self->setOff = &LED_setOff;
	self->toggle = &LED_toggle;
	self->setLeds = &LED_setLeds;
}
