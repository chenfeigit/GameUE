// Fill out your copyright notice in the Description page of Project Settings.


#include "GameUEGameInstance.h"
#include "Public/UnLua.h"

void UGameUEGameInstance::Init()
{
	lua_State* L = UnLua::GetState();
	ProtoC.Setup(L);
}

void UGameUEGameInstance::Shutdown()
{
	ProtoC.CleanUp();
}

UObject* UGameUEGameInstance::GetSingletonObject(UClass* Class)
{
	FName Name = Class->GetFName();
	auto Ref = SingletonObjectMap.FindRef(Name);
	if (Ref == nullptr)
	{
		Ref = NewObject<UObject>(this, Class);
		SingletonObjectMap.Add(Name, Ref);
	}
	return Ref;
}

UTcpClient * UGameUEGameInstance::GetTcpClient()
{
	UObject* Ref = GetSingletonObject(UTcpClient::StaticClass());
	UTcpClient* TcpClientRef = Cast<UTcpClient>(Ref);
	return TcpClientRef;
}
