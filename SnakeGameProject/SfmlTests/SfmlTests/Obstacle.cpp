#include "Obstacle.h"

// Function to spawn the main obstacle
void Obstacle::spawnObstacle(sf::RectangleShape& obstacle, const std::vector<Position>& emptyPositions, int cellSizeX, int& obstacleDirection) {
    if (emptyPositions.empty()) {
        std::cout << "Error: No empty positions available for obstacle placement." << std::endl;
        return;
    }

    Position pos = emptyPositions[rand() % emptyPositions.size()];
    obstacle.setPosition(pos.col * cellSizeX, pos.row * cellSizeX);
    obstacleDirection = rand() % 2; // Randomly choose initial movement direction (0: vertical, 1: horizontal)
}

// Function to move the main obstacle within the grid, reversing upon hitting a wall
void Obstacle::moveMainObstacle(sf::RectangleShape& obstacle, int& obstacleDirection, float& obstacleSpeed, int cellSizeX, int cellSizeY, const sf::RenderWindow& window, char grid[10][10]) {
    sf::Vector2f position = obstacle.getPosition();
    int col = static_cast<int>(position.x) / cellSizeX;
    int row = static_cast<int>(position.y) / cellSizeY;

    if (obstacleDirection == 0) { // Vertical movement
        int nextRow = (position.y + obstacleSpeed) / cellSizeY;
        if (nextRow < 0 || nextRow >= 10 || grid[nextRow][col] == 'X') {
            obstacleSpeed = -obstacleSpeed; // Reverse direction if hitting wall
        }
        obstacle.move(0, obstacleSpeed);
    }
    else { // Horizontal movement
        int nextCol = (position.x + obstacleSpeed) / cellSizeX;
        if (nextCol < 0 || nextCol >= 10 || grid[row][nextCol] == 'X') {
            obstacleSpeed = -obstacleSpeed; // Reverse direction if hitting wall
        }
        obstacle.move(obstacleSpeed, 0);
    }
}

// Function to move the obstacle on the Y-axis within the grid, reversing direction upon hitting a wall
void Obstacle::moveYAxisObstacle(sf::RectangleShape& obstacleY, float& yObstacleSpeed, int cellSizeY, const sf::RenderWindow& window, char grid[10][10]) {
    sf::Vector2f position = obstacleY.getPosition();
    int col = static_cast<int>(position.x) / cellSizeY;
    int row = static_cast<int>(position.y) / cellSizeY;

    int nextRow = static_cast<int>((position.y + yObstacleSpeed) / cellSizeY);

    if (nextRow < 0 || nextRow >= 10 || grid[nextRow][col] == 'X') {
        yObstacleSpeed = -yObstacleSpeed; // Reverse direction on collision with wall
    }

    obstacleY.move(0, yObstacleSpeed);
}

// Function to move the obstacle on the X-axis within the grid, reversing direction upon hitting a wall
void Obstacle::moveXAxisObstacle(sf::RectangleShape& obstacleX, float& xObstacleSpeed, int cellSizeX, const sf::RenderWindow& window, char grid[10][10]) {
    sf::Vector2f position = obstacleX.getPosition();
    int row = static_cast<int>(position.y) / cellSizeX;
    int col = static_cast<int>(position.x) / cellSizeX;

    int nextCol = static_cast<int>((position.x + xObstacleSpeed) / cellSizeX);

    if (nextCol < 0 || nextCol >= 10 || grid[row][nextCol] == 'X') {
        xObstacleSpeed = -xObstacleSpeed; // Reverse direction on collision with wall
    }

    obstacleX.move(xObstacleSpeed, 0);
}
