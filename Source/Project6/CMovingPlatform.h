// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CPlatform.h"
#include "CMovingPlatform.generated.h"

UCLASS()
class PROJECT6_API ACMovingPlatform : public ACPlatform
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta=(MakeEditWidget))
	FVector MoveLocation;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float MoveSpeed;
	
private:
	FVector StartPos;
	bool bReturn;
	float MoveLocationLerpValue;
	
public:	
	// Sets default values for this actor's properties
	ACMovingPlatform();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
