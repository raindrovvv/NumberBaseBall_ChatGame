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
    // �ߺ� ���� 3�ڸ� ���� ���� ���� (1-9)
    UFUNCTION(BlueprintCallable, Category = "Baseball Game")
    static FString GenerateRandomNumber();

    // ��ȿ�� �Է����� Ȯ��
    UFUNCTION(BlueprintCallable, Category = "Baseball Game")
    static bool IsValidInput(const FString& Input, FString& OutCleanedInput);

    // ��Ʈ����ũ�� �� ���
    UFUNCTION(BlueprintCallable, Category = "Baseball Game")
    static FString CalculateResult(const FString& Target, const FString& CleanedInput);
};
