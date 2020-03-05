#include "Game.h"

int main()
{
	Game& game = Game::createGame();

	while (game.is_running())
	{
		game.events();
		game.update();
		game.render();
	}

	return 0;
}
