#include <stdio.h>
#include <string.h>

struct stm32_3399
{
    unsigned long   dataHeader;
    unsigned int    instantSpeed;
    unsigned int    tripDistance;
    unsigned char   isBrake;
    unsigned char   chargingStatus;
    unsigned char   driversLicenseNum[20];
    unsigned char   BccCheckValue;
};

void update_stm32_3399_value(struct stm32_3399 *para);