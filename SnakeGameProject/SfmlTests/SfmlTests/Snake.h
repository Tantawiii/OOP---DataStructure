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

// Enum for snake movement direction
enum Direction { NONE, UP, DOWN, LEFT, RIGHT };

class Snake
{
private:
    Direction currentDirection = NONE;
    int health = 3;
    float speed = 20.0f;
    int score = 0;
    bool invincible = false;
    bool stopSnake = false;
    vector<RectangleShape> snakeBody;
    RectangleShape head;

public:
    // Constructor
    Snake() : head(sf::Vector2f(20, 20)) {
        head.setFillColor(Color::Green);
        head.setPosition(400, 300);
        snakeBody.push_back(head);
    }
    // Setters
    void setDirection(Direction direction) {
        currentDirection = direction;
    }

    void setHealth(int h) {
        health = h;
    }

    void setSpeed(float s) {
        speed = s;
    }

    void setScore(int sc) {
        score = sc;
    }

    void setInvincible(bool inv) {
        invincible = inv;
    }

    void setStopSnake(bool stop) {
        stopSnake = stop;
    }

    // Getters
    Direction getDirection() const {
        return currentDirection;
    }

    int getHealth() const {
        return health;
    }

    float getSpeed() const {
        return speed;
    }

    int getScore() const {
        return score;
    }

    bool isInvincible() const {
        return invincible;
    }

    bool isStopSnake() const {
        return stopSnake;
    }
	void drawSnake(RenderWindow& window, vector<RectangleShape>& snakeBody);
	void placeSnakeHead(RectangleShape& head, vector<Position> emptyPositions, const RectangleShape& obstacle, const RectangleShape& collectible, int cellSizeX, int cellSizeY);
	void moveSnake(vector<RectangleShape>& snakeBody, Direction currentDirection, float speed);
    bool checkSnakeCollision(
        const vector<RectangleShape>& snakeBody,
        const RectangleShape& mainObstacle,
        const RectangleShape& obstacleX,
        const RectangleShape& obstacleY,
        char grid[10][10],
        int cellSizeX,
        int cellSizeY,
        int& health,
        bool invincible,
        bool& stopSnake,
        int& score,
        GameState& currentState,
        bool& tempInvincible,            // Add tempInvincible parameter
        Clock& tempInvincibilityClock    // Add tempInvincibilityClock parameter
    );
    void extendSnake(vector<RectangleShape>& snakeBody, Direction currentDirection);

};

