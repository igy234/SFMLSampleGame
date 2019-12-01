#pragma once

#include "stdafx.h"
#include "EnumScreenFields.h"

tuple<int, int, int, int> CalcualteStartingPoint(int windowX, int windowY, EnumScreenFields column, EnumScreenFields row); //4 returns in one object in one place (4 ints)

int getRand(int n);

static float RiskAllCards[8][8] =
{
	{2, 1.7, 1.4, 1.1, 0.8, 0.5, 0.2, 0},
	{1.7, 1.4, 1.1, 0.8, 0.5, 0.2, 0, -0.2},
	{1.4, 1.1, 0.8, 0.5, 0.2, 0, -0.2, -0.5},
	{1.1, 0.8, 0.5, 0.2, 0, -0.2, -0.5, -0.8},
	{0.8, 0.5, 0.2, 0, -0.2, -0.5, -0.8, -1.1},
	{0.5, 0.2, 0, -0.2, -0.5, -0.8, -1.1, -1.4},
	{0.2, 0, -0.2, -0.5, -0.8, -1.1, -1.4, -1.7},
	{0, -0.2, -0.5, -0.8, -1.1, -1.4, -1.7, -2},
};

static float RiskKingCard[8] = {0, 0.5, 1, 1.5, 2, 1.5, 1, 0.5};

static float RiskDestroyingCardsWithoutKing[15] = {-2, -1.7, -1.4, -1.1, -0.8, -0.5, -0.2, 0, 0.2, 0.5, 0.8, 1.1, 1.4, 1.7, 2};

static float RiskNormalCardsDependingOnDragons[8][8]=
{
	{0, 1.5, 3, 4, 4, 4, 4, 4},
	{0, 1.2, 2.5, 4, 4, 4, 4, 4},
	{0, 0.9, 2, 4, 2, 2, 2, 2},
	{0, 0.6, 1, 2, 1, 1, 1, 1},
	{0, 0.3, 0.5, 2, 0, 0, 0, 0},
	{0, 0, 0, 0, -1, -1, -1, -1},
	{0, -0.3, -0.7, -1, -2, -2, -2, -2},
	{0, -0.7, -1, -2, -3, -3, -3, -3},
};

static float RiskDestroyingCardsDependingOnDragons[14] = {0, 1.5, 4, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5};

static float RiskAddingCards[14] = {2, 1.8, 1.6, 1.4, 1.2, 1, 0.8, 0.6, 0.4, 0.2, 0, -0.2, -0.4, -0.6};

static float RiskIceQueen[7][7]=
{
	{1.2, 1, 0.8, 0.6, 0.4, 0.2, 0},
	{1, 0.8, 0.6, 0.4, 0.2, 0, -0.2},
	{0.8, 0.6, 0.4, 0.2, 0, -0.2, -0.4},
	{0.6, 0.4, 0.2, 0, -0.2, -0.4, -0.6},
	{0.4, 0.2, 0, -0.2, -0.4, -0.6, -0.8},
	{0.2, 0, -0.2, -0.4, -0.6, -0.8, -1},
	{0, -0.2, -0.4, -0.6, -0.8, -1, -1.2}
};