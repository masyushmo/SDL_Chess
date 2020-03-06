#ifndef GRID_H
#define GRID_H

#include "Game.h"

class Grid
{
	SDL_Renderer* renGrid;
	SDL_Texture* Grid_text;

public:

	SDL_Rect boardRec;

	Grid() = delete;
	Grid(std::string gettexture, SDL_Renderer* ren);
	~Grid();
	Grid(Grid const& src);
	Grid& operator=(Grid const& src);

	void Update();
	void Render();
	SDL_Renderer* getRend();

};

#endif;

