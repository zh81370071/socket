// tcp_client.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#pragma comment(lib, "WS2_32")


int main()
{
	system("title TCP�ͻ���");

	//���Э��ջ�Ƿ��ʹ��
	WSADATA wsaData;
	if (0 != WSAStartup(MAKEWORD(2, 2), &wsaData))
	{
		printf("error:  WSAStartup() faile...\n");
		return -1;
	}

	//�����ͻ��˵��׽���
	SOCKET sockClient = socket(AF_INET, SOCK_STREAM, 0);
	if(INVALID_SOCKET == sockClient)
	{
		printf("error:  socket() faile...:%d\n", WSAGetLastError());
		return -1;
	}

	SOCKADDR_IN addrServer;
	addrServer.sin_family = AF_INET;
	char szInIP[30] = "";
	printf("������Է�IP��ַ��ͬ����������eg:127.0.0.1\nIP>>");
	scanf("%s", szInIP);
	addrServer.sin_addr.S_un.S_addr = inet_addr(szInIP);
	addrServer.sin_port = htons(2000);

	//���������������TCP����
	if (INVALID_SOCKET == connect(sockClient, (SOCKADDR *)&addrServer, sizeof(SOCKADDR)))
	{
		printf("error:  connect() faile...:%d\n", WSAGetLastError());
		return -1;
	}
		

	char szRecvBuf[2048] = "";
	char szSendBuf[2048] = "�ͻ����Ѿ����ӳɹ�";


	while (true)
	{
		printf(">>");
		scanf("%s", szSendBuf);
		send(sockClient, szSendBuf, strlen(szSendBuf) + 1, 0);
		/*recv(sockClient, szRecvBuf, sizeof(szRecvBuf), 0);
		printf("�ͻ���:%s \n", szRecvBuf);*/

	}




	

	closesocket(sockClient);


	WSACleanup();
    return 0;
}

