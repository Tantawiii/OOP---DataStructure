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
class Collectible
{
public:
	bool checkCollision(const RectangleShape& snakeHead, const RectangleShape& collectible);
	void generateCollectible(RectangleShape& collectible, const RenderWindow& window, const vector<Position>& emptyPositions, Clock& collectibleTimer, char grid[10][10]);
	void generateDownsizeCollectible(RectangleShape& downsizeCollectible, const vector<Position>& emptyPositions, int cellSizeX, int cellSizeY, Clock& downsizeTimer, bool immediateRespawn);
	void generateInvincibilityCollectible(RectangleShape& invincibilityCollectible, const vector<Position>& emptyPositions, int cellSizeX, int cellSizeY, Clock& invincibilityTimer, bool immediateRespawn);
};

