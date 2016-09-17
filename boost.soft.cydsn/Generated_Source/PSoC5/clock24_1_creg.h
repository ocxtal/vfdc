/*******************************************************************************
* File Name: clock24_1_creg.h  
* Version 1.80
*
* Description:
*  This file containts Control Register function prototypes and register defines
*
* Note:
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_CONTROL_REG_clock24_1_creg_H) /* CY_CONTROL_REG_clock24_1_creg_H */
#define CY_CONTROL_REG_clock24_1_creg_H

#include "cytypes.h"

    
/***************************************
*     Data Struct Definitions
***************************************/

/* Sleep Mode API Support */
typedef struct
{
    uint8 controlState;

} clock24_1_creg_BACKUP_STRUCT;


/***************************************
*         Function Prototypes 
***************************************/

void    clock24_1_creg_Write(uint8 control) ;
uint8   clock24_1_creg_Read(void) ;

void clock24_1_creg_SaveConfig(void) ;
void clock24_1_creg_RestoreConfig(void) ;
void clock24_1_creg_Sleep(void) ; 
void clock24_1_creg_Wakeup(void) ;


/***************************************
*            Registers        
***************************************/

/* Control Register */
#define clock24_1_creg_Control        (* (reg8 *) clock24_1_creg_Sync_ctrl_reg__CONTROL_REG )
#define clock24_1_creg_Control_PTR    (  (reg8 *) clock24_1_creg_Sync_ctrl_reg__CONTROL_REG )

#endif /* End CY_CONTROL_REG_clock24_1_creg_H */


/* [] END OF FILE */
