// Copyright 2021 Glitch Games.
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "MultiCharacter.generated.h"

class UMyCharacterMovementComponent; 
UCLASS()
class MULTIPLAYERMOVEMENTPLUGIN_API AMultiCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AMultiCharacter(const class FObjectInitializer& ObjectInitializer);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UFUNCTION(BlueprintNativeEvent)
		void PhysNetCustom(float DeltaTime, int32 Iterations);

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Smooth Network Movement")
		UMyCharacterMovementComponent* GetMultiplayerMovementComponent() const;

	UFUNCTION(BlueprintNativeEvent)
		void OnMovementUpdatedCustom(float DeltaSeconds, const FVector& OldLocation,const FVector& OldVelocity); 

};
