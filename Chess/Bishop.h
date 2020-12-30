#pragma once
#include "BoardElement.h"
class Bishop : public Piece
{
public:
	Bishop(int t_x, int t_y, bool t_color, Board& t_board);

	void move(Board& t_board, std::unique_ptr<Piece>** t_arrangement) override;
};

