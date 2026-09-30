// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "EnhancedInputSubsystems.h"
#include "Components/SlateWrapperTypes.h"
#include "EnhancedInputComponent.h"
#include "GameFramework/PlayerController.h"
#include "GPAssessmentPlayerController.generated.h"


class UInputMappingContext;
class UUserWidget; 

/**
 *
 */
UCLASS()
class GPASSESSMENT_API AGPAssessmentPlayerController : public APlayerController
{
	GENERATED_BODY()
	
protected:

	/** Input Mapping Context to be used for player input */
	UPROPERTY(EditDefaultsOnly, Category = "Input")
	class UInputMappingContext* DefaultMappingContext;

	// Begin Actor interface
	
public: 
	
	void OpenMenuUI(TSubclassOf<UUserWidget> WidgetToOpen);
	
	void CloseMenuUI(); 
	
	UPROPERTY()
	UUserWidget* ActiveWidgetInstance;
protected:

	virtual void BeginPlay() override;
	
	virtual void SetupInputComponent() override; 
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "UI")
	TSubclassOf<UUserWidget> MaterialEditorWidget; 
	
	UPROPERTY()
	UUserWidget* MaterialEditorInstance; 
	
	

	// End Actor interface
};
