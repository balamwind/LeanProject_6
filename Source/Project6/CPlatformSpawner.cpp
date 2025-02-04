// Fill out your copyright notice in the Description page of Project Settings.


#include "CPlatformSpawner.h"

#include "CMovingPlatform.h"
#include "CPlatform.h"
#include "CRotatePlatform.h"

ACPlatformSpawner::ACPlatformSpawner()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

void ACPlatformSpawner::BeginPlay()
{
	Super::BeginPlay();

	int size = RandomPlatformLocationActorArray.Num();
	for (int i = 0; i < size; i++)
	{
		FVector location = RandomPlatformLocationActorArray[i]->GetActorLocation();

		int random = FMath::RandRange(0, PlatformClassArray.Num() - 1);
		ACPlatform* platform = Cast<ACPlatform>(GetWorld()->SpawnActor(PlatformClassArray[random], &location));

		float randomSize = FMath::RandRange(1.f, 3.f);
		platform->SetActorScale3D(FVector::OneVector * randomSize);
		
		if (ACMovingPlatform* movingPlat = Cast<ACMovingPlatform>(platform))
			movingPlat->MoveSpeed = FMath::RandRange(100, 400);
		
		if (ACRotatePlatform* rotatePlat = Cast<ACRotatePlatform>(platform))
		{
			rotatePlat->RotateSpeed = FMath::RandRange(50, 400);
			rotatePlat->bRotateXAxis = static_cast<bool>(FMath::RandRange(0, 1));
			rotatePlat->bRotateYAxis = static_cast<bool>(FMath::RandRange(0, 1));
			rotatePlat->bRotateZAxis = static_cast<bool>(FMath::RandRange(0, 1));
		}
	}
}

void ACPlatformSpawner::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}
