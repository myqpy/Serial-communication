#include <iostream>

class selfcheck
{
public:
        int first_self_check(void);
        int regular_self_check(void);
        int check_4G_modem(void);
        int check_4G_status(void);
        // int check_BD(void);
        int check_camera_AHD1(void);
        int check_TFcard(void);

private:
        int status = 0;
        int check_period = 0;
};

std::string getCmdResult(const std::string &strCmd);