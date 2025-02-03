// Fill out your copyright notice in the Description page of Project Settings.


#include "CRotatePlatform.h"

// Sets default values
ACRotatePlatform::ACRotatePlatform()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ACRotatePlatform::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACRotatePlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	FRotator rotateAxis(bRotateYAxis, bRotateZAxis, bRotateXAxis);
	AddActorLocalRotation(rotateAxis * RotateSpeed * DeltaTime);
	
}

