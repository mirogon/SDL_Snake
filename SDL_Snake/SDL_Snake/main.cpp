#include "Game.h"

#ifdef _DEBUG

#undef main

#endif


int main(int argc, char* argv[])
{
	SDL_Init(SDL_INIT_VIDEO);

	C_Game game;
	E_GameState gameState = Game_Play;

	bool quit = false;
	bool keyDown = false;

	SDL_Event ev;

	while (quit == false)
	{

		static int fps = 0;
		static Uint32 lastTime = SDL_GetTicks();

		while (SDL_PollEvent(&ev) != 0)
		{
			if (ev.type == SDL_QUIT)
			{
				quit = true;
			}

			if (ev.type == SDL_KEYDOWN)
			{
				if (ev.key.keysym.sym == SDLK_RETURN)
				{
					keyDown = true;
				}
			}

			else
			{
				keyDown = false;
			}

		}

		SDL_SetRenderDrawColor(_GetRenderer, 0x00, 0x00, 0x00, 0xFF);
		SDL_RenderClear(_GetRenderer);

		if (gameState == Game_Play)
		{
			if (game.Game_Play() == 1)
			{
				gameState = Game_Over;
			}
		}

		else if (gameState == Game_Over)
		{
			game.Game_Over();
			if (keyDown == true)
			{
				game.Game_Reset();
				gameState = Game_Play;
			}
		}
		
		SDL_RenderPresent(_GetRenderer);

		if (SDL_GetTicks() - lastTime >= 1000)
		{
			std::cout << "FPS: " << fps << std::endl;
			fps = 0;
			lastTime = SDL_GetTicks();
		}
		++fps;

	}
	
	
	
	SDL_Quit();

	return 0;
}