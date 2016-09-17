/*******************************************************************************
* File Name: seg1.h  
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

#if !defined(CY_PINS_seg1_H) /* Pins seg1_H */
#define CY_PINS_seg1_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "seg1_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 seg1__PORT == 15 && ((seg1__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    seg1_Write(uint8 value);
void    seg1_SetDriveMode(uint8 mode);
uint8   seg1_ReadDataReg(void);
uint8   seg1_Read(void);
void    seg1_SetInterruptMode(uint16 position, uint16 mode);
uint8   seg1_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the seg1_SetDriveMode() function.
     *  @{
     */
        #define seg1_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define seg1_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define seg1_DM_RES_UP          PIN_DM_RES_UP
        #define seg1_DM_RES_DWN         PIN_DM_RES_DWN
        #define seg1_DM_OD_LO           PIN_DM_OD_LO
        #define seg1_DM_OD_HI           PIN_DM_OD_HI
        #define seg1_DM_STRONG          PIN_DM_STRONG
        #define seg1_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define seg1_MASK               seg1__MASK
#define seg1_SHIFT              seg1__SHIFT
#define seg1_WIDTH              1u

/* Interrupt constants */
#if defined(seg1__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in seg1_SetInterruptMode() function.
     *  @{
     */
        #define seg1_INTR_NONE      (uint16)(0x0000u)
        #define seg1_INTR_RISING    (uint16)(0x0001u)
        #define seg1_INTR_FALLING   (uint16)(0x0002u)
        #define seg1_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define seg1_INTR_MASK      (0x01u) 
#endif /* (seg1__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define seg1_PS                     (* (reg8 *) seg1__PS)
/* Data Register */
#define seg1_DR                     (* (reg8 *) seg1__DR)
/* Port Number */
#define seg1_PRT_NUM                (* (reg8 *) seg1__PRT) 
/* Connect to Analog Globals */                                                  
#define seg1_AG                     (* (reg8 *) seg1__AG)                       
/* Analog MUX bux enable */
#define seg1_AMUX                   (* (reg8 *) seg1__AMUX) 
/* Bidirectional Enable */                                                        
#define seg1_BIE                    (* (reg8 *) seg1__BIE)
/* Bit-mask for Aliased Register Access */
#define seg1_BIT_MASK               (* (reg8 *) seg1__BIT_MASK)
/* Bypass Enable */
#define seg1_BYP                    (* (reg8 *) seg1__BYP)
/* Port wide control signals */                                                   
#define seg1_CTL                    (* (reg8 *) seg1__CTL)
/* Drive Modes */
#define seg1_DM0                    (* (reg8 *) seg1__DM0) 
#define seg1_DM1                    (* (reg8 *) seg1__DM1)
#define seg1_DM2                    (* (reg8 *) seg1__DM2) 
/* Input Buffer Disable Override */
#define seg1_INP_DIS                (* (reg8 *) seg1__INP_DIS)
/* LCD Common or Segment Drive */
#define seg1_LCD_COM_SEG            (* (reg8 *) seg1__LCD_COM_SEG)
/* Enable Segment LCD */
#define seg1_LCD_EN                 (* (reg8 *) seg1__LCD_EN)
/* Slew Rate Control */
#define seg1_SLW                    (* (reg8 *) seg1__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define seg1_PRTDSI__CAPS_SEL       (* (reg8 *) seg1__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define seg1_PRTDSI__DBL_SYNC_IN    (* (reg8 *) seg1__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define seg1_PRTDSI__OE_SEL0        (* (reg8 *) seg1__PRTDSI__OE_SEL0) 
#define seg1_PRTDSI__OE_SEL1        (* (reg8 *) seg1__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define seg1_PRTDSI__OUT_SEL0       (* (reg8 *) seg1__PRTDSI__OUT_SEL0) 
#define seg1_PRTDSI__OUT_SEL1       (* (reg8 *) seg1__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define seg1_PRTDSI__SYNC_OUT       (* (reg8 *) seg1__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(seg1__SIO_CFG)
    #define seg1_SIO_HYST_EN        (* (reg8 *) seg1__SIO_HYST_EN)
    #define seg1_SIO_REG_HIFREQ     (* (reg8 *) seg1__SIO_REG_HIFREQ)
    #define seg1_SIO_CFG            (* (reg8 *) seg1__SIO_CFG)
    #define seg1_SIO_DIFF           (* (reg8 *) seg1__SIO_DIFF)
#endif /* (seg1__SIO_CFG) */

/* Interrupt Registers */
#if defined(seg1__INTSTAT)
    #define seg1_INTSTAT            (* (reg8 *) seg1__INTSTAT)
    #define seg1_SNAP               (* (reg8 *) seg1__SNAP)
    
	#define seg1_0_INTTYPE_REG 		(* (reg8 *) seg1__0__INTTYPE)
#endif /* (seg1__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_seg1_H */


/* [] END OF FILE */
