// Fill out your copyright notice in the Description page of Project Settings.


#include "GameUEGameModeBase.h"


void AGameUEGameModeBase::GM(FString InCommand)
{
	CallbackFunction.ExecuteIfBound(InCommand);
}
