// ���� �ڵ�

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
// well known port�� ���ؼ� port ����

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

	serverSocket = socket(PF_INET, SOCK_STREAM, 0);	// PF_INET == AF_INET(Ipv4), TCP(UDT�� ��� SOCK_DGRAM)
	if (serverSocket == INVALID_SOCKET)
		Error("Socket() Error");

	Log("Socket Ok");

	memset(&serverAddress, 0, sizeof(serverAddress));
	serverAddress.sin_family = AF_INET;
	serverAddress.sin_addr.S_un.S_addr = inet_addr(strServerIP);
	serverAddress.sin_port = htons(atoi(strPort));
	// ������ ����� ��� �ܺ����Ͽ��� �о���� ������� ¥����
	// ������ �ȵ� ��쿡 ����� ��ȸ��η� ���������� �о���� ��� �ʿ�

	if (connect(serverSocket, (SOCKADDR*)&serverAddress, sizeof(serverAddress)) == SOCKET_ERROR)
		Error("Connect() Error");
	else
		Log("Connected...");

	while (1)
	{
		fputs("Input Message(Q to quit) : ", stdout);	// ǥ�� �����
		fgets(msg, Buf_Size, stdin);

		if (!strcmp(msg, "Q\n") || !strcmp(msg, "q\n"))
			break;

		send(serverSocket, msg, strlen(msg), 0);
		strLength = recv(serverSocket, msg, Buf_Size - 1, 0);	// Null ���� ����
		msg[strLength] = 0;

		printf("Message from Server : %s\n", msg);
	}

	closesocket(serverSocket);
	WSACleanup();
}
