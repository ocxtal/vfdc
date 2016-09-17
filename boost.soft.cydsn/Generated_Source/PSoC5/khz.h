/*******************************************************************************
* File Name: khz.h
* Version 2.20
*
*  Description:
*   Provides the function and constant definitions for the clock component.
*
*  Note:
*
********************************************************************************
* Copyright 2008-2012, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_CLOCK_khz_H)
#define CY_CLOCK_khz_H

#include <cytypes.h>
#include <cyfitter.h>


/***************************************
* Conditional Compilation Parameters
***************************************/

/* Check to see if required defines such as CY_PSOC5LP are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5LP)
    #error Component cy_clock_v2_20 requires cy_boot v3.0 or later
#endif /* (CY_PSOC5LP) */


/***************************************
*        Function Prototypes
***************************************/

void khz_Start(void) ;
void khz_Stop(void) ;

#if(CY_PSOC3 || CY_PSOC5LP)
void khz_StopBlock(void) ;
#endif /* (CY_PSOC3 || CY_PSOC5LP) */

void khz_StandbyPower(uint8 state) ;
void khz_SetDividerRegister(uint16 clkDivider, uint8 restart) 
                                ;
uint16 khz_GetDividerRegister(void) ;
void khz_SetModeRegister(uint8 modeBitMask) ;
void khz_ClearModeRegister(uint8 modeBitMask) ;
uint8 khz_GetModeRegister(void) ;
void khz_SetSourceRegister(uint8 clkSource) ;
uint8 khz_GetSourceRegister(void) ;
#if defined(khz__CFG3)
void khz_SetPhaseRegister(uint8 clkPhase) ;
uint8 khz_GetPhaseRegister(void) ;
#endif /* defined(khz__CFG3) */

#define khz_Enable()                       khz_Start()
#define khz_Disable()                      khz_Stop()
#define khz_SetDivider(clkDivider)         khz_SetDividerRegister(clkDivider, 1u)
#define khz_SetDividerValue(clkDivider)    khz_SetDividerRegister((clkDivider) - 1u, 1u)
#define khz_SetMode(clkMode)               khz_SetModeRegister(clkMode)
#define khz_SetSource(clkSource)           khz_SetSourceRegister(clkSource)
#if defined(khz__CFG3)
#define khz_SetPhase(clkPhase)             khz_SetPhaseRegister(clkPhase)
#define khz_SetPhaseValue(clkPhase)        khz_SetPhaseRegister((clkPhase) + 1u)
#endif /* defined(khz__CFG3) */


/***************************************
*             Registers
***************************************/

/* Register to enable or disable the clock */
#define khz_CLKEN              (* (reg8 *) khz__PM_ACT_CFG)
#define khz_CLKEN_PTR          ((reg8 *) khz__PM_ACT_CFG)

/* Register to enable or disable the clock */
#define khz_CLKSTBY            (* (reg8 *) khz__PM_STBY_CFG)
#define khz_CLKSTBY_PTR        ((reg8 *) khz__PM_STBY_CFG)

/* Clock LSB divider configuration register. */
#define khz_DIV_LSB            (* (reg8 *) khz__CFG0)
#define khz_DIV_LSB_PTR        ((reg8 *) khz__CFG0)
#define khz_DIV_PTR            ((reg16 *) khz__CFG0)

/* Clock MSB divider configuration register. */
#define khz_DIV_MSB            (* (reg8 *) khz__CFG1)
#define khz_DIV_MSB_PTR        ((reg8 *) khz__CFG1)

/* Mode and source configuration register */
#define khz_MOD_SRC            (* (reg8 *) khz__CFG2)
#define khz_MOD_SRC_PTR        ((reg8 *) khz__CFG2)

#if defined(khz__CFG3)
/* Analog clock phase configuration register */
#define khz_PHASE              (* (reg8 *) khz__CFG3)
#define khz_PHASE_PTR          ((reg8 *) khz__CFG3)
#endif /* defined(khz__CFG3) */


/**************************************
*       Register Constants
**************************************/

/* Power manager register masks */
#define khz_CLKEN_MASK         khz__PM_ACT_MSK
#define khz_CLKSTBY_MASK       khz__PM_STBY_MSK

/* CFG2 field masks */
#define khz_SRC_SEL_MSK        khz__CFG2_SRC_SEL_MASK
#define khz_MODE_MASK          (~(khz_SRC_SEL_MSK))

#if defined(khz__CFG3)
/* CFG3 phase mask */
#define khz_PHASE_MASK         khz__CFG3_PHASE_DLY_MASK
#endif /* defined(khz__CFG3) */

#endif /* CY_CLOCK_khz_H */


/* [] END OF FILE */
