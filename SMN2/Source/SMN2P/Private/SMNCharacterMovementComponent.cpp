// Fill out your copyright notice in the Description page of Project Settings.

#include "SMNCharacterMovementComponent.h"
#include "GameFramework/Character.h"
#include "UObject/PropertyAccessUtil.h"

void FSMN_NetworkMoveData::ClientFillNetworkMoveData(const FSavedMove_Character& ClientMove, ENetworkMoveType MoveType)
{
	Super::ClientFillNetworkMoveData(ClientMove, MoveType);

	const FSMN_SavedMove& SMN_ClientMove = static_cast<const FSMN_SavedMove&>(ClientMove);

	MoveData_PredictedProperties_Bool = SMN_ClientMove.SavedPredictedProperties_Bool;
	MoveData_PredictedProperties_Int32 = SMN_ClientMove.SavedPredictedProperties_Int32;
	MoveData_PredictedProperties_Float = SMN_ClientMove.SavedPredictedProperties_Float;
	MoveData_PredictedProperties_Double = SMN_ClientMove.SavedPredictedProperties_Double;
}

bool FSMN_NetworkMoveData::Serialize(UCharacterMovementComponent& CharacterMovement, FArchive& Ar, UPackageMap* PackageMap, ENetworkMoveType MoveType)
{
	for (TSMN_PredictedProperty<bool>& Property : MoveData_PredictedProperties_Bool)
	{
		SerializeOptionalValue<bool>(Ar.IsSaving(), Ar, Property.Value, Property.DefaultValue);
	}

	for (TSMN_PredictedProperty<int32>& Property : MoveData_PredictedProperties_Int32)
	{
		SerializeOptionalValue<int32>(Ar.IsSaving(), Ar, Property.Value, Property.DefaultValue);
	}

	for (TSMN_PredictedProperty<float>& Property : MoveData_PredictedProperties_Float)
	{
		SerializeOptionalValue<float>(Ar.IsSaving(), Ar, Property.Value, Property.DefaultValue);
	}

	for (TSMN_PredictedProperty<double>& Property : MoveData_PredictedProperties_Double)
	{
		SerializeOptionalValue<double>(Ar.IsSaving(), Ar, Property.Value, Property.DefaultValue);
	}
	
	return !Ar.IsError();
}

FSMN_CharacterNetworkMoveDataContainer::FSMN_CharacterNetworkMoveDataContainer()
{
	NewMoveData = &CustomDefaultMoveData[0];
	PendingMoveData = &CustomDefaultMoveData[1];
	OldMoveData = &CustomDefaultMoveData[2];
}

void FSMN_SavedMove::Clear()
{
	Super::Clear();

	for (TSMN_PredictedProperty<bool>& BoolProperty : SavedPredictedProperties_Bool)
	{
		BoolProperty.Value = false;
	}

	for (TSMN_PredictedProperty<int32>& Int32Property : SavedPredictedProperties_Int32)
	{
		Int32Property.Value = 0;
	}

	for (TSMN_PredictedProperty<float>& FloatProperty : SavedPredictedProperties_Float)
	{
		FloatProperty.Value = 0.0f;
	}

	for (TSMN_PredictedProperty<double>& DoubleProperty : SavedPredictedProperties_Double)
	{
		DoubleProperty.Value = 0.0;
	}
}

bool FSMN_SavedMove::CanCombineWith(const FSavedMovePtr& NewMove, ACharacter* Character, float MaxDelta) const
{
	const FSMN_SavedMove* NewSMNMove = static_cast<FSMN_SavedMove*>(NewMove.Get());

	if (SavedPredictedProperties_Bool != NewSMNMove->SavedPredictedProperties_Bool)
	{
		return false;
	}

	if (SavedPredictedProperties_Int32 != NewSMNMove->SavedPredictedProperties_Int32)
	{
		return false;
	}

	if (SavedPredictedProperties_Float != NewSMNMove->SavedPredictedProperties_Float)
	{
		return false;
	}

	if (SavedPredictedProperties_Double != NewSMNMove->SavedPredictedProperties_Double)
	{
		return false;
	}

	return Super::CanCombineWith(NewMove, Character, MaxDelta);
}

void FSMN_SavedMove::SetMoveFor(ACharacter* Character, float InDeltaTime, FVector const& NewAccel, FNetworkPredictionData_Client_Character& ClientData)
{
	Super::SetMoveFor(Character, InDeltaTime, NewAccel, ClientData);

	USMNCharacterMovementComponent* SMNCharacterMovement = Character->GetCharacterMovement<USMNCharacterMovementComponent>();
	if (LIKELY(SMNCharacterMovement))
	{
		for (TSMN_PredictedProperty<bool>& BoolProperty : SMNCharacterMovement->PredictedProperties_Bool)
		{
			if (const FBoolProperty* BoolPropertyPtr = CastField<FBoolProperty>(SMNCharacterMovement->GetClass()->FindPropertyByName(BoolProperty.PropertyName)))
			{
				const void* ValuePtr = BoolPropertyPtr->ContainerPtrToValuePtr<void>(SMNCharacterMovement);
				const bool Value = BoolPropertyPtr->GetPropertyValue(ValuePtr);
				BoolProperty.Value = Value; 
			}
		}

		for (TSMN_PredictedProperty<int32>& Int32Property : SMNCharacterMovement->PredictedProperties_Int32)
		{
			if (const FIntProperty* Int32PropertyPtr = Cast<FIntProperty>(SMNCharacterMovement->GetClass()->FindPropertyByName(Int32Property.PropertyName)))
			{
				const void* ValuePtr = Int32PropertyPtr->ContainerPtrToValuePtr<void>(SMNCharacterMovement);
				const int32 Value = Int32PropertyPtr->GetPropertyValue(ValuePtr);
				Int32Property.Value = Value;
			}
		}

		for (TSMN_PredictedProperty<float>& FloatProperty : SMNCharacterMovement->PredictedProperties_Float)
		{
			if (const FFloatProperty* FloatPropertyPtr = Cast<FFloatProperty>(SMNCharacterMovement->GetClass()->FindPropertyByName(FloatProperty.PropertyName)))
			{
				const void* ValuePtr = FloatPropertyPtr->ContainerPtrToValuePtr<void>(SMNCharacterMovement);
				const float Value = FloatPropertyPtr->GetPropertyValue(ValuePtr);
				FloatProperty.Value = Value;
			}
		}

		for (TSMN_PredictedProperty<double>& DoubleProperty : SMNCharacterMovement->PredictedProperties_Double)
		{
			if (const FDoubleProperty* DoublePropertyPtr = Cast<FDoubleProperty>(SMNCharacterMovement->GetClass()->FindPropertyByName(DoubleProperty.PropertyName)))
			{
				const void* ValuePtr = DoublePropertyPtr->ContainerPtrToValuePtr<void>(SMNCharacterMovement);
				const double Value = DoublePropertyPtr->GetPropertyValue(ValuePtr);
				DoubleProperty.Value = Value;
			}
		}
	}
}

void FSMN_SavedMove::PrepMoveFor(ACharacter* Character)
{
	Super::PrepMoveFor(Character);

	USMNCharacterMovementComponent* SMNCharacterMovement = Character->GetCharacterMovement<USMNCharacterMovementComponent>();
	if (LIKELY(Character))
	{
		for (TSMN_PredictedProperty<bool>& BoolProperty : SavedPredictedProperties_Bool)
		{
			if (const FBoolProperty* BoolPropertyPtr = Cast<FBoolProperty>(SMNCharacterMovement->GetClass()->FindPropertyByName(BoolProperty.PropertyName)))
			{
				void* ValuePtr = BoolPropertyPtr->ContainerPtrToValuePtr<void>(SMNCharacterMovement);
				BoolPropertyPtr->SetPropertyValue(ValuePtr, BoolProperty.Value);
			}
		}

		for (TSMN_PredictedProperty<int32>& Int32Property : SavedPredictedProperties_Int32)
		{
			if (const FIntProperty* Int32PropertyPtr = Cast<FIntProperty>(SMNCharacterMovement->GetClass()->FindPropertyByName(Int32Property.PropertyName)))
			{
				void* ValuePtr = Int32PropertyPtr->ContainerPtrToValuePtr<void>(SMNCharacterMovement);
				Int32PropertyPtr->SetPropertyValue(ValuePtr, Int32Property.Value);
			}
		}

		for (TSMN_PredictedProperty<float>& FloatProperty : SavedPredictedProperties_Float)
		{
			if (const FFloatProperty* FloatPropertyPtr = Cast<FFloatProperty>(SMNCharacterMovement->GetClass()->FindPropertyByName(FloatProperty.PropertyName)))
			{
				void* ValuePtr = FloatPropertyPtr->ContainerPtrToValuePtr<void>(SMNCharacterMovement);
				FloatPropertyPtr->SetPropertyValue(ValuePtr, FloatProperty.Value);
			}
		}

		for (TSMN_PredictedProperty<double>& DoubleProperty : SavedPredictedProperties_Double)
		{
			if (const FDoubleProperty* DoublePropertyPtr = Cast<FDoubleProperty>(SMNCharacterMovement->GetClass()->FindPropertyByName(DoubleProperty.PropertyName)))
			{
				void* ValuePtr = DoublePropertyPtr->ContainerPtrToValuePtr<void>(SMNCharacterMovement);
				DoublePropertyPtr->SetPropertyValue(ValuePtr, DoubleProperty.Value);
			}
		}
	}
}

FSMN_NetworkPredictionData_Client::FSMN_NetworkPredictionData_Client(const UCharacterMovementComponent& ClientMovement):
	Super(ClientMovement){ }

FSavedMovePtr FSMN_NetworkPredictionData_Client::AllocateNewMove()
{
	return MakeShared<FSMN_SavedMove>();
}

USMNCharacterMovementComponent::USMNCharacterMovementComponent()
{
	SetIsReplicated(true);
	SetNetworkMoveDataContainer(SMN_MoveDataContainer); 
}

FNetworkPredictionData_Client* USMNCharacterMovementComponent::GetPredictionData_Client() const
{
	check(PawnOwner);

	if (!ClientPredictionData)
	{
		USMNCharacterMovementComponent* MutableThis = const_cast<USMNCharacterMovementComponent*>(this);
		MutableThis->ClientPredictionData = new FSMN_NetworkPredictionData_Client(*this);
	}

	return ClientPredictionData; 
}

void USMNCharacterMovementComponent::MoveAutonomous(float ClientTimeStamp, float DeltaTime, uint8 CompressedFlags, const FVector& NewAccel)
{
	if (FSMN_NetworkMoveData* MoveData = static_cast<FSMN_NetworkMoveData*>(GetCurrentNetworkMoveData()))
	{
		for (TSMN_PredictedProperty<bool>& BoolProperty : PredictedProperties_Bool)
		{
			if (const FBoolProperty* BoolPropertyPtr = Cast<FBoolProperty>(
				GetClass()->FindPropertyByName(BoolProperty.PropertyName)))
			{
				void* ValuePtr = BoolPropertyPtr->ContainerPtrToValuePtr<void>(this);
				BoolPropertyPtr->SetPropertyValue(ValuePtr, BoolProperty.Value);
			}
		}

		for (TSMN_PredictedProperty<int32>& Int32Property : PredictedProperties_Int32)
		{
			if (const FIntProperty* Int32PropertyPtr = Cast<FIntProperty>(
				GetClass()->FindPropertyByName(Int32Property.PropertyName)))
			{
				void* ValuePtr = Int32PropertyPtr->ContainerPtrToValuePtr<void>(this);
				Int32PropertyPtr->SetPropertyValue(ValuePtr, Int32Property.Value);
			}
		}

		for (TSMN_PredictedProperty<float>& FloatProperty : PredictedProperties_Float)
		{
			if (const FFloatProperty* FloatPropertyPtr = Cast<FFloatProperty>(
				GetClass()->FindPropertyByName(FloatProperty.PropertyName)))
			{
				void* ValuePtr = FloatPropertyPtr->ContainerPtrToValuePtr<void>(this);
				FloatPropertyPtr->SetPropertyValue(ValuePtr, FloatProperty.Value);
			}
		}

		for (TSMN_PredictedProperty<double>& DoubleProperty : PredictedProperties_Double)
		{
			if (const FDoubleProperty* DoublePropertyPtr = Cast<FDoubleProperty>(
				GetClass()->FindPropertyByName(DoubleProperty.PropertyName)))
			{
				void* ValuePtr = DoublePropertyPtr->ContainerPtrToValuePtr<void>(this);
				DoublePropertyPtr->SetPropertyValue(ValuePtr, DoubleProperty.Value);
			}
		}
	}


	Super::MoveAutonomous(ClientTimeStamp, DeltaTime, CompressedFlags, NewAccel);
}

void USMNCharacterMovementComponent::AddPredictedProperty_Bool(FName PropertyName, bool DefaultValue)
{
	TSMN_PredictedProperty<bool> NewProperty;
	NewProperty.PropertyName = PropertyName;
	NewProperty.DefaultValue = DefaultValue;
	PredictedProperties_Bool.Add(NewProperty);
}

void USMNCharacterMovementComponent::AddPredictedProperty_Int32(FName PropertyName, int32 DefaultValue)
{
	TSMN_PredictedProperty<int32> NewProperty;
	NewProperty.PropertyName = PropertyName;
	NewProperty.DefaultValue = DefaultValue;
	PredictedProperties_Int32.Add(NewProperty);
}

void USMNCharacterMovementComponent::AddPredictedProperty_Float(FName PropertyName, float DefaultValue)
{
	TSMN_PredictedProperty<float> NewProperty;
	NewProperty.PropertyName = PropertyName;
	NewProperty.DefaultValue = DefaultValue;
	PredictedProperties_Float.Add(NewProperty);
}

void USMNCharacterMovementComponent::AddPredictedProperty_Double(FName PropertyName, double DefaultValue)
{
	TSMN_PredictedProperty<double> NewProperty;
	NewProperty.PropertyName = PropertyName;
	NewProperty.DefaultValue = DefaultValue;
	PredictedProperties_Double.Add(NewProperty);
}

void USMNCharacterMovementComponent::AddPredictedProperty_Vector(FName PropertyName, FVector DefaultValue)
{
	TSMN_PredictedProperty<FVector> NewProperty;
	NewProperty.PropertyName = PropertyName;
	NewProperty.DefaultValue = DefaultValue;
	PredictedProperties_Vector.Add(NewProperty);
}

void USMNCharacterMovementComponent::AddPredictedProperty_Vector2D(FName PropertyName, FVector2D DefaultValue)
{
	TSMN_PredictedProperty<FVector2D> NewProperty;
	NewProperty.PropertyName = PropertyName;
	NewProperty.DefaultValue = DefaultValue;
	PredictedProperties_Vector2D.Add(NewProperty);
}

void USMNCharacterMovementComponent::AddPredictedProperty_Vector4(FName PropertyName, FVector4 DefaultValue)
{
	TSMN_PredictedProperty<FVector4> NewProperty;
	NewProperty.PropertyName = PropertyName;
	NewProperty.DefaultValue = DefaultValue;
	PredictedProperties_Vector4.Add(NewProperty);
}

void USMNCharacterMovementComponent::AddPredictedProperty_Quat(FName PropertyName, FQuat DefaultValue)
{
	TSMN_PredictedProperty<FQuat> NewProperty;
	NewProperty.PropertyName = PropertyName;
	NewProperty.DefaultValue = DefaultValue;
	PredictedProperties_Quat.Add(NewProperty);
}

void USMNCharacterMovementComponent::AddPredictedProperty_Transform(FName PropertyName, FTransform DefaultValue)
{
	TSMN_PredictedProperty<FTransform> NewProperty;
	NewProperty.PropertyName = PropertyName;
	NewProperty.DefaultValue = DefaultValue;
	PredictedProperties_Transform.Add(NewProperty);
}

void USMNCharacterMovementComponent::AddPredictedProperty_Byte(FName PropertyName, uint8 DefaultValue)
{
	TSMN_PredictedProperty<uint8> NewProperty;
	NewProperty.PropertyName = PropertyName;
	NewProperty.DefaultValue = DefaultValue;
	PredictedProperties_Byte.Add(NewProperty);
}

void USMNCharacterMovementComponent::AddPredictedProperty_GameplayTag(FName PropertyName, FGameplayTag DefaultValue)
{
	TSMN_PredictedProperty<FGameplayTag> NewProperty;
	NewProperty.PropertyName = PropertyName;
	NewProperty.DefaultValue = DefaultValue;
	PredictedProperties_GameplayTag.Add(NewProperty);
}

void USMNCharacterMovementComponent::AddPredictedProperty_GameplayTagContainer(FName PropertyName, FGameplayTagContainer DefaultValue)
{
	TSMN_PredictedProperty<FGameplayTagContainer> NewProperty;
	NewProperty.PropertyName = PropertyName;
	NewProperty.DefaultValue = DefaultValue;
	PredictedProperties_GameplayTagContainer.Add(NewProperty);
}

void USMNCharacterMovementComponent::OnMovementUpdated(float DeltaSeconds, const FVector& OldLocation, const FVector& OldVelocity)
{
	Super::OnMovementUpdated(DeltaSeconds, OldLocation, OldVelocity);

	K2_OnMovementUpdated(DeltaSeconds, OldLocation, OldVelocity);
}

void USMNCharacterMovementComponent::OnMovementModeChanged(EMovementMode PreviousMovementMode, uint8 PreviousCustomMode)
{
	Super::OnMovementModeChanged(PreviousMovementMode, PreviousCustomMode);

	K2_OnMovementModeChanged(PreviousMovementMode, PreviousCustomMode);
}

float USMNCharacterMovementComponent::GetMaxSpeed() const
{
	if (const UFunction* MaxSpeedFunction = GetClass()->FindFunctionByName("K2_GetMaxSpeed"); MaxSpeedFunction->IsInBlueprint())
	{
		return K2_GetMaxSpeed(); 
	}
	
	return Super::GetMaxSpeed();
}

float USMNCharacterMovementComponent::GetMaxAcceleration() const
{
	if (const UFunction* MaxAccelerationFunction = GetClass()->FindFunctionByName("K2_GetMaxAcceleration"); MaxAccelerationFunction->IsInBlueprint())
	{
		return K2_GetMaxAcceleration();
	}

	return Super::GetMaxAcceleration();
}

float USMNCharacterMovementComponent::GetMaxBrakingDeceleration() const
{
	if (const UFunction* MaxBrakingDecelerationFunction = GetClass()->FindFunctionByName("K2_GetMaxBrakingDeceleration"); MaxBrakingDecelerationFunction->IsInBlueprint())
	{
		return K2_GetMaxBrakingDeceleration();
	}

	return Super::GetMaxBrakingDeceleration();
}

float USMNCharacterMovementComponent::GetGravityZ() const
{
	if (const UFunction* GravityZFunction = GetClass()->FindFunctionByName("K2_GetGravityZ"); GravityZFunction->IsInBlueprint())
	{
		return K2_GetGravityZ();
	}

	return Super::GetGravityZ();
}

float USMNCharacterMovementComponent::GetMaxJumpHeight() const
{
	if (const UFunction* MaxJumpHeightFunction = GetClass()->FindFunctionByName("K2_GetMaxJumpHeight"); MaxJumpHeightFunction->IsInBlueprint())
	{
		return K2_GetMaxJumpHeight();
	}

	return Super::GetMaxJumpHeight();
}

bool USMNCharacterMovementComponent::ShouldCorrectRotation() const
{
	if (const UFunction* ShouldCorrectRotationFunction = GetClass()->FindFunctionByName("K2_ShouldCorrectRotation"); ShouldCorrectRotationFunction->IsInBlueprint())
	{
		return K2_ShouldCorrectRotation();
	}
	
	return Super::ShouldCorrectRotation();
}

bool USMNCharacterMovementComponent::ShouldCatchAir(const FFindFloorResult& OldFloor, const FFindFloorResult& NewFloor)
{
	if (const UFunction* ShouldCatchAirFunction = GetClass()->FindFunctionByName("K2_ShouldCatchAir"); ShouldCatchAirFunction->IsInBlueprint())
	{
		return K2_ShouldCatchAir(OldFloor, NewFloor);
	}
	
	return Super::ShouldCatchAir(OldFloor, NewFloor);
}

bool USMNCharacterMovementComponent::CanAttemptJump() const
{
	if (const UFunction* CanAttemptJumpFunction = GetClass()->FindFunctionByName("K2_CanAttemptJump"); CanAttemptJumpFunction->IsInBlueprint())
	{
		return K2_CanAttemptJump();
	}
	
	return Super::CanAttemptJump();
}

void USMNCharacterMovementComponent::StartFalling(int32 Iterations, float remainingTime, float timeTick, const FVector& Delta, const FVector& subLoc)
{
	if (const UFunction* StartFallingFunction = GetClass()->FindFunctionByName("K2_StartFalling"); StartFallingFunction->IsInBlueprint())
	{
		K2_StartFalling(Iterations, remainingTime, timeTick, Delta, subLoc);
		return;
	}
	
	Super::StartFalling(Iterations, remainingTime, timeTick, Delta, subLoc);
}

void USMNCharacterMovementComponent::HandleWalkingOffLedge(const FVector& PreviousFloorImpactNormal, const FVector& PreviousFloorContactNormal, const FVector& PreviousLocation, float TimeDelta)
{
	if (const UFunction* HandleWalkingOffLedgeFunction = GetClass()->FindFunctionByName("K2_HandleWalkingOffLedge"); HandleWalkingOffLedgeFunction->IsInBlueprint())
	{
		K2_HandleWalkingOffLedge(PreviousFloorImpactNormal, PreviousFloorContactNormal, PreviousLocation, TimeDelta);
		return;
	}
	
	Super::HandleWalkingOffLedge(PreviousFloorImpactNormal, PreviousFloorContactNormal, PreviousLocation, TimeDelta);
}

void USMNCharacterMovementComponent::PhysWalking(float deltaTime, int32 Iterations)
{
	if (const UFunction* PhysWalkingFunction = GetClass()->FindFunctionByName("K2_PhysWalking"); PhysWalkingFunction->IsInBlueprint())
	{
		K2_PhysWalking(deltaTime, Iterations);
		return;
	}
	
	Super::PhysWalking(deltaTime, Iterations);
}

void USMNCharacterMovementComponent::PhysFalling(float deltaTime, int32 Iterations)
{
	if (const UFunction* PhysFallingFunction = GetClass()->FindFunctionByName("K2_PhysFalling"); PhysFallingFunction->IsInBlueprint())
	{
		K2_PhysFalling(deltaTime, Iterations);
		return;
	}
	
	Super::PhysFalling(deltaTime, Iterations);
}

void USMNCharacterMovementComponent::PhysSwimming(float deltaTime, int32 Iterations)
{
	if (const UFunction* PhysSwimmingFunction = GetClass()->FindFunctionByName("K2_PhysSwimming"); PhysSwimmingFunction->IsInBlueprint())
	{
		K2_PhysSwimming(deltaTime, Iterations);
		return;
	}
	
	Super::PhysSwimming(deltaTime, Iterations);
}

void USMNCharacterMovementComponent::PhysFlying(float deltaTime, int32 Iterations)
{
	if (const UFunction* PhysFlyingFunction = GetClass()->FindFunctionByName("K2_PhysFlying"); PhysFlyingFunction->IsInBlueprint())
	{
		K2_PhysFlying(deltaTime, Iterations);
		return;
	}
	
	Super::PhysFlying(deltaTime, Iterations);
}

void USMNCharacterMovementComponent::PhysCustom(float deltaTime, int32 Iterations)
{
	if (const UFunction* PhysCustomFunction = GetClass()->FindFunctionByName("K2_PhysCustom"); PhysCustomFunction->IsInBlueprint())
	{
		K2_PhysCustom(deltaTime, Iterations);
		return;
	}
	
	Super::PhysCustom(deltaTime, Iterations);
}

float USMNCharacterMovementComponent::SlideAlongSurface(const FVector& Delta, float Time, const FVector& Normal,
                                                        FHitResult& Hit, bool bHandleImpact)
{
	if (const UFunction* SlideAlongSurfaceFunction = GetClass()->FindFunctionByName("K2_SlideAlongSurface"); SlideAlongSurfaceFunction->IsInBlueprint())
	{
		return K2_SlideAlongSurface(Delta, Time, Normal, Hit, bHandleImpact);
	}
	
	return Super::SlideAlongSurface(Delta, Time, Normal, Hit, bHandleImpact);
}

void USMNCharacterMovementComponent::TwoWallAdjust(FVector& Delta, const FHitResult& Hit,
	const FVector& OldHitNormal) const
{
	if (const UFunction* TwoWallAdjustFunction = GetClass()->FindFunctionByName("K2_TwoWallAdjust"); TwoWallAdjustFunction->IsInBlueprint())
	{
		K2_TwoWallAdjust(Delta, Hit, OldHitNormal);
		return;
	}
	Super::TwoWallAdjust(Delta, Hit, OldHitNormal);
}

void USMNCharacterMovementComponent::AdjustFloorHeight()
{
	Super::AdjustFloorHeight();

	K2_AdjustFloorHeight();
}

void USMNCharacterMovementComponent::CalcVelocity(float deltaTime, float Friction, bool bFluid, float BrakingDeceleration)
{
	if (const UFunction* CalcVelocityFunction = GetClass()->FindFunctionByName("K2_CalcVelocity"); CalcVelocityFunction->IsInBlueprint())
	{
		K2_CalcVelocity(deltaTime, Friction, bFluid, BrakingDeceleration);
		return;
	}
	
	Super::CalcVelocity(deltaTime, Friction, bFluid, BrakingDeceleration);
}

void USMNCharacterMovementComponent::PerformMovement(float deltaTime)
{
	Super::PerformMovement(deltaTime);

	K2_PerformMovement(deltaTime);
}

void USMNCharacterMovementComponent::SimulateMovement(float deltaTime)
{
	Super::SimulateMovement(deltaTime);

	K2_SimulateMovement(deltaTime);
}

