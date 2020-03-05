#ifndef GRID_H
#define GRID_H

#include "Game.h"

enum { L = 1, D = -1 }; //  L(white) = 1, D(black) = -1
enum { Dead = 0, P, N, B, R, Q, K }; //  (P)awn, (N*K)night, (B)ishop, (R)ook, (Q)ueen, (K)ing

class Grid
{

	SDL_Renderer* renGrid;
	SDL_Texture* Grid_text;

public:

	SDL_Rect boardRec;

	Grid() = delete;
	Grid(const char* gettexture, SDL_Renderer* ren);
	~Grid();
	Grid(Grid const& src);
	Grid& operator=(Grid const& src);

	void Update();
	void Render();
	SDL_Renderer* getRend();

};

#endif;

