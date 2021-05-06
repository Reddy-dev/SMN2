// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "MultiplayerMovementPlugin/Public/MyCharacterMovementComponent.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeMyCharacterMovementComponent() {}
// Cross Module References
	MULTIPLAYERMOVEMENTPLUGIN_API UClass* Z_Construct_UClass_UMyCharacterMovementComponent_NoRegister();
	MULTIPLAYERMOVEMENTPLUGIN_API UClass* Z_Construct_UClass_UMyCharacterMovementComponent();
	ENGINE_API UClass* Z_Construct_UClass_UCharacterMovementComponent();
	UPackage* Z_Construct_UPackage__Script_MultiplayerMovementPlugin();
	ENGINE_API UEnum* Z_Construct_UEnum_Engine_EMovementMode();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector();
// End Cross Module References
	DEFINE_FUNCTION(UMyCharacterMovementComponent::execSetMovementModeRep)
	{
		P_GET_PROPERTY(FByteProperty,Z_Param_NewMovementMode);
		P_GET_PROPERTY(FByteProperty,Z_Param_NewCustomMovementMode);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->SetMovementModeRep(EMovementMode(Z_Param_NewMovementMode),Z_Param_NewCustomMovementMode);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UMyCharacterMovementComponent::execServerSetMovementMode)
	{
		P_GET_PROPERTY(FByteProperty,Z_Param_NewMovementMode);
		P_GET_PROPERTY(FByteProperty,Z_Param_NewCustomMovementMode);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->ServerSetMovementMode_Implementation(EMovementMode(Z_Param_NewMovementMode),Z_Param_NewCustomMovementMode);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UMyCharacterMovementComponent::execClientSetMovementMode)
	{
		P_GET_PROPERTY(FByteProperty,Z_Param_NewMovementMode);
		P_GET_PROPERTY(FByteProperty,Z_Param_NewCustomMovementMode);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->ClientSetMovementMode_Implementation(EMovementMode(Z_Param_NewMovementMode),Z_Param_NewCustomMovementMode);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UMyCharacterMovementComponent::execSafeMoveUpdatedLocation)
	{
		P_GET_STRUCT(FVector,Z_Param_NewLocation);
		P_GET_UBOOL(Z_Param_Sweep);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->SafeMoveUpdatedLocation(Z_Param_NewLocation,Z_Param_Sweep);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UMyCharacterMovementComponent::execSafeMoveUpdatedVelocity)
	{
		P_GET_PROPERTY(FFloatProperty,Z_Param_DeltaTime);
		P_GET_UBOOL(Z_Param_Sweep);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->SafeMoveUpdatedVelocity(Z_Param_DeltaTime,Z_Param_Sweep);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UMyCharacterMovementComponent::execLaunchCharacterReplicated)
	{
		P_GET_STRUCT(FVector,Z_Param_NewLaunchVelocity);
		P_GET_UBOOL(Z_Param_bXYOverride);
		P_GET_UBOOL(Z_Param_bZOverride);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->LaunchCharacterReplicated(Z_Param_NewLaunchVelocity,Z_Param_bXYOverride,Z_Param_bZOverride);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UMyCharacterMovementComponent::execSetMaxSpeedCrouched)
	{
		P_GET_PROPERTY(FFloatProperty,Z_Param_NewCrouchSpeed);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->SetMaxSpeedCrouched(Z_Param_NewCrouchSpeed);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UMyCharacterMovementComponent::execStopNewMovementMode)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->StopNewMovementMode();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UMyCharacterMovementComponent::execSetCrouchedHalfHeight)
	{
		P_GET_PROPERTY(FFloatProperty,Z_Param_NewCrouchedHalfHeight);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->SetCrouchedHalfHeight(Z_Param_NewCrouchedHalfHeight);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UMyCharacterMovementComponent::execSetAirControl)
	{
		P_GET_PROPERTY(FFloatProperty,Z_Param_NewAirControl);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->SetAirControl(Z_Param_NewAirControl);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UMyCharacterMovementComponent::execSetMaxJumpHeight)
	{
		P_GET_PROPERTY(FFloatProperty,Z_Param_NewJumpHeight);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->SetMaxJumpHeight(Z_Param_NewJumpHeight);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UMyCharacterMovementComponent::execSetMaxAcceleration)
	{
		P_GET_PROPERTY(FFloatProperty,Z_Param_NewAcceleration);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->SetMaxAcceleration(Z_Param_NewAcceleration);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UMyCharacterMovementComponent::execSetPlaneConstraintReplicated)
	{
		P_GET_STRUCT(FVector,Z_Param_NewPlaneConstraint);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->SetPlaneConstraintReplicated(Z_Param_NewPlaneConstraint);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UMyCharacterMovementComponent::execSetMaxGravity)
	{
		P_GET_PROPERTY(FFloatProperty,Z_Param_NewMaxGravity);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->SetMaxGravity(Z_Param_NewMaxGravity);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UMyCharacterMovementComponent::execSetGroundFriction)
	{
		P_GET_PROPERTY(FFloatProperty,Z_Param_NewGroundFriction);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->SetGroundFriction(Z_Param_NewGroundFriction);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UMyCharacterMovementComponent::execSetMaxGroundSpeed)
	{
		P_GET_PROPERTY(FFloatProperty,Z_Param_NewMaxGroundSpeed);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->SetMaxGroundSpeed(Z_Param_NewMaxGroundSpeed);
		P_NATIVE_END;
	}
	static FName NAME_UMyCharacterMovementComponent_ClientSetMovementMode = FName(TEXT("ClientSetMovementMode"));
	void UMyCharacterMovementComponent::ClientSetMovementMode(EMovementMode NewMovementMode, uint8 NewCustomMovementMode)
	{
		MyCharacterMovementComponent_eventClientSetMovementMode_Parms Parms;
		Parms.NewMovementMode=NewMovementMode;
		Parms.NewCustomMovementMode=NewCustomMovementMode;
		ProcessEvent(FindFunctionChecked(NAME_UMyCharacterMovementComponent_ClientSetMovementMode),&Parms);
	}
	static FName NAME_UMyCharacterMovementComponent_ServerSetMovementMode = FName(TEXT("ServerSetMovementMode"));
	void UMyCharacterMovementComponent::ServerSetMovementMode(EMovementMode NewMovementMode, uint8 NewCustomMovementMode)
	{
		MyCharacterMovementComponent_eventServerSetMovementMode_Parms Parms;
		Parms.NewMovementMode=NewMovementMode;
		Parms.NewCustomMovementMode=NewCustomMovementMode;
		ProcessEvent(FindFunctionChecked(NAME_UMyCharacterMovementComponent_ServerSetMovementMode),&Parms);
	}
	void UMyCharacterMovementComponent::StaticRegisterNativesUMyCharacterMovementComponent()
	{
		UClass* Class = UMyCharacterMovementComponent::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "ClientSetMovementMode", &UMyCharacterMovementComponent::execClientSetMovementMode },
			{ "LaunchCharacterReplicated", &UMyCharacterMovementComponent::execLaunchCharacterReplicated },
			{ "SafeMoveUpdatedLocation", &UMyCharacterMovementComponent::execSafeMoveUpdatedLocation },
			{ "SafeMoveUpdatedVelocity", &UMyCharacterMovementComponent::execSafeMoveUpdatedVelocity },
			{ "ServerSetMovementMode", &UMyCharacterMovementComponent::execServerSetMovementMode },
			{ "SetAirControl", &UMyCharacterMovementComponent::execSetAirControl },
			{ "SetCrouchedHalfHeight", &UMyCharacterMovementComponent::execSetCrouchedHalfHeight },
			{ "SetGroundFriction", &UMyCharacterMovementComponent::execSetGroundFriction },
			{ "SetMaxAcceleration", &UMyCharacterMovementComponent::execSetMaxAcceleration },
			{ "SetMaxGravity", &UMyCharacterMovementComponent::execSetMaxGravity },
			{ "SetMaxGroundSpeed", &UMyCharacterMovementComponent::execSetMaxGroundSpeed },
			{ "SetMaxJumpHeight", &UMyCharacterMovementComponent::execSetMaxJumpHeight },
			{ "SetMaxSpeedCrouched", &UMyCharacterMovementComponent::execSetMaxSpeedCrouched },
			{ "SetMovementModeRep", &UMyCharacterMovementComponent::execSetMovementModeRep },
			{ "SetPlaneConstraintReplicated", &UMyCharacterMovementComponent::execSetPlaneConstraintReplicated },
			{ "StopNewMovementMode", &UMyCharacterMovementComponent::execStopNewMovementMode },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_UMyCharacterMovementComponent_ClientSetMovementMode_Statics
	{
		static const UE4CodeGen_Private::FBytePropertyParams NewProp_NewMovementMode;
		static const UE4CodeGen_Private::FBytePropertyParams NewProp_NewCustomMovementMode;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UMyCharacterMovementComponent_ClientSetMovementMode_Statics::NewProp_NewMovementMode = { "NewMovementMode", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(MyCharacterMovementComponent_eventClientSetMovementMode_Parms, NewMovementMode), Z_Construct_UEnum_Engine_EMovementMode, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UMyCharacterMovementComponent_ClientSetMovementMode_Statics::NewProp_NewCustomMovementMode = { "NewCustomMovementMode", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(MyCharacterMovementComponent_eventClientSetMovementMode_Parms, NewCustomMovementMode), nullptr, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UMyCharacterMovementComponent_ClientSetMovementMode_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMyCharacterMovementComponent_ClientSetMovementMode_Statics::NewProp_NewMovementMode,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMyCharacterMovementComponent_ClientSetMovementMode_Statics::NewProp_NewCustomMovementMode,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UMyCharacterMovementComponent_ClientSetMovementMode_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/MyCharacterMovementComponent.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UMyCharacterMovementComponent_ClientSetMovementMode_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UMyCharacterMovementComponent, nullptr, "ClientSetMovementMode", nullptr, nullptr, sizeof(MyCharacterMovementComponent_eventClientSetMovementMode_Parms), Z_Construct_UFunction_UMyCharacterMovementComponent_ClientSetMovementMode_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UMyCharacterMovementComponent_ClientSetMovementMode_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x01020CC0, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UMyCharacterMovementComponent_ClientSetMovementMode_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UMyCharacterMovementComponent_ClientSetMovementMode_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UMyCharacterMovementComponent_ClientSetMovementMode()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UMyCharacterMovementComponent_ClientSetMovementMode_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UMyCharacterMovementComponent_LaunchCharacterReplicated_Statics
	{
		struct MyCharacterMovementComponent_eventLaunchCharacterReplicated_Parms
		{
			FVector NewLaunchVelocity;
			bool bXYOverride;
			bool bZOverride;
		};
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_NewLaunchVelocity;
		static void NewProp_bXYOverride_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_bXYOverride;
		static void NewProp_bZOverride_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_bZOverride;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UMyCharacterMovementComponent_LaunchCharacterReplicated_Statics::NewProp_NewLaunchVelocity = { "NewLaunchVelocity", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(MyCharacterMovementComponent_eventLaunchCharacterReplicated_Parms, NewLaunchVelocity), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(nullptr, 0) };
	void Z_Construct_UFunction_UMyCharacterMovementComponent_LaunchCharacterReplicated_Statics::NewProp_bXYOverride_SetBit(void* Obj)
	{
		((MyCharacterMovementComponent_eventLaunchCharacterReplicated_Parms*)Obj)->bXYOverride = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UMyCharacterMovementComponent_LaunchCharacterReplicated_Statics::NewProp_bXYOverride = { "bXYOverride", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(MyCharacterMovementComponent_eventLaunchCharacterReplicated_Parms), &Z_Construct_UFunction_UMyCharacterMovementComponent_LaunchCharacterReplicated_Statics::NewProp_bXYOverride_SetBit, METADATA_PARAMS(nullptr, 0) };
	void Z_Construct_UFunction_UMyCharacterMovementComponent_LaunchCharacterReplicated_Statics::NewProp_bZOverride_SetBit(void* Obj)
	{
		((MyCharacterMovementComponent_eventLaunchCharacterReplicated_Parms*)Obj)->bZOverride = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UMyCharacterMovementComponent_LaunchCharacterReplicated_Statics::NewProp_bZOverride = { "bZOverride", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(MyCharacterMovementComponent_eventLaunchCharacterReplicated_Parms), &Z_Construct_UFunction_UMyCharacterMovementComponent_LaunchCharacterReplicated_Statics::NewProp_bZOverride_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UMyCharacterMovementComponent_LaunchCharacterReplicated_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMyCharacterMovementComponent_LaunchCharacterReplicated_Statics::NewProp_NewLaunchVelocity,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMyCharacterMovementComponent_LaunchCharacterReplicated_Statics::NewProp_bXYOverride,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMyCharacterMovementComponent_LaunchCharacterReplicated_Statics::NewProp_bZOverride,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UMyCharacterMovementComponent_LaunchCharacterReplicated_Statics::Function_MetaDataParams[] = {
		{ "Category", "Smooth Network Movement" },
		{ "ModuleRelativePath", "Public/MyCharacterMovementComponent.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UMyCharacterMovementComponent_LaunchCharacterReplicated_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UMyCharacterMovementComponent, nullptr, "LaunchCharacterReplicated", nullptr, nullptr, sizeof(MyCharacterMovementComponent_eventLaunchCharacterReplicated_Parms), Z_Construct_UFunction_UMyCharacterMovementComponent_LaunchCharacterReplicated_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UMyCharacterMovementComponent_LaunchCharacterReplicated_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04820401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UMyCharacterMovementComponent_LaunchCharacterReplicated_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UMyCharacterMovementComponent_LaunchCharacterReplicated_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UMyCharacterMovementComponent_LaunchCharacterReplicated()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UMyCharacterMovementComponent_LaunchCharacterReplicated_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UMyCharacterMovementComponent_SafeMoveUpdatedLocation_Statics
	{
		struct MyCharacterMovementComponent_eventSafeMoveUpdatedLocation_Parms
		{
			FVector NewLocation;
			bool Sweep;
		};
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_NewLocation_MetaData[];
#endif
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_NewLocation;
		static void NewProp_Sweep_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_Sweep;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UMyCharacterMovementComponent_SafeMoveUpdatedLocation_Statics::NewProp_NewLocation_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UMyCharacterMovementComponent_SafeMoveUpdatedLocation_Statics::NewProp_NewLocation = { "NewLocation", nullptr, (EPropertyFlags)0x0010000000000082, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(MyCharacterMovementComponent_eventSafeMoveUpdatedLocation_Parms, NewLocation), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(Z_Construct_UFunction_UMyCharacterMovementComponent_SafeMoveUpdatedLocation_Statics::NewProp_NewLocation_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_UMyCharacterMovementComponent_SafeMoveUpdatedLocation_Statics::NewProp_NewLocation_MetaData)) };
	void Z_Construct_UFunction_UMyCharacterMovementComponent_SafeMoveUpdatedLocation_Statics::NewProp_Sweep_SetBit(void* Obj)
	{
		((MyCharacterMovementComponent_eventSafeMoveUpdatedLocation_Parms*)Obj)->Sweep = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UMyCharacterMovementComponent_SafeMoveUpdatedLocation_Statics::NewProp_Sweep = { "Sweep", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(MyCharacterMovementComponent_eventSafeMoveUpdatedLocation_Parms), &Z_Construct_UFunction_UMyCharacterMovementComponent_SafeMoveUpdatedLocation_Statics::NewProp_Sweep_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UMyCharacterMovementComponent_SafeMoveUpdatedLocation_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMyCharacterMovementComponent_SafeMoveUpdatedLocation_Statics::NewProp_NewLocation,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMyCharacterMovementComponent_SafeMoveUpdatedLocation_Statics::NewProp_Sweep,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UMyCharacterMovementComponent_SafeMoveUpdatedLocation_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/MyCharacterMovementComponent.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UMyCharacterMovementComponent_SafeMoveUpdatedLocation_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UMyCharacterMovementComponent, nullptr, "SafeMoveUpdatedLocation", nullptr, nullptr, sizeof(MyCharacterMovementComponent_eventSafeMoveUpdatedLocation_Parms), Z_Construct_UFunction_UMyCharacterMovementComponent_SafeMoveUpdatedLocation_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UMyCharacterMovementComponent_SafeMoveUpdatedLocation_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00820401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UMyCharacterMovementComponent_SafeMoveUpdatedLocation_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UMyCharacterMovementComponent_SafeMoveUpdatedLocation_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UMyCharacterMovementComponent_SafeMoveUpdatedLocation()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UMyCharacterMovementComponent_SafeMoveUpdatedLocation_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UMyCharacterMovementComponent_SafeMoveUpdatedVelocity_Statics
	{
		struct MyCharacterMovementComponent_eventSafeMoveUpdatedVelocity_Parms
		{
			float DeltaTime;
			bool Sweep;
		};
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_DeltaTime;
		static void NewProp_Sweep_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_Sweep;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UMyCharacterMovementComponent_SafeMoveUpdatedVelocity_Statics::NewProp_DeltaTime = { "DeltaTime", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(MyCharacterMovementComponent_eventSafeMoveUpdatedVelocity_Parms, DeltaTime), METADATA_PARAMS(nullptr, 0) };
	void Z_Construct_UFunction_UMyCharacterMovementComponent_SafeMoveUpdatedVelocity_Statics::NewProp_Sweep_SetBit(void* Obj)
	{
		((MyCharacterMovementComponent_eventSafeMoveUpdatedVelocity_Parms*)Obj)->Sweep = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UMyCharacterMovementComponent_SafeMoveUpdatedVelocity_Statics::NewProp_Sweep = { "Sweep", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(MyCharacterMovementComponent_eventSafeMoveUpdatedVelocity_Parms), &Z_Construct_UFunction_UMyCharacterMovementComponent_SafeMoveUpdatedVelocity_Statics::NewProp_Sweep_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UMyCharacterMovementComponent_SafeMoveUpdatedVelocity_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMyCharacterMovementComponent_SafeMoveUpdatedVelocity_Statics::NewProp_DeltaTime,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMyCharacterMovementComponent_SafeMoveUpdatedVelocity_Statics::NewProp_Sweep,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UMyCharacterMovementComponent_SafeMoveUpdatedVelocity_Statics::Function_MetaDataParams[] = {
		{ "Category", "Smooth Network Movement" },
		{ "ModuleRelativePath", "Public/MyCharacterMovementComponent.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UMyCharacterMovementComponent_SafeMoveUpdatedVelocity_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UMyCharacterMovementComponent, nullptr, "SafeMoveUpdatedVelocity", nullptr, nullptr, sizeof(MyCharacterMovementComponent_eventSafeMoveUpdatedVelocity_Parms), Z_Construct_UFunction_UMyCharacterMovementComponent_SafeMoveUpdatedVelocity_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UMyCharacterMovementComponent_SafeMoveUpdatedVelocity_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UMyCharacterMovementComponent_SafeMoveUpdatedVelocity_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UMyCharacterMovementComponent_SafeMoveUpdatedVelocity_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UMyCharacterMovementComponent_SafeMoveUpdatedVelocity()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UMyCharacterMovementComponent_SafeMoveUpdatedVelocity_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UMyCharacterMovementComponent_ServerSetMovementMode_Statics
	{
		static const UE4CodeGen_Private::FBytePropertyParams NewProp_NewMovementMode;
		static const UE4CodeGen_Private::FBytePropertyParams NewProp_NewCustomMovementMode;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UMyCharacterMovementComponent_ServerSetMovementMode_Statics::NewProp_NewMovementMode = { "NewMovementMode", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(MyCharacterMovementComponent_eventServerSetMovementMode_Parms, NewMovementMode), Z_Construct_UEnum_Engine_EMovementMode, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UMyCharacterMovementComponent_ServerSetMovementMode_Statics::NewProp_NewCustomMovementMode = { "NewCustomMovementMode", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(MyCharacterMovementComponent_eventServerSetMovementMode_Parms, NewCustomMovementMode), nullptr, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UMyCharacterMovementComponent_ServerSetMovementMode_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMyCharacterMovementComponent_ServerSetMovementMode_Statics::NewProp_NewMovementMode,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMyCharacterMovementComponent_ServerSetMovementMode_Statics::NewProp_NewCustomMovementMode,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UMyCharacterMovementComponent_ServerSetMovementMode_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/MyCharacterMovementComponent.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UMyCharacterMovementComponent_ServerSetMovementMode_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UMyCharacterMovementComponent, nullptr, "ServerSetMovementMode", nullptr, nullptr, sizeof(MyCharacterMovementComponent_eventServerSetMovementMode_Parms), Z_Construct_UFunction_UMyCharacterMovementComponent_ServerSetMovementMode_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UMyCharacterMovementComponent_ServerSetMovementMode_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00220CC0, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UMyCharacterMovementComponent_ServerSetMovementMode_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UMyCharacterMovementComponent_ServerSetMovementMode_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UMyCharacterMovementComponent_ServerSetMovementMode()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UMyCharacterMovementComponent_ServerSetMovementMode_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UMyCharacterMovementComponent_SetAirControl_Statics
	{
		struct MyCharacterMovementComponent_eventSetAirControl_Parms
		{
			float NewAirControl;
		};
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_NewAirControl;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UMyCharacterMovementComponent_SetAirControl_Statics::NewProp_NewAirControl = { "NewAirControl", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(MyCharacterMovementComponent_eventSetAirControl_Parms, NewAirControl), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UMyCharacterMovementComponent_SetAirControl_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMyCharacterMovementComponent_SetAirControl_Statics::NewProp_NewAirControl,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UMyCharacterMovementComponent_SetAirControl_Statics::Function_MetaDataParams[] = {
		{ "Category", "Smooth Network Movement" },
		{ "ModuleRelativePath", "Public/MyCharacterMovementComponent.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UMyCharacterMovementComponent_SetAirControl_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UMyCharacterMovementComponent, nullptr, "SetAirControl", nullptr, nullptr, sizeof(MyCharacterMovementComponent_eventSetAirControl_Parms), Z_Construct_UFunction_UMyCharacterMovementComponent_SetAirControl_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UMyCharacterMovementComponent_SetAirControl_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UMyCharacterMovementComponent_SetAirControl_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UMyCharacterMovementComponent_SetAirControl_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UMyCharacterMovementComponent_SetAirControl()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UMyCharacterMovementComponent_SetAirControl_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UMyCharacterMovementComponent_SetCrouchedHalfHeight_Statics
	{
		struct MyCharacterMovementComponent_eventSetCrouchedHalfHeight_Parms
		{
			float NewCrouchedHalfHeight;
		};
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_NewCrouchedHalfHeight;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UMyCharacterMovementComponent_SetCrouchedHalfHeight_Statics::NewProp_NewCrouchedHalfHeight = { "NewCrouchedHalfHeight", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(MyCharacterMovementComponent_eventSetCrouchedHalfHeight_Parms, NewCrouchedHalfHeight), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UMyCharacterMovementComponent_SetCrouchedHalfHeight_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMyCharacterMovementComponent_SetCrouchedHalfHeight_Statics::NewProp_NewCrouchedHalfHeight,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UMyCharacterMovementComponent_SetCrouchedHalfHeight_Statics::Function_MetaDataParams[] = {
		{ "Category", "Smooth Network Movement" },
		{ "ModuleRelativePath", "Public/MyCharacterMovementComponent.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UMyCharacterMovementComponent_SetCrouchedHalfHeight_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UMyCharacterMovementComponent, nullptr, "SetCrouchedHalfHeight", nullptr, nullptr, sizeof(MyCharacterMovementComponent_eventSetCrouchedHalfHeight_Parms), Z_Construct_UFunction_UMyCharacterMovementComponent_SetCrouchedHalfHeight_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UMyCharacterMovementComponent_SetCrouchedHalfHeight_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UMyCharacterMovementComponent_SetCrouchedHalfHeight_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UMyCharacterMovementComponent_SetCrouchedHalfHeight_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UMyCharacterMovementComponent_SetCrouchedHalfHeight()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UMyCharacterMovementComponent_SetCrouchedHalfHeight_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UMyCharacterMovementComponent_SetGroundFriction_Statics
	{
		struct MyCharacterMovementComponent_eventSetGroundFriction_Parms
		{
			float NewGroundFriction;
		};
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_NewGroundFriction;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UMyCharacterMovementComponent_SetGroundFriction_Statics::NewProp_NewGroundFriction = { "NewGroundFriction", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(MyCharacterMovementComponent_eventSetGroundFriction_Parms, NewGroundFriction), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UMyCharacterMovementComponent_SetGroundFriction_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMyCharacterMovementComponent_SetGroundFriction_Statics::NewProp_NewGroundFriction,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UMyCharacterMovementComponent_SetGroundFriction_Statics::Function_MetaDataParams[] = {
		{ "Category", "Smooth Network Movement" },
		{ "ModuleRelativePath", "Public/MyCharacterMovementComponent.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UMyCharacterMovementComponent_SetGroundFriction_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UMyCharacterMovementComponent, nullptr, "SetGroundFriction", nullptr, nullptr, sizeof(MyCharacterMovementComponent_eventSetGroundFriction_Parms), Z_Construct_UFunction_UMyCharacterMovementComponent_SetGroundFriction_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UMyCharacterMovementComponent_SetGroundFriction_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UMyCharacterMovementComponent_SetGroundFriction_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UMyCharacterMovementComponent_SetGroundFriction_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UMyCharacterMovementComponent_SetGroundFriction()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UMyCharacterMovementComponent_SetGroundFriction_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UMyCharacterMovementComponent_SetMaxAcceleration_Statics
	{
		struct MyCharacterMovementComponent_eventSetMaxAcceleration_Parms
		{
			float NewAcceleration;
		};
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_NewAcceleration;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UMyCharacterMovementComponent_SetMaxAcceleration_Statics::NewProp_NewAcceleration = { "NewAcceleration", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(MyCharacterMovementComponent_eventSetMaxAcceleration_Parms, NewAcceleration), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UMyCharacterMovementComponent_SetMaxAcceleration_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMyCharacterMovementComponent_SetMaxAcceleration_Statics::NewProp_NewAcceleration,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UMyCharacterMovementComponent_SetMaxAcceleration_Statics::Function_MetaDataParams[] = {
		{ "Category", "Smooth Network Movement" },
		{ "ModuleRelativePath", "Public/MyCharacterMovementComponent.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UMyCharacterMovementComponent_SetMaxAcceleration_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UMyCharacterMovementComponent, nullptr, "SetMaxAcceleration", nullptr, nullptr, sizeof(MyCharacterMovementComponent_eventSetMaxAcceleration_Parms), Z_Construct_UFunction_UMyCharacterMovementComponent_SetMaxAcceleration_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UMyCharacterMovementComponent_SetMaxAcceleration_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UMyCharacterMovementComponent_SetMaxAcceleration_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UMyCharacterMovementComponent_SetMaxAcceleration_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UMyCharacterMovementComponent_SetMaxAcceleration()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UMyCharacterMovementComponent_SetMaxAcceleration_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UMyCharacterMovementComponent_SetMaxGravity_Statics
	{
		struct MyCharacterMovementComponent_eventSetMaxGravity_Parms
		{
			float NewMaxGravity;
		};
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_NewMaxGravity;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UMyCharacterMovementComponent_SetMaxGravity_Statics::NewProp_NewMaxGravity = { "NewMaxGravity", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(MyCharacterMovementComponent_eventSetMaxGravity_Parms, NewMaxGravity), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UMyCharacterMovementComponent_SetMaxGravity_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMyCharacterMovementComponent_SetMaxGravity_Statics::NewProp_NewMaxGravity,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UMyCharacterMovementComponent_SetMaxGravity_Statics::Function_MetaDataParams[] = {
		{ "Category", "Smooth Network Movement" },
		{ "ModuleRelativePath", "Public/MyCharacterMovementComponent.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UMyCharacterMovementComponent_SetMaxGravity_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UMyCharacterMovementComponent, nullptr, "SetMaxGravity", nullptr, nullptr, sizeof(MyCharacterMovementComponent_eventSetMaxGravity_Parms), Z_Construct_UFunction_UMyCharacterMovementComponent_SetMaxGravity_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UMyCharacterMovementComponent_SetMaxGravity_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UMyCharacterMovementComponent_SetMaxGravity_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UMyCharacterMovementComponent_SetMaxGravity_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UMyCharacterMovementComponent_SetMaxGravity()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UMyCharacterMovementComponent_SetMaxGravity_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UMyCharacterMovementComponent_SetMaxGroundSpeed_Statics
	{
		struct MyCharacterMovementComponent_eventSetMaxGroundSpeed_Parms
		{
			float NewMaxGroundSpeed;
		};
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_NewMaxGroundSpeed;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UMyCharacterMovementComponent_SetMaxGroundSpeed_Statics::NewProp_NewMaxGroundSpeed = { "NewMaxGroundSpeed", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(MyCharacterMovementComponent_eventSetMaxGroundSpeed_Parms, NewMaxGroundSpeed), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UMyCharacterMovementComponent_SetMaxGroundSpeed_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMyCharacterMovementComponent_SetMaxGroundSpeed_Statics::NewProp_NewMaxGroundSpeed,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UMyCharacterMovementComponent_SetMaxGroundSpeed_Statics::Function_MetaDataParams[] = {
		{ "Category", "Smooth Network Movement" },
		{ "ModuleRelativePath", "Public/MyCharacterMovementComponent.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UMyCharacterMovementComponent_SetMaxGroundSpeed_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UMyCharacterMovementComponent, nullptr, "SetMaxGroundSpeed", nullptr, nullptr, sizeof(MyCharacterMovementComponent_eventSetMaxGroundSpeed_Parms), Z_Construct_UFunction_UMyCharacterMovementComponent_SetMaxGroundSpeed_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UMyCharacterMovementComponent_SetMaxGroundSpeed_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UMyCharacterMovementComponent_SetMaxGroundSpeed_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UMyCharacterMovementComponent_SetMaxGroundSpeed_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UMyCharacterMovementComponent_SetMaxGroundSpeed()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UMyCharacterMovementComponent_SetMaxGroundSpeed_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UMyCharacterMovementComponent_SetMaxJumpHeight_Statics
	{
		struct MyCharacterMovementComponent_eventSetMaxJumpHeight_Parms
		{
			float NewJumpHeight;
		};
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_NewJumpHeight;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UMyCharacterMovementComponent_SetMaxJumpHeight_Statics::NewProp_NewJumpHeight = { "NewJumpHeight", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(MyCharacterMovementComponent_eventSetMaxJumpHeight_Parms, NewJumpHeight), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UMyCharacterMovementComponent_SetMaxJumpHeight_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMyCharacterMovementComponent_SetMaxJumpHeight_Statics::NewProp_NewJumpHeight,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UMyCharacterMovementComponent_SetMaxJumpHeight_Statics::Function_MetaDataParams[] = {
		{ "Category", "Smooth Network Movement" },
		{ "ModuleRelativePath", "Public/MyCharacterMovementComponent.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UMyCharacterMovementComponent_SetMaxJumpHeight_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UMyCharacterMovementComponent, nullptr, "SetMaxJumpHeight", nullptr, nullptr, sizeof(MyCharacterMovementComponent_eventSetMaxJumpHeight_Parms), Z_Construct_UFunction_UMyCharacterMovementComponent_SetMaxJumpHeight_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UMyCharacterMovementComponent_SetMaxJumpHeight_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UMyCharacterMovementComponent_SetMaxJumpHeight_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UMyCharacterMovementComponent_SetMaxJumpHeight_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UMyCharacterMovementComponent_SetMaxJumpHeight()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UMyCharacterMovementComponent_SetMaxJumpHeight_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UMyCharacterMovementComponent_SetMaxSpeedCrouched_Statics
	{
		struct MyCharacterMovementComponent_eventSetMaxSpeedCrouched_Parms
		{
			float NewCrouchSpeed;
		};
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_NewCrouchSpeed;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UMyCharacterMovementComponent_SetMaxSpeedCrouched_Statics::NewProp_NewCrouchSpeed = { "NewCrouchSpeed", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(MyCharacterMovementComponent_eventSetMaxSpeedCrouched_Parms, NewCrouchSpeed), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UMyCharacterMovementComponent_SetMaxSpeedCrouched_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMyCharacterMovementComponent_SetMaxSpeedCrouched_Statics::NewProp_NewCrouchSpeed,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UMyCharacterMovementComponent_SetMaxSpeedCrouched_Statics::Function_MetaDataParams[] = {
		{ "Category", "Smooth Network Movement" },
		{ "ModuleRelativePath", "Public/MyCharacterMovementComponent.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UMyCharacterMovementComponent_SetMaxSpeedCrouched_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UMyCharacterMovementComponent, nullptr, "SetMaxSpeedCrouched", nullptr, nullptr, sizeof(MyCharacterMovementComponent_eventSetMaxSpeedCrouched_Parms), Z_Construct_UFunction_UMyCharacterMovementComponent_SetMaxSpeedCrouched_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UMyCharacterMovementComponent_SetMaxSpeedCrouched_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UMyCharacterMovementComponent_SetMaxSpeedCrouched_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UMyCharacterMovementComponent_SetMaxSpeedCrouched_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UMyCharacterMovementComponent_SetMaxSpeedCrouched()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UMyCharacterMovementComponent_SetMaxSpeedCrouched_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UMyCharacterMovementComponent_SetMovementModeRep_Statics
	{
		struct MyCharacterMovementComponent_eventSetMovementModeRep_Parms
		{
			TEnumAsByte<EMovementMode> NewMovementMode;
			uint8 NewCustomMovementMode;
		};
		static const UE4CodeGen_Private::FBytePropertyParams NewProp_NewMovementMode;
		static const UE4CodeGen_Private::FBytePropertyParams NewProp_NewCustomMovementMode;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UMyCharacterMovementComponent_SetMovementModeRep_Statics::NewProp_NewMovementMode = { "NewMovementMode", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(MyCharacterMovementComponent_eventSetMovementModeRep_Parms, NewMovementMode), Z_Construct_UEnum_Engine_EMovementMode, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UMyCharacterMovementComponent_SetMovementModeRep_Statics::NewProp_NewCustomMovementMode = { "NewCustomMovementMode", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(MyCharacterMovementComponent_eventSetMovementModeRep_Parms, NewCustomMovementMode), nullptr, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UMyCharacterMovementComponent_SetMovementModeRep_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMyCharacterMovementComponent_SetMovementModeRep_Statics::NewProp_NewMovementMode,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMyCharacterMovementComponent_SetMovementModeRep_Statics::NewProp_NewCustomMovementMode,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UMyCharacterMovementComponent_SetMovementModeRep_Statics::Function_MetaDataParams[] = {
		{ "Category", "Smooth Network Movement" },
		{ "ModuleRelativePath", "Public/MyCharacterMovementComponent.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UMyCharacterMovementComponent_SetMovementModeRep_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UMyCharacterMovementComponent, nullptr, "SetMovementModeRep", nullptr, nullptr, sizeof(MyCharacterMovementComponent_eventSetMovementModeRep_Parms), Z_Construct_UFunction_UMyCharacterMovementComponent_SetMovementModeRep_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UMyCharacterMovementComponent_SetMovementModeRep_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UMyCharacterMovementComponent_SetMovementModeRep_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UMyCharacterMovementComponent_SetMovementModeRep_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UMyCharacterMovementComponent_SetMovementModeRep()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UMyCharacterMovementComponent_SetMovementModeRep_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UMyCharacterMovementComponent_SetPlaneConstraintReplicated_Statics
	{
		struct MyCharacterMovementComponent_eventSetPlaneConstraintReplicated_Parms
		{
			FVector NewPlaneConstraint;
		};
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_NewPlaneConstraint;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UMyCharacterMovementComponent_SetPlaneConstraintReplicated_Statics::NewProp_NewPlaneConstraint = { "NewPlaneConstraint", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(MyCharacterMovementComponent_eventSetPlaneConstraintReplicated_Parms, NewPlaneConstraint), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UMyCharacterMovementComponent_SetPlaneConstraintReplicated_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMyCharacterMovementComponent_SetPlaneConstraintReplicated_Statics::NewProp_NewPlaneConstraint,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UMyCharacterMovementComponent_SetPlaneConstraintReplicated_Statics::Function_MetaDataParams[] = {
		{ "Category", "Smooth Network Movement" },
		{ "ModuleRelativePath", "Public/MyCharacterMovementComponent.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UMyCharacterMovementComponent_SetPlaneConstraintReplicated_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UMyCharacterMovementComponent, nullptr, "SetPlaneConstraintReplicated", nullptr, nullptr, sizeof(MyCharacterMovementComponent_eventSetPlaneConstraintReplicated_Parms), Z_Construct_UFunction_UMyCharacterMovementComponent_SetPlaneConstraintReplicated_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UMyCharacterMovementComponent_SetPlaneConstraintReplicated_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04820401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UMyCharacterMovementComponent_SetPlaneConstraintReplicated_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UMyCharacterMovementComponent_SetPlaneConstraintReplicated_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UMyCharacterMovementComponent_SetPlaneConstraintReplicated()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UMyCharacterMovementComponent_SetPlaneConstraintReplicated_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UMyCharacterMovementComponent_StopNewMovementMode_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UMyCharacterMovementComponent_StopNewMovementMode_Statics::Function_MetaDataParams[] = {
		{ "Category", "Smooth Network Movement" },
		{ "ModuleRelativePath", "Public/MyCharacterMovementComponent.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UMyCharacterMovementComponent_StopNewMovementMode_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UMyCharacterMovementComponent, nullptr, "StopNewMovementMode", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UMyCharacterMovementComponent_StopNewMovementMode_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UMyCharacterMovementComponent_StopNewMovementMode_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UMyCharacterMovementComponent_StopNewMovementMode()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UMyCharacterMovementComponent_StopNewMovementMode_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_UMyCharacterMovementComponent_NoRegister()
	{
		return UMyCharacterMovementComponent::StaticClass();
	}
	struct Z_Construct_UClass_UMyCharacterMovementComponent_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UMyCharacterMovementComponent_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UCharacterMovementComponent,
		(UObject* (*)())Z_Construct_UPackage__Script_MultiplayerMovementPlugin,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_UMyCharacterMovementComponent_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_UMyCharacterMovementComponent_ClientSetMovementMode, "ClientSetMovementMode" }, // 3868440767
		{ &Z_Construct_UFunction_UMyCharacterMovementComponent_LaunchCharacterReplicated, "LaunchCharacterReplicated" }, // 1854249990
		{ &Z_Construct_UFunction_UMyCharacterMovementComponent_SafeMoveUpdatedLocation, "SafeMoveUpdatedLocation" }, // 3470834892
		{ &Z_Construct_UFunction_UMyCharacterMovementComponent_SafeMoveUpdatedVelocity, "SafeMoveUpdatedVelocity" }, // 2321273865
		{ &Z_Construct_UFunction_UMyCharacterMovementComponent_ServerSetMovementMode, "ServerSetMovementMode" }, // 996902367
		{ &Z_Construct_UFunction_UMyCharacterMovementComponent_SetAirControl, "SetAirControl" }, // 2592766163
		{ &Z_Construct_UFunction_UMyCharacterMovementComponent_SetCrouchedHalfHeight, "SetCrouchedHalfHeight" }, // 2401482148
		{ &Z_Construct_UFunction_UMyCharacterMovementComponent_SetGroundFriction, "SetGroundFriction" }, // 1134818081
		{ &Z_Construct_UFunction_UMyCharacterMovementComponent_SetMaxAcceleration, "SetMaxAcceleration" }, // 3398992089
		{ &Z_Construct_UFunction_UMyCharacterMovementComponent_SetMaxGravity, "SetMaxGravity" }, // 2502073586
		{ &Z_Construct_UFunction_UMyCharacterMovementComponent_SetMaxGroundSpeed, "SetMaxGroundSpeed" }, // 170334217
		{ &Z_Construct_UFunction_UMyCharacterMovementComponent_SetMaxJumpHeight, "SetMaxJumpHeight" }, // 3417565472
		{ &Z_Construct_UFunction_UMyCharacterMovementComponent_SetMaxSpeedCrouched, "SetMaxSpeedCrouched" }, // 4274675941
		{ &Z_Construct_UFunction_UMyCharacterMovementComponent_SetMovementModeRep, "SetMovementModeRep" }, // 4087264467
		{ &Z_Construct_UFunction_UMyCharacterMovementComponent_SetPlaneConstraintReplicated, "SetPlaneConstraintReplicated" }, // 3745228835
		{ &Z_Construct_UFunction_UMyCharacterMovementComponent_StopNewMovementMode, "StopNewMovementMode" }, // 1527103227
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UMyCharacterMovementComponent_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n * \n */" },
		{ "IncludePath", "MyCharacterMovementComponent.h" },
		{ "ModuleRelativePath", "Public/MyCharacterMovementComponent.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UMyCharacterMovementComponent_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UMyCharacterMovementComponent>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UMyCharacterMovementComponent_Statics::ClassParams = {
		&UMyCharacterMovementComponent::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		nullptr,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		0,
		0,
		0x00B000A4u,
		METADATA_PARAMS(Z_Construct_UClass_UMyCharacterMovementComponent_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UMyCharacterMovementComponent_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UMyCharacterMovementComponent()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UMyCharacterMovementComponent_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UMyCharacterMovementComponent, 1563584479);
	template<> MULTIPLAYERMOVEMENTPLUGIN_API UClass* StaticClass<UMyCharacterMovementComponent>()
	{
		return UMyCharacterMovementComponent::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_UMyCharacterMovementComponent(Z_Construct_UClass_UMyCharacterMovementComponent, &UMyCharacterMovementComponent::StaticClass, TEXT("/Script/MultiplayerMovementPlugin"), TEXT("UMyCharacterMovementComponent"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UMyCharacterMovementComponent);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
