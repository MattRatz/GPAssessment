// Fill out your copyright notice in the Description page of Project Settings.


#include "CaveDecorationActor_Crystal.h"

ACaveDecorationActor_Crystal::ACaveDecorationActor_Crystal()
{
	
}

void ACaveDecorationActor_Crystal::BeginPlay()
{
	Super::BeginPlay();
	
}
void ACaveDecorationActor_Crystal::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime); 

}



void ACaveDecorationActor_Crystal::ChangeMaterialScalar(FName ParamName, float ScalarValue)
{
	Super::ChangeMaterialScalar(ParamName, ScalarValue);
	if (ObjectMID)
	{
		ObjectMID->SetScalarParameterValue(FName(ParamName), ScalarValue);
	}
}

