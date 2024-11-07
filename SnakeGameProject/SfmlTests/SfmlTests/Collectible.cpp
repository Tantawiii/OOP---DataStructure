#include "Collectible.h"
// Function to generate downsize collectible with a delay, and option for immediate respawn
void Collectible::generateDownsizeCollectible(RectangleShape& downsizeCollectible, const vector<Position>& emptyPositions, int cellSizeX, int cellSizeY, Clock& downsizeTimer, bool immediateRespawn = false) {
    float downsizeDelay = 20.0f; // 20 seconds delay

    // Check if immediate respawn is requested
    if (!immediateRespawn && downsizeTimer.getElapsedTime().asSeconds() < downsizeDelay) {
        return; // Delay not met, do not spawn
    }

    // Select a random valid position for the collectible
    Position pos = emptyPositions[rand() % emptyPositions.size()];
    downsizeCollectible.setPosition(pos.col * cellSizeX, pos.row * cellSizeY);

    // Restart the timer after spawning the collectible
    downsizeTimer.restart();
}

// Function to generate invincibility collectible with a delay, and option for immediate respawn
void Collectible::generateInvincibilityCollectible(RectangleShape& invincibilityCollectible, const vector<Position>& emptyPositions, int cellSizeX, int cellSizeY, Clock& invincibilityTimer, bool immediateRespawn = false) {
    float invincibilityDelay = 50.0f; // 50 seconds delay

    // Check if immediate respawn is requested
    if (!immediateRespawn && invincibilityTimer.getElapsedTime().asSeconds() <= invincibilityDelay) {
        return; // Delay not met, do not spawn
    }

    // Select a random valid position for the collectible
    Position pos = emptyPositions[rand() % emptyPositions.size()];
    invincibilityCollectible.setPosition(pos.col * cellSizeX, pos.row * cellSizeY);

    // Restart the timer after spawning the collectible
    invincibilityTimer.restart();
}

// Function to check collision between the snake's head and a collectible
bool Collectible::checkCollision(const RectangleShape& snakeHead, const RectangleShape& collectible) {
    return snakeHead.getGlobalBounds().intersects(collectible.getGlobalBounds());
}

// Function to generate a collectible at a random empty position within the grid
void Collectible::generateCollectible(RectangleShape& collectible, const RenderWindow& window, const vector<Position>& emptyPositions, Clock& collectibleTimer, char grid[10][10]) {
    if (emptyPositions.empty()) {
        cerr << "Error: No empty positions available for collectible placement." << endl;
        return;
    }

    int cellSizeX = window.getSize().x / 10;
    int cellSizeY = window.getSize().y / 10;

    // Select a random valid position directly from emptyPositions without additional filtering
    Position pos = emptyPositions[rand() % emptyPositions.size()];

    // Set collectible position based on the selected grid cell
    collectible.setPosition(pos.col * cellSizeX, pos.row * cellSizeY);

    // Restart the timer after spawning the collectible
    collectibleTimer.restart();
}