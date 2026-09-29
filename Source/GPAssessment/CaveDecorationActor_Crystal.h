// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CaveDecorationActor.h"
#include "CaveDecorationActor_Crystal.generated.h"

/**
 * 
 */
UCLASS()
class GPASSESSMENT_API ACaveDecorationActor_Crystal : public ACaveDecorationActor
{
	GENERATED_BODY()
	
	ACaveDecorationActor_Crystal();
	
public:
	
	float ElapsedTime = 0.0f; 
	virtual void BeginPlay() override; 
	
	virtual void ChangeMaterialScalar(float ScalarValue) override; 
	
	virtual void Tick( float DeltaTime ) override;
	
};
