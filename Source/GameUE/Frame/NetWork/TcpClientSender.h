#pragma once

#include "Networking/Public/Networking.h"

class GAMEUE_API TcpClientSender
{
private:
	FSocket *HostSocket;
	FIPv4Address IpAddress;
	FRunnableThread* TcpReceiverThread;
};