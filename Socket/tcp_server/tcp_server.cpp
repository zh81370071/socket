// tcp_server.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#pragma comment(lib, "WS2_32")


int main()
{
	system("title TCP������");

	//���Э��ջ�Ƿ��ʹ��
	WSADATA wsaData;
	if (0 != WSAStartup(MAKEWORD(2, 2), &wsaData))
	{
		printf("error:  WSAStartup() faile...\n");
		return -1;
	}

	printf("�������Ѿ�����...\n");

	//�����������˵��׽���
	SOCKET SockServer = socket(AF_INET, SOCK_STREAM, 0);

	//�����������˵ĵ�ַ
	SOCKADDR_IN addrSrever;
	addrSrever.sin_family = AF_INET;
	addrSrever.sin_addr.S_un.S_addr = htonl(INADDR_ANY);
	addrSrever.sin_port = htons(2000);

	//���׽���
	if (SOCKET_ERROR == bind(SockServer, (SOCKADDR *)&addrSrever, sizeof(SOCKADDR)))
	{
		printf("error:  bind() faile...:%d\n", WSAGetLastError());
		return -1;
	}

	//����
	if (SOCKET_ERROR == listen(SockServer, 5))
	{
		printf("error:  listen() faile...:%d\n", WSAGetLastError());
		return -1;
	}
	printf("������������...\n");
	
	//��ʼ���ͻ���ַ���Ȳ���
	int len = sizeof(SOCKADDR);
	SOCKADDR_IN addrClient;
	char szSendBuf[2048] = "�Ѿ����ӷ������ɹ�";
	char szRecvBuf[2048] = "";

	//�ȴ��ͻ�����������,������������
	SOCKET sockAccept = accept(SockServer, (SOCKADDR *)&addrClient, &len);
	if (INVALID_SOCKET == sockAccept)
	{
		printf("error:  accept() faile...:%d\n", WSAGetLastError());
		return -1;
	}

	//������ӳɹ��Ŀͻ�IP�Ͷ˿ں�
	printf("Accepted client IP:[%s], prot:[%d]\n", inet_ntoa(addrClient.sin_addr), ntohs(addrClient.sin_port));

	//����һ������ѭ����
	while (true)
	{

	    recv(sockAccept, szRecvBuf, sizeof(szRecvBuf), 0);
	    printf("�ͻ���:%s \n", szRecvBuf);
	    /*printf(">>");
	    scanf("%s", szSendBuf);
	    send(SockServer, szSendBuf, strlen(szSendBuf) + 1, 0);*/

	}
	
	//�ر��׽���
	closesocket(SockServer);
	//�ر�Э��ջ�ļ��
	WSACleanup();


    return 0;
}

