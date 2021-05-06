// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
struct FVector;
class UMyCharacterMovementComponent;
#ifdef MULTIPLAYERMOVEMENTPLUGIN_MultiCharacter_generated_h
#error "MultiCharacter.generated.h already included, missing '#pragma once' in MultiCharacter.h"
#endif
#define MULTIPLAYERMOVEMENTPLUGIN_MultiCharacter_generated_h

#define HostProject_Plugins_MultiplayerMovementPlugin_Source_MultiplayerMovementPlugin_Public_MultiCharacter_h_12_SPARSE_DATA
#define HostProject_Plugins_MultiplayerMovementPlugin_Source_MultiplayerMovementPlugin_Public_MultiCharacter_h_12_RPC_WRAPPERS \
	virtual void OnMovementUpdatedCustom_Implementation(float DeltaSeconds, FVector const& OldLocation, FVector const& OldVelocity); \
	virtual void PhysNetCustom_Implementation(float DeltaTime, int32 Iterations); \
 \
	DECLARE_FUNCTION(execOnMovementUpdatedCustom); \
	DECLARE_FUNCTION(execGetMultiplayerMovementComponent); \
	DECLARE_FUNCTION(execPhysNetCustom);


#define HostProject_Plugins_MultiplayerMovementPlugin_Source_MultiplayerMovementPlugin_Public_MultiCharacter_h_12_RPC_WRAPPERS_NO_PURE_DECLS \
	virtual void OnMovementUpdatedCustom_Implementation(float DeltaSeconds, FVector const& OldLocation, FVector const& OldVelocity); \
	virtual void PhysNetCustom_Implementation(float DeltaTime, int32 Iterations); \
 \
	DECLARE_FUNCTION(execOnMovementUpdatedCustom); \
	DECLARE_FUNCTION(execGetMultiplayerMovementComponent); \
	DECLARE_FUNCTION(execPhysNetCustom);


#define HostProject_Plugins_MultiplayerMovementPlugin_Source_MultiplayerMovementPlugin_Public_MultiCharacter_h_12_EVENT_PARMS \
	struct MultiCharacter_eventOnMovementUpdatedCustom_Parms \
	{ \
		float DeltaSeconds; \
		FVector OldLocation; \
		FVector OldVelocity; \
	}; \
	struct MultiCharacter_eventPhysNetCustom_Parms \
	{ \
		float DeltaTime; \
		int32 Iterations; \
	};


#define HostProject_Plugins_MultiplayerMovementPlugin_Source_MultiplayerMovementPlugin_Public_MultiCharacter_h_12_CALLBACK_WRAPPERS
#define HostProject_Plugins_MultiplayerMovementPlugin_Source_MultiplayerMovementPlugin_Public_MultiCharacter_h_12_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAMultiCharacter(); \
	friend struct Z_Construct_UClass_AMultiCharacter_Statics; \
public: \
	DECLARE_CLASS(AMultiCharacter, ACharacter, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/MultiplayerMovementPlugin"), NO_API) \
	DECLARE_SERIALIZER(AMultiCharacter)


#define HostProject_Plugins_MultiplayerMovementPlugin_Source_MultiplayerMovementPlugin_Public_MultiCharacter_h_12_INCLASS \
private: \
	static void StaticRegisterNativesAMultiCharacter(); \
	friend struct Z_Construct_UClass_AMultiCharacter_Statics; \
public: \
	DECLARE_CLASS(AMultiCharacter, ACharacter, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/MultiplayerMovementPlugin"), NO_API) \
	DECLARE_SERIALIZER(AMultiCharacter)


#define HostProject_Plugins_MultiplayerMovementPlugin_Source_MultiplayerMovementPlugin_Public_MultiCharacter_h_12_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API AMultiCharacter(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(AMultiCharacter) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AMultiCharacter); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AMultiCharacter); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AMultiCharacter(AMultiCharacter&&); \
	NO_API AMultiCharacter(const AMultiCharacter&); \
public:


#define HostProject_Plugins_MultiplayerMovementPlugin_Source_MultiplayerMovementPlugin_Public_MultiCharacter_h_12_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AMultiCharacter(AMultiCharacter&&); \
	NO_API AMultiCharacter(const AMultiCharacter&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AMultiCharacter); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AMultiCharacter); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(AMultiCharacter)


#define HostProject_Plugins_MultiplayerMovementPlugin_Source_MultiplayerMovementPlugin_Public_MultiCharacter_h_12_PRIVATE_PROPERTY_OFFSET
#define HostProject_Plugins_MultiplayerMovementPlugin_Source_MultiplayerMovementPlugin_Public_MultiCharacter_h_9_PROLOG \
	HostProject_Plugins_MultiplayerMovementPlugin_Source_MultiplayerMovementPlugin_Public_MultiCharacter_h_12_EVENT_PARMS


#define HostProject_Plugins_MultiplayerMovementPlugin_Source_MultiplayerMovementPlugin_Public_MultiCharacter_h_12_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	HostProject_Plugins_MultiplayerMovementPlugin_Source_MultiplayerMovementPlugin_Public_MultiCharacter_h_12_PRIVATE_PROPERTY_OFFSET \
	HostProject_Plugins_MultiplayerMovementPlugin_Source_MultiplayerMovementPlugin_Public_MultiCharacter_h_12_SPARSE_DATA \
	HostProject_Plugins_MultiplayerMovementPlugin_Source_MultiplayerMovementPlugin_Public_MultiCharacter_h_12_RPC_WRAPPERS \
	HostProject_Plugins_MultiplayerMovementPlugin_Source_MultiplayerMovementPlugin_Public_MultiCharacter_h_12_CALLBACK_WRAPPERS \
	HostProject_Plugins_MultiplayerMovementPlugin_Source_MultiplayerMovementPlugin_Public_MultiCharacter_h_12_INCLASS \
	HostProject_Plugins_MultiplayerMovementPlugin_Source_MultiplayerMovementPlugin_Public_MultiCharacter_h_12_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define HostProject_Plugins_MultiplayerMovementPlugin_Source_MultiplayerMovementPlugin_Public_MultiCharacter_h_12_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	HostProject_Plugins_MultiplayerMovementPlugin_Source_MultiplayerMovementPlugin_Public_MultiCharacter_h_12_PRIVATE_PROPERTY_OFFSET \
	HostProject_Plugins_MultiplayerMovementPlugin_Source_MultiplayerMovementPlugin_Public_MultiCharacter_h_12_SPARSE_DATA \
	HostProject_Plugins_MultiplayerMovementPlugin_Source_MultiplayerMovementPlugin_Public_MultiCharacter_h_12_RPC_WRAPPERS_NO_PURE_DECLS \
	HostProject_Plugins_MultiplayerMovementPlugin_Source_MultiplayerMovementPlugin_Public_MultiCharacter_h_12_CALLBACK_WRAPPERS \
	HostProject_Plugins_MultiplayerMovementPlugin_Source_MultiplayerMovementPlugin_Public_MultiCharacter_h_12_INCLASS_NO_PURE_DECLS \
	HostProject_Plugins_MultiplayerMovementPlugin_Source_MultiplayerMovementPlugin_Public_MultiCharacter_h_12_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> MULTIPLAYERMOVEMENTPLUGIN_API UClass* StaticClass<class AMultiCharacter>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID HostProject_Plugins_MultiplayerMovementPlugin_Source_MultiplayerMovementPlugin_Public_MultiCharacter_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
