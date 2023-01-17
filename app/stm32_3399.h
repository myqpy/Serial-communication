#include <iostream>
#include <string.h>

class stm32_value
{
    public:
        unsigned long   dataHeader;
        unsigned int    instantSpeed;
        unsigned int    tripDistance;
        unsigned char   isBrake;
        unsigned char   chargingStatus;
        std::string     driversLicenseNum;
        unsigned char   BccCheckValue;

        int get(unsigned long *up_dataHeader, unsigned int *up_instantSpeed, 
                        unsigned int *up_tripDistance, unsigned char* up_isBrake, 
                        unsigned char *up_chargingStatus, std::string &up_driversLicenseNum, 
                        unsigned char *up_BccCheckValue);
        int update(unsigned long up_dataHeader, unsigned int up_instantSpeed, 
                        unsigned int up_tripDistance, unsigned char &up_isBrake, 
                        unsigned char up_chargingStatus, std::string &up_driversLicenseNum, 
                        unsigned char up_BccCheckValue);
};

