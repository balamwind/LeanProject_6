// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CPlatform.h"
#include "CRotatePlatform.generated.h"

UCLASS()
class PROJECT6_API ACRotatePlatform : public ACPlatform
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category= "CRotatePlatform|RotateAxis")
	bool bRotateXAxis;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category= "CRotatePlatform|RotateAxis")
	bool bRotateYAxis;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category= "CRotatePlatform|RotateAxis")
	bool bRotateZAxis;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float RotateSpeed;
	
public:	
	// Sets default values for this actor's properties
	ACRotatePlatform();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
