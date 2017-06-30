#pragma once
#include "Graphics.h"

class Cell {
public:
	static constexpr int width = 20;
	static constexpr int height = 20;

	bool populated = false;

	int gridX;
	int gridY;

public:
	void show(int x, int y,	Graphics& gfx);
};