#pragma once

#include "Graphics.h"
#include "MainWindow.h"

class Cell {
public:
	static constexpr int width = 20;
	static constexpr int height = 20;

	bool populated = false;

	int gridX;
	int gridY;

public:
	void show(int x, int y,	Graphics& gfx);
	void populate(MainWindow& wnd);
	void checkNeighbours(int x, int y);
	void evolve(int x, int y);
};