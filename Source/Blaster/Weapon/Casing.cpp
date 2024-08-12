#include "Casing.h"

ACasing::ACasing()
{
	PrimaryActorTick.bCanEverTick = false;

	CasignMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("CasingMesh"));
	SetRootComponent(CasignMesh);
}

void ACasing::BeginPlay()
{
	Super::BeginPlay();
	
}

