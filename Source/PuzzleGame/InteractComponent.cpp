

#include "InteractComponent.h"

#include "InteractableInterface.h"


UInteractComponent::UInteractComponent()
{
	PrimaryComponentTick.bCanEverTick = true;
}


// Called when the game starts
void UInteractComponent::BeginPlay()
{
	Super::BeginPlay();
}


// Called every frame
void UInteractComponent::TickComponent(float DeltaTime, ELevelTick TickType,
                                       FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}

void UInteractComponent::Interact(USceneComponent* PlayerCamera)
{
	FVector StartLocation = PlayerCamera->GetComponentLocation();
	FVector EndLocation = StartLocation + (PlayerCamera->GetForwardVector() * InteractableRange);
	
	FHitResult Hit;
	
	GetWorld()->LineTraceSingleByChannel(Hit, StartLocation, EndLocation, ECC_Visibility);

	AActor* HitActor = Hit.GetActor();

	if (HitActor && HitActor->Implements<UInteractableInterface>())
	{
		IInteractableInterface::Execute_Interact(HitActor);

		UE_LOG(LogTemp, Log, TEXT("Interact"));
	}

	
}

