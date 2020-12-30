#include "Queen.h"

void Queen::move(Board& t_board, std::unique_ptr<Piece>** t_arrangement)
{
	for (int i = 1; ((getX() + i < 8) && (getY() + i < 8)); i++)
	{
		if (t_arrangement[getX() + i][getY() + i] == nullptr)
		{
			possibleMoves.push_back(new PossibleMove(t_board, getX() + i, getY() + i));
		}
		else if (t_arrangement[getX() + i][getY() + i]->getColor() != color)
		{
			possibleMoves.push_back(new PossibleMove(t_board, getX() + i, getY() + i));
			break;
		}
		else break;
	}
	for (int i = -1; (getX() + i >= 0) && (getY() + i >= 0); i--)
	{
		if (t_arrangement[getX() + i][getY() + i] == nullptr)
		{
			possibleMoves.push_back(new PossibleMove(t_board, getX() + i, getY() + i));
		}
		else if (t_arrangement[getX() + i][getY() + i]->getColor() != color)
		{
			possibleMoves.push_back(new PossibleMove(t_board, getX() + i, getY() + i));
			break;
		}
		else break;
	}
	for (int i = 1; ((getX() - i >= 0) && (getY() + i < 8)); i++)
	{
		if (t_arrangement[getX() - i][getY() + i] == nullptr)
		{
			possibleMoves.push_back(new PossibleMove(t_board, getX() - i, getY() + i));
		}
		else if (t_arrangement[getX() - i][getY() + i]->getColor() != color)
		{
			possibleMoves.push_back(new PossibleMove(t_board, getX() - i, getY() + i));
			break;
		}
		else break;
	}
	for (int i = 1; ((getX() + i < 8) && (getY() - i >= 0)); i++)
	{
		if (t_arrangement[getX() + i][getY() - i] == nullptr)
		{
			possibleMoves.push_back(new PossibleMove(t_board, getX() + i, getY() - i));
		}
		else if (t_arrangement[getX() + i][getY() - i]->getColor() != color)
		{
			possibleMoves.push_back(new PossibleMove(t_board, getX() + i, getY() - i));
			break;
		}
		else break;
	}
	for (short x = getX() - 1; x >= 0; x--)
	{
		if (t_arrangement[x][getY()] == nullptr)
		{
			possibleMoves.push_back(new PossibleMove(t_board, x, getY()));
		}
		else if (t_arrangement[x][getY()]->getColor() != color)
		{
			possibleMoves.push_back(new PossibleMove(t_board, x, getY()));
			break;
		}
		else break;
	}

	for (short x = getX() + 1; x < 8; x++)
	{
		if (t_arrangement[x][getY()] == nullptr)
		{
			possibleMoves.push_back(new PossibleMove(t_board, x, getY()));
		}
		else if (t_arrangement[x][getY()]->getColor() != color)
		{
			possibleMoves.push_back(new PossibleMove(t_board, x, getY()));
			break;
		}
		else break;
	}

	for (short y = getY() - 1; y >= 0; y--)
	{
		if (t_arrangement[getX()][y] == nullptr)
		{
			possibleMoves.push_back(new PossibleMove(t_board, getX(), y));
		}
		else if (t_arrangement[getX()][y]->getColor() != color)
		{
			possibleMoves.push_back(new PossibleMove(t_board, getX(), y));
			break;
		}
		else break;
	}

	for (short y = getY() + 1; y < 8; y++)
	{
		if (t_arrangement[getX()][y] == nullptr)
		{
			possibleMoves.push_back(new PossibleMove(t_board, getX(), y));
		}
		else if (t_arrangement[getX()][y]->getColor() != color)
		{
			possibleMoves.push_back(new PossibleMove(t_board, getX(), y));
			break;
		}
		else break;
	}

}

Queen::Queen(int t_x, int t_y, bool t_color, Board& t_board)
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
		if (!(texture.loadFromFile(WHITE_QUEEN_IMAGE_PATH)))
			std::cout << "[WARNING]: Image not found: " << WHITE_QUEEN_IMAGE_PATH << '\n';
	}
	else
	{
		if (!(texture.loadFromFile(BLACK_QUEEN_IMAGE_PATH)))
			std::cout << "[WARNING]: Image not found: " << BLACK_QUEEN_IMAGE_PATH << '\n';
	}
	setTexture(texture);

	setOriginCentered();

	sprite.setPosition(t_board.position[getX()][getY()].pos);
	positionOnBoard = t_board.position[getX()][getY()].pos;
}