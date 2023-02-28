#include "stm32_3399.h"
#include "utilUart.h"

// int stm32_value::get(struct stm32_to_rk3399 &stm32_to_rk3399_)
// {
//     stm32_to_rk3399_.dataHeader = 0x5AA50001;
//     stm32_to_rk3399_.driversLicenseNum = "410105199607150035";   // 01H 当前驾驶员信息*
//     return 0;
// }

// int stm32_value::update(struct stm32_to_rk3399 &stm32_to_rk3399_)
// {
//     stm32_to_rk3399_.update.dataHeader = stm32_to_rk3399_.dataHeader;
//     std::cout << "dataHeader == " << std::hex << stm32_to_rk3399_.update.dataHeader << std::endl;
// }
int stm32_value::get(struct stm32_to_rk3399 *stm32_to_rk3399_)
{
    // char buff[UART_GPS_BUF_SIZE];
    // int index = -1;

    // int open_count = 0;
    // while (1)
    // {
    //     index = UartOpen(UART1, 115200, 8, 1, NO_CHECK);
    //     open_count++;

    //     if (index <= 0)
    //     {
    //         //std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    //         if (open_count >= 3)
    //         {
    //             system("sudo reboot");
    //         }
    //         continue;
    //     }
    //     else
    //     {
    //         open_count = 0;
    //         break;
    //     }
    // }

    stm32_to_rk3399_->dataHeader = 0x5AA50001;

    stm32_to_rk3399_->driversLicenseNum = "410105199607150035";   // 01H 当前驾驶员信息*
    stm32_to_rk3399_->initTime = "230215";                        // 02H 初次安装时间
    stm32_to_rk3399_->initDistance = 123;                         // 03H 初始里程
    stm32_to_rk3399_->tripDistance = 455;                         // 03H 累计行驶里程
    stm32_to_rk3399_->impulseIndexHigh = 0x01;                    // 04H 脉冲系数高字节
    stm32_to_rk3399_->impulseIndexLow = 0x00;                     // 04H 脉冲系数低字节
    stm32_to_rk3399_->workingConditionSigNum = 0x05;              // 06H 状态信号字节个数
    stm32_to_rk3399_->workingConditionIO_get.bit.D7signal = 0x01; // 06H D7 制动
    stm32_to_rk3399_->workingConditionIO_get.bit.D6signal = 0x01; // 06H D6 左转
    stm32_to_rk3399_->workingConditionIO_get.bit.D5signal = 0x01; // 06H D5 右转
    stm32_to_rk3399_->workingConditionIO_get.bit.D4signal = 0x01; // 06H D4 远光
    stm32_to_rk3399_->workingConditionIO_get.bit.D3signal = 0x01; // 06H D3 近光
    stm32_to_rk3399_->workingConditionIO_get.bit.D2signal = 0x00; // 06H D2 xx
    stm32_to_rk3399_->workingConditionIO_get.bit.D1signal = 0x00; // 06H D1 xx
    stm32_to_rk3399_->workingConditionIO_get.bit.D0signal = 0x00; // 06H D0 xx
    stm32_to_rk3399_->avgSpeed = 50;                              // 08H 平均速度

    stm32_to_rk3399_->loginORlogout = 0x1;  // 12H 单位驾驶人身份记录
    stm32_to_rk3399_->chargingStatus = 0x1; // 13H 外部供电记录
    stm32_to_rk3399_->eventType = 0x55;     // 14H 参数修改记录
    stm32_to_rk3399_->BccCheckValue = 0xF2;

    return 0;
}

int stm32_value::update(struct stm32_to_rk3399 *stm32_to_rk3399_)
{
    stm32_to_rk3399_->update.dataHeader = stm32_to_rk3399_->dataHeader;
    std::cout << "dataHeader == " << std::hex << stm32_to_rk3399_->update.dataHeader << std::endl;

    if (stm32_to_rk3399_->dataHeader == 0x5AA50001)
    {

        if (stm32_to_rk3399_->driversLicenseNum.size() == 18)
        {
            stm32_to_rk3399_->update.driversLicenseNum = stm32_to_rk3399_->driversLicenseNum;
        }
        else if (stm32_to_rk3399_->driversLicenseNum.size() == 15)
        {
            stm32_to_rk3399_->driversLicenseNum += "000";
            stm32_to_rk3399_->update.driversLicenseNum = stm32_to_rk3399_->driversLicenseNum;
        }
        else
        {
            std::cout << "身份证位数 = " << std::dec << stm32_to_rk3399_->driversLicenseNum.size() << " 错误 (应为15位或18位)" << std::endl;
            stm32_to_rk3399_->update.driversLicenseNum = "000000000000000000";
        }

        stm32_to_rk3399_->update.initTime = stm32_to_rk3399_->initTime;                                                          // 02H 初次安装时间
        stm32_to_rk3399_->update.initDistance = stm32_to_rk3399_->initDistance;                                                  // 03H 初始里程
        stm32_to_rk3399_->update.tripDistance = stm32_to_rk3399_->tripDistance;                                                  // 03H 累计行驶里程
        stm32_to_rk3399_->update.impulseIndexHigh = stm32_to_rk3399_->impulseIndexHigh;                                          // 04H 脉冲系数高字节
        stm32_to_rk3399_->update.impulseIndexLow = stm32_to_rk3399_->impulseIndexLow;                                            // 04H 脉冲系数低字节
        stm32_to_rk3399_->update.workingConditionSigNum = stm32_to_rk3399_->workingConditionSigNum;                              // 06H 状态信号字节个数
        stm32_to_rk3399_->update.workingConditionIO_update.bit.D7signal = stm32_to_rk3399_->workingConditionIO_get.bit.D7signal; // 06H D7 制动
        stm32_to_rk3399_->update.workingConditionIO_update.bit.D6signal = stm32_to_rk3399_->workingConditionIO_get.bit.D6signal; // 06H D6 左转
        stm32_to_rk3399_->update.workingConditionIO_update.bit.D5signal = stm32_to_rk3399_->workingConditionIO_get.bit.D5signal; // 06H D5 右转
        stm32_to_rk3399_->update.workingConditionIO_update.bit.D4signal = stm32_to_rk3399_->workingConditionIO_get.bit.D4signal; // 06H D4 远光
        stm32_to_rk3399_->update.workingConditionIO_update.bit.D3signal = stm32_to_rk3399_->workingConditionIO_get.bit.D3signal; // 06H D3 近光
        stm32_to_rk3399_->update.workingConditionIO_update.bit.D2signal = stm32_to_rk3399_->workingConditionIO_get.bit.D2signal; // 06H D2 xx
        stm32_to_rk3399_->update.workingConditionIO_update.bit.D1signal = stm32_to_rk3399_->workingConditionIO_get.bit.D1signal; // 06H D1 xx
        stm32_to_rk3399_->update.workingConditionIO_update.bit.D0signal = stm32_to_rk3399_->workingConditionIO_get.bit.D0signal; // 06H D0 xx
        stm32_to_rk3399_->update.avgSpeed = stm32_to_rk3399_->avgSpeed;                                                          // 08H 平均速度
        stm32_to_rk3399_->update.loginORlogout = stm32_to_rk3399_->loginORlogout;                                                // 12H 单位驾驶人身份记录
        stm32_to_rk3399_->update.chargingStatus = stm32_to_rk3399_->chargingStatus;                                              // 13H 外部供电记录
        stm32_to_rk3399_->update.eventType = stm32_to_rk3399_->eventType;                                                        // 14H 参数修改记录
        stm32_to_rk3399_->update.BccCheckValue = stm32_to_rk3399_->BccCheckValue;

        std::cout << "driversLicenseNum == " << stm32_to_rk3399_->update.driversLicenseNum << std::endl;
        std::cout << "initTime == " << stm32_to_rk3399_->update.initTime << std::endl;
        std::cout << "initDistance == " << std::dec << stm32_to_rk3399_->update.initDistance << std::endl;
        std::cout << "tripDistance == " << stm32_to_rk3399_->update.tripDistance << std::endl;
        std::cout << "impulseIndexHigh == " << (int)stm32_to_rk3399_->update.impulseIndexHigh << std::endl;
        std::cout << "impulseIndexLow == " << (int)stm32_to_rk3399_->update.impulseIndexLow << std::endl;
        std::cout << "workingConditionSigNum == " << (int)stm32_to_rk3399_->update.workingConditionSigNum << std::endl;
        std::cout << "D7signal == " << (int)stm32_to_rk3399_->update.workingConditionIO_update.bit.D7signal << std::endl;
        std::cout << "D6signal == " << (int)stm32_to_rk3399_->update.workingConditionIO_update.bit.D6signal << std::endl;
        std::cout << "D5signal == " << (int)stm32_to_rk3399_->update.workingConditionIO_update.bit.D5signal << std::endl;
        std::cout << "D4signal == " << (int)stm32_to_rk3399_->update.workingConditionIO_update.bit.D4signal << std::endl;
        std::cout << "D3signal == " << (int)stm32_to_rk3399_->update.workingConditionIO_update.bit.D3signal << std::endl;
        std::cout << "D2signal == " << (int)stm32_to_rk3399_->update.workingConditionIO_update.bit.D2signal << std::endl;
        std::cout << "D1signal == " << (int)stm32_to_rk3399_->update.workingConditionIO_update.bit.D1signal << std::endl;
        std::cout << "D0signal == " << (int)stm32_to_rk3399_->update.workingConditionIO_update.bit.D0signal << std::endl;
        std::cout << "avgSpeed == " << (int)stm32_to_rk3399_->update.avgSpeed << std::endl;

        std::cout << "loginORlogout == " << (int)stm32_to_rk3399_->update.loginORlogout << std::endl;
        std::cout << "chargingStatus == " << (int)stm32_to_rk3399_->update.chargingStatus << std::endl;
        std::cout << "eventType == " << std::hex << (int)stm32_to_rk3399_->update.eventType << std::endl;
        std::cout << "BccCheckValue == " << (int)stm32_to_rk3399_->update.BccCheckValue << std::endl;
    }

    else
    {
        std::cout << "dataHeader == " << std::hex << stm32_to_rk3399_->update.dataHeader << "!= 0x5AA50001" << std::endl;
    }

    return 0;
}