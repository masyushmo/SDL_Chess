#ifndef GRID_H
#define GRID_H

#include "Game.h"
#include <vector>

class Grid
{
	SDL_Renderer* renGrid;
	SDL_Texture* Grid_text;
	std::vector<int> offB;
	
public:

	SDL_Rect gridRec;
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

