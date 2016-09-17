# THIS FILE IS AUTOMATICALLY GENERATED
# Project: C:\Users\suzukihajime\Documents\PSoC Creator\boost\boost.cydsn\boost.cyprj
# Date: Fri, 16 Sep 2016 16:21:28 GMT
#set_units -time ns
create_clock -name {ADC_theACLK(routed)} -period 833.33333333333326 -waveform {0 416.666666666667} [list [get_pins {ClockBlock/dclk_1}]]
create_clock -name {CyILO} -period 1000000 -waveform {0 500000} [list [get_pins {ClockBlock/ilo}] [get_pins {ClockBlock/clk_100k}] [get_pins {ClockBlock/clk_1k}] [get_pins {ClockBlock/clk_32k}]]
create_clock -name {CyIMO} -period 333.33333333333331 -waveform {0 166.666666666667} [list [get_pins {ClockBlock/imo}]]
create_clock -name {CyPLL_OUT} -period 41.666666666666664 -waveform {0 20.8333333333333} [list [get_pins {ClockBlock/pllout}]]
create_clock -name {CyMASTER_CLK} -period 41.666666666666664 -waveform {0 20.8333333333333} [list [get_pins {ClockBlock/clk_sync}]]
create_generated_clock -name {CyBUS_CLK} -source [get_pins {ClockBlock/clk_sync}] -edges {1 2 3} [list [get_pins {ClockBlock/clk_bus_glb}]]
create_generated_clock -name {clk} -source [get_pins {ClockBlock/clk_sync}] -edges {1 3 5} [list [get_pins {ClockBlock/dclk_glb_0}]]
create_generated_clock -name {ADC_theACLK} -source [get_pins {ClockBlock/clk_sync}] -edges {1 21 41} -nominal_period 833.33333333333326 [list [get_pins {ClockBlock/dclk_glb_1}]]
create_generated_clock -name {khz} -source [get_pins {ClockBlock/clk_sync}] -edges {1 751 1501} [list [get_pins {ClockBlock/dclk_glb_2}]]
create_generated_clock -name {Clock_1} -source [get_pins {ClockBlock/clk_sync}] -edges {1 240001 480001} [list [get_pins {ClockBlock/dclk_glb_3}]]


# Component constraints for C:\Users\suzukihajime\Documents\PSoC Creator\boost\boost.cydsn\TopDesign\TopDesign.cysch
# Project: C:\Users\suzukihajime\Documents\PSoC Creator\boost\boost.cydsn\boost.cyprj
# Date: Fri, 16 Sep 2016 16:21:23 GMT
