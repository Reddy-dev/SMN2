// Copyright 2021 Glitch Games.

#include "MyCharacterMovementComponent.h"
#include "MultiCharacter.h"
#include "GameFramework/Character.h"
#include "Kismet/KismetSystemLibrary.h"


//Construction Script
UMyCharacterMovementComponent::UMyCharacterMovementComponent()
{
    SetNetworkMoveDataContainer(MoveDataContainer);
    //UMovementComponent::SetPlaneConstraintEnabled(true); 
}

#pragma region Flag Activation and Clearing
void UMyCharacterMovementComponent::ActivateMovementFlag(EMovementFlag FlagToActivate)
{
    MovementFlagCustom |= FlagToActivate; 
}

void UMyCharacterMovementComponent::ClearMovementFlag(EMovementFlag FlagToClear)
{
    MovementFlagCustom &= ~FlagToClear; 
}

#pragma endregion 

#pragma region Functions Needed for Saving Moves
//Clears all Saved Flags : By setting them to False
void FGDSavedMove::Clear()
{
    //SavedGen1Var = false; 
    Super::Clear();
    //Currently Not Used though Could be used in the future
  //  SavedMovementFlagCustom &= ~0;
 //   SavedMovementFlagCustom &= ~1; 
}

//Returns which move is taking which flag
uint8 FGDSavedMove::GetCompressedFlags() const
{
    uint8 Result = Super::GetCompressedFlags();
/*
    
    if (SavedGen1Var)
        Result |= DefaultEngineCustomFlag;
        */
    //Returns Result which we set above ^^
    return Result;
    
}

FGDNetworkPredictionData_Client::FGDNetworkPredictionData_Client(const UCharacterMovementComponent& ClientMovement) : Super(ClientMovement)
{
}

///@brief Allocates a new copy of our custom saved move
FSavedMovePtr FGDNetworkPredictionData_Client::AllocateNewMove()
{
    return FSavedMovePtr(new FGDSavedMove()); 
}

#pragma endregion 
//The Flags parameter contains the compressed input flags that are stored in the saved move.
//UpdateFromCompressed flags simply copies the flags from the saved move into the movement component.
//It basically just resets the movement component to the state when the move was made so it can simulate from there.
void UMyCharacterMovementComponent::UpdateFromCompressedFlags(uint8 Flags)
{
    Super::UpdateFromCompressedFlags(Flags);
    //EXAMPLES
   // SpeedIndex = (Flags & FSavedMove_Character::FLAG_Custom_0) != 0;
    /*
    GravityIndex = (Flags & FSavedMove_Character::FLAG_Custom_1) != 0;
    NewMovementModeRep = (Flags & FSavedMove_Character::FLAG_Custom_2) != 0;
    CustomMovementModeRep = (Flags & FSavedMove_Character::FLAG_Custom_3) != 0;
    CustomFlags = IsCompressedFlagSet(ECompressedFlags::CFLAG_JustChangedMode);
    CustomFlags = IsCompressedFlagSet(ECompressedFlags::CFLAG_WantsToSwitchMode);
    */

//    MovementFlagCustom = IsCompressedFlagSet(EMovementFlag::CFLAG_NewMovementMode);
   // MovementFlagCustom = IsCompressedFlagSet(EMovementFlag::CFLAG_JustChangedMovementModes); 
 }

//Does What it literally Says 
FNetworkPredictionData_Client* UMyCharacterMovementComponent::GetPredictionData_Client() const
{
    check(PawnOwner != NULL);

    if (!ClientPredictionData)
    {
        UMyCharacterMovementComponent* MutableThis = const_cast<UMyCharacterMovementComponent*>(this);

        MutableThis->ClientPredictionData = new FGDNetworkPredictionData_Client(*this); 
    }

    return ClientPredictionData; 
}

//Event Tick
void UMyCharacterMovementComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)                                               
{
    Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}

#pragma region Get Value

//These Functions are called to get what value it should be lik GetMaxSpeed will get which value speed should be. 
float UMyCharacterMovementComponent::GetMaxSpeed() const
{
    if (PawnOwner)
    {
        switch (MovementMode)
        {
            //Called When the Character is Walking or any Variation of it
            case MOVE_Walking:
            case MOVE_NavWalking:
                {
                    if (IsCrouching())
                    {
                        return MaxSpeedCrouched; 
                    }
                    return MaxGroundSpeed; 
                }
            //Called When Falling 
            case MOVE_Falling:
                {
                    return MaxGroundSpeed; 
                }

        case MOVE_Swimming:
            return MaxSwimSpeed; 
		
        case MOVE_Flying:
            return MaxFlySpeed; 
		 

        case MOVE_Custom:
            return MaxCustomMovementSpeed; 
		

        case MOVE_None:
        default:
            return 0.f;
        }
        
    }

    return 0.f; 
}
float UMyCharacterMovementComponent::GetMaxAcceleration() const
{
       //return MaxAccelerationCustom;
   return MaxAccelerationCustom; 
}
#pragma endregion 

#pragma region Set and Clear Custom Flags
/*
void UMyCharacterMovementComponent::SetCustomFlag(ECompressedFlags flag)
{
   // CustomFlags |= flag; 
}
*/
/*
void UMyCharacterMovementComponent::ClearCustomCompressedFlag(ECompressedFlags flag)
{
    //CustomFlags &= ~flag;   
}
*/
#pragma endregion

#pragma region Phys Functions and Move Data

//Finished
FCharacterNetworkMoveDataContainer_my::FCharacterNetworkMoveDataContainer_my()
{
    NewMoveData = &CustomDefaultMoveData[0];
    PendingMoveData = &CustomDefaultMoveData[1];
    OldMoveData = &CustomDefaultMoveData[2];
}

//Gets called on tick when movement mode is custom
void UMyCharacterMovementComponent::PhysCustom(float deltaTime, int32 Iterations)
{
    if (GetOwner()->GetLocalRole() == ROLE_SimulatedProxy)
        return;
    
    Super::PhysCustom(deltaTime, Iterations);

    AMultiCharacter* MultiCharacter = static_cast<AMultiCharacter*>(PawnOwner);
    if (MultiCharacter)
    {
        MultiCharacter->PhysNetCustom(deltaTime, Iterations); 
    }
}

#pragma endregion 

#pragma region Setting Values through Functions
//Setting Values
void UMyCharacterMovementComponent::SetMaxGroundSpeed(float NewMaxGroundSpeed)
{
    MaxGroundSpeed = NewMaxGroundSpeed;
}

void UMyCharacterMovementComponent::SetGroundFriction(float NewGroundFriction)
{
    CustomGroundFriction = NewGroundFriction; 
}

void UMyCharacterMovementComponent::SetMaxGravity(float NewMaxGravity)
{
    MaxGravity = NewMaxGravity; 
}

void UMyCharacterMovementComponent::SetPlaneConstraintReplicated(FVector NewPlaneConstraint)
{
    PlaneConstraint = NewPlaneConstraint; 
}

void UMyCharacterMovementComponent::SetMaxAcceleration(float NewAcceleration)
{
	MaxAccelerationCustom = NewAcceleration; 
}

void UMyCharacterMovementComponent::SetMaxJumpHeight(float NewJumpHeight)
{
    MaxJumpHeightCustom = NewJumpHeight; 
}

void UMyCharacterMovementComponent::SetAirControl(float NewAirControl)
{
    AirControlCustom = NewAirControl; 
}

void UMyCharacterMovementComponent::SetCrouchedHalfHeight(float NewCrouchedHalfHeight)
{
    CustomCrouchHalfHeight = NewCrouchedHalfHeight; 
}

void UMyCharacterMovementComponent::StopNewMovementMode()
{
    ClearMovementFlag(EMovementFlag::CFLAG_NewMovementMode);
}

void UMyCharacterMovementComponent::SetMaxSpeedCrouched(float NewCrouchSpeed)
{
    MaxSpeedCrouched = NewCrouchSpeed; 
}

void UMyCharacterMovementComponent::LaunchCharacterReplicated(FVector NewLaunchVelocity, bool bXYOverride, bool bZOverride)
{
    FVector FinalVel = NewLaunchVelocity;

    if (!bXYOverride)
    {
        FinalVel.X += Velocity.X;
        FinalVel.Y += Velocity.Y; 
    }
    if (!bZOverride)
    {
       FinalVel.Z += Velocity.Z; 
    }
    
    LaunchVelocityCustom = FinalVel;
    ACharacter* CharacterOwner2 = static_cast<ACharacter*>(PawnOwner);
    CharacterOwner2->OnLaunched(NewLaunchVelocity, bXYOverride, bZOverride); 
}

#pragma endregion

#pragma region SafeMoveComponentFunctions
//Used for Phys Custom 
void UMyCharacterMovementComponent::SafeMoveUpdatedVelocity( float DeltaTime, bool Sweep)
{
         FHitResult Hit(1.f); 
        const FVector AdjustedVelocity = Velocity * DeltaTime;
        SafeMoveUpdatedComponent(AdjustedVelocity, UpdatedComponent->GetComponentQuat(), Sweep, Hit); 
    
}

void UMyCharacterMovementComponent::SafeMoveUpdatedLocation(const FVector NewLocation, bool Sweep)
{
    FHitResult Hit;

    SafeMoveUpdatedComponent(NewLocation, UpdatedComponent->GetComponentQuat(), Sweep, Hit); 
}

#pragma endregion 

#pragma region Movement Mode Replicated

void UMyCharacterMovementComponent::SetMovementModeRep(EMovementMode NewMovementMode, uint8 NewCustomMovementMode)
{
   MovementFlagCustom |= 1;
   CustomNewMovementMode = NewMovementMode;
   CustomNewCustomMovementMode = NewCustomMovementMode; 
}


void UMyCharacterMovementComponent::ClientSetMovementMode_Implementation(EMovementMode NewMovementMode, uint8 NewCustomMovementMode)
{
    SetMovementMode(NewMovementMode, NewCustomMovementMode); 
}

void UMyCharacterMovementComponent::ServerSetMovementMode_Implementation(EMovementMode NewMovementMode, uint8 NewCustomMovementMode)
{
    SetMovementMode(NewMovementMode, NewCustomMovementMode); 
}
#pragma endregion

#pragma region Functions Needed to Set Saved and Real Move Data Vars
/*
*@Documentation Extending Saved Move Data

To add new data, first extend FSavedMove_Character to include whatever information your Character Movement Component needs. Next, extend FCharacterNetworkMoveData and add the custom data you want to send across the network; in most cases, this mirrors the data added to FSavedMove_Character. You will also need to extend FCharacterNetworkMoveDataContainer so that it can serialize your FCharacterNetworkMoveData for network transmission, and deserialize it upon receipt. When this setup is finised, configure the system as follows:

Modify your Character Movement Component to use the FCharacterNetworkMoveDataContainer subclass you created with the SetNetworkMoveDataContainer function. The simplest way to accomplish this is to add an instance of your FCharacterNetworkMoveDataContainer to your Character Movement Component child class, and call SetNetworkMoveDataContainer from the constructor.

Since your FCharacterNetworkMoveDataContainer needs its own instances of FCharacterNetworkMoveData, point it (typically in the constructor) to instances of your FCharacterNetworkMoveData subclass. See the base constructor for more details and an example.

In your extended version of FCharacterNetworkMoveData, override the ClientFillNetworkMoveData function to copy or compute data from the saved move. Override the Serialize function to read and write your data using an FArchive; this is the bit stream that RPCs require. 

To extend the server response to clients, which can acknowledges a good move or send correction data, extend FCharacterMoveResponseData, FCharacterMoveResponseDataContainer, and override your Character Movement Component's version of the SetMoveResponseDataContainer. 
*/
//Receives moves from Serialize
void UMyCharacterMovementComponent::MoveAutonomous(float ClientTimeStamp, float DeltaTime, uint8 CompressedFlags, const FVector& NewAccel)
{
    FNetWorkMoveData_My* moveData = static_cast<FNetWorkMoveData_My*>(GetCurrentNetworkMoveData());
    if (moveData != nullptr)
    {
        //CustomFlags = moveData->SavedCustomFlags1;
        MaxGroundSpeed = moveData->SavedMaxGroundSpeed2;
        CustomGroundFriction = moveData->SavedCustomGroundFriction2;
        MaxGravity = moveData->SavedMaxGravity2;
        PlaneConstraint = moveData->SavedPlaneConstraint2;
        MaxAccelerationCustom = moveData->SavedMaxAccelerationCustom2;
        MaxJumpHeightCustom = moveData->SavedMaxJumpHeightCustom2;
        AirControlCustom = moveData->SavedAirControlCustom2;
        MovementFlagCustom = moveData->SavedMovementFlagCustom2;
        CustomNewMovementMode = moveData->SavedCustomNewMovementMode2;
        CustomNewCustomMovementMode = moveData->SavedCustomNewCustomMovementMode2;
        JustChangedMovementMode = moveData->SavedJustChangedMovementMode2;
        CustomCrouchHalfHeight = moveData->SavedCustomCrouchHalfHeight2;
        MaxSpeedCrouched = moveData->SavedMaxSpeedCrouched2;
        LaunchVelocityCustom = moveData->SavedLaunchVelocityCustom2; 
    }
    Super::MoveAutonomous(ClientTimeStamp, DeltaTime, CompressedFlags, NewAccel);
}

//Sends the Movement Data 
bool FNetWorkMoveData_My::Serialize(UCharacterMovementComponent& CharacterMovement, FArchive& Ar, UPackageMap* PackageMap, ENetworkMoveType MoveType)                                   
{
    Super::Serialize(CharacterMovement, Ar, PackageMap, MoveType);
    
        SerializeOptionalValue<float>(Ar.IsSaving(), Ar, SavedMaxGroundSpeed2, 600.f);
        SerializeOptionalValue<float>(Ar.IsSaving(), Ar, SavedCustomGroundFriction2, 8.f);
        SerializeOptionalValue<float>(Ar.IsSaving(), Ar, SavedMaxGravity2, 1.f);
        SerializeOptionalValue<FVector>(Ar.IsSaving(), Ar, SavedPlaneConstraint2, FVector(0.f, 0.f, 0.f));
        SerializeOptionalValue<float>(Ar.IsSaving(), Ar, SavedMaxAccelerationCustom2, 2048.f);
        SerializeOptionalValue<float>(Ar.IsSaving(), Ar, SavedMaxJumpHeightCustom2, 420.f);
        SerializeOptionalValue<float>(Ar.IsSaving(), Ar, SavedAirControlCustom2, 0.05f);
        SerializeOptionalValue<uint8>(Ar.IsSaving(), Ar, SavedMovementFlagCustom2, 0);
        SerializeOptionalValue<uint8>(Ar.IsSaving(), Ar, SavedCustomNewMovementMode2, 0);
        SerializeOptionalValue<uint8>(Ar.IsSaving(), Ar, SavedCustomNewCustomMovementMode2, 0);
        SerializeOptionalValue<uint8>(Ar.IsSaving(), Ar, SavedJustChangedMovementMode2, 0);
        SerializeOptionalValue<float>(Ar.IsSaving(), Ar, SavedCustomCrouchHalfHeight2, 40.f);
        SerializeOptionalValue<float>(Ar.IsSaving(), Ar, SavedMaxSpeedCrouched2, 300.f);
        SerializeOptionalValue<FVector>(Ar.IsSaving(), Ar, SavedLaunchVelocityCustom2, FVector(0.f, 0.f, 0.f)); 
    
    return !Ar.IsError(); 
}

void FNetWorkMoveData_My::ClientFillNetworkMoveData(const FSavedMove_Character& ClientMove, ENetworkMoveType MoveType)                                                  
{
    Super::ClientFillNetworkMoveData(ClientMove, MoveType);

    const FGDSavedMove& savedMove = static_cast<const FGDSavedMove&>(ClientMove);   
    //EXAMPLE SavedCustomFlags1 = savedMove.SavedCustomFlags;
    SavedMaxGroundSpeed2 = savedMove.SavedMaxGroundSpeed;
    SavedCustomGroundFriction2 = savedMove.SavedCustomGroundFriction;
    SavedMaxGravity2 = savedMove.SavedMaxGravity;
    SavedPlaneConstraint2 = savedMove.SavedPlaneConstraint;
    SavedMaxAccelerationCustom2 = savedMove.SavedMaxAccelerationCustom;
    SavedMaxJumpHeightCustom2 = savedMove.SavedMaxJumpHeightCustom;
    SavedAirControlCustom2 = savedMove.SavedAirControlCustom;
    SavedMovementFlagCustom2 = savedMove.SavedMovementFlagCustom;
    SavedCustomNewMovementMode2 = savedMove.SavedCustomNewMovementMode;
    SavedCustomNewCustomMovementMode2 = savedMove.SavedCustomNewCustomMovementMode;
    SavedJustChangedMovementMode2 = savedMove.SavedJustChangedMovementMode;
    SavedCustomCrouchHalfHeight2 = savedMove.SavedCustomCrouchHalfHeight;
    SavedMaxSpeedCrouched2 = savedMove.SavedMaxSpeedCrouched;
    SavedLaunchVelocityCustom2 = savedMove.SavedLaunchVelocityCustom; 
}

//Combines Flags together as an optimization option by the engine to send less data over the network
bool FGDSavedMove::CanCombineWith(const FSavedMovePtr& NewMove, ACharacter* Character, float MaxDelta) const
{
    FGDSavedMove* NewMovePtr = static_cast<FGDSavedMove*>(NewMove.Get());
    if (SavedMaxGroundSpeed!= NewMovePtr->SavedMaxGroundSpeed)
    {
        return false; 
    }

    if (SavedCustomGroundFriction != NewMovePtr->SavedCustomGroundFriction)
    {
        return false; 
    }

    if (SavedMaxGravity != NewMovePtr->SavedMaxGravity)
    {
        return false; 
    }

    if (SavedPlaneConstraint != NewMovePtr->SavedPlaneConstraint)
    {
        return false; 
    }

    if (SavedMaxAccelerationCustom != NewMovePtr->SavedMaxAccelerationCustom)
    {
        return false;
    }

    if (SavedMaxJumpHeightCustom != NewMovePtr->SavedMaxJumpHeightCustom)
    {
        return false; 
    }

    if (SavedAirControlCustom != NewMovePtr->SavedAirControlCustom)
    {
        return false; 
    }

    if (SavedMovementFlagCustom != NewMovePtr->SavedMovementFlagCustom)
    {
        return false; 
    }

    if (SavedCustomNewMovementMode != NewMovePtr->SavedCustomNewMovementMode || SavedCustomNewCustomMovementMode != NewMovePtr->SavedCustomNewCustomMovementMode)
    {
       return false; 
    }

    if (SavedJustChangedMovementMode != NewMovePtr->SavedJustChangedMovementMode)
    {
        return false; 
    }

    if (SavedCustomCrouchHalfHeight != NewMovePtr->SavedCustomCrouchHalfHeight)
    {
        return false; 
    }

    if (SavedMaxSpeedCrouched != NewMovePtr->SavedMaxSpeedCrouched)
    {
        return false; 
    }

    if (SavedLaunchVelocityCustom != NewMovePtr->SavedLaunchVelocityCustom)
    {
        return false; 
    }
    
    return Super::CanCombineWith(NewMove, Character, MaxDelta); 
}

//Saves Move before Using
void FGDSavedMove::SetMoveFor(ACharacter* Character, float InDeltaTime, FVector const& NewAccel, FNetworkPredictionData_Client_Character& ClientData)
{
    Super::SetMoveFor(Character, InDeltaTime, NewAccel, ClientData);

    //This is where you set the saved move in case a packet is dropped containing this to minimize corrections
    UMyCharacterMovementComponent* CharacterMovement = Cast<UMyCharacterMovementComponent>(Character->GetCharacterMovement());
    if (CharacterMovement)
    {
        SavedMaxGroundSpeed = CharacterMovement->MaxGroundSpeed;
        SavedCustomGroundFriction = CharacterMovement->CustomGroundFriction;
        SavedMaxGravity = CharacterMovement->MaxGravity;
        SavedPlaneConstraint = CharacterMovement->PlaneConstraint;
        SavedMaxAccelerationCustom = CharacterMovement->MaxAccelerationCustom;
        SavedMaxJumpHeightCustom = CharacterMovement->MaxJumpHeightCustom;
        SavedAirControlCustom = CharacterMovement->AirControlCustom;
        SavedMovementFlagCustom = CharacterMovement->MovementFlagCustom;
        SavedCustomNewMovementMode = CharacterMovement->CustomNewMovementMode;
        SavedCustomNewCustomMovementMode = CharacterMovement->CustomNewCustomMovementMode;
        SavedJustChangedMovementMode = CharacterMovement->JustChangedMovementMode;
        SavedCustomCrouchHalfHeight = CharacterMovement->CustomCrouchHalfHeight;
        SavedMaxSpeedCrouched = CharacterMovement->MaxSpeedCrouched;
        SavedLaunchVelocityCustom = CharacterMovement->LaunchVelocityCustom; 
    }
    
}

//This is called usually when a packet is dropped and resets the compressed flag to its saved state
void FGDSavedMove::PrepMoveFor(ACharacter* Character)
{
    Super::PrepMoveFor(Character);

    UMyCharacterMovementComponent* CharacterMovementComponent = Cast<UMyCharacterMovementComponent>(Character->GetCharacterMovement());
    if (CharacterMovementComponent)
    {
        
        /*
        CharacterMovementComponent->SpeedIndex = SavedSpeedIndex;
        CharacterMovementComponent->GravityIndex = SavedGravityIndex;
        CharacterMovementComponent->NewMovementModeRep = SavedNewMovementModeRep;
        CharacterMovementComponent->CustomMovementModeRep = SavedCustomMovementModeRep;
        CharacterMovementComponent->CustomFlags = SavedCustomFlags;
        */
        CharacterMovementComponent->MaxGroundSpeed = SavedMaxGroundSpeed;
        CharacterMovementComponent->CustomGroundFriction = SavedCustomGroundFriction;
        CharacterMovementComponent->MaxGravity = SavedMaxGravity;
        CharacterMovementComponent->PlaneConstraint = SavedPlaneConstraint;
        CharacterMovementComponent->MaxAccelerationCustom = SavedMaxAccelerationCustom;
        CharacterMovementComponent->MaxJumpHeightCustom = SavedMaxJumpHeightCustom;
        CharacterMovementComponent->AirControlCustom = SavedAirControlCustom;
        CharacterMovementComponent->MovementFlagCustom = SavedMovementFlagCustom;
        CharacterMovementComponent->CustomNewMovementMode = SavedCustomNewMovementMode;
        CharacterMovementComponent->CustomNewCustomMovementMode = SavedCustomNewCustomMovementMode;
        CharacterMovementComponent->JustChangedMovementMode = SavedJustChangedMovementMode;
        CharacterMovementComponent->CustomCrouchHalfHeight = SavedCustomCrouchHalfHeight;
        CharacterMovementComponent->MaxSpeedCrouched = SavedMaxSpeedCrouched;
        CharacterMovementComponent->LaunchVelocityCustom = SavedLaunchVelocityCustom; 
    }
}

//Called on tick, can be used for setting values and movement mode
void UMyCharacterMovementComponent::OnMovementUpdated(float DeltaSeconds, const FVector& OldLocation, const FVector& OldVelocity)
{
    Super::OnMovementUpdated(DeltaSeconds, OldLocation, OldVelocity); 

    GroundFriction = CustomGroundFriction;
    GravityScale = MaxGravity;
    PlaneConstraintNormal = PlaneConstraint;
    JumpZVelocity = MaxJumpHeightCustom;
    AirControl = AirControlCustom;
    CrouchedHalfHeight = CustomCrouchHalfHeight;
    
    AMultiCharacter* MultiCharacter = static_cast<AMultiCharacter*>(PawnOwner);
    if (MultiCharacter)
    {
        MultiCharacter->OnMovementUpdatedCustom(DeltaSeconds, OldLocation, OldVelocity); 
    }

    if (IsCompressedFlagSet(EMovementFlag::CFLAG_NewMovementMode))
    {
       SetMovementMode(EMovementMode(CustomNewMovementMode), CustomNewCustomMovementMode);
       JustChangedMovementMode = 1; 
       
   }

    if (IsCompressedFlagSet(EMovementFlag::CFLAG_NewMovementMode) == false && JustChangedMovementMode == 1)
    {
        SetMovementMode(DefaultLandMovementMode, 0);
        JustChangedMovementMode = 0; 
         
    }

    if ((MovementMode != MOVE_None) && IsActive() && HasValidData())
    {
        PendingLaunchVelocity = LaunchVelocityCustom;
        LaunchVelocityCustom = FVector(0.f, 0.f, 0.f); 
    }
}
#pragma endregion

