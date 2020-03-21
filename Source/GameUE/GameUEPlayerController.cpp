// Fill out your copyright notice in the Description page of Project Settings.


#include "GameUEPlayerController.h"

void AGameUEPlayerController::AddPitchInput(float Val)
{
	if ((Val * InputPitchScale > 0 && RotationInput.Pitch > CameraPitchMAx) || Val * InputPitchScale < 0 && RotationInput.Pitch < CameraPitchMin) {
		return;
	}
	UE_LOG(LogTemp, Warning, TEXT("%f"), RotationInput.Pitch);
	RotationInput.Pitch += !IsLookInputIgnored() ? Val * InputPitchScale : 0.f;
}

void AGameUEPlayerController::AddYawInput(float Val)
{
	RotationInput.Yaw += !IsLookInputIgnored() ? Val * InputYawScale : 0.f;
}
