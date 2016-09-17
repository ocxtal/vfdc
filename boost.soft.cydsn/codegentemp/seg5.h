/*******************************************************************************
* File Name: seg5.h  
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

#if !defined(CY_PINS_seg5_H) /* Pins seg5_H */
#define CY_PINS_seg5_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "seg5_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 seg5__PORT == 15 && ((seg5__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    seg5_Write(uint8 value);
void    seg5_SetDriveMode(uint8 mode);
uint8   seg5_ReadDataReg(void);
uint8   seg5_Read(void);
void    seg5_SetInterruptMode(uint16 position, uint16 mode);
uint8   seg5_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the seg5_SetDriveMode() function.
     *  @{
     */
        #define seg5_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define seg5_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define seg5_DM_RES_UP          PIN_DM_RES_UP
        #define seg5_DM_RES_DWN         PIN_DM_RES_DWN
        #define seg5_DM_OD_LO           PIN_DM_OD_LO
        #define seg5_DM_OD_HI           PIN_DM_OD_HI
        #define seg5_DM_STRONG          PIN_DM_STRONG
        #define seg5_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define seg5_MASK               seg5__MASK
#define seg5_SHIFT              seg5__SHIFT
#define seg5_WIDTH              1u

/* Interrupt constants */
#if defined(seg5__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in seg5_SetInterruptMode() function.
     *  @{
     */
        #define seg5_INTR_NONE      (uint16)(0x0000u)
        #define seg5_INTR_RISING    (uint16)(0x0001u)
        #define seg5_INTR_FALLING   (uint16)(0x0002u)
        #define seg5_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define seg5_INTR_MASK      (0x01u) 
#endif /* (seg5__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define seg5_PS                     (* (reg8 *) seg5__PS)
/* Data Register */
#define seg5_DR                     (* (reg8 *) seg5__DR)
/* Port Number */
#define seg5_PRT_NUM                (* (reg8 *) seg5__PRT) 
/* Connect to Analog Globals */                                                  
#define seg5_AG                     (* (reg8 *) seg5__AG)                       
/* Analog MUX bux enable */
#define seg5_AMUX                   (* (reg8 *) seg5__AMUX) 
/* Bidirectional Enable */                                                        
#define seg5_BIE                    (* (reg8 *) seg5__BIE)
/* Bit-mask for Aliased Register Access */
#define seg5_BIT_MASK               (* (reg8 *) seg5__BIT_MASK)
/* Bypass Enable */
#define seg5_BYP                    (* (reg8 *) seg5__BYP)
/* Port wide control signals */                                                   
#define seg5_CTL                    (* (reg8 *) seg5__CTL)
/* Drive Modes */
#define seg5_DM0                    (* (reg8 *) seg5__DM0) 
#define seg5_DM1                    (* (reg8 *) seg5__DM1)
#define seg5_DM2                    (* (reg8 *) seg5__DM2) 
/* Input Buffer Disable Override */
#define seg5_INP_DIS                (* (reg8 *) seg5__INP_DIS)
/* LCD Common or Segment Drive */
#define seg5_LCD_COM_SEG            (* (reg8 *) seg5__LCD_COM_SEG)
/* Enable Segment LCD */
#define seg5_LCD_EN                 (* (reg8 *) seg5__LCD_EN)
/* Slew Rate Control */
#define seg5_SLW                    (* (reg8 *) seg5__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define seg5_PRTDSI__CAPS_SEL       (* (reg8 *) seg5__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define seg5_PRTDSI__DBL_SYNC_IN    (* (reg8 *) seg5__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define seg5_PRTDSI__OE_SEL0        (* (reg8 *) seg5__PRTDSI__OE_SEL0) 
#define seg5_PRTDSI__OE_SEL1        (* (reg8 *) seg5__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define seg5_PRTDSI__OUT_SEL0       (* (reg8 *) seg5__PRTDSI__OUT_SEL0) 
#define seg5_PRTDSI__OUT_SEL1       (* (reg8 *) seg5__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define seg5_PRTDSI__SYNC_OUT       (* (reg8 *) seg5__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(seg5__SIO_CFG)
    #define seg5_SIO_HYST_EN        (* (reg8 *) seg5__SIO_HYST_EN)
    #define seg5_SIO_REG_HIFREQ     (* (reg8 *) seg5__SIO_REG_HIFREQ)
    #define seg5_SIO_CFG            (* (reg8 *) seg5__SIO_CFG)
    #define seg5_SIO_DIFF           (* (reg8 *) seg5__SIO_DIFF)
#endif /* (seg5__SIO_CFG) */

/* Interrupt Registers */
#if defined(seg5__INTSTAT)
    #define seg5_INTSTAT            (* (reg8 *) seg5__INTSTAT)
    #define seg5_SNAP               (* (reg8 *) seg5__SNAP)
    
	#define seg5_0_INTTYPE_REG 		(* (reg8 *) seg5__0__INTTYPE)
#endif /* (seg5__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_seg5_H */


/* [] END OF FILE */
