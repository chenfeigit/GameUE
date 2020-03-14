// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "GameUEGameModeBase.generated.h"

GAMEUE_API DECLARE_LOG_CATEGORY_EXTERN(GMLog, Log, All);

DECLARE_DYNAMIC_DELEGATE_OneParam(FOnGMCommandExecute, FString, Output);

/**
 * 
 */
UCLASS()
class GAMEUE_API AGameUEGameModeBase : public AGameModeBase
{
	GENERATED_BODY()

public:
	/**
	 * GM command entry function, executable in console.
	 */
	UFUNCTION(Exec)
		void GM(FString InCommand);

	UPROPERTY()
		FOnGMCommandExecute CallbackFunction;
};
