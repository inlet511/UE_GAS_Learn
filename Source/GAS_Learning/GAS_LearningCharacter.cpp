// Copyright Epic Games, Inc. All Rights Reserved.

#include "GAS_LearningCharacter.h"
#include "Engine/LocalPlayer.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "GameFramework/Controller.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "InputActionValue.h"
#include "AbilitySystemComponent.h"
#include "Public/BaseAttributeSet.h"


DEFINE_LOG_CATEGORY(LogTemplateCharacter);

//////////////////////////////////////////////////////////////////////////
// AGAS_LearningCharacter

AGAS_LearningCharacter::AGAS_LearningCharacter()
{
	// Set size for collision capsule
	GetCapsuleComponent()->InitCapsuleSize(42.f, 96.0f);

}

void AGAS_LearningCharacter::BeginPlay()
{
	// Call the base class  
	Super::BeginPlay();

	UAbilitySystemComponent* AbilitySystemComponent = this->FindComponentByClass<UAbilitySystemComponent>();
	if (AbilitySystemComponent)
	{
		AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(UBaseAttributeSet::GetHPAttribute()).AddUObject(this, &AGAS_LearningCharacter::OnHPAttributeChanged);
	}

}

void AGAS_LearningCharacter::OnHPAttributeChanged(const FOnAttributeChangeData& Data)
{
	HPChangedEvent.Broadcast(Data.NewValue);
}

