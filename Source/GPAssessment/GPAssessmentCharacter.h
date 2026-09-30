// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Logging/LogMacros.h"
#include "Blueprint/UserWidget.h"
#include "Animation/AnimInstance.h"
#include "Animation/AnimMontage.h"
#include "CaveDecorationActor.h"
#include "GP_InteractInterface.h"
#include "GPAssessmentCharacter.generated.h"

class UInputComponent;
class USkeletalMeshComponent;
class UCameraComponent;
class UInputAction;
class UInputMappingContext;
struct FInputActionValue;
class UUserWidget; 
class UAnimMontage; 
class IGP_InteractInterface;

DECLARE_LOG_CATEGORY_EXTERN(LogTemplateCharacter, Log, All);

UCLASS(config=Game)
class AGPAssessmentCharacter : public ACharacter, public IGP_InteractInterface 
{
	GENERATED_BODY()

	/** Pawn mesh: 1st person view (arms; seen only by self) */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=Mesh, meta = (AllowPrivateAccess = "true"))
	USkeletalMeshComponent* Mesh1P;

	/** First person camera */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	UCameraComponent* FirstPersonCameraComponent;

	/** Jump Input Action */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Input, meta=(AllowPrivateAccess = "true"))
	UInputAction* JumpAction;

	/** Move Input Action */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Input, meta=(AllowPrivateAccess = "true"))
	UInputAction* MoveAction;
	
	//Interact Action
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Input, meta=(AllowPrivateAccess = "true")) 
	UInputAction* InteractAction;
	
	//Select action (with mouse)
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Input, meta=(AllowPrivateAccess = "true"))
	UInputAction* SelectAction; 
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Input, meta=(AllowPrivateAccess = "true"))
	UInputAction* CancelAction; 

	
public:
	AGPAssessmentCharacter();
	
	TArray<ACaveDecorationActor*> CaveDecorations;
	
	void StoreInteractableActor(AActor* ActorToStore);
	
	void RemoveInteractableActor(); 
	
	void InteractWithActor(); 
	
	void ZoomPlayerCam(float DeltaTime); 
	
	void DeZoomPlayerCam(float DeltaTime); 
	
	virtual void Interact() override; 
	
	virtual void Tick(float DeltaTime) override; 
	
	UPROPERTY()
	TObjectPtr<UStaticMeshComponent> ComponentToFocus;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Animation", meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UAnimMontage> SelectMontage; 
	
	UPROPERTY()
	FRotator OriginalCamRotation; 
	
	UPROPERTY()
	float OriginalFOV; 
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float RotationSpeedZoomIn = .25f;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float RotationSpeedZoomOut = 4.0f;
	
	float FovZoomSpeed = 10.0f; 


protected:
	virtual void BeginPlay();
	
	void PlayAttackMontage(); 
	
	UPROPERTY()
	TObjectPtr<AActor> StoredInteractActor; 
	
private:


public:
		
	/** Look Input Action */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	class UInputAction* LookAction;

protected:
	/** Called for movement input */
	void Move(const FInputActionValue& Value);

	/** Called for looking input */
	void Look(const FInputActionValue& Value);
	
	// Called for interact input
	void InteractInput(const FInputActionValue& Value); 
	
	void SelectInput(const FInputActionValue& Value); 
	
	void CancelInput(const FInputActionValue& Value); 


protected:
	// APawn interface
	virtual void SetupPlayerInputComponent(UInputComponent* InputComponent) override;
	// End of APawn interface

public:
	/** Returns Mesh1P subobject **/
	USkeletalMeshComponent* GetMesh1P() const { return Mesh1P; }
	/** Returns FirstPersonCameraComponent subobject **/
	UCameraComponent* GetFirstPersonCameraComponent() const { return FirstPersonCameraComponent; }

};

