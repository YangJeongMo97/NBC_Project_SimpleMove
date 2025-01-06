// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MyActor.generated.h"

UCLASS()
class NBC_SIMPLEMOVE_API AMyActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMyActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// 이동 관련
	void Move();
	int32 Step();

	// 거리
	float Distance(FVector2D first, FVector2D second);

	// 이벤트 관련
	int32 CreateEvent();
	bool TriggerEventWithProbability(float Probability);

private:
	int32 stepCnt;	// 현재 걸음 수
	int32 stepMax;	// 최대 걸음 수
	FVector2D start;// 현재 좌표
	FVector2D prev;	// 이전 좌표
	int32 evCnt;	// 이벤트 실행 횟수
	float totDist;	// 총 이동 거리
};
