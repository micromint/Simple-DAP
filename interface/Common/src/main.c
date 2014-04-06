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

#include <RTL.h>
#include <rl_usb.h>

#if !defined(CONF_DAP) && !defined(CONF_CDC)
#error "Configure at least one device by defining CONF_DAP or CONF_CDC"
#endif

#if defined(CONF_DAP)
#include "DAP_config.h"
#include "DAP.h"

extern void usbd_hid_process (void);
#endif

#if defined(CONF_CDC)
#include "UART.h"
#include <stdio.h>

#define SIZE_DATA (64)

void serial_process() {
    uint8_t data[SIZE_DATA];
    int32_t len_data = 0;

    while (1) {

        len_data = USBD_CDC_ACM_DataFree();
        if (len_data > SIZE_DATA)
            len_data = SIZE_DATA;
        if (len_data)
            len_data = uart_read_data(data, len_data);
        if (len_data) {
            USBD_CDC_ACM_DataSend(data , len_data);
        }

        len_data = uart_write_free();
        if (len_data > SIZE_DATA)
            len_data = SIZE_DATA;
        if (len_data)
            len_data = USBD_CDC_ACM_DataRead(data, len_data);
        if (len_data) {
            uart_write_data(data, len_data);
        }
    }
}
#endif

// Main program
int main (void) {
#if defined(CONF_DAP)
  DAP_Setup();                          // DAP Setup 
#endif

  usbd_init();                          // USB Device Initialization
  usbd_connect(0);                      // USB Device Disconnect
  usbd_connect(1);                      // USB Device Connect

  while (!usbd_configured());           // Wait for USB Device to configure

#if defined(CONF_DAP)
  LED_CONNECTED_OUT(1);                 // Turn on  Debugger Connected LED
  LED_RUNNING_OUT(1);                   // Turn on  Target Running LED
  Delayms(500);                         // Wait for 500ms
  LED_RUNNING_OUT(0);                   // Turn off Target Running LED
  LED_CONNECTED_OUT(0);                 // Turn off Debugger Connected LED
#endif

  while (1) {                           // Endless Loop
#if defined(CONF_DAP)
    usbd_hid_process();                 // Process USB HID Data
#endif
#if defined(CONF_CDC)
    serial_process();                   // Process USB CDC Data
#endif
  }
}
