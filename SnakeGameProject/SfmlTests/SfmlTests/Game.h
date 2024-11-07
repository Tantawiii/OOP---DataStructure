#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <vector>
#include "Extras.h"
#include "Grid.h"
#include "Snake.h"
#include "Collectible.h"
#include "Obstacle.h"
#include "GameState.h"
#include "Position.h"

class Game {
public:
    Game();                // Constructor to initialize all components
    void run();            // Method to start the main game loop

private:
    // SFML window and assets
    sf::RenderWindow window;
    sf::Texture backgroundTexture;
    sf::Sprite background;
    sf::Font font;
    sf::SoundBuffer buffer;
    sf::Sound sound;

    // Game objects and helpers
    Extras extra;
    Grid grid;
    Snake snake;
    Collectible collectible;
    Obstacle obstacle;

    // Game state and properties
    GameState gameState;
    int health = 3;
    float cellSizeX;
    float cellSizeY;
    int score = 0;
    char gridArray[10][10];
    std::vector<Position> emptyPositions;

    // Obstacles and collectibles properties
    sf::RectangleShape mainObstacle;
    int mainObstacleDirection;
    float mainObstacleSpeed = 0.2f;
    sf::RectangleShape obstacleY;
    float yObstacleSpeed = 0.5f;
    sf::RectangleShape obstacleX;
    float xObstacleSpeed = 0.5f;

    // Timing and controls
    sf::Clock clock;
    sf::Time timeSinceLastMove;
    sf::Clock tempInvincibilityClock;
    bool tempInvincible = false;
    const float invincibilityDuration = 5.0f;

    // HUD text elements
    sf::Text startText;
    sf::Text exitText;
    sf::Text gameOverText;
    sf::Text healthText;
    sf::Text speedText;
    sf::Text scoreText;

    // Private methods for game functionality
    void initializeGame();
    void processEvents();
    void handleKeyPress(sf::Keyboard::Key key);
    void update();
    void render();
    void handleCollectibles();
    bool checkCollisions();
    void restartGame();
    void updateHUD();
};
