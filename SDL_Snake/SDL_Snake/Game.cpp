#include "Game.h"

C_Game::C_Game(): snake{ C_Snake(0,0) }, food{ C_Food(0,0) }
{
	snake.AddTailrect();
	snake.AddTailrect();
	snake.AddTailrect();

	GenerateFood();
}

void C_Game::Game_Reset()
{
	snake = C_Snake(0, 0);
	food = C_Food(0, 0);
	snake.AddTailrect();
	snake.AddTailrect();
	snake.AddTailrect();
	GenerateFood();
}

void C_Game::GenerateFood()
{
	food.Spawn(_RandomNumer(0, WINDOW_SIZE/TAILRECT_SIZE) * TAILRECT_SIZE, _RandomNumer(0,WINDOW_SIZE/TAILRECT_SIZE) * TAILRECT_SIZE);
}