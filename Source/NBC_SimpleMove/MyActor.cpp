// Fill out your copyright notice in the Description page of Project Settings.


#include "MyActor.h"

// Sets default values
AMyActor::AMyActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// 변수 초기화
	stepCnt = 0;
	stepMax = 10;
	start = FVector2D::ZeroVector;
	prev = start;
	evCnt = 0;
	totDist = 0.f;
}

// Called when the game starts or when spawned
void AMyActor::BeginPlay()
{
	Super::BeginPlay();

	UE_LOG(LogTemp, Log, TEXT("Start------------------------------------------------------"));

	// 10걸음 시뮬레이션
	while (stepCnt != stepMax)
	{
		stepCnt++;

		Move();
		if (TriggerEventWithProbability(50.f)) CreateEvent();	// 50% 확률로 이벤트 호출

		if (stepCnt == stepMax)	//이동 종료
		{
			totDist = Distance(FVector2D::ZeroVector, start);
			UE_LOG(LogTemp, Log, TEXT("Total Move Distance : %f"), totDist);
			UE_LOG(LogTemp, Log, TEXT("Total Event Occurred Count : %d"), evCnt);
		}
	}
	UE_LOG(LogTemp, Log, TEXT("Finish------------------------------------------------------"));
}

// Called every frame
void AMyActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AMyActor::Move()
{
	prev = start;		//이동 전 좌표 저장
	start.X += Step();	
	start.Y += Step();

	UE_LOG(LogTemp, Log, TEXT("%d Step Distance [%lf, %lf] : %f"), stepCnt, start.X, start.Y, Distance(start, prev));
}

int32 AMyActor::Step()
{
	return FMath::RandRange(0, 1);	// 0 or 1 랜덤하게 return
}

float AMyActor::Distance(FVector2D first, FVector2D second)
{
	return sqrt(pow(first.X - second.X, 2) + pow(first.Y - second.Y, 2)) ;
}

int32 AMyActor::CreateEvent()
{
	totDist = Distance(FVector2D::ZeroVector, start);		//현재까지 이동거리로 초기화

	UE_LOG(LogTemp, Log, TEXT("(Event) Current Move Distance : %f"), totDist);

	return ++evCnt;		//이벤트 호출 횟수 증가
}

bool AMyActor::TriggerEventWithProbability(float Probability)
{
	int32 RandVal = FMath::RandRange(1, 100);
	if (RandVal > Probability) return true;		//Probability값에 따른 확률적 return
	return false;
}

