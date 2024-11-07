#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include <string>
#include "Position.h"

class Grid {
public:
    void getGrid(const std::string& path, char grid[10][10], std::vector<Position>& emptyPositions);
    void drawWalls(sf::RenderWindow& window, char grid[10][10], int cellSizeX, int cellSizeY);
    const std::vector<Position>& getEmptyPositions() const { return emptyPositions; }

private:
    std::vector<Position> emptyPositions;
};
