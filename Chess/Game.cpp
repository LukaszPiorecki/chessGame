#include "Game.h"
void Game::arrangeFigures(Board& t_board, bool t_switchColor)
{
	for (int i = 0; i < 8; i++)
	{
		arrangement[i] = new std::unique_ptr<Piece>[8];
	}
	for (int y = 0; y < 8; y++)
	{
		for (int x = 0; x < 8; x++)
		{
			switch (initialArrangement[x][y])
			{
				case PAWN:
					arrangement[x][y].reset(new Pawn(x, y, !(t_switchColor), t_board));
					break;
				case TOWER:
					arrangement[x][y].reset(new Tower(x, y, !(t_switchColor), t_board));
					break;
				case KNIGHT:
					arrangement[x][y].reset(new Knight(x, y, !(t_switchColor), t_board));
					break;
			}
		}
	}
}