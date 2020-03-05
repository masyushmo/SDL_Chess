#include "Grid.h"

Grid::Grid(const char* gettexture, SDL_Renderer* ren)
{
	renGrid = ren;
	Grid_text = Preloads::load_tex(gettexture, renGrid);

	boardRec.x = 50;
	boardRec.y = 100;
	boardRec.w = W_W / 2;
	boardRec.h = W_H / 2;
}

Grid::~Grid()
{
	SDL_DestroyTexture(Grid_text);
}

Grid::Grid(Grid const& src)
{
	renGrid = src.renGrid;
	boardRec = src.boardRec;
	Grid_text = src.Grid_text;
}

Grid& Grid::operator=(Grid const& src)
{
	if (this != &src)
	{
		renGrid = src.renGrid;
		boardRec = src.boardRec;
		Grid_text = src.Grid_text;
	}
	return *this;
}

void Grid::Update()
{

}

void Grid::Render()
{
	SDL_RenderCopy(renGrid, Grid_text, NULL, &boardRec);
}

SDL_Renderer* Grid::getRend() { return renGrid; }