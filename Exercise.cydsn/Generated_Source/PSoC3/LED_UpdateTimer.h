/*******************************************************************************
* File Name: LED_UpdateTimer.h
* Version 2.80
*
*  Description:
*     Contains the function prototypes and constants available to the timer
*     user module.
*
*   Note:
*     None
*
********************************************************************************
* Copyright 2008-2017, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
********************************************************************************/

#if !defined(CY_TIMER_LED_UpdateTimer_H)
#define CY_TIMER_LED_UpdateTimer_H

#include "cytypes.h"
#include "cyfitter.h"
#include "CyLib.h" /* For CyEnterCriticalSection() and CyExitCriticalSection() functions */

extern uint8 LED_UpdateTimer_initVar;

/* Check to see if required defines such as CY_PSOC5LP are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5LP)
    #error Component Timer_v2_80 requires cy_boot v3.0 or later
#endif /* (CY_ PSOC5LP) */


/**************************************
*           Parameter Defaults
**************************************/

#define LED_UpdateTimer_Resolution                 8u
#define LED_UpdateTimer_UsingFixedFunction         0u
#define LED_UpdateTimer_UsingHWCaptureCounter      0u
#define LED_UpdateTimer_SoftwareCaptureMode        0u
#define LED_UpdateTimer_SoftwareTriggerMode        0u
#define LED_UpdateTimer_UsingHWEnable              0u
#define LED_UpdateTimer_EnableTriggerMode          0u
#define LED_UpdateTimer_InterruptOnCaptureCount    0u
#define LED_UpdateTimer_RunModeUsed                0u
#define LED_UpdateTimer_ControlRegRemoved          0u

#if defined(LED_UpdateTimer_TimerUDB_sCTRLReg_SyncCtl_ctrlreg__CONTROL_REG)
    #define LED_UpdateTimer_UDB_CONTROL_REG_REMOVED            (0u)
#elif  (LED_UpdateTimer_UsingFixedFunction)
    #define LED_UpdateTimer_UDB_CONTROL_REG_REMOVED            (0u)
#else 
    #define LED_UpdateTimer_UDB_CONTROL_REG_REMOVED            (1u)
#endif /* End LED_UpdateTimer_TimerUDB_sCTRLReg_SyncCtl_ctrlreg__CONTROL_REG */


/***************************************
*       Type defines
***************************************/


/**************************************************************************
 * Sleep Wakeup Backup structure for Timer Component
 *************************************************************************/
typedef struct
{
    uint8 TimerEnableState;
    #if(!LED_UpdateTimer_UsingFixedFunction)

        uint8 TimerUdb;
        uint8 InterruptMaskValue;
        #if (LED_UpdateTimer_UsingHWCaptureCounter)
            uint8 TimerCaptureCounter;
        #endif /* variable declarations for backing up non retention registers in CY_UDB_V1 */

        #if (!LED_UpdateTimer_UDB_CONTROL_REG_REMOVED)
            uint8 TimerControlRegister;
        #endif /* variable declaration for backing up enable state of the Timer */
    #endif /* define backup variables only for UDB implementation. Fixed function registers are all retention */

}LED_UpdateTimer_backupStruct;


/***************************************
*       Function Prototypes
***************************************/

void    LED_UpdateTimer_Start(void) ;
void    LED_UpdateTimer_Stop(void) ;

void    LED_UpdateTimer_SetInterruptMode(uint8 interruptMode) ;
uint8   LED_UpdateTimer_ReadStatusRegister(void) ;
/* Deprecated function. Do not use this in future. Retained for backward compatibility */
#define LED_UpdateTimer_GetInterruptSource() LED_UpdateTimer_ReadStatusRegister()

#if(!LED_UpdateTimer_UDB_CONTROL_REG_REMOVED)
    uint8   LED_UpdateTimer_ReadControlRegister(void) ;
    void    LED_UpdateTimer_WriteControlRegister(uint8 control) ;
#endif /* (!LED_UpdateTimer_UDB_CONTROL_REG_REMOVED) */

uint8  LED_UpdateTimer_ReadPeriod(void) ;
void    LED_UpdateTimer_WritePeriod(uint8 period) ;
uint8  LED_UpdateTimer_ReadCounter(void) ;
void    LED_UpdateTimer_WriteCounter(uint8 counter) ;
uint8  LED_UpdateTimer_ReadCapture(void) ;
void    LED_UpdateTimer_SoftwareCapture(void) ;

#if(!LED_UpdateTimer_UsingFixedFunction) /* UDB Prototypes */
    #if (LED_UpdateTimer_SoftwareCaptureMode)
        void    LED_UpdateTimer_SetCaptureMode(uint8 captureMode) ;
    #endif /* (!LED_UpdateTimer_UsingFixedFunction) */

    #if (LED_UpdateTimer_SoftwareTriggerMode)
        void    LED_UpdateTimer_SetTriggerMode(uint8 triggerMode) ;
    #endif /* (LED_UpdateTimer_SoftwareTriggerMode) */

    #if (LED_UpdateTimer_EnableTriggerMode)
        void    LED_UpdateTimer_EnableTrigger(void) ;
        void    LED_UpdateTimer_DisableTrigger(void) ;
    #endif /* (LED_UpdateTimer_EnableTriggerMode) */


    #if(LED_UpdateTimer_InterruptOnCaptureCount)
        void    LED_UpdateTimer_SetInterruptCount(uint8 interruptCount) ;
    #endif /* (LED_UpdateTimer_InterruptOnCaptureCount) */

    #if (LED_UpdateTimer_UsingHWCaptureCounter)
        void    LED_UpdateTimer_SetCaptureCount(uint8 captureCount) ;
        uint8   LED_UpdateTimer_ReadCaptureCount(void) ;
    #endif /* (LED_UpdateTimer_UsingHWCaptureCounter) */

    void LED_UpdateTimer_ClearFIFO(void) ;
#endif /* UDB Prototypes */

/* Sleep Retention APIs */
void LED_UpdateTimer_Init(void)          ;
void LED_UpdateTimer_Enable(void)        ;
void LED_UpdateTimer_SaveConfig(void)    ;
void LED_UpdateTimer_RestoreConfig(void) ;
void LED_UpdateTimer_Sleep(void)         ;
void LED_UpdateTimer_Wakeup(void)        ;


/***************************************
*   Enumerated Types and Parameters
***************************************/

/* Enumerated Type B_Timer__CaptureModes, Used in Capture Mode */
#define LED_UpdateTimer__B_TIMER__CM_NONE 0
#define LED_UpdateTimer__B_TIMER__CM_RISINGEDGE 1
#define LED_UpdateTimer__B_TIMER__CM_FALLINGEDGE 2
#define LED_UpdateTimer__B_TIMER__CM_EITHEREDGE 3
#define LED_UpdateTimer__B_TIMER__CM_SOFTWARE 4



/* Enumerated Type B_Timer__TriggerModes, Used in Trigger Mode */
#define LED_UpdateTimer__B_TIMER__TM_NONE 0x00u
#define LED_UpdateTimer__B_TIMER__TM_RISINGEDGE 0x04u
#define LED_UpdateTimer__B_TIMER__TM_FALLINGEDGE 0x08u
#define LED_UpdateTimer__B_TIMER__TM_EITHEREDGE 0x0Cu
#define LED_UpdateTimer__B_TIMER__TM_SOFTWARE 0x10u


/***************************************
*    Initialial Parameter Constants
***************************************/

#define LED_UpdateTimer_INIT_PERIOD             254u
#define LED_UpdateTimer_INIT_CAPTURE_MODE       ((uint8)((uint8)0u << LED_UpdateTimer_CTRL_CAP_MODE_SHIFT))
#define LED_UpdateTimer_INIT_TRIGGER_MODE       ((uint8)((uint8)0u << LED_UpdateTimer_CTRL_TRIG_MODE_SHIFT))
#if (LED_UpdateTimer_UsingFixedFunction)
    #define LED_UpdateTimer_INIT_INTERRUPT_MODE (((uint8)((uint8)0u << LED_UpdateTimer_STATUS_TC_INT_MASK_SHIFT)) | \
                                                  ((uint8)((uint8)0 << LED_UpdateTimer_STATUS_CAPTURE_INT_MASK_SHIFT)))
#else
    #define LED_UpdateTimer_INIT_INTERRUPT_MODE (((uint8)((uint8)0u << LED_UpdateTimer_STATUS_TC_INT_MASK_SHIFT)) | \
                                                 ((uint8)((uint8)0 << LED_UpdateTimer_STATUS_CAPTURE_INT_MASK_SHIFT)) | \
                                                 ((uint8)((uint8)0 << LED_UpdateTimer_STATUS_FIFOFULL_INT_MASK_SHIFT)))
#endif /* (LED_UpdateTimer_UsingFixedFunction) */
#define LED_UpdateTimer_INIT_CAPTURE_COUNT      (2u)
#define LED_UpdateTimer_INIT_INT_CAPTURE_COUNT  ((uint8)((uint8)(1u - 1u) << LED_UpdateTimer_CTRL_INTCNT_SHIFT))


/***************************************
*           Registers
***************************************/

#if (LED_UpdateTimer_UsingFixedFunction) /* Implementation Specific Registers and Register Constants */


    /***************************************
    *    Fixed Function Registers
    ***************************************/

    #define LED_UpdateTimer_STATUS         (*(reg8 *) LED_UpdateTimer_TimerHW__SR0 )
    /* In Fixed Function Block Status and Mask are the same register */
    #define LED_UpdateTimer_STATUS_MASK    (*(reg8 *) LED_UpdateTimer_TimerHW__SR0 )
    #define LED_UpdateTimer_CONTROL        (*(reg8 *) LED_UpdateTimer_TimerHW__CFG0)
    #define LED_UpdateTimer_CONTROL2       (*(reg8 *) LED_UpdateTimer_TimerHW__CFG1)
    #define LED_UpdateTimer_CONTROL2_PTR   ( (reg8 *) LED_UpdateTimer_TimerHW__CFG1)
    #define LED_UpdateTimer_RT1            (*(reg8 *) LED_UpdateTimer_TimerHW__RT1)
    #define LED_UpdateTimer_RT1_PTR        ( (reg8 *) LED_UpdateTimer_TimerHW__RT1)

    #if (CY_PSOC3 || CY_PSOC5LP)
        #define LED_UpdateTimer_CONTROL3       (*(reg8 *) LED_UpdateTimer_TimerHW__CFG2)
        #define LED_UpdateTimer_CONTROL3_PTR   ( (reg8 *) LED_UpdateTimer_TimerHW__CFG2)
    #endif /* (CY_PSOC3 || CY_PSOC5LP) */
    #define LED_UpdateTimer_GLOBAL_ENABLE  (*(reg8 *) LED_UpdateTimer_TimerHW__PM_ACT_CFG)
    #define LED_UpdateTimer_GLOBAL_STBY_ENABLE  (*(reg8 *) LED_UpdateTimer_TimerHW__PM_STBY_CFG)

    #define LED_UpdateTimer_CAPTURE_LSB         (* (reg16 *) LED_UpdateTimer_TimerHW__CAP0 )
    #define LED_UpdateTimer_CAPTURE_LSB_PTR       ((reg16 *) LED_UpdateTimer_TimerHW__CAP0 )
    #define LED_UpdateTimer_PERIOD_LSB          (* (reg16 *) LED_UpdateTimer_TimerHW__PER0 )
    #define LED_UpdateTimer_PERIOD_LSB_PTR        ((reg16 *) LED_UpdateTimer_TimerHW__PER0 )
    #define LED_UpdateTimer_COUNTER_LSB         (* (reg16 *) LED_UpdateTimer_TimerHW__CNT_CMP0 )
    #define LED_UpdateTimer_COUNTER_LSB_PTR       ((reg16 *) LED_UpdateTimer_TimerHW__CNT_CMP0 )


    /***************************************
    *    Register Constants
    ***************************************/

    /* Fixed Function Block Chosen */
    #define LED_UpdateTimer_BLOCK_EN_MASK                     LED_UpdateTimer_TimerHW__PM_ACT_MSK
    #define LED_UpdateTimer_BLOCK_STBY_EN_MASK                LED_UpdateTimer_TimerHW__PM_STBY_MSK

    /* Control Register Bit Locations */
    /* Interrupt Count - Not valid for Fixed Function Block */
    #define LED_UpdateTimer_CTRL_INTCNT_SHIFT                  0x00u
    /* Trigger Polarity - Not valid for Fixed Function Block */
    #define LED_UpdateTimer_CTRL_TRIG_MODE_SHIFT               0x00u
    /* Trigger Enable - Not valid for Fixed Function Block */
    #define LED_UpdateTimer_CTRL_TRIG_EN_SHIFT                 0x00u
    /* Capture Polarity - Not valid for Fixed Function Block */
    #define LED_UpdateTimer_CTRL_CAP_MODE_SHIFT                0x00u
    /* Timer Enable - As defined in Register Map, part of TMRX_CFG0 register */
    #define LED_UpdateTimer_CTRL_ENABLE_SHIFT                  0x00u

    /* Control Register Bit Masks */
    #define LED_UpdateTimer_CTRL_ENABLE                        ((uint8)((uint8)0x01u << LED_UpdateTimer_CTRL_ENABLE_SHIFT))

    /* Control2 Register Bit Masks */
    /* As defined in Register Map, Part of the TMRX_CFG1 register */
    #define LED_UpdateTimer_CTRL2_IRQ_SEL_SHIFT                 0x00u
    #define LED_UpdateTimer_CTRL2_IRQ_SEL                      ((uint8)((uint8)0x01u << LED_UpdateTimer_CTRL2_IRQ_SEL_SHIFT))

    #if (CY_PSOC5A)
        /* Use CFG1 Mode bits to set run mode */
        /* As defined by Verilog Implementation */
        #define LED_UpdateTimer_CTRL_MODE_SHIFT                 0x01u
        #define LED_UpdateTimer_CTRL_MODE_MASK                 ((uint8)((uint8)0x07u << LED_UpdateTimer_CTRL_MODE_SHIFT))
    #endif /* (CY_PSOC5A) */
    #if (CY_PSOC3 || CY_PSOC5LP)
        /* Control3 Register Bit Locations */
        #define LED_UpdateTimer_CTRL_RCOD_SHIFT        0x02u
        #define LED_UpdateTimer_CTRL_ENBL_SHIFT        0x00u
        #define LED_UpdateTimer_CTRL_MODE_SHIFT        0x00u

        /* Control3 Register Bit Masks */
        #define LED_UpdateTimer_CTRL_RCOD_MASK  ((uint8)((uint8)0x03u << LED_UpdateTimer_CTRL_RCOD_SHIFT)) /* ROD and COD bit masks */
        #define LED_UpdateTimer_CTRL_ENBL_MASK  ((uint8)((uint8)0x80u << LED_UpdateTimer_CTRL_ENBL_SHIFT)) /* HW_EN bit mask */
        #define LED_UpdateTimer_CTRL_MODE_MASK  ((uint8)((uint8)0x03u << LED_UpdateTimer_CTRL_MODE_SHIFT)) /* Run mode bit mask */

        #define LED_UpdateTimer_CTRL_RCOD       ((uint8)((uint8)0x03u << LED_UpdateTimer_CTRL_RCOD_SHIFT))
        #define LED_UpdateTimer_CTRL_ENBL       ((uint8)((uint8)0x80u << LED_UpdateTimer_CTRL_ENBL_SHIFT))
    #endif /* (CY_PSOC3 || CY_PSOC5LP) */

    /*RT1 Synch Constants: Applicable for PSoC3 and PSoC5LP */
    #define LED_UpdateTimer_RT1_SHIFT                       0x04u
    /* Sync TC and CMP bit masks */
    #define LED_UpdateTimer_RT1_MASK                        ((uint8)((uint8)0x03u << LED_UpdateTimer_RT1_SHIFT))
    #define LED_UpdateTimer_SYNC                            ((uint8)((uint8)0x03u << LED_UpdateTimer_RT1_SHIFT))
    #define LED_UpdateTimer_SYNCDSI_SHIFT                   0x00u
    /* Sync all DSI inputs with Mask  */
    #define LED_UpdateTimer_SYNCDSI_MASK                    ((uint8)((uint8)0x0Fu << LED_UpdateTimer_SYNCDSI_SHIFT))
    /* Sync all DSI inputs */
    #define LED_UpdateTimer_SYNCDSI_EN                      ((uint8)((uint8)0x0Fu << LED_UpdateTimer_SYNCDSI_SHIFT))

    #define LED_UpdateTimer_CTRL_MODE_PULSEWIDTH            ((uint8)((uint8)0x01u << LED_UpdateTimer_CTRL_MODE_SHIFT))
    #define LED_UpdateTimer_CTRL_MODE_PERIOD                ((uint8)((uint8)0x02u << LED_UpdateTimer_CTRL_MODE_SHIFT))
    #define LED_UpdateTimer_CTRL_MODE_CONTINUOUS            ((uint8)((uint8)0x00u << LED_UpdateTimer_CTRL_MODE_SHIFT))

    /* Status Register Bit Locations */
    /* As defined in Register Map, part of TMRX_SR0 register */
    #define LED_UpdateTimer_STATUS_TC_SHIFT                 0x07u
    /* As defined in Register Map, part of TMRX_SR0 register, Shared with Compare Status */
    #define LED_UpdateTimer_STATUS_CAPTURE_SHIFT            0x06u
    /* As defined in Register Map, part of TMRX_SR0 register */
    #define LED_UpdateTimer_STATUS_TC_INT_MASK_SHIFT        (LED_UpdateTimer_STATUS_TC_SHIFT - 0x04u)
    /* As defined in Register Map, part of TMRX_SR0 register, Shared with Compare Status */
    #define LED_UpdateTimer_STATUS_CAPTURE_INT_MASK_SHIFT   (LED_UpdateTimer_STATUS_CAPTURE_SHIFT - 0x04u)

    /* Status Register Bit Masks */
    #define LED_UpdateTimer_STATUS_TC                       ((uint8)((uint8)0x01u << LED_UpdateTimer_STATUS_TC_SHIFT))
    #define LED_UpdateTimer_STATUS_CAPTURE                  ((uint8)((uint8)0x01u << LED_UpdateTimer_STATUS_CAPTURE_SHIFT))
    /* Interrupt Enable Bit-Mask for interrupt on TC */
    #define LED_UpdateTimer_STATUS_TC_INT_MASK              ((uint8)((uint8)0x01u << LED_UpdateTimer_STATUS_TC_INT_MASK_SHIFT))
    /* Interrupt Enable Bit-Mask for interrupt on Capture */
    #define LED_UpdateTimer_STATUS_CAPTURE_INT_MASK         ((uint8)((uint8)0x01u << LED_UpdateTimer_STATUS_CAPTURE_INT_MASK_SHIFT))

#else   /* UDB Registers and Register Constants */


    /***************************************
    *           UDB Registers
    ***************************************/

    #define LED_UpdateTimer_STATUS              (* (reg8 *) LED_UpdateTimer_TimerUDB_rstSts_stsreg__STATUS_REG )
    #define LED_UpdateTimer_STATUS_MASK         (* (reg8 *) LED_UpdateTimer_TimerUDB_rstSts_stsreg__MASK_REG)
    #define LED_UpdateTimer_STATUS_AUX_CTRL     (* (reg8 *) LED_UpdateTimer_TimerUDB_rstSts_stsreg__STATUS_AUX_CTL_REG)
    #define LED_UpdateTimer_CONTROL             (* (reg8 *) LED_UpdateTimer_TimerUDB_sCTRLReg_SyncCtl_ctrlreg__CONTROL_REG )
    
    #if(LED_UpdateTimer_Resolution <= 8u) /* 8-bit Timer */
        #define LED_UpdateTimer_CAPTURE_LSB         (* (reg8 *) LED_UpdateTimer_TimerUDB_sT8_timerdp_u0__F0_REG )
        #define LED_UpdateTimer_CAPTURE_LSB_PTR       ((reg8 *) LED_UpdateTimer_TimerUDB_sT8_timerdp_u0__F0_REG )
        #define LED_UpdateTimer_PERIOD_LSB          (* (reg8 *) LED_UpdateTimer_TimerUDB_sT8_timerdp_u0__D0_REG )
        #define LED_UpdateTimer_PERIOD_LSB_PTR        ((reg8 *) LED_UpdateTimer_TimerUDB_sT8_timerdp_u0__D0_REG )
        #define LED_UpdateTimer_COUNTER_LSB         (* (reg8 *) LED_UpdateTimer_TimerUDB_sT8_timerdp_u0__A0_REG )
        #define LED_UpdateTimer_COUNTER_LSB_PTR       ((reg8 *) LED_UpdateTimer_TimerUDB_sT8_timerdp_u0__A0_REG )
    #elif(LED_UpdateTimer_Resolution <= 16u) /* 8-bit Timer */
        #if(CY_PSOC3) /* 8-bit addres space */
            #define LED_UpdateTimer_CAPTURE_LSB         (* (reg16 *) LED_UpdateTimer_TimerUDB_sT8_timerdp_u0__F0_REG )
            #define LED_UpdateTimer_CAPTURE_LSB_PTR       ((reg16 *) LED_UpdateTimer_TimerUDB_sT8_timerdp_u0__F0_REG )
            #define LED_UpdateTimer_PERIOD_LSB          (* (reg16 *) LED_UpdateTimer_TimerUDB_sT8_timerdp_u0__D0_REG )
            #define LED_UpdateTimer_PERIOD_LSB_PTR        ((reg16 *) LED_UpdateTimer_TimerUDB_sT8_timerdp_u0__D0_REG )
            #define LED_UpdateTimer_COUNTER_LSB         (* (reg16 *) LED_UpdateTimer_TimerUDB_sT8_timerdp_u0__A0_REG )
            #define LED_UpdateTimer_COUNTER_LSB_PTR       ((reg16 *) LED_UpdateTimer_TimerUDB_sT8_timerdp_u0__A0_REG )
        #else /* 16-bit address space */
            #define LED_UpdateTimer_CAPTURE_LSB         (* (reg16 *) LED_UpdateTimer_TimerUDB_sT8_timerdp_u0__16BIT_F0_REG )
            #define LED_UpdateTimer_CAPTURE_LSB_PTR       ((reg16 *) LED_UpdateTimer_TimerUDB_sT8_timerdp_u0__16BIT_F0_REG )
            #define LED_UpdateTimer_PERIOD_LSB          (* (reg16 *) LED_UpdateTimer_TimerUDB_sT8_timerdp_u0__16BIT_D0_REG )
            #define LED_UpdateTimer_PERIOD_LSB_PTR        ((reg16 *) LED_UpdateTimer_TimerUDB_sT8_timerdp_u0__16BIT_D0_REG )
            #define LED_UpdateTimer_COUNTER_LSB         (* (reg16 *) LED_UpdateTimer_TimerUDB_sT8_timerdp_u0__16BIT_A0_REG )
            #define LED_UpdateTimer_COUNTER_LSB_PTR       ((reg16 *) LED_UpdateTimer_TimerUDB_sT8_timerdp_u0__16BIT_A0_REG )
        #endif /* CY_PSOC3 */
    #elif(LED_UpdateTimer_Resolution <= 24u)/* 24-bit Timer */
        #define LED_UpdateTimer_CAPTURE_LSB         (* (reg32 *) LED_UpdateTimer_TimerUDB_sT8_timerdp_u0__F0_REG )
        #define LED_UpdateTimer_CAPTURE_LSB_PTR       ((reg32 *) LED_UpdateTimer_TimerUDB_sT8_timerdp_u0__F0_REG )
        #define LED_UpdateTimer_PERIOD_LSB          (* (reg32 *) LED_UpdateTimer_TimerUDB_sT8_timerdp_u0__D0_REG )
        #define LED_UpdateTimer_PERIOD_LSB_PTR        ((reg32 *) LED_UpdateTimer_TimerUDB_sT8_timerdp_u0__D0_REG )
        #define LED_UpdateTimer_COUNTER_LSB         (* (reg32 *) LED_UpdateTimer_TimerUDB_sT8_timerdp_u0__A0_REG )
        #define LED_UpdateTimer_COUNTER_LSB_PTR       ((reg32 *) LED_UpdateTimer_TimerUDB_sT8_timerdp_u0__A0_REG )
    #else /* 32-bit Timer */
        #if(CY_PSOC3 || CY_PSOC5) /* 8-bit address space */
            #define LED_UpdateTimer_CAPTURE_LSB         (* (reg32 *) LED_UpdateTimer_TimerUDB_sT8_timerdp_u0__F0_REG )
            #define LED_UpdateTimer_CAPTURE_LSB_PTR       ((reg32 *) LED_UpdateTimer_TimerUDB_sT8_timerdp_u0__F0_REG )
            #define LED_UpdateTimer_PERIOD_LSB          (* (reg32 *) LED_UpdateTimer_TimerUDB_sT8_timerdp_u0__D0_REG )
            #define LED_UpdateTimer_PERIOD_LSB_PTR        ((reg32 *) LED_UpdateTimer_TimerUDB_sT8_timerdp_u0__D0_REG )
            #define LED_UpdateTimer_COUNTER_LSB         (* (reg32 *) LED_UpdateTimer_TimerUDB_sT8_timerdp_u0__A0_REG )
            #define LED_UpdateTimer_COUNTER_LSB_PTR       ((reg32 *) LED_UpdateTimer_TimerUDB_sT8_timerdp_u0__A0_REG )
        #else /* 32-bit address space */
            #define LED_UpdateTimer_CAPTURE_LSB         (* (reg32 *) LED_UpdateTimer_TimerUDB_sT8_timerdp_u0__32BIT_F0_REG )
            #define LED_UpdateTimer_CAPTURE_LSB_PTR       ((reg32 *) LED_UpdateTimer_TimerUDB_sT8_timerdp_u0__32BIT_F0_REG )
            #define LED_UpdateTimer_PERIOD_LSB          (* (reg32 *) LED_UpdateTimer_TimerUDB_sT8_timerdp_u0__32BIT_D0_REG )
            #define LED_UpdateTimer_PERIOD_LSB_PTR        ((reg32 *) LED_UpdateTimer_TimerUDB_sT8_timerdp_u0__32BIT_D0_REG )
            #define LED_UpdateTimer_COUNTER_LSB         (* (reg32 *) LED_UpdateTimer_TimerUDB_sT8_timerdp_u0__32BIT_A0_REG )
            #define LED_UpdateTimer_COUNTER_LSB_PTR       ((reg32 *) LED_UpdateTimer_TimerUDB_sT8_timerdp_u0__32BIT_A0_REG )
        #endif /* CY_PSOC3 || CY_PSOC5 */ 
    #endif

    #define LED_UpdateTimer_COUNTER_LSB_PTR_8BIT       ((reg8 *) LED_UpdateTimer_TimerUDB_sT8_timerdp_u0__A0_REG )
    
    #if (LED_UpdateTimer_UsingHWCaptureCounter)
        #define LED_UpdateTimer_CAP_COUNT              (*(reg8 *) LED_UpdateTimer_TimerUDB_sCapCount_counter__PERIOD_REG )
        #define LED_UpdateTimer_CAP_COUNT_PTR          ( (reg8 *) LED_UpdateTimer_TimerUDB_sCapCount_counter__PERIOD_REG )
        #define LED_UpdateTimer_CAPTURE_COUNT_CTRL     (*(reg8 *) LED_UpdateTimer_TimerUDB_sCapCount_counter__CONTROL_AUX_CTL_REG )
        #define LED_UpdateTimer_CAPTURE_COUNT_CTRL_PTR ( (reg8 *) LED_UpdateTimer_TimerUDB_sCapCount_counter__CONTROL_AUX_CTL_REG )
    #endif /* (LED_UpdateTimer_UsingHWCaptureCounter) */


    /***************************************
    *       Register Constants
    ***************************************/

    /* Control Register Bit Locations */
    #define LED_UpdateTimer_CTRL_INTCNT_SHIFT              0x00u       /* As defined by Verilog Implementation */
    #define LED_UpdateTimer_CTRL_TRIG_MODE_SHIFT           0x02u       /* As defined by Verilog Implementation */
    #define LED_UpdateTimer_CTRL_TRIG_EN_SHIFT             0x04u       /* As defined by Verilog Implementation */
    #define LED_UpdateTimer_CTRL_CAP_MODE_SHIFT            0x05u       /* As defined by Verilog Implementation */
    #define LED_UpdateTimer_CTRL_ENABLE_SHIFT              0x07u       /* As defined by Verilog Implementation */

    /* Control Register Bit Masks */
    #define LED_UpdateTimer_CTRL_INTCNT_MASK               ((uint8)((uint8)0x03u << LED_UpdateTimer_CTRL_INTCNT_SHIFT))
    #define LED_UpdateTimer_CTRL_TRIG_MODE_MASK            ((uint8)((uint8)0x03u << LED_UpdateTimer_CTRL_TRIG_MODE_SHIFT))
    #define LED_UpdateTimer_CTRL_TRIG_EN                   ((uint8)((uint8)0x01u << LED_UpdateTimer_CTRL_TRIG_EN_SHIFT))
    #define LED_UpdateTimer_CTRL_CAP_MODE_MASK             ((uint8)((uint8)0x03u << LED_UpdateTimer_CTRL_CAP_MODE_SHIFT))
    #define LED_UpdateTimer_CTRL_ENABLE                    ((uint8)((uint8)0x01u << LED_UpdateTimer_CTRL_ENABLE_SHIFT))

    /* Bit Counter (7-bit) Control Register Bit Definitions */
    /* As defined by the Register map for the AUX Control Register */
    #define LED_UpdateTimer_CNTR_ENABLE                    0x20u

    /* Status Register Bit Locations */
    #define LED_UpdateTimer_STATUS_TC_SHIFT                0x00u  /* As defined by Verilog Implementation */
    #define LED_UpdateTimer_STATUS_CAPTURE_SHIFT           0x01u  /* As defined by Verilog Implementation */
    #define LED_UpdateTimer_STATUS_TC_INT_MASK_SHIFT       LED_UpdateTimer_STATUS_TC_SHIFT
    #define LED_UpdateTimer_STATUS_CAPTURE_INT_MASK_SHIFT  LED_UpdateTimer_STATUS_CAPTURE_SHIFT
    #define LED_UpdateTimer_STATUS_FIFOFULL_SHIFT          0x02u  /* As defined by Verilog Implementation */
    #define LED_UpdateTimer_STATUS_FIFONEMP_SHIFT          0x03u  /* As defined by Verilog Implementation */
    #define LED_UpdateTimer_STATUS_FIFOFULL_INT_MASK_SHIFT LED_UpdateTimer_STATUS_FIFOFULL_SHIFT

    /* Status Register Bit Masks */
    /* Sticky TC Event Bit-Mask */
    #define LED_UpdateTimer_STATUS_TC                      ((uint8)((uint8)0x01u << LED_UpdateTimer_STATUS_TC_SHIFT))
    /* Sticky Capture Event Bit-Mask */
    #define LED_UpdateTimer_STATUS_CAPTURE                 ((uint8)((uint8)0x01u << LED_UpdateTimer_STATUS_CAPTURE_SHIFT))
    /* Interrupt Enable Bit-Mask */
    #define LED_UpdateTimer_STATUS_TC_INT_MASK             ((uint8)((uint8)0x01u << LED_UpdateTimer_STATUS_TC_SHIFT))
    /* Interrupt Enable Bit-Mask */
    #define LED_UpdateTimer_STATUS_CAPTURE_INT_MASK        ((uint8)((uint8)0x01u << LED_UpdateTimer_STATUS_CAPTURE_SHIFT))
    /* NOT-Sticky FIFO Full Bit-Mask */
    #define LED_UpdateTimer_STATUS_FIFOFULL                ((uint8)((uint8)0x01u << LED_UpdateTimer_STATUS_FIFOFULL_SHIFT))
    /* NOT-Sticky FIFO Not Empty Bit-Mask */
    #define LED_UpdateTimer_STATUS_FIFONEMP                ((uint8)((uint8)0x01u << LED_UpdateTimer_STATUS_FIFONEMP_SHIFT))
    /* Interrupt Enable Bit-Mask */
    #define LED_UpdateTimer_STATUS_FIFOFULL_INT_MASK       ((uint8)((uint8)0x01u << LED_UpdateTimer_STATUS_FIFOFULL_SHIFT))

    #define LED_UpdateTimer_STATUS_ACTL_INT_EN             0x10u   /* As defined for the ACTL Register */

    /* Datapath Auxillary Control Register definitions */
    #define LED_UpdateTimer_AUX_CTRL_FIFO0_CLR             0x01u   /* As defined by Register map */
    #define LED_UpdateTimer_AUX_CTRL_FIFO1_CLR             0x02u   /* As defined by Register map */
    #define LED_UpdateTimer_AUX_CTRL_FIFO0_LVL             0x04u   /* As defined by Register map */
    #define LED_UpdateTimer_AUX_CTRL_FIFO1_LVL             0x08u   /* As defined by Register map */
    #define LED_UpdateTimer_STATUS_ACTL_INT_EN_MASK        0x10u   /* As defined for the ACTL Register */

#endif /* Implementation Specific Registers and Register Constants */

#endif  /* CY_TIMER_LED_UpdateTimer_H */


/* [] END OF FILE */
