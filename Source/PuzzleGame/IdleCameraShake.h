// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Shakes/LegacyCameraShake.h"
#include "IdleCameraShake.generated.h"


UCLASS()
class PUZZLEGAME_API UIdleCameraShake : public ULegacyCameraShake
{
	GENERATED_BODY()

public:
	UIdleCameraShake();
};
