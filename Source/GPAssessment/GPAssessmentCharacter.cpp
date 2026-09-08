// Copyright Epic Games, Inc. All Rights Reserved.

#include "GPAssessmentCharacter.h"
#include "GPAssessmentProjectile.h"
#include "Animation/AnimInstance.h"
#include "GP_InteractInterface.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "Components/SkeletalMeshComponent.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "InputActionValue.h"
#include "KismetTraceUtils.h"
#include "Engine/LocalPlayer.h"

DEFINE_LOG_CATEGORY(LogTemplateCharacter);

//////////////////////////////////////////////////////////////////////////
// AGPAssessmentCharacter

AGPAssessmentCharacter::AGPAssessmentCharacter()
{
	// Set size for collision capsule
	GetCapsuleComponent()->InitCapsuleSize(55.f, 96.0f);
		
	// Create a CameraComponent	
	FirstPersonCameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("FirstPersonCamera"));
	FirstPersonCameraComponent->SetupAttachment(GetCapsuleComponent());
	FirstPersonCameraComponent->SetRelativeLocation(FVector(-10.f, 0.f, 60.f)); // Position the camera
	FirstPersonCameraComponent->bUsePawnControlRotation = true;

	// Create a mesh component that will be used when being viewed from a '1st person' view (when controlling this pawn)
	Mesh1P = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("CharacterMesh1P"));
	Mesh1P->SetOnlyOwnerSee(true);
	Mesh1P->SetupAttachment(FirstPersonCameraComponent);
	Mesh1P->bCastDynamicShadow = false;
	Mesh1P->CastShadow = false;
	//Mesh1P->SetRelativeRotation(FRotator(0.9f, -19.19f, 5.2f));
	Mesh1P->SetRelativeLocation(FVector(-30.f, 0.f, -150.f));

}

void AGPAssessmentCharacter::BeginPlay()
{
	// Call the base class  
	Super::BeginPlay();
}

//////////////////////////////////////////////////////////////////////////// Input

void AGPAssessmentCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{	
	// Set up action bindings
	if (UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(PlayerInputComponent))
	{
		// Jumping
		EnhancedInputComponent->BindAction(JumpAction, ETriggerEvent::Started, this, &ACharacter::Jump);
		EnhancedInputComponent->BindAction(JumpAction, ETriggerEvent::Completed, this, &ACharacter::StopJumping);

		// Moving
		EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &AGPAssessmentCharacter::Move);

		// Looking
		EnhancedInputComponent->BindAction(LookAction, ETriggerEvent::Triggered, this, &AGPAssessmentCharacter::Look);
		
		//Interacting
		EnhancedInputComponent->BindAction(InteractAction, ETriggerEvent::Triggered, this, &AGPAssessmentCharacter::InteractInput); 
	}
	else
	{
		UE_LOG(LogTemplateCharacter, Error, TEXT("'%s' Failed to find an Enhanced Input Component! This template is built to use the Enhanced Input system. If you intend to use the legacy system, then you will need to update this C++ file."), *GetNameSafe(this));
	}
}


void AGPAssessmentCharacter::Move(const FInputActionValue& Value)
{
	// input is a Vector2D
	FVector2D MovementVector = Value.Get<FVector2D>();

	if (Controller != nullptr)
	{
		// add movement 
		AddMovementInput(GetActorForwardVector(), MovementVector.Y);
		AddMovementInput(GetActorRightVector(), MovementVector.X);
	}
}

void AGPAssessmentCharacter::Look(const FInputActionValue& Value)
{
	// input is a Vector2D
	FVector2D LookAxisVector = Value.Get<FVector2D>();

	if (Controller != nullptr)
	{
		// add yaw and pitch input to controller
		AddControllerYawInput(LookAxisVector.X);
		AddControllerPitchInput(LookAxisVector.Y);
	}
}

void AGPAssessmentCharacter::InteractInput(const FInputActionValue& Value)
{
	UE_LOG(LogTemp, Warning, TEXT("Player used Interact")); 
	
	FHitResult HitActorByTrace; 
	
	FVector VectorTraceStart = GetActorLocation(); 
	FVector VectorTraceEnd = VectorTraceStart + (GetActorForwardVector() * 250.f); 
	float TraceRadius = 50.f; 
	
	FCollisionShape SphereTraceForInteract = FCollisionShape::MakeSphere(TraceRadius);
	
	TArray<AActor*> ActorsToIgnoreInTrace ; 
	ActorsToIgnoreInTrace.Add(this); 
	
	bool IsHit = UKismetSystemLibrary::SphereTraceSingle(this, 
		VectorTraceStart, 
		VectorTraceEnd, 
		TraceRadius, 
		UEngineTypes::ConvertToTraceType(ECC_Visibility), 
		false, 
		ActorsToIgnoreInTrace,
		EDrawDebugTrace::Persistent, 
		HitActorByTrace, 
true); 	
	
	
	if (IsHit == true && IsValid(HitActorByTrace.GetActor()))
	{
		if (HitActorByTrace.GetActor()->Implements<UGP_InteractInterface>())
		{
			Cast<IGP_InteractInterface>(HitActorByTrace.GetActor())->Interact();
		}
		else
		{
			UE_LOG(LogTemp, Warning, TEXT("Object does not implement interface")); 
		}
	}
	
	UE_LOG(LogTemp, Warning, TEXT("Player used Interact")); 
	
}

void AGPAssessmentCharacter::Interact()
{
	
}
