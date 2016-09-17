/*******************************************************************************
* File Name: g.h  
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

#if !defined(CY_PINS_g_H) /* Pins g_H */
#define CY_PINS_g_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "g_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 g__PORT == 15 && ((g__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    g_Write(uint8 value);
void    g_SetDriveMode(uint8 mode);
uint8   g_ReadDataReg(void);
uint8   g_Read(void);
void    g_SetInterruptMode(uint16 position, uint16 mode);
uint8   g_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the g_SetDriveMode() function.
     *  @{
     */
        #define g_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define g_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define g_DM_RES_UP          PIN_DM_RES_UP
        #define g_DM_RES_DWN         PIN_DM_RES_DWN
        #define g_DM_OD_LO           PIN_DM_OD_LO
        #define g_DM_OD_HI           PIN_DM_OD_HI
        #define g_DM_STRONG          PIN_DM_STRONG
        #define g_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define g_MASK               g__MASK
#define g_SHIFT              g__SHIFT
#define g_WIDTH              1u

/* Interrupt constants */
#if defined(g__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in g_SetInterruptMode() function.
     *  @{
     */
        #define g_INTR_NONE      (uint16)(0x0000u)
        #define g_INTR_RISING    (uint16)(0x0001u)
        #define g_INTR_FALLING   (uint16)(0x0002u)
        #define g_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define g_INTR_MASK      (0x01u) 
#endif /* (g__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define g_PS                     (* (reg8 *) g__PS)
/* Data Register */
#define g_DR                     (* (reg8 *) g__DR)
/* Port Number */
#define g_PRT_NUM                (* (reg8 *) g__PRT) 
/* Connect to Analog Globals */                                                  
#define g_AG                     (* (reg8 *) g__AG)                       
/* Analog MUX bux enable */
#define g_AMUX                   (* (reg8 *) g__AMUX) 
/* Bidirectional Enable */                                                        
#define g_BIE                    (* (reg8 *) g__BIE)
/* Bit-mask for Aliased Register Access */
#define g_BIT_MASK               (* (reg8 *) g__BIT_MASK)
/* Bypass Enable */
#define g_BYP                    (* (reg8 *) g__BYP)
/* Port wide control signals */                                                   
#define g_CTL                    (* (reg8 *) g__CTL)
/* Drive Modes */
#define g_DM0                    (* (reg8 *) g__DM0) 
#define g_DM1                    (* (reg8 *) g__DM1)
#define g_DM2                    (* (reg8 *) g__DM2) 
/* Input Buffer Disable Override */
#define g_INP_DIS                (* (reg8 *) g__INP_DIS)
/* LCD Common or Segment Drive */
#define g_LCD_COM_SEG            (* (reg8 *) g__LCD_COM_SEG)
/* Enable Segment LCD */
#define g_LCD_EN                 (* (reg8 *) g__LCD_EN)
/* Slew Rate Control */
#define g_SLW                    (* (reg8 *) g__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define g_PRTDSI__CAPS_SEL       (* (reg8 *) g__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define g_PRTDSI__DBL_SYNC_IN    (* (reg8 *) g__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define g_PRTDSI__OE_SEL0        (* (reg8 *) g__PRTDSI__OE_SEL0) 
#define g_PRTDSI__OE_SEL1        (* (reg8 *) g__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define g_PRTDSI__OUT_SEL0       (* (reg8 *) g__PRTDSI__OUT_SEL0) 
#define g_PRTDSI__OUT_SEL1       (* (reg8 *) g__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define g_PRTDSI__SYNC_OUT       (* (reg8 *) g__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(g__SIO_CFG)
    #define g_SIO_HYST_EN        (* (reg8 *) g__SIO_HYST_EN)
    #define g_SIO_REG_HIFREQ     (* (reg8 *) g__SIO_REG_HIFREQ)
    #define g_SIO_CFG            (* (reg8 *) g__SIO_CFG)
    #define g_SIO_DIFF           (* (reg8 *) g__SIO_DIFF)
#endif /* (g__SIO_CFG) */

/* Interrupt Registers */
#if defined(g__INTSTAT)
    #define g_INTSTAT            (* (reg8 *) g__INTSTAT)
    #define g_SNAP               (* (reg8 *) g__SNAP)
    
	#define g_0_INTTYPE_REG 		(* (reg8 *) g__0__INTTYPE)
#endif /* (g__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_g_H */


/* [] END OF FILE */
