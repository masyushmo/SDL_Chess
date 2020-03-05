#include "sdl.h"

MySDL::MySDL()
{
	init_SDL("SDL CHESS", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1280, 720, false);
}

int MySDL::init_SDL(const char* title, int xpos, int ypos, int width, int height, bool is_full)
{
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
		init_error("SDL could not initialize! SDL_Error: %s\n");
	if (!(win = SDL_CreateWindow(title, xpos, ypos, width, height, SDL_WINDOW_RESIZABLE)))
		init_error("Window could not be created! SDL_Error: %s\n");
	if (!(win_surf = SDL_CreateRGBSurface(0, W_W, W_H, 32, 0, 0, 0, 0)))
		init_error("Window surface could not be created! SDL_Error: %s\n");
	if (!(rend = SDL_CreateRenderer(win, -1, \
		SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC)))
		init_error("Render could not be created! SDL_Error: %s\n");
	SDL_SetRenderDrawColor(rend, 255, 0, 0, 255);
	if (!(win_tex = SDL_CreateTexture(rend, SDL_PIXELFORMAT_ARGB8888, \
		SDL_TEXTUREACCESS_TARGET, width, height)))
		init_error("Window texture could not be created! SDL_Error: %s\n");

	return 0;
}

MySDL::~MySDL()
{
	SDL_DestroyWindow(win);
	SDL_DestroyTexture(win_tex);
	SDL_DestroyRenderer(rend);
	SDL_Quit();
	std::cout << "SDL CLEANED!" << std::endl;
}
