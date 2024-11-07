#include "Game.h"
#include <iostream>

Game::Game()
    : window(sf::VideoMode(800, 800), "Snake Game", sf::Style::Titlebar | sf::Style::Close),
    gameState(MENU), cellSizeX(window.getSize().x / 10), cellSizeY(window.getSize().y / 10) {

    window.setFramerateLimit(60);

    // Load font, background, and music
    if (!extra.loadFont(font)) {
        std::cerr << "Failed to load font!" << std::endl;
    }
    extra.loadBackground(backgroundTexture, background, window);
    extra.playBackgroundMusic(buffer, sound);

    // Initialize text elements
    extra.setupText(startText, font, "Press Enter to Start", window.getSize().x / 2.0f, window.getSize().y / 2.0f - 30);
    extra.setupText(exitText, font, "Press Escape to Exit", window.getSize().x / 2.0f, window.getSize().y / 2.0f + 30);
    extra.setupText(gameOverText, font, "Game Over! Press Enter to Restart", window.getSize().x / 2.0f, window.getSize().y / 2.0f);

    // Initialize the grid and empty positions for placing objects
    grid.getGrid("C:/Users/omart/OneDrive/Documents/GitHub/OOP---DataStructure/SnakeGameProject/SfmlTests/gridfile.txt", gridArray, emptyPositions);

    collectible.generateCollectible(window, emptyPositions);
    collectible.generateDownsizeCollectible(emptyPositions,cellSizeX,cellSizeY,false);
    collectible.generateInvincibilityCollectible(emptyPositions, cellSizeX, cellSizeY, false);

    // Set obstacle sizes and colors
    mainObstacle.setSize(sf::Vector2f(cellSizeX / 1.5, cellSizeY / 1.5));
    mainObstacle.setFillColor(sf::Color::Yellow);

    obstacleY.setSize(sf::Vector2f(cellSizeX / 1.5, cellSizeY / 1.5));
    obstacleY.setFillColor(sf::Color::White);

    obstacleX.setSize(sf::Vector2f(cellSizeX/ 1.5, cellSizeY/ 1.5));
    obstacleX.setFillColor(sf::Color::Black);

    // Spawn each obstacle at a valid position
    obstacle.spawnObstacle(mainObstacle, emptyPositions, cellSizeX, mainObstacleDirection);
    obstacle.spawnObstacle(obstacleY, emptyPositions, cellSizeX, mainObstacleDirection);
    obstacle.spawnObstacle(obstacleX, emptyPositions, cellSizeX, mainObstacleDirection);
}

void Game::run() {
    while (window.isOpen()) {
        processEvents();

        if (gameState == GAME) {
            update();
        }

        render();
    }
}

void Game::processEvents() {
    sf::Event event;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            window.close();
        }

        if (event.type == sf::Event::KeyPressed) {
            handleKeyPress(event.key.code);
        }
    }
}

void Game::handleKeyPress(sf::Keyboard::Key key) {
    switch (gameState) {
    case MENU:
        if (key == sf::Keyboard::Enter) {
            gameState = GAME;
        }
        else if (key == sf::Keyboard::Escape) {
            window.close();
        }
        break;

    case GAME:
        if (!snake.getStopSnake()) {
            if (key == sf::Keyboard::W && snake.getDirection() != DOWN) {
                snake.setDirection(UP);
            }
            else if (key == sf::Keyboard::A && snake.getDirection() != RIGHT) {
                snake.setDirection(LEFT);
            }
            else if (key == sf::Keyboard::S && snake.getDirection() != UP) {
                snake.setDirection(DOWN);
            }
            else if (key == sf::Keyboard::D && snake.getDirection() != LEFT) {
                snake.setDirection(RIGHT);
            }
        }
        if (key == sf::Keyboard::Escape) {
            gameState = MENU;
        }
        break;

    case GAME_OVER:
        if (key == sf::Keyboard::Enter) {
            restartGame();
        }
        break;
    }
}

void Game::update() {
    timeSinceLastMove += clock.restart();
    if (timeSinceLastMove.asMilliseconds() > 100) {
        handleCollectibles();
        snake.moveSnake(snake.getBody(), snake.getDirection(), snake.getSpeed());

        if (checkCollisions()) {
            gameState = GAME_OVER;
        }

        timeSinceLastMove = sf::Time::Zero;
    }

    // Update obstacles
    obstacle.moveMainObstacle(mainObstacle, mainObstacleDirection, mainObstacleSpeed, cellSizeX, cellSizeY, window, gridArray);
    obstacle.moveYAxisObstacle(obstacleY, yObstacleSpeed, cellSizeY, window, gridArray);
    obstacle.moveXAxisObstacle(obstacleX, xObstacleSpeed, cellSizeX, window, gridArray);
}

void Game::handleCollectibles() {
    // Normal collectible: Increases score by 100 and extends the snake's body
    if (snake.getBody().front().getGlobalBounds().intersects(collectible.getCollectibleShape().getGlobalBounds())) {
        snake.extendSnake(snake.getBody(), snake.getDirection());
        collectible.generateCollectible(window, emptyPositions);  // Respawn collectible
        snake.increaseScore(100);
        snake.increaseSpeed(); // Optional: Increase speed slightly with each collectible
    }

    // Shrink collectible: Shrinks snake and adds 1000 points to score
    if (snake.getBody().front().getGlobalBounds().intersects(collectible.getShrinkCollectibleShape().getGlobalBounds())) {
        if (snake.getBody().size() > 1) {
            snake.shrinkSnake();
        }
        collectible.generateDownsizeCollectible(emptyPositions, cellSizeX, cellSizeY, true);  // Respawn shrink collectible
        snake.increaseScore(1000);
    }

    // Invincibility collectible: Grants temporary invincibility and adds 10 points
    if (snake.getBody().front().getGlobalBounds().intersects(collectible.getInvincibilityCollectibleShape().getGlobalBounds())) {
        snake.setInvincible(true);
        tempInvincibilityClock.restart();  // Start the invincibility timer
        collectible.generateInvincibilityCollectible(emptyPositions, cellSizeX, cellSizeY, true);  // Respawn invincibility collectible
        snake.increaseScore(10);
    }

    // Manage invincibility duration
    if (snake.isInvincible() && tempInvincibilityClock.getElapsedTime().asSeconds() > invincibilityDuration) {
        snake.setInvincible(false);  // Disable invincibility after the duration ends
    }
}

bool Game::checkCollisions() {
    // Local variables to store mutable values for passing by reference
    bool stopSnake = snake.getStopSnake();
    int score = snake.getScore();

    // Call checkSnakeCollision with non-const reference arguments
    if (snake.checkSnakeCollision(snake.getBody(), mainObstacle, obstacleX, obstacleY, gridArray, cellSizeX, cellSizeY,
        health, snake.isInvincible(), stopSnake, score, gameState,
        tempInvincible, tempInvincibilityClock)) {
        // Update the snake's properties if they were modified in the function
        snake.setStopSnake(stopSnake);
        snake.setScore(score);

        return health <= 0;
    }
    return false;
}


void Game::restartGame() {
    gameState = GAME;
    health = 3;
    snake.resetSnake();
    snake.setSpeed(20.0f);
    snake.setScore(0);
    snake.setInvincible(false);
    snake.setStopSnake(false);
    collectible.generateCollectible(window, emptyPositions);
    collectible.generateDownsizeCollectible(emptyPositions, cellSizeX, cellSizeY, true);
    collectible.generateInvincibilityCollectible(emptyPositions, cellSizeX, cellSizeY, true);
    obstacle.spawnObstacle(mainObstacle, emptyPositions, cellSizeX, mainObstacleDirection);
}

void Game::render() {
    window.clear();

    if (gameState == MENU) {
        window.draw(background);
        window.draw(startText);
        window.draw(exitText);
    }
    else if (gameState == GAME) {
        grid.drawWalls(window, gridArray, cellSizeX, cellSizeY);
        snake.drawSnake(window, snake.getBody());
        window.draw(collectible.getCollectibleShape());
        window.draw(collectible.getShrinkCollectibleShape());
        window.draw(collectible.getInvincibilityCollectibleShape());
        window.draw(mainObstacle);
        window.draw(obstacleY);
        window.draw(obstacleX);

        // Draw HUD elements
        updateHUD();
        window.draw(healthText);
        window.draw(speedText);
        window.draw(scoreText);
    }
    else if (gameState == GAME_OVER) {
        window.draw(gameOverText);
    }

    window.display();
}

void Game::updateHUD() {
    healthText.setString("Health: " + std::to_string(health));
    healthText.setPosition(10, 10);
    healthText.setFont(font);
    healthText.setCharacterSize(24);
    healthText.setFillColor(sf::Color::White);

    speedText.setString("Speed: " + std::to_string(snake.getSpeed()));
    speedText.setPosition(10, 40);
    speedText.setFont(font);
    speedText.setCharacterSize(24);
    speedText.setFillColor(sf::Color::White);

    scoreText.setString("Score: " + std::to_string(snake.getScore()));
    scoreText.setPosition(10, 70);
    scoreText.setFont(font);
    scoreText.setCharacterSize(24);
    scoreText.setFillColor(sf::Color::White);
}