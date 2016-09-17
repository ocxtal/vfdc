/*******************************************************************************
* File Name: clk.h
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

#if !defined(CY_CLOCK_clk_H)
#define CY_CLOCK_clk_H

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

void clk_Start(void) ;
void clk_Stop(void) ;

#if(CY_PSOC3 || CY_PSOC5LP)
void clk_StopBlock(void) ;
#endif /* (CY_PSOC3 || CY_PSOC5LP) */

void clk_StandbyPower(uint8 state) ;
void clk_SetDividerRegister(uint16 clkDivider, uint8 restart) 
                                ;
uint16 clk_GetDividerRegister(void) ;
void clk_SetModeRegister(uint8 modeBitMask) ;
void clk_ClearModeRegister(uint8 modeBitMask) ;
uint8 clk_GetModeRegister(void) ;
void clk_SetSourceRegister(uint8 clkSource) ;
uint8 clk_GetSourceRegister(void) ;
#if defined(clk__CFG3)
void clk_SetPhaseRegister(uint8 clkPhase) ;
uint8 clk_GetPhaseRegister(void) ;
#endif /* defined(clk__CFG3) */

#define clk_Enable()                       clk_Start()
#define clk_Disable()                      clk_Stop()
#define clk_SetDivider(clkDivider)         clk_SetDividerRegister(clkDivider, 1u)
#define clk_SetDividerValue(clkDivider)    clk_SetDividerRegister((clkDivider) - 1u, 1u)
#define clk_SetMode(clkMode)               clk_SetModeRegister(clkMode)
#define clk_SetSource(clkSource)           clk_SetSourceRegister(clkSource)
#if defined(clk__CFG3)
#define clk_SetPhase(clkPhase)             clk_SetPhaseRegister(clkPhase)
#define clk_SetPhaseValue(clkPhase)        clk_SetPhaseRegister((clkPhase) + 1u)
#endif /* defined(clk__CFG3) */


/***************************************
*             Registers
***************************************/

/* Register to enable or disable the clock */
#define clk_CLKEN              (* (reg8 *) clk__PM_ACT_CFG)
#define clk_CLKEN_PTR          ((reg8 *) clk__PM_ACT_CFG)

/* Register to enable or disable the clock */
#define clk_CLKSTBY            (* (reg8 *) clk__PM_STBY_CFG)
#define clk_CLKSTBY_PTR        ((reg8 *) clk__PM_STBY_CFG)

/* Clock LSB divider configuration register. */
#define clk_DIV_LSB            (* (reg8 *) clk__CFG0)
#define clk_DIV_LSB_PTR        ((reg8 *) clk__CFG0)
#define clk_DIV_PTR            ((reg16 *) clk__CFG0)

/* Clock MSB divider configuration register. */
#define clk_DIV_MSB            (* (reg8 *) clk__CFG1)
#define clk_DIV_MSB_PTR        ((reg8 *) clk__CFG1)

/* Mode and source configuration register */
#define clk_MOD_SRC            (* (reg8 *) clk__CFG2)
#define clk_MOD_SRC_PTR        ((reg8 *) clk__CFG2)

#if defined(clk__CFG3)
/* Analog clock phase configuration register */
#define clk_PHASE              (* (reg8 *) clk__CFG3)
#define clk_PHASE_PTR          ((reg8 *) clk__CFG3)
#endif /* defined(clk__CFG3) */


/**************************************
*       Register Constants
**************************************/

/* Power manager register masks */
#define clk_CLKEN_MASK         clk__PM_ACT_MSK
#define clk_CLKSTBY_MASK       clk__PM_STBY_MSK

/* CFG2 field masks */
#define clk_SRC_SEL_MSK        clk__CFG2_SRC_SEL_MASK
#define clk_MODE_MASK          (~(clk_SRC_SEL_MSK))

#if defined(clk__CFG3)
/* CFG3 phase mask */
#define clk_PHASE_MASK         clk__CFG3_PHASE_DLY_MASK
#endif /* defined(clk__CFG3) */

#endif /* CY_CLOCK_clk_H */


/* [] END OF FILE */
