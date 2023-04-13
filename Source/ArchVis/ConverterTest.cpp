#pragma once
#include "ConverterTest.h"
#include "StructToTMapConverter.h"
#include "GameplayTags.h"
#include "GameplayTagsManager.h"
#include "TestStruct.h"


AConverterTestActor::AConverterTestActor()
{
    PrimaryActorTick.bCanEverTick = false;
}


void AConverterTestActor::BeginPlay()
{
    Super::BeginPlay();

    TestConverters(); 
}


void AConverterTestActor::TestConverters()
{
    FTestStruct TestStruct;
    TestStruct.EnumField = ETestEnum::VALUE_C;
    TestStruct.FloatField = 3.14f;
    TestStruct.IntField = 42;
    TestStruct.BoolField = true;
    TestStruct.NameField = FName("TestName");

    /*
    //gameplaytag creation
    FGameplayTagContainer TagContainer;
    TagContainer.AddTag(FGameplayTag::RequestGameplayTag("Test.Tag"));
    UGameplayTagsManager& GameplayTagsManager = UGameplayTagsManager::Get();
    GameplayTagsManager.AddGameplayTag(TagContainer.GetByIndex(0));

    TestStruct.GameplayTagField = FGameplayTag::RequestGameplayTag(FName("Test.Tag"));
    */

    //Convert
    TMap<FString, FString> ConvertedTMap = UStructToTMapConverter::ConvertUStructToTMap(TestStruct);

    FTestStruct ConvertedStruct;
    UStructToTMapConverter::ConvertTMapToUStruct(ConvertedTMap, ConvertedStruct);

    UE_LOG(LogTemp, Log, TEXT("Converted TMap content:"));
    for (const auto& KeyValuePair : ConvertedTMap)
    {
        UE_LOG(LogTemp, Log, TEXT("Key: %s, Value: %s"), *KeyValuePair.Key, *KeyValuePair.Value);
    }

}