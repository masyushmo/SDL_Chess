#ifndef FIGURE_H
#define FIGURE_H

#include "Grid.h"

class Grid;

class Figure
{
	SDL_Renderer* renFig;
	SDL_Texture* Fig_text;

public:

	SDL_Rect distRec;
	bool move;

	Figure() = delete;
	Figure(std::string gettexture, Grid * g, int xpos, int ypos);
	~Figure();
	Figure(Figure const& src);
	Figure& operator=(Figure const& src);

	void Update();
	void Render();
	SDL_Texture* getTexture() const;
};

#endif

