#include "stm32_3399.h"
#include "utilUart.h"

int stm32_value::get(stm32_to_rk3399 *stm32_to_rk3399)
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


    stm32_to_rk3399->dataHeader = 0x5AA50001;

    stm32_to_rk3399->driversLicenseNum = "41010519960715003";                                                                         // 01H 当前驾驶员信息*
    stm32_to_rk3399->initTime = "230215";                                                                                           // 02H 初次安装时间
    stm32_to_rk3399->initDistance = 123;                                                                                            // 03H 初始里程
    stm32_to_rk3399->tripDistance = 455;                                                                                            // 03H 累计行驶里程
    stm32_to_rk3399->impulseIndexHigh = 0x01;                                                                                       // 04H 脉冲系数高字节
    stm32_to_rk3399->impulseIndexLow = 0x00;                                                                                        // 04H 脉冲系数低字节
    stm32_to_rk3399->workingConditionSigNum = 0x05;                                                                                 // 06H 状态信号字节个数
    stm32_to_rk3399->D7signal = 0x01;                                                                                               // 06H D7 制动
    stm32_to_rk3399->D6signal = 0x01;                                                                                               // 06H D6 左转
    stm32_to_rk3399->D5signal = 0x01;                                                                                               // 06H D5 右转
    stm32_to_rk3399->D4signal = 0x01;                                                                                               // 06H D4 远光
    stm32_to_rk3399->D3signal = 0x01;                                                                                               // 06H D3 近光
    stm32_to_rk3399->D2signal = 0x00;                                                                                               // 06H D2 xx
    stm32_to_rk3399->D1signal = 0x00;                                                                                               // 06H D1 xx
    stm32_to_rk3399->D0signal = 0x00;                                                                                               // 06H D0 xx
    stm32_to_rk3399->avgSpeed = 50;                                                                                                 // 08H 平均速度
    stm32_to_rk3399->GGA = "$GNGGA,045449.000,3951.764319,N,11615.386554,E,2,19,0.70,57.726,M,-9.89,M,11,0000*69,1872,2d,19,0,0,0"; // 09H 位置信息记录GGA高度信息
    stm32_to_rk3399->loginORlogout = 0x1;                                                                                           // 12H 单位驾驶人身份记录
    stm32_to_rk3399->chargingStatus = 0x1;                                                                                          // 13H 外部供电记录
    stm32_to_rk3399->eventType = 0x55;                                                                                              // 14H 参数修改记录
    stm32_to_rk3399->BccCheckValue = 0xF2;

    return 0;
}

int stm32_value::update(stm32_to_rk3399 *stm32_to_rk3399)
{
    stm32_to_rk3399->update.dataHeader = stm32_to_rk3399->dataHeader;
    std::cout << "dataHeader == " << std::hex << stm32_to_rk3399->update.dataHeader << std::endl;

    if (stm32_to_rk3399->dataHeader == 0x5AA50001)
    {

        if (stm32_to_rk3399->driversLicenseNum.size() == 18)
        {
            stm32_to_rk3399->update.driversLicenseNum = stm32_to_rk3399->driversLicenseNum;
        }
        else if (stm32_to_rk3399->driversLicenseNum.size() == 15)
        {
            stm32_to_rk3399->driversLicenseNum += "000";
            stm32_to_rk3399->update.driversLicenseNum = stm32_to_rk3399->driversLicenseNum;
        }
        else
        {
            std::cout << "身份证位数 = " << std::dec << stm32_to_rk3399->driversLicenseNum.size() << " 错误 (应为15位或18位)" << std::endl;
            stm32_to_rk3399->update.driversLicenseNum = "000000000000000000";
        }

        stm32_to_rk3399->update.initTime = stm32_to_rk3399->initTime;                             // 02H 初次安装时间
        stm32_to_rk3399->update.initDistance = stm32_to_rk3399->initDistance;                     // 03H 初始里程
        stm32_to_rk3399->update.tripDistance = stm32_to_rk3399->tripDistance;                     // 03H 累计行驶里程
        stm32_to_rk3399->update.impulseIndexHigh = stm32_to_rk3399->impulseIndexHigh;             // 04H 脉冲系数高字节
        stm32_to_rk3399->update.impulseIndexLow = stm32_to_rk3399->impulseIndexLow;               // 04H 脉冲系数低字节
        stm32_to_rk3399->update.workingConditionSigNum = stm32_to_rk3399->workingConditionSigNum; // 06H 状态信号字节个数
        stm32_to_rk3399->update.D7signal = stm32_to_rk3399->D7signal;                             // 06H D7 制动
        stm32_to_rk3399->update.D6signal = stm32_to_rk3399->D6signal;                             // 06H D6 左转
        stm32_to_rk3399->update.D5signal = stm32_to_rk3399->D5signal;                             // 06H D5 右转
        stm32_to_rk3399->update.D4signal = stm32_to_rk3399->D4signal;                             // 06H D4 远光
        stm32_to_rk3399->update.D3signal = stm32_to_rk3399->D3signal;                             // 06H D3 近光
        stm32_to_rk3399->update.D2signal = stm32_to_rk3399->D2signal;                             // 06H D2 xx
        stm32_to_rk3399->update.D1signal = stm32_to_rk3399->D1signal;                             // 06H D1 xx
        stm32_to_rk3399->update.D0signal = stm32_to_rk3399->D0signal;                             // 06H D0 xx
        stm32_to_rk3399->update.avgSpeed = stm32_to_rk3399->avgSpeed;                             // 08H 平均速度
        stm32_to_rk3399->update.GGA = stm32_to_rk3399->GGA;                                       // 09H 位置信息记录GGA高度信息
        stm32_to_rk3399->update.loginORlogout = stm32_to_rk3399->loginORlogout;                   // 12H 单位驾驶人身份记录
        stm32_to_rk3399->update.chargingStatus = stm32_to_rk3399->chargingStatus;                 // 13H 外部供电记录
        stm32_to_rk3399->update.eventType = stm32_to_rk3399->eventType;                           // 14H 参数修改记录
        stm32_to_rk3399->update.BccCheckValue = stm32_to_rk3399->BccCheckValue;

        std::cout << "driversLicenseNum == " << stm32_to_rk3399->update.driversLicenseNum << std::endl;
        std::cout << "initTime == " << stm32_to_rk3399->update.initTime << std::endl;
        std::cout << "initDistance == " << std::dec <<stm32_to_rk3399->update.initDistance << std::endl;
        std::cout << "tripDistance == " << stm32_to_rk3399->update.tripDistance << std::endl;
        std::cout << "impulseIndexHigh == " << (int)stm32_to_rk3399->update.impulseIndexHigh << std::endl;
        std::cout << "impulseIndexLow == " << (int)stm32_to_rk3399->update.impulseIndexLow << std::endl;
        std::cout << "workingConditionSigNum == " << (int)stm32_to_rk3399->update.workingConditionSigNum << std::endl;
        std::cout << "D7signal == " << (int)stm32_to_rk3399->update.D7signal << std::endl;
        std::cout << "D6signal == " << (int)stm32_to_rk3399->update.D6signal << std::endl;
        std::cout << "D5signal == " << (int)stm32_to_rk3399->update.D5signal << std::endl;
        std::cout << "D4signal == " << (int)stm32_to_rk3399->update.D4signal << std::endl;
        std::cout << "D3signal == " << (int)stm32_to_rk3399->update.D3signal << std::endl;
        std::cout << "D2signal == " << (int)stm32_to_rk3399->update.D2signal << std::endl;
        std::cout << "D1signal == " << (int)stm32_to_rk3399->update.D1signal << std::endl;
        std::cout << "D0signal == " << (int)stm32_to_rk3399->update.D0signal << std::endl;
        std::cout << "avgSpeed == " << (int)stm32_to_rk3399->update.avgSpeed << std::endl;
        std::cout << "GGA == " << stm32_to_rk3399->update.GGA << std::endl;
        std::cout << "loginORlogout == " << (int)stm32_to_rk3399->update.loginORlogout << std::endl;
        std::cout << "chargingStatus == " << (int)stm32_to_rk3399->update.chargingStatus << std::endl;
        std::cout << "eventType == " <<std::hex<<(int)stm32_to_rk3399->update.eventType << std::endl;
        std::cout << "BccCheckValue == " << (int)stm32_to_rk3399->update.BccCheckValue << std::endl;
    }

    else
    {
        std::cout << "dataHeader == " << std::hex << stm32_to_rk3399->update.dataHeader << "!= 0x5AA50001" << std::endl;
    }

    return 0;
}