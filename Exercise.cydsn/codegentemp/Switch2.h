/*******************************************************************************
* File Name: Switch2.h  
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

#if !defined(CY_PINS_Switch2_H) /* Pins Switch2_H */
#define CY_PINS_Switch2_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "Switch2_aliases.h"


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    Switch2_Write(uint8 value) ;
void    Switch2_SetDriveMode(uint8 mode) ;
uint8   Switch2_ReadDataReg(void) ;
uint8   Switch2_Read(void) ;
void    Switch2_SetInterruptMode(uint16 position, uint16 mode) ;
uint8   Switch2_ClearInterrupt(void) ;
/** @} general */

/***************************************
*           API Constants        
***************************************/

/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the Switch2_SetDriveMode() function.
     *  @{
     */
        /* Drive Modes */
        #define Switch2_DM_ALG_HIZ         PIN_DM_ALG_HIZ   /**< \brief High Impedance Analog   */
        #define Switch2_DM_DIG_HIZ         PIN_DM_DIG_HIZ   /**< \brief High Impedance Digital  */
        #define Switch2_DM_RES_UP          PIN_DM_RES_UP    /**< \brief Resistive Pull Up       */
        #define Switch2_DM_RES_DWN         PIN_DM_RES_DWN   /**< \brief Resistive Pull Down     */
        #define Switch2_DM_OD_LO           PIN_DM_OD_LO     /**< \brief Open Drain, Drives Low  */
        #define Switch2_DM_OD_HI           PIN_DM_OD_HI     /**< \brief Open Drain, Drives High */
        #define Switch2_DM_STRONG          PIN_DM_STRONG    /**< \brief Strong Drive            */
        #define Switch2_DM_RES_UPDWN       PIN_DM_RES_UPDWN /**< \brief Resistive Pull Up/Down  */
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define Switch2_MASK               Switch2__MASK
#define Switch2_SHIFT              Switch2__SHIFT
#define Switch2_WIDTH              1u

/* Interrupt constants */
#if defined(Switch2__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in Switch2_SetInterruptMode() function.
     *  @{
     */
        #define Switch2_INTR_NONE      (uint16)(0x0000u)   /**< \brief Disabled             */
        #define Switch2_INTR_RISING    (uint16)(0x0001u)   /**< \brief Rising edge trigger  */
        #define Switch2_INTR_FALLING   (uint16)(0x0002u)   /**< \brief Falling edge trigger */
        #define Switch2_INTR_BOTH      (uint16)(0x0003u)   /**< \brief Both edge trigger    */
        /** @} intrMode */
/** @} group_constants */

    #define Switch2_INTR_MASK      (0x01u)
#endif /* (Switch2__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define Switch2_PS                     (* (reg8 *) Switch2__PS)
/* Data Register */
#define Switch2_DR                     (* (reg8 *) Switch2__DR)
/* Port Number */
#define Switch2_PRT_NUM                (* (reg8 *) Switch2__PRT) 
/* Connect to Analog Globals */                                                  
#define Switch2_AG                     (* (reg8 *) Switch2__AG)                       
/* Analog MUX bux enable */
#define Switch2_AMUX                   (* (reg8 *) Switch2__AMUX) 
/* Bidirectional Enable */                                                        
#define Switch2_BIE                    (* (reg8 *) Switch2__BIE)
/* Bit-mask for Aliased Register Access */
#define Switch2_BIT_MASK               (* (reg8 *) Switch2__BIT_MASK)
/* Bypass Enable */
#define Switch2_BYP                    (* (reg8 *) Switch2__BYP)
/* Port wide control signals */                                                   
#define Switch2_CTL                    (* (reg8 *) Switch2__CTL)
/* Drive Modes */
#define Switch2_DM0                    (* (reg8 *) Switch2__DM0) 
#define Switch2_DM1                    (* (reg8 *) Switch2__DM1)
#define Switch2_DM2                    (* (reg8 *) Switch2__DM2) 
/* Input Buffer Disable Override */
#define Switch2_INP_DIS                (* (reg8 *) Switch2__INP_DIS)
/* LCD Common or Segment Drive */
#define Switch2_LCD_COM_SEG            (* (reg8 *) Switch2__LCD_COM_SEG)
/* Enable Segment LCD */
#define Switch2_LCD_EN                 (* (reg8 *) Switch2__LCD_EN)
/* Slew Rate Control */
#define Switch2_SLW                    (* (reg8 *) Switch2__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define Switch2_PRTDSI__CAPS_SEL       (* (reg8 *) Switch2__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define Switch2_PRTDSI__DBL_SYNC_IN    (* (reg8 *) Switch2__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define Switch2_PRTDSI__OE_SEL0        (* (reg8 *) Switch2__PRTDSI__OE_SEL0) 
#define Switch2_PRTDSI__OE_SEL1        (* (reg8 *) Switch2__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define Switch2_PRTDSI__OUT_SEL0       (* (reg8 *) Switch2__PRTDSI__OUT_SEL0) 
#define Switch2_PRTDSI__OUT_SEL1       (* (reg8 *) Switch2__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define Switch2_PRTDSI__SYNC_OUT       (* (reg8 *) Switch2__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(Switch2__SIO_CFG)
    #define Switch2_SIO_HYST_EN        (* (reg8 *) Switch2__SIO_HYST_EN)
    #define Switch2_SIO_REG_HIFREQ     (* (reg8 *) Switch2__SIO_REG_HIFREQ)
    #define Switch2_SIO_CFG            (* (reg8 *) Switch2__SIO_CFG)
    #define Switch2_SIO_DIFF           (* (reg8 *) Switch2__SIO_DIFF)
#endif /* (Switch2__SIO_CFG) */

/* Interrupt Registers */
#if defined(Switch2__INTSTAT)
    #define Switch2_INTSTAT             (* (reg8 *) Switch2__INTSTAT)
    #define Switch2_SNAP                (* (reg8 *) Switch2__SNAP)
    
	#define Switch2_0_INTTYPE_REG 		(* (reg8 *) Switch2__0__INTTYPE)
#endif /* (Switch2__INTSTAT) */

#endif /* End Pins Switch2_H */


/* [] END OF FILE */
