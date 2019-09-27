#pragma once

// Include C++ standard headers
#include <string>


// Include network socket stuff
#define WIN32_LEAN_AND_MEAN

#include <winsock2.h>
#include <ws2tcpip.h>
#include <stdio.h>


// Need to link with Ws2_32.lib
#pragma comment (lib, "Ws2_32.lib")


#define DEFAULT_BUFLEN 512
#define DEFAULT_PORT "27015"


class LemonClient
{
public:
	LemonClient(std::string ip);
	~LemonClient();

	bool Connect();
	void Disconnect();

	bool SendMessage(std::string message);
	std::string ReceivedMessage();

private:
	std::string ip;

	WSADATA wsaData;
	SOCKET ConnectSocket;
	struct addrinfo *result;
	struct addrinfo *ptr;
	struct addrinfo hints;
	char *sendbuf;
	char recvbuf[DEFAULT_BUFLEN];
	int iResult;
	int recvbuflen;

};
