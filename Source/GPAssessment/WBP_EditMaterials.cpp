// Fill out your copyright notice in the Description page of Project Settings.


#include "WBP_EditMaterials.h"


void UWBP_EditMaterials::NativeConstruct()
{
	Super::NativeConstruct();
	
	if (CrystalButton)
	{
		CrystalButton->OnClicked.AddDynamic(this, &UWBP_EditMaterials::OnCrystalButtonClicked);
	}
	
	if (RockButton)
	{
		RockButton->OnClicked.AddDynamic(this, &UWBP_EditMaterials::OnRockButtonClicked);
	}
	
	if (LightButton)
	{
		LightButton->OnClicked.AddDynamic(this, &UWBP_EditMaterials::OnLightButtonClicked);
	}
	
	if (EmissiveSlider)
	{
		EmissiveSlider->OnValueChanged.AddDynamic(this, &UWBP_EditMaterials::OnEmissiveSliderChanged);
	}
	
	if (RoughnessSlider)
	{
		RoughnessSlider->OnValueChanged.AddDynamic(this, &UWBP_EditMaterials::OnRoughnessSliderChanged);
	}
	
	if (MetallicSlider)
	{
		MetallicSlider->OnValueChanged.AddDynamic(this, &UWBP_EditMaterials::OnMetallicSliderChanged);
	}
	
	if (SpecularSlider)
	{
		SpecularSlider->OnValueChanged.AddDynamic(this, &UWBP_EditMaterials::OnSpecularSliderChanged); 
	}
	
	if (SpeedSlider)
	{
		SpeedSlider->OnValueChanged.AddDynamic(this, &UWBP_EditMaterials::OnSpeedSliderChanged); 
	}
	
	if (EmissiveStrength)
	{
		EmissiveStrength->OnValueChanged.AddDynamic(this, &UWBP_EditMaterials::OnEmissiveLightSliderChanged); 
	}
	
	
	TArray<AActor*> FoundActors;
	
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), ACaveDecorationActor::StaticClass(), FoundActors); 
	for (AActor* EachActor : FoundActors)
	{
		if (ACaveDecorationActor* DecorationToAdd = Cast<ACaveDecorationActor>(EachActor))
		{
			CaveDecorations.Add(DecorationToAdd);
		}
	}
	
	
}

void UWBP_EditMaterials::ChangeSelectedMaterialSliderParam(FName ParamName, float Value)
{
	for (ACaveDecorationActor* EachDecoration : CaveDecorations)
	{
		if (EachDecoration->IsSelected == true)
		{
			EachDecoration->ChangeMaterialScalar(ParamName, Value);
		}
	}
}

void UWBP_EditMaterials::OnCrystalButtonClicked()
{
	UE_LOG(LogTemp, Warning, TEXT("CrystalButtonClicked"));
	
	for (ACaveDecorationActor* EachDecoration : CaveDecorations)
	{
		if (ACaveDecorationActor_Crystal* EachCrystal = Cast<ACaveDecorationActor_Crystal>(EachDecoration))
		{
			EachCrystal->SelectMaterial();
		}
		else
		{
			Cast<ACaveDecorationActor>(EachDecoration)->DeSelectMaterial();
		}
	}
	
}

void UWBP_EditMaterials::OnRockButtonClicked()
{
	UE_LOG(LogTemp, Warning, TEXT("RockButtonClicked"));
	
	for (ACaveDecorationActor* EachDecoration : CaveDecorations)
	{
		if (ACaveDecorationActor_Rock* EachRock = Cast<ACaveDecorationActor_Rock>(EachDecoration))
		{
			EachRock->SelectMaterial();
		}
		else
		{
			Cast<ACaveDecorationActor>(EachDecoration)->DeSelectMaterial();
		}
	}
	
}

void UWBP_EditMaterials::OnLightButtonClicked()
{
	UE_LOG(LogTemp, Warning, TEXT("LightButtonClicked"));
	
	for (ACaveDecorationActor* EachDecoration : CaveDecorations)
	{
		if (ACaveDecorationActor_Light* EachLight = Cast<ACaveDecorationActor_Light>(EachDecoration))
		{
			EachLight->SelectMaterial();
		}
		else
		{
			Cast<ACaveDecorationActor>(EachDecoration)->DeSelectMaterial();
		}
	}
	
}

void UWBP_EditMaterials::OnEmissiveSliderChanged(float Value)
{
	ChangeSelectedMaterialSliderParam(TEXT("EmissiveParam"), Value);
}

void UWBP_EditMaterials::OnRoughnessSliderChanged(float Value)
{
	ChangeSelectedMaterialSliderParam(TEXT("RoughnessParam"), Value);
}

void UWBP_EditMaterials::OnMetallicSliderChanged(float Value)
{
	ChangeSelectedMaterialSliderParam(TEXT("MetallicParam"), Value); 
}

void UWBP_EditMaterials::OnSpecularSliderChanged(float Value)
{
	ChangeSelectedMaterialSliderParam(TEXT("SpecularParam"), Value);
}

void UWBP_EditMaterials::OnSpeedSliderChanged(float Value)
{
	ChangeSelectedMaterialSliderParam(TEXT("PanSpeed"), Value);
}

void UWBP_EditMaterials::OnEmissiveLightSliderChanged(float Value)
{
	ChangeSelectedMaterialSliderParam(TEXT("EmissiveParam"), Value);
}
