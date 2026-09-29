// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/SceneComponent.h"
#include "CaveMaterialComponent.generated.h"

class UMaterialInstanceDynamc; 
class UMaterialInterface; 
class UMeshComponent; 

UCLASS( Blueprintable, BlueprintType, meta=(BlueprintSpawnableComponent) )
class GPASSESSMENT_API UCaveMaterialComponent : public USceneComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UCaveMaterialComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;
	
	
	UPROPERTY(EditAnywhere, Category = "Cosmetic")
	TObjectPtr<UStaticMeshComponent> ObjectMesh; 
	
	UPROPERTY(EditAnywhere, Category = "Cosmetic")
	TObjectPtr<UMaterialInterface> ObjectMaterial; 
	
	UPROPERTY(EditAnywhere, Category = "Cosmetic")
	TObjectPtr<UMaterialInterface> OverlayMaterial; 
	
	UPROPERTY()
	TObjectPtr<UMaterialInstanceDynamic> OverlayMaterialMID; 
	
	UPROPERTY()
	TObjectPtr<UMaterialInstanceDynamic> ObjectMID; 
	
	UPROPERTY(BlueprintReadOnly, Category = "Functional")
	bool IsSelected; 
	
	UFUNCTION(BlueprintCallable, Category = "Functional")
	virtual void ChangeMaterialScalar(); 
	
	UFUNCTION(BlueprintCallable, Category = "Functional")
	void  SelectMaterial(); 
	
	UFUNCTION(BlueprintCallable, Category = "Functional")
	void  DeSelectMaterial();
	


public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

		
};


