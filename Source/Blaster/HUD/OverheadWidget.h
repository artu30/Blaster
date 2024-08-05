#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "OverheadWidget.generated.h"

class UTextBlock;

/**
 * 
 */
UCLASS()
class BLASTER_API UOverheadWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	UPROPERTY(meta = (BindWidget))
	UTextBlock* DisplayText;

	UPROPERTY(meta = (BindWidget))
	UTextBlock* PlayerNameText;
	
	void SetDiplayText(FString Display);
	
	void SetPlayerNameText(FString PlayerName);

	UFUNCTION(BlueprintCallable)
	void ShowPlayerNetRole(APawn* InPawn);

	UFUNCTION(BlueprintCallable)
	void ShowPlayerName(APawn* InPawn);
	
protected:
	virtual void NativeDestruct() override;
	
};
