// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GP_InteractInterface.h"
#include "Components/SphereComponent.h"
#include "Blueprint/UserWidget.h"
#include "GP_DungeonEntrance.generated.h"

UCLASS()
class GPASSESSMENT_API AGP_DungeonEntrance : public AActor, public IGP_InteractInterface 
{
	GENERATED_BODY()

	
public:	
	// Sets default values for this actor's properties
	AGP_DungeonEntrance();
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Cosmetic") 
	TObjectPtr<UStaticMeshComponent> DungeonStaticMesh; 
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Functional")
	TObjectPtr<USphereComponent> WidgetProximitySphere; 
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Cosmetic") 
	TSubclassOf<class UUserWidget> InteractWidget; 
	
	UPROPERTY()
	UUserWidget* InteractionWidgetInstance; 


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;


public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	
	virtual void Interact() override; 
	
	void OnSphereOverlapBegin(UPrimitiveComponent* OverlappedComponentclass, AActor* OverlappedActor, UPrimitiveComponent* OtherComp,
		int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult); 
	
	void OnSphereOverlapEnd(UPrimitiveComponent* OverlappedComponentclass, AActor* OverlappedActor, UPrimitiveComponent* OtherComp,
		int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult); 

};
