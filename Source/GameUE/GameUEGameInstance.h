// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Frame/NetWork/TcpClient.h"
#include "Engine/GameInstance.h"
#include "Frame/NetWork/LuaProto.h"
#include "GameUEGameInstance.generated.h"

/**
 * 
 */
UCLASS()
class GAMEUE_API UGameUEGameInstance : public UGameInstance
{
	GENERATED_BODY()

public:

	virtual void Init() override;

	virtual void Shutdown() override;

	UFUNCTION(BlueprintCallable, Category = "GameUE")
	UObject* GetSingletonObject(UClass* Class);

	UFUNCTION(BlueprintCallable, Category = "GameUE")
	UTcpClient* GetTcpClient();

private:

	TMap<FName, UObject*> SingletonObjectMap;

	FLuaProto ProtoC;

	//UTcpClient TcpClient;
};
