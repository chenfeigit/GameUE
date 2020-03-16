// Fill out your copyright notice in the Description page of Project Settings.


#include "TcpSocket.h"
#include "Engine.h"

// Sets default values
ATcpSocket::ATcpSocket()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

bool ATcpSocket::StartTcpReceiver(const FString& SocketName, const FString& IPString, const int32 PortNumber)
{
	ListenerSocket = CreateTcpConnectionListener(SocketName, IPString, PortNumber);
	if (ListenerSocket == nullptr)
	{
		UE_LOG(LogTemp, Warning, TEXT("StartTcpReceiver: Tcp listener socket created failed."));
		UE_LOG(LogTemp, Warning, TEXT("StartTcpReceiver: IP %s, Port %d"), &IPString, PortNumber);
		return false;
	}
	UE_LOG(LogTemp, Log, TEXT("StartTcpReceiver: Tcp listener socket created success."));
	UE_LOG(LogTemp, Log, TEXT("StartTcpReceiver: IP %s, Port %d"), &IPString, PortNumber);

	FTimerHandle TimeHandle;
	GetWorldTimerManager().SetTimer(TimeHandle, this, &ATcpSocket::TcpConnectionListener, 0.01, true);
	return true;
}

void ATcpSocket::TcpConnectionListener()
{
	if (ListenerSocket == nullptr)
	{
		UE_LOG(LogTemp, Warning, TEXT("TcpConnectionListener: Listener socket invalid."));
		return;
	}
	TSharedRef<FInternetAddr> RemoteAddress = ISocketSubsystem::Get(PLATFORM_SOCKETSUBSYSTEM)->CreateInternetAddr();
	// Handle incoming connections
	bool Pending;
	if (ListenerSocket->HasPendingConnection(Pending) && Pending)
	{
		// Already have a connection? destroy previous
		if (ConnectionSocket)
		{
			ConnectionSocket->Close();
			ISocketSubsystem::Get(PLATFORM_SOCKETSUBSYSTEM)->DestroySocket(ConnectionSocket);
		}
		// Accept a connect that is pending
		ConnectionSocket = ListenerSocket->Accept(*RemoteAddress, TEXT("TcpSocket received socket connection."));
		if (ConnectionSocket != nullptr)
		{
			// Global cache of current remote address
			RemoteAddressForConnection = FIPv4Endpoint(RemoteAddress);
			UE_LOG(LogTemp, Log, TEXT("TcpConnectionListener: Accepted connection success."));
			FTimerHandle Handle;
			GetWorldTimerManager().SetTimer(Handle, this, &ATcpSocket::TcpSocketListener, 0.01, true);
		}
	}
}

void ATcpSocket::TcpSocketListener()
{
	if (!ConnectionSocket)
		return;
	TArray<uint8> ReceivedData;
	uint32 Size;
	while (ConnectionSocket->HasPendingData(Size))
	{
		ReceivedData.Init(FMath::Min(Size, 65507u), 0);
		int32 Read = 0;
		ConnectionSocket->Recv(ReceivedData.GetData(), ReceivedData.Num(), Read);
		UE_LOG(LogTemp, Log, TEXT("TcpSocketListener: %d bytes data received."), ReceivedData.Num());
	}
	if (ReceivedData.Num() < 0)
	{
		return;
	}
	const FString ReceivedUE4String = StringFromBinaryArray(ReceivedData);
	UE_LOG(LogTemp, Log, TEXT("_____________________________________________________________"));
	UE_LOG(LogTemp, Log, TEXT("%s"), &ReceivedUE4String);
	UE_LOG(LogTemp, Log, TEXT("_____________________________________________________________"));
}

bool ATcpSocket::FormatIP4ToNumber(const FString & IPString, uint8(&Out)[4])
{
	IPString.Replace(TEXT(" "), TEXT(""));
	TArray<FString> ByteStringArray;
	IPString.ParseIntoArray(ByteStringArray, TEXT("."), true);
	if (ByteStringArray.Num() != 4)
	{
		return false;
	}
	for (int32 Index = 0; Index < 4; ++Index)
	{
		Out[Index] = FCString::Atoi(*ByteStringArray[Index]);
	}
	return true;
}

FString ATcpSocket::StringFromBinaryArray(TArray<uint8>& BinaryArray)
{
	BinaryArray.Add(0);
	return FString(ANSI_TO_TCHAR(reinterpret_cast<const char*>(BinaryArray.GetData())));
}

FSocket* ATcpSocket::CreateTcpConnectionListener(const FString& SocketName, const FString& IPString, const int32 PortNumber, const int32 ReceiveBufferSize /*= 2 * 1024 * 1024*/)
{
	uint8 IP4Nums[4];
	if (!FormatIP4ToNumber(IPString, IP4Nums))
	{
		UE_LOG(LogTemp, Warning, TEXT("CreateTcpConnectionListener: Invalid IP address: %s."), &IPString);
		return nullptr;
	}
	FIPv4Endpoint EndPoint(FIPv4Address(IP4Nums[0], IP4Nums[1], IP4Nums[2], IP4Nums[3]), PortNumber);
	FSocket* NewListenerSocket = FTcpSocketBuilder(SocketName)
		.AsReusable()
		.BoundToEndpoint(EndPoint)
		.Listening(8);
	// Set receive buffer size
	int32 NewSize = 0;
	NewListenerSocket->SetReceiveBufferSize(ReceiveBufferSize, NewSize);
	return NewListenerSocket;
}

// Called when the game starts or when spawned
void ATcpSocket::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ATcpSocket::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

