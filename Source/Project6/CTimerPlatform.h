// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CPlatform.h"
#include "GameFramework/Actor.h"
#include "CTimerPlatform.generated.h"

UCLASS()
class PROJECT6_API ACTimerPlatform : public ACPlatform
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float DisableTime;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float EnableTime;

	FTimerHandle Timer;
	
public:	
	// Sets default values for this actor's properties
	ACTimerPlatform();

	virtual void NotifyHit(class UPrimitiveComponent* MyComp, AActor* Other, class UPrimitiveComponent* OtherComp, bool bSelfMoved, FVector HitLocation, FVector HitNormal, FVector NormalImpulse, const FHitResult& Hit) override;
	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
};
