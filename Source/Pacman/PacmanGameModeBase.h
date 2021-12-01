// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "PacmanGameModeBase.generated.h"

/**
 * 
 */
UENUM(BlueprintType)
enum class EGameState : uint8
{
	EMenu,
	EPlay,
	EPause,
	Ewin,
	EGameOver
};

UCLASS()
class PACMAN_API APacmanGameModeBase : public AGameModeBase
{
	GENERATED_BODY()
	
public:
	void StartGame();
	void PauseGame();
	void RestartGame();

	void SetEnemiesVulnerable();

	void RecordEnemiesTimer();
	void RestoreEnemiesTimer();
	APacmanGameModeBase();
	int GetPacdotNum() const;
	void SetPacdotNum(int Value);
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	int PacdotNum;
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	EGameState CurrentState;

	EGameState GetCurrentState() const;
	void SetCurrentState(EGameState Value);


protected:
	virtual void BeginPlay() override;
private:
	TArray<class APacmanEnemy*> Enemies;
	TArray<float> EnemiesTimerRemaining;
};

FORCEINLINE int APacmanGameModeBase::GetPacdotNum() const
{
	return PacdotNum;
};
FORCEINLINE EGameState APacmanGameModeBase::GetCurrentState() const
{
	return CurrentState;
};