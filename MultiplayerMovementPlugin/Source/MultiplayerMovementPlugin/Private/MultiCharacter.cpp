// Copyright 2021 Glitch Games.


#include "MultiCharacter.h"
#include "MyCharacterMovementComponent.h"

// Sets default values
AMultiCharacter::AMultiCharacter(const class FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer.SetDefaultSubobjectClass<UMyCharacterMovementComponent>(ACharacter::CharacterMovementComponentName))
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMultiCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMultiCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AMultiCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void AMultiCharacter::PhysNetCustom_Implementation(float DeltaTime, int32 Iterations)
{
	//This is made to be overridable in a c++ class. 
}

UMyCharacterMovementComponent* AMultiCharacter::GetMultiplayerMovementComponent() const
{
	UMyCharacterMovementComponent* MyCharacterMovementComponent = static_cast<UMyCharacterMovementComponent*>(GetCharacterMovement());
	return MyCharacterMovementComponent; 
}

void AMultiCharacter::OnMovementUpdatedCustom_Implementation(float DeltaSeconds, const FVector& OldLocation,
	const FVector& OldVelocity)
{
	//This is made to be overridable in a c++ class.
}




