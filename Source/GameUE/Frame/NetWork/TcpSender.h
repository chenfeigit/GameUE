#pragma once
// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "TcpClientReceiver.h"

/**
 *
 */
class GAMEUE_API FTcpSender : public FRunnable 
{

public:

	FTcpSender() {}

	~FTcpSender() { bStopped = true; }

	/* Create Socket and connect to server. */
	bool CreateSocket(FString IPString, int32 PortNumber);

	/* Send socket message (main thread). */
	bool SocketSend(FString Message);

	/* Receive socket message (child thread). */
	bool SocketReceive();

	bool ThreadEnd();

	FString StringFromBinaryArray(TArray<uint8> BinaryArray);

	virtual bool Init() override;

	virtual uint32 Run() override;

	virtual void Stop() override;

private:

	bool bStopped;

	FThreadSafeCounter StopTaskCounter;

	FSocket *ClientSocket;

	FIPv4Address IPAddress;

	FRunnableThread* TcpReceiverThread;
};
