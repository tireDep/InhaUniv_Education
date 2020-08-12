// 서버 코드

#define _WINSOCK_DEPRECATED_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>
#include<string>
#include<WinSock2.h>

#pragma comment(lib, "ws2_32.lib")

#define Buf_Size 1024

void Error(char* msg);
void Log(char* msg);
void ClientCode();

char strServerIP[] = "165.246.192.55";
char strClient[] = "127.0.0.1";

char strPort[] = "12345";
// well known port은 피해서 port 설정

int main()
{
	ClientCode();
	return 0;
}

void Error(char* msg)
{
	Log(msg);
	exit(1);
}

void Log(char* msg)
{
	fputs(msg, stderr);
	fputc('\n', stderr);
}

void ClientCode()
{
	WSADATA wsaData;
	SOCKET serverSocket, clientSocket;
	char msg[Buf_Size];
	int strLength, i;

	SOCKADDR_IN serverAddress, clientAddress;
	int clientAddressSize;

	if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0)
		Error("WSAStartup Error");

	Log("Start...");

	serverSocket = socket(PF_INET, SOCK_STREAM, 0);	// PF_INET == AF_INET(Ipv4), TCP(UDT의 경우 SOCK_DGRAM)
	if (serverSocket == INVALID_SOCKET)
		Error("Socket() Error");

	Log("Socket Ok");

	memset(&serverAddress, 0, sizeof(serverAddress));
	serverAddress.sin_family = AF_INET;
	serverAddress.sin_addr.S_un.S_addr = inet_addr(strServerIP);
	serverAddress.sin_port = htons(atoi(strPort));
	// 실제로 사용할 경우 외부파일에서 읽어오는 방식으로 짜야함
	// 접속이 안될 경우에 사용할 우회경로로 내부적으로 읽어오는 방식 필요

	if (connect(serverSocket, (SOCKADDR*)&serverAddress, sizeof(serverAddress)) == SOCKET_ERROR)
		Error("Connect() Error");
	else
		Log("Connected...");

	while (1)
	{
		fputs("Input Message(Q to quit) : ", stdout);	// 표준 입출력
		fgets(msg, Buf_Size, stdin);

		if (!strcmp(msg, "Q\n") || !strcmp(msg, "q\n"))
			break;

		send(serverSocket, msg, strlen(msg), 0);
		strLength = recv(serverSocket, msg, Buf_Size - 1, 0);	// Null 문자 포함
		msg[strLength] = 0;

		printf("Message from Server : %s\n", msg);
	}

	closesocket(serverSocket);
	WSACleanup();
}
