# vfdc

Table clock firmware on PSoC5LP, driving four NEC LD8035 VFD tubes.

## Contents

* **boost.soft.cydsn** software-based one
* **boost.cydsn** hardware (UDB and DMA) based one

Schematics is not available yet...😢

## Internal architecture

The entire firmware consists of three blocks, 5V to 15V boost converter, 100mA constant current driver, and 24 hour clock module. (*See boost.soft.cydsn/main.c for the details...*)

### 5V-to-15V boost converter

Boost converter generates 15V for VFD grids and segments. It is implemented with a 1mH inductor, an N-ch FET and a low-Vf diode as typical boost converters. The output voltage (smoothed with 100uF capacitor) is divided with two registors, 4.7kOhm and 1kOhm, and returned to the chip as a feedback. The FET is drived by 8-bit PWM with 47kHz period, whose duty is updated on every cycle according to the feedback voltage. The calculation of the PWM duty (from the ADC value of the feedback input) is implemented with a pair of DMA instances, which is called *indexed DMA* in the official document, the former one transferring the ADC value to the lower 8-bit of DMA source address register of the latter DMA instance and the latter one copying the value of the pointed address to the PWM period register. The table is configured to have offsetted value at each index.
In this configuration, the output voltage V and duty value c (ranged from 0 to 255) follows the equation:

1/5 : 1/(V - 5) = 256 - c : c

1 / (1 + 4.7) * V * 256 / 5 = c - offset

Thus the default offset -10 give a output voltage V = 13.1(V) and PWM period c = 108.


### 100mA constant current driver

Constant current driver is used to supply bias for heaters. Inside the chip is only a voltage DAC, whose output is used as a reference voltage of a current regurator with an OPAMP to amplify voltage by 21 (10k / 470) on 1Ohm current detection registor and another OPAMP to drive a NPN transistor. Any part of dual OPAMP is suited at least it is capable of driving 4V output at Vcc = 5V. The default value 60 (which gives 0.96V on DAC output) results in 45mA current (11mA for each heater with 4 tubes).


### 24 hour clock module

A clock counters are implemented with PLD and DMA, but codes running on CPU. The clock counter module takes 32768kHz clock (from ILO) and divide it into 1/60 Hz. Each minute and hour conter is implemented with a UDB block, handling count up and count down signal synchronized with master clock. In a counter adjustment mode, the count up / down signals are bypassed to pulse generator, which send pulses according to the UP / DOWN button input signals. The clock counter values (kept in A0 registers) are converted to 7-segment pattern with two-staged DMAs in the same way described in the boost converter section.


## License

Copyright (c) 2016, Hajime Suzuki

MIT




