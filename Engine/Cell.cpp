#include "Cell.h"
#include "Game.h"

void Cell::show(int x, int y, Graphics& gfx)
{
	for (int i = 0; i < Game::rowNum; i++) {
		for (int j = 0; j < Game::colNum; j++) {
			if (Game::cells[i][j].populated);
		}
	}
}
