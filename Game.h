#ifndef GAME_H
#define GAME_H

#include "Preloads.h"
#include "Grid.h"
#include "Figure.h"

#include <map>
#include <string>

enum FigCode { BK = -6, BQ, BR, BB, BN, BP, Dead, WP, WN, WB, WR, WQ, WK }; //  (P)awn, (N*K)night, (B)ishop, (R)ook, (Q)ueen, (K)ing

class Grid;
class Figure;

class Game
{

private:

	MySDL	ms;
	Grid * g;
	Figure* f[32];
	bool is_run;
	int	currX;
	int currY;

	Game();
	Game(Game const& src) = delete;
	Game& operator=(Game const& src) = delete;

public:

	static Game& createGame() { static Game g; return g; }
	~Game();

	void events();
	void update();
	void render();
	void clean();

	bool is_running() { return is_run; }

	void Init_figures(Grid * g);
};


#endif 
