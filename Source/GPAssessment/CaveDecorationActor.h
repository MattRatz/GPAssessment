// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Kismet/GameplayStatics.h"
#include "CaveDecorationActor.generated.h"

UCLASS(Blueprintable, BlueprintType)
class GPASSESSMENT_API ACaveDecorationActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACaveDecorationActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	
	
	UPROPERTY(EditAnywhere, Category = "Cosmetic")
	TObjectPtr<UStaticMeshComponent> ObjectMesh; 
	

	TObjectPtr<UMaterialInterface> ObjectMaterial; 
	
	TObjectPtr<UMaterialInterface> OverlayMaterial; 
	
	UPROPERTY()
	TObjectPtr<UMaterialInstanceDynamic> OverlayMaterialMID; 
	
	UPROPERTY()
	TObjectPtr<UMaterialInstanceDynamic> ObjectMID; 
	
	UPROPERTY(BlueprintReadOnly, Category = "Functional")
	bool IsSelected; 
	
	UFUNCTION(BlueprintCallable, Category = "Functional")
	virtual void ChangeMaterialScalar(FName ParamName, float ScalarValue); 
	
	UFUNCTION(BlueprintCallable, Category = "Functional")
	void  SelectMaterial(); 
	
	UFUNCTION(BlueprintCallable, Category = "Functional")
	void  DeSelectMaterial();
	
	
	

};


