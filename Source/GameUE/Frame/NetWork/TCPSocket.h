// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Networking/Public/Networking.h"
#include "TcpSocket.generated.h"

UCLASS()
class GAMEUE_API ATcpSocket : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ATcpSocket();

	FSocket* ListenerSocket;
	FSocket* ConnectionSocket;
	FIPv4Endpoint RemoteAddressForConnection;

	bool StartTcpReceiver(const FString& SocketName, const FString& IPString, const int32 PortNumber);

	FSocket* CreateTcpConnectionListener(const FString& SocketName, const FString& IPString, const int32 PortNumber, const int32 ReceiveBufferSize = 2 * 1024 * 1024);

	//Timer functions, could be threads
	void TcpConnectionListener();

	void TcpSocketListener();

	bool FormatIP4ToNumber(const FString& IPString, uint8(&Out)[4]);

	FString StringFromBinaryArray(TArray<uint8>& BinaryArray);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
