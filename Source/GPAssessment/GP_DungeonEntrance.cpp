// Fill out your copyright notice in the Description page of Project Settings.


#include "GP_DungeonEntrance.h"

#include "GPAssessmentCharacter.h"

// Sets default values
AGP_DungeonEntrance::AGP_DungeonEntrance()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	DungeonStaticMesh = CreateDefaultSubobject<UStaticMeshComponent>("DungeonEntranceSM"); 
	WidgetProximitySphere = CreateDefaultSubobject<USphereComponent>("WidgetProximitySphere");
	TestWidget = CreateDefaultSubobject<UWidgetComponent>("TestWidgetComponent"); 
	
	WidgetProximitySphere->SetMobility(EComponentMobility::Movable); 
	RootComponent = DungeonStaticMesh; 
	
	WidgetProximitySphere->SetupAttachment(DungeonStaticMesh);
	TestWidget->SetupAttachment(DungeonStaticMesh);
	
	TestWidget->SetWidgetSpace(EWidgetSpace::World); 
	TestWidget->SetDrawSize(FVector2D(500.0f, 500.0f));
	
	

}

// Called when the game starts or when spawned
void AGP_DungeonEntrance::BeginPlay()
{
	Super::BeginPlay();
	
	FVector EntranceLocation = DungeonStaticMesh->GetComponentLocation(); 
	SetActorTickEnabled(false);
	if (TestWidget)
	{
		TestWidget->SetWidgetClass(InteractWidget); 
		TestWidget->SetVisibility(true); 
		TestWidgetInstance = TestWidget->GetUserWidgetObject();
		TestWidgetInstance->SetVisibility(ESlateVisibility::Hidden);
		
	}
	
	if (WidgetProximitySphere)
	{
		WidgetProximitySphere->OnComponentBeginOverlap.AddDynamic(this, &AGP_DungeonEntrance::OnSphereOverlapBegin); 
		WidgetProximitySphere->OnComponentEndOverlap.AddDynamic(this, &AGP_DungeonEntrance::OnSphereOverlapEnd); 
		WidgetProximitySphere->SetCollisionResponseToAllChannels(ECR_Overlap); 
		WidgetProximitySphere->SetGenerateOverlapEvents(true); 
	}
	
	PlayerRef = UGameplayStatics::GetPlayerPawn(this, 0);
	
	
}

// Called every frame
void AGP_DungeonEntrance::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
	if (PlayerRef)
	{
		FVector PlayerLocation = PlayerRef->GetActorLocation(); 
		FVector WidgetLocation = TestWidget->GetComponentLocation(); 
		FRotator PlayerWidgetLookAtRotation = (PlayerLocation - WidgetLocation).Rotation();
		
		FRotator NewLookAtRotation = FRotator(0.0f, PlayerWidgetLookAtRotation.Yaw, 0.0f); 
	
		TestWidget->SetWorldRotation(NewLookAtRotation);
	}
	

}

void AGP_DungeonEntrance::Interact()
{
	
}

void AGP_DungeonEntrance::OnSphereOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OverlappedActor, UPrimitiveComponent* OtherComp,
	int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	
	if (OverlappedActor->IsA(AGPAssessmentCharacter::StaticClass()))
	{
		Cast<AGPAssessmentCharacter>(OverlappedActor)->StoreInteractableActor(this); 
		Cast<AGPAssessmentCharacter>(OverlappedActor)->ComponentToFocus = DungeonStaticMesh;
		Cast<AGPAssessmentCharacter>(OverlappedActor)->SetActorTickEnabled(true);
		SetActorTickEnabled(true);
		UE_LOG(LogTemp, Warning, TEXT("Overlap Begin")); 
		TestWidgetInstance->SetVisibility(ESlateVisibility::Visible);
		
		
	}
	
}

void AGP_DungeonEntrance::OnSphereOverlapEnd(UPrimitiveComponent* OverlappedComponent, AActor* OverlappedActor, UPrimitiveComponent* OtherComp,
		int32 OtherBodyIndex)
{
	if (OverlappedActor->IsA(AGPAssessmentCharacter::StaticClass()))
	{
		Cast<AGPAssessmentCharacter>(OverlappedActor)->RemoveInteractableActor();
		Cast<AGPAssessmentCharacter>(OverlappedActor)->ComponentToFocus = nullptr;
		SetActorTickEnabled(false);
		UE_LOG(LogTemp, Warning, TEXT("Overlap End"));
		TestWidgetInstance->SetVisibility(ESlateVisibility::Hidden);
	}
}


