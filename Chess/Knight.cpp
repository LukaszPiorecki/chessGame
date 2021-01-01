#include "Knight.h"

void Knight::move(Board& t_board, std::unique_ptr<Piece>** t_arrangement)
{

	/*if ((getX() - 2) >= 0)
	{
		if ((getY() + 1) < 8)
		{
			if (t_arrangement[getX() - 2][getY() + 1] != nullptr)
			{
				if (t_arrangement[getX() - 2][getY() + 1]->getColor() != color)
					possibleMoves.push_back(new PossibleMove(t_board, getX() - 2, getY() + 1));
			}
			else
			possibleMoves.push_back(new PossibleMove(t_board, getX() - 2, getY() + 1));
		}
		if ((getY() - 1) >= 0)
		{
			if (t_arrangement[getX() - 2][getY() - 1] != nullptr)
			{
				if (t_arrangement[getX() - 2][getY() - 1]->getColor() != color)
					possibleMoves.push_back(new PossibleMove(t_board, getX() - 2, getY() - 1));
			}
			else
				possibleMoves.push_back(new PossibleMove(t_board, getX() - 2, getY() - 1));
		}
	}*/

	for (int i = 0; i < 8; i++)
	{
		if ((getX() + knightMovement[i][0] >= 0) && (getX() + knightMovement[i][0] < 8))
		{
			if ((getY() + knightMovement[i][1] >= 0) && (getY() + knightMovement[i][1] < 8))
			{
				if (t_arrangement[getX() + knightMovement[i][0]][getY() + knightMovement[i][1]] != nullptr)
				{
					if (t_arrangement[getX() + knightMovement[i][0]][getY() + knightMovement[i][1]]->getColor() != color)
						possibleMoves.push_back(new PossibleMove(t_board, getX() + knightMovement[i][0], getY() + knightMovement[i][1]));
				}
				else
					possibleMoves.push_back(new PossibleMove(t_board, getX() + knightMovement[i][0], getY() + knightMovement[i][1]));
			}
		}
	}
}

Knight::Knight(int t_x, int t_y, bool t_color, Board& t_board)
{
	setType(3);

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
		if (!(texture.loadFromFile(WHITE_KNIGHT_IMAGE_PATH)))
			std::cout << "[WARNING]: Image not found: " << WHITE_KNIGHT_IMAGE_PATH << '\n';
	}
	else
	{
		if (!(texture.loadFromFile(BLACK_KNIGHT_IMAGE_PATH)))
			std::cout << "[WARNING]: Image not found: " << BLACK_KNIGHT_IMAGE_PATH << '\n';
	}
	setTexture(texture);

	setOriginCentered();

	sprite.setPosition(t_board.position[getX()][getY()].pos);
	positionOnBoard = t_board.position[getX()][getY()].pos;
}