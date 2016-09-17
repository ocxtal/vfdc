/*******************************************************************************
* File Name: grid4.h  
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

#if !defined(CY_PINS_grid4_H) /* Pins grid4_H */
#define CY_PINS_grid4_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "grid4_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 grid4__PORT == 15 && ((grid4__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    grid4_Write(uint8 value);
void    grid4_SetDriveMode(uint8 mode);
uint8   grid4_ReadDataReg(void);
uint8   grid4_Read(void);
void    grid4_SetInterruptMode(uint16 position, uint16 mode);
uint8   grid4_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the grid4_SetDriveMode() function.
     *  @{
     */
        #define grid4_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define grid4_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define grid4_DM_RES_UP          PIN_DM_RES_UP
        #define grid4_DM_RES_DWN         PIN_DM_RES_DWN
        #define grid4_DM_OD_LO           PIN_DM_OD_LO
        #define grid4_DM_OD_HI           PIN_DM_OD_HI
        #define grid4_DM_STRONG          PIN_DM_STRONG
        #define grid4_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define grid4_MASK               grid4__MASK
#define grid4_SHIFT              grid4__SHIFT
#define grid4_WIDTH              1u

/* Interrupt constants */
#if defined(grid4__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in grid4_SetInterruptMode() function.
     *  @{
     */
        #define grid4_INTR_NONE      (uint16)(0x0000u)
        #define grid4_INTR_RISING    (uint16)(0x0001u)
        #define grid4_INTR_FALLING   (uint16)(0x0002u)
        #define grid4_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define grid4_INTR_MASK      (0x01u) 
#endif /* (grid4__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define grid4_PS                     (* (reg8 *) grid4__PS)
/* Data Register */
#define grid4_DR                     (* (reg8 *) grid4__DR)
/* Port Number */
#define grid4_PRT_NUM                (* (reg8 *) grid4__PRT) 
/* Connect to Analog Globals */                                                  
#define grid4_AG                     (* (reg8 *) grid4__AG)                       
/* Analog MUX bux enable */
#define grid4_AMUX                   (* (reg8 *) grid4__AMUX) 
/* Bidirectional Enable */                                                        
#define grid4_BIE                    (* (reg8 *) grid4__BIE)
/* Bit-mask for Aliased Register Access */
#define grid4_BIT_MASK               (* (reg8 *) grid4__BIT_MASK)
/* Bypass Enable */
#define grid4_BYP                    (* (reg8 *) grid4__BYP)
/* Port wide control signals */                                                   
#define grid4_CTL                    (* (reg8 *) grid4__CTL)
/* Drive Modes */
#define grid4_DM0                    (* (reg8 *) grid4__DM0) 
#define grid4_DM1                    (* (reg8 *) grid4__DM1)
#define grid4_DM2                    (* (reg8 *) grid4__DM2) 
/* Input Buffer Disable Override */
#define grid4_INP_DIS                (* (reg8 *) grid4__INP_DIS)
/* LCD Common or Segment Drive */
#define grid4_LCD_COM_SEG            (* (reg8 *) grid4__LCD_COM_SEG)
/* Enable Segment LCD */
#define grid4_LCD_EN                 (* (reg8 *) grid4__LCD_EN)
/* Slew Rate Control */
#define grid4_SLW                    (* (reg8 *) grid4__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define grid4_PRTDSI__CAPS_SEL       (* (reg8 *) grid4__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define grid4_PRTDSI__DBL_SYNC_IN    (* (reg8 *) grid4__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define grid4_PRTDSI__OE_SEL0        (* (reg8 *) grid4__PRTDSI__OE_SEL0) 
#define grid4_PRTDSI__OE_SEL1        (* (reg8 *) grid4__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define grid4_PRTDSI__OUT_SEL0       (* (reg8 *) grid4__PRTDSI__OUT_SEL0) 
#define grid4_PRTDSI__OUT_SEL1       (* (reg8 *) grid4__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define grid4_PRTDSI__SYNC_OUT       (* (reg8 *) grid4__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(grid4__SIO_CFG)
    #define grid4_SIO_HYST_EN        (* (reg8 *) grid4__SIO_HYST_EN)
    #define grid4_SIO_REG_HIFREQ     (* (reg8 *) grid4__SIO_REG_HIFREQ)
    #define grid4_SIO_CFG            (* (reg8 *) grid4__SIO_CFG)
    #define grid4_SIO_DIFF           (* (reg8 *) grid4__SIO_DIFF)
#endif /* (grid4__SIO_CFG) */

/* Interrupt Registers */
#if defined(grid4__INTSTAT)
    #define grid4_INTSTAT            (* (reg8 *) grid4__INTSTAT)
    #define grid4_SNAP               (* (reg8 *) grid4__SNAP)
    
	#define grid4_0_INTTYPE_REG 		(* (reg8 *) grid4__0__INTTYPE)
#endif /* (grid4__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_grid4_H */


/* [] END OF FILE */
