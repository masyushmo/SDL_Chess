#include "Figure.h"

Figure::Figure(std::string gettexture, Grid* g, int xpos, int ypos)
{
	renFig = g->getRend();
	Fig_text = Preloads::load_tex(gettexture, renFig);

	distRec.x = xpos;
	distRec.y = ypos;
	distRec.w = g->gridRec.w;
	distRec.h = g->gridRec.h;

	move = false;
}

Figure::~Figure()
{
	SDL_DestroyTexture(Fig_text);
}

Figure::Figure(Figure const& src)
{
	renFig = src.renFig;
	distRec = src.distRec;
	Fig_text = src.Fig_text;
	move = false;
}

Figure& Figure::operator=(Figure const& src)
{
	if (this != &src)
	{
		renFig = src.renFig;
		distRec = src.distRec;
		Fig_text = src.Fig_text;
		move = false;
	}
	return *this;
}

void Figure::Update()
{

}

void Figure::Render()
{
	SDL_RenderCopy(renFig, Fig_text, NULL, &distRec);
}

SDL_Texture* Figure::getTexture() const { return Fig_text; }
