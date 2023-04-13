#pragma once
#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "TestStruct.generated.h"

UENUM(BlueprintType)
enum class ETestEnum : uint8
{
    VALUE_A,
    VALUE_B,
    VALUE_C
};

USTRUCT(BlueprintType)
struct FTestStruct
{
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
        ETestEnum EnumField;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
        float FloatField;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
        int32 IntField;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
        bool BoolField;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
        FName NameField;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
        FGameplayTag GameplayTagField;
};
