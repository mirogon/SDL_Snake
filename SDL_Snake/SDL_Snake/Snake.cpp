#include "Snake.h"

C_Snake::C_Snake(int x, int y)
{
	tailrects.push_back(SDL_Rect());
	_SNAKEHEAD.x = x;
	_SNAKEHEAD.y = y;
	_SNAKEHEAD.w = TAILRECT_SIZE;
	_SNAKEHEAD.h = TAILRECT_SIZE;

	currentDirection = E_Direction::Direction_Right;
}

void C_Snake::AddTailrect()
{
	static std::vector<SDL_Rect>::iterator iT = tailrects.end() - 1;

	tailrects.push_back(SDL_Rect());

	iT = tailrects.end() - 1;

	iT->w = TAILRECT_SIZE;
	iT->h = TAILRECT_SIZE;

	switch (currentDirection)
	{
		case Direction_Left: iT->x = (iT - 1)->x + TAILRECT_SIZE; iT->y = (iT - 1)->y; break;
		case Direction_Right: iT->x = (iT - 1)->x - TAILRECT_SIZE; iT->y = (iT - 1)->y; break;
		case Direction_Up: iT->y = (iT - 1)->y + TAILRECT_SIZE; iT->x = (iT - 1)->x; break;
		case Direction_Down: iT->y = (iT - 1)->y - TAILRECT_SIZE; iT->x = (iT - 1)->x; break;
	}

}

void C_Snake::ChangeDirection(E_Direction newDirection)
{
	currentDirection = newDirection;
}

void C_Snake::Move()
{
	static Uint32 lastTimeMoved = SDL_GetTicks();


	if (SDL_GetTicks() - lastTimeMoved >= snakeMoveTicks)
	{
		if (currentDirection == Direction_Left)
		{
			
			for (auto i = tailrects.end() -1; i != tailrects.begin(); --i)
			{
				i->x = (i - 1)->x;
				i->y = (i - 1)->y;
			}

			_SNAKEHEAD.x -= TAILRECT_SIZE;
		}

		else if (currentDirection == Direction_Right)
		{

			for (auto i = tailrects.end() -1; i != tailrects.begin(); --i)
			{
				i->x = (i - 1)->x;
				i->y = (i - 1)->y;
			}

			_SNAKEHEAD.x += TAILRECT_SIZE;
		}

		else if (currentDirection == Direction_Up)
		{

			for (auto i = tailrects.end() -1; i != tailrects.begin(); --i)
			{
				i->x = (i - 1)->x;
				i->y = (i - 1)->y;
			}

			_SNAKEHEAD.y -= TAILRECT_SIZE;
		}

		else if (currentDirection == Direction_Down)
		{

			for (auto i = tailrects.end() -1; i != tailrects.begin(); --i)
			{
				i->x = (i - 1)->x;
				i->y = (i - 1)->y;
			}

			_SNAKEHEAD.y += TAILRECT_SIZE;
		}

		lastTimeMoved = SDL_GetTicks();

	}

}

void C_Snake::Eat()
{
	AddTailrect();
}