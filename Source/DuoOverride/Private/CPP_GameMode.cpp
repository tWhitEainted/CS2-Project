// Fill out your copyright notice in the Description page of Project Settings.


#include "CPP_GameMode.h"
#include "CPP_Character.h"
#include "CPP_SplitGameState.h"
#include "CPP_SplitPlayerState.h"
#include "Kismet/GameplayStatics.h"



ACPP_GameMode::ACPP_GameMode()
{
	// Set default pawn class to our character
	DefaultPawnClass = ACPP_Character::StaticClass();
	
	GameStateClass = ACPP_SplitGameState::StaticClass();
	PlayerStateClass = ACPP_SplitPlayerState::StaticClass();
}

void ACPP_GameMode::BeginPlay()
{
	Super::BeginPlay();
	UGameplayStatics::CreatePlayer(GetWorld(), -1, true);
}