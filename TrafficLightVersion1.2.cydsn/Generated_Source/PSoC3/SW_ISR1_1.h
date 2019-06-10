/*******************************************************************************
* File Name: SW_ISR1_1.h
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

#if !defined(CY_ISR_SW_ISR1_1_H)
#define CY_ISR_SW_ISR1_1_H

#include <cytypes.h>
#include <cyfitter.h>

/* Interrupt Controller API. */
void SW_ISR1_1_Start(void) ;
void SW_ISR1_1_StartEx(cyisraddress address) ;
void SW_ISR1_1_Stop(void) ;

CY_ISR_PROTO(SW_ISR1_1_Interrupt);

void SW_ISR1_1_SetVector(cyisraddress address) ;
cyisraddress SW_ISR1_1_GetVector(void) ;

void SW_ISR1_1_SetPriority(uint8 priority) ;
uint8 SW_ISR1_1_GetPriority(void) ;

void SW_ISR1_1_Enable(void) ;
uint8 SW_ISR1_1_GetState(void) ;
void SW_ISR1_1_Disable(void) ;

void SW_ISR1_1_SetPending(void) ;
void SW_ISR1_1_ClearPending(void) ;


/* Interrupt Controller Constants */

/* Address of the INTC.VECT[x] register that contains the Address of the SW_ISR1_1 ISR. */
#define SW_ISR1_1_INTC_VECTOR            ((reg16 *) SW_ISR1_1__INTC_VECT)

/* Address of the SW_ISR1_1 ISR priority. */
#define SW_ISR1_1_INTC_PRIOR             ((reg8 *) SW_ISR1_1__INTC_PRIOR_REG)

/* Priority of the SW_ISR1_1 interrupt. */
#define SW_ISR1_1_INTC_PRIOR_NUMBER      SW_ISR1_1__INTC_PRIOR_NUM

/* Address of the INTC.SET_EN[x] byte to bit enable SW_ISR1_1 interrupt. */
#define SW_ISR1_1_INTC_SET_EN            ((reg8 *) SW_ISR1_1__INTC_SET_EN_REG)

/* Address of the INTC.CLR_EN[x] register to bit clear the SW_ISR1_1 interrupt. */
#define SW_ISR1_1_INTC_CLR_EN            ((reg8 *) SW_ISR1_1__INTC_CLR_EN_REG)

/* Address of the INTC.SET_PD[x] register to set the SW_ISR1_1 interrupt state to pending. */
#define SW_ISR1_1_INTC_SET_PD            ((reg8 *) SW_ISR1_1__INTC_SET_PD_REG)

/* Address of the INTC.CLR_PD[x] register to clear the SW_ISR1_1 interrupt. */
#define SW_ISR1_1_INTC_CLR_PD            ((reg8 *) SW_ISR1_1__INTC_CLR_PD_REG)



#endif /* CY_ISR_SW_ISR1_1_H */


/* [] END OF FILE */
