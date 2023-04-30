// Cudp2Socket.cpp: файл реализации
//

#include "pch.h"
#include "MFCApplicationGUI.h"
#include "Cudp2Socket.h"

using namespace std;
#define ECHOMAX 1024;

UINT ThreadFunction(LPVOID param)
{
		DWORD result = 0;
		UINT exitCode = 0;
		CSocket echoServer;

		cout << "Cudp2Socket() - It works!" << endl;
		AfxSocketInit(NULL);

		// Create socket for sending/receiving datagrams
		if (echoServer.Create(514, SOCK_DGRAM, NULL) == 0)
		{
			AfxMessageBox(L"Create() failed", MB_OK | MB_ICONSTOP);
		}
		SOCKADDR_IN echoClntAddr;
			// Set the size of the in-out parameter
		int clntAddrLen = sizeof(echoClntAddr);
			// Buffer for echo string
		unsigned char echoBuffer[1240];
		unsigned int iechoBuffer[1240];
		// Block until receive message from a client
		int recvMsgSize = 0;
		int i = 0;
		int buflen = 1240;
		for (;;)
		{
		
			recvMsgSize = 0;
			recvMsgSize = echoServer.ReceiveFrom(echoBuffer,buflen, (SOCKADDR*)&echoClntAddr, &clntAddrLen, 0);
			if (recvMsgSize < 0)
			{
				AfxMessageBox(L"RecvFrom() failed", MB_OK | MB_ICONSTOP);
			}
			if (recvMsgSize)
			{
				echoBuffer[recvMsgSize] = 0;
				cout << recvMsgSize << "  "<< i++<< endl;
				for (int n = 0; n < 1024; n++)
				{
					iechoBuffer[n] = echoBuffer[n];
					cout << (unsigned int)iechoBuffer[n] << " ";
				}
				cout << endl;
//				cout << echoBuffer  << endl;
//				cout <<  "echoServer.ReceiveFrom - It works!" << endl;
//				AfxMessageBox(L"RecvFrom() ", MB_OK | MB_ICONSTOP);
			}
			Sleep(10);
		}
		AfxEndThread(exitCode);
		return result;
}

Cudp2Socket::Cudp2Socket()
{
	CWinThread* pThread;
	LPVOID data = 0;
	pThread = AfxBeginThread(ThreadFunction, &data);
}

Cudp2Socket::~Cudp2Socket()
{
}
// функции-члены Cudp2Socket


void Cudp2Socket::OnReceive(int nErrorCode)
{
	// TODO: добавьте специализированный код или вызов базового класса
	std::cout << "OnReceive(nErrorCode); nErrorCode = " << nErrorCode << endl;
	CSocket::OnReceive(nErrorCode);
}
