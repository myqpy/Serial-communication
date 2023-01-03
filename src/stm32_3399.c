#include "stm32_3399.h"

void update_stm32_3399_value(struct stm32_3399 *para)
{   
    para->dataHeader        =   0x5AA50001;
    para->instantSpeed      =   30;
    para->tripDistance      =   64;
    para->isBrake           =   0x0;
    para->chargingStatus    =   0x0;
    memset(para->driversLicenseNum, 0, 18);
    memcpy(para->driversLicenseNum, "410105199607150035", 18);
    para->BccCheckValue     =   0x0;

    printf("dataHeader == 0x%lX\n",para->dataHeader);
    printf("instantSpeed == %d\n",para->instantSpeed);
    printf("tripDistance == %d\n",para->tripDistance);
    printf("isBrake == %x\n",para->isBrake);
    printf("chargingStatus == %x\n",para->chargingStatus);
    printf("driversLicenseNum == %s\n",para->driversLicenseNum);
    printf("BccCheckValue == %x\n",para->BccCheckValue);

}