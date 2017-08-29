#pragma once
#include "Base.h"

class C_Food
{
public:

	C_Food() = delete;
	C_Food(int x = 0, int y = 0);
	~C_Food() = default;

	void RGB();
	void Spawn(int x, int y);
	void Despawn();
	void Render();

	const SDL_Rect& GetRect()
	{
		return foodRect;
	}

	bool IsEaten()
	{
		return eaten;
	}


private:

	bool eaten;

	SDL_Rect foodRect;
	SDL_Color currentColor;

};

inline void C_Food::RGB()
{
	static Uint32 lastTime = SDL_GetTicks();

	if (SDL_GetTicks() - lastTime >= RGBTicks)
	{

		if (currentColor.r == 0xFF)
		{
			currentColor.r = 0x00;
			currentColor.g = 0xFF;
		}

		else if (currentColor.g == 0xFF)
		{
			currentColor.g = 0x00;
			currentColor.b = 0xFF;
		}

		else if (currentColor.b == 0xFF)
		{
			currentColor.b = 0x00;
			currentColor.r = 0xFF;
		}

		lastTime = SDL_GetTicks();
	}

	SDL_SetRenderDrawColor(_GetRenderer, currentColor.r, currentColor.g, currentColor.b, currentColor.a);
}

inline void C_Food::Render()
{
	if (eaten == false)
	{
		SDL_RenderFillRect(_GetRenderer, &foodRect);
	}
	
}