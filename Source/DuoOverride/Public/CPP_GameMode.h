// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "CPP_GameMode.generated.h"

/**
 * 
 */
UCLASS()
class DUOOVERRIDE_API ACPP_GameMode : public AGameModeBase
{
	GENERATED_BODY()
	
public:
	ACPP_GameMode();

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Player Classes")
	TSubclassOf<APawn> PlayerHackerBP;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Player Classes")
	TSubclassOf<APawn> PlayerAthleteBP;

	virtual UClass* GetDefaultPawnClassForController_Implementation(AController* InController) override;

protected:
	virtual void BeginPlay() override;

};
