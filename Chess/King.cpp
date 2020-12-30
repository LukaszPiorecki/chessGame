#include "King.h"
#include "Pawn.h"
void King::move(Board& t_board, std::unique_ptr<Piece>** t_arrangement)
{
	if (getY() + 1 < 8)
	{
		if (t_arrangement[getX()][getY() + 1] != nullptr)
		{
			if (t_arrangement[getX()][getY() + 1]->getColor() != color)
				possibleMoves.push_back(new PossibleMove(t_board, getX(), getY() + 1));
		}
		else possibleMoves.push_back(new PossibleMove(t_board, getX(), getY() + 1));

		if (getX() - 1 >= 0)
		{
			if (t_arrangement[getX() - 1][getY() + 1] != nullptr)
			{
				if (t_arrangement[getX() - 1][getY() + 1]->getColor() != color)
					possibleMoves.push_back(new PossibleMove(t_board, getX() - 1, getY() + 1));
			}
			else possibleMoves.push_back(new PossibleMove(t_board, getX() - 1, getY() + 1));
		}
		if (getX() + 1 < 8)
		{
			if (t_arrangement[getX() + 1][getY() + 1] != nullptr)
			{
				if (t_arrangement[getX() + 1][getY() + 1]->getColor() != color)
					possibleMoves.push_back(new PossibleMove(t_board, getX() + 1, getY() + 1));
			}
			else possibleMoves.push_back(new PossibleMove(t_board, getX() + 1, getY() + 1));
		}
	}
	if (getY() - 1 >= 0)
	{
		if (t_arrangement[getX()][getY() - 1] != nullptr)
		{
			if (t_arrangement[getX()][getY() - 1]->getColor() != color)
				possibleMoves.push_back(new PossibleMove(t_board, getX(), getY() - 1));
		}
		else possibleMoves.push_back(new PossibleMove(t_board, getX(), getY() - 1));

		if (getX() - 1 >= 0)
		{
			if (t_arrangement[getX() - 1][getY() - 1] != nullptr)
			{
				if (t_arrangement[getX() - 1][getY() - 1]->getColor() != color)
					possibleMoves.push_back(new PossibleMove(t_board, getX() - 1, getY() - 1));
			}
			else possibleMoves.push_back(new PossibleMove(t_board, getX() - 1, getY() - 1));
		}
		if (getX() + 1 < 8)
		{
			if (t_arrangement[getX() + 1][getY() - 1] != nullptr)
			{
				if (t_arrangement[getX() + 1][getY() - 1]->getColor() != color)
					possibleMoves.push_back(new PossibleMove(t_board, getX() + 1, getY() - 1));
			}
			else possibleMoves.push_back(new PossibleMove(t_board, getX() + 1, getY() - 1));
		}
	}

	if (getX() - 1 >= 0)
	{
		if (t_arrangement[getX() - 1][getY()] != nullptr)
		{
			if (t_arrangement[getX() - 1][getY()]->getColor() != color)
				possibleMoves.push_back(new PossibleMove(t_board, getX() - 1, getY()));
		}
		else possibleMoves.push_back(new PossibleMove(t_board, getX() - 1, getY()));
	}
	if (getX() + 1 < 8)
	{
		if (t_arrangement[getX() + 1][getY()] != nullptr)
		{
			if (t_arrangement[getX() + 1][getY()]->getColor() != color)
				possibleMoves.push_back(new PossibleMove(t_board, getX() + 1, getY()));
		}
		else possibleMoves.push_back(new PossibleMove(t_board, getX() + 1, getY()));
	}
}

King::King(int t_x, int t_y, bool t_color, Board& t_board)
{
	setX(t_x);
	setY(t_y);


	if (getY() > 4)
	{
		moveDirection = -1;
		setColor(t_color);
	}
	else
	{
		moveDirection = 1;
		setColor(!t_color);
	}



	sf::Texture texture;
	if (color)
	{
		if (!(texture.loadFromFile(WHITE_KING_IMAGE_PATH)))
			std::cout << "[WARNING]: Image not found: " << WHITE_PAWN_IMAGE_PATH << '\n';
	}
	else
	{
		if (!(texture.loadFromFile(BLACK_KING_IMAGE_PATH)))
			std::cout << "[WARNING]: Image not found: " << BLACK_KING_IMAGE_PATH << '\n';
	}
	setTexture(texture);

	setOriginCentered();

	sprite.setPosition(t_board.position[getX()][getY()].pos);
	positionOnBoard = t_board.position[getX()][getY()].pos;
}