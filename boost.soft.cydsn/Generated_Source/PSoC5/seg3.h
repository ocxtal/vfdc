/*******************************************************************************
* File Name: seg3.h  
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

#if !defined(CY_PINS_seg3_H) /* Pins seg3_H */
#define CY_PINS_seg3_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "seg3_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 seg3__PORT == 15 && ((seg3__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    seg3_Write(uint8 value);
void    seg3_SetDriveMode(uint8 mode);
uint8   seg3_ReadDataReg(void);
uint8   seg3_Read(void);
void    seg3_SetInterruptMode(uint16 position, uint16 mode);
uint8   seg3_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the seg3_SetDriveMode() function.
     *  @{
     */
        #define seg3_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define seg3_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define seg3_DM_RES_UP          PIN_DM_RES_UP
        #define seg3_DM_RES_DWN         PIN_DM_RES_DWN
        #define seg3_DM_OD_LO           PIN_DM_OD_LO
        #define seg3_DM_OD_HI           PIN_DM_OD_HI
        #define seg3_DM_STRONG          PIN_DM_STRONG
        #define seg3_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define seg3_MASK               seg3__MASK
#define seg3_SHIFT              seg3__SHIFT
#define seg3_WIDTH              1u

/* Interrupt constants */
#if defined(seg3__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in seg3_SetInterruptMode() function.
     *  @{
     */
        #define seg3_INTR_NONE      (uint16)(0x0000u)
        #define seg3_INTR_RISING    (uint16)(0x0001u)
        #define seg3_INTR_FALLING   (uint16)(0x0002u)
        #define seg3_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define seg3_INTR_MASK      (0x01u) 
#endif /* (seg3__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define seg3_PS                     (* (reg8 *) seg3__PS)
/* Data Register */
#define seg3_DR                     (* (reg8 *) seg3__DR)
/* Port Number */
#define seg3_PRT_NUM                (* (reg8 *) seg3__PRT) 
/* Connect to Analog Globals */                                                  
#define seg3_AG                     (* (reg8 *) seg3__AG)                       
/* Analog MUX bux enable */
#define seg3_AMUX                   (* (reg8 *) seg3__AMUX) 
/* Bidirectional Enable */                                                        
#define seg3_BIE                    (* (reg8 *) seg3__BIE)
/* Bit-mask for Aliased Register Access */
#define seg3_BIT_MASK               (* (reg8 *) seg3__BIT_MASK)
/* Bypass Enable */
#define seg3_BYP                    (* (reg8 *) seg3__BYP)
/* Port wide control signals */                                                   
#define seg3_CTL                    (* (reg8 *) seg3__CTL)
/* Drive Modes */
#define seg3_DM0                    (* (reg8 *) seg3__DM0) 
#define seg3_DM1                    (* (reg8 *) seg3__DM1)
#define seg3_DM2                    (* (reg8 *) seg3__DM2) 
/* Input Buffer Disable Override */
#define seg3_INP_DIS                (* (reg8 *) seg3__INP_DIS)
/* LCD Common or Segment Drive */
#define seg3_LCD_COM_SEG            (* (reg8 *) seg3__LCD_COM_SEG)
/* Enable Segment LCD */
#define seg3_LCD_EN                 (* (reg8 *) seg3__LCD_EN)
/* Slew Rate Control */
#define seg3_SLW                    (* (reg8 *) seg3__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define seg3_PRTDSI__CAPS_SEL       (* (reg8 *) seg3__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define seg3_PRTDSI__DBL_SYNC_IN    (* (reg8 *) seg3__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define seg3_PRTDSI__OE_SEL0        (* (reg8 *) seg3__PRTDSI__OE_SEL0) 
#define seg3_PRTDSI__OE_SEL1        (* (reg8 *) seg3__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define seg3_PRTDSI__OUT_SEL0       (* (reg8 *) seg3__PRTDSI__OUT_SEL0) 
#define seg3_PRTDSI__OUT_SEL1       (* (reg8 *) seg3__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define seg3_PRTDSI__SYNC_OUT       (* (reg8 *) seg3__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(seg3__SIO_CFG)
    #define seg3_SIO_HYST_EN        (* (reg8 *) seg3__SIO_HYST_EN)
    #define seg3_SIO_REG_HIFREQ     (* (reg8 *) seg3__SIO_REG_HIFREQ)
    #define seg3_SIO_CFG            (* (reg8 *) seg3__SIO_CFG)
    #define seg3_SIO_DIFF           (* (reg8 *) seg3__SIO_DIFF)
#endif /* (seg3__SIO_CFG) */

/* Interrupt Registers */
#if defined(seg3__INTSTAT)
    #define seg3_INTSTAT            (* (reg8 *) seg3__INTSTAT)
    #define seg3_SNAP               (* (reg8 *) seg3__SNAP)
    
	#define seg3_0_INTTYPE_REG 		(* (reg8 *) seg3__0__INTTYPE)
#endif /* (seg3__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_seg3_H */


/* [] END OF FILE */
