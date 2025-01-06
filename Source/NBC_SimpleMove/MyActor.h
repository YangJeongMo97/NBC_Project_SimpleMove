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

	// �̵� ����
	void Move();
	int32 Step();

	// �Ÿ�
	float Distance(FVector2D first, FVector2D second);

	// �̺�Ʈ ����
	int32 CreateEvent();
	bool TriggerEventWithProbability(float Probability);

private:
	int32 stepCnt;	// ���� ���� ��
	int32 stepMax;	// �ִ� ���� ��
	FVector2D start;// ���� ��ǥ
	FVector2D prev;	// ���� ��ǥ
	int32 evCnt;	// �̺�Ʈ ���� Ƚ��
	float totDist;	// �� �̵� �Ÿ�
};
