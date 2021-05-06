// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "MultiplayerMovementPlugin/Public/MultiCharacter.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeMultiCharacter() {}
// Cross Module References
	MULTIPLAYERMOVEMENTPLUGIN_API UClass* Z_Construct_UClass_AMultiCharacter_NoRegister();
	MULTIPLAYERMOVEMENTPLUGIN_API UClass* Z_Construct_UClass_AMultiCharacter();
	ENGINE_API UClass* Z_Construct_UClass_ACharacter();
	UPackage* Z_Construct_UPackage__Script_MultiplayerMovementPlugin();
	MULTIPLAYERMOVEMENTPLUGIN_API UClass* Z_Construct_UClass_UMyCharacterMovementComponent_NoRegister();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector();
// End Cross Module References
	DEFINE_FUNCTION(AMultiCharacter::execOnMovementUpdatedCustom)
	{
		P_GET_PROPERTY(FFloatProperty,Z_Param_DeltaSeconds);
		P_GET_STRUCT_REF(FVector,Z_Param_Out_OldLocation);
		P_GET_STRUCT_REF(FVector,Z_Param_Out_OldVelocity);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->OnMovementUpdatedCustom_Implementation(Z_Param_DeltaSeconds,Z_Param_Out_OldLocation,Z_Param_Out_OldVelocity);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(AMultiCharacter::execGetMultiplayerMovementComponent)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(UMyCharacterMovementComponent**)Z_Param__Result=P_THIS->GetMultiplayerMovementComponent();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(AMultiCharacter::execPhysNetCustom)
	{
		P_GET_PROPERTY(FFloatProperty,Z_Param_DeltaTime);
		P_GET_PROPERTY(FIntProperty,Z_Param_Iterations);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->PhysNetCustom_Implementation(Z_Param_DeltaTime,Z_Param_Iterations);
		P_NATIVE_END;
	}
	static FName NAME_AMultiCharacter_OnMovementUpdatedCustom = FName(TEXT("OnMovementUpdatedCustom"));
	void AMultiCharacter::OnMovementUpdatedCustom(float DeltaSeconds, FVector const& OldLocation, FVector const& OldVelocity)
	{
		MultiCharacter_eventOnMovementUpdatedCustom_Parms Parms;
		Parms.DeltaSeconds=DeltaSeconds;
		Parms.OldLocation=OldLocation;
		Parms.OldVelocity=OldVelocity;
		ProcessEvent(FindFunctionChecked(NAME_AMultiCharacter_OnMovementUpdatedCustom),&Parms);
	}
	static FName NAME_AMultiCharacter_PhysNetCustom = FName(TEXT("PhysNetCustom"));
	void AMultiCharacter::PhysNetCustom(float DeltaTime, int32 Iterations)
	{
		MultiCharacter_eventPhysNetCustom_Parms Parms;
		Parms.DeltaTime=DeltaTime;
		Parms.Iterations=Iterations;
		ProcessEvent(FindFunctionChecked(NAME_AMultiCharacter_PhysNetCustom),&Parms);
	}
	void AMultiCharacter::StaticRegisterNativesAMultiCharacter()
	{
		UClass* Class = AMultiCharacter::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "GetMultiplayerMovementComponent", &AMultiCharacter::execGetMultiplayerMovementComponent },
			{ "OnMovementUpdatedCustom", &AMultiCharacter::execOnMovementUpdatedCustom },
			{ "PhysNetCustom", &AMultiCharacter::execPhysNetCustom },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_AMultiCharacter_GetMultiplayerMovementComponent_Statics
	{
		struct MultiCharacter_eventGetMultiplayerMovementComponent_Parms
		{
			UMyCharacterMovementComponent* ReturnValue;
		};
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_ReturnValue_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AMultiCharacter_GetMultiplayerMovementComponent_Statics::NewProp_ReturnValue_MetaData[] = {
		{ "EditInline", "true" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_AMultiCharacter_GetMultiplayerMovementComponent_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000080588, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(MultiCharacter_eventGetMultiplayerMovementComponent_Parms, ReturnValue), Z_Construct_UClass_UMyCharacterMovementComponent_NoRegister, METADATA_PARAMS(Z_Construct_UFunction_AMultiCharacter_GetMultiplayerMovementComponent_Statics::NewProp_ReturnValue_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_AMultiCharacter_GetMultiplayerMovementComponent_Statics::NewProp_ReturnValue_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AMultiCharacter_GetMultiplayerMovementComponent_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AMultiCharacter_GetMultiplayerMovementComponent_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AMultiCharacter_GetMultiplayerMovementComponent_Statics::Function_MetaDataParams[] = {
		{ "Category", "Smooth Network Movement" },
		{ "ModuleRelativePath", "Public/MultiCharacter.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_AMultiCharacter_GetMultiplayerMovementComponent_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AMultiCharacter, nullptr, "GetMultiplayerMovementComponent", nullptr, nullptr, sizeof(MultiCharacter_eventGetMultiplayerMovementComponent_Parms), Z_Construct_UFunction_AMultiCharacter_GetMultiplayerMovementComponent_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AMultiCharacter_GetMultiplayerMovementComponent_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AMultiCharacter_GetMultiplayerMovementComponent_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_AMultiCharacter_GetMultiplayerMovementComponent_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AMultiCharacter_GetMultiplayerMovementComponent()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_AMultiCharacter_GetMultiplayerMovementComponent_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AMultiCharacter_OnMovementUpdatedCustom_Statics
	{
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_DeltaSeconds;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_OldLocation_MetaData[];
#endif
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_OldLocation;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_OldVelocity_MetaData[];
#endif
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_OldVelocity;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_AMultiCharacter_OnMovementUpdatedCustom_Statics::NewProp_DeltaSeconds = { "DeltaSeconds", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(MultiCharacter_eventOnMovementUpdatedCustom_Parms, DeltaSeconds), METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AMultiCharacter_OnMovementUpdatedCustom_Statics::NewProp_OldLocation_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_AMultiCharacter_OnMovementUpdatedCustom_Statics::NewProp_OldLocation = { "OldLocation", nullptr, (EPropertyFlags)0x0010000008000182, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(MultiCharacter_eventOnMovementUpdatedCustom_Parms, OldLocation), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(Z_Construct_UFunction_AMultiCharacter_OnMovementUpdatedCustom_Statics::NewProp_OldLocation_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_AMultiCharacter_OnMovementUpdatedCustom_Statics::NewProp_OldLocation_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AMultiCharacter_OnMovementUpdatedCustom_Statics::NewProp_OldVelocity_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_AMultiCharacter_OnMovementUpdatedCustom_Statics::NewProp_OldVelocity = { "OldVelocity", nullptr, (EPropertyFlags)0x0010000008000182, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(MultiCharacter_eventOnMovementUpdatedCustom_Parms, OldVelocity), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(Z_Construct_UFunction_AMultiCharacter_OnMovementUpdatedCustom_Statics::NewProp_OldVelocity_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_AMultiCharacter_OnMovementUpdatedCustom_Statics::NewProp_OldVelocity_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AMultiCharacter_OnMovementUpdatedCustom_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AMultiCharacter_OnMovementUpdatedCustom_Statics::NewProp_DeltaSeconds,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AMultiCharacter_OnMovementUpdatedCustom_Statics::NewProp_OldLocation,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AMultiCharacter_OnMovementUpdatedCustom_Statics::NewProp_OldVelocity,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AMultiCharacter_OnMovementUpdatedCustom_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/MultiCharacter.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_AMultiCharacter_OnMovementUpdatedCustom_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AMultiCharacter, nullptr, "OnMovementUpdatedCustom", nullptr, nullptr, sizeof(MultiCharacter_eventOnMovementUpdatedCustom_Parms), Z_Construct_UFunction_AMultiCharacter_OnMovementUpdatedCustom_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AMultiCharacter_OnMovementUpdatedCustom_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08C20C00, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AMultiCharacter_OnMovementUpdatedCustom_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_AMultiCharacter_OnMovementUpdatedCustom_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AMultiCharacter_OnMovementUpdatedCustom()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_AMultiCharacter_OnMovementUpdatedCustom_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AMultiCharacter_PhysNetCustom_Statics
	{
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_DeltaTime;
		static const UE4CodeGen_Private::FIntPropertyParams NewProp_Iterations;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_AMultiCharacter_PhysNetCustom_Statics::NewProp_DeltaTime = { "DeltaTime", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(MultiCharacter_eventPhysNetCustom_Parms, DeltaTime), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FIntPropertyParams Z_Construct_UFunction_AMultiCharacter_PhysNetCustom_Statics::NewProp_Iterations = { "Iterations", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(MultiCharacter_eventPhysNetCustom_Parms, Iterations), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AMultiCharacter_PhysNetCustom_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AMultiCharacter_PhysNetCustom_Statics::NewProp_DeltaTime,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AMultiCharacter_PhysNetCustom_Statics::NewProp_Iterations,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AMultiCharacter_PhysNetCustom_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/MultiCharacter.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_AMultiCharacter_PhysNetCustom_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AMultiCharacter, nullptr, "PhysNetCustom", nullptr, nullptr, sizeof(MultiCharacter_eventPhysNetCustom_Parms), Z_Construct_UFunction_AMultiCharacter_PhysNetCustom_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AMultiCharacter_PhysNetCustom_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08020C00, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AMultiCharacter_PhysNetCustom_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_AMultiCharacter_PhysNetCustom_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AMultiCharacter_PhysNetCustom()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_AMultiCharacter_PhysNetCustom_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_AMultiCharacter_NoRegister()
	{
		return AMultiCharacter::StaticClass();
	}
	struct Z_Construct_UClass_AMultiCharacter_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AMultiCharacter_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_ACharacter,
		(UObject* (*)())Z_Construct_UPackage__Script_MultiplayerMovementPlugin,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_AMultiCharacter_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_AMultiCharacter_GetMultiplayerMovementComponent, "GetMultiplayerMovementComponent" }, // 127238334
		{ &Z_Construct_UFunction_AMultiCharacter_OnMovementUpdatedCustom, "OnMovementUpdatedCustom" }, // 1504068266
		{ &Z_Construct_UFunction_AMultiCharacter_PhysNetCustom, "PhysNetCustom" }, // 58023847
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AMultiCharacter_Statics::Class_MetaDataParams[] = {
		{ "HideCategories", "Navigation" },
		{ "IncludePath", "MultiCharacter.h" },
		{ "ModuleRelativePath", "Public/MultiCharacter.h" },
		{ "ObjectInitializerConstructorDeclared", "" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_AMultiCharacter_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AMultiCharacter>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_AMultiCharacter_Statics::ClassParams = {
		&AMultiCharacter::StaticClass,
		"Game",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		nullptr,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		0,
		0,
		0x009000A4u,
		METADATA_PARAMS(Z_Construct_UClass_AMultiCharacter_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_AMultiCharacter_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AMultiCharacter()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_AMultiCharacter_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(AMultiCharacter, 2081226288);
	template<> MULTIPLAYERMOVEMENTPLUGIN_API UClass* StaticClass<AMultiCharacter>()
	{
		return AMultiCharacter::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_AMultiCharacter(Z_Construct_UClass_AMultiCharacter, &AMultiCharacter::StaticClass, TEXT("/Script/MultiplayerMovementPlugin"), TEXT("AMultiCharacter"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AMultiCharacter);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
