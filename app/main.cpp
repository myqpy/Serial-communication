#include <iostream>
#include "stm32_3399.h"
#include "selfcheck.h"
#include "switch4G.h"
#include <thread>
#include "utilUart.h"
#include "util.h"

int main(void)
{
    /*调用自检接口*/
    // selfcheck selfCheck;

    // while (true)
    // {
    //     selfCheck.first_self_check();
    //     // selfCheck.regular_self_check();
    //     std::cout << std::endl;
    //     std::cout << std::endl;
    //     std::this_thread::sleep_for(std::chrono::milliseconds(10000));
    // }

    /*4G开关指�?*/
    // switch4G switch4G_;
    // switch4G_.open4G();
    // switch4G_.close4G();

    // unsigned char buff[512];

    // rk_value rk_val;

    // car_time_str *car_time = new car_time_str;
    // auto index = rk_val.set_time(car_time, UART1);
    // delete car_time;

    // U32ToU8Array u32converter;
    // car_info_str car_info;

    // stm32_value stm32_value;
    // /*指针使用方法*/
    // stm32_to_rk3399 *stm32_to_rk3399_ = new stm32_to_rk3399;
    // while (1)
    // {
    //     stm32_value.get(stm32_to_rk3399_, car_info, index, buff);
    //     stm32_value.update(stm32_to_rk3399_, car_info);
    // }

    // delete stm32_to_rk3399_;

    /*引用使用方法*/
    // stm32_to_rk3399 stm32_to_rk3399_;
    // stm32_value.get(stm32_to_rk3399_);
    // stm32_value.update(stm32_to_rk3399_);

    // /*4G模块串口测试*/
    char buff[512];
    auto index = UartOpen(UARTUSB3, 115200, 8, 1, NO_CHECK);

    // std::cout << std::endl;
    std::string str_buf = "";

    // UartWrite(index, "AT\r\n", sizeof("AT\r\n"));
    // while (1)
    // {

    //     auto size = UartRead(index, buff, sizeof(buff));
    //     str_buf.assign(buff, buff + size);
    //     printf("%s", buff);
    //     auto inx_OK = str_buf.find("OK");
    //     if (inx_OK != std::string::npos)
    //     {
    //         std::this_thread::sleep_for(std::chrono::milliseconds(100));
    //         break;
    //     }
    // }

    // UartWrite(index, "AT+CPIN?\r\n", sizeof("AT+CPIN?\r\n"));
    // while (1)
    // {

    //     auto size = UartRead(index, buff, sizeof(buff));
    //     str_buf.assign(buff, buff + size);
    //     printf("%s", buff);
    //     auto inx_OK = str_buf.find("OK");
    //     if (inx_OK != std::string::npos)
    //     {
    //         std::this_thread::sleep_for(std::chrono::milliseconds(100));
    //         break;
    //     }
    // }

    // UartWrite(index, "AT+CCID\r\n", sizeof("AT+CCID\r\n"));
    // while (1)
    // {

    //     auto size = UartRead(index, buff, sizeof(buff));
    //     str_buf.assign(buff, buff + size);
    //     printf("%s", buff);
    //     auto inx_OK = str_buf.find("OK");
    //     if (inx_OK != std::string::npos)
    //     {
    //         std::this_thread::sleep_for(std::chrono::milliseconds(100));
    //         break;
    //     }
    // }

    // UartWrite(index, "AT+CMGF=1\r\n", sizeof("AT+CMGF=1\r\n"));
    // while (1)
    // {

    //     auto size = UartRead(index, buff, sizeof(buff));
    //     str_buf.assign(buff, buff + size);
    //     printf("%s", buff);
    //     auto inx_OK = str_buf.find("OK");
    //     if (inx_OK != std::string::npos)
    //     {
    //         std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    //         break;
    //     }
    // }

    // UartWrite(index, "AT+CSCS=\"GSM\"\r\n", sizeof("AT+CSCS=\"GSM\"\r\n"));
    // while (1)
    // {

    //     auto size = UartRead(index, buff, sizeof(buff));
    //     str_buf.assign(buff, buff + size);
    //     printf("%s", buff);
    //     auto inx_OK = str_buf.find("OK");
    //     if (inx_OK != std::string::npos)
    //     {
    //         std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    //         break;
    //     }
    // }
    
    // UartWrite(index, "AT+CMGS=\"15637142115\"\r\n", sizeof("AT+CMGS=\"15637142115\"\r\n"));
    // while (1)
    // {
    //     std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    //     auto size = UartRead(index, buff, sizeof(buff));
    //     str_buf.assign(buff, buff + size);
    //     printf("%s", buff);
    //     break;
    // }

    EC20_Control AT;
    std::string phone_num = "15637142115";
    std::string text = "test test test";
    AT.sendText(index, phone_num, text);
    // AT.ATcmd_response(index, "AT\r\n");
    // std::this_thread::sleep_for(std::chrono::milliseconds(100));
    // AT.ATcmd_response(index, "AT+CPIN?\r\n");
    // std::this_thread::sleep_for(std::chrono::milliseconds(100));
    // AT.ATcmd_response(index, "AT+CCID\r\n");
    // std::this_thread::sleep_for(std::chrono::milliseconds(100));
    // AT.ATcmd_response(index, "AT+CMGF=1\r\n");
    // std::this_thread::sleep_for(std::chrono::milliseconds(100));
    // AT.ATcmd_response(index, "AT+CSCS=\"GSM\"\r\n");
    // std::this_thread::sleep_for(std::chrono::milliseconds(100));

    // AT.ATcmd_no_response(index, "AT+CMGS=\"15637142115\"\r\n");

    // AT.ATcmd(index, "Hello world\x1A");
    // UartWrite(index, "Hello world\x1A", sizeof("Hello world\x1A"));
    // std::this_thread::sleep_for(std::chrono::milliseconds(1000));

    return 0;
}
