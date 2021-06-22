#pragma once

#include "SDL.h"
#include "SDL_image.h"

class Piece
{
public:
	static void init();
	static void enumTypes();
	static void loadPieces();
	static void destroyPieces();
	
	SDL_Texture* Piece::wk, Piece::wq, Piece::wr, Piece::wb, Piece::wn, Piece::wp;
	SDL_Texture* Piece::bk, Piece::bq, Piece::br, Piece::bb, Piece::bn, Piece::bp;

	uint8_t Piece::king, Piece::queen, Piece::rook, Piece::bishop, Piece::knight, Piece::pawn;
	uint8_t Piece::white, Piece::black;
};
