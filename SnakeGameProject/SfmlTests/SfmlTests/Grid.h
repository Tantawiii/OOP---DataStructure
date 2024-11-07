#pragma once
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <string>
#include <algorithm>
#include <random>
#include "Position.h"
#include "GameState.h"
using namespace std;
using namespace sf;

class Grid
{

public:
	void getGrid(const string& path, char grid[10][10], vector<Position>& emptyPositions);
	void drawWalls(RenderWindow& window, char grid[10][10], int cellSizeX, int cellSizeY);
};

