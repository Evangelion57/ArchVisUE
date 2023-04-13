#include "UstrictConverter.h"

// Sets default values
AUstrictConverter::AUstrictConverter()
{
	// Set this empty to call Tick() every frame. You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AUstrictConverter::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void AUstrictConverter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// Called to bind functionality to input
void AUstrictConverter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}
