#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include "Position.h"
#include <iostream>

class Obstacle {
public:
    void spawnObstacle(sf::RectangleShape& obstacle, const std::vector<Position>& emptyPositions, int cellSizeX, int& obstacleDirection);
    void moveMainObstacle(sf::RectangleShape& obstacle, int& obstacleDirection, float& obstacleSpeed, int cellSizeX, int cellSizeY, const sf::RenderWindow& window, char grid[10][10]);
    void moveYAxisObstacle(sf::RectangleShape& obstacleY, float& obstacleSpeed, int cellSizeY, const sf::RenderWindow& window, char grid[10][10]);
    void moveXAxisObstacle(sf::RectangleShape& obstacleX, float& obstacleSpeed, int cellSizeX, const sf::RenderWindow& window, char grid[10][10]);
};
