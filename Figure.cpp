#include "Figure.h"

Figure::Figure(const char* gettexture, Grid * g)
{
	renFig = g->getRend();
	Fig_text = Preloads::load_tex(gettexture, renFig);

	srcRec.x = 20;
	srcRec.y = 40;
	srcRec.w = 20;
	srcRec.h = 40;

	distRec.x = g->boardRec.x + 10;
	distRec.y = g->boardRec.y + 10;
	distRec.w = g->boardRec.w / 10;
	distRec.h = g->boardRec.h / 8;

	move = false;
}

Figure::~Figure()
{
	SDL_DestroyTexture(Fig_text);
}

Figure::Figure(Figure const& src)
{
	renFig = src.renFig;
	srcRec = src.srcRec;
	distRec = src.distRec;
	Fig_text = src.Fig_text;
	move = false;
}

Figure& Figure::operator=(Figure const& src)
{
	if (this != &src)
	{
		renFig = src.renFig;
		srcRec = src.srcRec;
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
	SDL_RenderCopy(renFig, Fig_text, &srcRec, &distRec);
}