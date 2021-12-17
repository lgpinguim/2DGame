// Fill out your copyright notice in the Description page of Project Settings.


#include "Jogo2DObjectiveActor.h"

#include "Jogo2DCharacter.h"
#include "Components/SphereComponent.h"
#include "Kismet/GameplayStatics.h"

class USphereComponent;
// Sets default values
AJogo2DObjectiveActor::AJogo2DObjectiveActor()
{
 		// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
    	PrimaryActorTick.bCanEverTick = true;
    
    	MeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComp"));
    	MeshComp->SetCollisionEnabled(ECollisionEnabled::NoCollision);
    	RootComponent = MeshComp;
    
    	SphereComp = CreateDefaultSubobject<USphereComponent>(TEXT("SphereComp"));
    	SphereComp->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
    	SphereComp->SetCollisionResponseToAllChannels(ECR_Ignore);
    	SphereComp->SetCollisionResponseToChannel(ECC_Pawn,ECR_Overlap);
    	SphereComp->SetupAttachment(MeshComp);

}

// Called when the game starts or when spawned
void AJogo2DObjectiveActor::BeginPlay()
{
	Super::BeginPlay();
	
	PlayEffects();
	
}

// Called every frame
void AJogo2DObjectiveActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AJogo2DObjectiveActor::PlayEffects()
{
	UGameplayStatics ::SpawnEmitterAtLocation(this, PickupFX,GetActorLocation());
}

void AJogo2DObjectiveActor::NotifyActorBeginOverlap(AActor* OtherActor)
{
	Super::NotifyActorBeginOverlap(OtherActor);

	PlayEffects();

	AJogo2DCharacter* MyCharacter = Cast<AJogo2DCharacter>(OtherActor);
	if (MyCharacter)
	{
		//TODO: collect logic
	}
}
