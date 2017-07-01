#include "Cell.h"
#include "Game.h"

void Cell::show(int x, int y, Graphics& gfx)
{
	if (Game::cells[x][y].populated) {
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

		if (!Game::cells[x][y].populated) {
			Game::cells[x][y].populated = true;
		}
	}
}
