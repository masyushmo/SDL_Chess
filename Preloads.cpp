#include "Preloads.h"

Preloads::Preloads() { }

Preloads::~Preloads()
{
	std::cout << "Prefs CLEANED!" << std::endl;
}

SDL_Texture* Preloads::load_tex(const char* path, SDL_Renderer * ren)
{
	SDL_Surface * temp = IMG_Load(path);
	if (temp == NULL)
	{
		SDL_FreeSurface(temp);
		std::cout << "Texture load error" << SDL_GetError() << std::endl;
	}
	SDL_Texture* texture = SDL_CreateTextureFromSurface(ren, temp);
	SDL_FreeSurface(temp);
	return (texture);
}

//sdl_surface** preloads::load_group(int w, int h,  const char* path)
//{
//	sdl_rect	rect;
//	sdl_surface** splited;
//	sdl_surface* sheet;
//
//	int count = 0;
//	sheet = load_tex(path);
//	sdl_setcolorkey(sheet, sdl_false, sdl_maprgb(sheet->format, 0, 0, 0));
//	splited = new sdl_surface*[12];
//	rect = { 0, 0, sheet->w / w - 1, sheet->h / h - 1 };
//	for (int i = 0; i < h; i++)
//	{
//		for (int j = 0; j < w; j++)
//		{
//			rect.x = sheet->w / w * j;
//			rect.y = sheet->h / h * i;
//			dsplited[count] = sdl_creatergbsurfacewithformat(0, rect.w, rect.h, 32, format);
//			sdl_blitsurface(sheet, &rect, splited[count], null);
//			count++;
//		}
//	}
//	sdl_freesurface(sheet);
//	return (splited);
//}

//void	Preloads::resize_surf(int w, int h, SDL_Surface ** surf)
//{
//	SDL_Surface* temp;
//	temp = *surf;
//	*surf = SDL_CreateRGBSurfaceWithFormat(0, w, h, 32, format);
//	SDL_BlitScaled(temp, 0, *surf, 0);
//	SDL_FreeSurface(temp);
//}