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
	MoveData_PredictedProperties_GameplayTagContainer = SMN_ClientMove.SavedPredictedProperties_GameplayTagContainer;
}

bool FSMN_NetworkMoveData::Serialize(UCharacterMovementComponent& CharacterMovement, FArchive& Ar, UPackageMap* PackageMap, ENetworkMoveType MoveType)
{
	bool bOut;
	
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

	for (TSMN_PredictedProperty<FVector>& Property : MoveData_PredictedProperties_Vector)
	{
		SerializeOptionalValue<FVector>(Ar.IsSaving(), Ar, Property.Value, Property.DefaultValue);
	}

	for (TSMN_PredictedProperty<FVector2D>& Property : MoveData_PredictedProperties_Vector2D)
	{
		SerializeOptionalValue<FVector2D>(Ar.IsSaving(), Ar, Property.Value, Property.DefaultValue);
	}

	for (TSMN_PredictedProperty<FVector4>& Property : MoveData_PredictedProperties_Vector4)
	{
		SerializeOptionalValue<FVector4>(Ar.IsSaving(), Ar, Property.Value, Property.DefaultValue);
	}

	for (TSMN_PredictedProperty<FQuat>& Property : MoveData_PredictedProperties_Quat)
	{
		SerializeOptionalValue<FQuat>(Ar.IsSaving(), Ar, Property.Value, Property.DefaultValue);
	}

	for (TSMN_PredictedProperty<FRotator>& Property : MoveData_PredictedProperties_Rotator)
	{
		SerializeOptionalValue<FRotator>(Ar.IsSaving(), Ar, Property.Value, Property.DefaultValue);
	}

	for (TSMN_PredictedProperty<uint8>& Property : MoveData_PredictedProperties_Byte)
	{
		SerializeOptionalValue<uint8>(Ar.IsSaving(), Ar, Property.Value, Property.DefaultValue);
	}

	for (TSMN_PredictedProperty<FGameplayTag>& Property : MoveData_PredictedProperties_GameplayTag)
	{
		Property.Value.NetSerialize(Ar, PackageMap, bOut);
	}

	for (TSMN_PredictedProperty<FGameplayTagContainer>& Property : MoveData_PredictedProperties_GameplayTagContainer)
	{
		Property.Value.NetSerialize(Ar, PackageMap, bOut);
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

	for (TSMN_PredictedProperty<FVector>& VectorProperty : SavedPredictedProperties_Vector)
	{
		VectorProperty.Value = FVector::ZeroVector;
	}

	for (TSMN_PredictedProperty<FVector2D>& Vector2DProperty : SavedPredictedProperties_Vector2D)
	{
		Vector2DProperty.Value = FVector2D::ZeroVector;
	}

	for (TSMN_PredictedProperty<FVector4>& Vector4Property : SavedPredictedProperties_Vector4)
	{
		Vector4Property.Value = FVector4::Zero();
	}

	for (TSMN_PredictedProperty<FQuat>& QuatProperty : SavedPredictedProperties_Quat)
	{
		QuatProperty.Value = FQuat::Identity;
	}

	for (TSMN_PredictedProperty<FRotator>& RotatorProperty : SavedPredictedProperties_Rotator)
	{
		RotatorProperty.Value = FRotator::ZeroRotator;
	}

	for (TSMN_PredictedProperty<uint8>& ByteProperty : SavedPredictedProperties_Byte)
	{
		ByteProperty.Value = 0;
	}

	for (TSMN_PredictedProperty<FGameplayTag>& GameplayTagProperty : SavedPredictedProperties_GameplayTag)
	{
		GameplayTagProperty.Value = FGameplayTag::EmptyTag;
	}

	for (TSMN_PredictedProperty<FGameplayTagContainer>& GameplayTagContainerProperty : SavedPredictedProperties_GameplayTagContainer)
	{
		GameplayTagContainerProperty.Value = FGameplayTagContainer::EmptyContainer;
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

	if (SavedPredictedProperties_GameplayTagContainer != NewSMNMove->SavedPredictedProperties_GameplayTagContainer)
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

		for (TSMN_PredictedProperty<FVector>& VectorProperty : SMNCharacterMovement->PredictedProperties_Vector)
		{
			if (const FStructProperty* VectorPropertyPtr = CastField<FStructProperty>(SMNCharacterMovement->GetClass()->FindPropertyByName(VectorProperty.PropertyName)))
			{;
				VectorProperty.Value = *VectorPropertyPtr->ContainerPtrToValuePtr<FVector>(SMNCharacterMovement);
			}
		}

		for (TSMN_PredictedProperty<FVector2D>& Vector2DProperty : SMNCharacterMovement->PredictedProperties_Vector2D)
		{
			if (const FStructProperty* Vector2DPropertyPtr = CastField<FStructProperty>(SMNCharacterMovement->GetClass()->FindPropertyByName(Vector2DProperty.PropertyName)))
			{
				Vector2DProperty.Value = *Vector2DPropertyPtr->ContainerPtrToValuePtr<FVector2D>(SMNCharacterMovement);
			}
		}

		for (TSMN_PredictedProperty<FVector4>& Vector4Property : SMNCharacterMovement->PredictedProperties_Vector4)
		{
			if (const FStructProperty* Vector4PropertyPtr = CastField<FStructProperty>(SMNCharacterMovement->GetClass()->FindPropertyByName(Vector4Property.PropertyName)))
			{
				Vector4Property.Value = *Vector4PropertyPtr->ContainerPtrToValuePtr<FVector4>(SMNCharacterMovement);
			}
		}

		for (TSMN_PredictedProperty<FQuat>& QuatProperty : SMNCharacterMovement->PredictedProperties_Quat)
		{
			if (const FStructProperty* QuatPropertyPtr = CastField<FStructProperty>(SMNCharacterMovement->GetClass()->FindPropertyByName(QuatProperty.PropertyName)))
			{
				QuatProperty.Value = *QuatPropertyPtr->ContainerPtrToValuePtr<FQuat>(SMNCharacterMovement);
			}
		}

		for (TSMN_PredictedProperty<FRotator>& RotatorProperty : SMNCharacterMovement->PredictedProperties_Rotator)
		{
			if (const FStructProperty* RotatorPropertyPtr = CastField<FStructProperty>(SMNCharacterMovement->GetClass()->FindPropertyByName(RotatorProperty.PropertyName)))
			{
				RotatorProperty.Value = *RotatorPropertyPtr->ContainerPtrToValuePtr<FRotator>(SMNCharacterMovement);
			}
		}

		for (TSMN_PredictedProperty<uint8>& ByteProperty : SMNCharacterMovement->PredictedProperties_Byte)
		{
			if (const FByteProperty* BytePropertyPtr = Cast<FByteProperty>(SMNCharacterMovement->GetClass()->FindPropertyByName(ByteProperty.PropertyName)))
			{
				const void* ValuePtr = BytePropertyPtr->ContainerPtrToValuePtr<void>(SMNCharacterMovement);
				const uint8 Value = BytePropertyPtr->GetPropertyValue(ValuePtr);
				ByteProperty.Value = Value;
			}
		}

		for (TSMN_PredictedProperty<FGameplayTag>& GameplayTagProperty : SMNCharacterMovement->PredictedProperties_GameplayTag)
		{
			if (const FStructProperty* GameplayTagPropertyPtr = CastField<FStructProperty>(SMNCharacterMovement->GetClass()->FindPropertyByName(GameplayTagProperty.PropertyName)))
			{
				GameplayTagProperty.Value = *GameplayTagPropertyPtr->ContainerPtrToValuePtr<FGameplayTag>(SMNCharacterMovement);
			}
		}

		for (TSMN_PredictedProperty<FGameplayTagContainer>& GameplayTagContainerProperty : SMNCharacterMovement->PredictedProperties_GameplayTagContainer)
		{
			if (const FStructProperty* GameplayTagContainerPropertyPtr = CastField<FStructProperty>(SMNCharacterMovement->GetClass()->FindPropertyByName(GameplayTagContainerProperty.PropertyName)))
			{
				GameplayTagContainerProperty.Value = *GameplayTagContainerPropertyPtr->ContainerPtrToValuePtr<FGameplayTagContainer>(SMNCharacterMovement);
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
			if (const FByteProperty* BytePropertyPtr = Cast<FByteProperty>(SMNCharacterMovement->GetClass()->FindPropertyByName(ByteProperty.PropertyName)))
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

		for (TSMN_PredictedProperty<FGameplayTagContainer>& GameplayTagContainerProperty : SavedPredictedProperties_GameplayTagContainer)
		{
			if (const FStructProperty* GameplayTagContainerPropertyPtr = CastField<FStructProperty>(SMNCharacterMovement->GetClass()->FindPropertyByName(GameplayTagContainerProperty.PropertyName)))
			{
				GameplayTagContainerPropertyPtr->SetValue_InContainer(SMNCharacterMovement, &GameplayTagContainerProperty.Value);
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

		for (TSMN_PredictedProperty<FVector>& VectorProperty : PredictedProperties_Vector)
		{
			if (const FStructProperty* VectorPropertyPtr = CastField<FStructProperty>(
				GetClass()->FindPropertyByName(VectorProperty.PropertyName)))
			{
				VectorPropertyPtr->SetValue_InContainer(this, &VectorProperty.Value);
			}
		}

		for (TSMN_PredictedProperty<FVector2D>& Vector2DProperty : PredictedProperties_Vector2D)
		{
			if (const FStructProperty* Vector2DPropertyPtr = CastField<FStructProperty>(
				GetClass()->FindPropertyByName(Vector2DProperty.PropertyName)))
			{
				Vector2DPropertyPtr->SetValue_InContainer(this, &Vector2DProperty.Value);
			}
		}

		for (TSMN_PredictedProperty<FVector4>& Vector4Property : PredictedProperties_Vector4)
		{
			if (const FStructProperty* Vector4PropertyPtr = CastField<FStructProperty>(
				GetClass()->FindPropertyByName(Vector4Property.PropertyName)))
			{
				Vector4PropertyPtr->SetValue_InContainer(this, &Vector4Property.Value);
			}
		}

		for (TSMN_PredictedProperty<FRotator>& RotatorProperty : PredictedProperties_Rotator)
		{
			if (const FStructProperty* RotatorPropertyPtr = CastField<FStructProperty>(
				GetClass()->FindPropertyByName(RotatorProperty.PropertyName)))
			{
				RotatorPropertyPtr->SetValue_InContainer(this, &RotatorProperty.Value);
			}
		}

		for (TSMN_PredictedProperty<FQuat>& QuatProperty : PredictedProperties_Quat)
		{
			if (const FStructProperty* QuatPropertyPtr = CastField<FStructProperty>(
				GetClass()->FindPropertyByName(QuatProperty.PropertyName)))
			{
				QuatPropertyPtr->SetValue_InContainer(this, &QuatProperty.Value);
			}
		}

		for (TSMN_PredictedProperty<uint8>& ByteProperty : PredictedProperties_Byte)
		{
			if (const FByteProperty* BytePropertyPtr = Cast<FByteProperty>(
				GetClass()->FindPropertyByName(ByteProperty.PropertyName)))
			{
				void* ValuePtr = BytePropertyPtr->ContainerPtrToValuePtr<void>(this);
				BytePropertyPtr->SetPropertyValue(ValuePtr, ByteProperty.Value);
			}
		}

		for (TSMN_PredictedProperty<FGameplayTag>& GameplayTagProperty : PredictedProperties_GameplayTag)
		{
			if (const FStructProperty* GameplayTagPropertyPtr = CastField<FStructProperty>(
				GetClass()->FindPropertyByName(GameplayTagProperty.PropertyName)))
			{
				GameplayTagPropertyPtr->SetValue_InContainer(this, &GameplayTagProperty.Value);
			}
		}

		for (TSMN_PredictedProperty<FGameplayTagContainer>& GameplayTagContainerProperty : PredictedProperties_GameplayTagContainer)
		{
			if (const FStructProperty* GameplayTagContainerPropertyPtr = CastField<FStructProperty>(
				GetClass()->FindPropertyByName(GameplayTagContainerProperty.PropertyName)))
			{
				GameplayTagContainerPropertyPtr->SetValue_InContainer(this, &GameplayTagContainerProperty.Value);
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

void USMNCharacterMovementComponent::AddPredictedProperty_Rotator(FName PropertyName, FRotator DefaultValue)
{
	TSMN_PredictedProperty<FRotator> NewProperty;
	NewProperty.PropertyName = PropertyName;
	NewProperty.DefaultValue = DefaultValue;
	PredictedProperties_Rotator.Add(NewProperty);
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

void USMNCharacterMovementComponent::K2_Construction_Implementation()
{
	
}

void USMNCharacterMovementComponent::PostInitProperties()
{
	Super::PostInitProperties();

	K2_Construction(); 
}

void USMNCharacterMovementComponent::K2_OnMovementUpdated_Implementation(float DeltaTime, const FVector OldLocation,
	const FVector OldVelocity)
{
	Super::OnMovementUpdated(DeltaTime, OldLocation, OldVelocity);
}

void USMNCharacterMovementComponent::OnMovementUpdated(float DeltaSeconds, const FVector& OldLocation, const FVector& OldVelocity)
{
	K2_OnMovementUpdated(DeltaSeconds, OldLocation, OldVelocity);
}

void USMNCharacterMovementComponent::K2_OnMovementModeChanged_Implementation(EMovementMode PrevMovementMode, uint8 PreviousCustomMode)
{
	
}

void USMNCharacterMovementComponent::OnMovementModeChanged(EMovementMode PreviousMovementMode, uint8 PreviousCustomMode)
{
	Super::OnMovementModeChanged(PreviousMovementMode, PreviousCustomMode);
	
	K2_OnMovementModeChanged(PreviousMovementMode, PreviousCustomMode);
}

float USMNCharacterMovementComponent::K2_GetMaxSpeed_Implementation() const
{
	return Super::GetMaxSpeed();
}

float USMNCharacterMovementComponent::GetMaxSpeed() const
{
	return K2_GetMaxSpeed();
}

float USMNCharacterMovementComponent::K2_GetMaxAcceleration_Implementation() const
{
	return Super::GetMaxAcceleration();
}

float USMNCharacterMovementComponent::GetMaxAcceleration() const
{
	return K2_GetMaxAcceleration();
}

float USMNCharacterMovementComponent::K2_GetMaxBrakingDeceleration_Implementation() const
{
	return Super::GetMaxBrakingDeceleration();
}

float USMNCharacterMovementComponent::GetMaxBrakingDeceleration() const
{
	return K2_GetMaxBrakingDeceleration();
}

float USMNCharacterMovementComponent::K2_GetGravityZ_Implementation() const
{
	return Super::GetGravityZ();
}

float USMNCharacterMovementComponent::GetGravityZ() const
{
	return K2_GetGravityZ();
}

float USMNCharacterMovementComponent::K2_GetMaxJumpHeight_Implementation() const
{
	return Super::GetMaxJumpHeight();
}

float USMNCharacterMovementComponent::GetMaxJumpHeight() const
{
	return K2_GetMaxJumpHeight();
}

bool USMNCharacterMovementComponent::K2_ShouldCorrectRotation_Implementation() const
{
	return Super::ShouldCorrectRotation();
}

bool USMNCharacterMovementComponent::ShouldCorrectRotation() const
{
	return K2_ShouldCorrectRotation();
}

bool USMNCharacterMovementComponent::K2_ShouldCatchAir_Implementation(const FFindFloorResult OldFloor, const FFindFloorResult NewFloor)
{
	return Super::ShouldCatchAir(OldFloor, NewFloor);
}

bool USMNCharacterMovementComponent::ShouldCatchAir(const FFindFloorResult& OldFloor, const FFindFloorResult& NewFloor)
{
	return K2_ShouldCatchAir(OldFloor, NewFloor);
}

bool USMNCharacterMovementComponent::K2_CanAttemptJump_Implementation() const
{
	return Super::CanAttemptJump();
}

bool USMNCharacterMovementComponent::CanAttemptJump() const
{
	return K2_CanAttemptJump();
}

void USMNCharacterMovementComponent::K2_StartFalling_Implementation(int32 Iterations, float remainingTime, float timeTick, const FVector Delta, const FVector subLoc)
{
	Super::StartFalling(Iterations, remainingTime, timeTick, Delta, subLoc);
}

void USMNCharacterMovementComponent::StartFalling(int32 Iterations, float remainingTime, float timeTick, const FVector& Delta, const FVector& subLoc)
{
	K2_StartFalling(Iterations, remainingTime, timeTick, Delta, subLoc);
}

void USMNCharacterMovementComponent::K2_HandleWalkingOffLedge_Implementation(const FVector& PreviousFloorImpactNormal, const FVector& PreviousFloorContactNormal, const FVector& PreviousLocation, float TimeDelta)
{
	Super::HandleWalkingOffLedge(PreviousFloorImpactNormal, PreviousFloorContactNormal, PreviousLocation, TimeDelta);
}

void USMNCharacterMovementComponent::HandleWalkingOffLedge(const FVector& PreviousFloorImpactNormal, const FVector& PreviousFloorContactNormal, const FVector& PreviousLocation, float TimeDelta)
{
	K2_HandleWalkingOffLedge(PreviousFloorImpactNormal, PreviousFloorContactNormal, PreviousLocation, TimeDelta);
}

void USMNCharacterMovementComponent::K2_PhysWalking_Implementation(float deltaTime, int32 Iterations)
{
	Super::PhysWalking(deltaTime, Iterations);
}

void USMNCharacterMovementComponent::PhysWalking(float deltaTime, int32 Iterations)
{
	K2_PhysWalking(deltaTime, Iterations);
}

void USMNCharacterMovementComponent::K2_PhysFalling_Implementation(float deltaTime, int32 Iterations)
{
	Super::PhysFalling(deltaTime, Iterations);
}

void USMNCharacterMovementComponent::PhysFalling(float deltaTime, int32 Iterations)
{
	K2_PhysFalling(deltaTime, Iterations);
}

void USMNCharacterMovementComponent::K2_PhysSwimming_Implementation(float deltaTime, int32 Iterations)
{
	Super::PhysSwimming(deltaTime, Iterations);
}

void USMNCharacterMovementComponent::PhysSwimming(float deltaTime, int32 Iterations)
{
	K2_PhysSwimming(deltaTime, Iterations);
}

void USMNCharacterMovementComponent::K2_PhysFlying_Implementation(float deltaTime, int32 Iterations)
{
	Super::PhysFlying(deltaTime, Iterations);
}

void USMNCharacterMovementComponent::PhysFlying(float deltaTime, int32 Iterations)
{
	K2_PhysFlying(deltaTime, Iterations);
}

void USMNCharacterMovementComponent::K2_PhysCustom_Implementation(float deltaTime, int32 Iterations)
{
	Super::PhysCustom(deltaTime, Iterations);
}

void USMNCharacterMovementComponent::PhysCustom(float deltaTime, int32 Iterations)
{
	K2_PhysCustom(deltaTime, Iterations);
}

float USMNCharacterMovementComponent::K2_SlideAlongSurface_Implementation(const FVector& Delta, float Time, const FVector& Normal, FHitResult& Hit, bool bHandleImpact)
{
	return Super::SlideAlongSurface(Delta, Time, Normal, Hit, bHandleImpact);
}

float USMNCharacterMovementComponent::SlideAlongSurface(const FVector& Delta, float Time, const FVector& Normal,
                                                        FHitResult& Hit, bool bHandleImpact)
{
	return K2_SlideAlongSurface(Delta, Time, Normal, Hit, bHandleImpact);
}

void USMNCharacterMovementComponent::K2_TwoWallAdjust_Implementation(FVector& Delta, const FHitResult Hit, const FVector OldHitNormal) const
{
	Super::TwoWallAdjust(Delta, Hit, OldHitNormal);
}

void USMNCharacterMovementComponent::TwoWallAdjust(FVector& Delta, const FHitResult& Hit,
	const FVector& OldHitNormal) const
{
	K2_TwoWallAdjust(Delta, Hit, OldHitNormal);
}

void USMNCharacterMovementComponent::K2_AdjustFloorHeight_Implementation()
{
	Super::AdjustFloorHeight();
}

void USMNCharacterMovementComponent::AdjustFloorHeight()
{
	K2_AdjustFloorHeight();
}

void USMNCharacterMovementComponent::K2_CalcVelocity_Implementation(float deltaTime, float Friction, bool bFluid, float BrakingDeceleration)
{
	Super::CalcVelocity(deltaTime, Friction, bFluid, BrakingDeceleration);
}

void USMNCharacterMovementComponent::CalcVelocity(float deltaTime, float Friction, bool bFluid, float BrakingDeceleration)
{
	K2_CalcVelocity(deltaTime, Friction, bFluid, BrakingDeceleration);
}

void USMNCharacterMovementComponent::K2_PerformMovement_Implementation(float deltaTime)
{
	Super::PerformMovement(deltaTime);
}

void USMNCharacterMovementComponent::PerformMovement(float deltaTime)
{
	K2_PerformMovement(deltaTime);
}

void USMNCharacterMovementComponent::K2_SimulateMovement_Implementation(float deltaTime)
{
	Super::SimulateMovement(deltaTime);
}

void USMNCharacterMovementComponent::SimulateMovement(float deltaTime)
{
	K2_SimulateMovement(deltaTime);
}

