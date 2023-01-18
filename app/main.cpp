#include <iostream>
#include <string.h>
#include "stm32_3399.h"


// int main(void)
// {
//     stm32_value stm32_value;

//     unsigned long up_dataHeader;
//     unsigned int up_instantSpeed;
//     unsigned int up_tripDistance;
//     unsigned char up_isBrake;
//     unsigned char up_chargingStatus; 
//     std::string up_driversLicenseNum;
//     unsigned char up_BccCheckValue;

//     stm32_value.get(&up_dataHeader, &up_instantSpeed, &up_tripDistance, &up_isBrake, 
//                          &up_chargingStatus, up_driversLicenseNum, &up_BccCheckValue);                  
//     stm32_value.update(up_dataHeader, up_instantSpeed, 
//                             up_tripDistance, up_isBrake, up_chargingStatus, 
//                             up_driversLicenseNum, up_BccCheckValue);
//     return 0;    
// }

int main(void)
{
    stm32_value stm32_value;
    stm32_value.get();           
    stm32_value.update();
    return 0;    
}