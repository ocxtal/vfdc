/*******************************************************************************
* File Name: tp.h  
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

#if !defined(CY_PINS_tp_H) /* Pins tp_H */
#define CY_PINS_tp_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "tp_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 tp__PORT == 15 && ((tp__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    tp_Write(uint8 value);
void    tp_SetDriveMode(uint8 mode);
uint8   tp_ReadDataReg(void);
uint8   tp_Read(void);
void    tp_SetInterruptMode(uint16 position, uint16 mode);
uint8   tp_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the tp_SetDriveMode() function.
     *  @{
     */
        #define tp_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define tp_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define tp_DM_RES_UP          PIN_DM_RES_UP
        #define tp_DM_RES_DWN         PIN_DM_RES_DWN
        #define tp_DM_OD_LO           PIN_DM_OD_LO
        #define tp_DM_OD_HI           PIN_DM_OD_HI
        #define tp_DM_STRONG          PIN_DM_STRONG
        #define tp_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define tp_MASK               tp__MASK
#define tp_SHIFT              tp__SHIFT
#define tp_WIDTH              1u

/* Interrupt constants */
#if defined(tp__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in tp_SetInterruptMode() function.
     *  @{
     */
        #define tp_INTR_NONE      (uint16)(0x0000u)
        #define tp_INTR_RISING    (uint16)(0x0001u)
        #define tp_INTR_FALLING   (uint16)(0x0002u)
        #define tp_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define tp_INTR_MASK      (0x01u) 
#endif /* (tp__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define tp_PS                     (* (reg8 *) tp__PS)
/* Data Register */
#define tp_DR                     (* (reg8 *) tp__DR)
/* Port Number */
#define tp_PRT_NUM                (* (reg8 *) tp__PRT) 
/* Connect to Analog Globals */                                                  
#define tp_AG                     (* (reg8 *) tp__AG)                       
/* Analog MUX bux enable */
#define tp_AMUX                   (* (reg8 *) tp__AMUX) 
/* Bidirectional Enable */                                                        
#define tp_BIE                    (* (reg8 *) tp__BIE)
/* Bit-mask for Aliased Register Access */
#define tp_BIT_MASK               (* (reg8 *) tp__BIT_MASK)
/* Bypass Enable */
#define tp_BYP                    (* (reg8 *) tp__BYP)
/* Port wide control signals */                                                   
#define tp_CTL                    (* (reg8 *) tp__CTL)
/* Drive Modes */
#define tp_DM0                    (* (reg8 *) tp__DM0) 
#define tp_DM1                    (* (reg8 *) tp__DM1)
#define tp_DM2                    (* (reg8 *) tp__DM2) 
/* Input Buffer Disable Override */
#define tp_INP_DIS                (* (reg8 *) tp__INP_DIS)
/* LCD Common or Segment Drive */
#define tp_LCD_COM_SEG            (* (reg8 *) tp__LCD_COM_SEG)
/* Enable Segment LCD */
#define tp_LCD_EN                 (* (reg8 *) tp__LCD_EN)
/* Slew Rate Control */
#define tp_SLW                    (* (reg8 *) tp__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define tp_PRTDSI__CAPS_SEL       (* (reg8 *) tp__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define tp_PRTDSI__DBL_SYNC_IN    (* (reg8 *) tp__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define tp_PRTDSI__OE_SEL0        (* (reg8 *) tp__PRTDSI__OE_SEL0) 
#define tp_PRTDSI__OE_SEL1        (* (reg8 *) tp__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define tp_PRTDSI__OUT_SEL0       (* (reg8 *) tp__PRTDSI__OUT_SEL0) 
#define tp_PRTDSI__OUT_SEL1       (* (reg8 *) tp__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define tp_PRTDSI__SYNC_OUT       (* (reg8 *) tp__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(tp__SIO_CFG)
    #define tp_SIO_HYST_EN        (* (reg8 *) tp__SIO_HYST_EN)
    #define tp_SIO_REG_HIFREQ     (* (reg8 *) tp__SIO_REG_HIFREQ)
    #define tp_SIO_CFG            (* (reg8 *) tp__SIO_CFG)
    #define tp_SIO_DIFF           (* (reg8 *) tp__SIO_DIFF)
#endif /* (tp__SIO_CFG) */

/* Interrupt Registers */
#if defined(tp__INTSTAT)
    #define tp_INTSTAT            (* (reg8 *) tp__INTSTAT)
    #define tp_SNAP               (* (reg8 *) tp__SNAP)
    
	#define tp_0_INTTYPE_REG 		(* (reg8 *) tp__0__INTTYPE)
#endif /* (tp__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_tp_H */


/* [] END OF FILE */
