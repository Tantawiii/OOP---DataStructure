#include "Grid.h"
#include <fstream>
#include <iostream>

void Grid::getGrid(const std::string& path, char grid[10][10], std::vector<Position>& emptyPositions) {
    std::ifstream myfile(path);

    if (!myfile.is_open()) {
        std::cerr << "Error: Could not open grid file." << std::endl;
        return;
    }

    std::string line;
    int row = 0;
    while (getline(myfile, line) && row < 10) {
        for (int col = 0; col < 10; col++) {
            if (line[col] == '0') {
                grid[row][col] = '0';
                emptyPositions.push_back({ row, col });
            }
            else {
                grid[row][col] = 'X';
            }
        }
        row++;
    }
}

void Grid::drawWalls(sf::RenderWindow& window, char grid[10][10], int cellSizeX, int cellSizeY) {
    for (int row = 0; row < 10; row++) {
        for (int col = 0; col < 10; col++) {
            sf::RectangleShape cell(sf::Vector2f(cellSizeX, cellSizeY));
            cell.setPosition(col * cellSizeX, row * cellSizeY);

            cell.setFillColor(sf::Color(50, 50, 50)); // Dark grey for empty cells
            cell.setOutlineColor(sf::Color::Black);
            cell.setOutlineThickness(-1);

            if (grid[row][col] == 'X') {
                cell.setFillColor(sf::Color::Blue); // Walls are blue
            }

            window.draw(cell);
        }
    }
}
