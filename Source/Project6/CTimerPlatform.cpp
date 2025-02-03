// Fill out your copyright notice in the Description page of Project Settings.


#include "CTimerPlatform.h"

#include "GameFramework/Character.h"

// Sets default values
ACTimerPlatform::ACTimerPlatform()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Model->SetNotifyRigidBodyCollision(true);
	Model->SetGenerateOverlapEvents(false);
}

void ACTimerPlatform::NotifyHit(class UPrimitiveComponent* MyComp, AActor* Other, class UPrimitiveComponent* OtherComp,
	bool bSelfMoved, FVector HitLocation, FVector HitNormal, FVector NormalImpulse, const FHitResult& Hit)
{
	Super::NotifyHit(MyComp, Other, OtherComp, bSelfMoved, HitLocation, HitNormal, NormalImpulse, Hit);

	if (Cast<ACharacter>(Other) == nullptr || GetWorld()->GetTimerManager().IsTimerActive(Timer))
		return;
	
	GetWorld()->GetTimerManager().SetTimer(Timer, [&]()
	{
		//비활성화
		Model->SetVisibility(false);
		Model->SetCollisionEnabled(ECollisionEnabled::NoCollision);

		//활성화
		GetWorld()->GetTimerManager().SetTimer(Timer, [&]()
		{
			Model->SetVisibility(true);
			Model->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
		}, EnableTime, false);
	}, DisableTime, false);
	
}

// Called when the game starts or when spawned
void ACTimerPlatform::BeginPlay()
{
	Super::BeginPlay();
	
}
