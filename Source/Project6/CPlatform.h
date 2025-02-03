// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CPlatform.generated.h"

UCLASS()
class PROJECT6_API ACPlatform : public AActor
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	TObjectPtr<USceneComponent> Root;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	TObjectPtr<class UStaticMeshComponent> Model; 
	
public:	
	// Sets default values for this actor's properties
	ACPlatform();
};
