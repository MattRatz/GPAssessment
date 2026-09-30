// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/Button.h"
#include "Components/Slider.h"
#include "Kismet/GameplayStatics.h"
#include "CaveDecorationActor.h"
#include "CaveDecorationActor_Crystal.h"
#include "CaveDecorationActor_Rock.h"
#include "CaveDecorationActor_Light.h"
#include "WBP_EditMaterials.generated.h"

class UButton; 

/**
 * 
 */
UCLASS()
class GPASSESSMENT_API UWBP_EditMaterials : public UUserWidget
{
	GENERATED_BODY()
	
public:
	
	TArray<ACaveDecorationActor*> CaveDecorations;
	
protected:
	
	virtual void NativeConstruct() override; 
	
	UFUNCTION()
	void ChangeSelectedMaterialSliderParam(FName ParamName, float Value); 
	
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
	
	UPROPERTY(meta = (BindWidget))
	class UButton* RockButton; 
	
	UPROPERTY(meta = (BindWidget))
	class UButton* CrystalButton;
	
	UPROPERTY(meta = (BindWidget))
	class UButton* LightButton; 
	
	UFUNCTION()
	void OnCrystalButtonClicked(); 
	
	UFUNCTION()
	void OnRockButtonClicked();
	
	UFUNCTION()
	void OnLightButtonClicked(); 
	
	UFUNCTION()
	void OnEmissiveSliderChanged(float Value); 
	
	UFUNCTION()
	void OnRoughnessSliderChanged(float Value); 
	
	UFUNCTION()
	void OnMetallicSliderChanged(float Value); 
	
	UFUNCTION()
	void OnSpecularSliderChanged(float Value); 
	
	UFUNCTION()
	void OnSpeedSliderChanged(float Value); 
	
	UFUNCTION()
	void OnEmissiveLightSliderChanged(float Value); 
	
	
	
};
