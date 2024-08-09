#include "AnimNotify_PlayLocalSound.h"

#include "Blaster/Character/BlasterCharacter.h"

void UAnimNotify_PlayLocalSound::Notify(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation,
                                        const FAnimNotifyEventReference& EventReference)
{
	if (!MeshComp->GetOwner())
	{
		return;
	}

	ABlasterCharacter* BlasterCharacter = Cast<ABlasterCharacter>(MeshComp->GetOwner());
	if (!BlasterCharacter)
	{
		return;
	}

	if (BlasterCharacter->IsLocallyControlled())
	{
		return Super::Notify(MeshComp, Animation, EventReference);
	}
}
