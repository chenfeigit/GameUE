#pragma once

#include "ThreadingBase.h"
#include "Networking/Public/Networking.h"

class GAMEUE_API FTcpClientReceiver : public FRunnable
{
public:

	FTcpClientReceiver(FSocket* client) : ClientSocket(client)
	{}

	~FTcpClientReceiver()
	{
		bStopped = true;
	}

	virtual bool Init() override
	{
		bStopped = false;
		return true;
	}

	virtual uint32 Run() override
	{
		if (!ClientSocket)
		{
			return 0;
		}

		TArray<uint8> ReceiveData;
		uint8 element = 0;

		while (!bStopped)
		{
			ReceiveData.Init(element, 1024u);

			int32 Read = 0;
			ClientSocket->Recv(ReceiveData.GetData(), ReceiveData.Num(), Read);

			const FString ReceivedUE4String = FString(ANSI_TO_TCHAR(reinterpret_cast<const char*>(ReceiveData.GetData())));

			FString log = "Server:" + ReceivedUE4String;
			UE_LOG(LogTemp, Warning, TEXT("*** %s"), *log);

			FPlatformProcess::Sleep(0.01f);
		}


		return 1;
	}

	virtual void Stop() override
	{
		bStopped = true;
	}

private:

	FSocket* ClientSocket;

	bool bStopped;

	FThreadSafeCounter StopTaskCounter;

};