/*********************************************************************
*                    SEGGER Microcontroller GmbH                     *
*                        The Embedded Experts                        *
**********************************************************************

-------------------------- END-OF-HEADER -----------------------------

File    : main.c
Purpose : Generic application start

*/

#include <stdio.h>
#include "main.h"
/*********************************************************************
*
*       main()
*
*  Function description
*   Application entry point.
*/
int main(void)
{
    rcu_periph_clock_enable(RCU_GPIOC);
    rcu_periph_clock_enable(RCU_PMU);

    systick_config();

    //USB Pullup
    gpio_init(GPIOC, GPIO_MODE_OUT_PP, GPIO_OSPEED_10MHZ, GPIO_PIN_11);
    gpio_init(GPIOC, GPIO_MODE_OUT_PP, GPIO_OSPEED_10MHZ, GPIO_PIN_12);
    gpio_bit_reset(GPIOC, GPIO_PIN_12);
    uint8_t x = 0;

    while (1)
    {
        gpio_bit_write(GPIOC, GPIO_PIN_12, (bit_status)(x++ & 0x1));
        delay_1ms(500);
    }

}

//void SysTick_Handler(void)
//{
//    delay_decrement();
//}

/*************************** End of file ****************************/
