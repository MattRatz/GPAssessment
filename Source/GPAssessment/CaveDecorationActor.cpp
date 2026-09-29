// Fill out your copyright notice in the Description page of Project Settings.


#include "CaveDecorationActor.h"

// Sets default values
ACaveDecorationActor::ACaveDecorationActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	ObjectMesh = CreateDefaultSubobject<UStaticMeshComponent>("ObjectMesh"); 
	RootComponent = ObjectMesh; 

}

// Called when the game starts or when spawned
void ACaveDecorationActor::BeginPlay()
{
	Super::BeginPlay();
	OverlayMaterial = ObjectMesh->GetOverlayMaterial(); 
	if (OverlayMaterial)
	{
		OverlayMaterialMID = UMaterialInstanceDynamic::Create(OverlayMaterial, this);
	}
	
	ObjectMaterial = ObjectMesh->GetMaterial(0);
	if (ObjectMaterial)
	{
		ObjectMID = UMaterialInstanceDynamic::Create(ObjectMaterial, this);
		ObjectMesh->SetMaterial(0, ObjectMID); 
	}
	
}

// Called every frame
void ACaveDecorationActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ACaveDecorationActor::ChangeMaterialScalar(float ScalarValue)
{
	
}

void ACaveDecorationActor::SelectMaterial()
{
}

void ACaveDecorationActor::DeSelectMaterial()
{
}

