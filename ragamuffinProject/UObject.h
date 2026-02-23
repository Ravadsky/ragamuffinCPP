#pragma once

enum class ObjectType { Static, Dynamic, Widget };


class UObject
{
public:
	ObjectType Type;
	virtual void Update() = 0;
};

