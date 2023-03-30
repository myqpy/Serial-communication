#ifndef _DATE_TIME_CTRL_H_
#define _DATE_TIME_CTRL_H_

#include <iostream>
#include <atomic>
#include <functional>
#include <list>
#include <queue>
#include <mutex>
#include <memory>
#include <string>
#include <thread>
#include <chrono>
#include <vector>
#include <numeric>
#include <fstream>

#include <cstdio>
#include <cstdlib>
#include <cmath>

#include <ctime>

// #include <time.h>
// #include <stdio.h>
// #include <stdlib.h>
#include <unistd.h>

// namespace libjt808
// {
  std::string TimestampToString(int64_t const &timestamp);

  std::string StampToStr(int64_t const &timestamp);

  std::string GetTime(void);

  std::string Stamp2StrYear4(time_t timeStamp);

  std::string Stamp2StrYear2(time_t timeStamp);

  std::time_t getNowTimeStamp();

  std::string getHHMMSS();



// }

#endif //_DATE_TIME_H_
