// Fill out your copyright notice in the Description page of Project Settings.


#include "HelloSphere.h"

#include "Components/SphereComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Engine/Classes/Particles/ParticleSystemComponent.h"

#include "Engine/Classes/Components/TextRenderComponent.h"

// Sets default values
AHelloSphere::AHelloSphere()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	USphereComponent* SphereComponent =
		CreateDefaultSubobject<USphereComponent>(TEXT("RootComponenet"));

	RootComponent = SphereComponent;
	SphereComponent->InitSphereRadius(200.0f);
	SphereComponent->SetCollisionProfileName(TEXT("OverlapAllDynamic"));

	UStaticMeshComponent* SphereVisual = 
		CreateDefaultSubobject<UStaticMeshComponent>(TEXT("SphereMesh"));
	SphereVisual->AttachTo(RootComponent);

	ConstructorHelpers::FObjectFinder<UStaticMesh>
		SphereAsset(TEXT("/Game/StarterContent/Shapes/Shape_Sphere.Shape_Sphere"));
	if (SphereAsset.Succeeded())
	{
		SphereVisual->SetStaticMesh(SphereAsset.Object);
		SphereVisual->SetRelativeLocation(FVector(0.0f, 0.0f, -50.0f));
	}

	UParticleSystemComponent* FireParticles =
		CreateDefaultSubobject<UParticleSystemComponent>(TEXT("FireParticles"));
	FireParticles->AttachTo(SphereVisual);
	FireParticles->bAutoActivate = true;

	ConstructorHelpers::FObjectFinder<UParticleSystem>
		FireVisual(TEXT("/Game/StarterContent/Particles/P_Fire.P_Fire"));
	if (FireVisual.Succeeded())
	{
		FireParticles->SetTemplate(FireVisual.Object);
	}

	UTextRenderComponent* TextRenderComponenet =
		CreateDefaultSubobject<UTextRenderComponent>(TEXT("Text"));

	TextRenderComponenet->AttachTo(SphereVisual);
	TextRenderComponenet->SetRelativeLocation(FVector(0.0f, 0.0f, 100.0f));
	TextRenderComponenet->SetHorizontalAlignment(EHTA_Center);
	TextRenderComponenet->SetYScale(2.0f);
	TextRenderComponenet->SetXScale(2.0f);
	TextRenderComponenet->SetVisibility(true);
	TextRenderComponenet->SetText(NSLOCTEXT("AnyNs","Any","Hello World")); // 앞에 두개는 아무거나 해도 됨
}

// Called when the game starts or when spawned
void AHelloSphere::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AHelloSphere::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AHelloSphere::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

