// 서버 코드

#include<stdio.h>
#include<stdlib.h>
#include<string>
#include<WinSock2.h>
#include<vector>

using std::vector;
using std::iterator;

#pragma comment(lib, "ws2_32.lib");

#define Buf_Size 1024

void Error(char* msg);
void Log(char* msg);
void ServerCode();

char strServerIP[] = "165.246.192.55"; 
char strClient[] = "127.0.0.1";

char strPort[] = "12345";
// well known port은 피해서 port 설정

int main()
{
	ServerCode();
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

void ServerCode()
{
	WSADATA wsaData;
	SOCKET serverSocket, clientSocket;
	vector<SOCKET> vClientSocket;
	char msg[Buf_Size];
	int strLength, i;

	SOCKADDR_IN serverAddress, clientAddress;
	int clientAddressSize;

	if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0)
		Error("WSAStartup Error");

	serverSocket = socket(PF_INET, SOCK_STREAM, 0);	// PF_INET == AF_INET(Ipv4), TCP(UDT의 경우 SOCK_DGRAM)
	if (serverSocket == INVALID_SOCKET)
		Error("Socket() Error");

	memset(&serverAddress, 0, sizeof(serverAddress));
	serverAddress.sin_family = AF_INET;	// Ipv4
	serverAddress.sin_addr.S_un.S_addr = htonl(INADDR_ANY);
	serverAddress.sin_port = htons(atoi(strPort));

	if (bind(serverSocket, (SOCKADDR*)&serverAddress, sizeof(serverAddress)) == SOCKET_ERROR)
		Error("Bind() Error");

	Log("Bind() Ok");

	if (listen(serverSocket, SOMAXCONN) == SOCKET_ERROR)
		Error("Listen() Error");

	Log("Listen() Ok"); 

	clientAddressSize = sizeof(clientAddress);

	memset(msg, 0, sizeof(msg));

	for (int i = 0; i < SOMAXCONN; i++)	// 받아놓을 수 있는 최대치 설정(실제로 여기까지 받지 x)
	{
		clientSocket = accept(serverSocket, 
			(SOCKADDR*)&clientAddress, &clientAddressSize);
		
		vClientSocket.push_back(clientSocket);

		Log("Accept()...");

		if (clientSocket == SOCKET_ERROR)
			Error("Accept() Error");
		else
			printf("Connected client %d\n", i + 1);

		while ((strLength = recv(clientSocket, msg, Buf_Size,0)) != 0)
		{
			printf("%d Client : %s\n", i + 1, msg);
			send(clientSocket, msg, strLength, 0);
			memset(msg, 0, sizeof(msg));
		}

		closesocket(clientSocket);
	}

	closesocket(serverSocket);

	WSACleanup();
	Log("Finish...");
}