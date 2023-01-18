#include "stm32_3399.h"
#include "utilUart.h"

// int stm32_value::get(unsigned long *up_dataHeader, unsigned int *up_instantSpeed, 
//                 unsigned int *up_tripDistance, unsigned char* up_isBrake, unsigned char *up_chargingStatus, 
//                 std::string &up_driversLicenseNum, unsigned char *up_BccCheckValue)
// {
//     *up_dataHeader        =   0x5AA50001;
//     *up_instantSpeed      =   30;
//     *up_tripDistance      =   64;
//     *up_isBrake         =   0x1;
//     *up_chargingStatus    =   0x2;
//     up_driversLicenseNum = "410105199601111111";
//     *up_BccCheckValue     =   0x3;

//     return 0;
// }

// int stm32_value::update(unsigned long up_dataHeader, unsigned int up_instantSpeed, 
//                             unsigned int up_tripDistance, unsigned char &up_isBrake, unsigned char up_chargingStatus, 
//                             std::string &up_driversLicenseNum, unsigned char up_BccCheckValue)
// {   

//     stm32_value::dataHeader        =   up_dataHeader;
//     std::cout << "dataHeader == " << std::hex <<  stm32_value::dataHeader << std::endl;
    
//     if(stm32_value::dataHeader == 0x5AA50001)
//     {
//         stm32_value::instantSpeed      =   up_instantSpeed;
//         stm32_value::tripDistance      =   up_tripDistance;
//         stm32_value::isBrake           =   up_isBrake;
//         stm32_value::chargingStatus    =   up_chargingStatus;
//         stm32_value::BccCheckValue     =   up_BccCheckValue;
//         if(up_driversLicenseNum.size() == 18)
//         {  
//             stm32_value::driversLicenseNum = up_driversLicenseNum;
//         }
//         else if(up_driversLicenseNum.size() == 15)
//         {
//             up_driversLicenseNum += "00H";
//             stm32_value::driversLicenseNum = up_driversLicenseNum;
//         }
//         else
//         {
//             std::cout << "身份证位数 = " << std::dec << up_driversLicenseNum.size() << " 错误 (应为15位或18位)" << std::endl;
//             stm32_value::driversLicenseNum = "00H";
//         }
//         std::cout << "driversLicenseNum == "        << stm32_value::driversLicenseNum   << std::endl;
//         std::cout << "instantSpeed == "<< std::dec  << stm32_value::instantSpeed        << std::endl;
//         std::cout << "tripDistance == "             << stm32_value::tripDistance        << std::endl;
//         std::cout << "isBrake == "                  << (int)stm32_value::isBrake        << std::endl;
//         std::cout << "chargingStatus == "           << (int)stm32_value::chargingStatus << std::endl;
//         std::cout << "BccCheckValue == "            << (int)stm32_value::BccCheckValue  << std::endl;
//     }

//     else
//     {
//         std::cout << "dataHeader == " << std::hex << stm32_value::dataHeader << "!= 0x5AA50001" << std::endl;
//     }

//     return 0;
// }








int stm32_value::get()
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

    
    up_dataHeader        =   0x5AA50001;
    up_instantSpeed      =   30;
    up_tripDistance      =   64;
    up_isBrake         =   0x1;
    up_chargingStatus    =   0x2;
    up_driversLicenseNum = "410105199601111111";
    up_BccCheckValue     =   0x3;

    return 0;
}

int stm32_value::update()
{   
    stm32_value::dataHeader        =   up_dataHeader;
    std::cout << "dataHeader == " << std::hex <<  stm32_value::dataHeader << std::endl;
    
    if(stm32_value::dataHeader == 0x5AA50001)
    {
        stm32_value::instantSpeed      =   up_instantSpeed;
        stm32_value::tripDistance      =   up_tripDistance;
        stm32_value::isBrake           =   up_isBrake;
        stm32_value::chargingStatus    =   up_chargingStatus;
        stm32_value::BccCheckValue     =   up_BccCheckValue;
        if(up_driversLicenseNum.size() == 18)
        {  
            stm32_value::driversLicenseNum = up_driversLicenseNum;
        }
        else if(up_driversLicenseNum.size() == 15)
        {
            up_driversLicenseNum += "00H";
            stm32_value::driversLicenseNum = up_driversLicenseNum;
        }
        else
        {
            std::cout << "身份证位数 = " << std::dec << up_driversLicenseNum.size() << " 错误 (应为15位或18位)" << std::endl;
            stm32_value::driversLicenseNum = "00H";
        }
        std::cout << "driversLicenseNum == "        << stm32_value::driversLicenseNum   << std::endl;
        std::cout << "instantSpeed == "<< std::dec  << stm32_value::instantSpeed        << std::endl;
        std::cout << "tripDistance == "             << stm32_value::tripDistance        << std::endl;
        std::cout << "isBrake == "                  << (int)stm32_value::isBrake        << std::endl;
        std::cout << "chargingStatus == "           << (int)stm32_value::chargingStatus << std::endl;
        std::cout << "BccCheckValue == "            << (int)stm32_value::BccCheckValue  << std::endl;
    }

    else
    {
        std::cout << "dataHeader == " << std::hex << stm32_value::dataHeader << "!= 0x5AA50001" << std::endl;
    }

    return 0;
}