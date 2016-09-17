/***************************************************************************
* File Name: clock_hh_addr_dma.c  
* Version 1.70
*
*  Description:
*   Provides an API for the DMAC component. The API includes functions
*   for the DMA controller, DMA channels and Transfer Descriptors.
*
*
*   Note:
*     This module requires the developer to finish or fill in the auto
*     generated funcions and setup the dma channel and TD's.
*
********************************************************************************
* Copyright 2008-2010, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
********************************************************************************/
#include <CYLIB.H>
#include <CYDMAC.H>
#include <clock_hh_addr_dma.H>



/****************************************************************************
* 
* The following defines are available in Cyfitter.h
* 
* 
* 
* clock_hh_addr__DRQ_CTL_REG
* 
* 
* clock_hh_addr__DRQ_NUMBER
* 
* Number of TD's used by this channel.
* clock_hh_addr__NUMBEROF_TDS
* 
* Priority of this channel.
* clock_hh_addr__PRIORITY
* 
* True if clock_hh_addr_TERMIN_SEL is used.
* clock_hh_addr__TERMIN_EN
* 
* TERMIN interrupt line to signal terminate.
* clock_hh_addr__TERMIN_SEL
* 
* 
* True if clock_hh_addr_TERMOUT0_SEL is used.
* clock_hh_addr__TERMOUT0_EN
* 
* 
* TERMOUT0 interrupt line to signal completion.
* clock_hh_addr__TERMOUT0_SEL
* 
* 
* True if clock_hh_addr_TERMOUT1_SEL is used.
* clock_hh_addr__TERMOUT1_EN
* 
* 
* TERMOUT1 interrupt line to signal completion.
* clock_hh_addr__TERMOUT1_SEL
* 
****************************************************************************/


/* Zero based index of clock_hh_addr dma channel */
uint8 clock_hh_addr_DmaHandle = DMA_INVALID_CHANNEL;

/*********************************************************************
* Function Name: uint8 clock_hh_addr_DmaInitalize
**********************************************************************
* Summary:
*   Allocates and initialises a channel of the DMAC to be used by the
*   caller.
*
* Parameters:
*   BurstCount.
*       
*       
*   ReqestPerBurst.
*       
*       
*   UpperSrcAddress.
*       
*       
*   UpperDestAddress.
*       
*
* Return:
*   The channel that can be used by the caller for DMA activity.
*   DMA_INVALID_CHANNEL (0xFF) if there are no channels left. 
*
*
*******************************************************************/
uint8 clock_hh_addr_DmaInitialize(uint8 BurstCount, uint8 ReqestPerBurst, uint16 UpperSrcAddress, uint16 UpperDestAddress) 
{

    /* Allocate a DMA channel. */
    clock_hh_addr_DmaHandle = (uint8)clock_hh_addr__DRQ_NUMBER;

    /* Configure the channel. */
    (void)CyDmaChSetConfiguration(clock_hh_addr_DmaHandle,
                                  BurstCount,
                                  ReqestPerBurst,
                                  (uint8)clock_hh_addr__TERMOUT0_SEL,
                                  (uint8)clock_hh_addr__TERMOUT1_SEL,
                                  (uint8)clock_hh_addr__TERMIN_SEL);

    /* Set the extended address for the transfers */
    (void)CyDmaChSetExtendedAddress(clock_hh_addr_DmaHandle, UpperSrcAddress, UpperDestAddress);

    /* Set the priority for this channel */
    (void)CyDmaChPriority(clock_hh_addr_DmaHandle, (uint8)clock_hh_addr__PRIORITY);
    
    return clock_hh_addr_DmaHandle;
}

/*********************************************************************
* Function Name: void clock_hh_addr_DmaRelease
**********************************************************************
* Summary:
*   Frees the channel associated with clock_hh_addr.
*
*
* Parameters:
*   void.
*
*
*
* Return:
*   void.
*
*******************************************************************/
void clock_hh_addr_DmaRelease(void) 
{
    /* Disable the channel */
    (void)CyDmaChDisable(clock_hh_addr_DmaHandle);
}

