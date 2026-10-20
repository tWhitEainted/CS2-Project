// Fill out your copyright notice in the Description page of Project Settings.


#include "CPP_GameMode.h"
#include "CPP_Character.h"
#include "CPP_SplitGameState.h"
#include "CPP_SplitPlayerState.h"
#include "Kismet/GameplayStatics.h"
#include "Engine/GameInstance.h"
#include "Engine/LocalPlayer.h"
#include "GameFramework/PlayerController.h"



ACPP_GameMode::ACPP_GameMode()
{
	// Set default pawn class to our character
	DefaultPawnClass = ACPP_Character::StaticClass();
	
	GameStateClass = ACPP_SplitGameState::StaticClass();
	PlayerStateClass = ACPP_SplitPlayerState::StaticClass();
}

UClass* ACPP_GameMode::GetDefaultPawnClassForController_Implementation(AController* InController)
{
	const APlayerController* PlayerController = Cast<APlayerController>(InController);           // cast to APlayerController to access GetLocalPlayer()
	ULocalPlayer* LocalPlayer = PlayerController ? PlayerController->GetLocalPlayer() : nullptr; // gets local player from one of the controllers
	const int32 LocalPlayerIndex = LocalPlayer													 // just a failsafe, if for some reason the local player is null, returns INDEX_NONE
		? GetGameInstance()->GetLocalPlayers().IndexOfByKey(LocalPlayer)						 // gets the index of the local player in the array of local players
		: INDEX_NONE;

	if (LocalPlayerIndex == 0 && PlayerHackerBP)												 // if the local player index is 0, it gets the hacker BP
	{
		return PlayerAthleteBP.Get();
	}

	if (LocalPlayerIndex == 1 && PlayerAthleteBP)												 // if the local player index is 1, it gets the athlete BP
	{
		return PlayerHackerBP.Get();
	}

	return Super::GetDefaultPawnClassForController_Implementation(InController);				 // if the local player index is not 0 or 1, it returns the default pawn class (failsafe)
}

void ACPP_GameMode::BeginPlay()
{
	Super::BeginPlay();
	UGameplayStatics::CreatePlayer(GetWorld(), -1, true);
}