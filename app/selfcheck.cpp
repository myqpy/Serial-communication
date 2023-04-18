#include "stm32_3399.h"
#include "utilUart.h"
#include "selfcheck.h"

#include <iostream>

/// 执行cmd指令并返回结果
std::string getCmdResult(const std::string &strCmd)
{
    char buf[10240] = {0};
    FILE *pf = NULL;

    if ((pf = popen(strCmd.c_str(), "r")) == NULL)
    {
        return "";
    }

    std::string strResult;
    while (fgets(buf, sizeof buf, pf))
    {
        strResult += buf;
    }

    pclose(pf);

    unsigned int iSize = strResult.size();
    if (iSize > 0 && strResult[iSize - 1] == '\n') // linux
    {
        strResult = strResult.substr(0, iSize - 1);
    }

    return strResult;
}

unsigned char selfcheck::check_4G_modem(void)
{
    std::string check_4G_modem = "ls /dev/ttyUSB*";
    std::string strRe = getCmdResult(check_4G_modem);
    if (strRe.find("/dev/ttyUSB0") != std::string::npos)
    {
        if (strRe.find("/dev/ttyUSB1") != std::string::npos)
        {
            if (strRe.find("/dev/ttyUSB2") != std::string::npos)
            {
                status = 1;
                std::cout << "4G modem OK." << std::endl;
            }
        }
    }
    else
    {
        status = 0;
    }
    return status;
}
// int selfcheck::check_BD(void)
// {

//     status = 1;
//     status = 0;
//     return status;
// }

unsigned char selfcheck::check_4G_IP_status(void)
{
    std::string camera_AHD1_check = "ifconfig";
    // auto ret = system(camera_check.c_str());
    std::string strRe = getCmdResult(camera_AHD1_check);
    // std::cout << strRe << std::endl;
    if (strRe.find("ppp0:") != std::string::npos)
    {
        if (strRe.find("UP,POINTOPOINT,RUNNING,NOARP,MULTICAST") != std::string::npos)
        {
            status = 1;
            std::cout << "4G Connetct OK." << std::endl;
        }
    }
    else
    {
        status = 0;
    }

    return status;
}

unsigned char selfcheck::check_camera_AHD1(void)
{
    std::string camera_AHD1_check = "dmesg | grep pr2000";
    // auto ret = system(camera_check.c_str());
    std::string strRe = getCmdResult(camera_AHD1_check);
    // std::cout << strRe << std::endl;
    if (strRe.find("Detected 720P25") != std::string::npos)
    {
        status = 1;
        std::cout << "camera_AHD1_check OK." << std::endl;
    }
    else
    {
        status = 0;
    }

    return status;
}
unsigned char selfcheck::check_TFcard(void)
{
    std::string TFcard_check = "sudo fdisk -l";
    std::string strRe = getCmdResult(TFcard_check);
    if (strRe.find("Disk /dev/mmcblk0") != std::string::npos)
    {
        status = 1;
        std::cout << "TFcard OK." << std::endl;
    }
    else
    {
        status = 0;
    }

    return status;
}

int selfcheck::self_check(struct_rk_info *rk_info)
{
    // struct struct_rk_info *rk_info = new struct_rk_info;
    rk_info->op = 0xee;
    rk_info->SDStatus = selfcheck::check_TFcard();
    rk_info->EC20Status = (selfcheck::check_4G_modem()) && (selfcheck::check_4G_IP_status());
    rk_info->cameraStatus = selfcheck::check_camera_AHD1();
    // rk_info->SDStatus = 1;
    // rk_info->EC20Status = 1;
    // rk_info->cameraStatus = 1;
    // rk_info->EC20SignalStrength = 1;
    // rk_info->BDStatus = 1;
    // rk_info->velocityStatus = 1;

    // if (selfcheck::check_4G_modem() == 0)
    // {
    //     std::cout << "4G modem error." << std::endl;
    // }
    // // if (selfcheck::check_BD() == 0)
    // // {
    // //     std::cout << "BD modem error." << std::endl;
    // // }
    // if (selfcheck::check_camera_AHD1() == 0)
    // {
    //     std::cout << "check_camera_AHD1 error." << std::endl;
    // }
    // if (selfcheck::check_TFcard() == 0)
    // {
    //     std::cout << "TFcard error." << std::endl;
    // }
    // // else
    // // {
    // //     std::cout << "Self Check Passed." << std::endl;
    // // }

    // if (selfcheck::check_4G_IP_status() == 0)
    // {
    //     std::cout << "4G connect error." << std::endl;
    // }
    return 0;
}
