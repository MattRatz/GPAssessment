// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GP_DungeonDirector.generated.h"

UCLASS()
class GPASSESSMENT_API AGP_DungeonDirector : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AGP_DungeonDirector();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	
	UPROPERTY(EditAnywhere, Category = "Enemies") 
	TArray<class AGP_EnemyBase*> PossibleEnemies; 
	
	

};
