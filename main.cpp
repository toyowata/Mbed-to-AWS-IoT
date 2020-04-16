/*******************************************************************************
 * Copyright (c) 2014, 2015 IBM Corp.
 *
 * All rights reserved. This program and the accompanying materials
 * are made available under the terms of the Eclipse Public License v1.0
 * and Eclipse Distribution License v1.0 which accompany this distribution.
 *
 * The Eclipse Public License is available at
 *    http://www.eclipse.org/legal/epl-v10.html
 * and the Eclipse Distribution License is available at
 *   http://www.eclipse.org/org/documents/edl-v10.php.
 *
 * Contributors:
 *    Ian Craggs - initial API and implementation and/or initial documentation
 *    Ian Craggs - make sure QoS2 processing works, and add device headers
 *******************************************************************************/

 /**
  This is a sample program to illustrate the use of the MQTT Client library
  on the mbed platform.  The Client class requires two classes which mediate
  access to system interfaces for networking and timing.  As long as these two
  classes provide the required public programming interfaces, it does not matter
  what facilities they use underneath. In this program, they use the mbed
  system libraries.

 */

#include "mbed.h"
#include "mbed-trace/mbed_trace.h"

/* Enable GPIO power for Wio target */
#if defined(TARGET_WIO_3G) || defined(TARGET_WIO_BG96)
DigitalOut GrovePower(GRO_POWR, 1);
#endif

Thread thread1;

void mqtt_thread();

int main(int argc, char* argv[])
{
    thread_sleep_for(100);
    mbed_trace_init();

    thread1.start(mqtt_thread);
}