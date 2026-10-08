// Fill out your copyright notice in the Description page of Project Settings.

// DATA FOR BOTH PLAYERS


#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerState.h"
#include "CPP_SplitPlayerState.generated.h"

/**
 * 
 */
UCLASS()
class DUOOVERRIDE_API ACPP_SplitPlayerState : public APlayerState
{
	GENERATED_BODY()
	
	
public:
	UPROPERTY(BlueprintReadOnly, Category = "SplitScreen")
	int32 LocalPlayerIndex = 0;
};
