/*.$file${.::bsp.c} vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv*/
/*
* Model: blinky_console.qm
* File:  ${.::bsp.c}
*
* This code has been generated by QM 5.1.1 <www.state-machine.com/qm/>.
* DO NOT EDIT THIS FILE MANUALLY. All your changes will be lost.
*
* This program is open source software: you can redistribute it and/or
* modify it under the terms of the GNU General Public License as published
* by the Free Software Foundation.
*
* This program is distributed in the hope that it will be useful, but
* WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
* or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License
* for more details.
*/
/*.$endhead${.::bsp.c} ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^*/
/* Board Support Package implementation for desktop OS (Windows, Linux, MacOS) */
#include "qpc.h"    /* QP/C framework API */
#include "bsp.h"    /* Board Support Package interface */
#include <stdio.h>  /* for printf()/fprintf() */
#include <stdlib.h> /* for exit() */

void BSP_init(void)   {
    printf("Simple Blinky example\n"
           "QP/C version: %s\n"
           "Press Ctrl-C to quit...\n",
           QP_VERSION_STR);
}
void BSP_ledOff(void) { printf("LED OFF\n"); }
void BSP_ledOn(void)  { printf("LED ON\n");  }

/* callback functions needed by the framework ------------------------------*/
void QF_onStartup(void) {}
void QF_onCleanup(void) {}
void QF_onClockTick(void) {
    QF_TICK_X(0U, (void *)0); /* QF clock tick processing for rate 0 */
}
void Q_onAssert(char const * const module, int loc) {
    fprintf(stderr, "Assertion failed in %s:%d", module, loc);
    exit(-1);
}