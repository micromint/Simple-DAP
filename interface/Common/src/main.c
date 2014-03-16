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
#include "DAP_config.h"
#include "DAP.h"

extern void usbd_hid_process (void);

// Main program
int main (void) {
  DAP_Setup();                          // DAP Setup 

  usbd_init();                          // USB Device Initialization
  usbd_connect(__TRUE);                 // USB Device Connect
	
  while (!usbd_configured());           // Wait for USB Device to configure

  LED_CONNECTED_OUT(1);                 // Turn on  Debugger Connected LED
  LED_RUNNING_OUT(1);                   // Turn on  Target Running LED
  Delayms(500);                         // Wait for 500ms
  LED_RUNNING_OUT(0);                   // Turn off Target Running LED
  LED_CONNECTED_OUT(0);                 // Turn off Debugger Connected LED

  while (1) {                           // Endless Loop
    usbd_hid_process();                 // Process USB HID Data
  }
}
