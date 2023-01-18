#ifndef _UTIL_UART_H_
#define _UTIL_UART_H_


#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif
#endif /* End of #ifdef __cplusplus */

#include <stdio.h>  
#include <string.h>  
#include <stdlib.h> 
#include <fcntl.h>     
#include <errno.h>      
#include <unistd.h>       
#include <termios.h>  
#include <pthread.h>
#include <sys/stat.h> 
#include <sys/types.h>

#define UART_TRUE  		1
#define UART_TIMEOUT 	0
#define UART_FALSE 		-1

typedef enum _UartCheck{
    NO_CHECK=0,
    ODD_CHECK,
    PARITY_CHECK
}UartCheck;

typedef enum _uartSelectType
{
    UART_READ_SELECT=0,
    UART_WRITE_SELECT
}uartSelectType;

int UartOpen(const char* UartName,int baud,int databits,int stopbits,UartCheck mParity);

int UartWrite(int uartFd,const void *buf,int bufLen);

int UartRead(int uartFd,void  *buf,int bufLen);

void UartClose(int *uartFd);

int uart_init(int num, int baud);

#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif /* End of #ifdef __cplusplus */

#endif
