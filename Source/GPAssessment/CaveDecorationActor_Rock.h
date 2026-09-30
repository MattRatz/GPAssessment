// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CaveDecorationActor.h"
#include "CaveDecorationActor_Rock.generated.h"

/**
 * 
 */
UCLASS()
class GPASSESSMENT_API ACaveDecorationActor_Rock : public ACaveDecorationActor
{
	GENERATED_BODY()
	
	ACaveDecorationActor_Rock();
	
public:
	
	float ElapsedTime = 0.0f; 
	virtual void BeginPlay() override; 
	
	virtual void ChangeMaterialScalar(FName ParamName, float ScalarValue) override; 
	
	virtual void Tick( float DeltaTime ) override;
	

};
