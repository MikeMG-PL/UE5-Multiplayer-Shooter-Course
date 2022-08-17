// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "OverheadWidget.generated.h"

/**
 * 
 */
UCLASS()
class BLASTER_API UOverheadWidget : public UUserWidget
{
	GENERATED_BODY()

public:

	UPROPERTY(meta = (BindWidget))
	class UTextBlock* DisplayText;

	UPROPERTY(meta = (BindWidget))
	class UTextBlock* Nickname;

	void SetDisplayText(FString TextToDisplay, bool bIsItNickName);

	UFUNCTION(BlueprintCallable)
	void ShowPlayerNetRole(APawn* InPawn, bool bLocal, bool bShow);

	UFUNCTION(BlueprintCallable)
	void ShowPlayerNickname(APlayerState* PlayerState, bool bShow);
	
protected:

	virtual void OnLevelRemovedFromWorld(ULevel* InLevel, UWorld* InWorld) override;	
	
};
