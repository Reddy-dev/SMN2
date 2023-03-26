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
	MoveData_PredictedProperties_Vector = SMN_ClientMove.SavedPredictedProperties_Vector;
	MoveData_PredictedProperties_Vector2D = SMN_ClientMove.SavedPredictedProperties_Vector2D;
	MoveData_PredictedProperties_Vector4 = SMN_ClientMove.SavedPredictedProperties_Vector4;
	MoveData_PredictedProperties_Quat = SMN_ClientMove.SavedPredictedProperties_Quat;
	MoveData_PredictedProperties_Rotator = SMN_ClientMove.SavedPredictedProperties_Rotator;
	MoveData_PredictedProperties_Byte = SMN_ClientMove.SavedPredictedProperties_Byte;
	MoveData_PredictedProperties_GameplayTag = SMN_ClientMove.SavedPredictedProperties_GameplayTag;
}

bool FSMN_NetworkMoveData::Serialize(UCharacterMovementComponent& CharacterMovement, FArchive& Ar, UPackageMap* PackageMap, ENetworkMoveType MoveType)
{
	Super::Serialize(CharacterMovement, Ar, PackageMap, MoveType);
	
	//Serialize all of the arrays
	Ar << MoveData_PredictedProperties_Bool;
	Ar << MoveData_PredictedProperties_Int32;
	Ar << MoveData_PredictedProperties_Float;
	Ar << MoveData_PredictedProperties_Double;
	Ar << MoveData_PredictedProperties_Vector;
	Ar << MoveData_PredictedProperties_Vector2D;
	Ar << MoveData_PredictedProperties_Vector4;
	Ar << MoveData_PredictedProperties_Quat;
	Ar << MoveData_PredictedProperties_Rotator;
	Ar << MoveData_PredictedProperties_Byte;
	Ar << MoveData_PredictedProperties_GameplayTag;
	
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

	SavedPredictedProperties_Bool.Empty();
	SavedPredictedProperties_Int32.Empty();
	SavedPredictedProperties_Float.Empty();
	SavedPredictedProperties_Double.Empty();
	SavedPredictedProperties_Vector.Empty();
	SavedPredictedProperties_Vector2D.Empty();
	SavedPredictedProperties_Vector4.Empty();
	SavedPredictedProperties_Quat.Empty();
	SavedPredictedProperties_Rotator.Empty();
	SavedPredictedProperties_Byte.Empty();
	SavedPredictedProperties_GameplayTag.Empty();
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

	if (SavedPredictedProperties_Vector != NewSMNMove->SavedPredictedProperties_Vector)
	{
		return false;
	}

	if (SavedPredictedProperties_Vector2D != NewSMNMove->SavedPredictedProperties_Vector2D)
	{
		return false;
	}

	if (SavedPredictedProperties_Vector4 != NewSMNMove->SavedPredictedProperties_Vector4)
	{
		return false;
	}

	if (SavedPredictedProperties_Quat != NewSMNMove->SavedPredictedProperties_Quat)
	{
		return false;
	}

	if (SavedPredictedProperties_Rotator != NewSMNMove->SavedPredictedProperties_Rotator)
	{
		return false;
	}

	if (SavedPredictedProperties_Byte != NewSMNMove->SavedPredictedProperties_Byte)
	{
		return false;
	}

	if (SavedPredictedProperties_GameplayTag != NewSMNMove->SavedPredictedProperties_GameplayTag)
	{
		return false;
	}

	return Super::CanCombineWith(NewMove, Character, MaxDelta);
}

void FSMN_SavedMove::SetMoveFor(ACharacter* Character, float InDeltaTime, FVector const& NewAccel, FNetworkPredictionData_Client_Character& ClientData)
{
	Super::SetMoveFor(Character, InDeltaTime, NewAccel, ClientData);

	USMN_CharacterMovementComponent* SMNCharacterMovement = Character->GetCharacterMovement<USMN_CharacterMovementComponent>();
	if (LIKELY(SMNCharacterMovement))
	{
		for (TSMN_PredictedProperty<bool>& BoolProperty : SMNCharacterMovement->PredictedProperties_Bool)
		{
			if (const FBoolProperty* BoolPropertyPtr = CastField<FBoolProperty>(SMNCharacterMovement->GetClass()->FindPropertyByName(BoolProperty.PropertyName)))
			{
				const void* ValuePtr = BoolPropertyPtr->ContainerPtrToValuePtr<void>(SMNCharacterMovement);
				const bool Value = BoolPropertyPtr->GetPropertyValue(ValuePtr);
				BoolProperty.Value = Value;
				SavedPredictedProperties_Bool.Add(BoolProperty);
			}
		}

		for (TSMN_PredictedProperty<int32>& Int32Property : SMNCharacterMovement->PredictedProperties_Int32)
		{
			if (const FIntProperty* Int32PropertyPtr = CastField<FIntProperty>(SMNCharacterMovement->GetClass()->FindPropertyByName(Int32Property.PropertyName)))
			{
				const void* ValuePtr = Int32PropertyPtr->ContainerPtrToValuePtr<void>(SMNCharacterMovement);
				const int32 Value = Int32PropertyPtr->GetPropertyValue(ValuePtr);
				Int32Property.Value = Value;
				SavedPredictedProperties_Int32.Add(Int32Property);
			}
		}

		for (TSMN_PredictedProperty<float>& FloatProperty : SMNCharacterMovement->PredictedProperties_Float)
		{
			if (const FFloatProperty* FloatPropertyPtr = CastField<FFloatProperty>(SMNCharacterMovement->GetClass()->FindPropertyByName(FloatProperty.PropertyName)))
			{
				const void* ValuePtr = FloatPropertyPtr->ContainerPtrToValuePtr<void>(SMNCharacterMovement);
				const float Value = FloatPropertyPtr->GetPropertyValue(ValuePtr);
				FloatProperty.Value = Value;
				SavedPredictedProperties_Float.Add(FloatProperty);
			}
		}

		for (TSMN_PredictedProperty<double>& DoubleProperty : SMNCharacterMovement->PredictedProperties_Double)
		{
			if (const FDoubleProperty* DoublePropertyPtr = CastField<FDoubleProperty>(SMNCharacterMovement->GetClass()->FindPropertyByName(DoubleProperty.PropertyName)))
			{
				const void* ValuePtr = DoublePropertyPtr->ContainerPtrToValuePtr<void>(SMNCharacterMovement);
				const double Value = DoublePropertyPtr->GetPropertyValue(ValuePtr);
				DoubleProperty.Value = Value;
				SavedPredictedProperties_Double.Add(DoubleProperty);
			}
		}

		for (TSMN_PredictedProperty<FVector>& VectorProperty : SMNCharacterMovement->PredictedProperties_Vector)
		{
			if (const FStructProperty* VectorPropertyPtr = CastField<FStructProperty>(SMNCharacterMovement->GetClass()->FindPropertyByName(VectorProperty.PropertyName)))
			{
				VectorProperty.Value = *VectorPropertyPtr->ContainerPtrToValuePtr<FVector>(SMNCharacterMovement);
				SavedPredictedProperties_Vector.Add(VectorProperty);
			}
		}

		for (TSMN_PredictedProperty<FVector2D>& Vector2DProperty : SMNCharacterMovement->PredictedProperties_Vector2D)
		{
			if (const FStructProperty* Vector2DPropertyPtr = CastField<FStructProperty>(SMNCharacterMovement->GetClass()->FindPropertyByName(Vector2DProperty.PropertyName)))
			{
				Vector2DProperty.Value = *Vector2DPropertyPtr->ContainerPtrToValuePtr<FVector2D>(SMNCharacterMovement);
				SavedPredictedProperties_Vector2D.Add(Vector2DProperty);
			}
		}

		for (TSMN_PredictedProperty<FVector4>& Vector4Property : SMNCharacterMovement->PredictedProperties_Vector4)
		{
			if (const FStructProperty* Vector4PropertyPtr = CastField<FStructProperty>(SMNCharacterMovement->GetClass()->FindPropertyByName(Vector4Property.PropertyName)))
			{
				Vector4Property.Value = *Vector4PropertyPtr->ContainerPtrToValuePtr<FVector4>(SMNCharacterMovement);
				SavedPredictedProperties_Vector4.Add(Vector4Property);
			}
		}

		for (TSMN_PredictedProperty<FQuat>& QuatProperty : SMNCharacterMovement->PredictedProperties_Quat)
		{
			if (const FStructProperty* QuatPropertyPtr = CastField<FStructProperty>(SMNCharacterMovement->GetClass()->FindPropertyByName(QuatProperty.PropertyName)))
			{
				QuatProperty.Value = *QuatPropertyPtr->ContainerPtrToValuePtr<FQuat>(SMNCharacterMovement);
				SavedPredictedProperties_Quat.Add(QuatProperty);
			}
		}

		for (TSMN_PredictedProperty<FRotator>& RotatorProperty : SMNCharacterMovement->PredictedProperties_Rotator)
		{
			if (const FStructProperty* RotatorPropertyPtr = CastField<FStructProperty>(SMNCharacterMovement->GetClass()->FindPropertyByName(RotatorProperty.PropertyName)))
			{
				RotatorProperty.Value = *RotatorPropertyPtr->ContainerPtrToValuePtr<FRotator>(SMNCharacterMovement);
				SavedPredictedProperties_Rotator.Add(RotatorProperty);
			}
		}

		for (TSMN_PredictedProperty<uint8>& ByteProperty : SMNCharacterMovement->PredictedProperties_Byte)
		{
			if (const FByteProperty* BytePropertyPtr = CastField<FByteProperty>(SMNCharacterMovement->GetClass()->FindPropertyByName(ByteProperty.PropertyName)))
			{
				const void* ValuePtr = BytePropertyPtr->ContainerPtrToValuePtr<void>(SMNCharacterMovement);
				const uint8 Value = BytePropertyPtr->GetPropertyValue(ValuePtr);
				ByteProperty.Value = Value;
				SavedPredictedProperties_Byte.Add(ByteProperty);
			}
		}

		for (TSMN_PredictedProperty<FGameplayTag>& GameplayTagProperty : SMNCharacterMovement->PredictedProperties_GameplayTag)
		{
			if (const FStructProperty* GameplayTagPropertyPtr = CastField<FStructProperty>(SMNCharacterMovement->GetClass()->FindPropertyByName(GameplayTagProperty.PropertyName)))
			{
				GameplayTagProperty.Value = *GameplayTagPropertyPtr->ContainerPtrToValuePtr<FGameplayTag>(SMNCharacterMovement);
				SavedPredictedProperties_GameplayTag.Add(GameplayTagProperty);
			}
		}
	}
}

void FSMN_SavedMove::PrepMoveFor(ACharacter* Character)
{
	Super::PrepMoveFor(Character);

	USMN_CharacterMovementComponent* SMNCharacterMovement = Character->GetCharacterMovement<USMN_CharacterMovementComponent>();
	if (LIKELY(Character))
	{
		for (TSMN_PredictedProperty<bool>& BoolProperty : SavedPredictedProperties_Bool)
		{
			if (const FBoolProperty* BoolPropertyPtr = CastField<FBoolProperty>(SMNCharacterMovement->GetClass()->FindPropertyByName(BoolProperty.PropertyName)))
			{
				void* ValuePtr = BoolPropertyPtr->ContainerPtrToValuePtr<void>(SMNCharacterMovement);
				BoolPropertyPtr->SetPropertyValue(ValuePtr, BoolProperty.Value);
			}
		}

		for (TSMN_PredictedProperty<int32>& Int32Property : SavedPredictedProperties_Int32)
		{
			if (const FIntProperty* Int32PropertyPtr = CastField<FIntProperty>(SMNCharacterMovement->GetClass()->FindPropertyByName(Int32Property.PropertyName)))
			{
				void* ValuePtr = Int32PropertyPtr->ContainerPtrToValuePtr<void>(SMNCharacterMovement);
				Int32PropertyPtr->SetPropertyValue(ValuePtr, Int32Property.Value);
			}
		}

		for (TSMN_PredictedProperty<float>& FloatProperty : SavedPredictedProperties_Float)
		{
			if (const FFloatProperty* FloatPropertyPtr = CastField<FFloatProperty>(SMNCharacterMovement->GetClass()->FindPropertyByName(FloatProperty.PropertyName)))
			{
				void* ValuePtr = FloatPropertyPtr->ContainerPtrToValuePtr<void>(SMNCharacterMovement);
				FloatPropertyPtr->SetPropertyValue(ValuePtr, FloatProperty.Value);
			}
		}

		for (TSMN_PredictedProperty<double>& DoubleProperty : SavedPredictedProperties_Double)
		{
			if (const FDoubleProperty* DoublePropertyPtr = CastField<FDoubleProperty>(SMNCharacterMovement->GetClass()->FindPropertyByName(DoubleProperty.PropertyName)))
			{
				void* ValuePtr = DoublePropertyPtr->ContainerPtrToValuePtr<void>(SMNCharacterMovement);
				DoublePropertyPtr->SetPropertyValue(ValuePtr, DoubleProperty.Value);
			}
		}

		for (TSMN_PredictedProperty<FVector>& VectorProperty : SavedPredictedProperties_Vector)
		{
			if (const FStructProperty* VectorPropertyPtr = CastField<FStructProperty>(SMNCharacterMovement->GetClass()->FindPropertyByName(VectorProperty.PropertyName)))
			{
				VectorPropertyPtr->SetValue_InContainer(SMNCharacterMovement, &VectorProperty.Value);
			}
		}

		for (TSMN_PredictedProperty<FVector2D>& Vector2DProperty : SavedPredictedProperties_Vector2D)
		{
			if (const FStructProperty* Vector2DPropertyPtr = CastField<FStructProperty>(SMNCharacterMovement->GetClass()->FindPropertyByName(Vector2DProperty.PropertyName)))
			{
				Vector2DPropertyPtr->SetValue_InContainer(SMNCharacterMovement, &Vector2DProperty.Value);
			}
		}

		for (TSMN_PredictedProperty<FVector4>& Vector4Property : SavedPredictedProperties_Vector4)
		{
			if (const FStructProperty* Vector4PropertyPtr = CastField<FStructProperty>(SMNCharacterMovement->GetClass()->FindPropertyByName(Vector4Property.PropertyName)))
			{
				Vector4PropertyPtr->SetValue_InContainer(SMNCharacterMovement, &Vector4Property.Value);
			}
		}

		for (TSMN_PredictedProperty<FQuat>& QuatProperty : SavedPredictedProperties_Quat)
		{
			if (const FStructProperty* QuatPropertyPtr = CastField<FStructProperty>(SMNCharacterMovement->GetClass()->FindPropertyByName(QuatProperty.PropertyName)))
			{
				QuatPropertyPtr->SetValue_InContainer(SMNCharacterMovement, &QuatProperty.Value);
			}
		}

		for (TSMN_PredictedProperty<FRotator>& RotatorProperty : SavedPredictedProperties_Rotator)
		{
			if (const FStructProperty* RotatorPropertyPtr = CastField<FStructProperty>(SMNCharacterMovement->GetClass()->FindPropertyByName(RotatorProperty.PropertyName)))
			{
				RotatorPropertyPtr->SetValue_InContainer(SMNCharacterMovement, &RotatorProperty.Value);
			}
		}

		for (TSMN_PredictedProperty<uint8>& ByteProperty : SavedPredictedProperties_Byte)
		{
			if (const FByteProperty* BytePropertyPtr = CastField<FByteProperty>(SMNCharacterMovement->GetClass()->FindPropertyByName(ByteProperty.PropertyName)))
			{
				void* ValuePtr = BytePropertyPtr->ContainerPtrToValuePtr<void>(SMNCharacterMovement);
				BytePropertyPtr->SetPropertyValue(ValuePtr, ByteProperty.Value);
			}
		}

		for (TSMN_PredictedProperty<FGameplayTag>& GameplayTagProperty : SavedPredictedProperties_GameplayTag)
		{
			if (const FStructProperty* GameplayTagPropertyPtr = CastField<FStructProperty>(SMNCharacterMovement->GetClass()->FindPropertyByName(GameplayTagProperty.PropertyName)))
			{
				GameplayTagPropertyPtr->SetValue_InContainer(SMNCharacterMovement, &GameplayTagProperty.Value);
			}
		}
	}
}

FSMN_NetworkPredictionData_Client::FSMN_NetworkPredictionData_Client(const UCharacterMovementComponent& ClientMovement):
	Super(ClientMovement){ }

FSavedMovePtr FSMN_NetworkPredictionData_Client::AllocateNewMove()
{
	return FSavedMovePtr(new FSMN_SavedMove());
}

USMN_CharacterMovementComponent::USMN_CharacterMovementComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	SetIsReplicatedByDefault(true);
	SetNetworkMoveDataContainer(SMN_MoveDataContainer); 
}

FNetworkPredictionData_Client* USMN_CharacterMovementComponent::GetPredictionData_Client() const
{
	check(PawnOwner);

	if (!ClientPredictionData)
	{
		USMN_CharacterMovementComponent* MutableThis = const_cast<USMN_CharacterMovementComponent*>(this);
		MutableThis->ClientPredictionData = new FSMN_NetworkPredictionData_Client(*this);
	}

	return ClientPredictionData; 
}

void USMN_CharacterMovementComponent::MoveAutonomous(float ClientTimeStamp, float DeltaTime, uint8 CompressedFlags, const FVector& NewAccel)
{
	if (FSMN_NetworkMoveData* MoveData = static_cast<FSMN_NetworkMoveData*>(GetCurrentNetworkMoveData()))
	{
		for (TSMN_PredictedProperty<bool>& BoolProperty : PredictedProperties_Bool)
		{
			if (const FBoolProperty* BoolPropertyPtr = CastField<FBoolProperty>(
				GetClass()->FindPropertyByName(BoolProperty.PropertyName)))
			{
				void* ValuePtr = BoolPropertyPtr->ContainerPtrToValuePtr<void>(this);
				BoolPropertyPtr->SetPropertyValue(ValuePtr, MoveData->MoveData_PredictedProperties_Bool.FindByKey(BoolProperty)->Value);
			}
		}

		for (TSMN_PredictedProperty<int32>& Int32Property : PredictedProperties_Int32)
		{
			if (const FIntProperty* Int32PropertyPtr = CastField<FIntProperty>(
				GetClass()->FindPropertyByName(Int32Property.PropertyName)))
			{
				void* ValuePtr = Int32PropertyPtr->ContainerPtrToValuePtr<void>(this);
				Int32PropertyPtr->SetPropertyValue(ValuePtr, MoveData->MoveData_PredictedProperties_Int32.FindByKey(Int32Property)->Value);
			}
		}

		for (TSMN_PredictedProperty<float>& FloatProperty : PredictedProperties_Float)
		{
			if (const FFloatProperty* FloatPropertyPtr = CastField<FFloatProperty>(
				GetClass()->FindPropertyByName(FloatProperty.PropertyName)))
			{
				void* ValuePtr = FloatPropertyPtr->ContainerPtrToValuePtr<void>(this);
				FloatPropertyPtr->SetPropertyValue(ValuePtr, MoveData->MoveData_PredictedProperties_Float.FindByKey(FloatProperty)->Value);
			}
		}

		for (TSMN_PredictedProperty<double>& DoubleProperty : PredictedProperties_Double)
		{
			if (const FDoubleProperty* DoublePropertyPtr = CastField<FDoubleProperty>(
				GetClass()->FindPropertyByName(DoubleProperty.PropertyName)))
			{
				void* ValuePtr = DoublePropertyPtr->ContainerPtrToValuePtr<void>(this);
				DoublePropertyPtr->SetPropertyValue(ValuePtr, MoveData->MoveData_PredictedProperties_Double.FindByKey(DoubleProperty)->Value);
			}
		}

		for (TSMN_PredictedProperty<FVector>& VectorProperty : PredictedProperties_Vector)
		{
			if (const FStructProperty* VectorPropertyPtr = CastField<FStructProperty>(
				GetClass()->FindPropertyByName(VectorProperty.PropertyName)))
			{
				VectorPropertyPtr->SetValue_InContainer(this, &MoveData->MoveData_PredictedProperties_Vector.FindByKey(VectorProperty)->Value);
			}
		}

		for (TSMN_PredictedProperty<FVector2D>& Vector2DProperty : PredictedProperties_Vector2D)
		{
			if (const FStructProperty* Vector2DPropertyPtr = CastField<FStructProperty>(
				GetClass()->FindPropertyByName(Vector2DProperty.PropertyName)))
			{
				Vector2DPropertyPtr->SetValue_InContainer(this, &MoveData->MoveData_PredictedProperties_Vector2D.FindByKey(Vector2DProperty)->Value);
			}
		}

		for (TSMN_PredictedProperty<FVector4>& Vector4Property : PredictedProperties_Vector4)
		{
			if (const FStructProperty* Vector4PropertyPtr = CastField<FStructProperty>(
				GetClass()->FindPropertyByName(Vector4Property.PropertyName)))
			{
				Vector4PropertyPtr->SetValue_InContainer(this, &MoveData->MoveData_PredictedProperties_Vector4.FindByKey(Vector4Property)->Value);
			}
		}

		for (TSMN_PredictedProperty<FRotator>& RotatorProperty : PredictedProperties_Rotator)
		{
			if (const FStructProperty* RotatorPropertyPtr = CastField<FStructProperty>(
				GetClass()->FindPropertyByName(RotatorProperty.PropertyName)))
			{
				RotatorPropertyPtr->SetValue_InContainer(this, &MoveData->MoveData_PredictedProperties_Rotator.FindByKey(RotatorProperty)->Value);
			}
		}

		for (TSMN_PredictedProperty<FQuat>& QuatProperty : PredictedProperties_Quat)
		{
			if (const FStructProperty* QuatPropertyPtr = CastField<FStructProperty>(
				GetClass()->FindPropertyByName(QuatProperty.PropertyName)))
			{
				QuatPropertyPtr->SetValue_InContainer(this, &MoveData->MoveData_PredictedProperties_Quat.FindByKey(QuatProperty)->Value);
			}
		}

		for (TSMN_PredictedProperty<uint8>& ByteProperty : PredictedProperties_Byte)
		{
			if (const FByteProperty* BytePropertyPtr = CastField<FByteProperty>(
				GetClass()->FindPropertyByName(ByteProperty.PropertyName)))
			{
				void* ValuePtr = BytePropertyPtr->ContainerPtrToValuePtr<void>(this);
				BytePropertyPtr->SetPropertyValue(ValuePtr, MoveData->MoveData_PredictedProperties_Byte.FindByKey(ByteProperty)->Value);
			}
		}

		for (TSMN_PredictedProperty<FGameplayTag>& GameplayTagProperty : PredictedProperties_GameplayTag)
		{
			if (const FStructProperty* GameplayTagPropertyPtr = CastField<FStructProperty>(
				GetClass()->FindPropertyByName(GameplayTagProperty.PropertyName)))
			{
				GameplayTagPropertyPtr->SetValue_InContainer(this, &MoveData->MoveData_PredictedProperties_GameplayTag.FindByKey(GameplayTagProperty)->Value);
			}
		}
	}

	Super::MoveAutonomous(ClientTimeStamp, DeltaTime, CompressedFlags, NewAccel);
}

void USMN_CharacterMovementComponent::AddPredictedProperty_Bool(FName PropertyName)
{
	TSMN_PredictedProperty<bool> NewProperty;
	NewProperty.PropertyName = PropertyName;
	PredictedProperties_Bool.Add(NewProperty);
}

void USMN_CharacterMovementComponent::AddPredictedProperty_Int32(FName PropertyName)
{
	TSMN_PredictedProperty<int32> NewProperty;
	NewProperty.PropertyName = PropertyName;
	PredictedProperties_Int32.Add(NewProperty);
}

void USMN_CharacterMovementComponent::AddPredictedProperty_Float(FName PropertyName)
{
	TSMN_PredictedProperty<float> NewProperty;
	NewProperty.PropertyName = PropertyName;
	PredictedProperties_Float.Add(NewProperty);
}

void USMN_CharacterMovementComponent::AddPredictedProperty_Double(FName PropertyName)
{
	TSMN_PredictedProperty<double> NewProperty;
	NewProperty.PropertyName = PropertyName;
	PredictedProperties_Double.Add(NewProperty);
}

void USMN_CharacterMovementComponent::AddPredictedProperty_Vector(FName PropertyName)
{
	TSMN_PredictedProperty<FVector> NewProperty;
	NewProperty.PropertyName = PropertyName;
	PredictedProperties_Vector.Add(NewProperty);
}

void USMN_CharacterMovementComponent::AddPredictedProperty_Vector2D(FName PropertyName)
{
	TSMN_PredictedProperty<FVector2D> NewProperty;
	NewProperty.PropertyName = PropertyName;
	PredictedProperties_Vector2D.Add(NewProperty);
}

void USMN_CharacterMovementComponent::AddPredictedProperty_Vector4(FName PropertyName)
{
	TSMN_PredictedProperty<FVector4> NewProperty;
	NewProperty.PropertyName = PropertyName;
	PredictedProperties_Vector4.Add(NewProperty);
}

void USMN_CharacterMovementComponent::AddPredictedProperty_Quat(FName PropertyName)
{
	TSMN_PredictedProperty<FQuat> NewProperty;
	NewProperty.PropertyName = PropertyName;
	PredictedProperties_Quat.Add(NewProperty);
}

void USMN_CharacterMovementComponent::AddPredictedProperty_Rotator(FName PropertyName)
{
	TSMN_PredictedProperty<FRotator> NewProperty;
	NewProperty.PropertyName = PropertyName;
	PredictedProperties_Rotator.Add(NewProperty);
}

void USMN_CharacterMovementComponent::AddPredictedProperty_Byte(FName PropertyName)
{
	TSMN_PredictedProperty<uint8> NewProperty;
	NewProperty.PropertyName = PropertyName;
	PredictedProperties_Byte.Add(NewProperty);
}

void USMN_CharacterMovementComponent::AddPredictedProperty_GameplayTag(FName PropertyName)
{
	TSMN_PredictedProperty<FGameplayTag> NewProperty;
	NewProperty.PropertyName = PropertyName;
	PredictedProperties_GameplayTag.Add(NewProperty);
}

void USMN_CharacterMovementComponent::K2_OnMovementUpdated_Implementation(float DeltaTime, const FVector OldLocation,
	const FVector OldVelocity)
{
	Super::OnMovementUpdated(DeltaTime, OldLocation, OldVelocity);
}

void USMN_CharacterMovementComponent::OnMovementUpdated(float DeltaSeconds, const FVector& OldLocation, const FVector& OldVelocity)
{
	K2_OnMovementUpdated(DeltaSeconds, OldLocation, OldVelocity);
}

void USMN_CharacterMovementComponent::K2_OnMovementModeChanged_Implementation(EMovementMode PrevMovementMode, uint8 PreviousCustomMode)
{
	
}

void USMN_CharacterMovementComponent::OnMovementModeChanged(EMovementMode PreviousMovementMode, uint8 PreviousCustomMode)
{
	Super::OnMovementModeChanged(PreviousMovementMode, PreviousCustomMode);
	
	K2_OnMovementModeChanged(PreviousMovementMode, PreviousCustomMode);
}

float USMN_CharacterMovementComponent::K2_GetMaxSpeed_Implementation() const
{
	return Super::GetMaxSpeed();
}

float USMN_CharacterMovementComponent::GetMaxSpeed() const
{
	return K2_GetMaxSpeed();
}

float USMN_CharacterMovementComponent::K2_GetMaxAcceleration_Implementation() const
{
	return Super::GetMaxAcceleration();
}

float USMN_CharacterMovementComponent::GetMaxAcceleration() const
{
	return K2_GetMaxAcceleration();
}

float USMN_CharacterMovementComponent::K2_GetMaxBrakingDeceleration_Implementation() const
{
	return Super::GetMaxBrakingDeceleration();
}

float USMN_CharacterMovementComponent::GetMaxBrakingDeceleration() const
{
	return K2_GetMaxBrakingDeceleration();
}

float USMN_CharacterMovementComponent::K2_GetGravityZ_Implementation() const
{
	return Super::GetGravityZ();
}

float USMN_CharacterMovementComponent::GetGravityZ() const
{
	return K2_GetGravityZ();
}

float USMN_CharacterMovementComponent::K2_GetMaxJumpHeight_Implementation() const
{
	return Super::GetMaxJumpHeight();
}

float USMN_CharacterMovementComponent::GetMaxJumpHeight() const
{
	return K2_GetMaxJumpHeight();
}

bool USMN_CharacterMovementComponent::K2_ShouldCorrectRotation_Implementation() const
{
	return Super::ShouldCorrectRotation();
}

bool USMN_CharacterMovementComponent::ShouldCorrectRotation() const
{
	return K2_ShouldCorrectRotation();
}

bool USMN_CharacterMovementComponent::K2_ShouldCatchAir_Implementation(const FFindFloorResult OldFloor, const FFindFloorResult NewFloor)
{
	return Super::ShouldCatchAir(OldFloor, NewFloor);
}

bool USMN_CharacterMovementComponent::ShouldCatchAir(const FFindFloorResult& OldFloor, const FFindFloorResult& NewFloor)
{
	return K2_ShouldCatchAir(OldFloor, NewFloor);
}

bool USMN_CharacterMovementComponent::K2_CanAttemptJump_Implementation() const
{
	return Super::CanAttemptJump();
}

bool USMN_CharacterMovementComponent::CanAttemptJump() const
{
	return K2_CanAttemptJump();
}

void USMN_CharacterMovementComponent::K2_StartFalling_Implementation(int32 Iterations, float remainingTime, float timeTick, const FVector Delta, const FVector subLoc)
{
	Super::StartFalling(Iterations, remainingTime, timeTick, Delta, subLoc);
}

void USMN_CharacterMovementComponent::StartFalling(int32 Iterations, float remainingTime, float timeTick, const FVector& Delta, const FVector& subLoc)
{
	K2_StartFalling(Iterations, remainingTime, timeTick, Delta, subLoc);
}

void USMN_CharacterMovementComponent::K2_HandleWalkingOffLedge_Implementation(const FVector& PreviousFloorImpactNormal, const FVector& PreviousFloorContactNormal, const FVector& PreviousLocation, float TimeDelta)
{
	Super::HandleWalkingOffLedge(PreviousFloorImpactNormal, PreviousFloorContactNormal, PreviousLocation, TimeDelta);
}

void USMN_CharacterMovementComponent::HandleWalkingOffLedge(const FVector& PreviousFloorImpactNormal, const FVector& PreviousFloorContactNormal, const FVector& PreviousLocation, float TimeDelta)
{
	K2_HandleWalkingOffLedge(PreviousFloorImpactNormal, PreviousFloorContactNormal, PreviousLocation, TimeDelta);
}

void USMN_CharacterMovementComponent::K2_PhysWalking_Implementation(float deltaTime, int32 Iterations)
{
	Super::PhysWalking(deltaTime, Iterations);
}

void USMN_CharacterMovementComponent::PhysWalking(float deltaTime, int32 Iterations)
{
	K2_PhysWalking(deltaTime, Iterations);
}

void USMN_CharacterMovementComponent::K2_PhysFalling_Implementation(float deltaTime, int32 Iterations)
{
	Super::PhysFalling(deltaTime, Iterations);
}

void USMN_CharacterMovementComponent::PhysFalling(float deltaTime, int32 Iterations)
{
	K2_PhysFalling(deltaTime, Iterations);
}

void USMN_CharacterMovementComponent::K2_PhysSwimming_Implementation(float deltaTime, int32 Iterations)
{
	Super::PhysSwimming(deltaTime, Iterations);
}

void USMN_CharacterMovementComponent::PhysSwimming(float deltaTime, int32 Iterations)
{
	K2_PhysSwimming(deltaTime, Iterations);
}

void USMN_CharacterMovementComponent::K2_PhysFlying_Implementation(float deltaTime, int32 Iterations)
{
	Super::PhysFlying(deltaTime, Iterations);
}

void USMN_CharacterMovementComponent::PhysFlying(float deltaTime, int32 Iterations)
{
	K2_PhysFlying(deltaTime, Iterations);
}

void USMN_CharacterMovementComponent::K2_PhysCustom_Implementation(float deltaTime, int32 Iterations)
{
	Super::PhysCustom(deltaTime, Iterations);
}

void USMN_CharacterMovementComponent::PhysCustom(float deltaTime, int32 Iterations)
{
	K2_PhysCustom(deltaTime, Iterations);
}

float USMN_CharacterMovementComponent::K2_SlideAlongSurface_Implementation(const FVector& Delta, float Time, const FVector& Normal, FHitResult& Hit, bool bHandleImpact)
{
	return Super::SlideAlongSurface(Delta, Time, Normal, Hit, bHandleImpact);
}

float USMN_CharacterMovementComponent::SlideAlongSurface(const FVector& Delta, float Time, const FVector& Normal,
                                                        FHitResult& Hit, bool bHandleImpact)
{
	return K2_SlideAlongSurface(Delta, Time, Normal, Hit, bHandleImpact);
}

void USMN_CharacterMovementComponent::K2_TwoWallAdjust_Implementation(FVector& Delta, const FHitResult Hit, const FVector OldHitNormal) const
{
	Super::TwoWallAdjust(Delta, Hit, OldHitNormal);
}

void USMN_CharacterMovementComponent::TwoWallAdjust(FVector& Delta, const FHitResult& Hit,
	const FVector& OldHitNormal) const
{
	K2_TwoWallAdjust(Delta, Hit, OldHitNormal);
}

void USMN_CharacterMovementComponent::K2_AdjustFloorHeight_Implementation()
{
	Super::AdjustFloorHeight();
}

void USMN_CharacterMovementComponent::AdjustFloorHeight()
{
	K2_AdjustFloorHeight();
}

void USMN_CharacterMovementComponent::K2_CalcVelocity_Implementation(float deltaTime, float Friction, bool bFluid, float BrakingDeceleration)
{
	Super::CalcVelocity(deltaTime, Friction, bFluid, BrakingDeceleration);
}

void USMN_CharacterMovementComponent::CalcVelocity(float deltaTime, float Friction, bool bFluid, float BrakingDeceleration)
{
	K2_CalcVelocity(deltaTime, Friction, bFluid, BrakingDeceleration);
}

void USMN_CharacterMovementComponent::K2_PerformMovement_Implementation(float deltaTime)
{
	Super::PerformMovement(deltaTime);
}

void USMN_CharacterMovementComponent::PerformMovement(float deltaTime)
{
	K2_PerformMovement(deltaTime);
}

void USMN_CharacterMovementComponent::K2_SimulateMovement_Implementation(float deltaTime)
{
	Super::SimulateMovement(deltaTime);
}

void USMN_CharacterMovementComponent::SimulateMovement(float deltaTime)
{
	K2_SimulateMovement(deltaTime);
}

