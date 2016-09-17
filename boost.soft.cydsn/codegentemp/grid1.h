/*******************************************************************************
* File Name: grid1.h  
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

#if !defined(CY_PINS_grid1_H) /* Pins grid1_H */
#define CY_PINS_grid1_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "grid1_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 grid1__PORT == 15 && ((grid1__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    grid1_Write(uint8 value);
void    grid1_SetDriveMode(uint8 mode);
uint8   grid1_ReadDataReg(void);
uint8   grid1_Read(void);
void    grid1_SetInterruptMode(uint16 position, uint16 mode);
uint8   grid1_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the grid1_SetDriveMode() function.
     *  @{
     */
        #define grid1_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define grid1_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define grid1_DM_RES_UP          PIN_DM_RES_UP
        #define grid1_DM_RES_DWN         PIN_DM_RES_DWN
        #define grid1_DM_OD_LO           PIN_DM_OD_LO
        #define grid1_DM_OD_HI           PIN_DM_OD_HI
        #define grid1_DM_STRONG          PIN_DM_STRONG
        #define grid1_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define grid1_MASK               grid1__MASK
#define grid1_SHIFT              grid1__SHIFT
#define grid1_WIDTH              1u

/* Interrupt constants */
#if defined(grid1__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in grid1_SetInterruptMode() function.
     *  @{
     */
        #define grid1_INTR_NONE      (uint16)(0x0000u)
        #define grid1_INTR_RISING    (uint16)(0x0001u)
        #define grid1_INTR_FALLING   (uint16)(0x0002u)
        #define grid1_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define grid1_INTR_MASK      (0x01u) 
#endif /* (grid1__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define grid1_PS                     (* (reg8 *) grid1__PS)
/* Data Register */
#define grid1_DR                     (* (reg8 *) grid1__DR)
/* Port Number */
#define grid1_PRT_NUM                (* (reg8 *) grid1__PRT) 
/* Connect to Analog Globals */                                                  
#define grid1_AG                     (* (reg8 *) grid1__AG)                       
/* Analog MUX bux enable */
#define grid1_AMUX                   (* (reg8 *) grid1__AMUX) 
/* Bidirectional Enable */                                                        
#define grid1_BIE                    (* (reg8 *) grid1__BIE)
/* Bit-mask for Aliased Register Access */
#define grid1_BIT_MASK               (* (reg8 *) grid1__BIT_MASK)
/* Bypass Enable */
#define grid1_BYP                    (* (reg8 *) grid1__BYP)
/* Port wide control signals */                                                   
#define grid1_CTL                    (* (reg8 *) grid1__CTL)
/* Drive Modes */
#define grid1_DM0                    (* (reg8 *) grid1__DM0) 
#define grid1_DM1                    (* (reg8 *) grid1__DM1)
#define grid1_DM2                    (* (reg8 *) grid1__DM2) 
/* Input Buffer Disable Override */
#define grid1_INP_DIS                (* (reg8 *) grid1__INP_DIS)
/* LCD Common or Segment Drive */
#define grid1_LCD_COM_SEG            (* (reg8 *) grid1__LCD_COM_SEG)
/* Enable Segment LCD */
#define grid1_LCD_EN                 (* (reg8 *) grid1__LCD_EN)
/* Slew Rate Control */
#define grid1_SLW                    (* (reg8 *) grid1__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define grid1_PRTDSI__CAPS_SEL       (* (reg8 *) grid1__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define grid1_PRTDSI__DBL_SYNC_IN    (* (reg8 *) grid1__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define grid1_PRTDSI__OE_SEL0        (* (reg8 *) grid1__PRTDSI__OE_SEL0) 
#define grid1_PRTDSI__OE_SEL1        (* (reg8 *) grid1__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define grid1_PRTDSI__OUT_SEL0       (* (reg8 *) grid1__PRTDSI__OUT_SEL0) 
#define grid1_PRTDSI__OUT_SEL1       (* (reg8 *) grid1__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define grid1_PRTDSI__SYNC_OUT       (* (reg8 *) grid1__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(grid1__SIO_CFG)
    #define grid1_SIO_HYST_EN        (* (reg8 *) grid1__SIO_HYST_EN)
    #define grid1_SIO_REG_HIFREQ     (* (reg8 *) grid1__SIO_REG_HIFREQ)
    #define grid1_SIO_CFG            (* (reg8 *) grid1__SIO_CFG)
    #define grid1_SIO_DIFF           (* (reg8 *) grid1__SIO_DIFF)
#endif /* (grid1__SIO_CFG) */

/* Interrupt Registers */
#if defined(grid1__INTSTAT)
    #define grid1_INTSTAT            (* (reg8 *) grid1__INTSTAT)
    #define grid1_SNAP               (* (reg8 *) grid1__SNAP)
    
	#define grid1_0_INTTYPE_REG 		(* (reg8 *) grid1__0__INTTYPE)
#endif /* (grid1__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_grid1_H */


/* [] END OF FILE */
