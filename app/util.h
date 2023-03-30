// MIT License
//
// Copyright (c) 2020 Yuming Meng
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.

// @File    :  util.h
// @Version :  1.0
// @Time    :  2020/06/24 10:04:45
// @Author  :  Meng Yuming
// @Contact :  mengyuming@hotmail.com
// @Desc    :  None

#ifndef JT808_UTIL_H_
#define JT808_UTIL_H_

#include <stdint.h>
#include <stddef.h>

#include <vector>
#include <iostream>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netdb.h>
#include <sys/unistd.h>

#define UART1 "/dev/ttysWK1"
#define UART2 "/dev/ttysWK2"
#define UART3 "/dev/ttysWK3"
#define UARTUSB1 "/dev/ttyUSB1"
#define UARTUSB2 "/dev/ttyUSB2"
#define UARTUSB3 "/dev/ttyUSB3"

// namespace libjt808
// {

  // 无符号64位整型转无符号字节数组.
  union U64ToU8Array
  {
    uint64_t u64val;
    uint8_t u8array[8];
  };

  // 无符号32位整型转无符号字节数组.
  union U32ToU8Array
  {
    uint32_t u32val;
    uint8_t u8array[4];
  };

  // 无符号16位整型转无符号字节数组.
  union U16ToU8Array
  {
    uint16_t u16val;
    uint8_t u8array[2];
  };

  // 大小端互换.
  constexpr uint16_t EndianSwap16(uint16_t const &u16val)
  {
    return (((u16val & 0x00FF) << 8) +
            ((u16val & 0xFF00) >> 8));
  }
  // 大小端互换.
  constexpr uint32_t EndianSwap32(uint32_t const &u32val)
  {
    return (((u32val & 0x000000FF) << 24) +
            ((u32val & 0x0000FF00) << 8) +
            ((u32val & 0x00FF0000) >> 8) +
            ((u32val & 0xFF000000) >> 24));
  }

  // // 转义函数.
  // int Escape(std::vector<uint8_t> const &in,
  //            std::vector<uint8_t> *out);

  // // 逆转义函数.
  // int ReverseEscape(std::vector<uint8_t> const &in,
  //                   std::vector<uint8_t> *out);

  // // 异或校验.
  // uint8_t BccCheckSum(const uint8_t *src, const size_t &len);

  // std::string getHostIpByName(const std::string &name);

// } // namespace libjt808

#endif // JT808_UTIL_H_
