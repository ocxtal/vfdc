/*******************************************************************************
* File Name: grid2.h  
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

#if !defined(CY_PINS_grid2_H) /* Pins grid2_H */
#define CY_PINS_grid2_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "grid2_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 grid2__PORT == 15 && ((grid2__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    grid2_Write(uint8 value);
void    grid2_SetDriveMode(uint8 mode);
uint8   grid2_ReadDataReg(void);
uint8   grid2_Read(void);
void    grid2_SetInterruptMode(uint16 position, uint16 mode);
uint8   grid2_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the grid2_SetDriveMode() function.
     *  @{
     */
        #define grid2_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define grid2_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define grid2_DM_RES_UP          PIN_DM_RES_UP
        #define grid2_DM_RES_DWN         PIN_DM_RES_DWN
        #define grid2_DM_OD_LO           PIN_DM_OD_LO
        #define grid2_DM_OD_HI           PIN_DM_OD_HI
        #define grid2_DM_STRONG          PIN_DM_STRONG
        #define grid2_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define grid2_MASK               grid2__MASK
#define grid2_SHIFT              grid2__SHIFT
#define grid2_WIDTH              1u

/* Interrupt constants */
#if defined(grid2__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in grid2_SetInterruptMode() function.
     *  @{
     */
        #define grid2_INTR_NONE      (uint16)(0x0000u)
        #define grid2_INTR_RISING    (uint16)(0x0001u)
        #define grid2_INTR_FALLING   (uint16)(0x0002u)
        #define grid2_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define grid2_INTR_MASK      (0x01u) 
#endif /* (grid2__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define grid2_PS                     (* (reg8 *) grid2__PS)
/* Data Register */
#define grid2_DR                     (* (reg8 *) grid2__DR)
/* Port Number */
#define grid2_PRT_NUM                (* (reg8 *) grid2__PRT) 
/* Connect to Analog Globals */                                                  
#define grid2_AG                     (* (reg8 *) grid2__AG)                       
/* Analog MUX bux enable */
#define grid2_AMUX                   (* (reg8 *) grid2__AMUX) 
/* Bidirectional Enable */                                                        
#define grid2_BIE                    (* (reg8 *) grid2__BIE)
/* Bit-mask for Aliased Register Access */
#define grid2_BIT_MASK               (* (reg8 *) grid2__BIT_MASK)
/* Bypass Enable */
#define grid2_BYP                    (* (reg8 *) grid2__BYP)
/* Port wide control signals */                                                   
#define grid2_CTL                    (* (reg8 *) grid2__CTL)
/* Drive Modes */
#define grid2_DM0                    (* (reg8 *) grid2__DM0) 
#define grid2_DM1                    (* (reg8 *) grid2__DM1)
#define grid2_DM2                    (* (reg8 *) grid2__DM2) 
/* Input Buffer Disable Override */
#define grid2_INP_DIS                (* (reg8 *) grid2__INP_DIS)
/* LCD Common or Segment Drive */
#define grid2_LCD_COM_SEG            (* (reg8 *) grid2__LCD_COM_SEG)
/* Enable Segment LCD */
#define grid2_LCD_EN                 (* (reg8 *) grid2__LCD_EN)
/* Slew Rate Control */
#define grid2_SLW                    (* (reg8 *) grid2__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define grid2_PRTDSI__CAPS_SEL       (* (reg8 *) grid2__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define grid2_PRTDSI__DBL_SYNC_IN    (* (reg8 *) grid2__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define grid2_PRTDSI__OE_SEL0        (* (reg8 *) grid2__PRTDSI__OE_SEL0) 
#define grid2_PRTDSI__OE_SEL1        (* (reg8 *) grid2__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define grid2_PRTDSI__OUT_SEL0       (* (reg8 *) grid2__PRTDSI__OUT_SEL0) 
#define grid2_PRTDSI__OUT_SEL1       (* (reg8 *) grid2__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define grid2_PRTDSI__SYNC_OUT       (* (reg8 *) grid2__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(grid2__SIO_CFG)
    #define grid2_SIO_HYST_EN        (* (reg8 *) grid2__SIO_HYST_EN)
    #define grid2_SIO_REG_HIFREQ     (* (reg8 *) grid2__SIO_REG_HIFREQ)
    #define grid2_SIO_CFG            (* (reg8 *) grid2__SIO_CFG)
    #define grid2_SIO_DIFF           (* (reg8 *) grid2__SIO_DIFF)
#endif /* (grid2__SIO_CFG) */

/* Interrupt Registers */
#if defined(grid2__INTSTAT)
    #define grid2_INTSTAT            (* (reg8 *) grid2__INTSTAT)
    #define grid2_SNAP               (* (reg8 *) grid2__SNAP)
    
	#define grid2_0_INTTYPE_REG 		(* (reg8 *) grid2__0__INTTYPE)
#endif /* (grid2__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_grid2_H */


/* [] END OF FILE */
