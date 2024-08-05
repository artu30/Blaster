#include "OverheadWidget.h"

#include "Components/TextBlock.h"
#include "GameFramework/PlayerState.h"

void UOverheadWidget::SetDiplayText(FString Display)
{
	if (DisplayText)
	{
		DisplayText->SetText(FText::FromString(Display));
	}
}

void UOverheadWidget::SetPlayerNameText(FString PlayerName)
{
	if (PlayerNameText)
	{
		PlayerNameText->SetText(FText::FromString(PlayerName));
	}
}

void UOverheadWidget::ShowPlayerNetRole(APawn* InPawn)
{
	ENetRole RemoteRole = InPawn->GetRemoteRole();

	FString Role;
	switch (RemoteRole)
	{
	case ROLE_Authority:
		Role = FString("Authority");
		break;
	case ROLE_AutonomousProxy:
		Role = FString("Autonomous Proxy");
		break;
	case ROLE_SimulatedProxy:
		Role = FString("Simulated Proxy");
		break;
	case ROLE_None:
	default:
		Role = FString("None");
		break;
	}
	
	FString RemoteRoleString = FString::Printf(TEXT("Remote Role: %s"), *Role);

	SetDiplayText(RemoteRoleString);
}

void UOverheadWidget::ShowPlayerName(APawn* InPawn)
{
	APlayerState* PlayerState = InPawn ? InPawn->GetPlayerState() : nullptr;
	if (!PlayerState)
	{
		return;
	}

	FString PlayerNameString = FString::Printf(TEXT("Player Name: %s"), *PlayerState->GetPlayerName());
	
	SetPlayerNameText(PlayerNameString);
}

void UOverheadWidget::NativeDestruct()
{
	RemoveFromParent();
	Super::NativeDestruct();
}
