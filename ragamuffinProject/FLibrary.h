#pragma once
#include "UWorldSubSystem.h"

inline UWorldSubSystem& GetWorldSubSystem()
{
	return UWorldSubSystem::GetWorldSubSystem();
}


inline float GetWorldDeltaTime()
{
	return UWorldSubSystem::GetWorldSubSystem().DeltaTime;
}