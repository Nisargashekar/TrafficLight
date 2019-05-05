/*******************************************************************************
* File Name: LED_UpdateISR.h
* Version 1.70
*
*  Description:
*   Provides the function definitions for the Interrupt Controller.
*
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_ISR_LED_UpdateISR_H)
#define CY_ISR_LED_UpdateISR_H

#include <cytypes.h>
#include <cyfitter.h>

/* Interrupt Controller API. */
void LED_UpdateISR_Start(void) ;
void LED_UpdateISR_StartEx(cyisraddress address) ;
void LED_UpdateISR_Stop(void) ;

CY_ISR_PROTO(LED_UpdateISR_Interrupt);

void LED_UpdateISR_SetVector(cyisraddress address) ;
cyisraddress LED_UpdateISR_GetVector(void) ;

void LED_UpdateISR_SetPriority(uint8 priority) ;
uint8 LED_UpdateISR_GetPriority(void) ;

void LED_UpdateISR_Enable(void) ;
uint8 LED_UpdateISR_GetState(void) ;
void LED_UpdateISR_Disable(void) ;

void LED_UpdateISR_SetPending(void) ;
void LED_UpdateISR_ClearPending(void) ;


/* Interrupt Controller Constants */

/* Address of the INTC.VECT[x] register that contains the Address of the LED_UpdateISR ISR. */
#define LED_UpdateISR_INTC_VECTOR            ((reg16 *) LED_UpdateISR__INTC_VECT)

/* Address of the LED_UpdateISR ISR priority. */
#define LED_UpdateISR_INTC_PRIOR             ((reg8 *) LED_UpdateISR__INTC_PRIOR_REG)

/* Priority of the LED_UpdateISR interrupt. */
#define LED_UpdateISR_INTC_PRIOR_NUMBER      LED_UpdateISR__INTC_PRIOR_NUM

/* Address of the INTC.SET_EN[x] byte to bit enable LED_UpdateISR interrupt. */
#define LED_UpdateISR_INTC_SET_EN            ((reg8 *) LED_UpdateISR__INTC_SET_EN_REG)

/* Address of the INTC.CLR_EN[x] register to bit clear the LED_UpdateISR interrupt. */
#define LED_UpdateISR_INTC_CLR_EN            ((reg8 *) LED_UpdateISR__INTC_CLR_EN_REG)

/* Address of the INTC.SET_PD[x] register to set the LED_UpdateISR interrupt state to pending. */
#define LED_UpdateISR_INTC_SET_PD            ((reg8 *) LED_UpdateISR__INTC_SET_PD_REG)

/* Address of the INTC.CLR_PD[x] register to clear the LED_UpdateISR interrupt. */
#define LED_UpdateISR_INTC_CLR_PD            ((reg8 *) LED_UpdateISR__INTC_CLR_PD_REG)



#endif /* CY_ISR_LED_UpdateISR_H */


/* [] END OF FILE */
