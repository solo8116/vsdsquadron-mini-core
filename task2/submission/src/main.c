#include <ch32v00x.h>
#include "gpio.h"
#include <debug.h>

#define BOARD_NAME       "VSDSquadron Mini (CH32V003F4U6)"
#define FW_VERSION       "v1.0.0"
#define BLINK_PERIOD_MS   500u

static void print_banner(void)
{
    printf("========================================\n");
    printf("  VSDSquadron Mini - Firmware Task 2\n");
    printf("  Board   : %s\n", BOARD_NAME);
    printf("  Version : %s\n", FW_VERSION);
    printf("  Author  : Sarthak Garg\n");
    printf("  UART TX : PD5  |  LED : PD6\n");
    printf("========================================\n");
    printf("[BOOT] System initialised.\n");
}



int main(void) {

    NVIC_PriorityGroupConfig(NVIC_PriorityGroup_1);
    SystemCoreClockUpdate();
    Delay_Init();

    USART_Printf_Init(15200);

    print_banner();
    
    int loop_counter = 0;

    gpio_init(PORT_D, LED_PIN, GPIO_OUTPUT);

    while (1)
    {
        printf("Counter:%i\n",loop_counter);
        gpio_toggle(PORT_D, LED_PIN);
        loop_counter++;
        Delay_Ms(BLINK_PERIOD_MS);
    }
}