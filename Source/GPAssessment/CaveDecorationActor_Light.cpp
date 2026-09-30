// Fill out your copyright notice in the Description page of Project Settings.


#include "CaveDecorationActor_Light.h"

ACaveDecorationActor_Light::ACaveDecorationActor_Light()
{
	PointLight = CreateDefaultSubobject<UPointLightComponent>("PointLight"); 
	PointLight->SetupAttachment(ObjectMesh);
	
}

void ACaveDecorationActor_Light::BeginPlay()
{
	Super::BeginPlay();
	if (PointLight)
	{
		ObjectMaterial = PointLight->LightFunctionMaterial; 
		ObjectMID = UMaterialInstanceDynamic::Create(ObjectMaterial, this);
		PointLight->LightFunctionMaterial = ObjectMID; 
		UE_LOG(LogTemp, Warning, TEXT("Created and assigned Light Function MID: %s"),
	*ObjectMID->GetName());
	}
}

void ACaveDecorationActor_Light::ChangeMaterialScalar(FName ParamName, float ScalarValue)
{
	Super::ChangeMaterialScalar(ParamName, ScalarValue);
	if (ObjectMID)
	{
		UE_LOG(LogTemp, Warning, TEXT("LightSliderClicked"));
		ObjectMID->SetScalarParameterValue(FName(ParamName), 5.0f);
	}
}

void ACaveDecorationActor_Light::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}
