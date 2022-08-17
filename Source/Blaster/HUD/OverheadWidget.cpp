// Fill out your copyright notice in the Description page of Project Settings.


#include "OverheadWidget.h"

#include "Components/TextBlock.h"
#include "GameFramework/PlayerState.h"

void UOverheadWidget::SetDisplayText(FString TextToDisplay, bool bIsItNickname)
{
	if (DisplayText && !bIsItNickname)
		DisplayText->SetText(FText::FromString(TextToDisplay));

	if(Nickname && bIsItNickname)
		Nickname->SetText(FText::FromString(TextToDisplay));
}

void UOverheadWidget::ShowPlayerNetRole(APawn* InPawn, bool bLocal, bool bShow)
{
	ENetRole NetRole;
	FString Role;

	if(bLocal)
		NetRole = InPawn->GetLocalRole();
	else
		NetRole = InPawn->GetRemoteRole();

	switch (NetRole)
	{
	case ENetRole::ROLE_Authority:
		Role = FString("Authority");
		break;

	case ENetRole::ROLE_AutonomousProxy:
		Role = FString("Autonomous Proxy");
		break;

	case ENetRole::ROLE_SimulatedProxy:
		Role = FString("Simulated Proxy");
		break;

	case ENetRole::ROLE_None:
		Role = FString("None");
		break;

	default:
		break;
	}
	FString RoleString = (bLocal ? FString::Printf(TEXT("Local Role: %s"), *Role) : FString::Printf(TEXT("Remote Role: %s"), *Role));

	if(bShow)
		SetDisplayText(RoleString, false);
}

void UOverheadWidget::ShowPlayerNickname(APlayerState* PlayerState, bool bShow)
{
	FString NickString = PlayerState->GetPlayerName();
	if(bShow)
		SetDisplayText(NickString, true);
}

void UOverheadWidget::OnLevelRemovedFromWorld(ULevel* InLevel, UWorld* InWorld)
{
	RemoveFromParent();
	Super::OnLevelRemovedFromWorld(InLevel, InWorld);
}
