#include "Game.h"
void Game::arrangeFigures(Board& t_board, bool t_switchColor)
{
	for (int y = 0; y < 8; y++)
	{
		for (int x = 0; x < 8; x++)
		{
			switch (arrangement[x][y])
			{
				case PAWN:
					pieces.push_back(new Pawn(x,y, !t_switchColor,t_board));
					break;
			}
		}
	}
}