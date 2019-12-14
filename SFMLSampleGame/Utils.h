#pragma once
#include "stdafx.h"
#include "EnumScreenFields.h"

/**
 * \file
 * Utils.h : file holding some of the program utilities 
 * and hardcoded values 
 */

///@brief method calcualting starting points of drawing for gui elements
///@param "windowX" representing window's width
///@param "windowY" representing window's height
///@param "row" representing row in net (divided screen parts)
///@param "column" representing colum in net (divided screen parts)
///@return 4 ints in tuple type 
tuple<int, int, int, int> CalcualteStartingPoint(int windowX, int windowY, EnumScreenFields column, EnumScreenFields row); //4 returns in one object in one place (4 ints)

///@brief method used for pseudo random generation of numbers in given range
///@param "n" representing range for random values
///@returns generated pseudo random value
int getRand(int n);

///Risk Table for all cards with filled risk values, used in calcualtions of AI's play coefficient
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

///Risk Table for King cards with filled risk values, used in calcualtions of AI's play coefficient
static float RiskKingCard[8] = {0, 0.5, 1, 1.5, 2, 1.5, 1, 0.5};

///Risk Table for destroying (without king) cards with filled risk values, used in calcualtions of AI's play coefficient
static float RiskDestroyingCardsWithoutKing[15] = {-2, -1.7, -1.4, -1.1, -0.8, -0.5, -0.2, 0, 0.2, 0.5, 0.8, 1.1, 1.4, 1.7, 2};

///Risk Table for non-special cards depending on number of dragons on battlefield  with filled risk values, used in calcualtions of AI's play coefficient
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

///Risk Table for destroying cards depending on number of dragons on battlefield with filled risk values, used in calcualtions of AI's play coefficient
static float RiskDestroyingCardsDependingOnDragons[14] = {0, 1.5, 4, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5};

///Risk Table for adding cards with filled risk values, used in calcualtions of AI's play coefficient
static float RiskAddingCards[14] = {2, 1.8, 1.6, 1.4, 1.2, 1, 0.8, 0.6, 0.4, 0.2, 0, -0.2, -0.4, -0.6};

///Risk Table for Ice Queen cards with filled risk values, used in calcualtions of AI's play coefficient
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