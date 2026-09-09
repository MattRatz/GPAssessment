// Fill out your copyright notice in the Description page of Project Settings.


#include "GP_DungeonEntrance.h"

// Sets default values
AGP_DungeonEntrance::AGP_DungeonEntrance()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	DungeonStaticMesh = CreateDefaultSubobject<UStaticMeshComponent>("DungeonEntranceSM"); 
	WidgetProximitySphere = CreateDefaultSubobject<USphereComponent>("WidgetProximitySphere");
	WidgetProximitySphere->SetMobility(EComponentMobility::Movable); 
	RootComponent = DungeonStaticMesh; 
	
	WidgetProximitySphere->SetupAttachment(DungeonStaticMesh);
	
	

}

// Called when the game starts or when spawned
void AGP_DungeonEntrance::BeginPlay()
{
	Super::BeginPlay();
	
	if (InteractWidget)
	{
		InteractionWidgetInstance = CreateWidget<UUserWidget>(GetWorld(), InteractWidget); 
		
		if (InteractionWidgetInstance)
		{
			InteractionWidgetInstance->AddToViewport(); 
			InteractionWidgetInstance->SetVisibility(ESlateVisibility::Hidden);  
		}
	}
	
	if (WidgetProximitySphere)
	{
		WidgetProximitySphere->OnComponentBeginOverlap.AddDynamic(this, &AGP_DungeonEntrance::OnSphereOverlapBegin); 
		WidgetProximitySphere->OnComponentBeginOverlap.AddDynamic(this, &AGP_DungeonEntrance::OnSphereOverlapEnd);
	}
	
	
}

// Called every frame
void AGP_DungeonEntrance::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AGP_DungeonEntrance::Interact()
{
	
}

void AGP_DungeonEntrance::OnSphereOverlapBegin(UPrimitiveComponent* OverlappedComponentclass, AActor* OverlappedActor, UPrimitiveComponent* OtherComp,
	int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	
}

void AGP_DungeonEntrance::OnSphereOverlapEnd(UPrimitiveComponent* OverlappedComponentclass, AActor* OverlappedActor, UPrimitiveComponent* OtherComp,
		int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	
}
