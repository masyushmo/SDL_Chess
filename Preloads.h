#ifndef PRELOADS_H
# define PRELOADS_H

# include "sdl.h"

class Preloads
{

private:

	Preloads(Preloads const& src) = delete;
	Preloads& operator=(Preloads const& src) = delete;

public:

	Preloads();
	
	static SDL_Texture* load_tex(const std::string spath, SDL_Renderer * ren);
	
	//SDL_Surface** load_group(int w, int h, const char* path);
	//void		resize_surf(int w, int h, SDL_Surface ** surf);
	
	~Preloads();
};

#endif

