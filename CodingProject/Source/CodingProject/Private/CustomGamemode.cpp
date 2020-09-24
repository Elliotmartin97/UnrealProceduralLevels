// Fill out your copyright notice in the Description page of Project Settings.


#include "CustomGamemode.h"
#include "PlayerPawn.h"

ACustomGamemode::ACustomGamemode()
{
    PrimaryActorTick.bCanEverTick = false;
    PrimaryActorTick.bStartWithTickEnabled = false;
    PrimaryActorTick.bAllowTickOnDedicatedServer = false;

    DefaultPawnClass = APlayerPawn::StaticClass();
}