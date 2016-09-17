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
	int i, offset = -10;
	
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

uint8_t s, m, h;
CY_ISR(count)
{
	if(++s >= 60) {
		s = 0;
		if(++m >= 60) {
			m = 0;
			if(++h >= 24) {
				h = 0;
			}
		}
	}
	return;
}

static uint32_t const lp = 200000, sp = 50000, dp = 3000;
static uint32_t mode_cnt = 0, up_cnt = 0, down_cnt = 0;
static uint8_t mode_state = 0;
void mode_pressed(void)
{
	s = 0;
	if(++mode_state == 3) { mode_state = 0; }
	return;
}

void up_pressed(void)
{
	switch(mode_state) {
		case 0: break;
		case 1: m = (m + 1) % 60; break;
		case 2: h = (h + 1) % 24; break;
	}
	return;
}

void down_pressed(void)
{
	switch(mode_state) {
		case 0: break;
		case 1: m = (m == 0) ? 59 : m - 1; break;
		case 2: h = (h == 0) ? 23 : h - 1; break;
	}
	return;
}

void poll(void)
{
	if(mode_Read()) {
		/* released */
		mode_cnt = lp;
	} else {
		if(--mode_cnt == lp - dp) {
			mode_pressed();
		}
		if(mode_cnt == 0) {
			mode_cnt = sp;
			mode_pressed();
		}
	}
	
	if(up_Read()) {
		/* released */
		up_cnt = lp;
	} else {
		if(--up_cnt == lp - dp) {
			up_pressed();
		}
		if(up_cnt == 0) {
			up_cnt = sp;
			up_pressed();
		}
	}

	if(down_Read()) {
		/* released */
		down_cnt = lp;
	} else {
		if(--down_cnt == lp - dp) {
			down_pressed();
		}
		if(down_cnt == 0) {
			down_cnt = sp;
			down_pressed();
		}
	}
	return;
}

void sel(uint8_t n)
{
	grid1_Write(0);
	grid2_Write(0);
	grid3_Write(0);
	grid4_Write(0);
	if(mode_state - 1 == (n>>1) && (s & 0x01) != 0) { return; }
	switch(n) {
		case 0: grid1_Write(1); break;
		case 1: grid2_Write(1); break;
		case 2: grid3_Write(1); break;
		case 3: grid4_Write(1); break;
	}
	return;
}

void seg(uint8_t n)
{
	static uint8_t const conv[16] = { 0xd7, 0x44, 0xcb, 0xce, 0x5c, 0x9e, 0x9f, 0xc4, 0xdf, 0xde };
	n = conv[n & 0x0f];
	seg0_Write((n>>0) & 0x01);
	seg1_Write((n>>1) & 0x01);
	seg2_Write((n>>2) & 0x01);
	seg3_Write((n>>3) & 0x01);
	seg4_Write((n>>4) & 0x01);
	seg5_Write((n>>5) & 0x01);
	seg6_Write((n>>6) & 0x01);
	seg7_Write((n>>7) & 0x01);
	return;
}

void delay(void)
{
	volatile uint32_t i = 0;
	for(i = 0; i < 500; i++) {
		poll();
	}
	return;
}

int main()
{
	boost_start();
	vdac_start();
	isr_StartEx(count);
	CyGlobalIntEnable; /* Enable global interrupts. */
	while(1) {
		sel(0);
		seg(m % 10);
		delay();
		sel(1);
		seg(m / 10);
		delay();
		sel(2);
		seg(h % 10);
		delay();
		sel(3);
		seg((h / 10 == 0) ? 0x0a : h / 10);
		delay();		
	}
}

/* [] END OF FILE */
