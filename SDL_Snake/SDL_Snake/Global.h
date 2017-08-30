#pragma once
#include <SDL.h>
#include <vector>
#include <iostream>
#include <stdlib.h>
#include <M1Random.h>

//Snake 
const int TAILRECT_SIZE = 25;
const float snakeMoveTicks = 150;
const SDL_Color tailrectColor{ 0xFF, 0xFF, 0xFF, 0xFF };
#define _SNAKEHEAD tailrects[0]

//Food
const float RGBTicks = 100;
const int FOOD_SIZE = TAILRECT_SIZE;

//General
const int WINDOW_SIZE = 500;
enum E_GameState { Game_Play = 0, Game_Over = 1 };
enum E_Direction { Direction_Left = 0, Direction_Right = 1, Direction_Up = 2, Direction_Down = 3 };














