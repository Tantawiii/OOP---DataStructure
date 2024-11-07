#include "Obstacle.h"
// Function to spawn the main obstacle
void Obstacle::spawnObstacle(RectangleShape& obstacle, const vector<Position>& emptyPositions, int cellSizeX, int& obstacleDirection) {
    if (emptyPositions.empty()) {
        cerr << "Error: No empty positions available for obstacle placement." << endl;
        return;
    }

    Position pos = emptyPositions[rand() % emptyPositions.size()];
    obstacle.setPosition(pos.col * cellSizeX, pos.row * cellSizeX);
    obstacleDirection = rand() % 2;
}

// Function to move the main obstacle within the grid, reversing upon hitting a wall
void Obstacle::moveMainObstacle(RectangleShape& obstacle, int& obstacleDirection, float& mainObstacleSpeed, int cellSizeX, int cellSizeY, const RenderWindow& window, char grid[10][10]) {
    Vector2f position = obstacle.getPosition();
    int col = static_cast<int>(position.x) / cellSizeX;
    int row = static_cast<int>(position.y) / cellSizeY;

    if (obstacleDirection == 0) { // Vertical movement
        int nextRow = (position.y + mainObstacleSpeed) / cellSizeY;
        if (nextRow < 0 || nextRow >= 10 || grid[nextRow][col] == 'X') {
            mainObstacleSpeed = -mainObstacleSpeed; // Reverse direction for main obstacle only
        }
        obstacle.move(0, mainObstacleSpeed);
    }
    else { // Horizontal movement
        int nextCol = (position.x + mainObstacleSpeed) / cellSizeX;
        if (nextCol < 0 || nextCol >= 10 || grid[row][nextCol] == 'X') {
            mainObstacleSpeed = -mainObstacleSpeed; // Reverse direction for main obstacle only
        }
        obstacle.move(mainObstacleSpeed, 0);
    }
}

// Function to move the obstacle on Y-axis within the grid, reversing direction upon hitting a wall
void Obstacle::moveYAxisObstacle(RectangleShape& obstacleY, float& yObstacleSpeed, int cellSizeY, const RenderWindow& window, char grid[10][10]) {
    Vector2f position = obstacleY.getPosition();
    int col = static_cast<int>(position.x) / cellSizeY;
    int row = static_cast<int>(position.y) / cellSizeY;

    int nextRow = static_cast<int>((position.y + yObstacleSpeed) / cellSizeY);

    if (nextRow < 0 || nextRow >= 10 || grid[nextRow][col] == 'X') {
        yObstacleSpeed = -yObstacleSpeed; // Reverse direction for Y-axis obstacle only
    }

    obstacleY.move(0, yObstacleSpeed);
}

// Function to move the obstacle on X-axis within the grid, reversing direction upon hitting a wall
void Obstacle::moveXAxisObstacle(RectangleShape& obstacleX, float& xObstacleSpeed, int cellSizeX, const RenderWindow& window, char grid[10][10]) {
    Vector2f position = obstacleX.getPosition();
    int row = static_cast<int>(position.y) / cellSizeX;
    int col = static_cast<int>(position.x) / cellSizeX;

    int nextCol = static_cast<int>((position.x + xObstacleSpeed) / cellSizeX);

    if (nextCol < 0 || nextCol >= 10 || grid[row][nextCol] == 'X') {
        xObstacleSpeed = -xObstacleSpeed; // Reverse direction for X-axis obstacle only
    }

    obstacleX.move(xObstacleSpeed, 0);
}