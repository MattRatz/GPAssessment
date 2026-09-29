// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CaveMaterialComponent.h"
#include "CaveMaterialComponent_Crystal.generated.h"

/**
 * 
 */
UCLASS()
class GPASSESSMENT_API UCaveMaterialComponent_Crystal : public UCaveMaterialComponent
{
	GENERATED_BODY()
	
public: 
	UCaveMaterialComponent_Crystal();
	
	virtual void BeginPlay() override; 
	
	virtual void ChangeMaterialScalar() override; 
};
