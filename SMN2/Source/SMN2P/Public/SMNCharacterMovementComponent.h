// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameplayTagContainer.h"
#include "SMNCharacterMovementComponent.generated.h"

template<typename T>
struct TSMN_PredictedProperty
{
	FName PropertyName;
	T Value; 
	T DefaultValue;

	bool operator ==(const TSMN_PredictedProperty& Other) const
	{
		return PropertyName == Other.PropertyName && Value == Other.Value && DefaultValue == Other.DefaultValue;
	}
};

class FSMN_NetworkMoveData : public FCharacterNetworkMoveData
{
public:

	using Super = FCharacterNetworkMoveData;

	virtual void ClientFillNetworkMoveData(const FSavedMove_Character& ClientMove, ENetworkMoveType MoveType) override;
	virtual bool Serialize(UCharacterMovementComponent& CharacterMovement, FArchive& Ar, UPackageMap* PackageMap, ENetworkMoveType MoveType) override;
	
	TArray<TSMN_PredictedProperty<bool>> MoveData_PredictedProperties_Bool;
	TArray<TSMN_PredictedProperty<int32>> MoveData_PredictedProperties_Int32;
	TArray<TSMN_PredictedProperty<float>> MoveData_PredictedProperties_Float;
	TArray<TSMN_PredictedProperty<double>> MoveData_PredictedProperties_Double;
};

class FSMN_CharacterNetworkMoveDataContainer : public FCharacterNetworkMoveDataContainer
{
public:

	FSMN_CharacterNetworkMoveDataContainer();

	FSMN_NetworkMoveData CustomDefaultMoveData[3];
};

class FSMN_SavedMove : public FSavedMove_Character
{
public:

	using Super = FSavedMove_Character;
	
	virtual void Clear() override;
	virtual bool CanCombineWith(const FSavedMovePtr& NewMove, ACharacter* Character, float MaxDelta) const override;
	virtual void SetMoveFor(ACharacter* Character, float InDeltaTime, FVector const& NewAccel, class FNetworkPredictionData_Client_Character & ClientData) override;
	virtual void PrepMoveFor(class ACharacter* Character) override;

	TArray<TSMN_PredictedProperty<bool>> SavedPredictedProperties_Bool;
	TArray<TSMN_PredictedProperty<int32>> SavedPredictedProperties_Int32;
	TArray<TSMN_PredictedProperty<float>> SavedPredictedProperties_Float;
	TArray<TSMN_PredictedProperty<double>> SavedPredictedProperties_Double;
};

class FSMN_NetworkPredictionData_Client : public FNetworkPredictionData_Client_Character
{
public:

	using Super = FNetworkPredictionData_Client_Character;

	FSMN_NetworkPredictionData_Client(const UCharacterMovementComponent& ClientMovement);
	virtual FSavedMovePtr AllocateNewMove() override;
};

/**
 * 
 */
UCLASS(Abstract, Blueprintable, BlueprintType)
class SMN2P_API USMNCharacterMovementComponent : public UCharacterMovementComponent
{
	GENERATED_BODY()
	
public:
	USMNCharacterMovementComponent();
	
	virtual FNetworkPredictionData_Client* GetPredictionData_Client() const override;
	virtual void MoveAutonomous(float ClientTimeStamp, float DeltaTime, uint8 CompressedFlags, const FVector& NewAccel) override;

	FSMN_CharacterNetworkMoveDataContainer SMN_MoveDataContainer; 

	UFUNCTION(BlueprintCallable, Category = "SMN2")
	void AddPredictedProperty_Bool(FName PropertyName, bool DefaultValue);

	UFUNCTION(BlueprintCallable, Category = "SMN2")
	void AddPredictedProperty_Int32(FName PropertyName, int32 DefaultValue);

	UFUNCTION(BlueprintCallable, Category = "SMN2")
	void AddPredictedProperty_Float(FName PropertyName,	float DefaultValue);

	UFUNCTION(BlueprintCallable, Category = "SMN2")
	void AddPredictedProperty_Double(FName PropertyName, double DefaultValue);

	UFUNCTION(BlueprintCallable, Category = "SMN2")
	void AddPredictedProperty_Vector(FName PropertyName, FVector DefaultValue);
	
	UFUNCTION(BlueprintCallable, Category = "SMN2")
	void AddPredictedProperty_Vector2D(FName PropertyName, FVector2D DefaultValue);

	UFUNCTION(BlueprintCallable, Category = "SMN2")
	void AddPredictedProperty_Vector4(FName PropertyName, FVector4 DefaultValue);

	UFUNCTION(BlueprintCallable, Category = "SMN2")
	void AddPredictedProperty_Quat(FName PropertyName, FQuat DefaultValue);

	UFUNCTION(BlueprintCallable, Category = "SMN2")
	void AddPredictedProperty_Transform(FName PropertyName, FTransform DefaultValue);

	UFUNCTION(BlueprintCallable, Category = "SMN2")
	void AddPredictedProperty_Byte(FName PropertyName, uint8 DefaultValue);

	UFUNCTION(BlueprintCallable, Category = "SMN2")
	void AddPredictedProperty_GameplayTag(FName PropertyName, FGameplayTag DefaultValue);

	UFUNCTION(BlueprintCallable, Category = "SMN2")
	void AddPredictedProperty_GameplayTagContainer(FName PropertyName, FGameplayTagContainer DefaultValue);

	TArray<TSMN_PredictedProperty<bool>> PredictedProperties_Bool;
	TArray<TSMN_PredictedProperty<int32>> PredictedProperties_Int32;
	TArray<TSMN_PredictedProperty<float>> PredictedProperties_Float;
	TArray<TSMN_PredictedProperty<double>> PredictedProperties_Double;
	TArray<TSMN_PredictedProperty<FVector>> PredictedProperties_Vector;
	TArray<TSMN_PredictedProperty<FVector2D>> PredictedProperties_Vector2D;
	TArray<TSMN_PredictedProperty<FVector4>> PredictedProperties_Vector4;
	TArray<TSMN_PredictedProperty<FQuat>> PredictedProperties_Quat;
	TArray<TSMN_PredictedProperty<FTransform>> PredictedProperties_Transform;
	TArray<TSMN_PredictedProperty<uint8>> PredictedProperties_Byte;
	TArray<TSMN_PredictedProperty<FGameplayTag>> PredictedProperties_GameplayTag;
	TArray<TSMN_PredictedProperty<FGameplayTagContainer>> PredictedProperties_GameplayTagContainer;
	

	// Implementable Events

	UFUNCTION(BlueprintImplementableEvent, Category = "SMN2", meta = (DisplayName = "OnMovementUpdated"))
	void K2_OnMovementUpdated(float DeltaTime, const FVector OldLocation, const FVector OldVelocity);
	virtual void OnMovementUpdated(float DeltaSeconds, const FVector& OldLocation, const FVector& OldVelocity) override;

	UFUNCTION(BlueprintImplementableEvent, Category = "SMN2", meta = (DisplayName = "OnMovementModeChanged"))
	void K2_OnMovementModeChanged(EMovementMode PrevMovementMode, uint8 PreviousCustomMode);
	virtual void OnMovementModeChanged(EMovementMode PreviousMovementMode, uint8 PreviousCustomMode) override;

	UFUNCTION(BlueprintImplementableEvent, Category = "SMN2", meta = (DisplayName = "GetMaxSpeed"))
	float K2_GetMaxSpeed() const;
	virtual float GetMaxSpeed() const override;

	UFUNCTION(BlueprintImplementableEvent, Category = "SMN2", meta = (DisplayName = "GetMaxAcceleration"))
	float K2_GetMaxAcceleration() const;
	virtual float GetMaxAcceleration() const override;

	UFUNCTION(BlueprintImplementableEvent, Category = "SMN2", meta = (DisplayName = "GetMaxBrakingDeceleration"))
	float K2_GetMaxBrakingDeceleration() const;
	virtual float GetMaxBrakingDeceleration() const override;

	UFUNCTION(BlueprintImplementableEvent, Category = "SMN2", meta = (DisplayName = "GetGravityZ"))
	float K2_GetGravityZ() const;
	virtual float GetGravityZ() const override;

	UFUNCTION(BlueprintImplementableEvent, Category = "SMN2", meta = (DisplayName = "GetMaxJumpHeight"))
	float K2_GetMaxJumpHeight() const;
	virtual float GetMaxJumpHeight() const override;

	UFUNCTION(BlueprintImplementableEvent, Category = "SMN2", meta = (DisplayName = "ShouldCorrectRotation"))
	bool K2_ShouldCorrectRotation() const;
	virtual bool ShouldCorrectRotation() const override;

	UFUNCTION(BlueprintImplementableEvent, Category = "SMN2", meta = (DisplayName = "ShouldCatchAir"))
	bool K2_ShouldCatchAir(const FFindFloorResult OldFloor, const FFindFloorResult NewFloor) const;
	virtual bool ShouldCatchAir(const FFindFloorResult& OldFloor, const FFindFloorResult& NewFloor) override;

	UFUNCTION(BlueprintImplementableEvent, Category = "SMN2", meta = (DisplayName = "CanAttemptJump"))
	bool K2_CanAttemptJump() const;
	virtual bool CanAttemptJump() const override;

	UFUNCTION(BlueprintImplementableEvent, Category = "SMN2", meta = (DisplayName = "StartFalling"))
	void K2_StartFalling(int32 Iterations, float remainingTime, float timeTick, const FVector Delta, const FVector subLoc);
	virtual void StartFalling(int32 Iterations, float remainingTime, float timeTick, const FVector& Delta, const FVector& subLoc) override;

	UFUNCTION(BlueprintImplementableEvent, Category = "SMN2", meta = (DisplayName = "HandleWalkingOffLedge"))
	void K2_HandleWalkingOffLedge(const FVector& PreviousFloorImpactNormal, const FVector& PreviousFloorContactNormal, const FVector& PreviousLocation, float TimeDelta);
	virtual void HandleWalkingOffLedge(const FVector& PreviousFloorImpactNormal, const FVector& PreviousFloorContactNormal, const FVector& PreviousLocation, float TimeDelta) override;

	UFUNCTION(BlueprintImplementableEvent, Category = "SMN2", meta = (DisplayName = "PhysWalking"))
	void K2_PhysWalking(float deltaTime, int32 Iterations);
	virtual void PhysWalking(float deltaTime, int32 Iterations) override;

	UFUNCTION(BlueprintImplementableEvent, Category = "SMN2", meta = (DisplayName = "PhysFalling"))
	void K2_PhysFalling(float deltaTime, int32 Iterations);
	virtual void PhysFalling(float deltaTime, int32 Iterations) override;

	UFUNCTION(BlueprintImplementableEvent, Category = "SMN2", meta = (DisplayName = "PhysSwimming"))
	void K2_PhysSwimming(float deltaTime, int32 Iterations);
	virtual void PhysSwimming(float deltaTime, int32 Iterations) override;

	UFUNCTION(BlueprintImplementableEvent, Category = "SMN2", meta = (DisplayName = "PhysFlying"))
	void K2_PhysFlying(float deltaTime, int32 Iterations);
	virtual void PhysFlying(float deltaTime, int32 Iterations) override;

	UFUNCTION(BlueprintImplementableEvent, Category = "SMN2", meta = (DisplayName = "PhysCustom"))
	void K2_PhysCustom(float deltaTime, int32 Iterations);
	virtual void PhysCustom(float deltaTime, int32 Iterations) override;

	UFUNCTION(BlueprintImplementableEvent, Category = "SMN2", meta = (DisplayName = "SlideAlongSurface"))
	float K2_SlideAlongSurface(const FVector& Delta, float Time, const FVector& Normal, FHitResult& Hit, bool bHandleImpact);
	virtual float SlideAlongSurface(const FVector& Delta, float Time, const FVector& Normal, FHitResult& Hit, bool bHandleImpact) override;

	UFUNCTION(BlueprintImplementableEvent, Category = "SMN2", meta = (DisplayName = "TwoWallAdjust"))
	void K2_TwoWallAdjust(FVector& Delta, const FHitResult& Hit, const FVector& OldHitNormal) const;
	virtual void TwoWallAdjust(FVector& Delta, const FHitResult& Hit, const FVector& OldHitNormal) const override;

	UFUNCTION(BlueprintImplementableEvent, Category = "SMN2", meta = (DisplayName = "AdjustFloorHeight"))
	void K2_AdjustFloorHeight();
	virtual void AdjustFloorHeight() override;

	UFUNCTION(BlueprintImplementableEvent, Category = "SMN2", meta = (DisplayName = "CalcVelocity"))
	void K2_CalcVelocity(float deltaTime, float Friction, bool bFluid, float BrakingDeceleration);
	virtual void CalcVelocity(float deltaTime, float Friction, bool bFluid, float BrakingDeceleration) override;

	UFUNCTION(BlueprintImplementableEvent, Category = "SMN2", meta = (DisplayName = "PerformMovement"))
	void K2_PerformMovement(float deltaTime);
	virtual void PerformMovement(float deltaTime) override;

	UFUNCTION(BlueprintImplementableEvent, Category = "SMN2", meta = (DisplayName = "SimulateMovement"))
	void K2_SimulateMovement(float deltaTime);
	virtual void SimulateMovement(float deltaTime) override;
	
	// Callables

	UFUNCTION(BlueprintCallable, Category = "SMN2", meta = (DisplayName = "IsMovementInProgress"))
	FORCEINLINE bool K2_IsMovementInProgress() const { return IsMovementInProgress(); }

	UFUNCTION(BlueprintCallable, Category = "SMN2", meta = (DisplayName = "SafeMoveUpdatedComponent"))
	FORCEINLINE bool K2_SafeMoveUpdatedComponent(const FVector& Delta, const FRotator& NewRotation, bool bSweep, FHitResult& OutHit, ETeleportType Teleport) { return SafeMoveUpdatedComponent(Delta, NewRotation, bSweep, OutHit, Teleport); }
};
