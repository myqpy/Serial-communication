#include <iostream>


class selfcheck
{
public:
        int self_check(struct struct_rk_info *rk_info);
        // int regular_self_check(void);
        unsigned char check_4G_modem(void);
        unsigned char check_4G_IP_status(void);
        // int check_BD(void);
        unsigned char check_camera_AHD1(void);
        unsigned char check_TFcard(void);

private:
        unsigned char status = 0;
        unsigned char check_period = 0;
};

std::string getCmdResult(const std::string &strCmd);