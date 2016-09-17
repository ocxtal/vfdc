/***************************************************************************
* File Name: DMA1_dma.c  
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
#include <DMA1_dma.H>



/****************************************************************************
* 
* The following defines are available in Cyfitter.h
* 
* 
* 
* DMA1__DRQ_CTL_REG
* 
* 
* DMA1__DRQ_NUMBER
* 
* Number of TD's used by this channel.
* DMA1__NUMBEROF_TDS
* 
* Priority of this channel.
* DMA1__PRIORITY
* 
* True if DMA1_TERMIN_SEL is used.
* DMA1__TERMIN_EN
* 
* TERMIN interrupt line to signal terminate.
* DMA1__TERMIN_SEL
* 
* 
* True if DMA1_TERMOUT0_SEL is used.
* DMA1__TERMOUT0_EN
* 
* 
* TERMOUT0 interrupt line to signal completion.
* DMA1__TERMOUT0_SEL
* 
* 
* True if DMA1_TERMOUT1_SEL is used.
* DMA1__TERMOUT1_EN
* 
* 
* TERMOUT1 interrupt line to signal completion.
* DMA1__TERMOUT1_SEL
* 
****************************************************************************/


/* Zero based index of DMA1 dma channel */
uint8 DMA1_DmaHandle = DMA_INVALID_CHANNEL;

/*********************************************************************
* Function Name: uint8 DMA1_DmaInitalize
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
uint8 DMA1_DmaInitialize(uint8 BurstCount, uint8 ReqestPerBurst, uint16 UpperSrcAddress, uint16 UpperDestAddress) 
{

    /* Allocate a DMA channel. */
    DMA1_DmaHandle = (uint8)DMA1__DRQ_NUMBER;

    /* Configure the channel. */
    (void)CyDmaChSetConfiguration(DMA1_DmaHandle,
                                  BurstCount,
                                  ReqestPerBurst,
                                  (uint8)DMA1__TERMOUT0_SEL,
                                  (uint8)DMA1__TERMOUT1_SEL,
                                  (uint8)DMA1__TERMIN_SEL);

    /* Set the extended address for the transfers */
    (void)CyDmaChSetExtendedAddress(DMA1_DmaHandle, UpperSrcAddress, UpperDestAddress);

    /* Set the priority for this channel */
    (void)CyDmaChPriority(DMA1_DmaHandle, (uint8)DMA1__PRIORITY);
    
    return DMA1_DmaHandle;
}

/*********************************************************************
* Function Name: void DMA1_DmaRelease
**********************************************************************
* Summary:
*   Frees the channel associated with DMA1.
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
void DMA1_DmaRelease(void) 
{
    /* Disable the channel */
    (void)CyDmaChDisable(DMA1_DmaHandle);
}

