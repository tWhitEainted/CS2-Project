// Fill out your copyright notice in the Description page of Project Settings.



#include "CPP_SplitGameState.h"

#include "CPP_Character.h"
#include "CPP_CustomViewportClient.h"
#include "Engine/World.h"



void ACPP_SplitGameState::SetSplitRatio(float NewRatio)
{
	if (UWorld* World = GetWorld())
	{
		if (UCPP_CustomViewportClient* VC = Cast<UCPP_CustomViewportClient>(World->GetGameViewport()))
		{
			VC->SetTargetRatio(NewRatio);
		}
	}
}


