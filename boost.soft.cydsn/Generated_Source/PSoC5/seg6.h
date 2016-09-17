/*******************************************************************************
* File Name: seg6.h  
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

#if !defined(CY_PINS_seg6_H) /* Pins seg6_H */
#define CY_PINS_seg6_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "seg6_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 seg6__PORT == 15 && ((seg6__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    seg6_Write(uint8 value);
void    seg6_SetDriveMode(uint8 mode);
uint8   seg6_ReadDataReg(void);
uint8   seg6_Read(void);
void    seg6_SetInterruptMode(uint16 position, uint16 mode);
uint8   seg6_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the seg6_SetDriveMode() function.
     *  @{
     */
        #define seg6_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define seg6_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define seg6_DM_RES_UP          PIN_DM_RES_UP
        #define seg6_DM_RES_DWN         PIN_DM_RES_DWN
        #define seg6_DM_OD_LO           PIN_DM_OD_LO
        #define seg6_DM_OD_HI           PIN_DM_OD_HI
        #define seg6_DM_STRONG          PIN_DM_STRONG
        #define seg6_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define seg6_MASK               seg6__MASK
#define seg6_SHIFT              seg6__SHIFT
#define seg6_WIDTH              1u

/* Interrupt constants */
#if defined(seg6__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in seg6_SetInterruptMode() function.
     *  @{
     */
        #define seg6_INTR_NONE      (uint16)(0x0000u)
        #define seg6_INTR_RISING    (uint16)(0x0001u)
        #define seg6_INTR_FALLING   (uint16)(0x0002u)
        #define seg6_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define seg6_INTR_MASK      (0x01u) 
#endif /* (seg6__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define seg6_PS                     (* (reg8 *) seg6__PS)
/* Data Register */
#define seg6_DR                     (* (reg8 *) seg6__DR)
/* Port Number */
#define seg6_PRT_NUM                (* (reg8 *) seg6__PRT) 
/* Connect to Analog Globals */                                                  
#define seg6_AG                     (* (reg8 *) seg6__AG)                       
/* Analog MUX bux enable */
#define seg6_AMUX                   (* (reg8 *) seg6__AMUX) 
/* Bidirectional Enable */                                                        
#define seg6_BIE                    (* (reg8 *) seg6__BIE)
/* Bit-mask for Aliased Register Access */
#define seg6_BIT_MASK               (* (reg8 *) seg6__BIT_MASK)
/* Bypass Enable */
#define seg6_BYP                    (* (reg8 *) seg6__BYP)
/* Port wide control signals */                                                   
#define seg6_CTL                    (* (reg8 *) seg6__CTL)
/* Drive Modes */
#define seg6_DM0                    (* (reg8 *) seg6__DM0) 
#define seg6_DM1                    (* (reg8 *) seg6__DM1)
#define seg6_DM2                    (* (reg8 *) seg6__DM2) 
/* Input Buffer Disable Override */
#define seg6_INP_DIS                (* (reg8 *) seg6__INP_DIS)
/* LCD Common or Segment Drive */
#define seg6_LCD_COM_SEG            (* (reg8 *) seg6__LCD_COM_SEG)
/* Enable Segment LCD */
#define seg6_LCD_EN                 (* (reg8 *) seg6__LCD_EN)
/* Slew Rate Control */
#define seg6_SLW                    (* (reg8 *) seg6__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define seg6_PRTDSI__CAPS_SEL       (* (reg8 *) seg6__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define seg6_PRTDSI__DBL_SYNC_IN    (* (reg8 *) seg6__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define seg6_PRTDSI__OE_SEL0        (* (reg8 *) seg6__PRTDSI__OE_SEL0) 
#define seg6_PRTDSI__OE_SEL1        (* (reg8 *) seg6__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define seg6_PRTDSI__OUT_SEL0       (* (reg8 *) seg6__PRTDSI__OUT_SEL0) 
#define seg6_PRTDSI__OUT_SEL1       (* (reg8 *) seg6__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define seg6_PRTDSI__SYNC_OUT       (* (reg8 *) seg6__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(seg6__SIO_CFG)
    #define seg6_SIO_HYST_EN        (* (reg8 *) seg6__SIO_HYST_EN)
    #define seg6_SIO_REG_HIFREQ     (* (reg8 *) seg6__SIO_REG_HIFREQ)
    #define seg6_SIO_CFG            (* (reg8 *) seg6__SIO_CFG)
    #define seg6_SIO_DIFF           (* (reg8 *) seg6__SIO_DIFF)
#endif /* (seg6__SIO_CFG) */

/* Interrupt Registers */
#if defined(seg6__INTSTAT)
    #define seg6_INTSTAT            (* (reg8 *) seg6__INTSTAT)
    #define seg6_SNAP               (* (reg8 *) seg6__SNAP)
    
	#define seg6_0_INTTYPE_REG 		(* (reg8 *) seg6__0__INTTYPE)
#endif /* (seg6__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_seg6_H */


/* [] END OF FILE */
