// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerCharacter.h"

#include "Camera/CameraComponent.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Kismet/GameplayStatics.h"
#include "IdleCameraShake.h"
#include "InteractComponent.h"
#include "WalkingCameraShake.h"
#include "RunningCameraShake.h"

// Sets default values
APlayerCharacter::APlayerCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	PlayerCamera = CreateDefaultSubobject<UCameraComponent>("PlayerCamera");
	PlayerCamera->SetupAttachment(RootComponent);

	PlayerCamera->bUsePawnControlRotation = true;

	InteractComponent = CreateDefaultSubobject<UInteractComponent>("InteractComponent");
}

// Called when the game starts or when spawned
void APlayerCharacter::BeginPlay()
{
	Super::BeginPlay();

	if (APlayerController* PlayerController = Cast<APlayerController>(Controller))
	{
		if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PlayerController->GetLocalPlayer()))
		{
			Subsystem->AddMappingContext(MappingContext, 0);
		}
	}

	GetCharacterMovement()->MaxWalkSpeed = WalkSpeed;
}

void APlayerCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
	UpdateMovementState();
	UpdateCameraShake();
}

// Called to bind functionality to input
void APlayerCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	UEnhancedInputComponent* Input = Cast<UEnhancedInputComponent>(PlayerInputComponent);

	Input->BindAction(MoveAction, ETriggerEvent::Triggered, this, &APlayerCharacter::Move);
	Input->BindAction(LookAction, ETriggerEvent::Triggered, this, &APlayerCharacter::Look);
	Input->BindAction(RunAction, ETriggerEvent::Triggered, this, &APlayerCharacter::StartRunning);
	Input->BindAction(RunAction, ETriggerEvent::None, this, &APlayerCharacter::StopRunning);
	Input->BindAction(InteractAction, ETriggerEvent::Triggered, this, &APlayerCharacter::Interact);
}

void APlayerCharacter::Move(const FInputActionValue& InputValue)
{
	FVector MoveVector = InputValue.Get<FVector>();

	AddMovementInput(GetActorForwardVector(), MoveVector.Y);
	AddMovementInput(GetActorRightVector(), MoveVector.X);
}

void APlayerCharacter::Look(const FInputActionValue& InputValue)
{
	FVector LookVector = InputValue.Get<FVector>();

	AddControllerYawInput(LookVector.X);
	AddControllerPitchInput(LookVector.Y);
}

void APlayerCharacter::StartRunning(const FInputActionValue& InputValue)
{
	GetCharacterMovement()->MaxWalkSpeed = RunSpeed;
}

void APlayerCharacter::StopRunning(const FInputActionValue& InputValue)
{
	GetCharacterMovement()->MaxWalkSpeed = WalkSpeed;
}

void APlayerCharacter::Interact(const FInputActionValue& InputValue)
{
	InteractComponent->Interact(PlayerCamera);
}

void APlayerCharacter::UpdateMovementState()
{
	float Speed = GetVelocity().Length();

	if (Speed <= 0)
	{
		CurrentMovementState = EPlayerMovementState::Idle;
	}
	else if (Speed > 0 && Speed < RunSpeed)
	{
		CurrentMovementState = EPlayerMovementState::Walking;
	}
	else
	{
		CurrentMovementState = EPlayerMovementState::Running;
	}
}

void APlayerCharacter::UpdateCameraShake()
{
	switch (CurrentMovementState)
	{
	case EPlayerMovementState::Idle:
			UGameplayStatics::GetPlayerCameraManager(GetWorld(), 0)->StartCameraShake(UIdleCameraShake::StaticClass());
			break;
		case EPlayerMovementState::Walking:
			UGameplayStatics::GetPlayerCameraManager(GetWorld(), 0)->StartCameraShake(UWalkingCameraShake::StaticClass());
			break;
		case EPlayerMovementState::Running:
			UGameplayStatics::GetPlayerCameraManager(GetWorld(), 0)->StartCameraShake(URunningCameraShake::StaticClass());
			break;
	}

	
}




