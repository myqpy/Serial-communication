#include "switch4G.h"
#include "selfcheck.h"

int switch4G::open4G(void)
{
    std::string open4G = "/home/work/4G/ppp-on-10086 &";
    // auto ret = system(open4G.c_str());
    std::string strRe = getCmdResult(open4G);
    if (strRe.find("local  IP address 10") != std::string::npos)
    {
        std::cout << "4G Open Success" << std::endl;
    }
    else
    {
        std::cout << "4G Open Fail" << std::endl;
    }
    return 0;
}

int switch4G::close4G(void)
{
    std::string close4G = "/home/work/4G/disconnect";
    // auto ret = system(close4G.c_str());
    std::string strRe = getCmdResult(close4G);
    if (strRe.find("Connection terminated.") != std::string::npos)
    {
        std::cout << "4G close Success" << std::endl;
    }
    else
    {
        std::cout << "4G close Fail" << std::endl;
    }
    return 0;
}