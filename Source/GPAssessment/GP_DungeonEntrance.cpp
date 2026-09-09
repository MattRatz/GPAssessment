// Fill out your copyright notice in the Description page of Project Settings.


#include "GP_DungeonEntrance.h"

// Sets default values
AGP_DungeonEntrance::AGP_DungeonEntrance()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	DungeonStaticMesh = CreateDefaultSubobject<UStaticMeshComponent>("DungeonEntranceSM"); 
	RootComponent = DungeonStaticMesh; 
	

}

// Called when the game starts or when spawned
void AGP_DungeonEntrance::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AGP_DungeonEntrance::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AGP_DungeonEntrance::Interact()
{
	
}
