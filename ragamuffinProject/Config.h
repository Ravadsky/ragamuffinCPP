#pragma once
#include <string>
#include <SFML/Graphics.hpp>

// FILE SYSTEM
const std::string RESOURCES_PATH = "Resources/";

// WINDOW 
const int WINDOW_HEIGHT = 720;
const int WINDOW_WIGHT = 1280;
const sf::Vector2f CAMERA_PIVOT = { WINDOW_WIGHT / 2, WINDOW_HEIGHT / 2 };

// SPRITE / RENDER
const int SPRITE_RAW_SIZE = 8;
const int SPRITE_GAME_SIZE = 128;
const sf::Vector2f OBJECT_SIZE = { SPRITE_GAME_SIZE / SPRITE_RAW_SIZE, SPRITE_GAME_SIZE / SPRITE_RAW_SIZE };

// PLAYER
const float PLAYER_SPEED = 400.f;

// WORLD GENERATION
const int ROOM_COUNT = 4;
const int ROOM_SIZE = 10;
const int WORLD_SIZE = 9;
const float WORLD_CENTER = static_cast<float>(WORLD_SIZE * (SPRITE_GAME_SIZE * ROOM_SIZE)) / 2;

// ANIM
const int ANIM_FRAMES_COUNT = 6;
const float ANIM_SPEED = 0.5f;
const float ANIM_DELTA_TIME = 1 / (ANIM_FRAMES_COUNT * ANIM_SPEED);
