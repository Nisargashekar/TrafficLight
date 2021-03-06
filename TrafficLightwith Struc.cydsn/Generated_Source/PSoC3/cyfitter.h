/*******************************************************************************
* File Name: cyfitter.h
* 
* PSoC Creator  4.2
*
* Description:
* 
* This file is automatically generated by PSoC Creator.
*
********************************************************************************
* Copyright (c) 2007-2018 Cypress Semiconductor.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
********************************************************************************/

#ifndef INCLUDED_CYFITTER_H
#define INCLUDED_CYFITTER_H
#include "cydevice.h"
#include "cydevice_trm.h"

/* LCD */
#define LCD_LCDPort__0__INTTYPE CYREG_PICU2_INTTYPE0
#define LCD_LCDPort__0__MASK 0x01u
#define LCD_LCDPort__0__PC CYREG_PRT2_PC0
#define LCD_LCDPort__0__PORT 2u
#define LCD_LCDPort__0__SHIFT 0u
#define LCD_LCDPort__1__INTTYPE CYREG_PICU2_INTTYPE1
#define LCD_LCDPort__1__MASK 0x02u
#define LCD_LCDPort__1__PC CYREG_PRT2_PC1
#define LCD_LCDPort__1__PORT 2u
#define LCD_LCDPort__1__SHIFT 1u
#define LCD_LCDPort__2__INTTYPE CYREG_PICU2_INTTYPE2
#define LCD_LCDPort__2__MASK 0x04u
#define LCD_LCDPort__2__PC CYREG_PRT2_PC2
#define LCD_LCDPort__2__PORT 2u
#define LCD_LCDPort__2__SHIFT 2u
#define LCD_LCDPort__3__INTTYPE CYREG_PICU2_INTTYPE3
#define LCD_LCDPort__3__MASK 0x08u
#define LCD_LCDPort__3__PC CYREG_PRT2_PC3
#define LCD_LCDPort__3__PORT 2u
#define LCD_LCDPort__3__SHIFT 3u
#define LCD_LCDPort__4__INTTYPE CYREG_PICU2_INTTYPE4
#define LCD_LCDPort__4__MASK 0x10u
#define LCD_LCDPort__4__PC CYREG_PRT2_PC4
#define LCD_LCDPort__4__PORT 2u
#define LCD_LCDPort__4__SHIFT 4u
#define LCD_LCDPort__5__INTTYPE CYREG_PICU2_INTTYPE5
#define LCD_LCDPort__5__MASK 0x20u
#define LCD_LCDPort__5__PC CYREG_PRT2_PC5
#define LCD_LCDPort__5__PORT 2u
#define LCD_LCDPort__5__SHIFT 5u
#define LCD_LCDPort__6__INTTYPE CYREG_PICU2_INTTYPE6
#define LCD_LCDPort__6__MASK 0x40u
#define LCD_LCDPort__6__PC CYREG_PRT2_PC6
#define LCD_LCDPort__6__PORT 2u
#define LCD_LCDPort__6__SHIFT 6u
#define LCD_LCDPort__AG CYREG_PRT2_AG
#define LCD_LCDPort__AMUX CYREG_PRT2_AMUX
#define LCD_LCDPort__BIE CYREG_PRT2_BIE
#define LCD_LCDPort__BIT_MASK CYREG_PRT2_BIT_MASK
#define LCD_LCDPort__BYP CYREG_PRT2_BYP
#define LCD_LCDPort__CTL CYREG_PRT2_CTL
#define LCD_LCDPort__DM0 CYREG_PRT2_DM0
#define LCD_LCDPort__DM1 CYREG_PRT2_DM1
#define LCD_LCDPort__DM2 CYREG_PRT2_DM2
#define LCD_LCDPort__DR CYREG_PRT2_DR
#define LCD_LCDPort__INP_DIS CYREG_PRT2_INP_DIS
#define LCD_LCDPort__INTTYPE_BASE CYDEV_PICU_INTTYPE_PICU2_BASE
#define LCD_LCDPort__LCD_COM_SEG CYREG_PRT2_LCD_COM_SEG
#define LCD_LCDPort__LCD_EN CYREG_PRT2_LCD_EN
#define LCD_LCDPort__MASK 0x7Fu
#define LCD_LCDPort__PORT 2u
#define LCD_LCDPort__PRT CYREG_PRT2_PRT
#define LCD_LCDPort__PRTDSI__CAPS_SEL CYREG_PRT2_CAPS_SEL
#define LCD_LCDPort__PRTDSI__DBL_SYNC_IN CYREG_PRT2_DBL_SYNC_IN
#define LCD_LCDPort__PRTDSI__OE_SEL0 CYREG_PRT2_OE_SEL0
#define LCD_LCDPort__PRTDSI__OE_SEL1 CYREG_PRT2_OE_SEL1
#define LCD_LCDPort__PRTDSI__OUT_SEL0 CYREG_PRT2_OUT_SEL0
#define LCD_LCDPort__PRTDSI__OUT_SEL1 CYREG_PRT2_OUT_SEL1
#define LCD_LCDPort__PRTDSI__SYNC_OUT CYREG_PRT2_SYNC_OUT
#define LCD_LCDPort__PS CYREG_PRT2_PS
#define LCD_LCDPort__SHIFT 0u
#define LCD_LCDPort__SLW CYREG_PRT2_SLW

/* Red_LED */
#define Red_LED__0__INTTYPE CYREG_PICU3_INTTYPE7
#define Red_LED__0__MASK 0x80u
#define Red_LED__0__PC CYREG_PRT3_PC7
#define Red_LED__0__PORT 3u
#define Red_LED__0__SHIFT 7u
#define Red_LED__AG CYREG_PRT3_AG
#define Red_LED__AMUX CYREG_PRT3_AMUX
#define Red_LED__BIE CYREG_PRT3_BIE
#define Red_LED__BIT_MASK CYREG_PRT3_BIT_MASK
#define Red_LED__BYP CYREG_PRT3_BYP
#define Red_LED__CTL CYREG_PRT3_CTL
#define Red_LED__DM0 CYREG_PRT3_DM0
#define Red_LED__DM1 CYREG_PRT3_DM1
#define Red_LED__DM2 CYREG_PRT3_DM2
#define Red_LED__DR CYREG_PRT3_DR
#define Red_LED__INP_DIS CYREG_PRT3_INP_DIS
#define Red_LED__INTTYPE_BASE CYDEV_PICU_INTTYPE_PICU3_BASE
#define Red_LED__LCD_COM_SEG CYREG_PRT3_LCD_COM_SEG
#define Red_LED__LCD_EN CYREG_PRT3_LCD_EN
#define Red_LED__MASK 0x80u
#define Red_LED__PORT 3u
#define Red_LED__PRT CYREG_PRT3_PRT
#define Red_LED__PRTDSI__CAPS_SEL CYREG_PRT3_CAPS_SEL
#define Red_LED__PRTDSI__DBL_SYNC_IN CYREG_PRT3_DBL_SYNC_IN
#define Red_LED__PRTDSI__OE_SEL0 CYREG_PRT3_OE_SEL0
#define Red_LED__PRTDSI__OE_SEL1 CYREG_PRT3_OE_SEL1
#define Red_LED__PRTDSI__OUT_SEL0 CYREG_PRT3_OUT_SEL0
#define Red_LED__PRTDSI__OUT_SEL1 CYREG_PRT3_OUT_SEL1
#define Red_LED__PRTDSI__SYNC_OUT CYREG_PRT3_SYNC_OUT
#define Red_LED__PS CYREG_PRT3_PS
#define Red_LED__SHIFT 7u
#define Red_LED__SLW CYREG_PRT3_SLW

/* Amber_LED */
#define Amber_LED__0__INTTYPE CYREG_PICU3_INTTYPE5
#define Amber_LED__0__MASK 0x20u
#define Amber_LED__0__PC CYREG_PRT3_PC5
#define Amber_LED__0__PORT 3u
#define Amber_LED__0__SHIFT 5u
#define Amber_LED__AG CYREG_PRT3_AG
#define Amber_LED__AMUX CYREG_PRT3_AMUX
#define Amber_LED__BIE CYREG_PRT3_BIE
#define Amber_LED__BIT_MASK CYREG_PRT3_BIT_MASK
#define Amber_LED__BYP CYREG_PRT3_BYP
#define Amber_LED__CTL CYREG_PRT3_CTL
#define Amber_LED__DM0 CYREG_PRT3_DM0
#define Amber_LED__DM1 CYREG_PRT3_DM1
#define Amber_LED__DM2 CYREG_PRT3_DM2
#define Amber_LED__DR CYREG_PRT3_DR
#define Amber_LED__INP_DIS CYREG_PRT3_INP_DIS
#define Amber_LED__INTTYPE_BASE CYDEV_PICU_INTTYPE_PICU3_BASE
#define Amber_LED__LCD_COM_SEG CYREG_PRT3_LCD_COM_SEG
#define Amber_LED__LCD_EN CYREG_PRT3_LCD_EN
#define Amber_LED__MASK 0x20u
#define Amber_LED__PORT 3u
#define Amber_LED__PRT CYREG_PRT3_PRT
#define Amber_LED__PRTDSI__CAPS_SEL CYREG_PRT3_CAPS_SEL
#define Amber_LED__PRTDSI__DBL_SYNC_IN CYREG_PRT3_DBL_SYNC_IN
#define Amber_LED__PRTDSI__OE_SEL0 CYREG_PRT3_OE_SEL0
#define Amber_LED__PRTDSI__OE_SEL1 CYREG_PRT3_OE_SEL1
#define Amber_LED__PRTDSI__OUT_SEL0 CYREG_PRT3_OUT_SEL0
#define Amber_LED__PRTDSI__OUT_SEL1 CYREG_PRT3_OUT_SEL1
#define Amber_LED__PRTDSI__SYNC_OUT CYREG_PRT3_SYNC_OUT
#define Amber_LED__PS CYREG_PRT3_PS
#define Amber_LED__SHIFT 5u
#define Amber_LED__SLW CYREG_PRT3_SLW

/* Green_LED */
#define Green_LED__0__INTTYPE CYREG_PICU3_INTTYPE3
#define Green_LED__0__MASK 0x08u
#define Green_LED__0__PC CYREG_PRT3_PC3
#define Green_LED__0__PORT 3u
#define Green_LED__0__SHIFT 3u
#define Green_LED__AG CYREG_PRT3_AG
#define Green_LED__AMUX CYREG_PRT3_AMUX
#define Green_LED__BIE CYREG_PRT3_BIE
#define Green_LED__BIT_MASK CYREG_PRT3_BIT_MASK
#define Green_LED__BYP CYREG_PRT3_BYP
#define Green_LED__CTL CYREG_PRT3_CTL
#define Green_LED__DM0 CYREG_PRT3_DM0
#define Green_LED__DM1 CYREG_PRT3_DM1
#define Green_LED__DM2 CYREG_PRT3_DM2
#define Green_LED__DR CYREG_PRT3_DR
#define Green_LED__INP_DIS CYREG_PRT3_INP_DIS
#define Green_LED__INTTYPE_BASE CYDEV_PICU_INTTYPE_PICU3_BASE
#define Green_LED__LCD_COM_SEG CYREG_PRT3_LCD_COM_SEG
#define Green_LED__LCD_EN CYREG_PRT3_LCD_EN
#define Green_LED__MASK 0x08u
#define Green_LED__PORT 3u
#define Green_LED__PRT CYREG_PRT3_PRT
#define Green_LED__PRTDSI__CAPS_SEL CYREG_PRT3_CAPS_SEL
#define Green_LED__PRTDSI__DBL_SYNC_IN CYREG_PRT3_DBL_SYNC_IN
#define Green_LED__PRTDSI__OE_SEL0 CYREG_PRT3_OE_SEL0
#define Green_LED__PRTDSI__OE_SEL1 CYREG_PRT3_OE_SEL1
#define Green_LED__PRTDSI__OUT_SEL0 CYREG_PRT3_OUT_SEL0
#define Green_LED__PRTDSI__OUT_SEL1 CYREG_PRT3_OUT_SEL1
#define Green_LED__PRTDSI__SYNC_OUT CYREG_PRT3_SYNC_OUT
#define Green_LED__PS CYREG_PRT3_PS
#define Green_LED__SHIFT 3u
#define Green_LED__SLW CYREG_PRT3_SLW

/* timer_clock */
#define timer_clock__CFG0 CYREG_CLKDIST_DCFG0_CFG0
#define timer_clock__CFG1 CYREG_CLKDIST_DCFG0_CFG1
#define timer_clock__CFG2 CYREG_CLKDIST_DCFG0_CFG2
#define timer_clock__CFG2_SRC_SEL_MASK 0x07u
#define timer_clock__INDEX 0x00u
#define timer_clock__PM_ACT_CFG CYREG_PM_ACT_CFG2
#define timer_clock__PM_ACT_MSK 0x01u
#define timer_clock__PM_STBY_CFG CYREG_PM_STBY_CFG2
#define timer_clock__PM_STBY_MSK 0x01u

/* Left_Red_LED */
#define Left_Red_LED__0__INTTYPE CYREG_PICU3_INTTYPE1
#define Left_Red_LED__0__MASK 0x02u
#define Left_Red_LED__0__PC CYREG_PRT3_PC1
#define Left_Red_LED__0__PORT 3u
#define Left_Red_LED__0__SHIFT 1u
#define Left_Red_LED__AG CYREG_PRT3_AG
#define Left_Red_LED__AMUX CYREG_PRT3_AMUX
#define Left_Red_LED__BIE CYREG_PRT3_BIE
#define Left_Red_LED__BIT_MASK CYREG_PRT3_BIT_MASK
#define Left_Red_LED__BYP CYREG_PRT3_BYP
#define Left_Red_LED__CTL CYREG_PRT3_CTL
#define Left_Red_LED__DM0 CYREG_PRT3_DM0
#define Left_Red_LED__DM1 CYREG_PRT3_DM1
#define Left_Red_LED__DM2 CYREG_PRT3_DM2
#define Left_Red_LED__DR CYREG_PRT3_DR
#define Left_Red_LED__INP_DIS CYREG_PRT3_INP_DIS
#define Left_Red_LED__INTTYPE_BASE CYDEV_PICU_INTTYPE_PICU3_BASE
#define Left_Red_LED__LCD_COM_SEG CYREG_PRT3_LCD_COM_SEG
#define Left_Red_LED__LCD_EN CYREG_PRT3_LCD_EN
#define Left_Red_LED__MASK 0x02u
#define Left_Red_LED__PORT 3u
#define Left_Red_LED__PRT CYREG_PRT3_PRT
#define Left_Red_LED__PRTDSI__CAPS_SEL CYREG_PRT3_CAPS_SEL
#define Left_Red_LED__PRTDSI__DBL_SYNC_IN CYREG_PRT3_DBL_SYNC_IN
#define Left_Red_LED__PRTDSI__OE_SEL0 CYREG_PRT3_OE_SEL0
#define Left_Red_LED__PRTDSI__OE_SEL1 CYREG_PRT3_OE_SEL1
#define Left_Red_LED__PRTDSI__OUT_SEL0 CYREG_PRT3_OUT_SEL0
#define Left_Red_LED__PRTDSI__OUT_SEL1 CYREG_PRT3_OUT_SEL1
#define Left_Red_LED__PRTDSI__SYNC_OUT CYREG_PRT3_SYNC_OUT
#define Left_Red_LED__PS CYREG_PRT3_PS
#define Left_Red_LED__SHIFT 1u
#define Left_Red_LED__SLW CYREG_PRT3_SLW

/* Front_Red_LED */
#define Front_Red_LED__0__INTTYPE CYREG_PICU0_INTTYPE4
#define Front_Red_LED__0__MASK 0x10u
#define Front_Red_LED__0__PC CYREG_PRT0_PC4
#define Front_Red_LED__0__PORT 0u
#define Front_Red_LED__0__SHIFT 4u
#define Front_Red_LED__AG CYREG_PRT0_AG
#define Front_Red_LED__AMUX CYREG_PRT0_AMUX
#define Front_Red_LED__BIE CYREG_PRT0_BIE
#define Front_Red_LED__BIT_MASK CYREG_PRT0_BIT_MASK
#define Front_Red_LED__BYP CYREG_PRT0_BYP
#define Front_Red_LED__CTL CYREG_PRT0_CTL
#define Front_Red_LED__DM0 CYREG_PRT0_DM0
#define Front_Red_LED__DM1 CYREG_PRT0_DM1
#define Front_Red_LED__DM2 CYREG_PRT0_DM2
#define Front_Red_LED__DR CYREG_PRT0_DR
#define Front_Red_LED__INP_DIS CYREG_PRT0_INP_DIS
#define Front_Red_LED__INTTYPE_BASE CYDEV_PICU_INTTYPE_PICU0_BASE
#define Front_Red_LED__LCD_COM_SEG CYREG_PRT0_LCD_COM_SEG
#define Front_Red_LED__LCD_EN CYREG_PRT0_LCD_EN
#define Front_Red_LED__MASK 0x10u
#define Front_Red_LED__PORT 0u
#define Front_Red_LED__PRT CYREG_PRT0_PRT
#define Front_Red_LED__PRTDSI__CAPS_SEL CYREG_PRT0_CAPS_SEL
#define Front_Red_LED__PRTDSI__DBL_SYNC_IN CYREG_PRT0_DBL_SYNC_IN
#define Front_Red_LED__PRTDSI__OE_SEL0 CYREG_PRT0_OE_SEL0
#define Front_Red_LED__PRTDSI__OE_SEL1 CYREG_PRT0_OE_SEL1
#define Front_Red_LED__PRTDSI__OUT_SEL0 CYREG_PRT0_OUT_SEL0
#define Front_Red_LED__PRTDSI__OUT_SEL1 CYREG_PRT0_OUT_SEL1
#define Front_Red_LED__PRTDSI__SYNC_OUT CYREG_PRT0_SYNC_OUT
#define Front_Red_LED__PS CYREG_PRT0_PS
#define Front_Red_LED__SHIFT 4u
#define Front_Red_LED__SLW CYREG_PRT0_SLW

/* LED_UpdateISR */
#define LED_UpdateISR__ES2_PATCH 0u
#define LED_UpdateISR__INTC_CLR_EN_REG CYREG_INTC_CLR_EN0
#define LED_UpdateISR__INTC_CLR_PD_REG CYREG_INTC_CLR_PD0
#define LED_UpdateISR__INTC_MASK 0x01u
#define LED_UpdateISR__INTC_NUMBER 0u
#define LED_UpdateISR__INTC_PRIOR_NUM 7u
#define LED_UpdateISR__INTC_PRIOR_REG CYREG_INTC_PRIOR0
#define LED_UpdateISR__INTC_SET_EN_REG CYREG_INTC_SET_EN0
#define LED_UpdateISR__INTC_SET_PD_REG CYREG_INTC_SET_PD0
#define LED_UpdateISR__INTC_VECT (CYREG_INTC_VECT_MBASE+0x00u)

/* Right_Red_LED */
#define Right_Red_LED__0__INTTYPE CYREG_PICU3_INTTYPE2
#define Right_Red_LED__0__MASK 0x04u
#define Right_Red_LED__0__PC CYREG_PRT3_PC2
#define Right_Red_LED__0__PORT 3u
#define Right_Red_LED__0__SHIFT 2u
#define Right_Red_LED__AG CYREG_PRT3_AG
#define Right_Red_LED__AMUX CYREG_PRT3_AMUX
#define Right_Red_LED__BIE CYREG_PRT3_BIE
#define Right_Red_LED__BIT_MASK CYREG_PRT3_BIT_MASK
#define Right_Red_LED__BYP CYREG_PRT3_BYP
#define Right_Red_LED__CTL CYREG_PRT3_CTL
#define Right_Red_LED__DM0 CYREG_PRT3_DM0
#define Right_Red_LED__DM1 CYREG_PRT3_DM1
#define Right_Red_LED__DM2 CYREG_PRT3_DM2
#define Right_Red_LED__DR CYREG_PRT3_DR
#define Right_Red_LED__INP_DIS CYREG_PRT3_INP_DIS
#define Right_Red_LED__INTTYPE_BASE CYDEV_PICU_INTTYPE_PICU3_BASE
#define Right_Red_LED__LCD_COM_SEG CYREG_PRT3_LCD_COM_SEG
#define Right_Red_LED__LCD_EN CYREG_PRT3_LCD_EN
#define Right_Red_LED__MASK 0x04u
#define Right_Red_LED__PORT 3u
#define Right_Red_LED__PRT CYREG_PRT3_PRT
#define Right_Red_LED__PRTDSI__CAPS_SEL CYREG_PRT3_CAPS_SEL
#define Right_Red_LED__PRTDSI__DBL_SYNC_IN CYREG_PRT3_DBL_SYNC_IN
#define Right_Red_LED__PRTDSI__OE_SEL0 CYREG_PRT3_OE_SEL0
#define Right_Red_LED__PRTDSI__OE_SEL1 CYREG_PRT3_OE_SEL1
#define Right_Red_LED__PRTDSI__OUT_SEL0 CYREG_PRT3_OUT_SEL0
#define Right_Red_LED__PRTDSI__OUT_SEL1 CYREG_PRT3_OUT_SEL1
#define Right_Red_LED__PRTDSI__SYNC_OUT CYREG_PRT3_SYNC_OUT
#define Right_Red_LED__PS CYREG_PRT3_PS
#define Right_Red_LED__SHIFT 2u
#define Right_Red_LED__SLW CYREG_PRT3_SLW

/* Left_Amber_LED */
#define Left_Amber_LED__0__INTTYPE CYREG_PICU0_INTTYPE7
#define Left_Amber_LED__0__MASK 0x80u
#define Left_Amber_LED__0__PC CYREG_PRT0_PC7
#define Left_Amber_LED__0__PORT 0u
#define Left_Amber_LED__0__SHIFT 7u
#define Left_Amber_LED__AG CYREG_PRT0_AG
#define Left_Amber_LED__AMUX CYREG_PRT0_AMUX
#define Left_Amber_LED__BIE CYREG_PRT0_BIE
#define Left_Amber_LED__BIT_MASK CYREG_PRT0_BIT_MASK
#define Left_Amber_LED__BYP CYREG_PRT0_BYP
#define Left_Amber_LED__CTL CYREG_PRT0_CTL
#define Left_Amber_LED__DM0 CYREG_PRT0_DM0
#define Left_Amber_LED__DM1 CYREG_PRT0_DM1
#define Left_Amber_LED__DM2 CYREG_PRT0_DM2
#define Left_Amber_LED__DR CYREG_PRT0_DR
#define Left_Amber_LED__INP_DIS CYREG_PRT0_INP_DIS
#define Left_Amber_LED__INTTYPE_BASE CYDEV_PICU_INTTYPE_PICU0_BASE
#define Left_Amber_LED__LCD_COM_SEG CYREG_PRT0_LCD_COM_SEG
#define Left_Amber_LED__LCD_EN CYREG_PRT0_LCD_EN
#define Left_Amber_LED__MASK 0x80u
#define Left_Amber_LED__PORT 0u
#define Left_Amber_LED__PRT CYREG_PRT0_PRT
#define Left_Amber_LED__PRTDSI__CAPS_SEL CYREG_PRT0_CAPS_SEL
#define Left_Amber_LED__PRTDSI__DBL_SYNC_IN CYREG_PRT0_DBL_SYNC_IN
#define Left_Amber_LED__PRTDSI__OE_SEL0 CYREG_PRT0_OE_SEL0
#define Left_Amber_LED__PRTDSI__OE_SEL1 CYREG_PRT0_OE_SEL1
#define Left_Amber_LED__PRTDSI__OUT_SEL0 CYREG_PRT0_OUT_SEL0
#define Left_Amber_LED__PRTDSI__OUT_SEL1 CYREG_PRT0_OUT_SEL1
#define Left_Amber_LED__PRTDSI__SYNC_OUT CYREG_PRT0_SYNC_OUT
#define Left_Amber_LED__PS CYREG_PRT0_PS
#define Left_Amber_LED__SHIFT 7u
#define Left_Amber_LED__SLW CYREG_PRT0_SLW

/* Left_Green_LED */
#define Left_Green_LED__0__INTTYPE CYREG_PICU0_INTTYPE5
#define Left_Green_LED__0__MASK 0x20u
#define Left_Green_LED__0__PC CYREG_PRT0_PC5
#define Left_Green_LED__0__PORT 0u
#define Left_Green_LED__0__SHIFT 5u
#define Left_Green_LED__AG CYREG_PRT0_AG
#define Left_Green_LED__AMUX CYREG_PRT0_AMUX
#define Left_Green_LED__BIE CYREG_PRT0_BIE
#define Left_Green_LED__BIT_MASK CYREG_PRT0_BIT_MASK
#define Left_Green_LED__BYP CYREG_PRT0_BYP
#define Left_Green_LED__CTL CYREG_PRT0_CTL
#define Left_Green_LED__DM0 CYREG_PRT0_DM0
#define Left_Green_LED__DM1 CYREG_PRT0_DM1
#define Left_Green_LED__DM2 CYREG_PRT0_DM2
#define Left_Green_LED__DR CYREG_PRT0_DR
#define Left_Green_LED__INP_DIS CYREG_PRT0_INP_DIS
#define Left_Green_LED__INTTYPE_BASE CYDEV_PICU_INTTYPE_PICU0_BASE
#define Left_Green_LED__LCD_COM_SEG CYREG_PRT0_LCD_COM_SEG
#define Left_Green_LED__LCD_EN CYREG_PRT0_LCD_EN
#define Left_Green_LED__MASK 0x20u
#define Left_Green_LED__PORT 0u
#define Left_Green_LED__PRT CYREG_PRT0_PRT
#define Left_Green_LED__PRTDSI__CAPS_SEL CYREG_PRT0_CAPS_SEL
#define Left_Green_LED__PRTDSI__DBL_SYNC_IN CYREG_PRT0_DBL_SYNC_IN
#define Left_Green_LED__PRTDSI__OE_SEL0 CYREG_PRT0_OE_SEL0
#define Left_Green_LED__PRTDSI__OE_SEL1 CYREG_PRT0_OE_SEL1
#define Left_Green_LED__PRTDSI__OUT_SEL0 CYREG_PRT0_OUT_SEL0
#define Left_Green_LED__PRTDSI__OUT_SEL1 CYREG_PRT0_OUT_SEL1
#define Left_Green_LED__PRTDSI__SYNC_OUT CYREG_PRT0_SYNC_OUT
#define Left_Green_LED__PS CYREG_PRT0_PS
#define Left_Green_LED__SHIFT 5u
#define Left_Green_LED__SLW CYREG_PRT0_SLW

/* Front_Amber_LED */
#define Front_Amber_LED__0__INTTYPE CYREG_PICU0_INTTYPE6
#define Front_Amber_LED__0__MASK 0x40u
#define Front_Amber_LED__0__PC CYREG_PRT0_PC6
#define Front_Amber_LED__0__PORT 0u
#define Front_Amber_LED__0__SHIFT 6u
#define Front_Amber_LED__AG CYREG_PRT0_AG
#define Front_Amber_LED__AMUX CYREG_PRT0_AMUX
#define Front_Amber_LED__BIE CYREG_PRT0_BIE
#define Front_Amber_LED__BIT_MASK CYREG_PRT0_BIT_MASK
#define Front_Amber_LED__BYP CYREG_PRT0_BYP
#define Front_Amber_LED__CTL CYREG_PRT0_CTL
#define Front_Amber_LED__DM0 CYREG_PRT0_DM0
#define Front_Amber_LED__DM1 CYREG_PRT0_DM1
#define Front_Amber_LED__DM2 CYREG_PRT0_DM2
#define Front_Amber_LED__DR CYREG_PRT0_DR
#define Front_Amber_LED__INP_DIS CYREG_PRT0_INP_DIS
#define Front_Amber_LED__INTTYPE_BASE CYDEV_PICU_INTTYPE_PICU0_BASE
#define Front_Amber_LED__LCD_COM_SEG CYREG_PRT0_LCD_COM_SEG
#define Front_Amber_LED__LCD_EN CYREG_PRT0_LCD_EN
#define Front_Amber_LED__MASK 0x40u
#define Front_Amber_LED__PORT 0u
#define Front_Amber_LED__PRT CYREG_PRT0_PRT
#define Front_Amber_LED__PRTDSI__CAPS_SEL CYREG_PRT0_CAPS_SEL
#define Front_Amber_LED__PRTDSI__DBL_SYNC_IN CYREG_PRT0_DBL_SYNC_IN
#define Front_Amber_LED__PRTDSI__OE_SEL0 CYREG_PRT0_OE_SEL0
#define Front_Amber_LED__PRTDSI__OE_SEL1 CYREG_PRT0_OE_SEL1
#define Front_Amber_LED__PRTDSI__OUT_SEL0 CYREG_PRT0_OUT_SEL0
#define Front_Amber_LED__PRTDSI__OUT_SEL1 CYREG_PRT0_OUT_SEL1
#define Front_Amber_LED__PRTDSI__SYNC_OUT CYREG_PRT0_SYNC_OUT
#define Front_Amber_LED__PS CYREG_PRT0_PS
#define Front_Amber_LED__SHIFT 6u
#define Front_Amber_LED__SLW CYREG_PRT0_SLW

/* Front_Green_LED */
#define Front_Green_LED__0__INTTYPE CYREG_PICU3_INTTYPE0
#define Front_Green_LED__0__MASK 0x01u
#define Front_Green_LED__0__PC CYREG_PRT3_PC0
#define Front_Green_LED__0__PORT 3u
#define Front_Green_LED__0__SHIFT 0u
#define Front_Green_LED__AG CYREG_PRT3_AG
#define Front_Green_LED__AMUX CYREG_PRT3_AMUX
#define Front_Green_LED__BIE CYREG_PRT3_BIE
#define Front_Green_LED__BIT_MASK CYREG_PRT3_BIT_MASK
#define Front_Green_LED__BYP CYREG_PRT3_BYP
#define Front_Green_LED__CTL CYREG_PRT3_CTL
#define Front_Green_LED__DM0 CYREG_PRT3_DM0
#define Front_Green_LED__DM1 CYREG_PRT3_DM1
#define Front_Green_LED__DM2 CYREG_PRT3_DM2
#define Front_Green_LED__DR CYREG_PRT3_DR
#define Front_Green_LED__INP_DIS CYREG_PRT3_INP_DIS
#define Front_Green_LED__INTTYPE_BASE CYDEV_PICU_INTTYPE_PICU3_BASE
#define Front_Green_LED__LCD_COM_SEG CYREG_PRT3_LCD_COM_SEG
#define Front_Green_LED__LCD_EN CYREG_PRT3_LCD_EN
#define Front_Green_LED__MASK 0x01u
#define Front_Green_LED__PORT 3u
#define Front_Green_LED__PRT CYREG_PRT3_PRT
#define Front_Green_LED__PRTDSI__CAPS_SEL CYREG_PRT3_CAPS_SEL
#define Front_Green_LED__PRTDSI__DBL_SYNC_IN CYREG_PRT3_DBL_SYNC_IN
#define Front_Green_LED__PRTDSI__OE_SEL0 CYREG_PRT3_OE_SEL0
#define Front_Green_LED__PRTDSI__OE_SEL1 CYREG_PRT3_OE_SEL1
#define Front_Green_LED__PRTDSI__OUT_SEL0 CYREG_PRT3_OUT_SEL0
#define Front_Green_LED__PRTDSI__OUT_SEL1 CYREG_PRT3_OUT_SEL1
#define Front_Green_LED__PRTDSI__SYNC_OUT CYREG_PRT3_SYNC_OUT
#define Front_Green_LED__PS CYREG_PRT3_PS
#define Front_Green_LED__SHIFT 0u
#define Front_Green_LED__SLW CYREG_PRT3_SLW

/* LED_UpdateTimer */
#define LED_UpdateTimer_TimerUDB_rstSts_stsreg__0__MASK 0x01u
#define LED_UpdateTimer_TimerUDB_rstSts_stsreg__0__POS 0
#define LED_UpdateTimer_TimerUDB_rstSts_stsreg__16BIT_STATUS_AUX_CTL_REG CYREG_B0_UDB11_12_ACTL
#define LED_UpdateTimer_TimerUDB_rstSts_stsreg__16BIT_STATUS_REG CYREG_B0_UDB11_12_ST
#define LED_UpdateTimer_TimerUDB_rstSts_stsreg__2__MASK 0x04u
#define LED_UpdateTimer_TimerUDB_rstSts_stsreg__2__POS 2
#define LED_UpdateTimer_TimerUDB_rstSts_stsreg__3__MASK 0x08u
#define LED_UpdateTimer_TimerUDB_rstSts_stsreg__3__POS 3
#define LED_UpdateTimer_TimerUDB_rstSts_stsreg__MASK 0x0Du
#define LED_UpdateTimer_TimerUDB_rstSts_stsreg__MASK_REG CYREG_B0_UDB11_MSK
#define LED_UpdateTimer_TimerUDB_rstSts_stsreg__MASK_ST_AUX_CTL_REG CYREG_B0_UDB11_MSK_ACTL
#define LED_UpdateTimer_TimerUDB_rstSts_stsreg__PER_ST_AUX_CTL_REG CYREG_B0_UDB11_MSK_ACTL
#define LED_UpdateTimer_TimerUDB_rstSts_stsreg__STATUS_AUX_CTL_REG CYREG_B0_UDB11_ACTL
#define LED_UpdateTimer_TimerUDB_rstSts_stsreg__STATUS_CNT_REG CYREG_B0_UDB11_ST_CTL
#define LED_UpdateTimer_TimerUDB_rstSts_stsreg__STATUS_CONTROL_REG CYREG_B0_UDB11_ST_CTL
#define LED_UpdateTimer_TimerUDB_rstSts_stsreg__STATUS_REG CYREG_B0_UDB11_ST
#define LED_UpdateTimer_TimerUDB_sCTRLReg_SyncCtl_ctrlreg__16BIT_CONTROL_AUX_CTL_REG CYREG_B0_UDB11_12_ACTL
#define LED_UpdateTimer_TimerUDB_sCTRLReg_SyncCtl_ctrlreg__16BIT_CONTROL_CONTROL_REG CYREG_B0_UDB11_12_CTL
#define LED_UpdateTimer_TimerUDB_sCTRLReg_SyncCtl_ctrlreg__16BIT_CONTROL_COUNT_REG CYREG_B0_UDB11_12_CTL
#define LED_UpdateTimer_TimerUDB_sCTRLReg_SyncCtl_ctrlreg__16BIT_COUNT_CONTROL_REG CYREG_B0_UDB11_12_CTL
#define LED_UpdateTimer_TimerUDB_sCTRLReg_SyncCtl_ctrlreg__16BIT_COUNT_COUNT_REG CYREG_B0_UDB11_12_CTL
#define LED_UpdateTimer_TimerUDB_sCTRLReg_SyncCtl_ctrlreg__16BIT_MASK_MASK_REG CYREG_B0_UDB11_12_MSK
#define LED_UpdateTimer_TimerUDB_sCTRLReg_SyncCtl_ctrlreg__16BIT_MASK_PERIOD_REG CYREG_B0_UDB11_12_MSK
#define LED_UpdateTimer_TimerUDB_sCTRLReg_SyncCtl_ctrlreg__16BIT_PERIOD_MASK_REG CYREG_B0_UDB11_12_MSK
#define LED_UpdateTimer_TimerUDB_sCTRLReg_SyncCtl_ctrlreg__16BIT_PERIOD_PERIOD_REG CYREG_B0_UDB11_12_MSK
#define LED_UpdateTimer_TimerUDB_sCTRLReg_SyncCtl_ctrlreg__7__MASK 0x80u
#define LED_UpdateTimer_TimerUDB_sCTRLReg_SyncCtl_ctrlreg__7__POS 7
#define LED_UpdateTimer_TimerUDB_sCTRLReg_SyncCtl_ctrlreg__CONTROL_AUX_CTL_REG CYREG_B0_UDB11_ACTL
#define LED_UpdateTimer_TimerUDB_sCTRLReg_SyncCtl_ctrlreg__CONTROL_REG CYREG_B0_UDB11_CTL
#define LED_UpdateTimer_TimerUDB_sCTRLReg_SyncCtl_ctrlreg__CONTROL_ST_REG CYREG_B0_UDB11_ST_CTL
#define LED_UpdateTimer_TimerUDB_sCTRLReg_SyncCtl_ctrlreg__COUNT_REG CYREG_B0_UDB11_CTL
#define LED_UpdateTimer_TimerUDB_sCTRLReg_SyncCtl_ctrlreg__COUNT_ST_REG CYREG_B0_UDB11_ST_CTL
#define LED_UpdateTimer_TimerUDB_sCTRLReg_SyncCtl_ctrlreg__MASK 0x80u
#define LED_UpdateTimer_TimerUDB_sCTRLReg_SyncCtl_ctrlreg__MASK_CTL_AUX_CTL_REG CYREG_B0_UDB11_MSK_ACTL
#define LED_UpdateTimer_TimerUDB_sCTRLReg_SyncCtl_ctrlreg__PER_CTL_AUX_CTL_REG CYREG_B0_UDB11_MSK_ACTL
#define LED_UpdateTimer_TimerUDB_sCTRLReg_SyncCtl_ctrlreg__PERIOD_REG CYREG_B0_UDB11_MSK
#define LED_UpdateTimer_TimerUDB_sT8_timerdp_u0__16BIT_A0_REG CYREG_B0_UDB11_12_A0
#define LED_UpdateTimer_TimerUDB_sT8_timerdp_u0__16BIT_A1_REG CYREG_B0_UDB11_12_A1
#define LED_UpdateTimer_TimerUDB_sT8_timerdp_u0__16BIT_D0_REG CYREG_B0_UDB11_12_D0
#define LED_UpdateTimer_TimerUDB_sT8_timerdp_u0__16BIT_D1_REG CYREG_B0_UDB11_12_D1
#define LED_UpdateTimer_TimerUDB_sT8_timerdp_u0__16BIT_DP_AUX_CTL_REG CYREG_B0_UDB11_12_ACTL
#define LED_UpdateTimer_TimerUDB_sT8_timerdp_u0__16BIT_F0_REG CYREG_B0_UDB11_12_F0
#define LED_UpdateTimer_TimerUDB_sT8_timerdp_u0__16BIT_F1_REG CYREG_B0_UDB11_12_F1
#define LED_UpdateTimer_TimerUDB_sT8_timerdp_u0__A0_A1_REG CYREG_B0_UDB11_A0_A1
#define LED_UpdateTimer_TimerUDB_sT8_timerdp_u0__A0_REG CYREG_B0_UDB11_A0
#define LED_UpdateTimer_TimerUDB_sT8_timerdp_u0__A1_REG CYREG_B0_UDB11_A1
#define LED_UpdateTimer_TimerUDB_sT8_timerdp_u0__D0_D1_REG CYREG_B0_UDB11_D0_D1
#define LED_UpdateTimer_TimerUDB_sT8_timerdp_u0__D0_REG CYREG_B0_UDB11_D0
#define LED_UpdateTimer_TimerUDB_sT8_timerdp_u0__D1_REG CYREG_B0_UDB11_D1
#define LED_UpdateTimer_TimerUDB_sT8_timerdp_u0__DP_AUX_CTL_REG CYREG_B0_UDB11_ACTL
#define LED_UpdateTimer_TimerUDB_sT8_timerdp_u0__F0_F1_REG CYREG_B0_UDB11_F0_F1
#define LED_UpdateTimer_TimerUDB_sT8_timerdp_u0__F0_REG CYREG_B0_UDB11_F0
#define LED_UpdateTimer_TimerUDB_sT8_timerdp_u0__F1_REG CYREG_B0_UDB11_F1
#define LED_UpdateTimer_TimerUDB_sT8_timerdp_u0__MSK_DP_AUX_CTL_REG CYREG_B0_UDB11_MSK_ACTL
#define LED_UpdateTimer_TimerUDB_sT8_timerdp_u0__PER_DP_AUX_CTL_REG CYREG_B0_UDB11_MSK_ACTL

/* Right_Amber_LED */
#define Right_Amber_LED__0__INTTYPE CYREG_PICU3_INTTYPE4
#define Right_Amber_LED__0__MASK 0x10u
#define Right_Amber_LED__0__PC CYREG_PRT3_PC4
#define Right_Amber_LED__0__PORT 3u
#define Right_Amber_LED__0__SHIFT 4u
#define Right_Amber_LED__AG CYREG_PRT3_AG
#define Right_Amber_LED__AMUX CYREG_PRT3_AMUX
#define Right_Amber_LED__BIE CYREG_PRT3_BIE
#define Right_Amber_LED__BIT_MASK CYREG_PRT3_BIT_MASK
#define Right_Amber_LED__BYP CYREG_PRT3_BYP
#define Right_Amber_LED__CTL CYREG_PRT3_CTL
#define Right_Amber_LED__DM0 CYREG_PRT3_DM0
#define Right_Amber_LED__DM1 CYREG_PRT3_DM1
#define Right_Amber_LED__DM2 CYREG_PRT3_DM2
#define Right_Amber_LED__DR CYREG_PRT3_DR
#define Right_Amber_LED__INP_DIS CYREG_PRT3_INP_DIS
#define Right_Amber_LED__INTTYPE_BASE CYDEV_PICU_INTTYPE_PICU3_BASE
#define Right_Amber_LED__LCD_COM_SEG CYREG_PRT3_LCD_COM_SEG
#define Right_Amber_LED__LCD_EN CYREG_PRT3_LCD_EN
#define Right_Amber_LED__MASK 0x10u
#define Right_Amber_LED__PORT 3u
#define Right_Amber_LED__PRT CYREG_PRT3_PRT
#define Right_Amber_LED__PRTDSI__CAPS_SEL CYREG_PRT3_CAPS_SEL
#define Right_Amber_LED__PRTDSI__DBL_SYNC_IN CYREG_PRT3_DBL_SYNC_IN
#define Right_Amber_LED__PRTDSI__OE_SEL0 CYREG_PRT3_OE_SEL0
#define Right_Amber_LED__PRTDSI__OE_SEL1 CYREG_PRT3_OE_SEL1
#define Right_Amber_LED__PRTDSI__OUT_SEL0 CYREG_PRT3_OUT_SEL0
#define Right_Amber_LED__PRTDSI__OUT_SEL1 CYREG_PRT3_OUT_SEL1
#define Right_Amber_LED__PRTDSI__SYNC_OUT CYREG_PRT3_SYNC_OUT
#define Right_Amber_LED__PS CYREG_PRT3_PS
#define Right_Amber_LED__SHIFT 4u
#define Right_Amber_LED__SLW CYREG_PRT3_SLW

/* Right_Green_LED */
#define Right_Green_LED__0__INTTYPE CYREG_PICU3_INTTYPE6
#define Right_Green_LED__0__MASK 0x40u
#define Right_Green_LED__0__PC CYREG_PRT3_PC6
#define Right_Green_LED__0__PORT 3u
#define Right_Green_LED__0__SHIFT 6u
#define Right_Green_LED__AG CYREG_PRT3_AG
#define Right_Green_LED__AMUX CYREG_PRT3_AMUX
#define Right_Green_LED__BIE CYREG_PRT3_BIE
#define Right_Green_LED__BIT_MASK CYREG_PRT3_BIT_MASK
#define Right_Green_LED__BYP CYREG_PRT3_BYP
#define Right_Green_LED__CTL CYREG_PRT3_CTL
#define Right_Green_LED__DM0 CYREG_PRT3_DM0
#define Right_Green_LED__DM1 CYREG_PRT3_DM1
#define Right_Green_LED__DM2 CYREG_PRT3_DM2
#define Right_Green_LED__DR CYREG_PRT3_DR
#define Right_Green_LED__INP_DIS CYREG_PRT3_INP_DIS
#define Right_Green_LED__INTTYPE_BASE CYDEV_PICU_INTTYPE_PICU3_BASE
#define Right_Green_LED__LCD_COM_SEG CYREG_PRT3_LCD_COM_SEG
#define Right_Green_LED__LCD_EN CYREG_PRT3_LCD_EN
#define Right_Green_LED__MASK 0x40u
#define Right_Green_LED__PORT 3u
#define Right_Green_LED__PRT CYREG_PRT3_PRT
#define Right_Green_LED__PRTDSI__CAPS_SEL CYREG_PRT3_CAPS_SEL
#define Right_Green_LED__PRTDSI__DBL_SYNC_IN CYREG_PRT3_DBL_SYNC_IN
#define Right_Green_LED__PRTDSI__OE_SEL0 CYREG_PRT3_OE_SEL0
#define Right_Green_LED__PRTDSI__OE_SEL1 CYREG_PRT3_OE_SEL1
#define Right_Green_LED__PRTDSI__OUT_SEL0 CYREG_PRT3_OUT_SEL0
#define Right_Green_LED__PRTDSI__OUT_SEL1 CYREG_PRT3_OUT_SEL1
#define Right_Green_LED__PRTDSI__SYNC_OUT CYREG_PRT3_SYNC_OUT
#define Right_Green_LED__PS CYREG_PRT3_PS
#define Right_Green_LED__SHIFT 6u
#define Right_Green_LED__SLW CYREG_PRT3_SLW

/* Miscellaneous */
#define BCLK__BUS_CLK__HZ 24000000U
#define BCLK__BUS_CLK__KHZ 24000U
#define BCLK__BUS_CLK__MHZ 24U
#define CY_PROJECT_NAME "TrafficLightwith Struc"
#define CY_VERSION "PSoC Creator  4.2"
#define CYDEV_CHIP_DIE_LEOPARD 1u
#define CYDEV_CHIP_DIE_PSOC4A 18u
#define CYDEV_CHIP_DIE_PSOC5LP 2u
#define CYDEV_CHIP_DIE_PSOC5TM 3u
#define CYDEV_CHIP_DIE_TMA4 4u
#define CYDEV_CHIP_DIE_UNKNOWN 0u
#define CYDEV_CHIP_FAMILY_FM0P 5u
#define CYDEV_CHIP_FAMILY_FM3 6u
#define CYDEV_CHIP_FAMILY_FM4 7u
#define CYDEV_CHIP_FAMILY_PSOC3 1u
#define CYDEV_CHIP_FAMILY_PSOC4 2u
#define CYDEV_CHIP_FAMILY_PSOC5 3u
#define CYDEV_CHIP_FAMILY_PSOC6 4u
#define CYDEV_CHIP_FAMILY_UNKNOWN 0u
#define CYDEV_CHIP_FAMILY_USED CYDEV_CHIP_FAMILY_PSOC3
#define CYDEV_CHIP_JTAG_ID 0x1E028069u
#define CYDEV_CHIP_MEMBER_3A 1u
#define CYDEV_CHIP_MEMBER_4A 18u
#define CYDEV_CHIP_MEMBER_4D 13u
#define CYDEV_CHIP_MEMBER_4E 6u
#define CYDEV_CHIP_MEMBER_4F 19u
#define CYDEV_CHIP_MEMBER_4G 4u
#define CYDEV_CHIP_MEMBER_4H 17u
#define CYDEV_CHIP_MEMBER_4I 23u
#define CYDEV_CHIP_MEMBER_4J 14u
#define CYDEV_CHIP_MEMBER_4K 15u
#define CYDEV_CHIP_MEMBER_4L 22u
#define CYDEV_CHIP_MEMBER_4M 21u
#define CYDEV_CHIP_MEMBER_4N 10u
#define CYDEV_CHIP_MEMBER_4O 7u
#define CYDEV_CHIP_MEMBER_4P 20u
#define CYDEV_CHIP_MEMBER_4Q 12u
#define CYDEV_CHIP_MEMBER_4R 8u
#define CYDEV_CHIP_MEMBER_4S 11u
#define CYDEV_CHIP_MEMBER_4T 9u
#define CYDEV_CHIP_MEMBER_4U 5u
#define CYDEV_CHIP_MEMBER_4V 16u
#define CYDEV_CHIP_MEMBER_5A 3u
#define CYDEV_CHIP_MEMBER_5B 2u
#define CYDEV_CHIP_MEMBER_6A 24u
#define CYDEV_CHIP_MEMBER_FM3 28u
#define CYDEV_CHIP_MEMBER_FM4 29u
#define CYDEV_CHIP_MEMBER_PDL_FM0P_TYPE1 25u
#define CYDEV_CHIP_MEMBER_PDL_FM0P_TYPE2 26u
#define CYDEV_CHIP_MEMBER_PDL_FM0P_TYPE3 27u
#define CYDEV_CHIP_MEMBER_UNKNOWN 0u
#define CYDEV_CHIP_MEMBER_USED CYDEV_CHIP_MEMBER_3A
#define CYDEV_CHIP_DIE_EXPECT CYDEV_CHIP_MEMBER_USED
#define CYDEV_CHIP_DIE_ACTUAL CYDEV_CHIP_DIE_EXPECT
#define CYDEV_CHIP_REV_LEOPARD_ES1 0u
#define CYDEV_CHIP_REV_LEOPARD_ES2 1u
#define CYDEV_CHIP_REV_LEOPARD_ES3 3u
#define CYDEV_CHIP_REV_LEOPARD_PRODUCTION 3u
#define CYDEV_CHIP_REV_PSOC4A_ES0 17u
#define CYDEV_CHIP_REV_PSOC4A_PRODUCTION 17u
#define CYDEV_CHIP_REV_PSOC5LP_ES0 0u
#define CYDEV_CHIP_REV_PSOC5LP_PRODUCTION 0u
#define CYDEV_CHIP_REV_PSOC5TM_ES0 0u
#define CYDEV_CHIP_REV_PSOC5TM_ES1 1u
#define CYDEV_CHIP_REV_PSOC5TM_PRODUCTION 1u
#define CYDEV_CHIP_REV_TMA4_ES 17u
#define CYDEV_CHIP_REV_TMA4_ES2 33u
#define CYDEV_CHIP_REV_TMA4_PRODUCTION 17u
#define CYDEV_CHIP_REVISION_3A_ES1 0u
#define CYDEV_CHIP_REVISION_3A_ES2 1u
#define CYDEV_CHIP_REVISION_3A_ES3 3u
#define CYDEV_CHIP_REVISION_3A_PRODUCTION 3u
#define CYDEV_CHIP_REVISION_4A_ES0 17u
#define CYDEV_CHIP_REVISION_4A_PRODUCTION 17u
#define CYDEV_CHIP_REVISION_4D_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4E_CCG2_NO_USBPD 0u
#define CYDEV_CHIP_REVISION_4E_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4F_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4F_PRODUCTION_256DMA 0u
#define CYDEV_CHIP_REVISION_4F_PRODUCTION_256K 0u
#define CYDEV_CHIP_REVISION_4G_ES 17u
#define CYDEV_CHIP_REVISION_4G_ES2 33u
#define CYDEV_CHIP_REVISION_4G_PRODUCTION 17u
#define CYDEV_CHIP_REVISION_4H_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4I_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4J_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4K_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4L_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4M_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4N_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4O_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4P_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4Q_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4R_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4S_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4T_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4U_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4V_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_5A_ES0 0u
#define CYDEV_CHIP_REVISION_5A_ES1 1u
#define CYDEV_CHIP_REVISION_5A_PRODUCTION 1u
#define CYDEV_CHIP_REVISION_5B_ES0 0u
#define CYDEV_CHIP_REVISION_5B_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_6A_ES 17u
#define CYDEV_CHIP_REVISION_6A_NO_UDB 33u
#define CYDEV_CHIP_REVISION_6A_PRODUCTION 33u
#define CYDEV_CHIP_REVISION_FM3_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_FM4_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_PDL_FM0P_TYPE1_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_PDL_FM0P_TYPE2_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_PDL_FM0P_TYPE3_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_USED CYDEV_CHIP_REVISION_3A_PRODUCTION
#define CYDEV_CHIP_REV_EXPECT CYDEV_CHIP_REVISION_USED
#define CYDEV_CONFIG_FASTBOOT_ENABLED 1
#define CYDEV_CONFIG_UNUSED_IO_AllowButWarn 0
#define CYDEV_CONFIG_UNUSED_IO CYDEV_CONFIG_UNUSED_IO_AllowButWarn
#define CYDEV_CONFIG_UNUSED_IO_AllowWithInfo 1
#define CYDEV_CONFIG_UNUSED_IO_Disallowed 2
#define CYDEV_CONFIGURATION_CLEAR_SRAM 1
#define CYDEV_CONFIGURATION_COMPRESSED 1
#define CYDEV_CONFIGURATION_DMA 0
#define CYDEV_CONFIGURATION_ECC 1
#define CYDEV_CONFIGURATION_IMOENABLED CYDEV_CONFIG_FASTBOOT_ENABLED
#define CYDEV_CONFIGURATION_MODE_COMPRESSED 0
#define CYDEV_CONFIGURATION_MODE CYDEV_CONFIGURATION_MODE_COMPRESSED
#define CYDEV_CONFIGURATION_MODE_DMA 2
#define CYDEV_CONFIGURATION_MODE_UNCOMPRESSED 1
#define CYDEV_DEBUG_ENABLE_MASK 0x01u
#define CYDEV_DEBUG_ENABLE_REGISTER CYREG_MLOGIC_DEBUG
#define CYDEV_DEBUGGING_DPS_Disable 3
#define CYDEV_DEBUGGING_DPS_JTAG_4 1
#define CYDEV_DEBUGGING_DPS_JTAG_5 0
#define CYDEV_DEBUGGING_DPS_SWD 2
#define CYDEV_DEBUGGING_DPS_SWD_SWV 6
#define CYDEV_DEBUGGING_DPS CYDEV_DEBUGGING_DPS_SWD_SWV
#define CYDEV_DEBUGGING_ENABLE 1
#define CYDEV_DEBUGGING_XRES 0
#define CYDEV_DMA_CHANNELS_AVAILABLE 24u
#define CYDEV_ECC_ENABLE 0
#define CYDEV_INSTRUCT_CACHE_ENABLED 1
#define CYDEV_INTR_RISING 0x00000001u
#define CYDEV_IS_EXPORTING_CODE 0
#define CYDEV_IS_IMPORTING_CODE 0
#define CYDEV_PROJ_TYPE 0
#define CYDEV_PROJ_TYPE_BOOTLOADER 1
#define CYDEV_PROJ_TYPE_LAUNCHER 5
#define CYDEV_PROJ_TYPE_LOADABLE 2
#define CYDEV_PROJ_TYPE_LOADABLEANDBOOTLOADER 4
#define CYDEV_PROJ_TYPE_MULTIAPPBOOTLOADER 3
#define CYDEV_PROJ_TYPE_STANDARD 0
#define CYDEV_PROTECTION_ENABLE 0
#define CYDEV_VARIABLE_VDDA 0
#define CYDEV_VDDA 5.0
#define CYDEV_VDDA_MV 5000
#define CYDEV_VDDD 5.0
#define CYDEV_VDDD_MV 5000
#define CYDEV_VDDIO0 5.0
#define CYDEV_VDDIO0_MV 5000
#define CYDEV_VDDIO1 5.0
#define CYDEV_VDDIO1_MV 5000
#define CYDEV_VDDIO2 5.0
#define CYDEV_VDDIO2_MV 5000
#define CYDEV_VDDIO3 5.0
#define CYDEV_VDDIO3_MV 5000
#define CYDEV_VIO0 5.0
#define CYDEV_VIO0_MV 5000
#define CYDEV_VIO1 5.0
#define CYDEV_VIO1_MV 5000
#define CYDEV_VIO2 5.0
#define CYDEV_VIO2_MV 5000
#define CYDEV_VIO3 5.0
#define CYDEV_VIO3_MV 5000
#define CYIPBLOCK_DP8051_VERSION 0
#define CYIPBLOCK_P3_ANAIF_VERSION 0
#define CYIPBLOCK_P3_CAN_VERSION 0
#define CYIPBLOCK_P3_CAPSENSE_VERSION 0
#define CYIPBLOCK_P3_COMP_VERSION 0
#define CYIPBLOCK_P3_DECIMATOR_VERSION 0
#define CYIPBLOCK_P3_DFB_VERSION 0
#define CYIPBLOCK_P3_DMA_VERSION 0
#define CYIPBLOCK_P3_DRQ_VERSION 0
#define CYIPBLOCK_P3_DSM_VERSION 0
#define CYIPBLOCK_P3_EMIF_VERSION 0
#define CYIPBLOCK_P3_I2C_VERSION 0
#define CYIPBLOCK_P3_LCD_VERSION 0
#define CYIPBLOCK_P3_LPF_VERSION 0
#define CYIPBLOCK_P3_OPAMP_VERSION 0
#define CYIPBLOCK_P3_PM_VERSION 0
#define CYIPBLOCK_P3_SCCT_VERSION 0
#define CYIPBLOCK_P3_TIMER_VERSION 0
#define CYIPBLOCK_P3_USB_VERSION 0
#define CYIPBLOCK_P3_VIDAC_VERSION 0
#define CYIPBLOCK_P3_VREF_VERSION 0
#define CYIPBLOCK_S8_GPIO_VERSION 0
#define CYIPBLOCK_S8_IRQ_VERSION 0
#define CYIPBLOCK_S8_SIO_VERSION 0
#define CYIPBLOCK_S8_UDB_VERSION 0
#define DMA_CHANNELS_USED__MASK0 0x00000000u
#define CYDEV_BOOTLOADER_ENABLE 0

#endif /* INCLUDED_CYFITTER_H */
