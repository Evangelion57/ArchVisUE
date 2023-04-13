#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "Containers/Map.h"
#include "StructToTMapConverter.generated.h"

UCLASS()
class ARCHVIS_API UStructToTMapConverter : public UBlueprintFunctionLibrary
{
    GENERATED_BODY()

public:
    template<typename StructType>
    static TMap<FString, FString> ConvertUStructToTMap(const StructType& Struct);

    template<typename StructType>
    static void ConvertTMapToUStruct(const TMap<FString, FString>& TMap, StructType& Struct);
};


template<typename StructType>
TMap<FString, FString> UStructToTMapConverter::ConvertUStructToTMap(const StructType& Struct)
{
    const UStruct* StructPtr = StructType::StaticStruct();
    TMap<FString, FString> Result;

    if (!StructPtr)
    {
        return Result;
    }

    for (TFieldIterator<const FProperty> PropIt(StructPtr); PropIt; ++PropIt)
    {
        const FProperty* Property = *PropIt;
        FString PropertyName = Property->GetName();
        FString PropertyValue;
        Property->ExportText_Direct(PropertyValue, Property->ContainerPtrToValuePtr<const void>(&Struct), Property->ContainerPtrToValuePtr<const void>(&Struct), nullptr, PPF_None);

        Result.Add(PropertyName, PropertyValue);
    }

    return Result;
}

template<typename StructType>
void UStructToTMapConverter::ConvertTMapToUStruct(const TMap<FString, FString>& TMap, StructType& Struct)
{
    const UStruct* StructPtr = StructType::StaticStruct();

    if (!StructPtr)
    {
        return;
    }

    for (const TPair<FString, FString>& Pair : TMap)
    {
        FProperty* Property = StructPtr->FindPropertyByName(*Pair.Key);
        if (Property)
        {
            FString Value = Pair.Value;
            Property->ImportText(*Value, Property->ContainerPtrToValuePtr<void>(&Struct), 0, nullptr, GWarn);
        }
    }
}