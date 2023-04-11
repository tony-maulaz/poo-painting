#include "pch.h"
#include <iostream>

//using namespace std;
using namespace System;
using namespace System::Net;
using namespace System::Net::Sockets;

int main(array<System::String ^> ^args)
{
	UdpClient^ udpClient = gcnew UdpClient();
	IPAddress^ ipAddress = IPAddress::Parse("127.0.0.1");
	udpClient->Connect(ipAddress, 9400);

	array<Byte>^ sendBytes = Text::Encoding::ASCII->GetBytes("Hello World");
	udpClient->Send(sendBytes, sendBytes->Length);
	
	for (int i = 0; i < 20; i++) {
		array<Byte>^ sendBytes = Text::Encoding::ASCII->GetBytes("Hello World : " + i);
		udpClient->Send(sendBytes, sendBytes->Length);
		_sleep(100);
	}
	
	udpClient->Close();

	std::cout << "Hello World" << std::endl;
    return 0;
}
