#include "Game.h"

int board[8][8] = { BR, BN, BB, BQ, BK, BB, BN, BR,
				    BP, BP, BP, BP, BP, BP, BP, BP,
					0,	0,	0,  0,	0,  0,  0,  0,
					0,	0,  0,  0,	0,  0,  0,  0,
					0,	0,  0,  0,	0,  0,  0,  0,
					0,	0,  0,  0,	0,  0,  0,  0,
				    WP, WP, WP, WP, WP, WP, WP, WP,
				    WR, WN, WB, WQ, WK, WB, WN, WR, };

int offBX = 100;
int offBY = 30;

Game::Game() : ms(), is_run(true)
{
	g = new Grid("./Assets/Board1.png", ms.rend);
	Init_figures(g);
	currX = 0;
	currY = 0;
}

Game::~Game()
{
	std::cout << "GAME CLEANED!" << std::endl;
}

void Game::clean() {}

void Game::Init_figures(Grid * g)
{
	int count = 0;

	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (board[i][j] == 0)
				continue;
			int x = abs(board[i][j]) - 1;
			int y = board[i][j] > 0 ? 1 : 0;
			std::string sfig = "";
			#define PROCESS_VAL(p) case(p): sfig = #p; break;
			switch (board[i][j]) {
				PROCESS_VAL(BK);
				PROCESS_VAL(BQ);
				PROCESS_VAL(BR);
				PROCESS_VAL(BB);
				PROCESS_VAL(BN);
				PROCESS_VAL(BP);
				PROCESS_VAL(WP);
				PROCESS_VAL(WN);
				PROCESS_VAL(WB);
				PROCESS_VAL(WR);
				PROCESS_VAL(WQ);
				PROCESS_VAL(WK);
			}
			#undef PROCESS_VAL

			f[count] = new Figure("./Assets/" + sfig + ".png",
				g, g->boardRec.x * i, g->boardRec.y * j);
			count++;
		}
		
	}

	//Figure * BB = new Figure("./Assets/BB.png", g, 10, 10);
}


void Game::events()
{
	SDL_GetMouseState(&currX, &currY);

	SDL_Event event;
	SDL_PollEvent(&event);
	if (event.type == SDL_QUIT)
		is_run = false;
	else if (event.type == SDL_MOUSEBUTTONDOWN)
	{
		if (event.button.button == SDL_BUTTON_LEFT)
		{
			if (currX > f[0]->distRec.x&& currX < f[0]->distRec.x + f[0]->distRec.w &&
				currY > f[0]->distRec.y&& currY < f[0]->distRec.y + f[0]->distRec.h)
				f[0]->move = (!f[0]->move) ? true : false;
		}
	}
	else if (event.type == SDL_MOUSEMOTION)
	{
		if (f[0]->move == true)
		{
			f[0]->distRec.x += event.motion.xrel;
			f[0]->distRec.y += event.motion.yrel;
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
	for (int i = 0; i < 32; i++)
		f[i]->Render();
}

void Game::render()
{
	SDL_RenderClear(ms.rend);
	g->Render();
	for (int i = 0; i < 32; i++)
		f[i]->Render();
	//SDL_DestroyTexture(ms.win_tex);
	//SDL_RenderCopy(ms.rend, text, NULL, NULL);
	SDL_RenderPresent(ms.rend);
}