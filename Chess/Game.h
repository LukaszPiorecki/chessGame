#pragma once
#include <vector>
#include "Pawn.h"

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
	
	/*short arrangement[8][8] = {
		{ 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 },
		{ 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 },
		{ 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 },
		{ 0 , 0 , 0 , 0 , 0 , 0 , 1 , 0 },
		{ 0 , 0 , 0 , 0 , 0 , 0 , 1 , 0 },
		{ 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 },
		{ 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 },
		{ 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 },
	};*/

public:
	short arrangement[8][8] = {
		{ 0 , 1 , 0 , 0 , 0 , 0 , 1 , 0 },
		{ 0 , 1 , 0 , 0 , 0 , 0 , 1 , 0 },
		{ 0 , 1 , 0 , 0 , 0 , 0 , 1 , 0 },
		{ 0 , 1 , 0 , 0 , 0 , 0 , 1 , 0 },
		{ 0 , 1 , 0 , 0 , 0 , 0 , 1 , 0 },
		{ 0 , 1 , 0 , 0 , 0 , 0 , 1 , 0 },
		{ 0 , 1 , 0 , 0 , 0 , 0 , 1 , 0 },
		{ 0 , 1 , 0 , 0 , 0 , 0 , 1 , 0 },
	};

	std::vector<Piece*> pieces;
	//std::vector<Tower> towers;

	void arrangeFigures(Board& t_board, bool t_switchColor = 0);
};
