// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameViewportClient.h"
#include "CPP_CustomViewportClient.generated.h"

/**
 * 
 */
UCLASS()
class DUOOVERRIDE_API UCPP_CustomViewportClient : public UGameViewportClient
{
	GENERATED_BODY()
	
public:
	virtual void LayoutPlayers() override;
	virtual void Tick(float DeltaTime) override;
	
	
	void SetTargetRatio(float NewRatio); // from 0 to 1 as a FLOAT, what player 1 gets
	void SnapRatio(float NewRatio);
	void SetVerticalSplit(bool b_Vertical);
	
	float TransitionSpeed = 3.0f; // the higher the faster the transition
	
private:
	float SplitRatio = 0.5f;
	float TargetRatio = 0.5f;
	bool b_VerticalSplit = true; // cause true is left right split
};
