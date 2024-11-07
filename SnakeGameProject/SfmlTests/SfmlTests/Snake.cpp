#include "Snake.h"
#include <cmath>
#include <SFML/Graphics.hpp>

Snake::Snake() : currentDirection(NONE), health(3), speed(20.0f), score(0), invincible(false), stopSnake(false) {
    head = sf::RectangleShape(sf::Vector2f(20, 20));
    head.setFillColor(sf::Color::Green);
    head.setPosition(400, 300);
    snakeBody.push_back(head);
}

void Snake::drawSnake(sf::RenderWindow& window, std::vector<sf::RectangleShape>& snakeBody) {
    for (auto& segment : snakeBody) {
        window.draw(segment);
    }
}

void Snake::moveSnake(std::vector<sf::RectangleShape>& snakeBody, Direction currentDirection, float speed) {
    for (int i = snakeBody.size() - 1; i > 0; --i) {
        snakeBody[i].setPosition(snakeBody[i - 1].getPosition());
    }

    switch (currentDirection) {
    case UP:
        snakeBody[0].move(0, -speed);
        break;
    case DOWN:
        snakeBody[0].move(0, speed);
        break;
    case LEFT:
        snakeBody[0].move(-speed, 0);
        break;
    case RIGHT:
        snakeBody[0].move(speed, 0);
        break;
    default:
        break;
    }
}

void Snake::extendSnake(std::vector<sf::RectangleShape>& snakeBody, Direction currentDirection) {
    sf::RectangleShape newSegment(sf::Vector2f(20, 20));
    newSegment.setFillColor(sf::Color::Green);
    sf::Vector2f tailPosition = snakeBody.back().getPosition();

    switch (currentDirection) {
    case UP:
        newSegment.setPosition(tailPosition.x, tailPosition.y + 20);
        break;
    case DOWN:
        newSegment.setPosition(tailPosition.x, tailPosition.y - 20);
        break;
    case LEFT:
        newSegment.setPosition(tailPosition.x + 20, tailPosition.y);
        break;
    case RIGHT:
        newSegment.setPosition(tailPosition.x - 20, tailPosition.y);
        break;
    default:
        break;
    }

    snakeBody.push_back(newSegment);
}

void Snake::shrinkSnake() {
    if (snakeBody.size() > 1) {
        snakeBody.resize(std::ceil(snakeBody.size() / 2));
    }
}

bool Snake::checkSnakeCollision(const std::vector<sf::RectangleShape>& snakeBody, const sf::RectangleShape& mainObstacle,
    const sf::RectangleShape& obstacleX, const sf::RectangleShape& obstacleY,
    char grid[10][10], int cellSizeX, int cellSizeY, int& health,
    bool invincible, bool& stopSnake, int& score, GameState& currentState,
    bool& tempInvincible, sf::Clock& tempInvincibilityClock) {
    const sf::RectangleShape& head = snakeBody[0];

    // Check collision with main obstacle
    if (head.getGlobalBounds().intersects(mainObstacle.getGlobalBounds()) ||
        head.getGlobalBounds().intersects(obstacleX.getGlobalBounds()) ||
        head.getGlobalBounds().intersects(obstacleY.getGlobalBounds())) {
        if (invincible) {
            score += 10;
            return false;
        }
        else {
            health--;
            return true;
        }
    }

    // Check for self-collision
    for (size_t i = 1; i < snakeBody.size(); i++) {
        if (head.getGlobalBounds().intersects(snakeBody[i].getGlobalBounds())) {
            if (!invincible) {
                health--;
            }
            return true;
        }
    }

    // Check for wall collision
    int headCol = static_cast<int>(head.getPosition().x) / cellSizeX;
    int headRow = static_cast<int>(head.getPosition().y) / cellSizeY;
    if (grid[headRow][headCol] == 'X') {
        if (invincible) {
            stopSnake = true;
            return false;
        }
        else {
            health--;
        }
        return true;
    }

    // Check for collision with obstacle X
    if (head.getGlobalBounds().intersects(obstacleX.getGlobalBounds()) && !tempInvincible) {
        if (score >= 200) {
            score -= 200;
        }
        else {
            currentState = GAME_OVER;
        }
        tempInvincible = true;
        tempInvincibilityClock.restart();
        return true;
    }

    // Check for collision with obstacle Y
    if (head.getGlobalBounds().intersects(obstacleY.getGlobalBounds()) && !tempInvincible) {
        if (score >= 100) {
            score -= 100;
        }
        else {
            currentState = GAME_OVER;
        }
        tempInvincible = true;
        tempInvincibilityClock.restart();
        return true;
    }

    return false;
}

void Snake::setDirection(Direction direction) {
    currentDirection = direction;
}

Direction Snake::getDirection() const {
    return currentDirection;
}

float Snake::getSpeed() const {
    return speed;
}

void Snake::setSpeed(float newSpeed) {
    speed = newSpeed;
}

void Snake::increaseSpeed() {
    speed += 0.01f;
}

int Snake::getScore() const {
    return score;
}

void Snake::setScore(int newScore) {
    score = newScore;
}

void Snake::increaseScore(int amount) {
    score += amount;
}

bool Snake::isInvincible() const {
    return invincible;
}

void Snake::setInvincible(bool inv) {
    invincible = inv;
}

void Snake::resetSnake() {
    snakeBody.clear();
    head.setPosition(400, 300);
    snakeBody.push_back(head);
    currentDirection = NONE;
    invincible = false;
    stopSnake = false;
    score = 0;
    health = 3;
    speed = 20.0f;
}

bool Snake::getStopSnake() const {
    return stopSnake;
}

void Snake::setStopSnake(bool stop) {
    stopSnake = stop;
}

std::vector<sf::RectangleShape>& Snake::getBody() {
    return snakeBody;
}
