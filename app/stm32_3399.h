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

void update_stm32_3399_value(struct stm32_3399 *para, long up_dataHeader, int up_instantSpeed, 
                            int up_tripDistance, unsigned char up_isBrake, unsigned char up_chargingStatus, 
                            unsigned char *up_driversLicenseNum, unsigned char up_BccCheckValue);

void get_stm32_3399_value(long *up_dataHeader, int *up_instantSpeed, 
                            int *up_tripDistance, unsigned char* up_isBrake, unsigned char *up_chargingStatus, 
                            unsigned char *up_driversLicenseNum, unsigned char *up_BccCheckValue);