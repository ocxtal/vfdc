# vfdc

Table clock firmware on PSoC5LP, driving four NEC LD8035 VFD tubes.

## Contents

* **boost.soft.cydsn** software-based
* **boost.cydsn** hardware (UDB and DMA) based

Schematics is not available😢

## Internal architecture

The entire firmware consists of three blocks, 5V to 15V boost converter, 100mA constant-current driver, and 24 hour clock module. (*See boost.soft.cydsn/main.c for the details...*)


## License

Copyright (c) 2016, Hajime Suzuki

MIT




