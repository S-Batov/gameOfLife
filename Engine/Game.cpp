/****************************************************************************************** 
 *	Chili DirectX Framework Version 16.07.20											  *	
 *	Game.cpp																			  *
 *	Copyright 2016 PlanetChili.net <http://www.planetchili.net>							  *
 *																						  *
 *	This file is part of The Chili DirectX Framework.									  *
 *																						  *
 *	The Chili DirectX Framework is free software: you can redistribute it and/or modify	  *
 *	it under the terms of the GNU General Public License as published by				  *
 *	the Free Software Foundation, either version 3 of the License, or					  *
 *	(at your option) any later version.													  *
 *																						  *
 *	The Chili DirectX Framework is distributed in the hope that it will be useful,		  *
 *	but WITHOUT ANY WARRANTY; without even the implied warranty of						  *
 *	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the						  *
 *	GNU General Public License for more details.										  *
 *																						  *
 *	You should have received a copy of the GNU General Public License					  *
 *	along with The Chili DirectX Framework.  If not, see <http://www.gnu.org/licenses/>.  *
 ******************************************************************************************/
#include "MainWindow.h"
#include "Game.h"
#include "Cell.h"


Cell Game::cells[rowNum][colNum];

Game::Game( MainWindow& wnd )
	:
	wnd( wnd ),
	gfx( wnd )
{
	init();
}

void Game::Go()
{
	gfx.BeginFrame();	
	UpdateModel();
	ComposeFrame();
	gfx.EndFrame();
}

void Game::UpdateModel()
{
	for (int i = 0; i < rowNum; i++) {
		for (int j = 0; j < colNum; j++) {
			cells[j][i].show(j, i, gfx);
		}
	}
}


void Game::ComposeFrame()
{
	drawGrid();
}

void Game::intialiseCells(int x, int y)
{
	cells[y][x].gridX = x;
	cells[y][x].gridY = y;
}

void Game::init()
{
	for (int i = 0; i < rowNum; i++) {
		for (int j = 0; j < colNum; j++) {
			intialiseCells(j, i);
		}
	}
}

void Game::drawGrid()
{
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
