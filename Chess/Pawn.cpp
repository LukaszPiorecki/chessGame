#include "Pawn.h"
void Pawn::move(Board& t_board, std::unique_ptr<Piece>** t_arrangement)
{
	int possibleVertical=1;
	int possibleAttack;
	if ((color == Color::Black) && (getY() == 1)) possibleVertical = 2;
	if ((color == Color::White) && (getY() == 6)) possibleVertical = 2;

	//std::cout << "ok " <<possibleVertical<< "\n";

	/*for (int y = 0; y < 8; y++)
	{
		for (int x = 0; x < 8; x++)
		{
			std::cout << t_arrangement[x][y] << " ";
		}
		std::cout << "\n";
	}*/

	for(int i =1; i<=possibleVertical; i++)
	{
		//std::cout << possibleVertical << '\n';
		if ((t_arrangement[getX()][getY() + (i * moveDirection)])==nullptr)
		{
			//std::cout << x << " " << y << "\n";
			possibleMoves.push_back(new PossibleMove(t_board, getX(), getY() + (i * moveDirection)));
		}
		else break;
	}
	if (getX() - 1 >= 0)
		if ((t_arrangement[getX() - 1][getY() + (1 * moveDirection)] != nullptr) && (t_arrangement[getX() - 1][getY() + (1 * moveDirection)]->getColor() != color)) { possibleMoves.push_back(new PossibleMove(t_board, getX() - 1, getY() + (1 * moveDirection))); }

	if(getX()+1<8)
		if ((t_arrangement[getX() + 1][getY() + (1 * moveDirection)] != nullptr) && (t_arrangement[getX() + 1][getY() + (1 * moveDirection)]->getColor() != color)) { possibleMoves.push_back(new PossibleMove(t_board, getX() + 1, getY() + (1 * moveDirection))); }
}

Pawn::Pawn(int t_x, int t_y, bool t_color, Board& t_board)
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
		if (!(texture.loadFromFile(WHITE_PAWN_IMAGE_PATH)))
		std::cout << "[WARNING]: Image not found: " << WHITE_PAWN_IMAGE_PATH<< '\n';
	}
	else
	{
		if (!(texture.loadFromFile(BLACK_PAWN_IMAGE_PATH)))
			std::cout << "[WARNING]: Image not found: " << BLACK_PAWN_IMAGE_PATH << '\n';
	}
	setTexture(texture);

	setOriginCentered();

	sprite.setPosition(t_board.position[getX()][getY()].pos);
	positionOnBoard = t_board.position[getX()][getY()].pos;
}