#pragma once

enum class ObjectType { Static, Dynamic, Widget, NonDrawable };


class UObject
{
public:
	ObjectType Type;
	virtual void Update() = 0;
};

