#pragma once

enum class ObjectType { Static, Dynamic, Widget, NonDrawable };


class UObject
{
public:
	ObjectType Type = ObjectType::NonDrawable;
	virtual void Update() = 0;
};

