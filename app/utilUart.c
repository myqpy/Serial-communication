#ifdef __cplusplus
#if __cplusplus
extern "C"
{
#endif
#endif /* End of #ifdef __cplusplus */

#include "utilUart.h"

	void set_speed(int fd, int speed, struct termios *Opt)
	{
		int i;
		int baud = -1;
		int speed_arr[] = {B2000000, B1500000, B921600, B115200, B57600, B38400, B19200, B9600, B4800, B2400, B1200, B300};
		int name_arr[] = {2000000, 1500000, 921600, 115200, 57600, 38400, 19200, 9600, 4800, 2400, 1200, 300};
		for (i = 0; i < sizeof(speed_arr) / sizeof(int); i++)
		{
			if (speed == name_arr[i])
			{
				baud = speed_arr[i];
				break;
			}
		}
		if (baud < 0)
		{
			printf("not support speed[%d]\n", speed);
			return;
		}
		cfsetispeed(Opt, baud);
		cfsetospeed(Opt, baud);
	}

	int uartselect(int sockfd, int usec, uartSelectType mtype)
	{
		struct timeval tv;
		fd_set readfds, writefds, exceptfds;
		int receive = 0;
		FD_ZERO(&readfds);
		FD_ZERO(&writefds);
		FD_ZERO(&exceptfds);
		tv.tv_sec = usec / 1000000;
		tv.tv_usec = usec % 1000000;
		FD_SET(sockfd, &exceptfds);
		if (mtype == UART_READ_SELECT)
		{
			FD_SET(sockfd, &readfds);
			receive = select(sockfd + 1, &readfds, NULL, &exceptfds, &tv);
		}
		else
		{
			FD_SET(sockfd, &writefds);
			receive = select(sockfd + 1, NULL, &writefds, &exceptfds, &tv);
		}
		if (receive < 0)
		{
			perror("select error:");
			return -1;
		}
		else if (receive == 0)
		{
			return 0;
		}
		else
		{
			if (mtype == UART_READ_SELECT)
			{
				if (FD_ISSET(sockfd, &readfds) > 0)
					return -1;
			}
			else
			{
				if (FD_ISSET(sockfd, &writefds) > 0)
					return -1;
			}
			return -1;
		}
		return 1;
	}

	int UartInit(int fd, int baud, int databits, int stopbits, UartCheck mParity)
	{
		struct termios Opt;
		tcgetattr(fd, &Opt);
		tcflush(fd, TCIOFLUSH);
		set_speed(fd, baud, &Opt);
		switch (databits)
		{
		case 5:
			Opt.c_cflag |= CS5;
			break;
		case 6:
			Opt.c_cflag |= CS6;
			break;
		case 7:
			Opt.c_cflag |= CS7;
			break;
		case 8:
			Opt.c_cflag |= CS8;
			break;
		default:
			Opt.c_cflag |= CS8;
			fprintf(stderr, "Unsupported data size/n");
			break;
		}

		switch (stopbits)
		{
		case 1:
			Opt.c_cflag &= ~CSTOPB;
			break;
		case 2:
			Opt.c_cflag |= CSTOPB;
			break;
		default:
			fprintf(stderr, "Unsupported stop bits/n");
			return UART_FALSE;
		}

		switch (mParity)
		{
		case NO_CHECK:
			Opt.c_cflag &= ~PARENB; /* Clear parity enable */
			Opt.c_iflag &= ~INPCK;	/* Enable parity checking */
			break;
		case ODD_CHECK:
			Opt.c_cflag |= (PARODD | PARENB); /* 锟斤拷锟斤拷为锟斤拷效锟斤拷*/
			Opt.c_iflag |= INPCK;			  /* Disnable parity checking */
			break;
		case PARITY_CHECK:
			Opt.c_cflag |= PARENB;	/* Enable parity */
			Opt.c_cflag &= ~PARODD; /* 转锟斤拷为偶效锟斤拷*/
			Opt.c_iflag |= INPCK;	/* Disnable parity checking */
			break;
		default:
			fprintf(stderr, "Unsupported parity/n");
			Opt.c_cflag &= ~PARENB;
			Opt.c_cflag &= ~CSTOPB;
			break;
		}

		Opt.c_cc[VTIME] = 10;		   // 10(100ms)timeout
		Opt.c_cc[VMIN] = 1;			   /*read when >=1 Bytes */
		Opt.c_cflag |= CLOCAL | CREAD; // local connect enable read
		Opt.c_oflag &= ~OPOST;
		Opt.c_lflag &= ~(ICANON | ISIG | ECHO | IEXTEN);
		Opt.c_iflag &= ~(INPCK | BRKINT | ICRNL | ISTRIP | IXON);

		if (tcsetattr(fd, TCSANOW, &Opt) != 0) //装锟截筹拷始锟斤拷锟斤拷锟斤拷
		{
			printf("SetupSerial!\n");
			close(fd);
			return UART_FALSE;
		}
		return fd;
	}

	int UartWrite(int uartFd, const void *buf, int bufLen)
	{
		if (uartFd < 0)
		{
			return UART_FALSE;
		}
		if (write(uartFd, buf, bufLen) != bufLen)
		{
			printf("write uart err\n");
			return UART_FALSE;
		};
		return UART_TRUE;
	}

	int UartRead(int uartFd, void *buff, int bufLen)
	{
		int nRead = 0, ret = 0;
		if (uartFd < 0)
			return -1;
#if 0
	ret = uartselect(uartFd,1000*1000,UART_READ_SELECT);
	if(ret<0){
		usleep(1000);
		return UART_FALSE;
	}else if(ret==0){
		printf("uartselect UART_TIMEOUT\n");
		return UART_TIMEOUT;
	}
#endif
		bzero(buff, bufLen);
		nRead = read(uartFd, buff, bufLen);
		tcflush(uartFd, TCIFLUSH);
		return nRead;
	}

	int UartOpen(const char *UartName, int baud, int databits, int stopbits, UartCheck mParity)
	{
		// int comFd=open(UartName, O_RDWR|O_NONBLOCK);
		int fd = 0;
		if (UartName == NULL)
			return -1;
		fd = open(UartName, O_RDWR);									//阻塞模式读写
		// fd = open(UartName, O_RDWR | O_NOCTTY | O_NDELAY | O_NONBLOCK); //非阻塞模式读写
		if (fd <= 0)
		{
			printf("open %s err\n", UartName);
			return UART_FALSE;
		}
		if (UartInit(fd, baud, databits, stopbits, mParity) <= 0)
		{
			return UART_FALSE;
		}
		return fd;
	}

	void UartClose(int *uartFd)
	{
		if (*uartFd > 0)
		{
			close(*uartFd);
			*uartFd = 0;
		}
	}

	int uart_init(int num, int baud)
	{
		int fd;
		char port[20];
		struct termios Opt;
		int uartbiit[] = {B921600, B460800, B115200, B57600, B38400, B9600, B19200, B4800, B2400, B1200};

		sprintf(port, "/dev/ttyS%d", num);
		printf("port %s \n", port);
		fd = open(port, O_RDWR);
		if (fd < 0)
		{
			return -1;
		}

		tcgetattr(fd, &Opt);
		tcflush(fd, TCIFLUSH);
		cfsetispeed(&Opt, uartbiit[baud]);
		cfsetospeed(&Opt, uartbiit[baud]);

		Opt.c_cflag |= CS8;
		Opt.c_cflag &= ~PARENB;
		Opt.c_oflag &= ~(OPOST);
		Opt.c_cflag &= ~CSTOPB;
		Opt.c_lflag &= ~(ICANON | ISIG | ECHO | IEXTEN);
		Opt.c_iflag &= ~(INPCK | BRKINT | ICRNL | ISTRIP | IXON);

		Opt.c_cc[VMIN] = 0;
		Opt.c_cc[VTIME] = 0;

		if (tcsetattr(fd, TCSANOW, &Opt) != 0)
		{
			perror("SetupSerial!\n");
			close(fd);
			return -2;
		}

		return (fd);
	}

#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif /* End of #ifdef __cplusplus */
