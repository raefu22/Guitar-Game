// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "guitarActor.generated.h"

UCLASS()
class BASICGUITAR_API AguitarActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AguitarActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
		class UBoxComponent* CollisionBox;

	UFUNCTION()
		void OnOverlapBegin(UPrimitiveComponent * OverlappedComp, AActor * OtherActor, UPrimitiveComponent * OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult );

	UFUNCTION()
		void OnOverlapEnd(UPrimitiveComponent* OverlapspedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);
	UPROPERTY(EditAnywhere, Category = String1)
		USoundBase* String1Sound;
};