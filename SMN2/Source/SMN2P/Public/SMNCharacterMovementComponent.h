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

	bool operator ==(const TSMN_PredictedProperty& Other) const
	{
		return PropertyName == Other.PropertyName;
	}

	friend FArchive& operator<<(FArchive& Ar, TSMN_PredictedProperty& A)
	{
		Ar << A.PropertyName;
		Ar << A.Value;
		return Ar;
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
	TArray<TSMN_PredictedProperty<FVector>> MoveData_PredictedProperties_Vector;
	TArray<TSMN_PredictedProperty<FVector2D>> MoveData_PredictedProperties_Vector2D;
	TArray<TSMN_PredictedProperty<FVector4>> MoveData_PredictedProperties_Vector4;
	TArray<TSMN_PredictedProperty<FQuat>> MoveData_PredictedProperties_Quat;
	TArray<TSMN_PredictedProperty<FRotator>> MoveData_PredictedProperties_Rotator;
	TArray<TSMN_PredictedProperty<uint8>> MoveData_PredictedProperties_Byte;
	TArray<TSMN_PredictedProperty<FGameplayTag>> MoveData_PredictedProperties_GameplayTag;
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
	TArray<TSMN_PredictedProperty<FVector>> SavedPredictedProperties_Vector;
	TArray<TSMN_PredictedProperty<FVector2D>> SavedPredictedProperties_Vector2D;
	TArray<TSMN_PredictedProperty<FVector4>> SavedPredictedProperties_Vector4;
	TArray<TSMN_PredictedProperty<FQuat>> SavedPredictedProperties_Quat;
	TArray<TSMN_PredictedProperty<FRotator>> SavedPredictedProperties_Rotator;
	TArray<TSMN_PredictedProperty<uint8>> SavedPredictedProperties_Byte;
	TArray<TSMN_PredictedProperty<FGameplayTag>> SavedPredictedProperties_GameplayTag;
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
UCLASS(Blueprintable, BlueprintType)
class SMN2P_API USMN_CharacterMovementComponent : public UCharacterMovementComponent
{
	GENERATED_BODY()
	
public:
	USMN_CharacterMovementComponent(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());
	
	virtual FNetworkPredictionData_Client* GetPredictionData_Client() const override;
	virtual void MoveAutonomous(float ClientTimeStamp, float DeltaTime, uint8 CompressedFlags, const FVector& NewAccel) override;

	FSMN_CharacterNetworkMoveDataContainer SMN_MoveDataContainer; 
	
	TArray<TSMN_PredictedProperty<bool>> PredictedProperties_Bool;
    TArray<TSMN_PredictedProperty<int32>> PredictedProperties_Int32;
    TArray<TSMN_PredictedProperty<float>> PredictedProperties_Float;
    TArray<TSMN_PredictedProperty<double>> PredictedProperties_Double;
    TArray<TSMN_PredictedProperty<FVector>> PredictedProperties_Vector;
    TArray<TSMN_PredictedProperty<FVector2D>> PredictedProperties_Vector2D;
    TArray<TSMN_PredictedProperty<FVector4>> PredictedProperties_Vector4;
    TArray<TSMN_PredictedProperty<FQuat>> PredictedProperties_Quat;
    TArray<TSMN_PredictedProperty<FRotator>> PredictedProperties_Rotator;
    TArray<TSMN_PredictedProperty<uint8>> PredictedProperties_Byte;
    TArray<TSMN_PredictedProperty<FGameplayTag>> PredictedProperties_GameplayTag;

	UFUNCTION(BlueprintCallable, Category = "SMN2")
	void AddPredictedProperty_Bool(FName PropertyName);

	UFUNCTION(BlueprintCallable, Category = "SMN2")
	void AddPredictedProperty_Int32(FName PropertyName);

	UFUNCTION(BlueprintCallable, Category = "SMN2")
	void AddPredictedProperty_Float(FName PropertyName);

	UFUNCTION(BlueprintCallable, Category = "SMN2")
	void AddPredictedProperty_Double(FName PropertyName);

	UFUNCTION(BlueprintCallable, Category = "SMN2")
	void AddPredictedProperty_Vector(FName PropertyName);
	
	UFUNCTION(BlueprintCallable, Category = "SMN2")
	void AddPredictedProperty_Vector2D(FName PropertyName);

	UFUNCTION(BlueprintCallable, Category = "SMN2")
	void AddPredictedProperty_Vector4(FName PropertyName);

	UFUNCTION(BlueprintCallable, Category = "SMN2")
	void AddPredictedProperty_Quat(FName PropertyName);

	UFUNCTION(BlueprintCallable, Category = "SMN2")
	void AddPredictedProperty_Byte(FName PropertyName);

	UFUNCTION(BlueprintCallable, Category = "SMN2")
	void AddPredictedProperty_GameplayTag(FName PropertyName);

	UFUNCTION(BlueprintCallable, Category = "SMN2")
	void AddPredictedProperty_Rotator(FName PropertyName);

	template <typename T>
	FORCEINLINE void AddPredictedProperty(FProperty* Property)
	{
		if constexpr (TIsSame<T, bool>::Value)
		{
			AddPredictedProperty_Bool(Property->GetFName());
		}
		else if constexpr (TIsSame<T, int32>::Value)
		{
			AddPredictedProperty_Int32(Property->GetFName());
		}
		else if constexpr (TIsSame<T, float>::Value)
		{
			AddPredictedProperty_Float(Property->GetFName());
		}
		else if constexpr (TIsSame<T, double>::Value)
		{
			AddPredictedProperty_Double(Property->GetFName());
		}
		else if constexpr (TIsSame<T, FVector>::Value)
		{
			AddPredictedProperty_Vector(Property->GetFName());
		}
		else if constexpr (TIsSame<T, FVector2D>::Value)
		{
			AddPredictedProperty_Vector2D(Property->GetFName());
		}
		else if constexpr (TIsSame<T, FVector4>::Value)
		{
			AddPredictedProperty_Vector4(Property->GetFName());
		}
		else if constexpr (TIsSame<T, FQuat>::Value)
		{
			AddPredictedProperty_Quat(Property->GetFName());
		}
		else if constexpr (TIsSame<T, FRotator>::Value)
		{
			AddPredictedProperty_Rotator(Property->GetFName());
		}
		else if constexpr (TIsSame<T, uint8>::Value)
		{
			AddPredictedProperty_Byte(Property->GetFName());
		}
		else if constexpr (TIsSame<T, FGameplayTag>::Value)
		{
			AddPredictedProperty_GameplayTag(Property->GetFName());
		}
	}

	template <typename T>
	FORCEINLINE void AddPredictedProperty(FName PropertyName)
	{
		if constexpr (TIsSame<T, bool>::Value)
		{
			AddPredictedProperty_Bool(PropertyName);
		}
		else if constexpr (TIsSame<T, int32>::Value)
		{
			AddPredictedProperty_Int32(PropertyName);
		}
		else if constexpr (TIsSame<T, float>::Value)
		{
			AddPredictedProperty_Float(PropertyName);
		}
		else if constexpr (TIsSame<T, double>::Value)
		{
			AddPredictedProperty_Double(PropertyName);
		}
		else if constexpr (TIsSame<T, FVector>::Value)
		{
			AddPredictedProperty_Vector(PropertyName);
		}
		else if constexpr (TIsSame<T, FVector2D>::Value)
		{
			AddPredictedProperty_Vector2D(PropertyName);
		}
		else if constexpr (TIsSame<T, FVector4>::Value)
		{
			AddPredictedProperty_Vector4(PropertyName);
		}
		else if constexpr (TIsSame<T, FQuat>::Value)
		{
			AddPredictedProperty_Quat(PropertyName);
		}
		else if constexpr (TIsSame<T, FRotator>::Value)
		{
			AddPredictedProperty_Rotator(PropertyName);
		}
		else if constexpr (TIsSame<T, uint8>::Value)
		{
			AddPredictedProperty_Byte(PropertyName);
		}
		else if constexpr (TIsSame<T, FGameplayTag>::Value)
		{
			AddPredictedProperty_GameplayTag(PropertyName);
		}
	}

	UFUNCTION(BlueprintCallable, Category = "SMN2")
	void AddPredictedProperty(FName PropertyName);
	
	UFUNCTION(BlueprintNativeEvent, Category = "SMN2", meta = (DisplayName = "OnMovementUpdated"))
	void K2_OnMovementUpdated(float DeltaTime, const FVector OldLocation, const FVector OldVelocity);
	FORCEINLINE virtual void OnMovementUpdated(float DeltaSeconds, const FVector& OldLocation, const FVector& OldVelocity) override { K2_OnMovementUpdated(DeltaSeconds, OldLocation, OldVelocity); }

	UFUNCTION(BlueprintNativeEvent, Category = "SMN2", meta = (DisplayName = "OnMovementModeChanged"))
	void K2_OnMovementModeChanged(EMovementMode PrevMovementMode, uint8 PreviousCustomMode);
	virtual void OnMovementModeChanged(EMovementMode PreviousMovementMode, uint8 PreviousCustomMode) override;

	UFUNCTION(BlueprintNativeEvent, Category = "SMN2", meta = (DisplayName = "GetMaxSpeed"))
	float K2_GetMaxSpeed() const;
	FORCEINLINE virtual float GetMaxSpeed() const override { return K2_GetMaxSpeed(); }

	UFUNCTION(BlueprintNativeEvent, Category = "SMN2", meta = (DisplayName = "GetMaxAcceleration"))
	float K2_GetMaxAcceleration() const;
	FORCEINLINE virtual float GetMaxAcceleration() const override { return K2_GetMaxAcceleration(); }

	UFUNCTION(BlueprintNativeEvent, Category = "SMN2", meta = (DisplayName = "GetMaxBrakingDeceleration"))
	float K2_GetMaxBrakingDeceleration() const;
	FORCEINLINE virtual float GetMaxBrakingDeceleration() const override { return K2_GetMaxBrakingDeceleration(); }

	UFUNCTION(BlueprintNativeEvent, Category = "SMN2", meta = (DisplayName = "GetGravityZ"))
	float K2_GetGravityZ() const;
	FORCEINLINE virtual float GetGravityZ() const override { return K2_GetGravityZ(); }

	UFUNCTION(BlueprintNativeEvent, Category = "SMN2", meta = (DisplayName = "GetMaxJumpHeight"))
	float K2_GetMaxJumpHeight() const;
	FORCEINLINE virtual float GetMaxJumpHeight() const override { return K2_GetMaxJumpHeight(); }

	UFUNCTION(BlueprintNativeEvent, Category = "SMN2", meta = (DisplayName = "ShouldCorrectRotation"))
	bool K2_ShouldCorrectRotation() const;
	FORCEINLINE virtual bool ShouldCorrectRotation() const override { return K2_ShouldCorrectRotation(); }

	UFUNCTION(BlueprintNativeEvent, Category = "SMN2", meta = (DisplayName = "ShouldCatchAir"))
	bool K2_ShouldCatchAir(const FFindFloorResult OldFloor, const FFindFloorResult NewFloor);
	FORCEINLINE virtual bool ShouldCatchAir(const FFindFloorResult& OldFloor, const FFindFloorResult& NewFloor) override { return K2_ShouldCatchAir(OldFloor, NewFloor); }

	UFUNCTION(BlueprintNativeEvent, Category = "SMN2", meta = (DisplayName = "CanAttemptJump"))
	bool K2_CanAttemptJump() const;
	FORCEINLINE virtual bool CanAttemptJump() const override { return K2_CanAttemptJump(); }

	UFUNCTION(BlueprintNativeEvent, Category = "SMN2", meta = (DisplayName = "StartFalling"))
	void K2_StartFalling(int32 Iterations, float remainingTime, float timeTick, const FVector Delta, const FVector subLoc);
	FORCEINLINE virtual void StartFalling(int32 Iterations, float remainingTime, float timeTick, const FVector& Delta, const FVector& subLoc) override { K2_StartFalling(Iterations, remainingTime, timeTick, Delta, subLoc); }

	UFUNCTION(BlueprintNativeEvent, Category = "SMN2", meta = (DisplayName = "HandleWalkingOffLedge"))
	void K2_HandleWalkingOffLedge(const FVector& PreviousFloorImpactNormal, const FVector& PreviousFloorContactNormal, const FVector& PreviousLocation, float TimeDelta);
	FORCEINLINE virtual void HandleWalkingOffLedge(const FVector& PreviousFloorImpactNormal, const FVector& PreviousFloorContactNormal, const FVector& PreviousLocation, float TimeDelta) override { K2_HandleWalkingOffLedge(PreviousFloorImpactNormal, PreviousFloorContactNormal, PreviousLocation, TimeDelta); }

	UFUNCTION(BlueprintNativeEvent, Category = "SMN2", meta = (DisplayName = "PhysWalking"))
	void K2_PhysWalking(float deltaTime, int32 Iterations);
	FORCEINLINE virtual void PhysWalking(float deltaTime, int32 Iterations) override { K2_PhysWalking(deltaTime, Iterations); }

	UFUNCTION(BlueprintNativeEvent, Category = "SMN2", meta = (DisplayName = "PhysFalling"))
	void K2_PhysFalling(float deltaTime, int32 Iterations);
	FORCEINLINE virtual void PhysFalling(float deltaTime, int32 Iterations) override { K2_PhysFalling(deltaTime, Iterations); }

	UFUNCTION(BlueprintNativeEvent, Category = "SMN2", meta = (DisplayName = "PhysSwimming"))
	void K2_PhysSwimming(float deltaTime, int32 Iterations);
	FORCEINLINE virtual void PhysSwimming(float deltaTime, int32 Iterations) override { K2_PhysSwimming(deltaTime, Iterations); }

	UFUNCTION(BlueprintNativeEvent, Category = "SMN2", meta = (DisplayName = "PhysFlying"))
	void K2_PhysFlying(float deltaTime, int32 Iterations);
	FORCEINLINE virtual void PhysFlying(float deltaTime, int32 Iterations) override { K2_PhysFlying(deltaTime, Iterations); }

	UFUNCTION(BlueprintNativeEvent, Category = "SMN2", meta = (DisplayName = "PhysCustom"))
	void K2_PhysCustom(float deltaTime, int32 Iterations);
	FORCEINLINE virtual void PhysCustom(float deltaTime, int32 Iterations) override { K2_PhysCustom(deltaTime, Iterations); }

	UFUNCTION(BlueprintNativeEvent, Category = "SMN2", meta = (DisplayName = "SlideAlongSurface"))
	float K2_SlideAlongSurface(const FVector& Delta, float Time, const FVector& Normal, FHitResult& Hit, bool bHandleImpact);
	FORCEINLINE virtual float SlideAlongSurface(const FVector& Delta, float Time, const FVector& Normal, FHitResult& Hit, bool bHandleImpact) override { return K2_SlideAlongSurface(Delta, Time, Normal, Hit, bHandleImpact); }

	UFUNCTION(BlueprintNativeEvent, Category = "SMN2", meta = (DisplayName = "TwoWallAdjust"))
	void K2_TwoWallAdjust(FVector& Delta, const FHitResult Hit, const FVector OldHitNormal) const;
	FORCEINLINE virtual void TwoWallAdjust(FVector& Delta, const FHitResult& Hit, const FVector& OldHitNormal) const override { K2_TwoWallAdjust(Delta, Hit, OldHitNormal); }

	UFUNCTION(BlueprintNativeEvent, Category = "SMN2", meta = (DisplayName = "AdjustFloorHeight"))
	void K2_AdjustFloorHeight();
	FORCEINLINE virtual void AdjustFloorHeight() override { K2_AdjustFloorHeight(); }

	UFUNCTION(BlueprintNativeEvent, Category = "SMN2", meta = (DisplayName = "CalcVelocity"))
	void K2_CalcVelocity(float deltaTime, float Friction, bool bFluid, float BrakingDeceleration);
	FORCEINLINE virtual void CalcVelocity(float deltaTime, float Friction, bool bFluid, float BrakingDeceleration) override { K2_CalcVelocity(deltaTime, Friction, bFluid, BrakingDeceleration); }

	UFUNCTION(BlueprintNativeEvent, Category = "SMN2", meta = (DisplayName = "PerformMovement"))
	void K2_PerformMovement(float deltaTime);
	FORCEINLINE virtual void PerformMovement(float deltaTime) override { K2_PerformMovement(deltaTime); }

	UFUNCTION(BlueprintNativeEvent, Category = "SMN2", meta = (DisplayName = "SimulateMovement"))
	void K2_SimulateMovement(float deltaTime);
	FORCEINLINE virtual void SimulateMovement(float deltaTime) override { K2_SimulateMovement(deltaTime); }

	UFUNCTION(BlueprintNativeEvent, Category = "SMN2", meta = (DisplayName = "SmoothClientPosition"))
	void K2_SmoothClientPosition(float DeltaSeconds);
	FORCEINLINE virtual void SmoothClientPosition(float DeltaSeconds) override { K2_SmoothClientPosition(DeltaSeconds); }

	UFUNCTION(BlueprintNativeEvent, Category = "SMN2", meta = (DisplayName = "GetImpartedMovementBaseVelocity"))
	FVector K2_GetImpartedMovementBaseVelocity() const;
	FORCEINLINE virtual FVector GetImpartedMovementBaseVelocity() const override { return K2_GetImpartedMovementBaseVelocity(); }

	UFUNCTION(BlueprintNativeEvent, Category = "SMN2", meta = (DisplayName = "ApplyRequestedMove"))
	bool K2_ApplyRequestedMove(float DeltaTime, float MaxAccel, float MaxSpeed, float Friction, float BrakingDeceleration, FVector& OutAcceleration, float& OutRequestedSpeed);
	FORCEINLINE virtual bool ApplyRequestedMove(float DeltaTime, float MaxAccel, float MaxSpeed, float Friction, float BrakingDeceleration, FVector& OutAcceleration, float& OutRequestedSpeed) override { return K2_ApplyRequestedMove(DeltaTime, MaxAccel, MaxSpeed, Friction, BrakingDeceleration, OutAcceleration, OutRequestedSpeed); }

	UFUNCTION(BlueprintNativeEvent, Category = "SMN2", meta = (DisplayName = "ControlledCharacterMove"))
	void K2_ControlledCharacterMove(const FVector& InputVector, float DeltaSeconds);
	FORCEINLINE virtual void ControlledCharacterMove(const FVector& InputVector, float DeltaSeconds) override { K2_ControlledCharacterMove(InputVector, DeltaSeconds); }
	
	// Callables
	UFUNCTION(BlueprintCallable, Category = "SMN2", meta = (DisplayName = "IsMovementInProgress"))
	FORCEINLINE bool K2_IsMovementInProgress() const { return IsMovementInProgress(); }

	UFUNCTION(BlueprintCallable, Category = "SMN2", meta = (DisplayName = "SafeMoveUpdatedComponent"))
	FORCEINLINE bool K2_SafeMoveUpdatedComponent(const FVector& Delta, const FRotator& NewRotation, bool bSweep, FHitResult& OutHit, ETeleportType Teleport) { return SafeMoveUpdatedComponent(Delta, NewRotation, bSweep, OutHit, Teleport); }
};
