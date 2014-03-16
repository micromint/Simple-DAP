/* CMSIS-DAP Interface Firmware
 * Copyright (c) 2009-2013 ARM Limited
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef __DAP_CONFIG_H__
#define __DAP_CONFIG_H__


//**************************************************************************************************
/** 
\defgroup DAP_Config_Debug_gr CMSIS-DAP Debug Unit Information
\ingroup DAP_ConfigIO_gr 
@{
Provides definitions about:
 - Definition of Cortex-M processor parameters used in CMSIS-DAP Debug Unit.
 - Debug Unit communication packet size.
 - Debug Access Port communication mode (JTAG or SWD).
 - Optional information about a connected Target Device (for Evaluation Boards).
*/

#include <LPC11Uxx.h>

/// Processor Clock of the Cortex-M MCU used in the Debug Unit.
/// This value is used to calculate the SWD/JTAG clock speed.
#define CPU_CLOCK               48000000       ///< Specifies the CPU Clock in Hz

/// Number of processor cycles for I/O Port write operations.
/// This value is used to calculate the SWD/JTAG clock speed that is generated with I/O
/// Port write operations in the Debug Unit by a Cortex-M MCU. Most Cortex-M processors
/// requrie 2 processor cycles for a I/O Port Write operation.  If the Debug Unit uses
/// a Cortex-M0+ processor with high-speed peripheral I/O only 1 processor cycle might be 
/// requrired.
#define IO_PORT_WRITE_CYCLES    1               ///< I/O Cycles: 2=default, 1=Cortex-M0+ fast I/0

/// Indicate that Serial Wire Debug (SWD) communication mode is available at the Debug Access Port.
/// This information is returned by the command \ref DAP_Info as part of <b>Capabilities</b>.
#define DAP_SWD                 1               ///< SWD Mode:  1 = available, 0 = not available

/// Indicate that JTAG communication mode is available at the Debug Port.
/// This information is returned by the command \ref DAP_Info as part of <b>Capabilities</b>.
#define DAP_JTAG                1               ///< JTAG Mode: 1 = available, 0 = not available.

/// Configure maximum number of JTAG devices on the scan chain connected to the Debug Access Port.
/// This setting impacts the RAM requirements of the Debug Unit. Valid range is 1 .. 255.
#define DAP_JTAG_DEV_CNT        8               ///< Maximum number of JTAG devices on scan chain

/// Default communication mode on the Debug Access Port.
/// Used for the command \ref DAP_Connect when Port Default mode is selected.
#define DAP_DEFAULT_PORT        1               ///< Default JTAG/SWJ Port Mode: 1 = SWD, 2 = JTAG.

/// Default communication speed on the Debug Access Port for SWD and JTAG mode.
/// Used to initialize the default SWD/JTAG clock frequency.
/// The command \ref DAP_SWJ_Clock can be used to overwrite this default setting.
#define DAP_DEFAULT_SWJ_CLOCK   1000000         ///< Default SWD/JTAG clock frequency in Hz.

/// Maximum Package Size for Command and Response data.
/// This configuration settings is used to optimized the communication performance with the
/// debugger and depends on the USB peripheral. Change setting to 1024 for High-Speed USB.
#define DAP_PACKET_SIZE         64            ///< USB: 64 = Full-Speed, 1024 = High-Speed.

/// Maximum Package Buffers for Command and Response data.
/// This configuration settings is used to optimized the communication performance with the
/// debugger and depends on the USB peripheral. For devices with limited RAM or USB buffer the
/// setting can be reduced (valid range is 1 .. 255). Change setting to 4 for High-Speed USB.
#define DAP_PACKET_COUNT        52               ///< Buffers: 64 = Full-Speed, 4 = High-Speed.


/// Debug Unit is connected to fixed Target Device.
/// The Debug Unit may be part of an evaluation board and always connected to a fixed
/// known device.  In this case a Device Vendor and Device Name string is stored which
/// may be used by the debugger or IDE to configure device parameters.
#define TARGET_DEVICE_FIXED     0               ///< Target Device: 1 = known, 0 = unknown;

#if TARGET_DEVICE_FIXED
#define TARGET_DEVICE_VENDOR    ""              ///< String indicating the Silicon Vendor
#define TARGET_DEVICE_NAME      ""              ///< String indicating the Target Device
#endif

///@}


// Peripheral register bit masks (used by macros)
#define FUNC_0									0
#define FUNC_1									1
#define FUNC_2									2
#define FUNC_3									3
#define FUNC_4									4
#define FUNC_5									5
#define FUNC_6									6
#define FUNC_7									7
#define INACTIVE_MODE						0
#define PULL_DOWN_ENABLED				(1 << 3)
#define PULL_UP_ENABLED					(2 << 3)
#define REPEATER_MODE						(3 << 3)
#define HYSTERESIS_ENABLE				(1 << 5)
#define INVERT									(1 << 6)
#define OPENDRAIN								(1 << 10)

// // Debug Port I/O Pins
// LPC11U35/501
// SWCLK/TCK Pin                PIO0_11
#define PIN_SWCLK_TCK_PORT      0
#define PIN_SWCLK_TCK_BIT       11
#define PIN_SWCLK_TCK_IOCON     LPC_IOCON->TDI_PIO0_11

// SWDIO/TMS Pin                PIO0_8
#define PIN_SWDIO_TMS_PORT      0
#define PIN_SWDIO_TMS_BIT       8
#define PIN_SWDIO_TMS_IOCON     LPC_IOCON->PIO0_8

// TDI Pin                      PIO0_17
#define PIN_TDI_PORT            0
#define PIN_TDI_BIT             17
#define PIN_TDI_IOCON           LPC_IOCON->PIO0_17

// TDO Pin                      PIO0_9
#define PIN_TDO_PORT            0
#define PIN_TDO_BIT             9
#define PIN_TDO_IOCON           LPC_IOCON->PIO0_9

// nTRST Pin                    Not available
#define PIN_nTRST_PORT
#define PIN_nTRST_BIT

// nRESET Pin                   PIO0_2
#define PIN_nRESET_PORT         0
#define PIN_nRESET_BIT          2
#define PIN_nRESET_IOCON        LPC_IOCON->PIO0_2


// Debug Unit LEDs

// Connected LED                PIO0_7
#define LED_CONNECTED_PORT      0
#define LED_CONNECTED_BIT       7
#define LED_CONNECTED_IOCON     LPC_IOCON->PIO0_7

// Target Running LED           PIO0_22
#define LEDRUNNING_CONNECTED_PORT      0
#define LEDRUNNING_CONNECTED_BIT       22
#define LEDRUNNING_CONNECTED_IOCON     LPC_IOCON->PIO0_22


//**************************************************************************************************
/** 
\defgroup DAP_Config_PortIO_gr CMSIS-DAP Hardware I/O Pin Access
\ingroup DAP_ConfigIO_gr 
@{

Standard I/O Pins of the CMSIS-DAP Hardware Debug Port support standard JTAG mode
and Serial Wire Debug (SWD) mode. In SWD mode only 2 pins are required to implement the debug 
interface of a device. The following I/O Pins are provided:

JTAG I/O Pin                 | SWD I/O Pin          | CMSIS-DAP Hardware pin mode
---------------------------- | -------------------- | ---------------------------------------------
TCK: Test Clock              | SWCLK: Clock         | Output Push/Pull
TMS: Test Mode Select        | SWDIO: Data I/O      | Output Push/Pull; Input (for receiving data)
TDI: Test Data Input         |                      | Output Push/Pull
TDO: Test Data Output        |                      | Input             
nTRST: Test Reset (optional) |                      | Output Open Drain with pull-up resistor
nRESET: Device Reset         | nRESET: Device Reset | Output Open Drain with pull-up resistor


DAP Hardware I/O Pin Access Functions
-------------------------------------
The various I/O Pins are accessed by functions that implement the Read, Write, Set, or Clear to 
these I/O Pins. 

For the SWDIO I/O Pin there are additional functions that are called in SWD I/O mode only.
This functions are provided to achieve faster I/O that is possible with some advanced GPIO 
peripherals that can independently write/read a single I/O pin without affecting any other pins 
of the same I/O port. The following SWDIO I/O Pin functions are provided:
 - \ref PIN_SWDIO_OUT_ENABLE to enable the output mode from the DAP hardware.
 - \ref PIN_SWDIO_OUT_DISABLE to enable the input mode to the DAP hardware.
 - \ref PIN_SWDIO_IN to read from the SWDIO I/O pin with utmost possible speed.
 - \ref PIN_SWDIO_OUT to write to the SWDIO I/O pin with utmost possible speed.
*/


// Configure DAP I/O pins ------------------------------

//   LPC-Link-II HW uses buffers for debug port pins. Therefore it is not
//   possible to disable outputs SWCLK/TCK, TDI and they are left active.
//   Only SWDIO/TMS output can be disabled but it is also left active.
//   nRESET is configured for open drain mode.

/** Setup JTAG I/O pins: TCK, TMS, TDI, TDO, nTRST, and nRESET.
Configures the DAP Hardware I/O pins for JTAG mode:
 - TCK, TMS, TDI, nTRST, nRESET to output mode and set to high level.
 - TDO to input mode.
*/ 
static __inline void PORT_JTAG_SETUP (void) {
    LPC_GPIO->MASK[PIN_SWDIO_TMS_PORT] = 0;
    LPC_GPIO->MASK[PIN_TDI_PORT] = ~(1 << PIN_TDI_BIT);
}
 
/** Setup SWD I/O pins: SWCLK, SWDIO, and nRESET.
Configures the DAP Hardware I/O pins for Serial Wire Debug (SWD) mode:
 - SWCLK, SWDIO, nRESET to output mode and set to default high level.
 - TDI, TMS, nTRST to HighZ mode (pins are unused in SWD mode).
*/ 
static __inline void PORT_SWD_SETUP (void) {
    LPC_GPIO->MASK[PIN_TDI_PORT] = 0;
    LPC_GPIO->MASK[PIN_SWDIO_TMS_PORT] = ~(1 << PIN_SWDIO_TMS_BIT);
}

/** Disable JTAG/SWD I/O Pins.
Disables the DAP Hardware I/O pins which configures:
 - TCK/SWCLK, TMS/SWDIO, TDI, TDO, nTRST, nRESET to High-Z mode.
*/
static __inline void PORT_OFF (void) {
    LPC_GPIO->SET[PIN_SWCLK_TCK_PORT]  =  (1 << PIN_SWCLK_TCK_BIT);
    LPC_GPIO->SET[PIN_SWDIO_TMS_PORT]  =  (1 << PIN_SWDIO_TMS_BIT);
    LPC_GPIO->SET[PIN_TDI_PORT]        =  (1 << PIN_TDI_BIT);
    LPC_GPIO->DIR[PIN_nRESET_PORT]    &= ~(1 << PIN_nRESET_BIT);
}


// SWCLK/TCK I/O pin -------------------------------------

/** SWCLK/TCK I/O pin: Get Input.
\return Current status of the SWCLK/TCK DAP hardware I/O pin.
*/
static __forceinline uint32_t PIN_SWCLK_TCK_IN  (void) {
    return ((LPC_GPIO->PIN[PIN_SWCLK_TCK_PORT] >> PIN_SWCLK_TCK_BIT) & 1);
}

/** SWCLK/TCK I/O pin: Set Output to High.
Set the SWCLK/TCK DAP hardware I/O pin to high level.
*/
static __forceinline void     PIN_SWCLK_TCK_SET (void) {
    LPC_GPIO->SET[PIN_SWCLK_TCK_PORT] = 1 << PIN_SWCLK_TCK_BIT;
}

/** SWCLK/TCK I/O pin: Set Output to Low.
Set the SWCLK/TCK DAP hardware I/O pin to low level.
*/
static __forceinline void     PIN_SWCLK_TCK_CLR (void) {
    LPC_GPIO->CLR[PIN_SWCLK_TCK_PORT] = 1 << PIN_SWCLK_TCK_BIT;
}


// SWDIO/TMS Pin I/O --------------------------------------

/** SWDIO/TMS I/O pin: Get Input.
\return Current status of the SWDIO/TMS DAP hardware I/O pin.
*/
static __forceinline uint32_t PIN_SWDIO_TMS_IN  (void) {
    return ((LPC_GPIO->PIN[PIN_SWDIO_TMS_PORT] >> PIN_SWDIO_TMS_BIT) & 1);
}

/** SWDIO/TMS I/O pin: Set Output to High.
Set the SWDIO/TMS DAP hardware I/O pin to high level.
*/
static __forceinline void     PIN_SWDIO_TMS_SET (void) {
    LPC_GPIO->SET[PIN_SWDIO_TMS_PORT] = 1 << PIN_SWDIO_TMS_BIT;
}

/** SWDIO/TMS I/O pin: Set Output to Low.
Set the SWDIO/TMS DAP hardware I/O pin to low level.
*/
static __forceinline void     PIN_SWDIO_TMS_CLR (void) {
    LPC_GPIO->CLR[PIN_SWDIO_TMS_PORT] = 1 << PIN_SWDIO_TMS_BIT;
}

/** SWDIO I/O pin: Get Input (used in SWD mode only).
\return Current status of the SWDIO DAP hardware I/O pin.
*/
static __forceinline uint32_t PIN_SWDIO_IN      (void) {
    return (LPC_GPIO->MPIN[PIN_SWDIO_TMS_PORT] >> PIN_SWDIO_TMS_BIT);
}

/** SWDIO I/O pin: Set Output (used in SWD mode only).
\param bit Output value for the SWDIO DAP hardware I/O pin.
*/
static __forceinline void     PIN_SWDIO_OUT     (uint32_t bit) {
    LPC_GPIO->MPIN[PIN_SWDIO_TMS_PORT] = bit << PIN_SWDIO_TMS_BIT;
}

/** SWDIO I/O pin: Switch to Output mode (used in SWD mode only).
Configure the SWDIO DAP hardware I/O pin to output mode. This function is
called prior \ref PIN_SWDIO_OUT function calls.
*/
static __forceinline void     PIN_SWDIO_OUT_ENABLE  (void) {
    // Not available
}

/** SWDIO I/O pin: Switch to Input mode (used in SWD mode only).
Configure the SWDIO DAP hardware I/O pin to input mode. This function is
called prior \ref PIN_SWDIO_IN function calls.
*/
static __forceinline void     PIN_SWDIO_OUT_DISABLE (void) {
    // Not available
}


// TDI Pin I/O ---------------------------------------------

/** TDI I/O pin: Get Input.
\return Current status of the TDI DAP hardware I/O pin.
*/
static __forceinline uint32_t PIN_TDI_IN  (void) {
    return ((LPC_GPIO->PIN [PIN_TDI_PORT] >> PIN_TDI_BIT) & 1);
}

/** TDI I/O pin: Set Output.
\param bit Output value for the TDI DAP hardware I/O pin.
*/
static __forceinline void     PIN_TDI_OUT (uint32_t bit) {
    LPC_GPIO->MPIN[PIN_TDI_PORT] = bit << PIN_TDI_BIT;
}


// TDO Pin I/O ---------------------------------------------

/** TDO I/O pin: Get Input.
\return Current status of the TDO DAP hardware I/O pin.
*/
static __forceinline uint32_t PIN_TDO_IN  (void) {
    return ((LPC_GPIO->PIN[PIN_TDO_PORT] >> PIN_TDO_BIT) & 1);
}


// nTRST Pin I/O -------------------------------------------

/** nTRST I/O pin: Get Input.
\return Current status of the nTRST DAP hardware I/O pin.
*/
static __forceinline uint32_t PIN_nTRST_IN   (void) {
    return (0);   // Not available
}

/** nTRST I/O pin: Set Output.
\param bit JTAG TRST Test Reset pin status:
           - 0: issue a JTAG TRST Test Reset.
           - 1: release JTAG TRST Test Reset.
*/
static __forceinline void     PIN_nTRST_OUT  (uint32_t bit) {
    // Not available
}

// nRESET Pin I/O------------------------------------------

/** nRESET I/O pin: Get Input.
\return Current status of the nRESET DAP hardware I/O pin.
*/
static __forceinline uint32_t PIN_nRESET_IN  (void) {
    return ((LPC_GPIO->PIN[PIN_nRESET_PORT] >> PIN_nRESET_BIT) & 1);
}

/** nRESET I/O pin: Set Output.
\param bit target device hardware reset pin status:
           - 0: issue a device hardware reset.
           - 1: release device hardware reset.
*/
static __forceinline void     PIN_nRESET_OUT (uint32_t bit) {
    if (bit) {
        LPC_GPIO->DIR[PIN_nRESET_PORT]    &= ~(1 << PIN_nRESET_BIT);
    } else {
        LPC_GPIO->DIR[PIN_nRESET_PORT]    |=  (1 << PIN_nRESET_BIT);
    }
}

///@}


//**************************************************************************************************
/** 
\defgroup DAP_Config_LEDs_gr CMSIS-DAP Hardware Status LEDs
\ingroup DAP_ConfigIO_gr
@{

CMSIS-DAP Hardware may provide LEDs that indicate the status of the CMSIS-DAP Debug Unit.

It is recommended to provide the following LEDs for status indication:
 - Connect LED: is active when the DAP hardware is connected to a debugger.
 - Running LED: is active when the debugger has put the target device into running state.
*/

/** Debug Unit: Set status of Connected LED.
\param bit status of the Connect LED.
           - 1: Connect LED ON: debugger is connected to CMSIS-DAP Debug Unit.
           - 0: Connect LED OFF: debugger is not connected to CMSIS-DAP Debug Unit.
*/
static __inline void LED_CONNECTED_OUT (uint32_t bit) {
    LPC_GPIO->B[32*LED_CONNECTED_PORT + LED_CONNECTED_BIT] = bit;
}

/** Debug Unit: Set status Target Running LED.
\param bit status of the Target Running LED.
           - 1: Target Running LED ON: program execution in target started.
           - 0: Target Running LED OFF: program execution in target stopped.
*/
static __inline void LED_RUNNING_OUT (uint32_t bit) {
    LPC_GPIO->B[32*LED_CONNECTED_PORT + LED_CONNECTED_BIT] = bit;
}

///@}


//**************************************************************************************************
/** 
\defgroup DAP_Config_Initialization_gr CMSIS-DAP Initialization
\ingroup DAP_ConfigIO_gr
@{

CMSIS-DAP Hardware I/O and LED Pins are initialized with the function \ref DAP_SETUP.
*/

/** Setup of the Debug Unit I/O pins and LEDs (called when Debug Unit is initialized).
This function performs the initialization of the CMSIS-DAP Hardware I/O Pins and the 
Status LEDs. In detail the operation of Hardware I/O and LED pins are enabled and set:
 - I/O clock system enabled.
 - all I/O pins: input buffer enabled, output pins are set to HighZ mode.
 - for nTRST, nRESET a weak pull-up (if available) is enabled.
 - LED output pins are enabled and LEDs are turned off.
*/
static __inline void DAP_SETUP (void) {
    /* Enable clock for GPIO outputs */
    LPC_SYSCON->SYSAHBCLKCTRL |= (1UL << 6);

    /* Configure I/O pins																				 */	
	PIN_SWCLK_TCK_IOCON = FUNC_1 | PULL_UP_ENABLED;  /* SWCLK/TCK */
	PIN_SWDIO_TMS_IOCON = FUNC_0 | PULL_UP_ENABLED;  /* SWDIO/TMS */
	PIN_TDI_IOCON       = FUNC_0 | PULL_UP_ENABLED;  /* TDI:      */
	PIN_TDO_IOCON       = FUNC_0 | PULL_UP_ENABLED;  /* TDO:      */
	PIN_nRESET_IOCON    = FUNC_0 | OPENDRAIN;        /* nRESET:   */
	LED_CONNECTED_IOCON = FUNC_0 | PULL_UP_ENABLED;  /* LED:      */
	LEDRUNNING_CONNECTED_IOCON = FUNC_0 | PULL_UP_ENABLED;  /* LED:      */

    /* Configure: SWCLK/TCK, SWDIO/TMS, TDI as outputs (high level)  */
    /*            TDO as input                                                 */
    /*            nRESET as input with output latch set to low level           */
    LPC_GPIO->SET[PIN_SWCLK_TCK_PORT]  =  (1 << PIN_SWCLK_TCK_BIT);
    LPC_GPIO->SET[PIN_SWDIO_TMS_PORT]  =  (1 << PIN_SWDIO_TMS_BIT);
    LPC_GPIO->SET[PIN_TDI_PORT]        =  (1 << PIN_TDI_BIT);
    LPC_GPIO->CLR[PIN_nRESET_PORT]     =  (1 << PIN_nRESET_BIT);
    LPC_GPIO->DIR[PIN_SWCLK_TCK_PORT] |=  (1 << PIN_SWCLK_TCK_BIT);
    LPC_GPIO->DIR[PIN_SWDIO_TMS_PORT] |=  (1 << PIN_SWDIO_TMS_BIT);
    LPC_GPIO->DIR[PIN_TDI_PORT]       |=  (1 << PIN_TDI_BIT);
    LPC_GPIO->DIR[PIN_TDO_PORT]       &= ~(1 << PIN_TDO_BIT);
    LPC_GPIO->DIR[PIN_nRESET_PORT]    &= ~(1 << PIN_nRESET_BIT);

    /* Configure: LED as output (turned off) */
    LPC_GPIO->CLR[LED_CONNECTED_PORT]  =  (1 << LED_CONNECTED_BIT);
    LPC_GPIO->DIR[LED_CONNECTED_PORT] |=  (1 << LED_CONNECTED_BIT);
    LPC_GPIO->CLR[LEDRUNNING_CONNECTED_PORT]  =  (1 << LEDRUNNING_CONNECTED_BIT);
    LPC_GPIO->DIR[LEDRUNNING_CONNECTED_PORT] |=  (1 << LEDRUNNING_CONNECTED_BIT);
}

/** Reset Target Device with custom specific I/O pin or command sequence.
This function allows the optional implementation of a device specific reset sequence.
It is called when the command \ref DAP_ResetTarget and is for example required 
when a device needs a time-critical unlock sequence that enables the debug port.
\return 0 = no device specific reset sequence is implemented.\n
        1 = a device specific reset sequence is implemented.
*/
static __inline uint32_t RESET_TARGET (void) {
    return (0);              // change to '1' when a device reset sequence is implemented
}

///@}


#endif /* __DAP_CONFIG_H__ */
