#pragma once

#define _VS

#ifdef _VS
#include "SDL.h"
#include "SDL2_gfxPrimitives.h"
#include "SDL_image.h"
#else
#include "usr/include/SDL2/SDL.h"
#include "usr/include/SDL2/SDL2_gfxPrimitives.h"
#include "usr/include/SDL2/SDL_image.h"
#endif

class Walker
{
public:
	Walker(int x, int y);
	void draw(SDL_Renderer* renderer);
	void update();
	//auto make2DArray(int cols, int rows);
	int _x, _y;

	int __x;
	int __y;

	int grid;
	int spacing = 5;
	int cols, rows;
	int color = 0x00000000;

	int _arr[400][600] = { 0, };



};