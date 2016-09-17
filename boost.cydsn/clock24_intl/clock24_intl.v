//`#start header` -- edit after this line, do not edit this line
// ========================================
//
// Copyright YOUR COMPANY, THE YEAR
// All Rights Reserved
// UNPUBLISHED, LICENSED SOFTWARE.
//
// CONFIDENTIAL AND PROPRIETARY INFORMATION
// WHICH IS THE PROPERTY OF your company.
//
// ========================================
`include "cypress.v"
//`#end` -- edit above this line, do not edit this line

//`#start body` -- edit after this line, do not edit this line

module clock24_intl(
	input wire mode,		// must be debounced
	input wire up,			// must be debounced
	input wire down,		// must be debounced
	output wire ml,
	output wire mh,
	output wire hl,
	output wire hh,
	input wire clk);		// 32768Hz

	// synchronize clk with bus_clk
	wire clk_intl;
	cy_psoc3_udb_clock_enable_v1_0 #(
		.sync_mode(`TRUE))
		clk_en (
		.clock_out(clk_intl),
		.clock_in(clk),
		.enable(1'b1)
	);

	// synchronize input pins with clk
	reg mode_intl;
	reg up_intl;
	reg down_intl;
	always @(posedge clk_intl) begin
		mode_intl <= mode;
		up_intl <= up;
		down_intl <= down;
	end

	// edge detection on input pins
	reg mode_delayed;
	reg up_delayed;
	reg down_delayed;
	wire mode_posedge;
	wire up_posedge;
	wire down_posedge;
	always @(posedge clk_intl) begin
		mode_delayed <= mode_intl;
		up_delayed <= up_intl;
		down_delayed <= down_intl;
	end
	assign mode_posedge = ~mode_delayed & mode_intl;
	assign up_posedge = ~up_delayed & up_intl;
	assign down_posedge = ~down_delayed & down_intl;

	// mode selector (0: idle state, 1: hour adj, 2: min adj)
	// bit 0 is used to indicate hour adjustment mode is activated
	// bit 1 is used to indicate minute adjustment mode is activated
	wire[6:0] mode_state_counter_out;
	wire mode_minute_adj;
	wire mode_hour_adj;
	wire mode_idle;
	cy_psoc3_count7 #(
		.cy_period(7'd2),
		.cy_route_ld(1),
		.cy_route_en(1))
		mode_state_counter (
		.clock(clk_intl),
		.reset(1'b0),
		.load(1'b0),
		.enable(mode_posedge),		// advance counter (state) by one on the posedge on mode pin
		.count(mode_state_counter_out),
		.tc(mode_idle)				// use tc to detect idle state
	);
	assign mode_minute_adj = mode_state_counter_out[1];
	assign mode_hour_adj = mode_state_counter_out[0];

	// up and down buttons are or'ed to generate state input signal of bsig module
	wire up_down_pressed;
	wire up_down_direction;
	wire up_down_posedge;
	assign up_down_pressed = up_intl & down_intl;
	assign up_down_direction = down_intl;	// high when down
	assign up_down_posedge = up_posedge | down_posedge;

	// bulk up/down signal generator
	// this datapath module takes a button signal (typically tacticle switch)
	// and generates single pulse in response to the head of the signal high
	// when signal high continued longer than a period which is determined by
	// the value in D1, then it begin to generate contiguous pulses in a period D0
	wire bsig_a0_zero;
	wire[2:0] bsig_sel;
	wire up_down_pulse;
	assign bsig_sel[2:0] = { 1'b0, bsig_a0_zero, up_down_pressed };
	assign up_down_pulse = bsig_a0_zero | up_down_posedge;
	cy_psoc3_dp #(.cy_dpconfig(
	{
	    `CS_ALU_OP_PASS, `CS_SRCA_A1, `CS_SRCB_A0,
	    `CS_SHFT_OP_PASS, `CS_A0_SRC__ALU, `CS_A1_SRC___D1,
	    `CS_FEEDBACK_DSBL, `CS_CI_SEL_CFGA, `CS_SI_SEL_CFGA,
	    `CS_CMP_SEL_CFGA, /*CFGRAM0:  idle state, load A1 to A0, D1 to A1*/
	    `CS_ALU_OP__DEC, `CS_SRCA_A0, `CS_SRCB_D0,
	    `CS_SHFT_OP_PASS, `CS_A0_SRC__ALU, `CS_A1_SRC_NONE,
	    `CS_FEEDBACK_DSBL, `CS_CI_SEL_CFGA, `CS_SI_SEL_CFGA,
	    `CS_CMP_SEL_CFGA, /*CFGRAM1:  input high, decrement counter*/
	    `CS_ALU_OP_PASS, `CS_SRCA_A1, `CS_SRCB_D0,
	    `CS_SHFT_OP_PASS, `CS_A0_SRC__ALU, `CS_A1_SRC___D1,
	    `CS_FEEDBACK_DSBL, `CS_CI_SEL_CFGA, `CS_SI_SEL_CFGA,
	    `CS_CMP_SEL_CFGA, /*CFGRAM2:  move to idle state*/
	    `CS_ALU_OP_PASS, `CS_SRCA_A0, `CS_SRCB_D1,
	    `CS_SHFT_OP_PASS, `CS_A0_SRC___D0, `CS_A1_SRC_NONE,
	    `CS_FEEDBACK_DSBL, `CS_CI_SEL_CFGA, `CS_SI_SEL_CFGA,
	    `CS_CMP_SEL_CFGA, /*CFGRAM3:  input high, reload short period*/
	    `CS_ALU_OP_PASS, `CS_SRCA_A0, `CS_SRCB_D0,
	    `CS_SHFT_OP_PASS, `CS_A0_SRC_NONE, `CS_A1_SRC_NONE,
	    `CS_FEEDBACK_DSBL, `CS_CI_SEL_CFGA, `CS_SI_SEL_CFGA,
	    `CS_CMP_SEL_CFGA, /*CFGRAM4:  */
	    `CS_ALU_OP_PASS, `CS_SRCA_A0, `CS_SRCB_D0,
	    `CS_SHFT_OP_PASS, `CS_A0_SRC_NONE, `CS_A1_SRC_NONE,
	    `CS_FEEDBACK_DSBL, `CS_CI_SEL_CFGA, `CS_SI_SEL_CFGA,
	    `CS_CMP_SEL_CFGA, /*CFGRAM5:  */
	    `CS_ALU_OP_PASS, `CS_SRCA_A0, `CS_SRCB_D0,
	    `CS_SHFT_OP_PASS, `CS_A0_SRC_NONE, `CS_A1_SRC_NONE,
	    `CS_FEEDBACK_DSBL, `CS_CI_SEL_CFGA, `CS_SI_SEL_CFGA,
	    `CS_CMP_SEL_CFGA, /*CFGRAM6:  */
	    `CS_ALU_OP_PASS, `CS_SRCA_A0, `CS_SRCB_D0,
	    `CS_SHFT_OP_PASS, `CS_A0_SRC_NONE, `CS_A1_SRC_NONE,
	    `CS_FEEDBACK_DSBL, `CS_CI_SEL_CFGA, `CS_SI_SEL_CFGA,
	    `CS_CMP_SEL_CFGA, /*CFGRAM7:  */
	    8'hFF, 8'h00,  /*CFG9:  */
	    8'hFF, 8'hFF,  /*CFG11-10:  */
	    `SC_CMPB_A1_D1, `SC_CMPA_A1_D1, `SC_CI_B_ARITH,
	    `SC_CI_A_ARITH, `SC_C1_MASK_DSBL, `SC_C0_MASK_DSBL,
	    `SC_A_MASK_DSBL, `SC_DEF_SI_0, `SC_SI_B_DEFSI,
	    `SC_SI_A_DEFSI, /*CFG13-12:  */
	    `SC_A0_SRC_ACC, `SC_SHIFT_SL, 1'h0,
	    1'h0, `SC_FIFO1_BUS, `SC_FIFO0_BUS,
	    `SC_MSB_DSBL, `SC_MSB_BIT0, `SC_MSB_NOCHN,
	    `SC_FB_NOCHN, `SC_CMP1_NOCHN,
	    `SC_CMP0_NOCHN, /*CFG15-14:  */
	    10'h00, `SC_FIFO_CLK__DP,`SC_FIFO_CAP_AX,
	    `SC_FIFO_LEVEL,`SC_FIFO__SYNC,`SC_EXTCRC_DSBL,
	    `SC_WRK16CAT_DSBL /*CFG17-16:  */
	}
	)) bsig_dp(
	        /*  input                   */  .reset(1'b0),
	        /*  input                   */  .clk(clk_intl),
	        /*  input   [02:00]         */  .cs_addr(bsig_sel),
	        /*  input                   */  .route_si(1'b0),
	        /*  input                   */  .route_ci(1'b0),
	        /*  input                   */  .f0_load(1'b0),
	        /*  input                   */  .f1_load(1'b0),
	        /*  input                   */  .d0_load(1'b0),
	        /*  input                   */  .d1_load(1'b0),
	        /*  output                  */  .ce0(),
	        /*  output                  */  .cl0(),
	        /*  output                  */  .z0(bsig_a0_zero),
	        /*  output                  */  .ff0(),
	        /*  output                  */  .ce1(),
	        /*  output                  */  .cl1(),
	        /*  output                  */  .z1(),
	        /*  output                  */  .ff1(),
	        /*  output                  */  .ov_msb(),
	        /*  output                  */  .co_msb(),
	        /*  output                  */  .cmsb(),
	        /*  output                  */  .so(),
	        /*  output                  */  .f0_bus_stat(),
	        /*  output                  */  .f0_blk_stat(),
	        /*  output                  */  .f1_bus_stat(),
	        /*  output                  */  .f1_blk_stat(),
	        
	        /* input                    */  .ci(1'b0),     // Carry in from previous stage
	        /* output                   */  .co(),         // Carry out to next stage
	        /* input                    */  .sir(1'b0),    // Shift in from right side
	        /* output                   */  .sor(),        // Shift out to right side
	        /* input                    */  .sil(1'b0),    // Shift in from left side
	        /* output                   */  .sol(),        // Shift out to left side
	        /* input                    */  .msbi(1'b0),   // MSB chain in
	        /* output                   */  .msbo(),       // MSB chain out
	        /* input [01:00]            */  .cei(2'b0),    // Compare equal in from prev stage
	        /* output [01:00]           */  .ceo(),        // Compare equal out to next stage
	        /* input [01:00]            */  .cli(2'b0),    // Compare less than in from prv stage
	        /* output [01:00]           */  .clo(),        // Compare less than out to next stage
	        /* input [01:00]            */  .zi(2'b0),     // Zero detect in from previous stage
	        /* output [01:00]           */  .zo(),         // Zero detect out to next stage
	        /* input [01:00]            */  .fi(2'b0),     // 0xFF detect in from previous stage
	        /* output [01:00]           */  .fo(),         // 0xFF detect out to next stage
	        /* input [01:00]            */  .capi(2'b0),   // Software capture from previous stage
	        /* output [01:00]           */  .capo(),       // Software capture to next stage
	        /* input                    */  .cfbi(1'b0),   // CRC Feedback in from previous stage
	        /* output                   */  .cfbo(),       // CRC Feedback out to next stage
	        /* input [07:00]            */  .pi(8'b0),     // Parallel data port
	        /* output [07:00]           */  .po()          // Parallel data port
	);
	
	// clock divider
	// combine three count7 instance to generate 21bit counter
	// divide 32768 Hz clock into 1/60 Hz (pulse per minute) signal
	wire div1_tc;
	wire div2_tc;
	wire div3_tc;
	wire clk_div_pulse;
	wire[6:0] div2_count;
	cy_psoc3_count7 #(
		.cy_period(7'b1111111),
		.cy_route_ld(1),
		.cy_route_en(1))
		div1_counter (
		.clock(clk_intl),
		.reset(1'b0),
		.load(1'b0),
		.enable(1'b1),		// free run in the first stage
		.tc(div1_tc)
	);
	cy_psoc3_count7 #(
		.cy_period(7'b1111111),
		.cy_route_ld(1),
		.cy_route_en(1))
		div2_counter (
		.clock(clk_intl),
		.reset(1'b0),
		.load(1'b0),
		.enable(div1_tc),
		.count(div2_count),
		.tc(div2_tc)
	);
	cy_psoc3_count7 #(
		.cy_period(7'b0000001),
		.cy_route_ld(1),
		.cy_route_en(1))
		div3_counter (
		.clock(clk_intl),
		.reset(1'b0),
		.load(1'b0),
		.enable(div2_tc),
		.tc(div3_tc)
	);
	assign clk_div_pulse = div3_tc;
	
	// generate dma invoke signal from div2 counter
	function [3:0] gen_sel;
		input [1:0] cnt;
		begin
			case(cnt)
				2'b00: gen_sel = 4'b0001;
				2'b01: gen_sel = 4'b0010;
				2'b10: gen_sel = 4'b0100;
				2'b11: gen_sel = 4'b1000;
			endcase
		end
	endfunction
	wire minute_low_intl;
	wire minute_high_intl;
	wire hour_low_intl;
	wire hour_high_intl;
	assign { hour_high_intl, hour_low_intl, minute_high_intl, minute_low_intl } = gen_sel(div2_count[3:2]);
	assign ml = minute_low_intl;
	assign mh = minute_high_intl;
	assign hl = hour_low_intl;
	assign hh = hour_high_intl;

	// minute counter
	wire minute_a0_zero;
	wire minute_a0_period;
	wire minute_a0_reload;
	wire minute_pulse;
	wire[2:0] minute_sel;
	assign minute_a0_reload = minute_a0_zero | minute_a0_period;
	assign minute_pulse = (mode_minute_adj & up_down_pulse) | (~mode_minute_adj & clk_div_pulse);
	assign minute_sel = { minute_a0_reload, up_down_direction, minute_pulse };
	cy_psoc3_dp #(.cy_dpconfig(
	{
	    `CS_ALU_OP_PASS, `CS_SRCA_A0, `CS_SRCB_D0,
	    `CS_SHFT_OP_PASS, `CS_A0_SRC_NONE, `CS_A1_SRC_NONE,
	    `CS_FEEDBACK_DSBL, `CS_CI_SEL_CFGA, `CS_SI_SEL_CFGA,
	    `CS_CMP_SEL_CFGA, /*CFGRAM0: normal operation (idle)*/
	    `CS_ALU_OP__INC, `CS_SRCA_A1, `CS_SRCB_D0,
	    `CS_SHFT_OP_PASS, `CS_A0_SRC__ALU, `CS_A1_SRC_NONE,
	    `CS_FEEDBACK_DSBL, `CS_CI_SEL_CFGA, `CS_SI_SEL_CFGA,
	    `CS_CMP_SEL_CFGA, /*CFGRAM1: count up*/
	    `CS_ALU_OP_PASS, `CS_SRCA_A0, `CS_SRCB_D0,
	    `CS_SHFT_OP_PASS, `CS_A0_SRC_NONE, `CS_A1_SRC_NONE,
	    `CS_FEEDBACK_DSBL, `CS_CI_SEL_CFGA, `CS_SI_SEL_CFGA,
	    `CS_CMP_SEL_CFGA, /*CFGRAM2: normal operation (idle)*/
	    `CS_ALU_OP__DEC, `CS_SRCA_A0, `CS_SRCB_D0,
	    `CS_SHFT_OP_PASS, `CS_A0_SRC__ALU, `CS_A1_SRC_NONE,
	    `CS_FEEDBACK_DSBL, `CS_CI_SEL_CFGA, `CS_SI_SEL_CFGA,
	    `CS_CMP_SEL_CFGA, /*CFGRAM3: count down*/
	    `CS_ALU_OP_PASS, `CS_SRCA_A0, `CS_SRCB_D0,
	    `CS_SHFT_OP_PASS, `CS_A0_SRC_NONE, `CS_A1_SRC_NONE,
	    `CS_FEEDBACK_DSBL, `CS_CI_SEL_CFGA, `CS_SI_SEL_CFGA,
	    `CS_CMP_SEL_CFGA, /*CFGRAM4: idle*/
	    `CS_ALU_OP__XOR, `CS_SRCA_A0, `CS_SRCB_A0,
	    `CS_SHFT_OP_PASS, `CS_A0_SRC__ALU, `CS_A1_SRC_NONE,
	    `CS_FEEDBACK_DSBL, `CS_CI_SEL_CFGA, `CS_SI_SEL_CFGA,
	    `CS_CMP_SEL_CFGA, /*CFGRAM5: clear A0*/
	    `CS_ALU_OP_PASS, `CS_SRCA_A0, `CS_SRCB_D0,
	    `CS_SHFT_OP_PASS, `CS_A0_SRC_NONE, `CS_A1_SRC_NONE,
	    `CS_FEEDBACK_DSBL, `CS_CI_SEL_CFGA, `CS_SI_SEL_CFGA,
	    `CS_CMP_SEL_CFGA, /*CFGRAM6: idle*/
	    `CS_ALU_OP_PASS, `CS_SRCA_A0, `CS_SRCB_D0,
	    `CS_SHFT_OP_PASS, `CS_A0_SRC___D0, `CS_A1_SRC_NONE,
	    `CS_FEEDBACK_DSBL, `CS_CI_SEL_CFGA, `CS_SI_SEL_CFGA,
	    `CS_CMP_SEL_CFGA, /*CFGRAM7: reload period to A0*/
	    8'hFF, 8'h00,  /*CFG9: */
	    8'hFF, 8'hFF,  /*CFG11-10: */
	    `SC_CMPB_A1_D1, `SC_CMPA_A1_D1, `SC_CI_B_ARITH,
	    `SC_CI_A_ARITH, `SC_C1_MASK_DSBL, `SC_C0_MASK_DSBL,
	    `SC_A_MASK_DSBL, `SC_DEF_SI_0, `SC_SI_B_DEFSI,
	    `SC_SI_A_DEFSI, /*CFG13-12: */
	    `SC_A0_SRC_ACC, `SC_SHIFT_SL, 1'h0,
	    1'h0, `SC_FIFO1_BUS, `SC_FIFO0_BUS,
	    `SC_MSB_DSBL, `SC_MSB_BIT0, `SC_MSB_NOCHN,
	    `SC_FB_NOCHN, `SC_CMP1_NOCHN,
	    `SC_CMP0_NOCHN, /*CFG15-14: */
	    10'h00, `SC_FIFO_CLK__DP,`SC_FIFO_CAP_AX,
	    `SC_FIFO_LEVEL,`SC_FIFO__SYNC,`SC_EXTCRC_DSBL,
	    `SC_WRK16CAT_DSBL /*CFG17-16: */
	}
	)) minute_counter(
	        /*  input                   */  .reset(1'b0),
	        /*  input                   */  .clk(clk_intl),
	        /*  input   [02:00]         */  .cs_addr(minute_sel),
	        /*  input                   */  .route_si(1'b0),
	        /*  input                   */  .route_ci(1'b0),
	        /*  input                   */  .f0_load(1'b0),
	        /*  input                   */  .f1_load(1'b0),
	        /*  input                   */  .d0_load(1'b0),
	        /*  input                   */  .d1_load(1'b0),
	        /*  output                  */  .ce0(minute_a0_period),
	        /*  output                  */  .cl0(),
	        /*  output                  */  .z0(minute_a0_zero),
	        /*  output                  */  .ff0(),
	        /*  output                  */  .ce1(),
	        /*  output                  */  .cl1(),
	        /*  output                  */  .z1(),
	        /*  output                  */  .ff1(),
	        /*  output                  */  .ov_msb(),
	        /*  output                  */  .co_msb(),
	        /*  output                  */  .cmsb(),
	        /*  output                  */  .so(),
	        /*  output                  */  .f0_bus_stat(),
	        /*  output                  */  .f0_blk_stat(),
	        /*  output                  */  .f1_bus_stat(),
	        /*  output                  */  .f1_blk_stat(),
	        
	        /* input                    */  .ci(1'b0),     // Carry in from previous stage
	        /* output                   */  .co(),         // Carry out to next stage
	        /* input                    */  .sir(1'b0),    // Shift in from right side
	        /* output                   */  .sor(),        // Shift out to right side
	        /* input                    */  .sil(1'b0),    // Shift in from left side
	        /* output                   */  .sol(),        // Shift out to left side
	        /* input                    */  .msbi(1'b0),   // MSB chain in
	        /* output                   */  .msbo(),       // MSB chain out
	        /* input [01:00]            */  .cei(2'b0),    // Compare equal in from prev stage
	        /* output [01:00]           */  .ceo(),        // Compare equal out to next stage
	        /* input [01:00]            */  .cli(2'b0),    // Compare less than in from prv stage
	        /* output [01:00]           */  .clo(),        // Compare less than out to next stage
	        /* input [01:00]            */  .zi(2'b0),     // Zero detect in from previous stage
	        /* output [01:00]           */  .zo(),         // Zero detect out to next stage
	        /* input [01:00]            */  .fi(2'b0),     // 0xFF detect in from previous stage
	        /* output [01:00]           */  .fo(),         // 0xFF detect out to next stage
	        /* input [01:00]            */  .capi(2'b0),   // Software capture from previous stage
	        /* output [01:00]           */  .capo(),       // Software capture to next stage
	        /* input                    */  .cfbi(1'b0),   // CRC Feedback in from previous stage
	        /* output                   */  .cfbo(),       // CRC Feedback out to next stage
	        /* input [07:00]            */  .pi(8'b0),     // Parallel data port
	        /* output [07:00]           */  .po()          // Parallel data port
	);

	// hour counter
	wire hour_a0_zero;
	wire hour_a0_period;
	wire hour_a0_reload;
	wire hour_pulse;
	wire[2:0] hour_sel;
	assign hour_a0_reload = hour_a0_zero | hour_a0_period;
	assign hour_pulse = (mode_hour_adj & up_down_pulse) | (~mode_hour_adj & clk_div_pulse & minute_a0_period);
	assign hour_sel = { hour_a0_reload, up_down_direction, hour_pulse };
	cy_psoc3_dp #(.cy_dpconfig(
	{
	    `CS_ALU_OP_PASS, `CS_SRCA_A0, `CS_SRCB_D0,
	    `CS_SHFT_OP_PASS, `CS_A0_SRC_NONE, `CS_A1_SRC_NONE,
	    `CS_FEEDBACK_DSBL, `CS_CI_SEL_CFGA, `CS_SI_SEL_CFGA,
	    `CS_CMP_SEL_CFGA, /*CFGRAM0: normal operation (idle)*/
	    `CS_ALU_OP__INC, `CS_SRCA_A1, `CS_SRCB_D0,
	    `CS_SHFT_OP_PASS, `CS_A0_SRC__ALU, `CS_A1_SRC_NONE,
	    `CS_FEEDBACK_DSBL, `CS_CI_SEL_CFGA, `CS_SI_SEL_CFGA,
	    `CS_CMP_SEL_CFGA, /*CFGRAM1: count up*/
	    `CS_ALU_OP_PASS, `CS_SRCA_A0, `CS_SRCB_D0,
	    `CS_SHFT_OP_PASS, `CS_A0_SRC_NONE, `CS_A1_SRC_NONE,
	    `CS_FEEDBACK_DSBL, `CS_CI_SEL_CFGA, `CS_SI_SEL_CFGA,
	    `CS_CMP_SEL_CFGA, /*CFGRAM2: normal operation (idle)*/
	    `CS_ALU_OP__DEC, `CS_SRCA_A0, `CS_SRCB_D0,
	    `CS_SHFT_OP_PASS, `CS_A0_SRC__ALU, `CS_A1_SRC_NONE,
	    `CS_FEEDBACK_DSBL, `CS_CI_SEL_CFGA, `CS_SI_SEL_CFGA,
	    `CS_CMP_SEL_CFGA, /*CFGRAM3: count down*/
	    `CS_ALU_OP_PASS, `CS_SRCA_A0, `CS_SRCB_D0,
	    `CS_SHFT_OP_PASS, `CS_A0_SRC_NONE, `CS_A1_SRC_NONE,
	    `CS_FEEDBACK_DSBL, `CS_CI_SEL_CFGA, `CS_SI_SEL_CFGA,
	    `CS_CMP_SEL_CFGA, /*CFGRAM4: idle*/
	    `CS_ALU_OP__XOR, `CS_SRCA_A0, `CS_SRCB_A0,
	    `CS_SHFT_OP_PASS, `CS_A0_SRC__ALU, `CS_A1_SRC_NONE,
	    `CS_FEEDBACK_DSBL, `CS_CI_SEL_CFGA, `CS_SI_SEL_CFGA,
	    `CS_CMP_SEL_CFGA, /*CFGRAM5: clear A0*/
	    `CS_ALU_OP_PASS, `CS_SRCA_A0, `CS_SRCB_D0,
	    `CS_SHFT_OP_PASS, `CS_A0_SRC_NONE, `CS_A1_SRC_NONE,
	    `CS_FEEDBACK_DSBL, `CS_CI_SEL_CFGA, `CS_SI_SEL_CFGA,
	    `CS_CMP_SEL_CFGA, /*CFGRAM6: idle*/
	    `CS_ALU_OP_PASS, `CS_SRCA_A0, `CS_SRCB_D0,
	    `CS_SHFT_OP_PASS, `CS_A0_SRC___D0, `CS_A1_SRC_NONE,
	    `CS_FEEDBACK_DSBL, `CS_CI_SEL_CFGA, `CS_SI_SEL_CFGA,
	    `CS_CMP_SEL_CFGA, /*CFGRAM7: reload period to A0*/
	    8'hFF, 8'h00,  /*CFG9: */
	    8'hFF, 8'hFF,  /*CFG11-10: */
	    `SC_CMPB_A1_D1, `SC_CMPA_A1_D1, `SC_CI_B_ARITH,
	    `SC_CI_A_ARITH, `SC_C1_MASK_DSBL, `SC_C0_MASK_DSBL,
	    `SC_A_MASK_DSBL, `SC_DEF_SI_0, `SC_SI_B_DEFSI,
	    `SC_SI_A_DEFSI, /*CFG13-12: */
	    `SC_A0_SRC_ACC, `SC_SHIFT_SL, 1'h0,
	    1'h0, `SC_FIFO1_BUS, `SC_FIFO0_BUS,
	    `SC_MSB_DSBL, `SC_MSB_BIT0, `SC_MSB_NOCHN,
	    `SC_FB_NOCHN, `SC_CMP1_NOCHN,
	    `SC_CMP0_NOCHN, /*CFG15-14: */
	    10'h00, `SC_FIFO_CLK__DP,`SC_FIFO_CAP_AX,
	    `SC_FIFO_LEVEL,`SC_FIFO__SYNC,`SC_EXTCRC_DSBL,
	    `SC_WRK16CAT_DSBL /*CFG17-16: */
	}
	)) hour_counter(
	        /*  input                   */  .reset(1'b0),
	        /*  input                   */  .clk(clk_intl),
	        /*  input   [02:00]         */  .cs_addr(hour_sel),
	        /*  input                   */  .route_si(1'b0),
	        /*  input                   */  .route_ci(1'b0),
	        /*  input                   */  .f0_load(1'b0),
	        /*  input                   */  .f1_load(1'b0),
	        /*  input                   */  .d0_load(1'b0),
	        /*  input                   */  .d1_load(1'b0),
	        /*  output                  */  .ce0(hour_a0_period),
	        /*  output                  */  .cl0(),
	        /*  output                  */  .z0(hour_a0_zero),
	        /*  output                  */  .ff0(),
	        /*  output                  */  .ce1(),
	        /*  output                  */  .cl1(),
	        /*  output                  */  .z1(),
	        /*  output                  */  .ff1(),
	        /*  output                  */  .ov_msb(),
	        /*  output                  */  .co_msb(),
	        /*  output                  */  .cmsb(),
	        /*  output                  */  .so(),
	        /*  output                  */  .f0_bus_stat(),
	        /*  output                  */  .f0_blk_stat(),
	        /*  output                  */  .f1_bus_stat(),
	        /*  output                  */  .f1_blk_stat(),
	        
	        /* input                    */  .ci(1'b0),     // Carry in from previous stage
	        /* output                   */  .co(),         // Carry out to next stage
	        /* input                    */  .sir(1'b0),    // Shift in from right side
	        /* output                   */  .sor(),        // Shift out to right side
	        /* input                    */  .sil(1'b0),    // Shift in from left side
	        /* output                   */  .sol(),        // Shift out to left side
	        /* input                    */  .msbi(1'b0),   // MSB chain in
	        /* output                   */  .msbo(),       // MSB chain out
	        /* input [01:00]            */  .cei(2'b0),    // Compare equal in from prev stage
	        /* output [01:00]           */  .ceo(),        // Compare equal out to next stage
	        /* input [01:00]            */  .cli(2'b0),    // Compare less than in from prv stage
	        /* output [01:00]           */  .clo(),        // Compare less than out to next stage
	        /* input [01:00]            */  .zi(2'b0),     // Zero detect in from previous stage
	        /* output [01:00]           */  .zo(),         // Zero detect out to next stage
	        /* input [01:00]            */  .fi(2'b0),     // 0xFF detect in from previous stage
	        /* output [01:00]           */  .fo(),         // 0xFF detect out to next stage
	        /* input [01:00]            */  .capi(2'b0),   // Software capture from previous stage
	        /* output [01:00]           */  .capo(),       // Software capture to next stage
	        /* input                    */  .cfbi(1'b0),   // CRC Feedback in from previous stage
	        /* output                   */  .cfbo(),       // CRC Feedback out to next stage
	        /* input [07:00]            */  .pi(8'b0),     // Parallel data port
	        /* output [07:00]           */  .po()          // Parallel data port
	);
endmodule

//`#end` -- edit above this line, do not edit this line

//`#start footer` -- edit after this line, do not edit this line
//`#end` -- edit above this line, do not edit this line


//[] END OF FILE


