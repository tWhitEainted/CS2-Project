// Fill out your copyright notice in the Description page of Project Settings.


#include "CPP_CustomViewportClient.h"
#include "Engine/GameInstance.h"
#include "Engine/LocalPlayer.h"

void UCPP_CustomViewportClient::LayoutPlayers()
{
	Super::LayoutPlayers(); // let the engine do its thang (normal layout)
	
	const TArray<ULocalPlayer*>& Players = GetGameInstance()->GetLocalPlayers();
	
	if (Players.Num() != 2) return; // failsafe, if there's more than 2 players (for some reason idk)
	
	const float R = FMath::Clamp(SplitRatio, 0.05f, 0.95f);
	
	
	if (b_VerticalSplit) // left right split
	{
		Players[0]-> Origin = FVector2D(0.f, 0.f);
		Players[0]-> Size = FVector2D(R, 1.f);
		Players[1]-> Origin = FVector2D(R, 0.f);
		Players[1]-> Size = FVector2D(1.f - R, 1.f);
	}
	else // top bottom split	
	{
		Players[0]-> Origin = FVector2D(0.f, 0.f);
		Players[0]-> Size = FVector2D(1.f, R);
		Players[1]-> Origin = FVector2D(0.f, R);
		Players[1]-> Size = FVector2D(1.f, 1.f - R);
	}
}


void UCPP_CustomViewportClient::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (!FMath::IsNearlyEqual(SplitRatio, TargetRatio, 0.001f))
	{
		SplitRatio = FMath::FInterpTo(SplitRatio, TargetRatio, DeltaTime, TransitionSpeed);
		LayoutPlayers();
	}
	else if (SplitRatio != TargetRatio)
	{
		SplitRatio = TargetRatio;
		LayoutPlayers();
	}
}

void UCPP_CustomViewportClient::SetTargetRatio(float NewTarget)
{
	TargetRatio = FMath::Clamp(NewTarget, 0.05f, 0.95f);
}

void UCPP_CustomViewportClient::SnapRatio(float NewRatio)
{
	TargetRatio = SplitRatio = FMath::Clamp(NewRatio, 0.05f, 0.95f);
	LayoutPlayers();
}

void UCPP_CustomViewportClient::SetVerticalSplit(bool b_Vertical)
{
	b_VerticalSplit = b_Vertical;
	LayoutPlayers();
}
	
