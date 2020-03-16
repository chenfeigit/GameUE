// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "TcpClientReceiver.h"
#include "TcpClient.generated.h"

/**
 * 
 */
UCLASS()
class GAMEUE_API UTcpClient : public UObject
{
	GENERATED_BODY()
	
public:

	/* Create Socket and connect to server. */
	UFUNCTION(BlueprintCallable, Category = "TcpClient")
		bool CreateSocket(FString IPString, int32 PortNumber);

	/* Send socket message (main thread). */
	UFUNCTION(BlueprintCallable, Category = "TcpClient")
		bool SocketSend(FString Message);

	/* Receive socket message (child thread). */
	UFUNCTION(BlueprintCallable, Category = "TcpClient")
		bool SocketReceive();

	UFUNCTION(BlueprintCallable, Category = "TcpClient")
		bool ThreadEnd();

	FString StringFromBinaryArray(TArray<uint8> BinaryArray);

private:

	FSocket *ClientSocket;

	FIPv4Address IPAddress;

	FRunnableThread* TcpReceiverThread;
};
