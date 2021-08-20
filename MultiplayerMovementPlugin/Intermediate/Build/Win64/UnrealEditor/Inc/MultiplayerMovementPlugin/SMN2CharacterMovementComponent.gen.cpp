// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "MultiplayerMovementPlugin/Public/SMN2CharacterMovementComponent.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeSMN2CharacterMovementComponent() {}
// Cross Module References
	MULTIPLAYERMOVEMENTPLUGIN_API UClass* Z_Construct_UClass_USMN2CharacterMovementComponent_NoRegister();
	MULTIPLAYERMOVEMENTPLUGIN_API UClass* Z_Construct_UClass_USMN2CharacterMovementComponent();
	ENGINE_API UClass* Z_Construct_UClass_UCharacterMovementComponent();
	UPackage* Z_Construct_UPackage__Script_MultiplayerMovementPlugin();
// End Cross Module References
	void USMN2CharacterMovementComponent::StaticRegisterNativesUSMN2CharacterMovementComponent()
	{
	}
	UClass* Z_Construct_UClass_USMN2CharacterMovementComponent_NoRegister()
	{
		return USMN2CharacterMovementComponent::StaticClass();
	}
	struct Z_Construct_UClass_USMN2CharacterMovementComponent_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_USMN2CharacterMovementComponent_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UCharacterMovementComponent,
		(UObject* (*)())Z_Construct_UPackage__Script_MultiplayerMovementPlugin,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_USMN2CharacterMovementComponent_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n * \n */" },
		{ "IncludePath", "SMN2CharacterMovementComponent.h" },
		{ "ModuleRelativePath", "Public/SMN2CharacterMovementComponent.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_USMN2CharacterMovementComponent_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<USMN2CharacterMovementComponent>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_USMN2CharacterMovementComponent_Statics::ClassParams = {
		&USMN2CharacterMovementComponent::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		nullptr,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		0,
		0,
		0x00B000A4u,
		METADATA_PARAMS(Z_Construct_UClass_USMN2CharacterMovementComponent_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_USMN2CharacterMovementComponent_Statics::Class_MetaDataParams))
	};
	extern FClassRegistrationInfo& Z_Registration_Info_UClass_USMN2CharacterMovementComponent();
	UClass* Z_Construct_UClass_USMN2CharacterMovementComponent()
	{
		static UClass*& OuterClass = Z_Registration_Info_UClass_USMN2CharacterMovementComponent().OuterSingleton;
		if (!OuterClass)
		{
			UECodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_USMN2CharacterMovementComponent_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(USMN2CharacterMovementComponent, 2697357963);
	template<> MULTIPLAYERMOVEMENTPLUGIN_API UClass* StaticClass<USMN2CharacterMovementComponent>()
	{
		return USMN2CharacterMovementComponent::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(USMN2CharacterMovementComponent);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
