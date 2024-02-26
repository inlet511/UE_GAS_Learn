// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Logging/LogMacros.h"
#include "GameplayEffectTypes.h"
#include "GAS_LearningCharacter.generated.h"


DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnHPChanged, float, NewHP);

DECLARE_LOG_CATEGORY_EXTERN(LogTemplateCharacter, Log, All);

UCLASS(config=Game)
class AGAS_LearningCharacter : public ACharacter
{
	GENERATED_BODY()


public:
	AGAS_LearningCharacter();
	
	
	// To add mapping context
	virtual void BeginPlay();

	UPROPERTY(BlueprintAssignable, Category = "Ability")
	FOnHPChanged HPChangedEvent;


	void OnHPAttributeChanged(const FOnAttributeChangeData& Data);
};

