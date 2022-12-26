// udp_server.cpp : �������̨Ӧ�ó������ڵ㡣

//
//������һ����򵥵� UDP ���������� UDPServer. ������֮�󣬽�������ѭ��������
//4567 �˿ڵ����� UDP �����������־ͽ��û��������ַ�����ʽ��ӡ��������ش������¡�

#include "stdafx.h"
#pragma comment(lib, "WS2_32")


int main()
{
	system("title UDP_Server_2018_1_11");

	WSADATA wsaDate;
	WSAStartup(MAKEWORD(2, 2), &wsaDate);

	// �����׽���
	SOCKET sockServer = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);

	if (sockServer == INVALID_SOCKET)
	{
		printf("Failed socket()\n");
	}

	// ��� sockaddr_in �ṹ
	SOCKADDR_IN addrServer;
	addrServer.sin_addr.S_un.S_addr = INADDR_ANY;
	addrServer.sin_family = AF_INET;
	addrServer.sin_port = htons(3456);

	// ������׽��ֵ�һ�����ص�ַ
	if (SOCKET_ERROR == bind(sockServer, (SOCKADDR *)&addrServer, sizeof(SOCKADDR_IN)))
	{
		printf("Failed bin()\n");
		return 0;
	}

	// ��������
	char szRecvBuf[1024] = "";
	SOCKADDR_IN addrClient;
	//SOCKET sockClient;   //*****UDP����û�����*****
	int len = sizeof(SOCKADDR_IN);


	while (true)
	{
		int nRecv = recvfrom(sockServer, szRecvBuf, 1024, 0, (SOCKADDR *)&addrClient, &len); //���շ����ܵ��ֽ���

		if (nRecv > 0)
		{
			szRecvBuf[nRecv] = '\0';
			printf("���յ�����(%s):%s\n", inet_ntoa(addrClient.sin_addr), szRecvBuf);
		}

	}

	//�ر��׽���
	closesocket(sockServer);

	//�ر������
	WSACleanup();

	return 0;
}

