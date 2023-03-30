#include <iostream>

class EC20_Control
{
public:
    int open4G(void);
    int close4G(void);
    int sendText(int index, std::string phoneNum, std::string text);
    int ATcmd_response(int index, std::string cmd);
    int ATcmd_no_response(int index, std::string cmd);
};