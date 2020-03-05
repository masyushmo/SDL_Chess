#ifndef SDL_H
#define SDL_H

#define SDL_MAIN_HANDLED
#include <SDL.h>
#include <SDL_image.h>
#include <iostream>

constexpr auto W_W = 1280;
constexpr auto W_H = 720;

class MySDL
{

private:

	MySDL(MySDL const& src) = delete;
	MySDL& operator=(MySDL const& src) = delete;
	int init_SDL(const char* title, int xpos, int ypos, int width, int height, bool is_full);
	int	init_error(std::string a) { std::cout << a << std::endl; return 1; }

public:

	SDL_Window* win;
	SDL_Renderer* rend;
	SDL_Texture* win_tex;
	SDL_Surface* win_surf;

	MySDL();
	~MySDL();
};


#endif 

