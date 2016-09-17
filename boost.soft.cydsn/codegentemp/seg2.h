/*******************************************************************************
* File Name: seg2.h  
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

#if !defined(CY_PINS_seg2_H) /* Pins seg2_H */
#define CY_PINS_seg2_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "seg2_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 seg2__PORT == 15 && ((seg2__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    seg2_Write(uint8 value);
void    seg2_SetDriveMode(uint8 mode);
uint8   seg2_ReadDataReg(void);
uint8   seg2_Read(void);
void    seg2_SetInterruptMode(uint16 position, uint16 mode);
uint8   seg2_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the seg2_SetDriveMode() function.
     *  @{
     */
        #define seg2_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define seg2_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define seg2_DM_RES_UP          PIN_DM_RES_UP
        #define seg2_DM_RES_DWN         PIN_DM_RES_DWN
        #define seg2_DM_OD_LO           PIN_DM_OD_LO
        #define seg2_DM_OD_HI           PIN_DM_OD_HI
        #define seg2_DM_STRONG          PIN_DM_STRONG
        #define seg2_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define seg2_MASK               seg2__MASK
#define seg2_SHIFT              seg2__SHIFT
#define seg2_WIDTH              1u

/* Interrupt constants */
#if defined(seg2__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in seg2_SetInterruptMode() function.
     *  @{
     */
        #define seg2_INTR_NONE      (uint16)(0x0000u)
        #define seg2_INTR_RISING    (uint16)(0x0001u)
        #define seg2_INTR_FALLING   (uint16)(0x0002u)
        #define seg2_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define seg2_INTR_MASK      (0x01u) 
#endif /* (seg2__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define seg2_PS                     (* (reg8 *) seg2__PS)
/* Data Register */
#define seg2_DR                     (* (reg8 *) seg2__DR)
/* Port Number */
#define seg2_PRT_NUM                (* (reg8 *) seg2__PRT) 
/* Connect to Analog Globals */                                                  
#define seg2_AG                     (* (reg8 *) seg2__AG)                       
/* Analog MUX bux enable */
#define seg2_AMUX                   (* (reg8 *) seg2__AMUX) 
/* Bidirectional Enable */                                                        
#define seg2_BIE                    (* (reg8 *) seg2__BIE)
/* Bit-mask for Aliased Register Access */
#define seg2_BIT_MASK               (* (reg8 *) seg2__BIT_MASK)
/* Bypass Enable */
#define seg2_BYP                    (* (reg8 *) seg2__BYP)
/* Port wide control signals */                                                   
#define seg2_CTL                    (* (reg8 *) seg2__CTL)
/* Drive Modes */
#define seg2_DM0                    (* (reg8 *) seg2__DM0) 
#define seg2_DM1                    (* (reg8 *) seg2__DM1)
#define seg2_DM2                    (* (reg8 *) seg2__DM2) 
/* Input Buffer Disable Override */
#define seg2_INP_DIS                (* (reg8 *) seg2__INP_DIS)
/* LCD Common or Segment Drive */
#define seg2_LCD_COM_SEG            (* (reg8 *) seg2__LCD_COM_SEG)
/* Enable Segment LCD */
#define seg2_LCD_EN                 (* (reg8 *) seg2__LCD_EN)
/* Slew Rate Control */
#define seg2_SLW                    (* (reg8 *) seg2__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define seg2_PRTDSI__CAPS_SEL       (* (reg8 *) seg2__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define seg2_PRTDSI__DBL_SYNC_IN    (* (reg8 *) seg2__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define seg2_PRTDSI__OE_SEL0        (* (reg8 *) seg2__PRTDSI__OE_SEL0) 
#define seg2_PRTDSI__OE_SEL1        (* (reg8 *) seg2__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define seg2_PRTDSI__OUT_SEL0       (* (reg8 *) seg2__PRTDSI__OUT_SEL0) 
#define seg2_PRTDSI__OUT_SEL1       (* (reg8 *) seg2__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define seg2_PRTDSI__SYNC_OUT       (* (reg8 *) seg2__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(seg2__SIO_CFG)
    #define seg2_SIO_HYST_EN        (* (reg8 *) seg2__SIO_HYST_EN)
    #define seg2_SIO_REG_HIFREQ     (* (reg8 *) seg2__SIO_REG_HIFREQ)
    #define seg2_SIO_CFG            (* (reg8 *) seg2__SIO_CFG)
    #define seg2_SIO_DIFF           (* (reg8 *) seg2__SIO_DIFF)
#endif /* (seg2__SIO_CFG) */

/* Interrupt Registers */
#if defined(seg2__INTSTAT)
    #define seg2_INTSTAT            (* (reg8 *) seg2__INTSTAT)
    #define seg2_SNAP               (* (reg8 *) seg2__SNAP)
    
	#define seg2_0_INTTYPE_REG 		(* (reg8 *) seg2__0__INTTYPE)
#endif /* (seg2__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_seg2_H */


/* [] END OF FILE */