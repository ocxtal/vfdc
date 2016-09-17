/*******************************************************************************
* File Name: c.h  
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

#if !defined(CY_PINS_c_H) /* Pins c_H */
#define CY_PINS_c_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "c_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 c__PORT == 15 && ((c__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    c_Write(uint8 value);
void    c_SetDriveMode(uint8 mode);
uint8   c_ReadDataReg(void);
uint8   c_Read(void);
void    c_SetInterruptMode(uint16 position, uint16 mode);
uint8   c_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the c_SetDriveMode() function.
     *  @{
     */
        #define c_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define c_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define c_DM_RES_UP          PIN_DM_RES_UP
        #define c_DM_RES_DWN         PIN_DM_RES_DWN
        #define c_DM_OD_LO           PIN_DM_OD_LO
        #define c_DM_OD_HI           PIN_DM_OD_HI
        #define c_DM_STRONG          PIN_DM_STRONG
        #define c_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define c_MASK               c__MASK
#define c_SHIFT              c__SHIFT
#define c_WIDTH              1u

/* Interrupt constants */
#if defined(c__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in c_SetInterruptMode() function.
     *  @{
     */
        #define c_INTR_NONE      (uint16)(0x0000u)
        #define c_INTR_RISING    (uint16)(0x0001u)
        #define c_INTR_FALLING   (uint16)(0x0002u)
        #define c_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define c_INTR_MASK      (0x01u) 
#endif /* (c__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define c_PS                     (* (reg8 *) c__PS)
/* Data Register */
#define c_DR                     (* (reg8 *) c__DR)
/* Port Number */
#define c_PRT_NUM                (* (reg8 *) c__PRT) 
/* Connect to Analog Globals */                                                  
#define c_AG                     (* (reg8 *) c__AG)                       
/* Analog MUX bux enable */
#define c_AMUX                   (* (reg8 *) c__AMUX) 
/* Bidirectional Enable */                                                        
#define c_BIE                    (* (reg8 *) c__BIE)
/* Bit-mask for Aliased Register Access */
#define c_BIT_MASK               (* (reg8 *) c__BIT_MASK)
/* Bypass Enable */
#define c_BYP                    (* (reg8 *) c__BYP)
/* Port wide control signals */                                                   
#define c_CTL                    (* (reg8 *) c__CTL)
/* Drive Modes */
#define c_DM0                    (* (reg8 *) c__DM0) 
#define c_DM1                    (* (reg8 *) c__DM1)
#define c_DM2                    (* (reg8 *) c__DM2) 
/* Input Buffer Disable Override */
#define c_INP_DIS                (* (reg8 *) c__INP_DIS)
/* LCD Common or Segment Drive */
#define c_LCD_COM_SEG            (* (reg8 *) c__LCD_COM_SEG)
/* Enable Segment LCD */
#define c_LCD_EN                 (* (reg8 *) c__LCD_EN)
/* Slew Rate Control */
#define c_SLW                    (* (reg8 *) c__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define c_PRTDSI__CAPS_SEL       (* (reg8 *) c__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define c_PRTDSI__DBL_SYNC_IN    (* (reg8 *) c__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define c_PRTDSI__OE_SEL0        (* (reg8 *) c__PRTDSI__OE_SEL0) 
#define c_PRTDSI__OE_SEL1        (* (reg8 *) c__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define c_PRTDSI__OUT_SEL0       (* (reg8 *) c__PRTDSI__OUT_SEL0) 
#define c_PRTDSI__OUT_SEL1       (* (reg8 *) c__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define c_PRTDSI__SYNC_OUT       (* (reg8 *) c__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(c__SIO_CFG)
    #define c_SIO_HYST_EN        (* (reg8 *) c__SIO_HYST_EN)
    #define c_SIO_REG_HIFREQ     (* (reg8 *) c__SIO_REG_HIFREQ)
    #define c_SIO_CFG            (* (reg8 *) c__SIO_CFG)
    #define c_SIO_DIFF           (* (reg8 *) c__SIO_DIFF)
#endif /* (c__SIO_CFG) */

/* Interrupt Registers */
#if defined(c__INTSTAT)
    #define c_INTSTAT            (* (reg8 *) c__INTSTAT)
    #define c_SNAP               (* (reg8 *) c__SNAP)
    
	#define c_0_INTTYPE_REG 		(* (reg8 *) c__0__INTTYPE)
#endif /* (c__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_c_H */


/* [] END OF FILE */
