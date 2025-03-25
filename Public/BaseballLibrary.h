// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "BaseballLibrary.generated.h"

/**
 * 
 */
UCLASS()
class SAMPLECHAT_API UBaseballLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
    // 중복 없는 3자리 랜덤 숫자 생성 (1-9)
    UFUNCTION(BlueprintCallable, Category = "Baseball Game")
    static FString GenerateRandomNumber();

    // 유효한 입력인지 확인
    UFUNCTION(BlueprintCallable, Category = "Baseball Game")
    static bool IsValidInput(const FString& Input, FString& OutCleanedInput);

    // 스트라이크와 볼 계산
    UFUNCTION(BlueprintCallable, Category = "Baseball Game")
    static FString CalculateResult(const FString& Target, const FString& CleanedInput);
};
