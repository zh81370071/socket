// udp_client.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#pragma comment(lib, "WS2_32")

int main()
{
	// ��ʼ��Winsock��
	WSADATA wsaData;
	WSAStartup(MAKEWORD(2, 2), &wsaData);

	// �����׽���
	SOCKET sockClient = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);


	// Ҳ�������������bind������һ�����ص�ַ
	// ����ϵͳ�����Զ�����

	// ��дԶ�̵�ַ��Ϣ
	SOCKADDR_IN addrClient;
	char szbuf[20] = "";
	printf("�������������IP:");
	scanf("%s", szbuf);
	addrClient.sin_addr.S_un.S_addr = inet_addr(szbuf);
	addrClient.sin_family = AF_INET;
	addrClient.sin_port = htons(3456);

	// ע�⣬����Ҫ��д�������������ڻ�����IP��ַ  �����ļ����û��������ֱ��ʹ��127.0.0.1����
	// ��������
	char szSendBuf[1024] = "";
	while (true)
	{
		printf(">>");
		scanf("%s", szSendBuf);
		sendto(sockClient, szSendBuf, strlen(szSendBuf) + 1, 0, (SOCKADDR *)&addrClient, sizeof(SOCKADDR_IN));
	}


	closesocket(sockClient);
	WSACleanup();



	return 0;
}


