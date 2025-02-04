// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CPlatformSpawner.generated.h"

class ACPlatform;

UCLASS()
class PROJECT6_API ACPlatformSpawner : public AActor
{
	GENERATED_BODY()
	
public:
	ACPlatformSpawner();
	virtual void Tick(float DeltaTime) override;
	
protected:
	virtual void BeginPlay() override;

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<TSubclassOf<ACPlatform>> PlatformClassArray;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<TObjectPtr<AActor>> RandomPlatformLocationActorArray;
};
