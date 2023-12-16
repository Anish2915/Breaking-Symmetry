// Fill out your copyright notice in the Description page of Project Settings.


#include "BlueMoveTile.h"
#include "../BasicParent.h"
#include "A_ArenaGameMode.h"

void ABlueMoveTile::action(ABasicParent* DynamicClass)
{
	if (!DynamicClass) return;
	if (int(DynamicClass->Type) >= 0 && int(DynamicClass->Type) <= 3) {
		GameMode->Func_Mapping[0][int(DynamicClass->Type)] = int(ArrowDir) + 1;
	}
}

void ABlueMoveTile::reaction(ABasicParent* DynamicClass)
{
	UE_LOG(LogTemp, Warning, TEXT("RedMove Reaction start"));
	if (!DynamicClass) return;
	UE_LOG(LogTemp, Warning, TEXT("RedMove reaction type %d"), int(DynamicClass->Type));
	if (int(DynamicClass->Type) >= 0 && int(DynamicClass->Type) <= 3) {
		GameMode->Func_Mapping[0][int(DynamicClass->Type)] = 0;
	}
}
