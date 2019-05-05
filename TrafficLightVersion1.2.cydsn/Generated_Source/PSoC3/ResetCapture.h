/*******************************************************************************
* File Name: ResetCapture.h
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

#if !defined(CY_ISR_ResetCapture_H)
#define CY_ISR_ResetCapture_H

#include <cytypes.h>
#include <cyfitter.h>

/* Interrupt Controller API. */
void ResetCapture_Start(void) ;
void ResetCapture_StartEx(cyisraddress address) ;
void ResetCapture_Stop(void) ;

CY_ISR_PROTO(ResetCapture_Interrupt);

void ResetCapture_SetVector(cyisraddress address) ;
cyisraddress ResetCapture_GetVector(void) ;

void ResetCapture_SetPriority(uint8 priority) ;
uint8 ResetCapture_GetPriority(void) ;

void ResetCapture_Enable(void) ;
uint8 ResetCapture_GetState(void) ;
void ResetCapture_Disable(void) ;

void ResetCapture_SetPending(void) ;
void ResetCapture_ClearPending(void) ;


/* Interrupt Controller Constants */

/* Address of the INTC.VECT[x] register that contains the Address of the ResetCapture ISR. */
#define ResetCapture_INTC_VECTOR            ((reg16 *) ResetCapture__INTC_VECT)

/* Address of the ResetCapture ISR priority. */
#define ResetCapture_INTC_PRIOR             ((reg8 *) ResetCapture__INTC_PRIOR_REG)

/* Priority of the ResetCapture interrupt. */
#define ResetCapture_INTC_PRIOR_NUMBER      ResetCapture__INTC_PRIOR_NUM

/* Address of the INTC.SET_EN[x] byte to bit enable ResetCapture interrupt. */
#define ResetCapture_INTC_SET_EN            ((reg8 *) ResetCapture__INTC_SET_EN_REG)

/* Address of the INTC.CLR_EN[x] register to bit clear the ResetCapture interrupt. */
#define ResetCapture_INTC_CLR_EN            ((reg8 *) ResetCapture__INTC_CLR_EN_REG)

/* Address of the INTC.SET_PD[x] register to set the ResetCapture interrupt state to pending. */
#define ResetCapture_INTC_SET_PD            ((reg8 *) ResetCapture__INTC_SET_PD_REG)

/* Address of the INTC.CLR_PD[x] register to clear the ResetCapture interrupt. */
#define ResetCapture_INTC_CLR_PD            ((reg8 *) ResetCapture__INTC_CLR_PD_REG)



#endif /* CY_ISR_ResetCapture_H */


/* [] END OF FILE */
