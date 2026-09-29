// Fill out your copyright notice in the Description page of Project Settings.


#include "CaveMaterialComponent.h"

// Sets default values for this component's properties
UCaveMaterialComponent::UCaveMaterialComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
	

	// ...
}


// Called when the game starts
void UCaveMaterialComponent::BeginPlay()
{
	Super::BeginPlay();
	
	if (ObjectMaterial && OverlayMaterial)
	{
		ObjectMID = UMaterialInstanceDynamic::Create(ObjectMaterial, this); 
		OverlayMaterialMID = UMaterialInstanceDynamic::Create(OverlayMaterial, this);
	}
	
	// ...
	
}



void UCaveMaterialComponent::ChangeMaterialScalar()
{
	
}

void UCaveMaterialComponent::SelectMaterial()
{
}

void UCaveMaterialComponent::DeSelectMaterial()
{
}

// Called every frame
void UCaveMaterialComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

