#pragma once
#include "Snake.h"

class C_Game
{

public:

	C_Game();
	~C_Game() = default;

	void Game_Play();


private:

	void GenerateFood();

	C_Snake snake;
	C_Food food;
};

inline void C_Game::Game_Play()
{
	if (m1::KeyIsPressed(SDL_SCANCODE_A) == true)
	{
		snake.ChangeDirection(Direction_Left);
	}

	else if (m1::KeyIsPressed(SDL_SCANCODE_D) == true)
	{
		snake.ChangeDirection(Direction_Right);
	}

	else if (m1::KeyIsPressed(SDL_SCANCODE_W) == true)
	{
		snake.ChangeDirection(Direction_Up);
	}

	else if (m1::KeyIsPressed(SDL_SCANCODE_S) == true)
	{
		snake.ChangeDirection(Direction_Down);
	}
	snake.Move();
	food.RGB();
	food.Render();
	snake.Render();

	//snake.ShowTailrectCoordinates();

}