#pragma once
#include <string>
#include <SFML/Graphics.hpp>

const std::string RESOURCES_PATH = "Resources/";

const int WINDOW_HEIGHT = 720;
const int WINDOW_WIGHT = 1280;
const sf::Vector2f CAMERA_PIVOT = { WINDOW_WIGHT / 2, WINDOW_HEIGHT / 2 };

const int SPRITE_RAW_SIZE = 8;
const int SPRITE_GAME_SIZE = 128;

const int ROOM_COUNT = 4;
const int ROOM_SIZE = 10;
const int WORLD_SIZE = 9;