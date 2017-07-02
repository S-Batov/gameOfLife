#include "Cell.h"
#include "Game.h"

void Cell::show(int x, int y, Graphics& gfx)
{
	if (Game::cells[y][x].populated) {
		for (int i = 0; i < Cell::height; i++) {
			for (int j = 0; j < Cell::width; j++) {
				gfx.PutPixel(x * Cell::width + j, y * Cell::height + i, 0, 0, 200);
			}
		}
	}

}

void Cell::populate(MainWindow& wnd)
{
	if (wnd.mouse.LeftIsPressed()) {
		int x = wnd.mouse.GetPosX() / Game::colNum;
		int y = wnd.mouse.GetPosY() / Game::rowNum;

		if (!Game::cells[y][x].populated) {
			Game::cells[y][x].populated = true;
		}
	}
}

void Cell::checkNeighbours(int x, int y)
{
	int curX = x - 1;
	int curY = y - 1;

	for (int i = 0; i < 9; i++) {
		if (curX >= 0 && curX < Game::colNum &&
			curY >= 0 && curY < Game::rowNum &&
			Game::cells[curY][curX].populated &&
			(curX != x || curY != y) ) {
			Game::cellNeighbourCount[y][x]++;

		}
		curX++;
		if (curX > x + 1) {
			curX = x - 1;
			curY++;
		}
	}
}
