#pragma once
#include "BoardElement.h"

#include <SFML/Graphics.hpp>



class Pawn : public Piece
{
public:
	Pawn(int t_x, int t_y, bool t_color, Board& t_board);

	void move(Board& t_board, short t_arrangement[8][8]) override;
};

