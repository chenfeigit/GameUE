// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "GameUEPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class GAMEUE_API AGameUEPlayerController : public APlayerController
{
	GENERATED_BODY()

public:

	/** Interp speed for blending remote view rotation for smoother client updates */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = PlayerController)
	float CameraPitchMAx;

	/** Interp speed for blending remote view rotation for smoother client updates */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = PlayerController)
	float CameraPitchMin;

	/**
	 * @Override
	 * Add Pitch (look up) input. This value is multiplied by InputPitchScale.
	 * @param Val Amount to add to Pitch. This value is multiplied by InputPitchScale.
	 */
		virtual void AddPitchInput(float Val) override;

	/**
	 * @Override
	 * Add Yaw (turn) input. This value is multiplied by InputYawScale.
	 * @param Val Amount to add to Yaw. This value is multiplied by InputYawScale.
	 */
		virtual void AddYawInput(float Val) override;
	
};
