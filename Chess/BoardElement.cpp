#include "BoardElement.h"

PossibleMove::PossibleMove(Board& t_board, short t_x, short t_y)
{
	sf::Texture texture;
	if (texture.loadFromFile(POSSIBLE_MOVE_IMAGE_PATH))
		setTexture(texture);
	else std::cout << "[WARNING]: Image not found: " << POSSIBLE_MOVE_IMAGE_PATH << '\n';
	setOriginCentered();
	setX(t_x);
	setY(t_y);
	sprite.setPosition(t_board.position[getX()][getY()].pos);

	//std::cout << "height: " << sprite.getGlobalBounds().height << "\nwidth: " << sprite.getGlobalBounds().width << "\ntop: " << sprite.getGlobalBounds().top << "\n left: " << sprite.getGlobalBounds().left << '\n';
	hitbox = sprite.getGlobalBounds();
	hitbox.width = texture.getSize().x;
	hitbox.height = texture.getSize().y;
}

void Piece::updatePiece(sf::RenderTarget& target, const sf::RenderStates t_states)
{
	for (int i = 0; i < possibleMoves.size(); i++)
	{
		possibleMoves[i]->draw(target);
	}

	draw(target, t_states);
}

void Piece::setIsBeingMoved(bool t_m)
{
	if (!(t_m)) possibleMoves.clear();
	isBeingMoved = t_m;
}
void Piece::raise(Cursor& t_cursor, short t_arrangement[8][8], Board& t_board)
{
	if ((t_cursor.isAlreadyMoving() == false) && (getIsBeingMoved() == false))
	{
		if (sprite.getGlobalBounds().contains(t_cursor.getPosition()))
		{
			if (t_cursor.isClicked())
			{
				t_cursor.setAlreadyMoving(1);
				setIsBeingMoved(true);
				setZ(2);
				move(t_board,t_arrangement);
			}
		}
	}

	if (getIsBeingMoved())
	{
		sprite.setPosition(t_cursor.getPosition());
		if (!(t_cursor.isClicked()))
		{
			sprite.setPosition(positionOnBoard);
			for (int i = 0; i < possibleMoves.size(); i++)
			{

				if (possibleMoves[i]->hitbox.contains(t_cursor.getPosition()))
				{
					//std::cout << i << '\n';
					sprite.setPosition(possibleMoves[i]->getPos());
					t_arrangement[getX()][getY()] = 0;
					this->setXY(possibleMoves[i]->getX(), possibleMoves[i]->getY());
					positionOnBoard = possibleMoves[i]->getPos();
					t_arrangement[possibleMoves[i]->getX()][possibleMoves[i]->getY()] = 1;
					break;
				}
			}

			t_cursor.setAlreadyMoving(false);
			setIsBeingMoved(false);
			setZ(0);
		}
	}
}
