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
class Obstacle
{
public:
	void spawnObstacle(RectangleShape& obstacle, const vector<Position>& emptyPositions, int cellSizeX, int& obstacleDirection);
	void moveMainObstacle(RectangleShape& obstacle, int& obstacleDirection, float& obstacleSpeed, int cellSizeX, int cellSizeY, const RenderWindow& window, char grid[10][10]);
	void moveYAxisObstacle(RectangleShape& obstacleY, float& obstacleSpeed, int cellSizeY, const RenderWindow& window, char grid[10][10]);
	void moveXAxisObstacle(RectangleShape& obstacleX, float& obstacleSpeed, int cellSizeX, const RenderWindow& window, char grid[10][10]);
};

