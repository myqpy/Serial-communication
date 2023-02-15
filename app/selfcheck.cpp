#include "stm32_3399.h"
#include "utilUart.h"
#include "selfcheck.h"

int selfcheck::check_4G(void)
{
    status = 1;
    status = 0;
    return status;
}
int selfcheck::check_BD(void)
{
    status = 1;
    status = 0;
    return status;
}
int selfcheck::check_camera(void)
{
    status = 1;
    status = 0;
    return status;
}

int selfcheck::self_check(void)
{
    if (selfcheck::check_4G() == 0)
    {
        std::cout << "4G modem error." << std::endl;
        if (selfcheck::check_BD() == 0)
        {
            std::cout << "BD modem error." << std::endl;
            if (selfcheck::check_camera() == 0)
            {
                std::cout << "camera error." << std::endl;
            }
        }
    }

    else
    {
        std::cout << "Self Check Passed." << std::endl;
    }

    return 0;
}