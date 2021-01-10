// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "IKFootPlacement.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class FOOTIKPLACEMENT_API UIKFootPlacement : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UIKFootPlacement();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	UPROPERTY(Transient)
	class ACharacter* Character;
	UPROPERTY(Transient)
	class UMeshComponent* Mesh;

	// The name of left foot bone/socket
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "IK | Bone Name", meta = (AllowPrivateAccess = "true"))
	FName LeftFootSocketName;
	// The name of right foot bone/socket
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "IK | Bone Name", meta = (AllowPrivateAccess = "true"))
	FName RightFootSocketName;
	// The name of left virtual bone (add by yourself)
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "IK | Bone Name", meta = (AllowPrivateAccess = "true"))
	FName LeftVirtualBoneName;
	// The name of right virtual bone (add by yourself)
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "IK | Bone Name", meta = (AllowPrivateAccess = "true"))
	FName RightVirtualBoneName;
	// The name of Hip/Pelvis bone
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "IK | Bone Name", meta = (AllowPrivateAccess = "true"))
	FName HipBone;

	// The Z-axis differences between foot bone and actual foot. Please input a positive value
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "IK | Foot Height", meta = (AllowPrivateAccess = "true"))
	float FootHeight;

	FVector LeftFootLocation;
	FVector RightFootLocation;
	float HipZOffset;
	float LeftAlpha;
	float RightAlpha;

	bool bLeftHit;
	bool bRightHit;

	FHitResult LeftHit;
	FHitResult RightHit;

	// Actor that the sphere trace will ignore
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "IK | Actors To Ignore", meta = (AllowPrivateAccess = "true"))
	TArray<AActor*> ActorsToIgnore;

	// The max. value of HipOffset in idle state, the min. value must be 0.f. Please input a positive value
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "IK | HipOffset", meta = (AllowPrivateAccess = "true"))
	float IdleHipOffsetMaxValue;
	// The max. value of HipOffset in moving state, the min. value must be 0.f. Please input a positive value
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "IK | HipOffset", meta = (AllowPrivateAccess = "true"))
	float MovingHipOffsetMaxValue;

	// Sphere Trace for legs
	UFUNCTION()
	bool FootSphereTrace(FName FootSocket, FHitResult& Hit, float StartOffset, float EndOffset);
	// Do the calculation for legs
	UFUNCTION()
	void UpdateFootPosition(FName VirtualBone, FName FootSocket, FHitResult Hit, FVector& FootLocation, float& Alpha, float DeltaTime);
	// Do the calculation for body position
	UFUNCTION()
	void UpdateHipPosition(FHitResult LeftHitResult, FHitResult RightHitResult, float& HipOffset, float DeltaTime);
	// Clamping the Hip Offset
	UFUNCTION()
	float ClampHipOffset(float X, float Min, float Max);

	// Get the location of left foot
	UFUNCTION(BlueprintCallable, BlueprintPure)
	FVector GetLeftFootEffector() {return LeftFootLocation;}
	// Get the location of right foot
	UFUNCTION(BlueprintCallable, BlueprintPure)
	FVector GetRightFootEffector() {return RightFootLocation;}
	// Get the alpha of left foot
	UFUNCTION(BlueprintCallable, BlueprintPure)
	float GetLeftFootAlpha() {return LeftAlpha;}
	// Get the alpha of right foot
	UFUNCTION(BlueprintCallable, BlueprintPure)
	float GetRightFootAlpha() {return RightAlpha;}
	// Get the offset of Hip
	UFUNCTION(BlueprintCallable, BlueprintPure)
	float GetHipOffset() {return HipZOffset;}

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

		
};
