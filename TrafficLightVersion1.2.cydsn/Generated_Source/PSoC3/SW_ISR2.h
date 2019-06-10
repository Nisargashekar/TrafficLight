/*******************************************************************************
* File Name: SW_ISR2.h
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

#if !defined(CY_ISR_SW_ISR2_H)
#define CY_ISR_SW_ISR2_H

#include <cytypes.h>
#include <cyfitter.h>

/* Interrupt Controller API. */
void SW_ISR2_Start(void) ;
void SW_ISR2_StartEx(cyisraddress address) ;
void SW_ISR2_Stop(void) ;

CY_ISR_PROTO(SW_ISR2_Interrupt);

void SW_ISR2_SetVector(cyisraddress address) ;
cyisraddress SW_ISR2_GetVector(void) ;

void SW_ISR2_SetPriority(uint8 priority) ;
uint8 SW_ISR2_GetPriority(void) ;

void SW_ISR2_Enable(void) ;
uint8 SW_ISR2_GetState(void) ;
void SW_ISR2_Disable(void) ;

void SW_ISR2_SetPending(void) ;
void SW_ISR2_ClearPending(void) ;


/* Interrupt Controller Constants */

/* Address of the INTC.VECT[x] register that contains the Address of the SW_ISR2 ISR. */
#define SW_ISR2_INTC_VECTOR            ((reg16 *) SW_ISR2__INTC_VECT)

/* Address of the SW_ISR2 ISR priority. */
#define SW_ISR2_INTC_PRIOR             ((reg8 *) SW_ISR2__INTC_PRIOR_REG)

/* Priority of the SW_ISR2 interrupt. */
#define SW_ISR2_INTC_PRIOR_NUMBER      SW_ISR2__INTC_PRIOR_NUM

/* Address of the INTC.SET_EN[x] byte to bit enable SW_ISR2 interrupt. */
#define SW_ISR2_INTC_SET_EN            ((reg8 *) SW_ISR2__INTC_SET_EN_REG)

/* Address of the INTC.CLR_EN[x] register to bit clear the SW_ISR2 interrupt. */
#define SW_ISR2_INTC_CLR_EN            ((reg8 *) SW_ISR2__INTC_CLR_EN_REG)

/* Address of the INTC.SET_PD[x] register to set the SW_ISR2 interrupt state to pending. */
#define SW_ISR2_INTC_SET_PD            ((reg8 *) SW_ISR2__INTC_SET_PD_REG)

/* Address of the INTC.CLR_PD[x] register to clear the SW_ISR2 interrupt. */
#define SW_ISR2_INTC_CLR_PD            ((reg8 *) SW_ISR2__INTC_CLR_PD_REG)



#endif /* CY_ISR_SW_ISR2_H */


/* [] END OF FILE */
