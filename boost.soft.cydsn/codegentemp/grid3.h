/*******************************************************************************
* File Name: grid3.h  
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

#if !defined(CY_PINS_grid3_H) /* Pins grid3_H */
#define CY_PINS_grid3_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "grid3_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 grid3__PORT == 15 && ((grid3__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    grid3_Write(uint8 value);
void    grid3_SetDriveMode(uint8 mode);
uint8   grid3_ReadDataReg(void);
uint8   grid3_Read(void);
void    grid3_SetInterruptMode(uint16 position, uint16 mode);
uint8   grid3_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the grid3_SetDriveMode() function.
     *  @{
     */
        #define grid3_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define grid3_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define grid3_DM_RES_UP          PIN_DM_RES_UP
        #define grid3_DM_RES_DWN         PIN_DM_RES_DWN
        #define grid3_DM_OD_LO           PIN_DM_OD_LO
        #define grid3_DM_OD_HI           PIN_DM_OD_HI
        #define grid3_DM_STRONG          PIN_DM_STRONG
        #define grid3_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define grid3_MASK               grid3__MASK
#define grid3_SHIFT              grid3__SHIFT
#define grid3_WIDTH              1u

/* Interrupt constants */
#if defined(grid3__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in grid3_SetInterruptMode() function.
     *  @{
     */
        #define grid3_INTR_NONE      (uint16)(0x0000u)
        #define grid3_INTR_RISING    (uint16)(0x0001u)
        #define grid3_INTR_FALLING   (uint16)(0x0002u)
        #define grid3_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define grid3_INTR_MASK      (0x01u) 
#endif /* (grid3__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define grid3_PS                     (* (reg8 *) grid3__PS)
/* Data Register */
#define grid3_DR                     (* (reg8 *) grid3__DR)
/* Port Number */
#define grid3_PRT_NUM                (* (reg8 *) grid3__PRT) 
/* Connect to Analog Globals */                                                  
#define grid3_AG                     (* (reg8 *) grid3__AG)                       
/* Analog MUX bux enable */
#define grid3_AMUX                   (* (reg8 *) grid3__AMUX) 
/* Bidirectional Enable */                                                        
#define grid3_BIE                    (* (reg8 *) grid3__BIE)
/* Bit-mask for Aliased Register Access */
#define grid3_BIT_MASK               (* (reg8 *) grid3__BIT_MASK)
/* Bypass Enable */
#define grid3_BYP                    (* (reg8 *) grid3__BYP)
/* Port wide control signals */                                                   
#define grid3_CTL                    (* (reg8 *) grid3__CTL)
/* Drive Modes */
#define grid3_DM0                    (* (reg8 *) grid3__DM0) 
#define grid3_DM1                    (* (reg8 *) grid3__DM1)
#define grid3_DM2                    (* (reg8 *) grid3__DM2) 
/* Input Buffer Disable Override */
#define grid3_INP_DIS                (* (reg8 *) grid3__INP_DIS)
/* LCD Common or Segment Drive */
#define grid3_LCD_COM_SEG            (* (reg8 *) grid3__LCD_COM_SEG)
/* Enable Segment LCD */
#define grid3_LCD_EN                 (* (reg8 *) grid3__LCD_EN)
/* Slew Rate Control */
#define grid3_SLW                    (* (reg8 *) grid3__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define grid3_PRTDSI__CAPS_SEL       (* (reg8 *) grid3__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define grid3_PRTDSI__DBL_SYNC_IN    (* (reg8 *) grid3__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define grid3_PRTDSI__OE_SEL0        (* (reg8 *) grid3__PRTDSI__OE_SEL0) 
#define grid3_PRTDSI__OE_SEL1        (* (reg8 *) grid3__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define grid3_PRTDSI__OUT_SEL0       (* (reg8 *) grid3__PRTDSI__OUT_SEL0) 
#define grid3_PRTDSI__OUT_SEL1       (* (reg8 *) grid3__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define grid3_PRTDSI__SYNC_OUT       (* (reg8 *) grid3__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(grid3__SIO_CFG)
    #define grid3_SIO_HYST_EN        (* (reg8 *) grid3__SIO_HYST_EN)
    #define grid3_SIO_REG_HIFREQ     (* (reg8 *) grid3__SIO_REG_HIFREQ)
    #define grid3_SIO_CFG            (* (reg8 *) grid3__SIO_CFG)
    #define grid3_SIO_DIFF           (* (reg8 *) grid3__SIO_DIFF)
#endif /* (grid3__SIO_CFG) */

/* Interrupt Registers */
#if defined(grid3__INTSTAT)
    #define grid3_INTSTAT            (* (reg8 *) grid3__INTSTAT)
    #define grid3_SNAP               (* (reg8 *) grid3__SNAP)
    
	#define grid3_0_INTTYPE_REG 		(* (reg8 *) grid3__0__INTTYPE)
#endif /* (grid3__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_grid3_H */


/* [] END OF FILE */
