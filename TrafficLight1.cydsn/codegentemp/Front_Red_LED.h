/*******************************************************************************
* File Name: Front_Red_LED.h  
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

#if !defined(CY_PINS_Front_Red_LED_H) /* Pins Front_Red_LED_H */
#define CY_PINS_Front_Red_LED_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "Front_Red_LED_aliases.h"


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    Front_Red_LED_Write(uint8 value) ;
void    Front_Red_LED_SetDriveMode(uint8 mode) ;
uint8   Front_Red_LED_ReadDataReg(void) ;
uint8   Front_Red_LED_Read(void) ;
void    Front_Red_LED_SetInterruptMode(uint16 position, uint16 mode) ;
uint8   Front_Red_LED_ClearInterrupt(void) ;
/** @} general */

/***************************************
*           API Constants        
***************************************/

/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the Front_Red_LED_SetDriveMode() function.
     *  @{
     */
        /* Drive Modes */
        #define Front_Red_LED_DM_ALG_HIZ         PIN_DM_ALG_HIZ   /**< \brief High Impedance Analog   */
        #define Front_Red_LED_DM_DIG_HIZ         PIN_DM_DIG_HIZ   /**< \brief High Impedance Digital  */
        #define Front_Red_LED_DM_RES_UP          PIN_DM_RES_UP    /**< \brief Resistive Pull Up       */
        #define Front_Red_LED_DM_RES_DWN         PIN_DM_RES_DWN   /**< \brief Resistive Pull Down     */
        #define Front_Red_LED_DM_OD_LO           PIN_DM_OD_LO     /**< \brief Open Drain, Drives Low  */
        #define Front_Red_LED_DM_OD_HI           PIN_DM_OD_HI     /**< \brief Open Drain, Drives High */
        #define Front_Red_LED_DM_STRONG          PIN_DM_STRONG    /**< \brief Strong Drive            */
        #define Front_Red_LED_DM_RES_UPDWN       PIN_DM_RES_UPDWN /**< \brief Resistive Pull Up/Down  */
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define Front_Red_LED_MASK               Front_Red_LED__MASK
#define Front_Red_LED_SHIFT              Front_Red_LED__SHIFT
#define Front_Red_LED_WIDTH              1u

/* Interrupt constants */
#if defined(Front_Red_LED__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in Front_Red_LED_SetInterruptMode() function.
     *  @{
     */
        #define Front_Red_LED_INTR_NONE      (uint16)(0x0000u)   /**< \brief Disabled             */
        #define Front_Red_LED_INTR_RISING    (uint16)(0x0001u)   /**< \brief Rising edge trigger  */
        #define Front_Red_LED_INTR_FALLING   (uint16)(0x0002u)   /**< \brief Falling edge trigger */
        #define Front_Red_LED_INTR_BOTH      (uint16)(0x0003u)   /**< \brief Both edge trigger    */
        /** @} intrMode */
/** @} group_constants */

    #define Front_Red_LED_INTR_MASK      (0x01u)
#endif /* (Front_Red_LED__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define Front_Red_LED_PS                     (* (reg8 *) Front_Red_LED__PS)
/* Data Register */
#define Front_Red_LED_DR                     (* (reg8 *) Front_Red_LED__DR)
/* Port Number */
#define Front_Red_LED_PRT_NUM                (* (reg8 *) Front_Red_LED__PRT) 
/* Connect to Analog Globals */                                                  
#define Front_Red_LED_AG                     (* (reg8 *) Front_Red_LED__AG)                       
/* Analog MUX bux enable */
#define Front_Red_LED_AMUX                   (* (reg8 *) Front_Red_LED__AMUX) 
/* Bidirectional Enable */                                                        
#define Front_Red_LED_BIE                    (* (reg8 *) Front_Red_LED__BIE)
/* Bit-mask for Aliased Register Access */
#define Front_Red_LED_BIT_MASK               (* (reg8 *) Front_Red_LED__BIT_MASK)
/* Bypass Enable */
#define Front_Red_LED_BYP                    (* (reg8 *) Front_Red_LED__BYP)
/* Port wide control signals */                                                   
#define Front_Red_LED_CTL                    (* (reg8 *) Front_Red_LED__CTL)
/* Drive Modes */
#define Front_Red_LED_DM0                    (* (reg8 *) Front_Red_LED__DM0) 
#define Front_Red_LED_DM1                    (* (reg8 *) Front_Red_LED__DM1)
#define Front_Red_LED_DM2                    (* (reg8 *) Front_Red_LED__DM2) 
/* Input Buffer Disable Override */
#define Front_Red_LED_INP_DIS                (* (reg8 *) Front_Red_LED__INP_DIS)
/* LCD Common or Segment Drive */
#define Front_Red_LED_LCD_COM_SEG            (* (reg8 *) Front_Red_LED__LCD_COM_SEG)
/* Enable Segment LCD */
#define Front_Red_LED_LCD_EN                 (* (reg8 *) Front_Red_LED__LCD_EN)
/* Slew Rate Control */
#define Front_Red_LED_SLW                    (* (reg8 *) Front_Red_LED__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define Front_Red_LED_PRTDSI__CAPS_SEL       (* (reg8 *) Front_Red_LED__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define Front_Red_LED_PRTDSI__DBL_SYNC_IN    (* (reg8 *) Front_Red_LED__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define Front_Red_LED_PRTDSI__OE_SEL0        (* (reg8 *) Front_Red_LED__PRTDSI__OE_SEL0) 
#define Front_Red_LED_PRTDSI__OE_SEL1        (* (reg8 *) Front_Red_LED__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define Front_Red_LED_PRTDSI__OUT_SEL0       (* (reg8 *) Front_Red_LED__PRTDSI__OUT_SEL0) 
#define Front_Red_LED_PRTDSI__OUT_SEL1       (* (reg8 *) Front_Red_LED__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define Front_Red_LED_PRTDSI__SYNC_OUT       (* (reg8 *) Front_Red_LED__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(Front_Red_LED__SIO_CFG)
    #define Front_Red_LED_SIO_HYST_EN        (* (reg8 *) Front_Red_LED__SIO_HYST_EN)
    #define Front_Red_LED_SIO_REG_HIFREQ     (* (reg8 *) Front_Red_LED__SIO_REG_HIFREQ)
    #define Front_Red_LED_SIO_CFG            (* (reg8 *) Front_Red_LED__SIO_CFG)
    #define Front_Red_LED_SIO_DIFF           (* (reg8 *) Front_Red_LED__SIO_DIFF)
#endif /* (Front_Red_LED__SIO_CFG) */

/* Interrupt Registers */
#if defined(Front_Red_LED__INTSTAT)
    #define Front_Red_LED_INTSTAT             (* (reg8 *) Front_Red_LED__INTSTAT)
    #define Front_Red_LED_SNAP                (* (reg8 *) Front_Red_LED__SNAP)
    
	#define Front_Red_LED_0_INTTYPE_REG 		(* (reg8 *) Front_Red_LED__0__INTTYPE)
#endif /* (Front_Red_LED__INTSTAT) */

#endif /* End Pins Front_Red_LED_H */


/* [] END OF FILE */
