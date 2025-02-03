// Fill out your copyright notice in the Description page of Project Settings.


#include "CMovingPlatform.h"

// Sets default values
ACMovingPlatform::ACMovingPlatform()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void ACMovingPlatform::BeginPlay()
{
	Super::BeginPlay();

	StartPos = GetActorLocation();
}

// Called every frame
void ACMovingPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	float length = MoveLocation.Length();
	SetActorLocation(FMath::Lerp(StartPos, StartPos + MoveLocation, MoveLocationLerpValue));
	MoveLocationLerpValue += (bReturn ? -1 : 1) * MoveSpeed / length * 3 * DeltaTime ;

	//되돌아옴
	if (bReturn && MoveLocationLerpValue <= 0)
	{
		bReturn = false;
		MoveLocationLerpValue = 0;
	}
	else if (!bReturn && MoveLocationLerpValue >= 1)
	{
		bReturn = true;
		MoveLocationLerpValue = 1;
	}
}
