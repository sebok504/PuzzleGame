// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "PlayerCharacter.generated.h"


UCLASS()
class PUZZLEGAME_API APlayerCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	APlayerCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UPROPERTY(EditDefaultsOnly) class UCameraComponent* PlayerCamera;

	UPROPERTY(EditDefaultsOnly, Category = "Input") class UInputMappingContext* MappingContext;
	UPROPERTY(EditDefaultsOnly, Category = "Input") class UInputAction* MoveAction;
	UPROPERTY(EditDefaultsOnly, Category = "Input") UInputAction* LookAction;
	UPROPERTY(EditDefaultsOnly, Category = "Input") UInputAction* RunAction;

	UPROPERTY(EditAnywhere, Category = "Movement") float WalkSpeed;
	UPROPERTY(EditAnywhere, Category = "Movement") float RunSpeed;

	UFUNCTION() void Move(const FInputActionValue& InputValue);
	UFUNCTION() void Look(const FInputActionValue& InputValue);
	UFUNCTION() void StartRunning(const FInputActionValue& InputValue);
	UFUNCTION() void StopRunning(const FInputActionValue& InputValue);
	

};
