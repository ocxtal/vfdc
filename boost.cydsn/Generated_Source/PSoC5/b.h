/*******************************************************************************
* File Name: b.h  
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

#if !defined(CY_PINS_b_H) /* Pins b_H */
#define CY_PINS_b_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "b_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 b__PORT == 15 && ((b__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    b_Write(uint8 value);
void    b_SetDriveMode(uint8 mode);
uint8   b_ReadDataReg(void);
uint8   b_Read(void);
void    b_SetInterruptMode(uint16 position, uint16 mode);
uint8   b_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the b_SetDriveMode() function.
     *  @{
     */
        #define b_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define b_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define b_DM_RES_UP          PIN_DM_RES_UP
        #define b_DM_RES_DWN         PIN_DM_RES_DWN
        #define b_DM_OD_LO           PIN_DM_OD_LO
        #define b_DM_OD_HI           PIN_DM_OD_HI
        #define b_DM_STRONG          PIN_DM_STRONG
        #define b_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define b_MASK               b__MASK
#define b_SHIFT              b__SHIFT
#define b_WIDTH              1u

/* Interrupt constants */
#if defined(b__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in b_SetInterruptMode() function.
     *  @{
     */
        #define b_INTR_NONE      (uint16)(0x0000u)
        #define b_INTR_RISING    (uint16)(0x0001u)
        #define b_INTR_FALLING   (uint16)(0x0002u)
        #define b_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define b_INTR_MASK      (0x01u) 
#endif /* (b__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define b_PS                     (* (reg8 *) b__PS)
/* Data Register */
#define b_DR                     (* (reg8 *) b__DR)
/* Port Number */
#define b_PRT_NUM                (* (reg8 *) b__PRT) 
/* Connect to Analog Globals */                                                  
#define b_AG                     (* (reg8 *) b__AG)                       
/* Analog MUX bux enable */
#define b_AMUX                   (* (reg8 *) b__AMUX) 
/* Bidirectional Enable */                                                        
#define b_BIE                    (* (reg8 *) b__BIE)
/* Bit-mask for Aliased Register Access */
#define b_BIT_MASK               (* (reg8 *) b__BIT_MASK)
/* Bypass Enable */
#define b_BYP                    (* (reg8 *) b__BYP)
/* Port wide control signals */                                                   
#define b_CTL                    (* (reg8 *) b__CTL)
/* Drive Modes */
#define b_DM0                    (* (reg8 *) b__DM0) 
#define b_DM1                    (* (reg8 *) b__DM1)
#define b_DM2                    (* (reg8 *) b__DM2) 
/* Input Buffer Disable Override */
#define b_INP_DIS                (* (reg8 *) b__INP_DIS)
/* LCD Common or Segment Drive */
#define b_LCD_COM_SEG            (* (reg8 *) b__LCD_COM_SEG)
/* Enable Segment LCD */
#define b_LCD_EN                 (* (reg8 *) b__LCD_EN)
/* Slew Rate Control */
#define b_SLW                    (* (reg8 *) b__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define b_PRTDSI__CAPS_SEL       (* (reg8 *) b__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define b_PRTDSI__DBL_SYNC_IN    (* (reg8 *) b__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define b_PRTDSI__OE_SEL0        (* (reg8 *) b__PRTDSI__OE_SEL0) 
#define b_PRTDSI__OE_SEL1        (* (reg8 *) b__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define b_PRTDSI__OUT_SEL0       (* (reg8 *) b__PRTDSI__OUT_SEL0) 
#define b_PRTDSI__OUT_SEL1       (* (reg8 *) b__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define b_PRTDSI__SYNC_OUT       (* (reg8 *) b__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(b__SIO_CFG)
    #define b_SIO_HYST_EN        (* (reg8 *) b__SIO_HYST_EN)
    #define b_SIO_REG_HIFREQ     (* (reg8 *) b__SIO_REG_HIFREQ)
    #define b_SIO_CFG            (* (reg8 *) b__SIO_CFG)
    #define b_SIO_DIFF           (* (reg8 *) b__SIO_DIFF)
#endif /* (b__SIO_CFG) */

/* Interrupt Registers */
#if defined(b__INTSTAT)
    #define b_INTSTAT            (* (reg8 *) b__INTSTAT)
    #define b_SNAP               (* (reg8 *) b__SNAP)
    
	#define b_0_INTTYPE_REG 		(* (reg8 *) b__0__INTTYPE)
#endif /* (b__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_b_H */


/* [] END OF FILE */
