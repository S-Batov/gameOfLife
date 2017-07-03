#pragma once

#include "Keyboard.h"
#include "Mouse.h"
#include "Graphics.h"
#include "Cell.h"
#include "FrameTimer.h"

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

	FrameTimer ft;
	float time = 0;

	bool populationDone = false;

public:
	static constexpr int rowNum = Graphics::ScreenHeight / Cell::height;
	static constexpr int colNum = Graphics::ScreenWidth / Cell::width;
	static Cell cells[rowNum][colNum];
	static int cellNeighbourCount[rowNum][colNum];
};