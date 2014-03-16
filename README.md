mbed CMSIS-DAP
==============
A subset of the mbed CMSIS-DAP project that implements a USB CMSIS-DAP interface for debugging.

This project is a simpler DAP-only implementation does not include the USB MSD flash filesystem, USB CDC serial interface and Keil RTX RTOS. It can be useful for testing your DAP logic before implementing a new mbed CMSIS-DAP interface or for implementing a standalone CMSIS-DAP debugger.

The mbed code is licensed under the permissive Apache 2.0 licence, so you can use it in both commercial and personal projects with confidence. This license also applies to the USB device stack.

Supported Interface Microcontrollers
------------------------------------
NXP:

* [LPC11U35] (http://www.nxp.com/products/microcontrollers/cortex_m0_m0/lpc1100/series/LPC11U00.html) (Cortex-M0)
* [LPC4320/LPC4330/LPC4370] (http://www.nxp.com/products/microcontrollers/cortex_m4/series/LPC4300.html) (Cortex-M4)

Freescale:

* [K20DX128] (http://www.freescale.com/webapp/sps/site/taxonomy.jsp?code=K20_USB_MCU) (Cortex-M4) (untested)

References
----------
* [mbed CMSIS-DAP Project] (https://github.com/mbedmicro/CMSIS-DAP)
* [ARM CMSIS-DAP Reference Implementation Beta 0.01](http://silver.arm.com/browse/CMSISDAP) (Free registration required)
* [NXP AN11321 - Porting the CMSIS-DAP debugger to the Cortex-M0 platform](http://www.nxp.com/documents/application_note/AN11321.zip)
