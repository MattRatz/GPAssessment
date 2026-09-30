// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CaveDecorationActor.h"
#include "Components/PointLightComponent.h"
#include "CaveDecorationActor_Light.generated.h"

/**
 * 
 */
UCLASS()
class GPASSESSMENT_API ACaveDecorationActor_Light : public ACaveDecorationActor
{
	GENERATED_BODY()
	

	ACaveDecorationActor_Light();
	
	
	
public:
	
	float ElapsedTime = 0.0f; 
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Light")
	UPointLightComponent* PointLight; 
	
	virtual void BeginPlay() override; 
	
	virtual void ChangeMaterialScalar(FName ParamName, float ScalarValue) override; 
	
	virtual void Tick( float DeltaTime ) override;
	

	
};
