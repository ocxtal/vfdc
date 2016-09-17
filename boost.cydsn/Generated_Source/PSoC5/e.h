/*******************************************************************************
* File Name: e.h  
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

#if !defined(CY_PINS_e_H) /* Pins e_H */
#define CY_PINS_e_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "e_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 e__PORT == 15 && ((e__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    e_Write(uint8 value);
void    e_SetDriveMode(uint8 mode);
uint8   e_ReadDataReg(void);
uint8   e_Read(void);
void    e_SetInterruptMode(uint16 position, uint16 mode);
uint8   e_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the e_SetDriveMode() function.
     *  @{
     */
        #define e_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define e_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define e_DM_RES_UP          PIN_DM_RES_UP
        #define e_DM_RES_DWN         PIN_DM_RES_DWN
        #define e_DM_OD_LO           PIN_DM_OD_LO
        #define e_DM_OD_HI           PIN_DM_OD_HI
        #define e_DM_STRONG          PIN_DM_STRONG
        #define e_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define e_MASK               e__MASK
#define e_SHIFT              e__SHIFT
#define e_WIDTH              1u

/* Interrupt constants */
#if defined(e__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in e_SetInterruptMode() function.
     *  @{
     */
        #define e_INTR_NONE      (uint16)(0x0000u)
        #define e_INTR_RISING    (uint16)(0x0001u)
        #define e_INTR_FALLING   (uint16)(0x0002u)
        #define e_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define e_INTR_MASK      (0x01u) 
#endif /* (e__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define e_PS                     (* (reg8 *) e__PS)
/* Data Register */
#define e_DR                     (* (reg8 *) e__DR)
/* Port Number */
#define e_PRT_NUM                (* (reg8 *) e__PRT) 
/* Connect to Analog Globals */                                                  
#define e_AG                     (* (reg8 *) e__AG)                       
/* Analog MUX bux enable */
#define e_AMUX                   (* (reg8 *) e__AMUX) 
/* Bidirectional Enable */                                                        
#define e_BIE                    (* (reg8 *) e__BIE)
/* Bit-mask for Aliased Register Access */
#define e_BIT_MASK               (* (reg8 *) e__BIT_MASK)
/* Bypass Enable */
#define e_BYP                    (* (reg8 *) e__BYP)
/* Port wide control signals */                                                   
#define e_CTL                    (* (reg8 *) e__CTL)
/* Drive Modes */
#define e_DM0                    (* (reg8 *) e__DM0) 
#define e_DM1                    (* (reg8 *) e__DM1)
#define e_DM2                    (* (reg8 *) e__DM2) 
/* Input Buffer Disable Override */
#define e_INP_DIS                (* (reg8 *) e__INP_DIS)
/* LCD Common or Segment Drive */
#define e_LCD_COM_SEG            (* (reg8 *) e__LCD_COM_SEG)
/* Enable Segment LCD */
#define e_LCD_EN                 (* (reg8 *) e__LCD_EN)
/* Slew Rate Control */
#define e_SLW                    (* (reg8 *) e__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define e_PRTDSI__CAPS_SEL       (* (reg8 *) e__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define e_PRTDSI__DBL_SYNC_IN    (* (reg8 *) e__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define e_PRTDSI__OE_SEL0        (* (reg8 *) e__PRTDSI__OE_SEL0) 
#define e_PRTDSI__OE_SEL1        (* (reg8 *) e__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define e_PRTDSI__OUT_SEL0       (* (reg8 *) e__PRTDSI__OUT_SEL0) 
#define e_PRTDSI__OUT_SEL1       (* (reg8 *) e__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define e_PRTDSI__SYNC_OUT       (* (reg8 *) e__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(e__SIO_CFG)
    #define e_SIO_HYST_EN        (* (reg8 *) e__SIO_HYST_EN)
    #define e_SIO_REG_HIFREQ     (* (reg8 *) e__SIO_REG_HIFREQ)
    #define e_SIO_CFG            (* (reg8 *) e__SIO_CFG)
    #define e_SIO_DIFF           (* (reg8 *) e__SIO_DIFF)
#endif /* (e__SIO_CFG) */

/* Interrupt Registers */
#if defined(e__INTSTAT)
    #define e_INTSTAT            (* (reg8 *) e__INTSTAT)
    #define e_SNAP               (* (reg8 *) e__SNAP)
    
	#define e_0_INTTYPE_REG 		(* (reg8 *) e__0__INTTYPE)
#endif /* (e__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_e_H */


/* [] END OF FILE */
