// Fill out your copyright notice in the Description page of Project Settings.

// THIS GAME STATE IS USED FOR SPLIT SCREEN MODE.
// IT WILL HANDLE STUFF THAT BOTH PLAYERS NEED TO KNOW



#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameStateBase.h"
#include "CPP_SplitGameState.generated.h"


UCLASS()
class DUOOVERRIDE_API ACPP_SplitGameState : public AGameStateBase
{
	GENERATED_BODY()
	
public:
	
	ACPP_SplitGameState();
	
	virtual void Tick(float DeltaSeconds) override;
	
	 // ================ SPLIT SCREEN STUFF ================
	//  == FUNCTIONS
	UFUNCTION(BlueprintCallable, Category="Splitscreen") // this will transition smoothly
	void SetSplitRatio(float NewRatio);
	
	UFUNCTION(BlueprintCallable, Category="Splitscreen") // this will snap transition
	void SnapSplitRatio(float NewRatio);
	
	
	
	
	//  == PROPERTIES
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="SplitScreen") // the higher the faster the transition
	float TransitionSpeed = 3.0f;
	
	UPROPERTY(BlueprintReadOnly, Category="Splitscreen") // current ratio
	float SplitRatio = 0.5f;
	
	UPROPERTY(BlueprintReadOnly, Category="Splitscreen") // target ratio
	float TargetSplitRatio = 0.5f;
	
private:
	void ApplyRatio();
	
	
	
};


