#include "Food.h"

C_Food::C_Food(int x, int y)
{
	eaten = false;

	foodRect.x = x;
	foodRect.y = y;
	foodRect.w = FOOD_SIZE;
	foodRect.h = FOOD_SIZE;

	currentColor.r = 0xFF;
	currentColor.g = 0x00;
	currentColor.b = 0x00;
	currentColor.a = 0xFF;
}

void C_Food::Spawn(int x, int y)
{
	foodRect.x = x;
	foodRect.y = y;
	eaten = false;
}

void C_Food::Despawn()
{
	eaten = true;
}