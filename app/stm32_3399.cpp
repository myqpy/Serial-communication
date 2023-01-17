#include "stm32_3399.h"

int get_32_value(unsigned long *up_dataHeader, unsigned int *up_instantSpeed, 
                unsigned int *up_tripDistance, unsigned char* up_isBrake, unsigned char *up_chargingStatus, 
                char *up_driversLicenseNum, unsigned char *up_BccCheckValue)
{
    *up_dataHeader        =   0x5AA50001;
    *up_instantSpeed      =   30;
    *up_tripDistance      =   64;
    *up_isBrake         =   0x0;
    *up_chargingStatus    =   0x0;
    memset(up_driversLicenseNum, 0, 20);
    memcpy(up_driversLicenseNum, "410105199611002",20);
    *up_BccCheckValue     =   0x0;

    return 0;
}

int update_32_value(struct stm32_3399 *para, unsigned long up_dataHeader, unsigned int up_instantSpeed, 
                            unsigned int up_tripDistance, unsigned char up_isBrake, unsigned char up_chargingStatus, 
                            char *up_driversLicenseNum, unsigned char up_BccCheckValue)
{   

    para->dataHeader        =   up_dataHeader;
    cout << "dataHeader == " << hex << para->dataHeader << endl;
    if(para->dataHeader == 0x5AA50001)
    {
        para->instantSpeed      =   up_instantSpeed;
        para->tripDistance      =   up_tripDistance;
        para->isBrake           =   up_isBrake;
        para->chargingStatus    =   up_chargingStatus;
        para->BccCheckValue     =   up_BccCheckValue;
        if(strlen(up_driversLicenseNum) == 18)
        {  
            
            memset(para->driversLicenseNum, 0, 20);
            memcpy(para->driversLicenseNum, up_driversLicenseNum, 18);
        }
        else if(strlen(up_driversLicenseNum) == 15)
        {
            memset(para->driversLicenseNum, 0, 20);
            strncat(up_driversLicenseNum, "00H", 4);
            memcpy(para->driversLicenseNum, up_driversLicenseNum, 18);
        }
        else
        {
            memset(para->driversLicenseNum, 0, 20);
            cout << "身份证位数 = " << dec << strlen(up_driversLicenseNum) << " 错误 (应为15位或18位)" << endl;
            memcpy(para->driversLicenseNum, "00H", 4);
        }

        cout << "driversLicenseNum == "     << para->driversLicenseNum  << endl;
        cout << "instantSpeed == "  <<  dec << para->instantSpeed       << endl;
        cout << "tripDistance == "  <<  dec << para->tripDistance       << endl;
        cout << "isBrake == "               << para->isBrake            << endl;
        cout << "chargingStatus == "        << para->chargingStatus     << endl;
        cout << "BccCheckValue == "         << para->BccCheckValue      << endl;

        // printf("driversLicenseNum == %s\n",para->driversLicenseNum);
        // printf("instantSpeed == %d\n",para->instantSpeed);
        // printf("tripDistance == %d\n",para->tripDistance);
        // printf("isBrake == %x\n",para->isBrake);
        // printf("chargingStatus == %x\n",para->chargingStatus);
        // printf("BccCheckValue == %x\n",para->BccCheckValue);
    }

    else
    {
        cout << "dataHeader == " << hex << para->dataHeader << "!= 0x5AA50001" << endl;
    }

    return 0;
}