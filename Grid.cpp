#include "Grid.h"

Grid::Grid(std::string gettexture, SDL_Renderer* ren)
{
	renGrid = ren;
	Grid_text = Preloads::load_tex(gettexture, renGrid);

	boardRec.w = W_W / 2;
	boardRec.h = boardRec.w;
	boardRec.x = (W_W - boardRec.w) / 2;
	boardRec.y = (W_H - boardRec.h) / 2;
	offB = { 15, 5, 4};

	gridRec.x = boardRec.x + offB[0];
	gridRec.y = boardRec.y + offB[1];
	gridRec.w = boardRec.w / 8 - offB[2];
	gridRec.h = gridRec.w;
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