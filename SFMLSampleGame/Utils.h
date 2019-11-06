#pragma once

#include "stdafx.h"
#include "EnumScreenFields.h"

tuple<int, int, int, int> CalcualteStartingPoint(int windowX, int windowY, EnumScreenFields column, EnumScreenFields row); //4 returns in one object in one place (4 ints)
