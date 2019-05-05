# THIS FILE IS AUTOMATICALLY GENERATED
# Project: D:\nisarga 2\PSoC Manual Projects\Project 3\Project 3D\TrafficLightVersion1.2.cydsn\TrafficLightVersion1.2.cyprj
# Date: Thu, 25 Apr 2019 12:43:13 GMT
#set_units -time ns
create_clock -name {CyILO} -period 1000000 -waveform {0 500000} [list [get_pins {ClockBlock/ilo}] [get_pins {ClockBlock/clk_100k}] [get_pins {ClockBlock/clk_1k}] [get_pins {ClockBlock/clk_32k}]]
create_clock -name {CyIMO} -period 333.33333333333331 -waveform {0 166.666666666667} [list [get_pins {ClockBlock/imo}]]
create_clock -name {CyPLL_OUT} -period 41.666666666666664 -waveform {0 20.8333333333333} [list [get_pins {ClockBlock/pllout}]]
create_clock -name {CyMASTER_CLK} -period 41.666666666666664 -waveform {0 20.8333333333333} [list [get_pins {ClockBlock/clk_sync}]]
create_generated_clock -name {CyBUS_CLK} -source [get_pins {ClockBlock/clk_sync}] -edges {1 2 3} [list [get_pins {ClockBlock/clk_bus_glb}]]
create_generated_clock -name {timer_clock} -source [get_pins {ClockBlock/clk_sync}] -edges {1 94113 188241} [list [get_pins {ClockBlock/dclk_glb_0}]]
create_generated_clock -name {timer_clock_1} -source [get_pins {ClockBlock/clk_sync}] -edges {1 240001 480001} [list [get_pins {ClockBlock/dclk_glb_1}]]


# Component constraints for D:\nisarga 2\PSoC Manual Projects\Project 3\Project 3D\TrafficLightVersion1.2.cydsn\TopDesign\TopDesign.cysch
# Project: D:\nisarga 2\PSoC Manual Projects\Project 3\Project 3D\TrafficLightVersion1.2.cydsn\TrafficLightVersion1.2.cyprj
# Date: Thu, 25 Apr 2019 12:43:08 GMT
