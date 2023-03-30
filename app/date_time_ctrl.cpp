#include "date_time_ctrl.h"

std::string TimestampToString(int64_t const &timestamp)
{
    struct tm tm_now;
    auto tt = static_cast<time_t>(timestamp);
    localtime_r(&tt, &tm_now);
    char date[16] = {0};
    snprintf(date, sizeof(date) - 1, "%02d%02d%02d%02d%02d%02d",
             (tm_now.tm_year + 1900) / 100, tm_now.tm_mon + 1, tm_now.tm_mday,
             tm_now.tm_hour, tm_now.tm_min, tm_now.tm_sec);
    return std::string(date);
}

std::string StampToStr(int64_t const &timestamp)
{
    struct tm tm_now;
    auto tt = static_cast<time_t>(timestamp);
    localtime_r(&tt, &tm_now);
    char date[16] = {0};
    snprintf(date, sizeof(date) - 1, "%02d%02d%02d%02d%02d%02d",
             (tm_now.tm_year + 1900) % 2000, tm_now.tm_mon + 1, tm_now.tm_mday,
             tm_now.tm_hour, tm_now.tm_min, tm_now.tm_sec);
    return std::string(date);
}

std::string GetTime(void)
{
    auto time_count = std::chrono::duration_cast<std::chrono::seconds>(std::chrono::system_clock::now().time_since_epoch()).count();
    return TimestampToString(time_count);
}

std::string Stamp2StrYear4(time_t timeStamp)
{
    struct tm *timeinfo = nullptr;
    char buffer[80];
    timeinfo = localtime(&timeStamp);
    strftime(buffer, 80, "%Y%m%d%H%M%S", timeinfo);
    // printf("%s\n",buffer);
    return std::string(buffer);
}

std::string Stamp2StrYear2(time_t timeStamp)
{
    struct tm *timeinfo = nullptr;
    char buffer[80];
    timeinfo = localtime(&timeStamp);
    strftime(buffer, 80, "%y%m%d%H%M%S", timeinfo);
    // printf("%s\n",buffer);
    return std::string(buffer);
}

std::time_t getNowTimeStamp()
{
    // std::chrono::time_point<std::chrono::system_clock, std::chrono::milliseconds> tp = std::chrono::time_point_cast<std::chrono::milliseconds>(std::chrono::system_clock::now());
    // auto tmp = std::chrono::duration_cast<std::chrono::milliseconds>(tp.time_since_epoch());
    // std::time_t timestamp = tmp.count();

    std::chrono::system_clock::time_point now = std::chrono::system_clock::now(); // 当前时间time_point格式
    std::time_t timestamp = std::chrono::system_clock::to_time_t(now);            // 转换为 std::time_t 格式

    return timestamp;
}

std::string timestampToHMS(time_t timestamp)
{
    struct tm *timeinfo = nullptr;
    char buffer[80];
    timeinfo = localtime(&timestamp);
    strftime(buffer, 80, "%H%M%S", timeinfo);
    // printf("%s\n",buffer);
    return std::string(buffer);
}

std::string getHHMMSS()
{
    std::chrono::system_clock::time_point now = std::chrono::system_clock::now(); // 当前时间time_point格式
    std::time_t timestamp = std::chrono::system_clock::to_time_t(now);            // 转换为 std::time_t 格式

    struct tm *timeinfo = nullptr;
    char buffer[80];
    timeinfo = localtime(&timestamp);
    strftime(buffer, 80, "%H%M%S", timeinfo);
    // printf("%s\n",buffer);
    return std::string(buffer);
}
