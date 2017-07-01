#pragma once

#include "Keyboard.h"
#include "Mouse.h"
#include "Graphics.h"
#include "Cell.h"

class Game
{
public:
	Game( class MainWindow& wnd );
	Game( const Game& ) = delete;
	Game& operator=( const Game& ) = delete;
	void Go();
private:
	void ComposeFrame();
	void UpdateModel();
	/********************************/
	/*  User Functions              */
	/********************************/

	void intialiseCells(int x, int y);
	void init();
	void drawGrid();
	void showcells();
	void populate();

private:
	MainWindow& wnd;
	Graphics gfx;
	/********************************/
	/*  User Variables              */
	/********************************/

	bool populationDone = false;

public:
	static constexpr int rowNum = int(Graphics::ScreenHeight / Cell::height);
	static constexpr int colNum = int(Graphics::ScreenWidth / Cell::width);
	static Cell cells[rowNum][colNum];
};