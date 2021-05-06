// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
struct FVector;
#ifdef MULTIPLAYERMOVEMENTPLUGIN_MyCharacterMovementComponent_generated_h
#error "MyCharacterMovementComponent.generated.h already included, missing '#pragma once' in MyCharacterMovementComponent.h"
#endif
#define MULTIPLAYERMOVEMENTPLUGIN_MyCharacterMovementComponent_generated_h

#define HostProject_Plugins_MultiplayerMovementPlugin_Source_MultiplayerMovementPlugin_Public_MyCharacterMovementComponent_h_128_SPARSE_DATA
#define HostProject_Plugins_MultiplayerMovementPlugin_Source_MultiplayerMovementPlugin_Public_MyCharacterMovementComponent_h_128_RPC_WRAPPERS \
	virtual void ServerSetMovementMode_Implementation(EMovementMode NewMovementMode, uint8 NewCustomMovementMode); \
	virtual void ClientSetMovementMode_Implementation(EMovementMode NewMovementMode, uint8 NewCustomMovementMode); \
 \
	DECLARE_FUNCTION(execSetMovementModeRep); \
	DECLARE_FUNCTION(execServerSetMovementMode); \
	DECLARE_FUNCTION(execClientSetMovementMode); \
	DECLARE_FUNCTION(execSafeMoveUpdatedLocation); \
	DECLARE_FUNCTION(execSafeMoveUpdatedVelocity); \
	DECLARE_FUNCTION(execLaunchCharacterReplicated); \
	DECLARE_FUNCTION(execSetMaxSpeedCrouched); \
	DECLARE_FUNCTION(execStopNewMovementMode); \
	DECLARE_FUNCTION(execSetCrouchedHalfHeight); \
	DECLARE_FUNCTION(execSetAirControl); \
	DECLARE_FUNCTION(execSetMaxJumpHeight); \
	DECLARE_FUNCTION(execSetMaxAcceleration); \
	DECLARE_FUNCTION(execSetPlaneConstraintReplicated); \
	DECLARE_FUNCTION(execSetMaxGravity); \
	DECLARE_FUNCTION(execSetGroundFriction); \
	DECLARE_FUNCTION(execSetMaxGroundSpeed);


#define HostProject_Plugins_MultiplayerMovementPlugin_Source_MultiplayerMovementPlugin_Public_MyCharacterMovementComponent_h_128_RPC_WRAPPERS_NO_PURE_DECLS \
	virtual void ServerSetMovementMode_Implementation(EMovementMode NewMovementMode, uint8 NewCustomMovementMode); \
	virtual void ClientSetMovementMode_Implementation(EMovementMode NewMovementMode, uint8 NewCustomMovementMode); \
 \
	DECLARE_FUNCTION(execSetMovementModeRep); \
	DECLARE_FUNCTION(execServerSetMovementMode); \
	DECLARE_FUNCTION(execClientSetMovementMode); \
	DECLARE_FUNCTION(execSafeMoveUpdatedLocation); \
	DECLARE_FUNCTION(execSafeMoveUpdatedVelocity); \
	DECLARE_FUNCTION(execLaunchCharacterReplicated); \
	DECLARE_FUNCTION(execSetMaxSpeedCrouched); \
	DECLARE_FUNCTION(execStopNewMovementMode); \
	DECLARE_FUNCTION(execSetCrouchedHalfHeight); \
	DECLARE_FUNCTION(execSetAirControl); \
	DECLARE_FUNCTION(execSetMaxJumpHeight); \
	DECLARE_FUNCTION(execSetMaxAcceleration); \
	DECLARE_FUNCTION(execSetPlaneConstraintReplicated); \
	DECLARE_FUNCTION(execSetMaxGravity); \
	DECLARE_FUNCTION(execSetGroundFriction); \
	DECLARE_FUNCTION(execSetMaxGroundSpeed);


#define HostProject_Plugins_MultiplayerMovementPlugin_Source_MultiplayerMovementPlugin_Public_MyCharacterMovementComponent_h_128_EVENT_PARMS \
	struct MyCharacterMovementComponent_eventClientSetMovementMode_Parms \
	{ \
		TEnumAsByte<EMovementMode> NewMovementMode; \
		uint8 NewCustomMovementMode; \
	}; \
	struct MyCharacterMovementComponent_eventServerSetMovementMode_Parms \
	{ \
		TEnumAsByte<EMovementMode> NewMovementMode; \
		uint8 NewCustomMovementMode; \
	};


#define HostProject_Plugins_MultiplayerMovementPlugin_Source_MultiplayerMovementPlugin_Public_MyCharacterMovementComponent_h_128_CALLBACK_WRAPPERS
#define HostProject_Plugins_MultiplayerMovementPlugin_Source_MultiplayerMovementPlugin_Public_MyCharacterMovementComponent_h_128_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUMyCharacterMovementComponent(); \
	friend struct Z_Construct_UClass_UMyCharacterMovementComponent_Statics; \
public: \
	DECLARE_CLASS(UMyCharacterMovementComponent, UCharacterMovementComponent, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/MultiplayerMovementPlugin"), NO_API) \
	DECLARE_SERIALIZER(UMyCharacterMovementComponent)


#define HostProject_Plugins_MultiplayerMovementPlugin_Source_MultiplayerMovementPlugin_Public_MyCharacterMovementComponent_h_128_INCLASS \
private: \
	static void StaticRegisterNativesUMyCharacterMovementComponent(); \
	friend struct Z_Construct_UClass_UMyCharacterMovementComponent_Statics; \
public: \
	DECLARE_CLASS(UMyCharacterMovementComponent, UCharacterMovementComponent, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/MultiplayerMovementPlugin"), NO_API) \
	DECLARE_SERIALIZER(UMyCharacterMovementComponent)


#define HostProject_Plugins_MultiplayerMovementPlugin_Source_MultiplayerMovementPlugin_Public_MyCharacterMovementComponent_h_128_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UMyCharacterMovementComponent(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UMyCharacterMovementComponent) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UMyCharacterMovementComponent); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UMyCharacterMovementComponent); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UMyCharacterMovementComponent(UMyCharacterMovementComponent&&); \
	NO_API UMyCharacterMovementComponent(const UMyCharacterMovementComponent&); \
public:


#define HostProject_Plugins_MultiplayerMovementPlugin_Source_MultiplayerMovementPlugin_Public_MyCharacterMovementComponent_h_128_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UMyCharacterMovementComponent(UMyCharacterMovementComponent&&); \
	NO_API UMyCharacterMovementComponent(const UMyCharacterMovementComponent&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UMyCharacterMovementComponent); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UMyCharacterMovementComponent); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(UMyCharacterMovementComponent)


#define HostProject_Plugins_MultiplayerMovementPlugin_Source_MultiplayerMovementPlugin_Public_MyCharacterMovementComponent_h_128_PRIVATE_PROPERTY_OFFSET
#define HostProject_Plugins_MultiplayerMovementPlugin_Source_MultiplayerMovementPlugin_Public_MyCharacterMovementComponent_h_125_PROLOG \
	HostProject_Plugins_MultiplayerMovementPlugin_Source_MultiplayerMovementPlugin_Public_MyCharacterMovementComponent_h_128_EVENT_PARMS


#define HostProject_Plugins_MultiplayerMovementPlugin_Source_MultiplayerMovementPlugin_Public_MyCharacterMovementComponent_h_128_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	HostProject_Plugins_MultiplayerMovementPlugin_Source_MultiplayerMovementPlugin_Public_MyCharacterMovementComponent_h_128_PRIVATE_PROPERTY_OFFSET \
	HostProject_Plugins_MultiplayerMovementPlugin_Source_MultiplayerMovementPlugin_Public_MyCharacterMovementComponent_h_128_SPARSE_DATA \
	HostProject_Plugins_MultiplayerMovementPlugin_Source_MultiplayerMovementPlugin_Public_MyCharacterMovementComponent_h_128_RPC_WRAPPERS \
	HostProject_Plugins_MultiplayerMovementPlugin_Source_MultiplayerMovementPlugin_Public_MyCharacterMovementComponent_h_128_CALLBACK_WRAPPERS \
	HostProject_Plugins_MultiplayerMovementPlugin_Source_MultiplayerMovementPlugin_Public_MyCharacterMovementComponent_h_128_INCLASS \
	HostProject_Plugins_MultiplayerMovementPlugin_Source_MultiplayerMovementPlugin_Public_MyCharacterMovementComponent_h_128_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define HostProject_Plugins_MultiplayerMovementPlugin_Source_MultiplayerMovementPlugin_Public_MyCharacterMovementComponent_h_128_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	HostProject_Plugins_MultiplayerMovementPlugin_Source_MultiplayerMovementPlugin_Public_MyCharacterMovementComponent_h_128_PRIVATE_PROPERTY_OFFSET \
	HostProject_Plugins_MultiplayerMovementPlugin_Source_MultiplayerMovementPlugin_Public_MyCharacterMovementComponent_h_128_SPARSE_DATA \
	HostProject_Plugins_MultiplayerMovementPlugin_Source_MultiplayerMovementPlugin_Public_MyCharacterMovementComponent_h_128_RPC_WRAPPERS_NO_PURE_DECLS \
	HostProject_Plugins_MultiplayerMovementPlugin_Source_MultiplayerMovementPlugin_Public_MyCharacterMovementComponent_h_128_CALLBACK_WRAPPERS \
	HostProject_Plugins_MultiplayerMovementPlugin_Source_MultiplayerMovementPlugin_Public_MyCharacterMovementComponent_h_128_INCLASS_NO_PURE_DECLS \
	HostProject_Plugins_MultiplayerMovementPlugin_Source_MultiplayerMovementPlugin_Public_MyCharacterMovementComponent_h_128_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> MULTIPLAYERMOVEMENTPLUGIN_API UClass* StaticClass<class UMyCharacterMovementComponent>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID HostProject_Plugins_MultiplayerMovementPlugin_Source_MultiplayerMovementPlugin_Public_MyCharacterMovementComponent_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
