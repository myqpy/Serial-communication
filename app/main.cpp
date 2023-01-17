#include <iostream>
#include <string.h>
#include "stm32_3399.h"


using namespace std;

int main(void)
{
    struct stm32_3399 parameter;
    unsigned long up_dataHeader;
    unsigned int up_instantSpeed;
    unsigned int up_tripDistance;
    unsigned char up_isBrake;
    unsigned char up_chargingStatus; 
    char up_driversLicenseNum[20] = "0";
    unsigned char up_BccCheckValue;



    get_32_value(&up_dataHeader, &up_instantSpeed, &up_tripDistance, &up_isBrake, 
                        &up_chargingStatus, up_driversLicenseNum, &up_BccCheckValue);
    update_32_value(&parameter, up_dataHeader, up_instantSpeed, 
                            up_tripDistance, up_isBrake, up_chargingStatus, 
                            up_driversLicenseNum, up_BccCheckValue);
    return 0;    
}