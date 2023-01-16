#include "stm32_3399.h"
void get_stm32_3399_value(long *up_dataHeader, int *up_instantSpeed, 
                            int *up_tripDistance, unsigned char* up_isBrake, unsigned char *up_chargingStatus, 
                            unsigned char *up_driversLicenseNum, unsigned char *up_BccCheckValue)
{
    *up_dataHeader        =   0x5AA50001;
    *up_instantSpeed      =   30;
    *up_tripDistance      =   64;
    *up_isBrake         =   0x5;
    *up_chargingStatus    =   0x3;
    memset(up_driversLicenseNum, 0, 20);
    memcpy(up_driversLicenseNum, "410105199607150000", 20);
    *up_BccCheckValue     =   0x7;
}

void update_stm32_3399_value(struct stm32_3399 *para, long up_dataHeader, int up_instantSpeed, 
                            int up_tripDistance, unsigned char up_isBrake, unsigned char up_chargingStatus, 
                            unsigned char *up_driversLicenseNum, unsigned char up_BccCheckValue)
{   
    para->dataHeader        =   up_dataHeader;
    para->instantSpeed      =   up_instantSpeed;
    para->tripDistance      =   up_tripDistance;
    para->isBrake           =   up_isBrake;
    para->chargingStatus    =   up_chargingStatus;
    para->BccCheckValue     =   up_BccCheckValue;
    if(strlen(up_driversLicenseNum) == 18)
    {  
        
        memset(para->driversLicenseNum, 0, 18);
        memcpy(para->driversLicenseNum, up_driversLicenseNum, 18);
    }
    else if(strlen(up_driversLicenseNum) == 15)
    {
        memset(para->driversLicenseNum, 0, 18);
        strncat(up_driversLicenseNum, "00H", 3);
        memcpy(para->driversLicenseNum, up_driversLicenseNum, 18);
    }
    else
    {
        printf("身份证位数 = %d 错误 (应为15位或18位)  \n", strlen(up_driversLicenseNum));
        return -1;
    }

    

    printf("dataHeader == 0x%lX\n",para->dataHeader);
    printf("instantSpeed == %d\n",para->instantSpeed);
    printf("tripDistance == %d\n",para->tripDistance);
    printf("isBrake == %x\n",para->isBrake);
    printf("chargingStatus == %x\n",para->chargingStatus);
    printf("driversLicenseNum == %s\n",para->driversLicenseNum);
    printf("BccCheckValue == %x\n",para->BccCheckValue);

}