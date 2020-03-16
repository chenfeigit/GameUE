// Fill out your copyright notice in the Description page of Project Settings.

#include "TcpClient.h"
#include "Networking/Public/Networking.h"
#include "Networking/Public/Interfaces/IPv4/IPv4Address.h"

bool UTcpClient::CreateSocket(FString IPString, int32 PortNumber)
{
	//if (!FIPv4Address::Parse(IPString, IPAddress))
	//{
	//	return false;
	//}

	//TSharedPtr<FInternetAddr> InternetAddress = ISocketSubsystem::Get(PLATFORM_SOCKETSUBSYSTEM)->CreateInternetAddr();
	//InternetAddress->SetIp(IPAddress.Value);
	//InternetAddress->SetPort(PortNumber);

	//ClientSocket = ISocketSubsystem::Get(PLATFORM_SOCKETSUBSYSTEM)->CreateSocket(NAME_Stream, TEXT("default"), false);

	//if (ClientSocket->Connect(*InternetAddress))
	//{
	//	UE_LOG(LogTemp, Warning, TEXT("Connect Succeed!"));
	//	return true;
	//}
	//else
	//{
	//	UE_LOG(LogTemp, Warning, TEXT("Connect Failed!"));
	//	return false;
	//}
	UE_LOG(LogTemp, Warning, TEXT("Create Socket"));
	return true;
}

bool UTcpClient::SocketSend(FString Message)
{
	//TCHAR *SeriallizedChar = Message.GetCharArray().GetData();
	//int32 Size = FCString::Strlen(SeriallizedChar) + 1;
	//int32 Sent = 0;

	//if (ClientSocket->Send((uint8*)TCHAR_TO_UTF8(SeriallizedChar), Size, Sent))
	//{
	//	UE_LOG(LogTemp, Warning, TEXT("___Send Succeed!"));
	//	return true;
	//}
	//else
	//{
	//	UE_LOG(LogTemp, Warning, TEXT("___Send Failed!"));
	//	return false;
	//}
	UE_LOG(LogTemp, Warning, TEXT("Send Message"));
	return true;
}

bool UTcpClient::SocketReceive()
{
	//TcpReceiverThread = FRunnableThread::Create(new FTcpClientReceiver(ClientSocket), TEXT("RecvThread"));
	UE_LOG(LogTemp, Warning, TEXT("Send Message"));
	return true;
}

bool UTcpClient::ThreadEnd()
{
	if (TcpReceiverThread != nullptr)
	{
		TcpReceiverThread->Kill(true);
		delete TcpReceiverThread;
	}
	return true;
}

FString UTcpClient::StringFromBinaryArray(TArray<uint8> BinaryArray)
{
	return FString(ANSI_TO_TCHAR(reinterpret_cast<const char*>(BinaryArray.GetData())));
}
