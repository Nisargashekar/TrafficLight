/*******************************************************************************
* File Name: Setting_mode.h  
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

#if !defined(CY_PINS_Setting_mode_H) /* Pins Setting_mode_H */
#define CY_PINS_Setting_mode_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "Setting_mode_aliases.h"


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    Setting_mode_Write(uint8 value) ;
void    Setting_mode_SetDriveMode(uint8 mode) ;
uint8   Setting_mode_ReadDataReg(void) ;
uint8   Setting_mode_Read(void) ;
void    Setting_mode_SetInterruptMode(uint16 position, uint16 mode) ;
uint8   Setting_mode_ClearInterrupt(void) ;
/** @} general */

/***************************************
*           API Constants        
***************************************/

/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the Setting_mode_SetDriveMode() function.
     *  @{
     */
        /* Drive Modes */
        #define Setting_mode_DM_ALG_HIZ         PIN_DM_ALG_HIZ   /**< \brief High Impedance Analog   */
        #define Setting_mode_DM_DIG_HIZ         PIN_DM_DIG_HIZ   /**< \brief High Impedance Digital  */
        #define Setting_mode_DM_RES_UP          PIN_DM_RES_UP    /**< \brief Resistive Pull Up       */
        #define Setting_mode_DM_RES_DWN         PIN_DM_RES_DWN   /**< \brief Resistive Pull Down     */
        #define Setting_mode_DM_OD_LO           PIN_DM_OD_LO     /**< \brief Open Drain, Drives Low  */
        #define Setting_mode_DM_OD_HI           PIN_DM_OD_HI     /**< \brief Open Drain, Drives High */
        #define Setting_mode_DM_STRONG          PIN_DM_STRONG    /**< \brief Strong Drive            */
        #define Setting_mode_DM_RES_UPDWN       PIN_DM_RES_UPDWN /**< \brief Resistive Pull Up/Down  */
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define Setting_mode_MASK               Setting_mode__MASK
#define Setting_mode_SHIFT              Setting_mode__SHIFT
#define Setting_mode_WIDTH              1u

/* Interrupt constants */
#if defined(Setting_mode__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in Setting_mode_SetInterruptMode() function.
     *  @{
     */
        #define Setting_mode_INTR_NONE      (uint16)(0x0000u)   /**< \brief Disabled             */
        #define Setting_mode_INTR_RISING    (uint16)(0x0001u)   /**< \brief Rising edge trigger  */
        #define Setting_mode_INTR_FALLING   (uint16)(0x0002u)   /**< \brief Falling edge trigger */
        #define Setting_mode_INTR_BOTH      (uint16)(0x0003u)   /**< \brief Both edge trigger    */
        /** @} intrMode */
/** @} group_constants */

    #define Setting_mode_INTR_MASK      (0x01u)
#endif /* (Setting_mode__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define Setting_mode_PS                     (* (reg8 *) Setting_mode__PS)
/* Data Register */
#define Setting_mode_DR                     (* (reg8 *) Setting_mode__DR)
/* Port Number */
#define Setting_mode_PRT_NUM                (* (reg8 *) Setting_mode__PRT) 
/* Connect to Analog Globals */                                                  
#define Setting_mode_AG                     (* (reg8 *) Setting_mode__AG)                       
/* Analog MUX bux enable */
#define Setting_mode_AMUX                   (* (reg8 *) Setting_mode__AMUX) 
/* Bidirectional Enable */                                                        
#define Setting_mode_BIE                    (* (reg8 *) Setting_mode__BIE)
/* Bit-mask for Aliased Register Access */
#define Setting_mode_BIT_MASK               (* (reg8 *) Setting_mode__BIT_MASK)
/* Bypass Enable */
#define Setting_mode_BYP                    (* (reg8 *) Setting_mode__BYP)
/* Port wide control signals */                                                   
#define Setting_mode_CTL                    (* (reg8 *) Setting_mode__CTL)
/* Drive Modes */
#define Setting_mode_DM0                    (* (reg8 *) Setting_mode__DM0) 
#define Setting_mode_DM1                    (* (reg8 *) Setting_mode__DM1)
#define Setting_mode_DM2                    (* (reg8 *) Setting_mode__DM2) 
/* Input Buffer Disable Override */
#define Setting_mode_INP_DIS                (* (reg8 *) Setting_mode__INP_DIS)
/* LCD Common or Segment Drive */
#define Setting_mode_LCD_COM_SEG            (* (reg8 *) Setting_mode__LCD_COM_SEG)
/* Enable Segment LCD */
#define Setting_mode_LCD_EN                 (* (reg8 *) Setting_mode__LCD_EN)
/* Slew Rate Control */
#define Setting_mode_SLW                    (* (reg8 *) Setting_mode__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define Setting_mode_PRTDSI__CAPS_SEL       (* (reg8 *) Setting_mode__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define Setting_mode_PRTDSI__DBL_SYNC_IN    (* (reg8 *) Setting_mode__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define Setting_mode_PRTDSI__OE_SEL0        (* (reg8 *) Setting_mode__PRTDSI__OE_SEL0) 
#define Setting_mode_PRTDSI__OE_SEL1        (* (reg8 *) Setting_mode__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define Setting_mode_PRTDSI__OUT_SEL0       (* (reg8 *) Setting_mode__PRTDSI__OUT_SEL0) 
#define Setting_mode_PRTDSI__OUT_SEL1       (* (reg8 *) Setting_mode__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define Setting_mode_PRTDSI__SYNC_OUT       (* (reg8 *) Setting_mode__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(Setting_mode__SIO_CFG)
    #define Setting_mode_SIO_HYST_EN        (* (reg8 *) Setting_mode__SIO_HYST_EN)
    #define Setting_mode_SIO_REG_HIFREQ     (* (reg8 *) Setting_mode__SIO_REG_HIFREQ)
    #define Setting_mode_SIO_CFG            (* (reg8 *) Setting_mode__SIO_CFG)
    #define Setting_mode_SIO_DIFF           (* (reg8 *) Setting_mode__SIO_DIFF)
#endif /* (Setting_mode__SIO_CFG) */

/* Interrupt Registers */
#if defined(Setting_mode__INTSTAT)
    #define Setting_mode_INTSTAT             (* (reg8 *) Setting_mode__INTSTAT)
    #define Setting_mode_SNAP                (* (reg8 *) Setting_mode__SNAP)
    
	#define Setting_mode_0_INTTYPE_REG 		(* (reg8 *) Setting_mode__0__INTTYPE)
#endif /* (Setting_mode__INTSTAT) */

#endif /* End Pins Setting_mode_H */


/* [] END OF FILE */
