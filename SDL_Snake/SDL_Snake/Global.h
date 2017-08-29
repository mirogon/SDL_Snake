#pragma once
#include <SDL.h>
#include <vector>
#include <iostream>
#include <stdlib.h>
#include <M1Random.h>

const float RGBTicks = 100;

const int tailrectSize = 25;

const int FOOD_SIZE = tailrectSize;

const float snakeMoveTicks = 200;

const SDL_Color tailrectColor{ 0xFF, 0xFF, 0xFF, 0xFF };

enum E_Direction { Direction_Left = 0, Direction_Right = 1, Direction_Up = 2, Direction_Down = 3 };

#define _SNAKEHEAD tailrects[0]

