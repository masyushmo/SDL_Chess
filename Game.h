#ifndef GAME_H
#define GAME_H

#include "Preloads.h"
#include "Grid.h"
#include "Figure.h"

class Grid;
class Figure;

class Game
{

private:

	MySDL	ms;
	Grid * g;
	Figure* f;
	bool is_run;
	int	xpos;
	int ypos;

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
};


#endif 
