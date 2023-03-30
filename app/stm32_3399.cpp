#include "stm32_3399.h"
#include "utilUart.h"
#include "util.h"
#include "date_time_ctrl.h"

// #define BUFFER_SIZE_RECEIVE 1024
// unsigned char BufferReceive[BUFFER_SIZE_RECEIVE] = {0};

// int stm32_value::get(struct stm32_to_rk3399 &stm32_to_rk3399_)
// {
//     stm32_to_rk3399_.dataHeader = 0x5AA50001;
//     stm32_to_rk3399_.driversLicenseNum = "410105199607150035";   // 01H 当前驾驶员信息*
//     return 0;
// }

// int stm32_value::update(struct stm32_to_rk3399 &stm32_to_rk3399_)
// {
//     stm32_to_rk3399_.update.dataHeader = stm32_to_rk3399_.dataHeader;
//     std::cout << "dataHeader == " << std::hex << stm32_to_rk3399_.update.dataHeader << std::endl;
// }

int rk_value::set_time(struct car_time_str *car_time, const char *UART_NAME)
{
    time_t now = time(0);
    tm *ltm = localtime(&now);

    // car_time_str car_time;

    car_time->op = 0xfe;
    car_time->w_year = ltm->tm_year + 1900;
    car_time->w_month = (ltm->tm_mon + 1);
    car_time->w_date = ltm->tm_mday;
    car_time->hour = ltm->tm_hour;
    car_time->min = ltm->tm_min;
    car_time->sec = ltm->tm_sec;

    car_time->w_year = EndianSwap16(car_time->w_year);
    auto index = UartOpen(UART_NAME, 115200, 8, 1, NO_CHECK);
    UartWrite(index, car_time, sizeof(car_time));

    return index;
}

int stm32_value::get(struct stm32_to_rk3399 *stm32_to_rk3399_, struct car_info_str &car_info, int index, unsigned char *buff)
{
    // char buff[UART_GPS_BUF_SIZE];
    // int index = -1;

    // int open_count = 0;
    // while (1)
    // {
    //     index = UartOpen(UART1, 115200, 8, 1, NO_CHECK);
    //     open_count++;

    //     if (index <= 0)
    //     {
    //         //std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    //         if (open_count >= 3)
    //         {
    //             system("sudo reboot");
    //         }
    //         continue;
    //     }
    //     else
    //     {
    //         open_count = 0;
    //         break;
    //     }
    // }

    auto size = UartRead(index, buff, 512);
    for (int i = 0; i < size; ++i)
    {
        printf("%02x ", (int)buff[i]);
    }
    std::cout << std::endl;

    std::cout << "size: " << size << std::endl;
    memcpy(&car_info, buff, size);
    memcpy(car_info.driver_num, "41010519960715005", strlen("41010519960715005"));
    // printf("car_info.mileage:%08x\n", car_info.mileage);
    // printf("car_info.velocity:%08x\n", car_info.velocity);
    // car_info.mileage = EndianSwap32(car_info.mileage);
    // car_info.velocity = EndianSwap32(car_info.velocity);
    // printf("op:%02x\n", (car_info.op));
    // printf("car_info.mileage:%08x\n", car_info.mileage);
    // printf("car_info.velocity:%08x\n", car_info.velocity);
    // printf("car_info.driver_num:%s\n", car_info.driver_num);
    // printf("IO:%02x\n", (car_info.IO));

    // int pos = 0;
    // car_info.op = buff[pos];
    // // std::cout << "op:" << op << std::endl;
    // printf("op:%x\n", car_info.op);
    // pos++;

    // memcpy(u32converter.u8array, (buff + pos), 4);
    // // unsigned int mileage = EndianSwap32(u32converter.u32val);
    // car_info.mileage = u32converter.u32val;
    // pos += 4;
    // std::cout << "mileage:" << car_info.mileage << std::endl;

    // memcpy(u32converter.u8array, (buff + pos), 4);
    // // unsigned int speed = EndianSwap32(u32converter.u32val);
    // car_info.velocity = u32converter.u32val;
    // pos += 4;
    // std::cout << "velocity:" << car_info.velocity << std::endl;

    // memcpy(car_info.driver_num, (buff + pos), 18);
    // // std::cout << "driversLicenseNum:" << driversLicenseNum << std::endl;
    // printf("driver_num:%s\n", car_info.driver_num);
    // pos += 18;

    // car_info.IO = buff[pos];
    // // std::cout << "IO:" << IO << std::endl;
    // printf("IO:%x\n", car_info.IO);

    memset(buff, 0, 512);

    // stm32_to_rk3399_->dataHeader = 0x5AA50001;

    // stm32_to_rk3399_->driversLicenseNum = "410105199607150035";   // 01H 当前驾驶员信息*
    // stm32_to_rk3399_->initTime = "230215";                        // 02H 初次安装时间
    // stm32_to_rk3399_->initDistance = 123;                         // 03H 初始里程
    // stm32_to_rk3399_->tripDistance = 455;                         // 03H 累计行驶里程
    // stm32_to_rk3399_->impulseIndexHigh = 0x01;                    // 04H 脉冲系数高字节
    // stm32_to_rk3399_->impulseIndexLow = 0x00;                     // 04H 脉冲系数低字节
    // stm32_to_rk3399_->workingConditionSigNum = 0x05;              // 06H 状态信号字节个数
    // stm32_to_rk3399_->workingConditionIO_get.bit.D7signal = 0x01; // 06H D7 制动
    // stm32_to_rk3399_->workingConditionIO_get.bit.D6signal = 0x01; // 06H D6 左转
    // stm32_to_rk3399_->workingConditionIO_get.bit.D5signal = 0x01; // 06H D5 右转
    // stm32_to_rk3399_->workingConditionIO_get.bit.D4signal = 0x01; // 06H D4 远光
    // stm32_to_rk3399_->workingConditionIO_get.bit.D3signal = 0x01; // 06H D3 近光
    // stm32_to_rk3399_->workingConditionIO_get.bit.D2signal = 0x00; // 06H D2 xx
    // stm32_to_rk3399_->workingConditionIO_get.bit.D1signal = 0x00; // 06H D1 xx
    // stm32_to_rk3399_->workingConditionIO_get.bit.D0signal = 0x00; // 06H D0 xx
    // stm32_to_rk3399_->avgSpeed = 50;                              // 08H 平均速度

    // stm32_to_rk3399_->loginORlogout = 0x1;  // 12H 单位驾驶人身份记录
    // stm32_to_rk3399_->chargingStatus = 0x1; // 13H 外部供电记录
    // stm32_to_rk3399_->eventType = 0x55;     // 14H 参数修改记录
    // stm32_to_rk3399_->BccCheckValue = 0xF2;

    return 0;
}

int stm32_value::update(struct stm32_to_rk3399 *stm32_to_rk3399_, struct car_info_str &car_info)
{
    stm32_to_rk3399_->dataHeader = car_info.op;
    std::cout << "dataHeader == " << std::hex << stm32_to_rk3399_->dataHeader << std::endl;

    if (stm32_to_rk3399_->dataHeader == 0xfe)
    {
        stm32_to_rk3399_->driversLicenseNum.clear();
        for (int i = 0; i < sizeof(car_info.driver_num); i++)
        {
            stm32_to_rk3399_->driversLicenseNum.push_back(car_info.driver_num[i]);
        }

        if (stm32_to_rk3399_->driversLicenseNum.size() == 18)
        {

        }
        else if (stm32_to_rk3399_->driversLicenseNum.size() == 15)
        {
            stm32_to_rk3399_->driversLicenseNum += "000";
        }
        else
        {
            std::cout << "身份证位数 = " << std::dec << stm32_to_rk3399_->driversLicenseNum.size() << " 错误 (应为15位或18位)" << std::endl;
            stm32_to_rk3399_->driversLicenseNum = "000000000000000000";
        }
        // stm32_to_rk3399_->update.initTime = stm32_to_rk3399_->initTime;                                                          // 02H 初次安装时间
        // stm32_to_rk3399_->update.initDistance = stm32_to_rk3399_->initDistance;                                                  // 03H 初始里程
        stm32_to_rk3399_->tripDistance = car_info.mileage; // 03H 累计行驶里程
        // stm32_to_rk3399_->update.impulseIndexHigh = stm32_to_rk3399_->impulseIndexHigh;                                          // 04H 脉冲系数高字节
        // stm32_to_rk3399_->update.impulseIndexLow = stm32_to_rk3399_->impulseIndexLow;                                            // 04H 脉冲系数低字节
        // stm32_to_rk3399_->workingConditionSigNum = stm32_to_rk3399_->workingConditionSigNum;                              // 06H 状态信号字节个数
        // stm32_to_rk3399_->workingConditionIO_update.bit.D7signal = ; // 06H D7 制动
        // stm32_to_rk3399_->workingConditionIO_update.bit.D6signal = ;  // 06H D6 左转
        // stm32_to_rk3399_->workingConditionIO_update.bit.D5signal = ;  // 06H D5 右转
        // stm32_to_rk3399_->workingConditionIO_update.bit.D4signal = ;  // 06H D4 远光
        // stm32_to_rk3399_->workingConditionIO_update.bit.D3signal = ;  // 06H D3 近光
        // stm32_to_rk3399_->workingConditionIO_update.bit.D2signal = ;  // 06H D2 xx
        // stm32_to_rk3399_->workingConditionIO_update.bit.D1signal = ;  // 06H D1 xx
        // stm32_to_rk3399_->workingConditionIO_update.bit.D0signal = ;  // 06H D0 xx
        stm32_to_rk3399_->IO.value = car_info.IO;
        stm32_to_rk3399_->avgSpeed = car_info.velocity; // 08H 平均速度
        // stm32_to_rk3399_->update.loginORlogout = stm32_to_rk3399_->loginORlogout;                                                // 12H 单位驾驶人身份记录
        // stm32_to_rk3399_->update.chargingStatus = stm32_to_rk3399_->chargingStatus;                                              // 13H 外部供电记录
        // stm32_to_rk3399_->update.eventType = stm32_to_rk3399_->eventType;                                                        // 14H 参数修改记录
        // stm32_to_rk3399_->update.BccCheckValue = stm32_to_rk3399_->BccCheckValue;

        std::cout << "driversLicenseNum == " << stm32_to_rk3399_->driversLicenseNum << std::endl;
        // std::cout << "initTime == " << stm32_to_rk3399_->update.initTime << std::endl;
        // std::cout << "initDistance == " << std::dec << stm32_to_rk3399_->update.initDistance << std::endl;
        std::cout << "tripDistance == " << stm32_to_rk3399_->tripDistance << std::endl;
        // std::cout << "impulseIndexHigh == " << (int)stm32_to_rk3399_->update.impulseIndexHigh << std::endl;
        // std::cout << "impulseIndexLow == " << (int)stm32_to_rk3399_->update.impulseIndexLow << std::endl;
        // std::cout << "workingConditionSigNum == " << (int)stm32_to_rk3399_->update.workingConditionSigNum << std::endl;
        std::cout << "D7signal == " << (int)stm32_to_rk3399_->IO.bit.D7signal << std::endl;
        std::cout << "D6signal == " << (int)stm32_to_rk3399_->IO.bit.D6signal << std::endl;
        std::cout << "D5signal == " << (int)stm32_to_rk3399_->IO.bit.D5signal << std::endl;
        std::cout << "D4signal == " << (int)stm32_to_rk3399_->IO.bit.D4signal << std::endl;
        std::cout << "D3signal == " << (int)stm32_to_rk3399_->IO.bit.D3signal << std::endl;
        std::cout << "D2signal == " << (int)stm32_to_rk3399_->IO.bit.D2signal << std::endl;
        std::cout << "D1signal == " << (int)stm32_to_rk3399_->IO.bit.D1signal << std::endl;
        std::cout << "D0signal == " << (int)stm32_to_rk3399_->IO.bit.D0signal << std::endl;
        std::cout << "avgSpeed == " << stm32_to_rk3399_->avgSpeed << std::endl;

        // std::cout << "loginORlogout == " << (int)stm32_to_rk3399_->update.loginORlogout << std::endl;
        // std::cout << "chargingStatus == " << (int)stm32_to_rk3399_->update.chargingStatus << std::endl;
        // std::cout << "eventType == " << std::hex << (int)stm32_to_rk3399_->update.eventType << std::endl;
        // std::cout << "BccCheckValue == " << (int)stm32_to_rk3399_->update.BccCheckValue << std::endl;
    }

    else
    {
        std::cout << "dataHeader == " << std::hex << stm32_to_rk3399_->dataHeader << "!= 0xfe" << std::endl;
    }

    return 0;
}

// int handle_stm_to_rk(struct stm32_to_rk3399 *stm_to_rk)
// {
//     uint16_t pos;
//     unsigned short msg_len;
//     unsigned int p_id;
//     unsigned char cnt;
//     // union U32ToU8Array u32converter;
//     int isFind = 0, i;
//     unsigned len;

//     if (stm_to_rk == NULL)
//     {
//         return -1;
//     }
//     pos = 0;
//     // if (para->parse.msg_head.msgbody_attr.bit.packet == 1)
//     // {
//     //         pos = MSGBODY_PACKET_POS;
//     // }
//     // msg_len = para->parse.msg_head.msgbody_attr.bit.msglen;
//     // if (msg_len < 1)
//     // {
//     //         return -1;
//     // }
//     // 解析设置的参数总个数.
//     cnt = BufferReceive[pos];
//     pos++;

//     if (cnt <= 0)
//     {
//         return -1;
//     }

//     // for (i = 0; i < cnt; ++i)
//     // {
//     //         // 查找参数项的参数ID
//     //         memcpy(u32converter.u8array, (BufferReceive + pos), 4);
//     //         p_id = EndianSwap32(u32converter.u32val);
//     //         pos += 4;
//     //         // 从已支持的参数项数组中查找是否有当前参数ID
//     //         isFind = findParameterIDFromArray(p_id);
//     //         len = BufferReceive[pos];
//     //         pos++;
//     //         if (isFind == 1)
//     //         {
//     //                 jt808ParameterSettingParse(p_id, (BufferReceive + pos), len, para);
//     //         }
//     //         pos += len;
//     // }

//     //	boot_loader_flag();

//     return 0;
// }