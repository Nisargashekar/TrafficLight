/*******************************************************************************
* File Name: LED_UpdateTimer_PM.c
* Version 2.80
*
*  Description:
*     This file provides the power management source code to API for the
*     Timer.
*
*   Note:
*     None
*
*******************************************************************************
* Copyright 2008-2017, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
********************************************************************************/

#include "LED_UpdateTimer.h"

static LED_UpdateTimer_backupStruct LED_UpdateTimer_backup;


/*******************************************************************************
* Function Name: LED_UpdateTimer_SaveConfig
********************************************************************************
*
* Summary:
*     Save the current user configuration
*
* Parameters:
*  void
*
* Return:
*  void
*
* Global variables:
*  LED_UpdateTimer_backup:  Variables of this global structure are modified to
*  store the values of non retention configuration registers when Sleep() API is
*  called.
*
*******************************************************************************/
void LED_UpdateTimer_SaveConfig(void) 
{
    #if (!LED_UpdateTimer_UsingFixedFunction)
        LED_UpdateTimer_backup.TimerUdb = LED_UpdateTimer_ReadCounter();
        LED_UpdateTimer_backup.InterruptMaskValue = LED_UpdateTimer_STATUS_MASK;
        #if (LED_UpdateTimer_UsingHWCaptureCounter)
            LED_UpdateTimer_backup.TimerCaptureCounter = LED_UpdateTimer_ReadCaptureCount();
        #endif /* Back Up capture counter register  */

        #if(!LED_UpdateTimer_UDB_CONTROL_REG_REMOVED)
            LED_UpdateTimer_backup.TimerControlRegister = LED_UpdateTimer_ReadControlRegister();
        #endif /* Backup the enable state of the Timer component */
    #endif /* Backup non retention registers in UDB implementation. All fixed function registers are retention */
}


/*******************************************************************************
* Function Name: LED_UpdateTimer_RestoreConfig
********************************************************************************
*
* Summary:
*  Restores the current user configuration.
*
* Parameters:
*  void
*
* Return:
*  void
*
* Global variables:
*  LED_UpdateTimer_backup:  Variables of this global structure are used to
*  restore the values of non retention registers on wakeup from sleep mode.
*
*******************************************************************************/
void LED_UpdateTimer_RestoreConfig(void) 
{   
    #if (!LED_UpdateTimer_UsingFixedFunction)

        LED_UpdateTimer_WriteCounter(LED_UpdateTimer_backup.TimerUdb);
        LED_UpdateTimer_STATUS_MASK =LED_UpdateTimer_backup.InterruptMaskValue;
        #if (LED_UpdateTimer_UsingHWCaptureCounter)
            LED_UpdateTimer_SetCaptureCount(LED_UpdateTimer_backup.TimerCaptureCounter);
        #endif /* Restore Capture counter register*/

        #if(!LED_UpdateTimer_UDB_CONTROL_REG_REMOVED)
            LED_UpdateTimer_WriteControlRegister(LED_UpdateTimer_backup.TimerControlRegister);
        #endif /* Restore the enable state of the Timer component */
    #endif /* Restore non retention registers in the UDB implementation only */
}


/*******************************************************************************
* Function Name: LED_UpdateTimer_Sleep
********************************************************************************
*
* Summary:
*     Stop and Save the user configuration
*
* Parameters:
*  void
*
* Return:
*  void
*
* Global variables:
*  LED_UpdateTimer_backup.TimerEnableState:  Is modified depending on the
*  enable state of the block before entering sleep mode.
*
*******************************************************************************/
void LED_UpdateTimer_Sleep(void) 
{
    #if(!LED_UpdateTimer_UDB_CONTROL_REG_REMOVED)
        /* Save Counter's enable state */
        if(LED_UpdateTimer_CTRL_ENABLE == (LED_UpdateTimer_CONTROL & LED_UpdateTimer_CTRL_ENABLE))
        {
            /* Timer is enabled */
            LED_UpdateTimer_backup.TimerEnableState = 1u;
        }
        else
        {
            /* Timer is disabled */
            LED_UpdateTimer_backup.TimerEnableState = 0u;
        }
    #endif /* Back up enable state from the Timer control register */
    LED_UpdateTimer_Stop();
    LED_UpdateTimer_SaveConfig();
}


/*******************************************************************************
* Function Name: LED_UpdateTimer_Wakeup
********************************************************************************
*
* Summary:
*  Restores and enables the user configuration
*
* Parameters:
*  void
*
* Return:
*  void
*
* Global variables:
*  LED_UpdateTimer_backup.enableState:  Is used to restore the enable state of
*  block on wakeup from sleep mode.
*
*******************************************************************************/
void LED_UpdateTimer_Wakeup(void) 
{
    LED_UpdateTimer_RestoreConfig();
    #if(!LED_UpdateTimer_UDB_CONTROL_REG_REMOVED)
        if(LED_UpdateTimer_backup.TimerEnableState == 1u)
        {     /* Enable Timer's operation */
                LED_UpdateTimer_Enable();
        } /* Do nothing if Timer was disabled before */
    #endif /* Remove this code section if Control register is removed */
}


/* [] END OF FILE */
