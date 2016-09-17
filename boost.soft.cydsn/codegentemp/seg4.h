/*******************************************************************************
* File Name: seg4.h  
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

#if !defined(CY_PINS_seg4_H) /* Pins seg4_H */
#define CY_PINS_seg4_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "seg4_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 seg4__PORT == 15 && ((seg4__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    seg4_Write(uint8 value);
void    seg4_SetDriveMode(uint8 mode);
uint8   seg4_ReadDataReg(void);
uint8   seg4_Read(void);
void    seg4_SetInterruptMode(uint16 position, uint16 mode);
uint8   seg4_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the seg4_SetDriveMode() function.
     *  @{
     */
        #define seg4_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define seg4_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define seg4_DM_RES_UP          PIN_DM_RES_UP
        #define seg4_DM_RES_DWN         PIN_DM_RES_DWN
        #define seg4_DM_OD_LO           PIN_DM_OD_LO
        #define seg4_DM_OD_HI           PIN_DM_OD_HI
        #define seg4_DM_STRONG          PIN_DM_STRONG
        #define seg4_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define seg4_MASK               seg4__MASK
#define seg4_SHIFT              seg4__SHIFT
#define seg4_WIDTH              1u

/* Interrupt constants */
#if defined(seg4__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in seg4_SetInterruptMode() function.
     *  @{
     */
        #define seg4_INTR_NONE      (uint16)(0x0000u)
        #define seg4_INTR_RISING    (uint16)(0x0001u)
        #define seg4_INTR_FALLING   (uint16)(0x0002u)
        #define seg4_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define seg4_INTR_MASK      (0x01u) 
#endif /* (seg4__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define seg4_PS                     (* (reg8 *) seg4__PS)
/* Data Register */
#define seg4_DR                     (* (reg8 *) seg4__DR)
/* Port Number */
#define seg4_PRT_NUM                (* (reg8 *) seg4__PRT) 
/* Connect to Analog Globals */                                                  
#define seg4_AG                     (* (reg8 *) seg4__AG)                       
/* Analog MUX bux enable */
#define seg4_AMUX                   (* (reg8 *) seg4__AMUX) 
/* Bidirectional Enable */                                                        
#define seg4_BIE                    (* (reg8 *) seg4__BIE)
/* Bit-mask for Aliased Register Access */
#define seg4_BIT_MASK               (* (reg8 *) seg4__BIT_MASK)
/* Bypass Enable */
#define seg4_BYP                    (* (reg8 *) seg4__BYP)
/* Port wide control signals */                                                   
#define seg4_CTL                    (* (reg8 *) seg4__CTL)
/* Drive Modes */
#define seg4_DM0                    (* (reg8 *) seg4__DM0) 
#define seg4_DM1                    (* (reg8 *) seg4__DM1)
#define seg4_DM2                    (* (reg8 *) seg4__DM2) 
/* Input Buffer Disable Override */
#define seg4_INP_DIS                (* (reg8 *) seg4__INP_DIS)
/* LCD Common or Segment Drive */
#define seg4_LCD_COM_SEG            (* (reg8 *) seg4__LCD_COM_SEG)
/* Enable Segment LCD */
#define seg4_LCD_EN                 (* (reg8 *) seg4__LCD_EN)
/* Slew Rate Control */
#define seg4_SLW                    (* (reg8 *) seg4__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define seg4_PRTDSI__CAPS_SEL       (* (reg8 *) seg4__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define seg4_PRTDSI__DBL_SYNC_IN    (* (reg8 *) seg4__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define seg4_PRTDSI__OE_SEL0        (* (reg8 *) seg4__PRTDSI__OE_SEL0) 
#define seg4_PRTDSI__OE_SEL1        (* (reg8 *) seg4__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define seg4_PRTDSI__OUT_SEL0       (* (reg8 *) seg4__PRTDSI__OUT_SEL0) 
#define seg4_PRTDSI__OUT_SEL1       (* (reg8 *) seg4__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define seg4_PRTDSI__SYNC_OUT       (* (reg8 *) seg4__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(seg4__SIO_CFG)
    #define seg4_SIO_HYST_EN        (* (reg8 *) seg4__SIO_HYST_EN)
    #define seg4_SIO_REG_HIFREQ     (* (reg8 *) seg4__SIO_REG_HIFREQ)
    #define seg4_SIO_CFG            (* (reg8 *) seg4__SIO_CFG)
    #define seg4_SIO_DIFF           (* (reg8 *) seg4__SIO_DIFF)
#endif /* (seg4__SIO_CFG) */

/* Interrupt Registers */
#if defined(seg4__INTSTAT)
    #define seg4_INTSTAT            (* (reg8 *) seg4__INTSTAT)
    #define seg4_SNAP               (* (reg8 *) seg4__SNAP)
    
	#define seg4_0_INTTYPE_REG 		(* (reg8 *) seg4__0__INTTYPE)
#endif /* (seg4__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_seg4_H */


/* [] END OF FILE */
