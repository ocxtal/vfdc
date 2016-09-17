/* ========================================
 *
 * Copyright YOUR COMPANY, THE YEAR
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF your company.
 *
 * ========================================
*/

#include <stdint.h>
#include <CYLIB.H>
#include <CYDMAC.H>
#include "`$INSTANCE_NAME`_clock24.h"
#include "`$INSTANCE_NAME`_ml_addr_dma.h"
#include "`$INSTANCE_NAME`_mh_addr_dma.h"
#include "`$INSTANCE_NAME`_hl_addr_dma.h"
#include "`$INSTANCE_NAME`_hh_addr_dma.h"
#include "`$INSTANCE_NAME`_creg.h"

/* counter value to 7seg conversion table */ 
static uint8_t conv_ml[64] __attribute__(( aligned(256) )) = {
	0
};
static uint8_t conv_mh[64] __attribute__(( aligned(256) )) = {
	0
};
static uint8_t conv_hl[64] __attribute__(( aligned(256) )) = {
	0
};
static uint8_t conv_hh[64] __attribute__(( aligned(256) )) = {
	0
};
/* dma instances */
static uint8_t ml_addr_chan, ml_data_chan;
static uint8_t mh_addr_chan, mh_data_chan;
static uint8_t hl_addr_chan, hl_data_chan;
static uint8_t hh_addr_chan, hh_data_chan;
static uint8_t ml_addr_td[1], ml_data_td[1];
static uint8_t mh_addr_td[1], mh_data_td[1];
static uint8_t hl_addr_td[1], hl_data_td[1];
static uint8_t hh_addr_td[1], hh_data_td[1];

void `$INSTANCE_NAME`_Start(void)
{
	/* initialize four dmas */
	ml_addr_chan = `$INSTANCE_NAME`_ml_addr_DmaInitialize(1, 0, HI16(CYDEV_PERIPH_BASE), HI16(CYDEV_PERIPH_BASE));
	ml_addr_td[0] = CyDmaTdAllocate();
	CyDmaTdSetConfiguration(ml_addr_td[0], 1, DMA_INVALID_TD, `$INSTANCE_NAME`_ml_addr__TD_TERMOUT_EN);
	CyDmaTdSetAddress(ml_addr_td[0], LO16((uint32)`$INSTANCE_NAME`_cmod_minute_counter__A0_REG), LO16((uint32)`$INSTANCE_NAME`_creg_Control_PTR));
	CyDmaChSetInitialTd(ml_addr_chan, ml_addr_td[0]);
	CyDmaChEnable(ml_addr_chan, 1);
	CyDmaClearPendingDrq(ml_addr_chan);

	mh_addr_chan = `$INSTANCE_NAME`_mh_addr_DmaInitialize(1, 0, HI16(CYDEV_PERIPH_BASE), HI16(CYDEV_PERIPH_BASE));
	mh_addr_td[0] = CyDmaTdAllocate();
	CyDmaTdSetConfiguration(mh_addr_td[0], 1, DMA_INVALID_TD, `$INSTANCE_NAME`_mh_addr__TD_TERMOUT_EN);
	CyDmaTdSetAddress(mh_addr_td[0], LO16((uint32)`$INSTANCE_NAME`_cmod_minute_counter__A0_REG), LO16((uint32)`$INSTANCE_NAME`_creg_Control_PTR));
	CyDmaChSetInitialTd(mh_addr_chan, mh_addr_td[0]);
	CyDmaChEnable(mh_addr_chan, 1);
	CyDmaClearPendingDrq(mh_addr_chan);

	hl_addr_chan = `$INSTANCE_NAME`_hl_addr_DmaInitialize(1, 0, HI16(CYDEV_PERIPH_BASE), HI16(CYDEV_PERIPH_BASE));
	hl_addr_td[0] = CyDmaTdAllocate();
	CyDmaTdSetConfiguration(hl_addr_td[0], 1, DMA_INVALID_TD, `$INSTANCE_NAME`_hl_addr__TD_TERMOUT_EN);
	CyDmaTdSetAddress(hl_addr_td[0], LO16((uint32)`$INSTANCE_NAME`_cmod_hour_counter__A0_REG), LO16((uint32)`$INSTANCE_NAME`_creg_Control_PTR));
	CyDmaChSetInitialTd(hl_addr_chan, hl_addr_td[0]);
	CyDmaChEnable(hl_addr_chan, 1);
	CyDmaClearPendingDrq(hl_addr_chan);

	hh_addr_chan = `$INSTANCE_NAME`_hh_addr_DmaInitialize(1, 0, HI16(CYDEV_PERIPH_BASE), HI16(CYDEV_PERIPH_BASE));
	hh_addr_td[0] = CyDmaTdAllocate();
	CyDmaTdSetConfiguration(hh_addr_td[0], 1, DMA_INVALID_TD, `$INSTANCE_NAME`_hh_addr__TD_TERMOUT_EN);
	CyDmaTdSetAddress(hh_addr_td[0], LO16((uint32)`$INSTANCE_NAME`_cmod_hour_counter__A0_REG), LO16((uint32)`$INSTANCE_NAME`_creg_Control_PTR));
	CyDmaChSetInitialTd(hh_addr_chan, hh_addr_td[0]);
	CyDmaChEnable(hh_addr_chan, 1);
	CyDmaClearPendingDrq(hh_addr_chan);
	return;
}

void `$INSTANCE_NAME`_Stop(void)
{
	/* nothing to do */
	return;
}

/* [] END OF FILE */
