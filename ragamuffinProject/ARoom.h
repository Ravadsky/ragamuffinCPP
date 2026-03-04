#pragma once
#include "UObject.h"
#include "AActor.h"
#include "CoreMinimal.h"
#include <unordered_map>


class ARoom : public UObject
{
private:

    std::unordered_map<char, int> KeySymbols
    {
        {'1', 2001},
        {'2', 2002},
        {'3', 3001}
    };

    const std::string RoomNames[ROOM_COUNT] =
    {
        "START_ROOM:",
        "ROOM1:",
        "ROOM2:",
        "WALL:"
    };
public:
    ARoom(int x, int y);
    ARoom(int x, int y, int RoomIndex);

    virtual void Update() override;

};

