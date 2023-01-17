#include <iostream>
#include <string.h>

using namespace std;


struct stm32_3399
{
    unsigned long   dataHeader;
    unsigned int    instantSpeed;
    unsigned int    tripDistance;
    unsigned char   isBrake;
    unsigned char   chargingStatus;
    char   driversLicenseNum[20];
    unsigned char   BccCheckValue;
};

int update_32_value(struct stm32_3399 *para, unsigned long up_dataHeader, unsigned int up_instantSpeed, 
                            unsigned int up_tripDistance, unsigned char up_isBrake, unsigned char up_chargingStatus, 
                            char *up_driversLicenseNum, unsigned char up_BccCheckValue);

int get_32_value(unsigned long *up_dataHeader, unsigned int *up_instantSpeed, 
                           unsigned int *up_tripDistance, unsigned char* up_isBrake, unsigned char *up_chargingStatus, 
                        char *up_driversLicenseNum, unsigned char *up_BccCheckValue);