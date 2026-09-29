// Copyright Epic Games, Inc. All Rights Reserved.


#include "GPAssessmentPlayerController.h"
#include "EnhancedInputSubsystems.h"
#include "Engine/LocalPlayer.h"

void AGPAssessmentPlayerController::BeginPlay()
{
	Super::BeginPlay();
	
	if (MaterialEditorWidget)
	{
		UE_LOG(LogTemp, Warning, TEXT("MaterialEditorDoesExist")); 
		MaterialEditorInstance = CreateWidget<UUserWidget>(this, MaterialEditorWidget);
		if (MaterialEditorInstance)
		{
			MaterialEditorInstance->AddToViewport();
			UE_LOG(LogTemp, Warning, TEXT("Added to Viewport")); 
			MaterialEditorInstance->SetVisibility(ESlateVisibility::Hidden);
		}

	}
}

void AGPAssessmentPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent(); // Crucial! This sets up the underlying input systems.

	// Inject your Input Mapping Context (IMC) here
	if (ULocalPlayer* LocalPlayer = GetLocalPlayer())
	{
		if (UEnhancedInputLocalPlayerSubsystem* Subsystem = LocalPlayer->GetSubsystem<UEnhancedInputLocalPlayerSubsystem>())
		{
			if (DefaultMappingContext)
			{
				Subsystem->AddMappingContext(DefaultMappingContext, 0);
			}
		}
	}
}