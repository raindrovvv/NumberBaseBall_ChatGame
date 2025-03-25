#include "BaseballLibrary.h"

// 무작위 야구 숫자를 생성하는 라이브러리
FString UBaseballLibrary::GenerateRandomNumber()
{
    // 1부터 9까지 숫자를 담을 배열
    TArray<int32> Numbers;
    for (int32 i = 1; i <= 9; i++)
    {
        Numbers.Add(i);
    }

    // 배열을 무작위로 섞어 3개의 자리수를 만들 준비
    for (int32 i = 0; i < Numbers.Num(); i++)
    {
        int32 RandomIndex = FMath::RandRange(i, Numbers.Num() - 1);
        if (i != RandomIndex)
        {
            Numbers.Swap(i, RandomIndex); // 현재 인덱스와 무작위 인덱스를 교환
        }
    }

    // 섞인 배열에서 앞의 3자리만 문자열로 생성
    FString Result;
    for (int32 i = 0; i < 3; i++)
    {
        Result.AppendInt(Numbers[i]); // 숫자를 문자열로 추가
    }

    return Result;
}

// 사용자가 입력한 문자열이 조건(길이, 범위, 중복)에 맞는지 검증하고, 정제된 입력값을 반환
bool UBaseballLibrary::IsValidInput(const FString& Input, FString& OutCleanedInput)
{
    OutCleanedInput.Empty();
    for (int32 i = 0; i < Input.Len(); i++)
    {
        if (Input[i] >= '0' && Input[i] <= '9')
        {
            OutCleanedInput.AppendChar(Input[i]);
        }
    }
    UE_LOG(LogTemp, Warning, TEXT("⚡IsValidInput: 정제된 입력값: %s"), *OutCleanedInput);

    if (OutCleanedInput.Len() != 3)
    {
        UE_LOG(LogTemp, Warning, TEXT("🔴IsValidInput: 길이가 3이 아님 (길이: %d)"), OutCleanedInput.Len());
        return false;
    }

    for (int32 i = 0; i < 3; i++)
    {
        if (OutCleanedInput[i] < '1' || OutCleanedInput[i] > '9')
        {
            UE_LOG(LogTemp, Warning, TEXT("🔴IsValidInput: %d번째 문자 범위 오류 (값: %c, ASCII: %d)"),
                i, OutCleanedInput[i], (int32)OutCleanedInput[i]);
            return false;
        }
    }

    for (int32 i = 0; i < 3; i++)
    {
        for (int32 j = i + 1; j < 3; j++)
        {
            if (OutCleanedInput[i] == OutCleanedInput[j])
            {
                UE_LOG(LogTemp, Warning, TEXT("🔴IsValidInput: 중복 발견"));
                return false;
            }
        }
    }

    UE_LOG(LogTemp, Log, TEXT("IsValidInput: 유효한 입력 확인: %s"), *OutCleanedInput);
    return true;
}

// 스트라이크와 볼을 계산해 반환
FString UBaseballLibrary::CalculateResult(const FString& Target, const FString& CleanedInput)
{
    int32 Strikes = 0;
    int32 Balls = 0;

    UE_LOG(LogTemp, Warning, TEXT("➡️CalculateResult: 타겟: %s, 입력: %s"), *Target, *CleanedInput);

    for (int32 i = 0; i < 3; i++)
    {
        if (CleanedInput[i] == Target[i])
        {
            Strikes++;
            UE_LOG(LogTemp, Warning, TEXT("➡️CalculateResult: %d번째 자리 스트라이크 (숫자: %c)"), i, CleanedInput[i]);
        }
        else
        {
            for (int32 j = 0; j < 3; j++)
            {
                if (CleanedInput[i] == Target[j] && i != j)
                {
                    Balls++;
                    UE_LOG(LogTemp, Warning, TEXT("➡️CalculateResult: %d번째 자리 볼 (숫자: %c, 타겟 위치: %d)"), i, CleanedInput[i], j);
                }
            }
        }
    }

    // 스트라이크와 볼이 모두 0이면 OUT
    if (Strikes == 0 && Balls == 0)
    {
        return TEXT("OUT");
    }

    // 그렇지 않으면 "xS yB" 형태의 문자열 반환
    return FString::Printf(TEXT("%dS%dB"), Strikes, Balls);
}
