#include "MainWindow.h" 
#include "Game.h" 
#include "Cell.h" 



Cell Game::cells[rowNum][colNum];

Game::Game(MainWindow& wnd)
	:
	wnd(wnd),
	gfx(wnd) {
	init();
}
void Game::Go() {
	gfx.BeginFrame();
	UpdateModel();
	ComposeFrame();
	gfx.EndFrame();
}

void Game::UpdateModel() {
	populate();
}

void Game::ComposeFrame() {
	showcells();
	drawGrid();
}

void Game::init() {
	for (int i = 0; i < rowNum; i++) {
		for (int j = 0; j < colNum; j++) {
			intialiseCells(j, i);
		}
	}
}

void Game::intialiseCells(int x, int y) {
	cells[y][x].gridX = x;
	cells[y][x].gridY = y;
}

void Game::drawGrid() {
	for (int i = 0; i < rowNum; i++) {
		for (int j = 0; j < Graphics::ScreenWidth; j++) {
			gfx.PutPixel(j, i * Cell::height, 255, 255, 255);
		}
	}
	for (int i = 0; i < Graphics::ScreenHeight; i++) {
		for (int j = 0; j < rowNum; j++) {
			gfx.PutPixel(j * Cell::width, i, 255, 255, 255);
		}
	}
}

void Game::showcells() {
	for (int i = 0; i < rowNum; i++) {
		for (int j = 0; j < colNum; j++) {
			cells[j][i].show(j, i, gfx);
		}
	}
}

void Game::populate()
{
	if (!populationDone) {
		for (int i = 0; i < rowNum; i++) {
			for (int j = 0; j < colNum; j++) {
				cells[j][i].populate(wnd);
			}
		}
	}
	if ( wnd.mouse.RightIsPressed() ){
		populationDone = true;
	}
}
