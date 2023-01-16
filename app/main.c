#include <stdio.h>
#include <string.h>
#include "stm32_3399.h"

int main(void)
{
    struct stm32_3399 parameter;
    long up_dataHeader;
    int up_instantSpeed, up_tripDistance;
    unsigned char up_isBrake;
    unsigned char up_chargingStatus; 
    unsigned char up_driversLicenseNum[20];
    unsigned char up_BccCheckValue;

    get_stm32_3399_value(&up_dataHeader, &up_instantSpeed, &up_tripDistance, &up_isBrake, 
                        &up_chargingStatus, up_driversLicenseNum, &up_BccCheckValue);
    update_stm32_3399_value(&parameter, up_dataHeader, up_instantSpeed, 
                            up_tripDistance, up_isBrake, up_chargingStatus, 
                            up_driversLicenseNum, up_BccCheckValue);
    return 0;    
}