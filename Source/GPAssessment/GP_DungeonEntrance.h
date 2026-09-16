// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GP_InteractInterface.h"
#include "Components/SphereComponent.h"
#include "Kismet/GameplayStatics.h" 
#include "Blueprint/UserWidget.h"
#include "Camera/CameraComponent.h"
#include "Components/WidgetComponent.h"
#include "GP_DungeonEntrance.generated.h"

class UWidgetComponent; 

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
	TObjectPtr<UWidgetComponent> TestWidget; 
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Cosmetic") 
	TSubclassOf<class UUserWidget> InteractWidget; 
	
	UPROPERTY()
	TObjectPtr<UUserWidget> TestWidgetInstance;  

private: 
	
	UPROPERTY()
	TObjectPtr<AActor> PlayerRef; 


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;


public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	
	virtual void Interact() override; 
	
	UFUNCTION()
	void OnSphereOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OverlappedActor, UPrimitiveComponent* OtherComp,
		int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult); 
	
	UFUNCTION()
	void OnSphereOverlapEnd(UPrimitiveComponent* OverlappedComponent, AActor* OverlappedActor, UPrimitiveComponent* OtherComp,
		int32 OtherBodyIndex); 

};
