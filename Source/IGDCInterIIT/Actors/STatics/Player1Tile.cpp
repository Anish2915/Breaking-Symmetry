// Fill out your copyright notice in the Description page of Project Settings.


#include "Player1Tile.h"
#include "../BasicParent.h"
#include "A_ArenaGameMode.h"
void APlayer1Tile::action(ABasicParent* DynamicClass)
{
	if (!DynamicClass) return;
	if (int(DynamicClass->Type) >= 4 && int(DynamicClass->Type)<=8) {
		GameMode->currPlayer1 = DynamicClass->Next;
		GameMode->currPlayer1->change_level(1);
		DynamicClass->Next->change_level(2);
	}
}

void APlayer1Tile::reaction(ABasicParent* DynamicClass)
{
	if (!DynamicClass) return;
	if (int(DynamicClass->Type) >= 4 && int(DynamicClass->Type) <= 8) {
		DynamicClass->Next->change_level(1);
		GameMode->currPlayer1 = nullptr;
	}
}
