#include "Game.h"

#undef main


int main(int argc, char* argv[])
{
	SDL_Init(SDL_INIT_VIDEO);

	C_Game game;

	bool quit = false;
	SDL_Event ev;

	while (quit == false)
	{
		while (SDL_PollEvent(&ev) != 0)
		{
			if (ev.type == SDL_QUIT)
			{
				quit = true;
			}
		}

		SDL_SetRenderDrawColor(_GetRenderer, 0x00, 0x00, 0x00, 0xFF);
		SDL_RenderClear(_GetRenderer);

		if (game.Game_Play() == 1)
		{
			quit = true;
		}

		SDL_RenderPresent(_GetRenderer);
	}
	
	
	
	SDL_Quit();

	return 0;
}