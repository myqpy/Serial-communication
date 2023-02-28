#include <iostream>
#include "stm32_3399.h"
#include "selfcheck.h"
#include "switch4G.h"
#include <thread>

int main(void)
{
    /*调用自检接口*/
    selfcheck selfCheck;
    selfCheck.first_self_check();

    while (true)
    {
        selfCheck.regular_self_check();
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    }

    // stm32_value stm32_value;
    /*指针使用方法*/
    // stm32_to_rk3399 *stm32_to_rk3399_ = new stm32_to_rk3399;
    // stm32_value.get(stm32_to_rk3399_);
    // stm32_value.update(stm32_to_rk3399_);
    // delete stm32_to_rk3399_;

    /*引用使用方法*/
    // stm32_to_rk3399 stm32_to_rk3399_;
    // stm32_value.get(stm32_to_rk3399_);
    // stm32_value.update(stm32_to_rk3399_);

    /*4G开关指令*/
    // switch4G switch4G_;
    // switch4G_.open4G();
    // switch4G_.close4G();

    return 0;
}