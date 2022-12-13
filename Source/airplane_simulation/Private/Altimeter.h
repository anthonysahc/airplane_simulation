// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Altimeter.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class UAltimeter : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UAltimeter();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UFUNCTION(BlueprintCallable)
		void SetTarget(AActor* Target);

private:

	AActor* m_target =  nullptr;

	UPROPERTY(EditAnywhere)
		double m_maxAltitude = 10000;

	FRotator m_startRotation = FRotator();

	void SetAltitudeNeedle();



		
};
