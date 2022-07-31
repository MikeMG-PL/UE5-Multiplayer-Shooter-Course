// Fill out your copyright notice in the Description page of Project Settings.


#include "BlasterAnimInstance.h"

#include "BlasterCharacter.h"
#include "GameFramework/CharacterMovementComponent.h"

void UBlasterAnimInstance::NativeInitializeAnimation()
{
	Super::NativeInitializeAnimation();

	BlasterCharacter = Cast<ABlasterCharacter>(TryGetPawnOwner());
}

void UBlasterAnimInstance::NativeUpdateAnimation(float DeltaSeconds)
{
	Super::NativeUpdateAnimation(DeltaSeconds);

	if(BlasterCharacter == nullptr)
		BlasterCharacter = Cast<ABlasterCharacter>(TryGetPawnOwner());

	if(BlasterCharacter == nullptr) return;

	// Setting up Speed
	FVector Velocity = BlasterCharacter->GetVelocity();
	Velocity.Z = 0;
	Speed = Velocity.Size();

	// Setting up bIsInAir
	bIsInAir = BlasterCharacter->GetCharacterMovement()->IsFalling();

	// Setting up bIsAccelerating
	bIsAccelerating = BlasterCharacter->GetCharacterMovement()->GetCurrentAcceleration().Size() > 0 ? true : false;	
}
