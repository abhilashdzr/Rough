#include "Piece.h"
#include "Window.h"

SDL_Texture* Piece::wk, Piece::wq, Piece::wr, Piece::wb, Piece::wn, Piece::wp;
SDL_Texture* Piece::bk, Piece::bq, Piece::br, Piece::bb, Piece::bn, Piece::bp;

uint8_t Piece::king, Piece::queen, Piece::rook, Piece::bishop, Piece::knight, Piece::pawn;
uint8_t Piece::white, Piece::black;

void Piece::init()
{
	loadPieces();
	enumTypes();
}

void Piece::enumTypes()
{	
	//first 6 bits for type
	king = (1 << 0);
	queen = (1 << 1);
	rook = (1 << 2);
	bishop = (1 << 3);
	knight = (1 << 4);	
	pawn = (1 << 5);
	//last 2 bits for color (both zero means empty)
	white = (1 << 6);
	black = (1 << 7);
}

void Piece::loadPieces()
{
	// load the image into memory using SDL_image library function
    SDL_Surface* wk_img = IMG_Load("resources/wk.png");
    SDL_Surface* wq_img = IMG_Load("resources/wq.png");
    SDL_Surface* wr_img = IMG_Load("resources/wr.png");
    SDL_Surface* wb_img = IMG_Load("resources/wb.png");
    SDL_Surface* wn_img = IMG_Load("resources/wn.png");
    SDL_Surface* wp_img = IMG_Load("resources/wp.png");
    SDL_Surface* bk_img = IMG_Load("resources/bk.png");
    SDL_Surface* bq_img = IMG_Load("resources/bq.png");
    SDL_Surface* br_img = IMG_Load("resources/br.png");
    SDL_Surface* bb_img = IMG_Load("resources/bb.png");
    SDL_Surface* bn_img = IMG_Load("resources/bn.png");
    SDL_Surface* bp_img = IMG_Load("resources/bp.png");

    // load the image data into the graphics hardware's memory
    wk = SDL_CreateTextureFromSurface(Window::rend, wk_img);
    SDL_FreeSurface(wk_img);
    wq = SDL_CreateTextureFromSurface(Window::rend, wq_img);
    SDL_FreeSurface(wq_img);
    wr = SDL_CreateTextureFromSurface(Window::rend, wr_img);
    SDL_FreeSurface(wr_img);
    wb = SDL_CreateTextureFromSurface(Window::rend, wb_img);
    SDL_FreeSurface(wb_img);
    wn = SDL_CreateTextureFromSurface(Window::rend, wn_img);
    SDL_FreeSurface(wn_img);
    wp = SDL_CreateTextureFromSurface(Window::rend, wp_img);
    SDL_FreeSurface(wp_img);
    bk = SDL_CreateTextureFromSurface(Window::rend, bk_img);
    SDL_FreeSurface(bk_img);
    bq = SDL_CreateTextureFromSurface(Window::rend, bq_img);
    SDL_FreeSurface(bq_img);
    br = SDL_CreateTextureFromSurface(Window::rend, br_img);
    SDL_FreeSurface(br_img);
    bb = SDL_CreateTextureFromSurface(Window::rend, bb_img);
    SDL_FreeSurface(bb_img);
    bn = SDL_CreateTextureFromSurface(Window::rend, bn_img);
    SDL_FreeSurface(bn_img);
    bp = SDL_CreateTextureFromSurface(Window::rend, bp_img);
    SDL_FreeSurface(bp_img);
}

void Piece::destroyPieces()
{
	SDL_DestroyTexture(wk);
	SDL_DestroyTexture(wq);
	SDL_DestroyTexture(wr);
	SDL_DestroyTexture(wb);
	SDL_DestroyTexture(wn);
	SDL_DestroyTexture(wp);
	SDL_DestroyTexture(bk);
	SDL_DestroyTexture(bq);
	SDL_DestroyTexture(br);
	SDL_DestroyTexture(bb);
	SDL_DestroyTexture(bn);
	SDL_DestroyTexture(bp);
}
