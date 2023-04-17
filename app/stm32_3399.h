#include <iostream>


#pragma pack(push)
#pragma pack(1) // 结构体1字节对齐
struct car_time_str
{
    unsigned char op;
    unsigned char hour;
    unsigned char min;
    unsigned char sec;
    // 公历日月年周
    unsigned short int w_year;
    unsigned char w_month;
    unsigned char w_date;
};
#pragma pack() // 恢复默认字节对齐

#pragma pack(push)
#pragma pack(1) // 结构体1字节对齐
struct car_info_str
{
    unsigned char op;
    unsigned int mileage;
    unsigned int velocity;
    unsigned char driver_num[18]; // 机动车驾驶证号码
    unsigned char IO;
};
#pragma pack() // 恢复默认字节对齐

#pragma pack(push)
#pragma pack(1) // 结构体1字节对齐
struct struct_rk_info
{
	unsigned char 	op;
	unsigned char 	EC20Status;
	unsigned int	EC20SignalStrength;
	unsigned char 	BDStatus;
	unsigned char 	SDStatus;
	unsigned char 	cameraStatus;
        unsigned char 	velocityStatus;
};
#pragma pack() // 恢复默认字节对齐


class stm32_value
{
public:
        int get(struct stm32_to_rk3399 *stm32_to_rk3399_, struct car_info_str &car_info, int index, unsigned char* buff);
        int update(struct stm32_to_rk3399 *stm32_to_rk3399_, struct car_info_str &car_info);
        // int get(struct stm32_to_rk3399 &stm32_to_rk3399);
        // int update(struct stm32_to_rk3399 &stm32_to_rk3399);
};

class rk_value
{
public:
        int set_time(struct car_time_str *car_time, const char* UART_NAME);
        // int get(struct stm32_to_rk3399 *stm32_to_rk3399);
        // int update(struct stm32_to_rk3399 *stm32_to_rk3399);
        // int get(struct stm32_to_rk3399 &stm32_to_rk3399);
        // int update(struct stm32_to_rk3399 &stm32_to_rk3399);
};


// enum stm32SupportedCommands
// {
//         kdriversLicenseNum = 0x0001, // 01H 当前驾驶员信息
//         kinitTime,                   // 02H 初次安装时间
//         ktripDistance,               // 03H 累计行驶里程
//         kinitDistance,               // 03H 初始里程
//         kimpulseIndexHigh,           // 04H 脉冲系数高字节
//         kimpulseIndexLow,            // 04H 脉冲系数低字节
//         kimpulseIndex,               // 04H 脉冲系数
//         kvehicleVin,                 // 05H 车辆识别代号
//         kvehiclePlateNum,            // 05H 机动车号牌号码
//         kvehiclePlateClass,          // 05H 机动车号牌分类
//         kworkingConditionSigNum,     // 06H 状态信号字节个数
//         kworkingConditionIO,         //
//         kavgSpeed,                   // 08H 平均速度
//         kloginORlogout,              // 12H 单位驾驶人身份记录
//         kchargingStatus,             // 13H 外部供电记录
//         keventType                   // 14H 参数修改记录
// };

union UN_IO
{
        struct
        {
                unsigned char D7signal : 1; // 06H D7 制动
                unsigned char D6signal : 1; // 06H D6 左转
                unsigned char D5signal : 1; // 06H D5 右转
                unsigned char D4signal : 1; // 06H D4 远光
                unsigned char D3signal : 1; // 06H D3 近光
                unsigned char D2signal : 1; // 06H D2 xx
                unsigned char D1signal : 1; // 06H D1 xx
                unsigned char D0signal : 1; // 06H D0 xx
        } bit;
        uint8_t value;
};

struct stm32_to_rk3399
{
        unsigned long dataHeader;

        std::string driversLicenseNum; // 01H 当前驾驶员信息*
        // std::string instantTime;       // 02H 实时时间
        std::string initTime;      // 02H 初次安装时间
        unsigned int tripDistance; // 03H 累计行驶里程
        unsigned int initDistance; // 03H 初始里程
        // std::string impulseIndex;            //04H 脉冲系数
        unsigned char impulseIndexHigh; // 04H 脉冲系数高字节
        unsigned char impulseIndexLow;  // 04H 脉冲系数低字节
        unsigned short impulseIndex;    // 04H 脉冲系数
        // std::string vehicleInfo;             //05H 采集车辆信息
        std::string vehicleVin;        // 05H 车辆识别代号
        std::string vehiclePlateNum;   // 05H 机动车号牌号码
        std::string vehiclePlateClass; // 05H 机动车号牌分类
        // std::string workingConditionInitInfo;   //06H 采集记录仪状态信号配置信息

        unsigned char workingConditionSigNum; // 06H 状态信号字节个数
        UN_IO IO;
        unsigned int avgSpeed; // 08H 平均速度
        // std::string GGA;                      // 09H 位置信息记录GGA高度信息
        unsigned char loginORlogout;  // 12H 单位驾驶人身份记录
        unsigned char chargingStatus; // 13H 外部供电记录
        unsigned char eventType;      // 14H 参数修改记录

        // unsigned char isBrake;

        unsigned char BccCheckValue;

        // struct
        // {
        //         unsigned int dataHeader;

        //         std::string driversLicenseNum;        // 01H 当前驾驶员信息*
        //         std::string initTime;                 // 02H 初次安装时间
        //         unsigned int initDistance;            // 03H 初始里程
        //         unsigned int tripDistance;            // 03H 累计行驶里程
        //         unsigned char impulseIndexHigh;       // 04H 脉冲系数高字节
        //         unsigned char impulseIndexLow;        // 04H 脉冲系数低字节
        //         unsigned char workingConditionSigNum; // 06H 状态信号字节个数
        //         // unsigned char D7signal;               // 06H D7 制动
        //         // unsigned char D6signal;               // 06H D6 左转
        //         // unsigned char D5signal;               // 06H D5 右转
        //         // unsigned char D4signal;               // 06H D4 远光
        //         // unsigned char D3signal;               // 06H D3 近光
        //         // unsigned char D2signal;               // 06H D2 xx
        //         // unsigned char D1signal;               // 06H D1 xx
        //         // unsigned char D0signal;               // 06H D0 xx
        //         workingConditionIO workingConditionIO_update;
        //         unsigned int avgSpeed;        // 08H 平均速度
        //         // std::string GGA;              // 09H 位置信息记录GGA高度信息
        //         unsigned char loginORlogout;  // 12H 单位驾驶人身份记录
        //         unsigned char chargingStatus; // 13H 外部供电记录
        //         unsigned char eventType;      // 14H 参数修改记录

        //         unsigned char BccCheckValue;
        // } update;
};



int handle_stm_to_rk(struct stm32_to_rk3399 *stm_to_rk);