// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Shakes/LegacyCameraShake.h"
#include "WalkingCameraShake.generated.h"


UCLASS()
class PUZZLEGAME_API UWalkingCameraShake : public ULegacyCameraShake
{
	GENERATED_BODY()

public:
	UWalkingCameraShake();
};
