/*******************************************************************************
* File Name: sense.h  
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

#if !defined(CY_PINS_sense_H) /* Pins sense_H */
#define CY_PINS_sense_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "sense_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 sense__PORT == 15 && ((sense__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    sense_Write(uint8 value);
void    sense_SetDriveMode(uint8 mode);
uint8   sense_ReadDataReg(void);
uint8   sense_Read(void);
void    sense_SetInterruptMode(uint16 position, uint16 mode);
uint8   sense_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the sense_SetDriveMode() function.
     *  @{
     */
        #define sense_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define sense_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define sense_DM_RES_UP          PIN_DM_RES_UP
        #define sense_DM_RES_DWN         PIN_DM_RES_DWN
        #define sense_DM_OD_LO           PIN_DM_OD_LO
        #define sense_DM_OD_HI           PIN_DM_OD_HI
        #define sense_DM_STRONG          PIN_DM_STRONG
        #define sense_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define sense_MASK               sense__MASK
#define sense_SHIFT              sense__SHIFT
#define sense_WIDTH              1u

/* Interrupt constants */
#if defined(sense__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in sense_SetInterruptMode() function.
     *  @{
     */
        #define sense_INTR_NONE      (uint16)(0x0000u)
        #define sense_INTR_RISING    (uint16)(0x0001u)
        #define sense_INTR_FALLING   (uint16)(0x0002u)
        #define sense_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define sense_INTR_MASK      (0x01u) 
#endif /* (sense__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define sense_PS                     (* (reg8 *) sense__PS)
/* Data Register */
#define sense_DR                     (* (reg8 *) sense__DR)
/* Port Number */
#define sense_PRT_NUM                (* (reg8 *) sense__PRT) 
/* Connect to Analog Globals */                                                  
#define sense_AG                     (* (reg8 *) sense__AG)                       
/* Analog MUX bux enable */
#define sense_AMUX                   (* (reg8 *) sense__AMUX) 
/* Bidirectional Enable */                                                        
#define sense_BIE                    (* (reg8 *) sense__BIE)
/* Bit-mask for Aliased Register Access */
#define sense_BIT_MASK               (* (reg8 *) sense__BIT_MASK)
/* Bypass Enable */
#define sense_BYP                    (* (reg8 *) sense__BYP)
/* Port wide control signals */                                                   
#define sense_CTL                    (* (reg8 *) sense__CTL)
/* Drive Modes */
#define sense_DM0                    (* (reg8 *) sense__DM0) 
#define sense_DM1                    (* (reg8 *) sense__DM1)
#define sense_DM2                    (* (reg8 *) sense__DM2) 
/* Input Buffer Disable Override */
#define sense_INP_DIS                (* (reg8 *) sense__INP_DIS)
/* LCD Common or Segment Drive */
#define sense_LCD_COM_SEG            (* (reg8 *) sense__LCD_COM_SEG)
/* Enable Segment LCD */
#define sense_LCD_EN                 (* (reg8 *) sense__LCD_EN)
/* Slew Rate Control */
#define sense_SLW                    (* (reg8 *) sense__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define sense_PRTDSI__CAPS_SEL       (* (reg8 *) sense__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define sense_PRTDSI__DBL_SYNC_IN    (* (reg8 *) sense__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define sense_PRTDSI__OE_SEL0        (* (reg8 *) sense__PRTDSI__OE_SEL0) 
#define sense_PRTDSI__OE_SEL1        (* (reg8 *) sense__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define sense_PRTDSI__OUT_SEL0       (* (reg8 *) sense__PRTDSI__OUT_SEL0) 
#define sense_PRTDSI__OUT_SEL1       (* (reg8 *) sense__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define sense_PRTDSI__SYNC_OUT       (* (reg8 *) sense__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(sense__SIO_CFG)
    #define sense_SIO_HYST_EN        (* (reg8 *) sense__SIO_HYST_EN)
    #define sense_SIO_REG_HIFREQ     (* (reg8 *) sense__SIO_REG_HIFREQ)
    #define sense_SIO_CFG            (* (reg8 *) sense__SIO_CFG)
    #define sense_SIO_DIFF           (* (reg8 *) sense__SIO_DIFF)
#endif /* (sense__SIO_CFG) */

/* Interrupt Registers */
#if defined(sense__INTSTAT)
    #define sense_INTSTAT            (* (reg8 *) sense__INTSTAT)
    #define sense_SNAP               (* (reg8 *) sense__SNAP)
    
	#define sense_0_INTTYPE_REG 		(* (reg8 *) sense__0__INTTYPE)
#endif /* (sense__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_sense_H */


/* [] END OF FILE */
