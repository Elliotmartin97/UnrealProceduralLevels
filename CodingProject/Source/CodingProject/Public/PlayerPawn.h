// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/ObjectMacros.h"
#include "GameFramework/Pawn.h"
#include "PlayerPawn.generated.h"

class UInputComponent;
class UPawnMovementComponent;
class USphereComponent;
class UStaticMeshComponent;

UCLASS()
class CODINGPROJECT_API APlayerPawn : public APawn
{
	GENERATED_BODY()

public:
	APlayerPawn();
	virtual UPawnMovementComponent* GetMovementComponent() const override;
	virtual void SetupPlayerInputComponent(UInputComponent* InInputComponent) override;
	virtual void UpdateNavigationRelevance() override;
	virtual void MoveForward(float Val);
	virtual void MoveRight(float Val);
	virtual void MoveUp_World(float Val);
	virtual void TurnAtRate(float Rate);
	virtual void LookUpAtRate(float Rate);
	virtual void Tick(float DeltaTime) override;
	void RaycastGround();
	USphereComponent* GetCollisionComponent() const { return CollisionComponent; }
	UStaticMeshComponent* GetMeshComponent() const { return MeshComponent; }
protected:
	virtual void BeginPlay() override;
	UPawnMovementComponent* MovementComponent;
private:
	USphereComponent* CollisionComponent;
	UStaticMeshComponent* MeshComponent;
	float BaseTurnRate;
	float BaseLookUpRate;
	static FName MovementComponentName;
	static FName CollisionComponentName;
	static FName MeshComponentName;
	uint32 bAddDefaultMovementBindings : 1;
};
