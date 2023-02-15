#include <iostream>
#include <string.h>
#include "stm32_3399.h"
#include "selfcheck.h"


int main(void)
{
    // selfcheck selfCheck;
    // selfCheck.self_check();

    stm32_value stm32_value;
    stm32_to_rk3399 *stm32_to_rk3399;
    stm32_value.get(stm32_to_rk3399);
    stm32_value.update(stm32_to_rk3399);

    return 0;
}