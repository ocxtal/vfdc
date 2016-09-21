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
#include "`$INSTANCE_NAME`_ml_data_dma.h"
#include "`$INSTANCE_NAME`_mh_data_dma.h"
#include "`$INSTANCE_NAME`_hl_data_dma.h"
#include "`$INSTANCE_NAME`_hh_data_dma.h"
#include "`$INSTANCE_NAME`_creg.h"

/* counter value to 7seg conversion table */
static uint8_t conv[2][256] __attribute__(( aligned(256) )) = {
	{
		0xd7, 0x44, 0xcb, 0xce, 0x5c, 0x9e, 0x9f, 0xc4, 0xdf, 0xde,
		0xd7, 0x44, 0xcb, 0xce, 0x5c, 0x9e, 0x9f, 0xc4, 0xdf, 0xde,
		0xd7, 0x44, 0xcb, 0xce, 0x5c, 0x9e, 0x9f, 0xc4, 0xdf, 0xde,
		0xd7, 0x44, 0xcb, 0xce, 0x5c, 0x9e, 0x9f, 0xc4, 0xdf, 0xde,
		0xd7, 0x44, 0xcb, 0xce, 0x5c, 0x9e, 0x9f, 0xc4, 0xdf, 0xde,
		0xd7, 0x44, 0xcb, 0xce, 0x5c, 0x9e, 0x9f, 0xc4, 0xdf, 0xde
	},
	{ 
		0xd7, 0xd7, 0xd7, 0xd7, 0xd7, 0xd7, 0xd7, 0xd7, 0xd7, 0xd7,
		0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44,
		0xcb, 0xcb, 0xcb, 0xcb, 0xcb, 0xcb, 0xcb, 0xcb, 0xcb, 0xcb,
		0xce, 0xce, 0xce, 0xce, 0xce, 0xce, 0xce, 0xce, 0xce, 0xce,
		0x5c, 0x5c, 0x5c, 0x5c, 0x5c, 0x5c, 0x5c, 0x5c, 0x5c, 0x5c,
		0x9e, 0x9e, 0x9e, 0x9e, 0x9e, 0x9e, 0x9e, 0x9e, 0x9e, 0x9e
	}
};

/* dma instances */
static uint8_t chan[8];
static uint8_t td[8];

void `$INSTANCE_NAME`_Start(void)
{
	int i;
	uint32_t const d0_ptr[4] = {
		`$INSTANCE_NAME`_cmod_minute_counter__A0_REG,
		`$INSTANCE_NAME`_cmod_minute_counter__A0_REG,
		`$INSTANCE_NAME`_cmod_hour_counter__A0_REG,
		`$INSTANCE_NAME`_cmod_hour_counter__A0_REG
	};
	uint8_t (*init[8])(uint8_t, uint8_t, uint16_t, uint16_t) = {
		`$INSTANCE_NAME`_ml_data_DmaInitialize,
		`$INSTANCE_NAME`_ml_addr_DmaInitialize,
		`$INSTANCE_NAME`_mh_data_DmaInitialize,
		`$INSTANCE_NAME`_mh_addr_DmaInitialize,
		`$INSTANCE_NAME`_hl_data_DmaInitialize,
		`$INSTANCE_NAME`_hl_addr_DmaInitialize,
		`$INSTANCE_NAME`_hh_data_DmaInitialize,
		`$INSTANCE_NAME`_hh_addr_DmaInitialize
	};
	uint8_t to_flag[4] = {
		`$INSTANCE_NAME`_ml_addr__TD_TERMOUT_EN,
		`$INSTANCE_NAME`_mh_addr__TD_TERMOUT_EN,
		`$INSTANCE_NAME`_hl_addr__TD_TERMOUT_EN,
		`$INSTANCE_NAME`_hh_addr__TD_TERMOUT_EN
	};

	uint8_t e = 0;
	e = CyEnterCriticalSection();
	/* start mode state counter */
	*((reg8 *)`$INSTANCE_NAME`_cmod_mode_state_counter__CONTROL_AUX_CTL_REG) |= 0x20;
	*((reg8 *)`$INSTANCE_NAME`_cmod_mode_state_counter__COUNT_REG) = 0;

	/* start dividers */
	*((reg8 *)`$INSTANCE_NAME`_cmod_div1_counter__CONTROL_AUX_CTL_REG) |= 0x20;
	*((reg8 *)`$INSTANCE_NAME`_cmod_div2_counter__CONTROL_AUX_CTL_REG) |= 0x20;
	*((reg8 *)`$INSTANCE_NAME`_cmod_div3_counter__CONTROL_AUX_CTL_REG) |= 0x20;
	
	/* start minute and hour counters */
	*((reg8 *)`$INSTANCE_NAME`_cmod_minute_counter__D0_REG) = 59;
	*((reg8 *)`$INSTANCE_NAME`_cmod_hour_counter__D0_REG) = 23;
	
	/* start bulk pulse generator */
	*((reg8 *)`$INSTANCE_NAME`_cmod_bsig_dp__D0_REG) = 20;
	*((reg8 *)`$INSTANCE_NAME`_cmod_bsig_dp__D1_REG) = 200;

	/* initialize four dmas */
	for(i = 0; i < 4; i++) {
		int di = i * 2, ai = i * 2 + 1;

		chan[di] = init[di](1, 0, HI16(CYDEV_SRAM_BASE), HI16(CYDEV_PERIPH_BASE));
		td[di] = CyDmaTdAllocate();
		CyDmaTdSetConfiguration(td[di], 1, DMA_INVALID_TD, 0);
		CyDmaTdSetAddress(td[di], LO16((uint32)conv[i & 0x01]), LO16((uint32)`$INSTANCE_NAME`_creg_Control_PTR));
		CyDmaChSetInitialTd(chan[di], td[di]);
		CyDmaChEnable(chan[di], 1);
		CyDmaClearPendingDrq(chan[di]);

		chan[ai] = init[ai](1, 0, HI16(CYDEV_PERIPH_BASE), HI16(CYDEV_PERIPH_BASE));
		td[ai] = CyDmaTdAllocate();
		CyDmaTdSetConfiguration(td[ai], 1, DMA_INVALID_TD, to_flag[i]);
		CyDmaTdSetAddress(td[ai], LO16((uint32_t)d0_ptr[i]), LO16((uint32)&((dmac_tdmem2 CYXDATA *)DMAC_TDMEM)[td[di]].src_adr));
		CyDmaChSetInitialTd(chan[ai], td[ai]);
		CyDmaChEnable(chan[ai], 1);
		CyDmaClearPendingDrq(chan[ai]);
	}

	CyExitCriticalSection(e);
	return;
}

void `$INSTANCE_NAME`_Stop(void)
{
	/* nothing to do */
	return;
}

/* [] END OF FILE */
