/******************************************************************************
 *
 * Copyright (C) 2022-2023 Maxim Integrated Products, Inc. (now owned by 
 * Analog Devices, Inc.),
 * Copyright (C) 2023-2024 Analog Devices, Inc.
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
 *
 ******************************************************************************/

/*
 * @file    main.c
 * @brief   Demonstrates a watchdog timer in run mode
 *
 * @details When the program starts LED1 blinks three times and stops.
 *          Then LED0 start blinking continuously.
 *          Open a terminal program to see interrupt messages.
 *
 *          SW1: Push SW1 to trigger a watchdog reset. This will reset the watchdog before
 *               the wait period has expired and trigger an interrupt.
 *
 *          SW2: Push SW2 to trigger a delay and see LED0 stop blinking momentarily.
 *               This delay long enough for the timeout period to expire and trigger an interrupt.
 */

/***** Includes *****/
#include <stdio.h>
#include <stdint.h>
#include "mxc_device.h"
#include "mxc_sys.h"
#include "mxc_delay.h"
#include "nvic_table.h"
#include "wdt.h"
#include "led.h"
#include "board.h"

/***** Definitions *****/
#define SW1 0
#define SW2 1

/***** Globals *****/
#if defined(BOARD_FTHR)
static mxc_gpio_cfg_t pb_pin[] = {
    { MXC_GPIO1, MXC_GPIO_PIN_10, MXC_GPIO_FUNC_IN, MXC_GPIO_PAD_PULL_UP, MXC_GPIO_VSSEL_VDDIO },
    { MXC_GPIO0, MXC_GPIO_PIN_16, MXC_GPIO_FUNC_IN, MXC_GPIO_PAD_PULL_UP, MXC_GPIO_VSSEL_VDDIO },
};
#elif defined(BOARD_FTHR2)
static mxc_gpio_cfg_t pb_pin[] = {
    { MXC_GPIO0, MXC_GPIO_PIN_24, MXC_GPIO_FUNC_IN, MXC_GPIO_PAD_PULL_UP, MXC_GPIO_VSSEL_VDDIO },
    { MXC_GPIO0, MXC_GPIO_PIN_28, MXC_GPIO_FUNC_IN, MXC_GPIO_PAD_PULL_UP, MXC_GPIO_VSSEL_VDDIO },
};
#else
static mxc_gpio_cfg_t pb_pin[] = {
    { MXC_GPIO1, MXC_GPIO_PIN_6, MXC_GPIO_FUNC_IN, MXC_GPIO_PAD_PULL_UP, MXC_GPIO_VSSEL_VDDIOH },
    { MXC_GPIO1, MXC_GPIO_PIN_7, MXC_GPIO_FUNC_IN, MXC_GPIO_PAD_PULL_UP, MXC_GPIO_VSSEL_VDDIOH },
};
#endif

/***** Functions *****/

// *****************************************************************************
void watchdog_timeout_handler(void)
{
    //get and clear flag
    MXC_WDT_GetIntFlag(MXC_WDT0);
    MXC_WDT_ClearIntFlag(MXC_WDT0);
    printf("\nTIMEOUT! \n");
}

// *****************************************************************************
void WDT0_IRQHandler(void)
{
    watchdog_timeout_handler();
}
// *****************************************************************************
void MXC_WDT_Setup(void)
{
    MXC_WDT_Disable(MXC_WDT0);
    MXC_WDT_Enable(MXC_WDT0);
}

void blinkled(int led, int num_of_blink)
{
    for (int i = 0; i < num_of_blink; i++) {
        LED_On(led);
        MXC_Delay(MXC_DELAY_MSEC(100));
        LED_Off(led);
        MXC_Delay(MXC_DELAY_MSEC(100));
    }
}

// *****************************************************************************
int main(void)
{
    MXC_WDT_Init(MXC_WDT0);

    if (MXC_WDT_GetResetFlag(MXC_WDT0)) {
        MXC_WDT_ClearResetFlag(MXC_WDT0);
        MXC_WDT_DisableReset(MXC_WDT0);
        MXC_WDT_Enable(MXC_WDT0);
        printf("\nWatchdog reset\n");
    }

    printf("\n************** Watchdog Timer Demo ****************\n");
    printf("Press a button to create watchdog interrupt or reset:\n");
    // Please check pb_pin[] array to get Pushbuttons port&pin detail
    // If your board does not have 2 pushbuttons you can use related Port&Pin directly.
    printf("PushButton1  = reset program\n");
    printf("PushButton2  = timeout interrupt\n");

    // Configure GPIO
    MXC_GPIO_Config(&pb_pin[SW1]);
    MXC_GPIO_Config(&pb_pin[SW2]);

    //blink LED1 three times at startup
    blinkled(1, 3);

    //setup watchdog
    MXC_WDT_Setup();

    while (1) {
        //Push SW1 to reset watchdog
        if (MXC_GPIO_InGet(pb_pin[SW1].port, pb_pin[SW1].mask) == 0) {
            printf("\nResetting Program...\n");
            MXC_WDT_SetResetPeriod(MXC_WDT0, MXC_WDT_PERIOD_2_18);
            MXC_WDT_EnableReset(MXC_WDT0);
            MXC_WDT_EnableInt(MXC_WDT0);
            MXC_WDT_ResetTimer(MXC_WDT0);
            while (1) {}
        }

        //Push SW2 to start longer delay - shows Interrupt before the reset happens
        if (MXC_GPIO_InGet(pb_pin[SW2].port, pb_pin[SW2].mask) == 0) {
            printf("\nEnabling Timeout Interrupt...\n");
            MXC_WDT_SetResetPeriod(MXC_WDT0, MXC_WDT_PERIOD_2_27);
            MXC_WDT_SetIntPeriod(MXC_WDT0, MXC_WDT_PERIOD_2_26);
            MXC_WDT_EnableReset(MXC_WDT0);
            MXC_WDT_EnableInt(MXC_WDT0);
            NVIC_EnableIRQ(WDT0_IRQn);
            while (1) {}
        }

        //blink LED0
        blinkled(0, 1);

        //Reset watchdog
        MXC_WDT_ResetTimer(MXC_WDT0);
    }
}
