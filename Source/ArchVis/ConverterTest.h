#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ConverterTest.generated.h"

UCLASS()
class ARCHVIS_API AConverterTestActor : public AActor
{
    GENERATED_BODY()

public:
    AConverterTestActor();

    virtual void BeginPlay() override;

    UFUNCTION(BlueprintCallable, Category = "Test")
        void TestConverters();
};
