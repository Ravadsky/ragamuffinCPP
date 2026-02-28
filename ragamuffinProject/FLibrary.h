#pragma once
#include "UWorldSubSystem.h"
#include <cstdlib>

inline UWorldSubSystem& GetWorldSubSystem()
{
	return UWorldSubSystem::GetWorldSubSystem();
}

inline int GetRandomInt(int&& min, int&& max)
{
	int dif = max - min;
	if (!dif) return min;
	else return (rand() % (dif+1) + min);
}

inline float GetWorldDeltaTime()
{
	return UWorldSubSystem::GetWorldSubSystem().DeltaTime;
}