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
#include <project.h>

/*
 * 5V -> 12V boost converter
 */
static uint8_t boost_coef_table[256] __attribute__(( aligned(256) ));
static uint8_t DMA1_Chan, DMA2_Chan;
static uint8_t DMA1_TD[1], DMA2_TD[1];
static inline
void boost_start(void)
{
	int i, offset = 10;
	
	/* bootstrap */
	PWM_Start();
	PWM_WriteCompare(100);
	ADC_Start();

	for(i = 0; i < 100000; i++) {}

	/* initialize coefficient table */
	#define clip(x)		( (x) < 0 ? 0 : ((x) > 255 ? 255 : (x)) )
	for(i = 0; i < 256; i++) {
		boost_coef_table[i] = clip(i + offset);
	}
	
	/*
	 * indexed DMA: DMA1 and DMA2 cooperatively calculates
	 * `pwm_duty <- boost_coef_table[adc_read_value]' on every ADC conversion.
	 * DMA1: write current ADC value to the base address register of DMA2
	 * DMA2: transfer the content of boost_coef_table to PWM compare register
	 */
	#if 1
	DMA2_Chan = DMA2_DmaInitialize(1, 0, HI16(CYDEV_SRAM_BASE), HI16(CYDEV_PERIPH_BASE));
	DMA2_TD[0] = CyDmaTdAllocate();
	CyDmaTdSetConfiguration(DMA2_TD[0], 1, DMA_INVALID_TD, 0);
	CyDmaTdSetAddress(DMA2_TD[0], LO16((uint32)boost_coef_table), LO16((uint32)PWM_COMPARE1_LSB_PTR));
	CyDmaChSetInitialTd(DMA2_Chan, DMA2_TD[0]);
	CyDmaChEnable(DMA2_Chan, 1);
	CyDmaClearPendingDrq(DMA2_Chan);

	DMA1_Chan = DMA1_DmaInitialize(1, 0, HI16(CYDEV_PERIPH_BASE), HI16(CYDEV_PERIPH_BASE));
	DMA1_TD[0] = CyDmaTdAllocate();
	CyDmaTdSetConfiguration(DMA1_TD[0], 1, DMA_INVALID_TD, DMA1__TD_TERMOUT_EN);
	CyDmaTdSetAddress(DMA1_TD[0], LO16((uint32)ADC_SAR_WRK0_PTR), LO16((uint32)&((dmac_tdmem2 CYXDATA *)DMAC_TDMEM)[DMA2_TD[0]].src_adr));
	CyDmaChSetInitialTd(DMA1_Chan, DMA1_TD[0]);
	CyDmaChEnable(DMA1_Chan, 1);
	CyDmaClearPendingDrq(DMA1_Chan);
	#else
	DMA1_Chan = DMA1_DmaInitialize(0, 0, HI16(CYDEV_PERIPH_BASE), HI16(CYDEV_PERIPH_BASE));
	DMA1_TD[0] = CyDmaTdAllocate();
	CyDmaTdSetConfiguration(DMA1_TD[0], 1, DMA_INVALID_TD, DMA1__TD_TERMOUT_EN);
	CyDmaTdSetAddress(DMA1_TD[0], LO16((uint32)ADC_SAR_WRK0_PTR), LO16((uint32)PWM_COMPARE1_LSB_PTR));
	CyDmaChSetInitialTd(DMA1_Chan, DMA1_TD[0]);
	CyDmaChEnable(DMA1_Chan, 1);
	#endif
	return;
}

/*
 * filament driver
 */
static inline
void vdac_start(void)
{
	DAC_Start();
	DAC_SetValue(60);
	return;
}

//int goffset = -32;

int main()
{
	boost_start();
	vdac_start();
	clock_Start();
	CyGlobalIntEnable; /* Enable global interrupts. */
	while(1) {
		/*
		int64_t i;
		volatile int j = 0;
		for(i = 0; i < 1000; i++) { j++; }
		for(i = 0; i < 256; i++) { boost_coef_table[i] = clip(i + goffset); }
		*/
	}
}

/* [] END OF FILE */
