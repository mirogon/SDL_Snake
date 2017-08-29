#pragma once
#include "Food.h"

class C_Snake
{

public:

	C_Snake() = delete;
	C_Snake(int x = 0, int y = 0);
	~C_Snake() = default;

	void AddTailrect();
	void ChangeDirection(E_Direction newDirection);
	void Eat();
	void Move();
	void Render();
	const SDL_Rect& GetRect()
	{
		return _SNAKEHEAD;
	}

	const std::vector<SDL_Rect>& GetSnaketailRect()
	{
		return tailrects;
	}
	//Debug Functions

	void ShowTailrectCoordinates()
	{
		static Uint32 lastTime = SDL_GetTicks();

		if (SDL_GetTicks() - lastTime >= 1000)
		{
			static int n = 0;

			for (auto i = tailrects.begin(); i != tailrects.end(); ++i)
			{
				std::cout << "Tailrect " << n << " X: " << i->x << " Y: " << i->y << std::endl;

				++n;
			}

			n = 0;
			lastTime = SDL_GetTicks();
		}
	}
	
private:

	std::vector<SDL_Rect> tailrects;
	E_Direction currentDirection;

};

inline void C_Snake::Render()
{
	SDL_SetRenderDrawColor(_GetRenderer, tailrectColor.r, tailrectColor.g, tailrectColor.b, tailrectColor.a);

	for (auto i = tailrects.begin(); i != tailrects.end(); ++i)
	{
		SDL_RenderFillRect(_GetRenderer, &(*i));
	}
}