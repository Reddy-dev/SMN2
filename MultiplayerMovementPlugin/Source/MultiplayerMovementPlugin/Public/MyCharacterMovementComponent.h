// Copyright 2021 Glitch Games. 

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "MyCharacterMovementComponent.generated.h"

//Network Move DATA
class FNetWorkMoveData_My : public FCharacterNetworkMoveData 
{

	//class FGDSavedMove; 

public:

	typedef FCharacterNetworkMoveData Super;
	
	

	virtual void ClientFillNetworkMoveData(const FSavedMove_Character& ClientMove, ENetworkMoveType MoveType) override;

	virtual bool Serialize(UCharacterMovementComponent& CharacterMovement, FArchive& Ar, UPackageMap* PackageMap, ENetworkMoveType MoveType) override;
	float SavedMaxGroundSpeed2 = 600.f;
	float SavedCustomGroundFriction2 = 8.f;
	float SavedMaxGravity2 = 1.f;
	float SavedMaxAccelerationCustom2 = 2048.f;
	float SavedAirControlCustom2 = 0.05f; 
	float SavedMaxJumpHeightCustom2 = 420.f;
	FVector SavedPlaneConstraint2 = FVector(0.f, 0.f, 0.f); 
	float SavedCustomCrouchHalfHeight2 = 40.f; 
	uint8 SavedMovementFlagCustom2 = 0;
	float SavedMaxSpeedCrouched2 = 300.f;
	FVector SavedLaunchVelocityCustom2 = FVector(0.f, 0.f, 0.f); 

	uint8 SavedCustomNewMovementMode2 = 0;
	uint8 SavedCustomNewCustomMovementMode2 = 0;
	uint8 SavedJustChangedMovementMode2 = 0; 
};

//Finished
class FCharacterNetworkMoveDataContainer_my : public FCharacterNetworkMoveDataContainer
{
	
public:

	//typedef FCharacterNetworkMoveDataContainer Super;

	FCharacterNetworkMoveDataContainer_my();

	FNetWorkMoveData_My CustomDefaultMoveData[3];
};


//Class FGDSavedMove
class FGDSavedMove : public FSavedMove_Character
{
public:

	typedef FSavedMove_Character Super;
		
		
	///@brief Resets all saved variables.
	virtual void Clear() override;

	///@brief Store input commands in the compressed flags.
	virtual uint8 GetCompressedFlags() const override;

	///@brief This is used to check whether or not two moves can be combined into one.
	///Basically you just check to make sure that the saved variables are the same.
	virtual bool CanCombineWith(const FSavedMovePtr& NewMove, ACharacter* Character, float MaxDelta) const override;

	///@brief Sets up the move before sending it to the server. 
	virtual void SetMoveFor(ACharacter* Character, float InDeltaTime, FVector const& NewAccel, class FNetworkPredictionData_Client_Character & ClientData) override;
	///@brief Sets variables on character movement component before making a predictive correction.
	virtual void PrepMoveFor(class ACharacter* Character) override;

	

		
	//all Saved Variables are put here in case of Packet Drop
//	float SavedSpeedIndex; 
	
		
	

	//uint8 SavedCustomFlags = 0;

	float SavedMaxGroundSpeed = 600.f;
	float SavedCustomGroundFriction = 8.f;
	float SavedMaxGravity = 1.f;
	float SavedMaxAccelerationCustom = 2048.f;
	float SavedMaxJumpHeightCustom = 420.f;
	float SavedAirControlCustom = 0.05f;
	float SavedCustomCrouchHalfHeight = 40.f;
	float SavedMaxSpeedCrouched = 300.f; 
	FVector SavedPlaneConstraint = FVector(0.f, 0.f, 0.f);
	FVector SavedLaunchVelocityCustom = FVector(0.f, 0.f, 0.f); 
	uint8 SavedMovementFlagCustom = 0;

	uint8 SavedCustomNewMovementMode = 0;
	uint8 SavedCustomNewCustomMovementMode = 0;
	uint8 SavedJustChangedMovementMode = 0; 
};

//Class Prediction Data
class FGDNetworkPredictionData_Client : public FNetworkPredictionData_Client_Character
	{
	public:
		FGDNetworkPredictionData_Client(const UCharacterMovementComponent& ClientMovement);

		typedef FNetworkPredictionData_Client_Character Super;

		///@brief Allocates a new copy of our custom saved move
		virtual FSavedMovePtr AllocateNewMove() override;
	};

/*
 *Character Movement Component
 */
class AMultiCharacter;
/**
 * 
 */
UCLASS()
class MULTIPLAYERMOVEMENTPLUGIN_API UMyCharacterMovementComponent : public UCharacterMovementComponent
{
	GENERATED_BODY()

	friend class FGDSavedMove;
	//friend class FCharacterNetworkMoveDataContainer_my; 

	public:
	UMyCharacterMovementComponent();

	//New Move Data Container
	 FCharacterNetworkMoveDataContainer_my MoveDataContainer;
	
	enum EMovementFlag 
	{
		CFLAG_NewMovementMode  	= 1 << 0,
		//CFLAG_JustChangedMovementModes = 1 << 1,
	};

	uint8 MovementFlagCustom = 0;

	uint8 CustomNewMovementMode = 0;
	uint8 CustomNewCustomMovementMode = 0;
	uint8 JustChangedMovementMode = 0; 

	virtual void ActivateMovementFlag(EMovementFlag FlagToActivate);
	virtual void ClearMovementFlag(EMovementFlag FlagToClear); 
	
	float MaxGroundSpeed = 600.f;
	float CustomGroundFriction = 8.f;
	float MaxGravity = 1.f;
	float MaxAccelerationCustom = 2048.f;
	float MaxJumpHeightCustom = JumpZVelocity;
	float AirControlCustom = AirControl;
	float CustomCrouchHalfHeight = CrouchedHalfHeight;
	float MaxSpeedCrouched = 300.f; 
	FVector PlaneConstraint = FVector(0.f, 0.f, 0.f);
	FVector LaunchVelocityCustom = FVector(0.f, 0.f, 0.f); 
	
	//All Overridden Functions
	virtual float GetMaxAcceleration() const override;
	virtual float GetMaxSpeed() const override;
	virtual void UpdateFromCompressedFlags(uint8 Flags) override;
	virtual class FNetworkPredictionData_Client* GetPredictionData_Client() const override;
	virtual void OnMovementUpdated(float DeltaSeconds, const FVector& OldLocation, const FVector& OldVelocity) override;
	virtual void MoveAutonomous(float ClientTimeStamp, float DeltaTime, uint8 CompressedFlags, const FVector& NewAccel) override;
	virtual void PhysCustom(float deltaTime, int32 Iterations) override;

	//Is Flag activated Function 
	inline bool IsCompressedFlagSet(EMovementFlag flag) const {return (MovementFlagCustom & flag) != 0; }

	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	 
	//UFUNCTIONS for Setting the Stored Index for when it Gets such as GetMaxSpeed(), GetGravityZ(); 
#pragma region SetValue Functions 
	UFUNCTION(BlueprintCallable, Category = "Smooth Network Movement")
		void SetMaxGroundSpeed(float NewMaxGroundSpeed);

	UFUNCTION(BlueprintCallable, Category = "Smooth Network Movement")
		void SetGroundFriction(float NewGroundFriction);

	UFUNCTION(BlueprintCallable, Category = "Smooth Network Movement")
		void SetMaxGravity(float NewMaxGravity); 

	UFUNCTION(BlueprintCallable, Category = "Smooth Network Movement")
		void SetPlaneConstraintReplicated(FVector NewPlaneConstraint);

	UFUNCTION(BlueprintCallable, Category = "Smooth Network Movement")
		void SetMaxAcceleration(float NewAcceleration);

	UFUNCTION(BlueprintCallable, Category = "Smooth Network Movement")
		void SetMaxJumpHeight(float NewJumpHeight);

	UFUNCTION(BlueprintCallable, Category = "Smooth Network Movement")
		void SetAirControl(float NewAirControl);

	UFUNCTION(BlueprintCallable, Category = "Smooth Network Movement")
		void SetCrouchedHalfHeight(float NewCrouchedHalfHeight);

	UFUNCTION(BlueprintCallable, Category = "Smooth Network Movement")
		void StopNewMovementMode();

	UFUNCTION(BlueprintCallable, Category = "Smooth Network Movement")
		void SetMaxSpeedCrouched(float NewCrouchSpeed);

	UFUNCTION(BlueprintCallable, Category = "Smooth Network Movement")
		void LaunchCharacterReplicated(FVector NewLaunchVelocity, bool bXYOverride, bool bZOverride); 
#pragma endregion 	
	//virtual void SetCustomFlag(ECompressedFlags flag);

	//virtual void ClearCustomCompressedFlag(ECompressedFlags flag);

#pragma region Safe Move Updated Component Vars and Functions
	UFUNCTION(BlueprintCallable, Category = "Smooth Network Movement")
	void SafeMoveUpdatedVelocity(float DeltaTime, bool Sweep);

	UFUNCTION()
		void SafeMoveUpdatedLocation(const FVector NewLocation, bool Sweep); 
#pragma endregion

#pragma region Custom Movement Modes Bp
	UFUNCTION(Client, Reliable)
		void ClientSetMovementMode(EMovementMode NewMovementMode, uint8 NewCustomMovementMode);

	UFUNCTION(Server, Reliable)
		void ServerSetMovementMode(EMovementMode NewMovementMode, uint8 NewCustomMovementMode);

	UFUNCTION(BlueprintCallable, Category = "Smooth Network Movement")
		void SetMovementModeRep(EMovementMode NewMovementMode, uint8 NewCustomMovementMode);

#pragma endregion 
};

