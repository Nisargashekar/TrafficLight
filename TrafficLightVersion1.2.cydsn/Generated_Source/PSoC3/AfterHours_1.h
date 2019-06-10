/*******************************************************************************
* File Name: AfterHours_1.h  
* Version 2.20
*
* Description:
*  This file contains Pin function prototypes and register defines
*
* Note:
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_PINS_AfterHours_1_H) /* Pins AfterHours_1_H */
#define CY_PINS_AfterHours_1_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "AfterHours_1_aliases.h"


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    AfterHours_1_Write(uint8 value) ;
void    AfterHours_1_SetDriveMode(uint8 mode) ;
uint8   AfterHours_1_ReadDataReg(void) ;
uint8   AfterHours_1_Read(void) ;
void    AfterHours_1_SetInterruptMode(uint16 position, uint16 mode) ;
uint8   AfterHours_1_ClearInterrupt(void) ;
/** @} general */

/***************************************
*           API Constants        
***************************************/

/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the AfterHours_1_SetDriveMode() function.
     *  @{
     */
        /* Drive Modes */
        #define AfterHours_1_DM_ALG_HIZ         PIN_DM_ALG_HIZ   /**< \brief High Impedance Analog   */
        #define AfterHours_1_DM_DIG_HIZ         PIN_DM_DIG_HIZ   /**< \brief High Impedance Digital  */
        #define AfterHours_1_DM_RES_UP          PIN_DM_RES_UP    /**< \brief Resistive Pull Up       */
        #define AfterHours_1_DM_RES_DWN         PIN_DM_RES_DWN   /**< \brief Resistive Pull Down     */
        #define AfterHours_1_DM_OD_LO           PIN_DM_OD_LO     /**< \brief Open Drain, Drives Low  */
        #define AfterHours_1_DM_OD_HI           PIN_DM_OD_HI     /**< \brief Open Drain, Drives High */
        #define AfterHours_1_DM_STRONG          PIN_DM_STRONG    /**< \brief Strong Drive            */
        #define AfterHours_1_DM_RES_UPDWN       PIN_DM_RES_UPDWN /**< \brief Resistive Pull Up/Down  */
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define AfterHours_1_MASK               AfterHours_1__MASK
#define AfterHours_1_SHIFT              AfterHours_1__SHIFT
#define AfterHours_1_WIDTH              1u

/* Interrupt constants */
#if defined(AfterHours_1__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in AfterHours_1_SetInterruptMode() function.
     *  @{
     */
        #define AfterHours_1_INTR_NONE      (uint16)(0x0000u)   /**< \brief Disabled             */
        #define AfterHours_1_INTR_RISING    (uint16)(0x0001u)   /**< \brief Rising edge trigger  */
        #define AfterHours_1_INTR_FALLING   (uint16)(0x0002u)   /**< \brief Falling edge trigger */
        #define AfterHours_1_INTR_BOTH      (uint16)(0x0003u)   /**< \brief Both edge trigger    */
        /** @} intrMode */
/** @} group_constants */

    #define AfterHours_1_INTR_MASK      (0x01u)
#endif /* (AfterHours_1__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define AfterHours_1_PS                     (* (reg8 *) AfterHours_1__PS)
/* Data Register */
#define AfterHours_1_DR                     (* (reg8 *) AfterHours_1__DR)
/* Port Number */
#define AfterHours_1_PRT_NUM                (* (reg8 *) AfterHours_1__PRT) 
/* Connect to Analog Globals */                                                  
#define AfterHours_1_AG                     (* (reg8 *) AfterHours_1__AG)                       
/* Analog MUX bux enable */
#define AfterHours_1_AMUX                   (* (reg8 *) AfterHours_1__AMUX) 
/* Bidirectional Enable */                                                        
#define AfterHours_1_BIE                    (* (reg8 *) AfterHours_1__BIE)
/* Bit-mask for Aliased Register Access */
#define AfterHours_1_BIT_MASK               (* (reg8 *) AfterHours_1__BIT_MASK)
/* Bypass Enable */
#define AfterHours_1_BYP                    (* (reg8 *) AfterHours_1__BYP)
/* Port wide control signals */                                                   
#define AfterHours_1_CTL                    (* (reg8 *) AfterHours_1__CTL)
/* Drive Modes */
#define AfterHours_1_DM0                    (* (reg8 *) AfterHours_1__DM0) 
#define AfterHours_1_DM1                    (* (reg8 *) AfterHours_1__DM1)
#define AfterHours_1_DM2                    (* (reg8 *) AfterHours_1__DM2) 
/* Input Buffer Disable Override */
#define AfterHours_1_INP_DIS                (* (reg8 *) AfterHours_1__INP_DIS)
/* LCD Common or Segment Drive */
#define AfterHours_1_LCD_COM_SEG            (* (reg8 *) AfterHours_1__LCD_COM_SEG)
/* Enable Segment LCD */
#define AfterHours_1_LCD_EN                 (* (reg8 *) AfterHours_1__LCD_EN)
/* Slew Rate Control */
#define AfterHours_1_SLW                    (* (reg8 *) AfterHours_1__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define AfterHours_1_PRTDSI__CAPS_SEL       (* (reg8 *) AfterHours_1__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define AfterHours_1_PRTDSI__DBL_SYNC_IN    (* (reg8 *) AfterHours_1__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define AfterHours_1_PRTDSI__OE_SEL0        (* (reg8 *) AfterHours_1__PRTDSI__OE_SEL0) 
#define AfterHours_1_PRTDSI__OE_SEL1        (* (reg8 *) AfterHours_1__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define AfterHours_1_PRTDSI__OUT_SEL0       (* (reg8 *) AfterHours_1__PRTDSI__OUT_SEL0) 
#define AfterHours_1_PRTDSI__OUT_SEL1       (* (reg8 *) AfterHours_1__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define AfterHours_1_PRTDSI__SYNC_OUT       (* (reg8 *) AfterHours_1__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(AfterHours_1__SIO_CFG)
    #define AfterHours_1_SIO_HYST_EN        (* (reg8 *) AfterHours_1__SIO_HYST_EN)
    #define AfterHours_1_SIO_REG_HIFREQ     (* (reg8 *) AfterHours_1__SIO_REG_HIFREQ)
    #define AfterHours_1_SIO_CFG            (* (reg8 *) AfterHours_1__SIO_CFG)
    #define AfterHours_1_SIO_DIFF           (* (reg8 *) AfterHours_1__SIO_DIFF)
#endif /* (AfterHours_1__SIO_CFG) */

/* Interrupt Registers */
#if defined(AfterHours_1__INTSTAT)
    #define AfterHours_1_INTSTAT             (* (reg8 *) AfterHours_1__INTSTAT)
    #define AfterHours_1_SNAP                (* (reg8 *) AfterHours_1__SNAP)
    
	#define AfterHours_1_0_INTTYPE_REG 		(* (reg8 *) AfterHours_1__0__INTTYPE)
#endif /* (AfterHours_1__INTSTAT) */

#endif /* End Pins AfterHours_1_H */


/* [] END OF FILE */
