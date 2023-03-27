#include "Bishop.h"
void Bishop::move(Board& t_board, std::unique_ptr<Piece>** t_arrangement)
{
	for (int i = 1; ((getX() + i < 8) && (getY() + i < 8)); i++)
	{
		if (t_arrangement[getX()+i][getY()+i] == nullptr)
		{
			possibleMoves.push_back(PossibleMove(t_board, getX()+i, getY()+i));
		}
		else if (t_arrangement[getX()+i][getY()+i]->getColor() != color)
		{
			possibleMoves.push_back(PossibleMove(t_board, getX()+i, getY()+i));
			break;
		}
		else break;
	}
	for (int i = -1; (getX() + i >= 0) && (getY() + i >= 0); i--)
	{
		if (t_arrangement[getX() + i][getY() + i] == nullptr)
		{
			possibleMoves.push_back(PossibleMove(t_board, getX() + i, getY() + i));
		}
		else if (t_arrangement[getX() + i][getY() + i]->getColor() != color)
		{
			possibleMoves.push_back(PossibleMove(t_board, getX() + i, getY() + i));
			break;
		}
		else break;
	}
	for (int i = 1; ((getX() - i >= 0) && (getY() + i < 8)); i++)
	{
		if (t_arrangement[getX() - i][getY() + i] == nullptr)
		{
			possibleMoves.push_back(PossibleMove(t_board, getX() - i, getY() + i));
		}
		else if (t_arrangement[getX() - i][getY() + i]->getColor() != color)
		{
			possibleMoves.push_back(PossibleMove(t_board, getX() - i, getY() + i));
			break;
		}
		else break;
	}
	for (int i = 1; ((getX() + i < 8) && (getY() - i >= 0)); i++)
	{
		if (t_arrangement[getX() + i][getY() - i] == nullptr)
		{
			possibleMoves.push_back(PossibleMove(t_board, getX() + i, getY() - i));
		}
		else if (t_arrangement[getX() + i][getY() - i]->getColor() != color)
		{
			possibleMoves.push_back(PossibleMove(t_board, getX() + i, getY() - i));
			break;
		}
		else break;
	}
}

Bishop::Bishop(int t_x, int t_y, bool t_color, Board& t_board)
{
	setType(4);

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
		if (!(texture.loadFromFile(WHITE_BISHOP_IMAGE_PATH)))
			std::cout << "[WARNING]: Image not found: " << WHITE_BISHOP_IMAGE_PATH << '\n';
	}
	else
	{
		if (!(texture.loadFromFile(BLACK_BISHOP_IMAGE_PATH)))
			std::cout << "[WARNING]: Image not found: " << BLACK_BISHOP_IMAGE_PATH << '\n';
	}
	setTexture(texture);

	setOriginCentered();

	sprite.setPosition(t_board.position[getX()][getY()].pos);
	positionOnBoard = t_board.position[getX()][getY()].pos;
}