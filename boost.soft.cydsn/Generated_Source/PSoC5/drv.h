/*******************************************************************************
* File Name: drv.h  
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

#if !defined(CY_PINS_drv_H) /* Pins drv_H */
#define CY_PINS_drv_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "drv_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 drv__PORT == 15 && ((drv__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    drv_Write(uint8 value);
void    drv_SetDriveMode(uint8 mode);
uint8   drv_ReadDataReg(void);
uint8   drv_Read(void);
void    drv_SetInterruptMode(uint16 position, uint16 mode);
uint8   drv_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the drv_SetDriveMode() function.
     *  @{
     */
        #define drv_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define drv_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define drv_DM_RES_UP          PIN_DM_RES_UP
        #define drv_DM_RES_DWN         PIN_DM_RES_DWN
        #define drv_DM_OD_LO           PIN_DM_OD_LO
        #define drv_DM_OD_HI           PIN_DM_OD_HI
        #define drv_DM_STRONG          PIN_DM_STRONG
        #define drv_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define drv_MASK               drv__MASK
#define drv_SHIFT              drv__SHIFT
#define drv_WIDTH              1u

/* Interrupt constants */
#if defined(drv__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in drv_SetInterruptMode() function.
     *  @{
     */
        #define drv_INTR_NONE      (uint16)(0x0000u)
        #define drv_INTR_RISING    (uint16)(0x0001u)
        #define drv_INTR_FALLING   (uint16)(0x0002u)
        #define drv_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define drv_INTR_MASK      (0x01u) 
#endif /* (drv__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define drv_PS                     (* (reg8 *) drv__PS)
/* Data Register */
#define drv_DR                     (* (reg8 *) drv__DR)
/* Port Number */
#define drv_PRT_NUM                (* (reg8 *) drv__PRT) 
/* Connect to Analog Globals */                                                  
#define drv_AG                     (* (reg8 *) drv__AG)                       
/* Analog MUX bux enable */
#define drv_AMUX                   (* (reg8 *) drv__AMUX) 
/* Bidirectional Enable */                                                        
#define drv_BIE                    (* (reg8 *) drv__BIE)
/* Bit-mask for Aliased Register Access */
#define drv_BIT_MASK               (* (reg8 *) drv__BIT_MASK)
/* Bypass Enable */
#define drv_BYP                    (* (reg8 *) drv__BYP)
/* Port wide control signals */                                                   
#define drv_CTL                    (* (reg8 *) drv__CTL)
/* Drive Modes */
#define drv_DM0                    (* (reg8 *) drv__DM0) 
#define drv_DM1                    (* (reg8 *) drv__DM1)
#define drv_DM2                    (* (reg8 *) drv__DM2) 
/* Input Buffer Disable Override */
#define drv_INP_DIS                (* (reg8 *) drv__INP_DIS)
/* LCD Common or Segment Drive */
#define drv_LCD_COM_SEG            (* (reg8 *) drv__LCD_COM_SEG)
/* Enable Segment LCD */
#define drv_LCD_EN                 (* (reg8 *) drv__LCD_EN)
/* Slew Rate Control */
#define drv_SLW                    (* (reg8 *) drv__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define drv_PRTDSI__CAPS_SEL       (* (reg8 *) drv__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define drv_PRTDSI__DBL_SYNC_IN    (* (reg8 *) drv__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define drv_PRTDSI__OE_SEL0        (* (reg8 *) drv__PRTDSI__OE_SEL0) 
#define drv_PRTDSI__OE_SEL1        (* (reg8 *) drv__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define drv_PRTDSI__OUT_SEL0       (* (reg8 *) drv__PRTDSI__OUT_SEL0) 
#define drv_PRTDSI__OUT_SEL1       (* (reg8 *) drv__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define drv_PRTDSI__SYNC_OUT       (* (reg8 *) drv__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(drv__SIO_CFG)
    #define drv_SIO_HYST_EN        (* (reg8 *) drv__SIO_HYST_EN)
    #define drv_SIO_REG_HIFREQ     (* (reg8 *) drv__SIO_REG_HIFREQ)
    #define drv_SIO_CFG            (* (reg8 *) drv__SIO_CFG)
    #define drv_SIO_DIFF           (* (reg8 *) drv__SIO_DIFF)
#endif /* (drv__SIO_CFG) */

/* Interrupt Registers */
#if defined(drv__INTSTAT)
    #define drv_INTSTAT            (* (reg8 *) drv__INTSTAT)
    #define drv_SNAP               (* (reg8 *) drv__SNAP)
    
	#define drv_0_INTTYPE_REG 		(* (reg8 *) drv__0__INTTYPE)
#endif /* (drv__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_drv_H */


/* [] END OF FILE */
