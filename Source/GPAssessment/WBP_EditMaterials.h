// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "WBP_EditMaterials.generated.h"

/**
 * 
 */
UCLASS()
class GPASSESSMENT_API UWBP_EditMaterials : public UUserWidget
{
	GENERATED_BODY()
	
public:

	
protected:
	
	UPROPERTY(meta = (BindWidget))
	class USlider* RoughnessSlider;
	
	UPROPERTY(meta = (BindWidget))
	class USlider* MetallicSlider; 
	
	UPROPERTY(meta = (BindWidget))
	class USlider* EmissiveSlider; 
	
	UPROPERTY(meta = (BindWidget))
	class USlider* SpecularSlider; 
	
	UPROPERTY(meta = (BindWidget))
	class USlider* EmissiveStrength; 
	
	UPROPERTY(meta = (BindWidget))
	class USlider* SpeedSlider; 
	
	
};
