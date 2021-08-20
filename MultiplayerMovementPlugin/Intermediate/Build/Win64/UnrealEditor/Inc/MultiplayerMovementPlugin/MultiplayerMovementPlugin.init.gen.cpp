// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeMultiplayerMovementPlugin_init() {}
	uint32 Z_UPackage__Script_MultiplayerMovementPlugin_BodyHash()	
	{
		return 0xAD095910;
	}
	uint32 Z_UPackage__Script_MultiplayerMovementPlugin_DeclarationsHash()	
	{
		return 0xD1DD19FD;
	}
	static FPackageRegistrationInfo& Z_Registration_Info_UPackage__Script_MultiplayerMovementPlugin()
	{
		static FPackageRegistrationInfo info;
		return info;
	}
	UPackage* Z_Construct_UPackage__Script_MultiplayerMovementPlugin()
	{
		static UPackage*& ReturnPackage = Z_Registration_Info_UPackage__Script_MultiplayerMovementPlugin().OuterSingleton;
		if (!ReturnPackage)
		{
			const UECodeGen_Private::FPackageParams PackageParams = {
				"/Script/MultiplayerMovementPlugin",
				nullptr,
				0,
				PKG_CompiledIn | 0x00000000,
				0xAD095910,
				0xD1DD19FD,
				METADATA_PARAMS(nullptr, 0)
			};
			UECodeGen_Private::ConstructUPackage(ReturnPackage, PackageParams);
		}
		return ReturnPackage;
	}
	static FRegisterCompiledInInfo Z_CompiledInDeferPackage_UPackage__Script_MultiplayerMovementPlugin(Z_Construct_UPackage__Script_MultiplayerMovementPlugin, TEXT("/Script/MultiplayerMovementPlugin"), Z_Registration_Info_UPackage__Script_MultiplayerMovementPlugin(), CONSTUCT_RELOAD_VERSION_INFO(FPackageReloadVersionInfo, Z_UPackage__Script_MultiplayerMovementPlugin_BodyHash(), Z_UPackage__Script_MultiplayerMovementPlugin_DeclarationsHash()));
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
