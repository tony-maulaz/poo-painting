#include "pch.h"
#include <iostream>

using namespace System;
using namespace System::Net;
using namespace System::Net::Sockets;


int main(array<System::String ^> ^args)
{
	Application appl;

	UdpClient^ udpClient = gcnew UdpClient();
	IPAddress^ ipAddress = IPAddress::Parse("127.0.0.1");
	udpClient->Connect(ipAddress, 9400);

	array<Byte>^ sendBytes;

	while ( appl.IsInProgress() ) {

		appl.Execute();

		if (appl.robot.UpdateMove()) {
			if( appl.robot.IsInMove() )
				sendBytes = Text::Encoding::ASCII->GetBytes("Start");
			else
				sendBytes = Text::Encoding::ASCII->GetBytes("Stop");

			udpClient->Send(sendBytes, sendBytes->Length);
			appl.robot.ClearMove();
		}

		if (appl.robot.updatePrint) {
			if(appl.robot.printEnable)
				sendBytes = Text::Encoding::ASCII->GetBytes("Print");
			else
				sendBytes = Text::Encoding::ASCII->GetBytes("StopPrint");
			udpClient->Send(sendBytes, sendBytes->Length);
			appl.robot.updatePrint = false;
		}

		if (appl.robot.UpdateRotate()) {
			sendBytes = Text::Encoding::ASCII->GetBytes("Rot:"+(int)(appl.robot.GetAngle()) );
			udpClient->Send(sendBytes, sendBytes->Length);
			appl.robot.ClearRotate();
		}

		System::Threading::Thread::Sleep(100);
	}

	std::cout << "Application STOP" << std::endl;
	
	udpClient->Close();

	return 0;
}
