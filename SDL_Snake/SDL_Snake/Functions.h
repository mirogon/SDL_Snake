#pragma once
#include "Global.h"

namespace m1
{
	//CHECK IF THE KEY WITH THE SCANCODE scancode IS PRESSED
	bool KeyIsPressed(SDL_Scancode scancode);

	inline bool KeyIsPressed(SDL_Scancode scancode)
	{
		static const Uint8* keyStatus = SDL_GetKeyboardState(NULL);
		keyStatus = SDL_GetKeyboardState(NULL);

		if (keyStatus[scancode] == 1)
		{
			return true;
		}

		else
		{
			return false;
		}

	}
}