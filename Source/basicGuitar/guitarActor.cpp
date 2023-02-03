// Fill out your copyright notice in the Description page of Project Settings.


#include "guitarActor.h"
#include "Components/BoxComponent.h"
#include "Engine/Engine.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
AguitarActor::AguitarActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	CollisionBox = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxComponent"));
	CollisionBox->SetBoxExtent(FVector(2176.f, 20.16f, 44.8f));
	CollisionBox->SetCollisionProfileName("Trigger");
	RootComponent = CollisionBox;

	CollisionBox->OnComponentBeginOverlap.AddDynamic(this, &AguitarActor::OnOverlapBegin);
	CollisionBox->OnComponentEndOverlap.AddDynamic(this, &AguitarActor::OnOverlapEnd);
}

// Called when the game starts or when spawned
void AguitarActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AguitarActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AguitarActor::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	//GEngine->AddOnScreenDebugMessage(-1, 1.f, FColor::Green, "Overlap Begin Function Called");
	UGameplayStatics::PlaySoundAtLocation(GetWorld(), String1Sound, GetActorLocation(), 3.0f, 1.0f, 0.0f);
}

void AguitarActor::OnOverlapEnd(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	//GEngine->AddOnScreenDebugMessage(-1, 1.f, FColor::Red, "Overlap End Function Called");
}


