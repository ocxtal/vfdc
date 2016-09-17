/*******************************************************************************
* File Name: seg.h  
* Version 2.20
*
* Description:
*  This file contains the Alias definitions for Per-Pin APIs in cypins.h. 
*  Information on using these APIs can be found in the System Reference Guide.
*
* Note:
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_PINS_seg_ALIASES_H) /* Pins seg_ALIASES_H */
#define CY_PINS_seg_ALIASES_H

#include "cytypes.h"
#include "cyfitter.h"


/***************************************
*              Constants        
***************************************/
#define seg_0			(seg__0__PC)
#define seg_0_INTR	((uint16)((uint16)0x0001u << seg__0__SHIFT))

#define seg_1			(seg__1__PC)
#define seg_1_INTR	((uint16)((uint16)0x0001u << seg__1__SHIFT))

#define seg_2			(seg__2__PC)
#define seg_2_INTR	((uint16)((uint16)0x0001u << seg__2__SHIFT))

#define seg_3			(seg__3__PC)
#define seg_3_INTR	((uint16)((uint16)0x0001u << seg__3__SHIFT))

#define seg_4			(seg__4__PC)
#define seg_4_INTR	((uint16)((uint16)0x0001u << seg__4__SHIFT))

#define seg_5			(seg__5__PC)
#define seg_5_INTR	((uint16)((uint16)0x0001u << seg__5__SHIFT))

#define seg_6			(seg__6__PC)
#define seg_6_INTR	((uint16)((uint16)0x0001u << seg__6__SHIFT))

#define seg_7			(seg__7__PC)
#define seg_7_INTR	((uint16)((uint16)0x0001u << seg__7__SHIFT))

#define seg_INTR_ALL	 ((uint16)(seg_0_INTR| seg_1_INTR| seg_2_INTR| seg_3_INTR| seg_4_INTR| seg_5_INTR| seg_6_INTR| seg_7_INTR))

#endif /* End Pins seg_ALIASES_H */


/* [] END OF FILE */
