// Fill out your copyright notice in the Description page of Project Settings.


#include "Altimeter.h"

// Sets default values for this component's properties
UAltimeter::UAltimeter()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UAltimeter::BeginPlay()
{
	Super::BeginPlay();

	m_startRotation = GetOwner()->GetActorRotation();
	
}


// Called every frame
void UAltimeter::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	SetAltitudeNeedle();
}

void UAltimeter::SetTarget(AActor* Target)
{
	m_target = Target;
}

void UAltimeter::SetAltitudeNeedle()
{	

	if (m_target != nullptr)
	{
		double altitude = m_target->GetActorLocation().Z;


		FRotator rotation = FRotator(altitude * 360 / m_maxAltitude, m_startRotation.Yaw, m_startRotation.Roll);

		if (altitude > m_maxAltitude)
		{
			GetOwner()->SetActorRotation(FRotator(360, m_startRotation.Yaw, m_startRotation.Roll));
		}
		else if (altitude > 0)
		{
			UE_LOG(LogTemp, Display, TEXT("Rotation : %s"), *rotation.ToString());
			GetOwner()->SetActorRotation(rotation);
			UE_LOG(LogTemp, Display, TEXT("Rotation Owner : %s"), *GetOwner()->GetActorRotation().ToString());
		}
		else
		{
			GetOwner()->SetActorRotation(FRotator(0, m_startRotation.Yaw , m_startRotation.Roll));
		}
	}
	
}


