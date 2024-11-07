#include "Snake.h"
// Function to draw the snake
void Snake::drawSnake(RenderWindow& window, vector<RectangleShape>& snakeBody) {
    for (auto& segment : snakeBody) {
        window.draw(segment);
    }
}
// Function to place snake head at a random valid position
void Snake::placeSnakeHead(RectangleShape& head, vector<Position> emptyPositions, const RectangleShape& obstacle, const RectangleShape& collectible, int cellSizeX, int cellSizeY) {
    // Shuffle empty positions to ensure randomness
    random_device rd;
    default_random_engine rng(rd());
    shuffle(emptyPositions.begin(), emptyPositions.end(), rng);

    // Iterate through shuffled positions to find a valid one
    for (const auto& pos : emptyPositions) {
        // Set snake head position based on the grid cell
        head.setPosition(pos.col * cellSizeX, pos.row * cellSizeY);

        // Check if the head collides with the obstacle or collectible
        if (!head.getGlobalBounds().intersects(obstacle.getGlobalBounds()) &&
            !head.getGlobalBounds().intersects(collectible.getGlobalBounds())) {
            return; // Found a valid position, so we exit
        }
    }
    // If no valid position is found, fall back to default position (optional)
    head.setPosition(400, 300); // Center position
}

// Function to move the snake based on the current direction
void Snake::moveSnake(vector<RectangleShape>& snakeBody, Direction currentDirection, float speed) {
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
    case NONE:
        break;
    }
}

// Function to extend the snake's body by adding a segment opposite to the current direction
void Snake::extendSnake(vector<RectangleShape>& snakeBody, Direction currentDirection) {
    RectangleShape newSegment(Vector2f(20, 20));
    newSegment.setFillColor(Color::Green);
    Vector2f tailPosition = snakeBody.back().getPosition();

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