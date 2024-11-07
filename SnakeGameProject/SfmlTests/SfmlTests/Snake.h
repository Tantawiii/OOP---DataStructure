#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include "Position.h"
#include "GameState.h"

// Enum for snake movement direction
enum Direction { NONE, UP, DOWN, LEFT, RIGHT };

class Snake {
public:
    // Constructor
    Snake();

    // Drawing and movement
    void drawSnake(sf::RenderWindow& window, std::vector<sf::RectangleShape>& snakeBody);
    void moveSnake(std::vector<sf::RectangleShape>& snakeBody, Direction currentDirection, float speed);

    // Growth and shrinking
    void extendSnake(std::vector<sf::RectangleShape>& snakeBody, Direction currentDirection);
    void shrinkSnake();

    // Collision checking
    bool checkSnakeCollision(const std::vector<sf::RectangleShape>& snakeBody, const sf::RectangleShape& mainObstacle,
        const sf::RectangleShape& obstacleX, const sf::RectangleShape& obstacleY,
        char grid[10][10], int cellSizeX, int cellSizeY, int& health,
        bool invincible, bool& stopSnake, int& score, GameState& currentState,
        bool& tempInvincible, sf::Clock& tempInvincibilityClock);

    // Getters and setters for direction, speed, score, invincibility, etc.
    void setDirection(Direction direction);
    Direction getDirection() const;

    float getSpeed() const;
    void setSpeed(float newSpeed);
    void increaseSpeed();

    int getScore() const;
    void setScore(int newScore);
    void increaseScore(int amount);

    bool isInvincible() const;
    void setInvincible(bool inv);

    bool getStopSnake() const;
    void setStopSnake(bool stop);

    // Resetting and retrieving snake body
    void resetSnake();
    std::vector<sf::RectangleShape>& getBody();

private:
    // Snake properties
    Direction currentDirection;        // Current movement direction
    int health;                        // Health of the snake
    float speed;                       // Movement speed of the snake
    int score;                         // Current score
    bool invincible;                   // Invincibility state
    bool stopSnake;                    // Flag to stop snake's movement

    // Snake body
    std::vector<sf::RectangleShape> snakeBody;  // Vector of rectangles representing snake segments
    sf::RectangleShape head;                    // Head of the snake
};

