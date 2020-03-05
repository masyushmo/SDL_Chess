#include "Game.h"

Game::Game() : ms(), is_run(true)
{
	g = new Grid("./Assets/Board.png", ms.rend);
	f = new Figure("./Assets/Figures.png", g);
}

Game::~Game()
{
	std::cout << "GAME CLEANED!" << std::endl;
}

void Game::clean() {}

void Game::events()
{
	int x = 0;
	int y = 0;

	SDL_GetMouseState(&xpos, &ypos);

	SDL_Event event;
	SDL_PollEvent(&event);
	if (event.type == SDL_QUIT)
		is_run = false;
	else if (event.type == SDL_MOUSEBUTTONDOWN)
	{
		if (xpos > f->distRec.x&& xpos < f->distRec.x + f->distRec.w &&
			ypos > f->distRec.y&& ypos < f->distRec.y + f->distRec.h)
			f->move = true;
		else
			f->move = false;
	}
	else if (event.type == SDL_MOUSEBUTTONUP)
	{
		f->move = false;
	}
	else if (event.type == SDL_MOUSEMOTION)
	{
		if (f->move == true)
		{
			f->distRec.x += event.motion.xrel;
			f->distRec.y += event.motion.yrel;
		}
	}

//	// This should loop over all the sprites available for grabbing
//	for (int i = 0; i < numSprites; i++)
//	{
//		if (isInBoundingRegion(event.button.x, event.button.y,
//			mySprites[i]))
//			dragSprite = mySprites[i];
//		else
//			dragSprite = NULL;
//	}
//}
//else if (event.type == SDL_MOUSE_BUTTON_UP)
//{
//dragSprite = NULL;
//}
//else if (event.type == SDL_MOUSE_MOTION)
//{
//if (dragSprite != NULL)
//{
//	dragSprite->x += event.motion.xrel;
//	dragSprite->y += event.motion.yrel;
//}
//}
//}
}

void Game::update()
{
	g->Update();
	f->Update();
}

void Game::render()
{
	SDL_RenderClear(ms.rend);
	g->Render();
	f->Render();
	//SDL_DestroyTexture(ms.win_tex);
	//SDL_RenderCopy(ms.rend, text, NULL, NULL);
	SDL_RenderPresent(ms.rend);
}