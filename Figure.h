#ifndef FIGURE_H
#define FIGURE_H

#include "Game.h"
#include "Grid.h"

class Grid;

class Figure
{
	SDL_Renderer* renFig;
	SDL_Texture* Fig_text;
	SDL_Rect srcRec;

public:

	SDL_Rect distRec;
	bool move;

	Figure() = delete;
	Figure(const char* gettexture, Grid * g);
	~Figure();
	Figure(Figure const& src);
	Figure& operator=(Figure const& src);

	void Update();
	void Render();
};

#endif

