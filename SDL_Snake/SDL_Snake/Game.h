#pragma once
#include "Snake.h"

class C_Game
{

public:

	C_Game();
	~C_Game() = default;

	bool Game_Play();
	void Game_Over();
	void Game_Reset();

private:

	void GenerateFood();
	void CheckFood();
	bool CheckSnakeDead();

	C_Snake snake;
	C_Food food;
};

inline bool C_Game::Game_Play()
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
	if (CheckSnakeDead() == 1)
	{
		return 1;
	}
	food.RGB();
	CheckFood();
	food.Render();
	snake.Render();

	return 0;
	//snake.ShowTailrectCoordinates();

}

inline void C_Game::Game_Over()
{	
	SDL_SetRenderDrawColor(_GetRenderer, 0x80, 0x00, 0x00, 0xFF);
	SDL_RenderClear(_GetRenderer);
	food.Render();
	snake.Render();
}

inline void C_Game::CheckFood()
{
	if (snake.GetRect().x == food.GetRect().x && snake.GetRect().y == food.GetRect().y)
	{
		snake.Eat();
		food.Despawn();
		GenerateFood();
	}
}

inline bool C_Game::CheckSnakeDead()
{
	static std::vector<SDL_Rect> tR = snake.GetSnaketailRect();
	tR = snake.GetSnaketailRect();

	for (auto i = tR.begin() + 1; i != tR.end(); ++i)
	{
		if (snake.GetRect().x == i->x && snake.GetRect().y == i->y)
		{
			return 1;
		}
	}

	return 0;

}