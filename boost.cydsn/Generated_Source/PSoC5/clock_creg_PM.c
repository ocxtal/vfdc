/*******************************************************************************
* File Name: clock_creg_PM.c
* Version 1.80
*
* Description:
*  This file contains the setup, control, and status commands to support 
*  the component operation in the low power mode. 
*
* Note:
*
********************************************************************************
* Copyright 2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#include "clock_creg.h"

/* Check for removal by optimization */
#if !defined(clock_creg_Sync_ctrl_reg__REMOVED)

static clock_creg_BACKUP_STRUCT  clock_creg_backup = {0u};

    
/*******************************************************************************
* Function Name: clock_creg_SaveConfig
********************************************************************************
*
* Summary:
*  Saves the control register value.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void clock_creg_SaveConfig(void) 
{
    clock_creg_backup.controlState = clock_creg_Control;
}


/*******************************************************************************
* Function Name: clock_creg_RestoreConfig
********************************************************************************
*
* Summary:
*  Restores the control register value.
*
* Parameters:
*  None
*
* Return:
*  None
*
*
*******************************************************************************/
void clock_creg_RestoreConfig(void) 
{
     clock_creg_Control = clock_creg_backup.controlState;
}


/*******************************************************************************
* Function Name: clock_creg_Sleep
********************************************************************************
*
* Summary:
*  Prepares the component for entering the low power mode.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void clock_creg_Sleep(void) 
{
    clock_creg_SaveConfig();
}


/*******************************************************************************
* Function Name: clock_creg_Wakeup
********************************************************************************
*
* Summary:
*  Restores the component after waking up from the low power mode.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void clock_creg_Wakeup(void)  
{
    clock_creg_RestoreConfig();
}

#endif /* End check for removal by optimization */


/* [] END OF FILE */
