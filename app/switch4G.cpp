#include "switch4G.h"
#include "selfcheck.h"
#include "utilUart.h"
#include <thread>

int EC20_Control::open4G(void)
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

int EC20_Control::close4G(void)
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

unsigned char buff[512];
std::string str_buf = "";
// std::string cmd = "";
int EC20_Control::ATcmd_response(int index, std::string cmd)
{
    UartWrite(index, cmd.c_str(), cmd.size());

    while (1)
    {
        auto size = UartRead(index, buff, sizeof(buff));
        str_buf.assign(buff, buff + size);
        printf("%s", buff);
        auto inx_OK = str_buf.find("OK");
        if (inx_OK != std::string::npos)
        {
            // std::this_thread::sleep_for(std::chrono::milliseconds(100));
            break;
        }
    }
}

int EC20_Control::ATcmd_no_response(int index, std::string cmd)
{
    UartWrite(index, cmd.c_str(), cmd.size());
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    auto size = UartRead(index, buff, sizeof(buff));
    str_buf.assign(buff, buff + size);
    printf("%s", buff);
}

int EC20_Control::sendText(int index, std::string phoneNum, std::string text)
{
    this->ATcmd_no_response(index, "AT\r\n");
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
    ATcmd_response(index, "AT+CPIN?\r\n");
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
    ATcmd_response(index, "AT+CCID\r\n");
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
    ATcmd_response(index, "AT+CMGF=1\r\n");
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
    ATcmd_response(index, "AT+CSCS=\"GSM\"\r\n");
    std::this_thread::sleep_for(std::chrono::milliseconds(100));

    std::string set_phone = "";
    set_phone.assign("AT+CMGS=\"");
    set_phone.append(phoneNum);
    set_phone.append("\"\r\n");
    ATcmd_no_response(index, set_phone);

    std::string set_text = "";
    // set_text.assign("\"");
    set_text.append(text);
    set_text.append("\x1A");
    ATcmd_response(index, set_text);
}