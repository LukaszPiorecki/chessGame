#pragma once
#include <vector>
#include "Pawn.h"
#include "Tower.h"
#include "Knight.h"

#define PAWN 1
#define TOWER 2
#define KNIGHT 3
#define BISHOP 4
#define QUEEN 5
#define KING 6

class Game
{
private:
	bool turn;
	bool result;
	//bool type;
	
	short initialArrangement[8][8] = {
		{ 2 , 1 , 0 , 0 , 0 , 0 , 1 , 2 },
		{ 3 , 1 , 0 , 0 , 0 , 0 , 1 , 3 },
		{ 0 , 1 , 0 , 0 , 0 , 0 , 1 , 0 },
		{ 0 , 1 , 0 , 0 , 0 , 0 , 1 , 0 },
		{ 0 , 1 , 0 , 0 , 0 , 0 , 1 , 0 },
		{ 0 , 1 , 0 , 0 , 0 , 0 , 1 , 0 },
		{ 3 , 1 , 0 , 0 , 0 , 0 , 1 , 3 },
		{ 2 , 1 , 0 , 0 , 0 , 0 , 1 , 2 },
	};

public:
	std::unique_ptr<Piece>** arrangement = new std::unique_ptr<Piece> * [8];
	

	//std::vector<Piece*> pieces;
	//std::vector<Tower> towers;

	void arrangeFigures(Board& t_board, bool t_switchColor = 0);
};

