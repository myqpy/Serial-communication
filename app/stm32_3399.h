#include <iostream>

class stm32_value
{
public:
        int get(struct stm32_to_rk3399 *stm32_to_rk3399);
        int update(struct stm32_to_rk3399 *stm32_to_rk3399);
        // int get(struct stm32_to_rk3399 &stm32_to_rk3399);
        // int update(struct stm32_to_rk3399 &stm32_to_rk3399);
};

union workingConditionIO
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
        workingConditionIO workingConditionIO_get;
        unsigned int avgSpeed; // 08H 平均速度
        // std::string GGA;                      // 09H 位置信息记录GGA高度信息
        unsigned char loginORlogout;  // 12H 单位驾驶人身份记录
        unsigned char chargingStatus; // 13H 外部供电记录
        unsigned char eventType;      // 14H 参数修改记录

        // unsigned char isBrake;

        unsigned char BccCheckValue;

        struct
        {
                unsigned int dataHeader;

                std::string driversLicenseNum;        // 01H 当前驾驶员信息*
                std::string initTime;                 // 02H 初次安装时间
                unsigned int initDistance;            // 03H 初始里程
                unsigned int tripDistance;            // 03H 累计行驶里程
                unsigned char impulseIndexHigh;       // 04H 脉冲系数高字节
                unsigned char impulseIndexLow;        // 04H 脉冲系数低字节
                unsigned char workingConditionSigNum; // 06H 状态信号字节个数
                // unsigned char D7signal;               // 06H D7 制动
                // unsigned char D6signal;               // 06H D6 左转
                // unsigned char D5signal;               // 06H D5 右转
                // unsigned char D4signal;               // 06H D4 远光
                // unsigned char D3signal;               // 06H D3 近光
                // unsigned char D2signal;               // 06H D2 xx
                // unsigned char D1signal;               // 06H D1 xx
                // unsigned char D0signal;               // 06H D0 xx
                workingConditionIO workingConditionIO_update;
                unsigned int avgSpeed;        // 08H 平均速度
                std::string GGA;              // 09H 位置信息记录GGA高度信息
                unsigned char loginORlogout;  // 12H 单位驾驶人身份记录
                unsigned char chargingStatus; // 13H 外部供电记录
                unsigned char eventType;      // 14H 参数修改记录

                unsigned char BccCheckValue;
        } update;
};
