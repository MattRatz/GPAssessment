// Fill out your copyright notice in the Description page of Project Settings.


#include "CaveDecorationActor_Rock.h"

ACaveDecorationActor_Rock::ACaveDecorationActor_Rock()
{
	
}

void ACaveDecorationActor_Rock::BeginPlay()
{
	Super::BeginPlay(); 
}

void ACaveDecorationActor_Rock::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ACaveDecorationActor_Rock::ChangeMaterialScalar(FName ParamName, float ScalarValue)
{
	Super::ChangeMaterialScalar(ParamName, ScalarValue);
	if (ObjectMID)
	{
		ObjectMID->SetScalarParameterValue(FName(ParamName), ScalarValue);
	}
}