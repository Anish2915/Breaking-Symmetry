// Fill out your copyright notice in the Description page of Project Settings.


#include "Player2Tile.h"
#include "../BasicParent.h"
#include "A_ArenaGameMode.h"

void APlayer2Tile::action(ABasicParent* DynamicClass)
{
	if (!DynamicClass) return;
	if (int(DynamicClass->Type) >= 4 && int(DynamicClass->Type) <= 8) {
		GameMode->currPlayer2 = DynamicClass->Next;
		GameMode->currPlayer2->change_level(1);
		DynamicClass->Next->change_level(2);
	}
}

void APlayer2Tile::reaction(ABasicParent* DynamicClass)
{
	if (!DynamicClass) return;
	if (int(DynamicClass->Type) >= 4 && int(DynamicClass->Type) <= 8) {
		DynamicClass->Next->change_level(1);
		GameMode->currPlayer2 = nullptr;
	}
}
