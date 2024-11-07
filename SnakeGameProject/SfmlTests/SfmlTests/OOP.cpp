//#include <SFML/Audio.hpp>
//#include <SFML/Graphics.hpp>
//#include <SFML/Window.hpp>
//#include <iostream>
//#include <vector>
//#include <cstdlib>
//#include <ctime>
//#include <fstream>
//#include <string>
//#include <algorithm>
//#include <random>
//
//using namespace std;
//using namespace sf;
//
//// Enum for managing game state
//enum GameState { MENU, GAME, GAME_OVER };
//
//// Enum for snake movement direction
//enum Direction { NONE, UP, DOWN, LEFT, RIGHT };
//
//// Struct for storing grid positions
//struct Position {
//    int row;
//    int col;
//};
//
//// Function prototypes
//void loadFont(Font& font);
//void loadBackground(Texture& backgroundTexture, Sprite& background, const RenderWindow& window);
//void setupText(Text& text, const Font& font, const string& content, float x, float y);
//void playBackgroundMusic(SoundBuffer& buffer, Sound& sound);
//void drawSnake(RenderWindow& window, vector<RectangleShape>& snakeBody);
//void placeSnakeHead(RectangleShape& head, vector<Position> emptyPositions, const RectangleShape& obstacle, const RectangleShape& collectible, int cellSizeX, int cellSizeY);
//void moveSnake(vector<RectangleShape>& snakeBody, Direction currentDirection, float speed);
//bool checkCollision(const RectangleShape& snakeHead, const RectangleShape& collectible);
//bool checkSnakeCollision(
//    const vector<RectangleShape>& snakeBody,
//    const RectangleShape& mainObstacle,
//    const RectangleShape& obstacleX,
//    const RectangleShape& obstacleY,
//    char grid[10][10],
//    int cellSizeX,
//    int cellSizeY,
//    int& health,
//    bool invincible,
//    bool& stopSnake,
//    int& score,
//    GameState& currentState,
//    bool& tempInvincible,            // Add tempInvincible parameter
//    Clock& tempInvincibilityClock    // Add tempInvincibilityClock parameter
//);
//void generateCollectible(RectangleShape& collectible, const RenderWindow& window, const vector<Position>& emptyPositions, Clock& collectibleTimer, char grid[10][10]);
//void generateDownsizeCollectible(RectangleShape& downsizeCollectible, const vector<Position>& emptyPositions, int cellSizeX, int cellSizeY, Clock& downsizeTimer, bool immediateRespawn);
//void generateInvincibilityCollectible(RectangleShape& invincibilityCollectible, const vector<Position>& emptyPositions, int cellSizeX, int cellSizeY, Clock& invincibilityTimer, bool immediateRespawn);
//void extendSnake(vector<RectangleShape>& snakeBody, Direction currentDirection);
//void getGrid(const string& path, char grid[10][10], vector<Position>& emptyPositions);
//void drawWalls(RenderWindow& window, char grid[10][10], int cellSizeX, int cellSizeY);
//void spawnObstacle(RectangleShape& obstacle, const vector<Position>& emptyPositions, int cellSizeX, int& obstacleDirection);
//void moveMainObstacle(RectangleShape& obstacle, int& obstacleDirection, float& obstacleSpeed, int cellSizeX, int cellSizeY, const RenderWindow& window, char grid[10][10]);
//void moveYAxisObstacle(RectangleShape& obstacleY, float& obstacleSpeed, int cellSizeY, const RenderWindow& window, char grid[10][10]);
//void moveXAxisObstacle(RectangleShape& obstacleX, float& obstacleSpeed, int cellSizeX, const RenderWindow& window, char grid[10][10]);
//
//int main() {
//    srand(static_cast<unsigned>(time(0)));
//
//    RenderWindow window(VideoMode(800, 800), "Snake Game", Style::Titlebar | Style::Close);
//    window.setFramerateLimit(60);
//
//    Font font;
//    loadFont(font);
//
//    Texture backgroundTexture;
//    Sprite background;
//    loadBackground(backgroundTexture, background, window);
//
//    SoundBuffer buffer;
//    Sound sound;
//    playBackgroundMusic(buffer, sound);
//
//    Text startText, exitText, gameOverText, healthText, speedText, scoreText;
//    setupText(startText, font, "Press Enter to Start", window.getSize().x / 2.0f, window.getSize().y / 2.0f - 30);
//    setupText(exitText, font, "Press Escape to Exit", window.getSize().x / 2.0f, window.getSize().y / 2.0f + 30);
//    setupText(gameOverText, font, "Game Over! Press Enter to Restart", window.getSize().x / 2.0f, window.getSize().y / 2.0f);
//
//    GameState currentState = MENU;
//    Direction currentDirection = NONE;
//    int health = 3;
//    float speed = 20.0f;
//    int score = 0;
//    bool invincible = false;
//    bool stopSnake = false;
//    int cellSizeX = window.getSize().x / 10;
//    int cellSizeY = window.getSize().y / 10;
//
//
//    vector<RectangleShape> snakeBody;
//    RectangleShape head(Vector2f(20, 20));
//    head.setFillColor(Color::Green);
//    head.setPosition(400, 300);
//    snakeBody.push_back(head);
//
//    Clock clock;
//    Time timeSinceLastMove = Time::Zero;
//
//    char grid[10][10];
//    vector<Position> emptyPositions;
//    getGrid("C:/Users/omart/OneDrive/Documents/GitHub/SnakeGame/SfmlTests/gridfile.txt", grid, emptyPositions);
//
//    Clock collectibleTimer;
//    Clock downsizeTimer;       // Clock for downsize collectible delay
//    Clock invincibilityTimer;  // Clock for invincibility collectible delay
//    bool immediateRespawn = false;
//    RectangleShape collectible(Vector2f(20, 20));
//    collectible.setFillColor(Color::Red);
//    generateCollectible(collectible, window, emptyPositions, collectibleTimer, grid);
//
//    RectangleShape shrinkCollectible(Vector2f(20, 20));
//    shrinkCollectible.setFillColor(Color::Cyan);
//    generateDownsizeCollectible(shrinkCollectible, emptyPositions, cellSizeX, cellSizeY, downsizeTimer, immediateRespawn);
//
//    RectangleShape invincibilityCollectible(Vector2f(20, 20));
//    invincibilityCollectible.setFillColor(Color::Magenta);
//    generateInvincibilityCollectible(invincibilityCollectible, emptyPositions, cellSizeX, cellSizeY, invincibilityTimer, immediateRespawn);
//
//
//
//
//    // Create main obstacle
//    RectangleShape obstacle(Vector2f(20, 20));
//    obstacle.setFillColor(Color::Yellow);
//    int obstacleDirection;
//    float mainObstacleSpeed = 0.2f;
//    float yObstacleSpeed = 0.5f;
//    float xObstacleSpeed = 0.5f;
//    bool tempInvincible = false;
//    float tempInvincibilityDuration = 2.0f;
//    Clock tempInvincibilityClock;
//    // Invincibility duration in seconds
//    const float invincibilityDuration = 5.0f; // Set the duration to 5 seconds (or any other value)
//    spawnObstacle(obstacle, emptyPositions, cellSizeX, obstacleDirection);
//
//    RectangleShape obstacleY(Vector2f(20, 20));  // Moves on Y axis
//    obstacleY.setFillColor(Color::White);
//    obstacleY.setPosition(250, 100); // Initial position
//
//    RectangleShape obstacleX(Vector2f(20, 20));  // Moves on X axis
//    obstacleX.setFillColor(Color::Black);
//    obstacleX.setPosition(150, 250); // Initial position
//
//    while (window.isOpen()) {
//        Event event;
//        while (window.pollEvent(event)) {
//            if (event.type == Event::Closed)
//                window.close();
//
//            if (event.type == Event::Resized) {
//                cellSizeX = event.size.width / 10;
//                cellSizeY = event.size.height / 10;
//
//                float scaleX = static_cast<float>(event.size.width) / backgroundTexture.getSize().x;
//                float scaleY = static_cast<float>(event.size.height) / backgroundTexture.getSize().y;
//                background.setScale(scaleX, scaleY);
//
//                window.setView(View(FloatRect(0, 0, event.size.width, event.size.height)));
//
//                setupText(startText, font, "Press Enter to Start", event.size.width / 2.0f, event.size.height / 2.0f - 30);
//                setupText(exitText, font, "Press Escape to Exit", event.size.width / 2.0f, event.size.height / 2.0f + 30);
//                setupText(gameOverText, font, "Game Over! Press Enter to Restart", event.size.width / 2.0f, event.size.height / 2.0f);
//            }
//
//            if (event.type == Event::KeyPressed) {
//                if (currentState == MENU) {
//                    if (event.key.code == Keyboard::Enter) {
//                        currentState = GAME;
//                    }
//                    else if (event.key.code == Keyboard::Escape) {
//                        window.close();
//                    }
//                }
//                else if (currentState == GAME_OVER) {
//                    if (event.key.code == Keyboard::Enter) {
//                        snakeBody.clear();
//                        placeSnakeHead(head, emptyPositions, obstacle, collectible, cellSizeX, cellSizeY);
//                        snakeBody.push_back(head);
//                        currentDirection = NONE;
//                        generateCollectible(collectible, window, emptyPositions, collectibleTimer, grid);
//                        generateDownsizeCollectible(shrinkCollectible, emptyPositions, cellSizeX, cellSizeY, downsizeTimer, immediateRespawn);
//                        generateInvincibilityCollectible(invincibilityCollectible, emptyPositions, cellSizeX, cellSizeY, invincibilityTimer, immediateRespawn);
//                        spawnObstacle(obstacle, emptyPositions, cellSizeX, obstacleDirection);
//                        currentState = GAME;
//                        health = 3;
//                        speed = 20.0f;
//                        score = 0;
//                        invincible = false;
//                        stopSnake = false;
//                    }
//                }
//                else if (currentState == GAME) {
//                    if (!stopSnake) {
//                        if (event.key.code == Keyboard::W && currentDirection != DOWN) {
//                            currentDirection = UP;
//                        }
//                        else if (event.key.code == Keyboard::A && currentDirection != RIGHT) {
//                            currentDirection = LEFT;
//                        }
//                        else if (event.key.code == Keyboard::S && currentDirection != UP) {
//                            currentDirection = DOWN;
//                        }
//                        else if (event.key.code == Keyboard::D && currentDirection != LEFT) {
//                            currentDirection = RIGHT;
//                        }
//                    }
//
//                    if (event.key.code == Keyboard::Escape) {
//                        currentState = MENU;
//                    }
//                }
//            }
//        }
//
//        if (currentState == GAME) {
//            timeSinceLastMove += clock.restart();
//
//            if (timeSinceLastMove.asMilliseconds() > 100) {
//                // Regular respawn handling based on delay
//                generateDownsizeCollectible(shrinkCollectible, emptyPositions, cellSizeX, cellSizeY, downsizeTimer, false);
//                generateInvincibilityCollectible(invincibilityCollectible, emptyPositions, cellSizeX, cellSizeY, invincibilityTimer, false);
//
//                if (!stopSnake) {
//                    moveSnake(snakeBody, currentDirection, speed);
//                }
//
//                // Check for collision with red collectible
//                if (checkCollision(snakeBody[0], collectible)) {
//                    extendSnake(snakeBody, currentDirection);
//                    generateCollectible(collectible, window, emptyPositions, collectibleTimer, grid); // Immediate respawn
//                    speed += 0.01f;
//                    score += 100;
//                }
//
//                // Check for collision with downsize collectible
//                if (checkCollision(snakeBody[0], shrinkCollectible)) {
//                    if (snakeBody.size() > 1) {
//                        snakeBody.resize(ceil(snakeBody.size() / 2));  // Shrink to half size if more than 1 segment
//                    }
//                    downsizeTimer.restart();
//                    score += 1000;
//                    generateDownsizeCollectible(shrinkCollectible, emptyPositions, cellSizeX, cellSizeY, downsizeTimer, true); // Immediate respawn
//                }
//
//                // Check for collision with invincibility collectible
//                if (checkCollision(snakeBody[0], invincibilityCollectible)) {
//                    invincible = true;
//                    tempInvincibilityClock.restart();
//                    generateInvincibilityCollectible(invincibilityCollectible, emptyPositions, cellSizeX, cellSizeY, invincibilityTimer, true); // Immediate respawn
//                }
//
//                // Disable invincibility if the duration has passed
//                if (invincible && tempInvincibilityClock.getElapsedTime().asSeconds() > invincibilityDuration) {
//                    invincible = false;
//                }
//
//                timeSinceLastMove = Time::Zero;
//            }
//
//            // Move obstacles and other game logic
//            moveMainObstacle(obstacle, obstacleDirection, mainObstacleSpeed, cellSizeX, cellSizeY, window, grid);
//            moveYAxisObstacle(obstacleY, yObstacleSpeed, cellSizeY, window, grid);
//            moveXAxisObstacle(obstacleX, xObstacleSpeed, cellSizeX, window, grid);
//
//            if (tempInvincible && tempInvincibilityClock.getElapsedTime().asSeconds() > tempInvincibilityDuration) {
//                tempInvincible = false;
//            }
//
//            if (checkSnakeCollision(
//                snakeBody, obstacle, obstacleX, obstacleY, grid, cellSizeX, cellSizeY,
//                health, invincible, stopSnake, score, currentState, tempInvincible, tempInvincibilityClock)) // Updated arguments
//            {
//                if (health <= 0 || currentState == GAME_OVER) {
//                    currentState = GAME_OVER;
//                }
//            }
//
//            // Update HUD display
//            healthText.setString("Health: " + to_string(health));
//            healthText.setPosition(10, 10);
//            healthText.setFont(font);
//            healthText.setCharacterSize(24);
//            healthText.setFillColor(Color::White);
//
//            speedText.setString("Speed: " + to_string(speed));
//            speedText.setPosition(10, 40);
//            speedText.setFont(font);
//            speedText.setCharacterSize(24);
//            speedText.setFillColor(Color::White);
//
//            scoreText.setString("Score: " + to_string(score));
//            scoreText.setPosition(10, 70);
//            scoreText.setFont(font);
//            scoreText.setCharacterSize(24);
//            scoreText.setFillColor(Color::White);
//        }
//
//        window.clear();
//        if (currentState == MENU) {
//            window.draw(background);
//            window.draw(startText);
//            window.draw(exitText);
//        }
//        else if (currentState == GAME) {
//            drawWalls(window, grid, cellSizeX, cellSizeY);
//            drawSnake(window, snakeBody);
//            window.draw(collectible);
//            window.draw(shrinkCollectible);
//            window.draw(invincibilityCollectible);
//            window.draw(obstacle);
//            window.draw(obstacleY);
//            window.draw(obstacleX);
//            window.draw(healthText);
//            window.draw(speedText);
//            window.draw(scoreText);
//        }
//        else if (currentState == GAME_OVER) {
//            window.draw(gameOverText);
//        }
//        window.display();
//    }
//
//    return 0;
//}
//
//// Function to generate downsize collectible with a delay, and option for immediate respawn
//void generateDownsizeCollectible(RectangleShape& downsizeCollectible, const vector<Position>& emptyPositions, int cellSizeX, int cellSizeY, Clock& downsizeTimer, bool immediateRespawn = false) {
//    float downsizeDelay = 20.0f; // 20 seconds delay
//
//    // Check if immediate respawn is requested
//    if (!immediateRespawn && downsizeTimer.getElapsedTime().asSeconds() < downsizeDelay) {
//        return; // Delay not met, do not spawn
//    }
//
//    // Select a random valid position for the collectible
//    Position pos = emptyPositions[rand() % emptyPositions.size()];
//    downsizeCollectible.setPosition(pos.col * cellSizeX, pos.row * cellSizeY);
//
//    // Restart the timer after spawning the collectible
//    downsizeTimer.restart();
//}
//
//// Function to generate invincibility collectible with a delay, and option for immediate respawn
//void generateInvincibilityCollectible(RectangleShape& invincibilityCollectible, const vector<Position>& emptyPositions, int cellSizeX, int cellSizeY, Clock& invincibilityTimer, bool immediateRespawn = false) {
//    float invincibilityDelay = 50.0f; // 50 seconds delay
//
//    // Check if immediate respawn is requested
//    if (!immediateRespawn && invincibilityTimer.getElapsedTime().asSeconds() <= invincibilityDelay) {
//        return; // Delay not met, do not spawn
//    }
//
//    // Select a random valid position for the collectible
//    Position pos = emptyPositions[rand() % emptyPositions.size()];
//    invincibilityCollectible.setPosition(pos.col * cellSizeX, pos.row * cellSizeY);
//
//    // Restart the timer after spawning the collectible
//    invincibilityTimer.restart();
//}
//
//
//
//bool checkSnakeCollision(
//    const vector<RectangleShape>& snakeBody,
//    const RectangleShape& mainObstacle,
//    const RectangleShape& obstacleX,
//    const RectangleShape& obstacleY,
//    char grid[10][10],
//    int cellSizeX,
//    int cellSizeY,
//    int& health,
//    bool invincible,
//    bool& stopSnake,
//    int& score,
//    GameState& currentState,
//    bool& tempInvincible,            // Add tempInvincible parameter
//    Clock& tempInvincibilityClock    // Add tempInvincibilityClock parameter
//) {
//    const RectangleShape& head = snakeBody[0];
//
//    if (head.getGlobalBounds().intersects(mainObstacle.getGlobalBounds()) ||
//        head.getGlobalBounds().intersects(obstacleX.getGlobalBounds()) ||
//        head.getGlobalBounds().intersects(obstacleY.getGlobalBounds())) {
//        if (invincible) {
//            score += 10;  // Add points if invincible
//            return false;  // No penalty, allow continuation
//        }
//    }
//
//    // Check for self-collision
//    for (size_t i = 1; i < snakeBody.size(); i++) {
//        if (head.getGlobalBounds().intersects(snakeBody[i].getGlobalBounds())) {
//            if (!invincible) health -= 1;
//            return true;
//        }
//    }
//
//    // Check for wall collision
//    int headCol = static_cast<int>(head.getPosition().x) / cellSizeX;
//    int headRow = static_cast<int>(head.getPosition().y) / cellSizeY;
//    if (grid[headRow][headCol] == 'X') {
//        if (invincible) {
//            stopSnake = true;  // Stop movement until player input
//            return false;       // Prevent penalty
//        }
//        else {
//            health -= 1;
//        }
//        return true;
//    }
//
//    // Check for main obstacle collision
//    if (head.getGlobalBounds().intersects(mainObstacle.getGlobalBounds())) {
//        if (!invincible) {
//            health -= 1;
//            return true;
//        }
//    }
//
//    // Check for collision with obstacle X
//    if (head.getGlobalBounds().intersects(obstacleX.getGlobalBounds()) && !tempInvincible) {
//        if (score >= 200) {
//            score -= 200;
//        }
//        else {
//            currentState = GAME_OVER;
//        }
//        tempInvincible = true;
//        tempInvincibilityClock.restart();
//        return true;
//    }
//
//    // Check for collision with obstacle Y
//    if (head.getGlobalBounds().intersects(obstacleY.getGlobalBounds()) && !tempInvincible) {
//        if (score >= 100) {
//            score -= 100;
//        }
//        else {
//            currentState = GAME_OVER;
//        }
//        tempInvincible = true;
//        tempInvincibilityClock.restart();
//        return true;
//    }
//
//    return false; // No collision detected
//}
//
//
//
//
//
//// Function to load a font
//void loadFont(Font& font) {
//    if (!font.loadFromFile("C:/Users/omart/OneDrive/Documents/GitHub/SnakeGame/SfmlTests/Precious.ttf")) {
//        cerr << "Error: Could not load font." << endl;
//    }
//}
//
//// Function to load the background image and scale it to fit the window
//void loadBackground(Texture& backgroundTexture, Sprite& background, const RenderWindow& window) {
//    if (backgroundTexture.loadFromFile("C:/Users/omart/OneDrive/Documents/GitHub/SnakeGame/SfmlTests/images.jpg")) {
//        background.setTexture(backgroundTexture);
//
//        // Scale the background initially to fit the window size
//        float scaleX = static_cast<float>(window.getSize().x) / backgroundTexture.getSize().x;
//        float scaleY = static_cast<float>(window.getSize().y) / backgroundTexture.getSize().y;
//        background.setScale(scaleX, scaleY);
//    }
//    else {
//        cerr << "Error: Could not load background image." << endl;
//    }
//}
//
//// Function to set up and center text properties
//void setupText(Text& text, const Font& font, const string& content, float x, float y) {
//    text.setFont(font);
//    text.setString(content);
//    text.setCharacterSize(30);
//    text.setFillColor(Color::White);
//
//    FloatRect textRect = text.getLocalBounds();
//    text.setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);
//    text.setPosition(x, y);
//}
//
//// Function to load and play background music
//void playBackgroundMusic(SoundBuffer& buffer, Sound& sound) {
//    if (buffer.loadFromFile("C:/Users/omart/OneDrive/Documents/GitHub/SnakeGame/SfmlTests/music.mp3")) {
//        sound.setBuffer(buffer);
//        sound.setLoop(true); // Optional: loops the sound continuously
//        sound.setVolume(10); // Set volume (adjust as needed)
//        sound.play();
//    }
//    else {
//        cerr << "Error: Could not load background music." << endl;
//    }
//}
//
//// Function to draw the snake
//void drawSnake(RenderWindow& window, vector<RectangleShape>& snakeBody) {
//    for (auto& segment : snakeBody) {
//        window.draw(segment);
//    }
//}
//
//// Function to place snake head at a random valid position
//void placeSnakeHead(RectangleShape& head, vector<Position> emptyPositions, const RectangleShape& obstacle, const RectangleShape& collectible, int cellSizeX, int cellSizeY) {
//    // Shuffle empty positions to ensure randomness
//    random_device rd;
//    default_random_engine rng(rd());
//    shuffle(emptyPositions.begin(), emptyPositions.end(), rng);
//
//    // Iterate through shuffled positions to find a valid one
//    for (const auto& pos : emptyPositions) {
//        // Set snake head position based on the grid cell
//        head.setPosition(pos.col * cellSizeX, pos.row * cellSizeY);
//
//        // Check if the head collides with the obstacle or collectible
//        if (!head.getGlobalBounds().intersects(obstacle.getGlobalBounds()) &&
//            !head.getGlobalBounds().intersects(collectible.getGlobalBounds())) {
//            return; // Found a valid position, so we exit
//        }
//    }
//    // If no valid position is found, fall back to default position (optional)
//    head.setPosition(400, 300); // Center position
//}
//
//// Function to move the snake based on the current direction
//void moveSnake(vector<RectangleShape>& snakeBody, Direction currentDirection, float speed) {
//    for (int i = snakeBody.size() - 1; i > 0; --i) {
//        snakeBody[i].setPosition(snakeBody[i - 1].getPosition());
//    }
//
//    switch (currentDirection) {
//    case UP:
//        snakeBody[0].move(0, -speed);
//        break;
//    case DOWN:
//        snakeBody[0].move(0, speed);
//        break;
//    case LEFT:
//        snakeBody[0].move(-speed, 0);
//        break;
//    case RIGHT:
//        snakeBody[0].move(speed, 0);
//        break;
//    case NONE:
//        break;
//    }
//}
//
//// Function to check collision between the snake's head and a collectible
//bool checkCollision(const RectangleShape& snakeHead, const RectangleShape& collectible) {
//    return snakeHead.getGlobalBounds().intersects(collectible.getGlobalBounds());
//}
//
//// Function to generate a collectible at a random empty position within the grid
//void generateCollectible(RectangleShape& collectible, const RenderWindow& window, const vector<Position>& emptyPositions, Clock& collectibleTimer, char grid[10][10]) {
//    if (emptyPositions.empty()) {
//        cerr << "Error: No empty positions available for collectible placement." << endl;
//        return;
//    }
//
//    int cellSizeX = window.getSize().x / 10;
//    int cellSizeY = window.getSize().y / 10;
//
//    // Select a random valid position directly from emptyPositions without additional filtering
//    Position pos = emptyPositions[rand() % emptyPositions.size()];
//
//    // Set collectible position based on the selected grid cell
//    collectible.setPosition(pos.col * cellSizeX, pos.row * cellSizeY);
//
//    // Restart the timer after spawning the collectible
//    collectibleTimer.restart();
//}
//
//
//// Function to extend the snake's body by adding a segment opposite to the current direction
//void extendSnake(vector<RectangleShape>& snakeBody, Direction currentDirection) {
//    RectangleShape newSegment(Vector2f(20, 20));
//    newSegment.setFillColor(Color::Green);
//    Vector2f tailPosition = snakeBody.back().getPosition();
//
//    switch (currentDirection) {
//    case UP:
//        newSegment.setPosition(tailPosition.x, tailPosition.y + 20);
//        break;
//    case DOWN:
//        newSegment.setPosition(tailPosition.x, tailPosition.y - 20);
//        break;
//    case LEFT:
//        newSegment.setPosition(tailPosition.x + 20, tailPosition.y);
//        break;
//    case RIGHT:
//        newSegment.setPosition(tailPosition.x - 20, tailPosition.y);
//        break;
//    default:
//        break;
//    }
//
//    snakeBody.push_back(newSegment);
//}
//
//// Function to read the grid from a file and store it in a 2D array and vector of empty positions
//void getGrid(const string& path, char grid[10][10], vector<Position>& emptyPositions) {
//    ifstream myfile(path, ios_base::in);
//
//    if (!myfile.is_open()) {
//        cerr << "Error: Could not open file." << endl;
//        return;
//    }
//
//    string line;
//    int row = 0;
//
//    while (getline(myfile, line) && row < 10) {
//        for (int col = 0; col < 10; col++) {
//            if (line[col] == '0') {
//                grid[row][col] = '0';
//                emptyPositions.push_back({ row, col }); // Add empty position to the list
//            }
//            else {
//                grid[row][col] = 'X';
//            }
//        }
//        row++;
//    }
//
//    myfile.close();
//}
//
//// Function to draw the grid and walls based on the grid data
//void drawWalls(RenderWindow& window, char grid[10][10], int cellSizeX, int cellSizeY) {
//    for (int row = 0; row < 10; row++) {
//        for (int col = 0; col < 10; col++) {
//            RectangleShape cell(Vector2f(cellSizeX, cellSizeY));
//            cell.setPosition(col * cellSizeX, row * cellSizeY);
//
//            // Set dark grey background for all cells
//            cell.setFillColor(Color(50, 50, 50)); // Dark grey background
//            cell.setOutlineColor(Color::Black);   // Black border to create grid lines
//            cell.setOutlineThickness(-1);         // Draw outline inward
//
//            // If the cell is a wall ('X'), set it to blue color
//            if (grid[row][col] == 'X') {
//                cell.setFillColor(Color::Blue);
//            }
//
//            window.draw(cell);
//        }
//    }
//}
//
//// Function to spawn the main obstacle
//void spawnObstacle(RectangleShape& obstacle, const vector<Position>& emptyPositions, int cellSizeX, int& obstacleDirection) {
//    if (emptyPositions.empty()) {
//        cerr << "Error: No empty positions available for obstacle placement." << endl;
//        return;
//    }
//
//    Position pos = emptyPositions[rand() % emptyPositions.size()];
//    obstacle.setPosition(pos.col * cellSizeX, pos.row * cellSizeX);
//    obstacleDirection = rand() % 2;
//}
//
//// Function to move the main obstacle within the grid, reversing upon hitting a wall
//void moveMainObstacle(RectangleShape& obstacle, int& obstacleDirection, float& mainObstacleSpeed, int cellSizeX, int cellSizeY, const RenderWindow& window, char grid[10][10]) {
//    Vector2f position = obstacle.getPosition();
//    int col = static_cast<int>(position.x) / cellSizeX;
//    int row = static_cast<int>(position.y) / cellSizeY;
//
//    if (obstacleDirection == 0) { // Vertical movement
//        int nextRow = (position.y + mainObstacleSpeed) / cellSizeY;
//        if (nextRow < 0 || nextRow >= 10 || grid[nextRow][col] == 'X') {
//            mainObstacleSpeed = -mainObstacleSpeed; // Reverse direction for main obstacle only
//        }
//        obstacle.move(0, mainObstacleSpeed);
//    }
//    else { // Horizontal movement
//        int nextCol = (position.x + mainObstacleSpeed) / cellSizeX;
//        if (nextCol < 0 || nextCol >= 10 || grid[row][nextCol] == 'X') {
//            mainObstacleSpeed = -mainObstacleSpeed; // Reverse direction for main obstacle only
//        }
//        obstacle.move(mainObstacleSpeed, 0);
//    }
//}
//
//// Function to move the obstacle on Y-axis within the grid, reversing direction upon hitting a wall
//void moveYAxisObstacle(RectangleShape& obstacleY, float& yObstacleSpeed, int cellSizeY, const RenderWindow& window, char grid[10][10]) {
//    Vector2f position = obstacleY.getPosition();
//    int col = static_cast<int>(position.x) / cellSizeY;
//    int row = static_cast<int>(position.y) / cellSizeY;
//
//    int nextRow = static_cast<int>((position.y + yObstacleSpeed) / cellSizeY);
//
//    if (nextRow < 0 || nextRow >= 10 || grid[nextRow][col] == 'X') {
//        yObstacleSpeed = -yObstacleSpeed; // Reverse direction for Y-axis obstacle only
//    }
//
//    obstacleY.move(0, yObstacleSpeed);
//}
//
//// Function to move the obstacle on X-axis within the grid, reversing direction upon hitting a wall
//void moveXAxisObstacle(RectangleShape& obstacleX, float& xObstacleSpeed, int cellSizeX, const RenderWindow& window, char grid[10][10]) {
//    Vector2f position = obstacleX.getPosition();
//    int row = static_cast<int>(position.y) / cellSizeX;
//    int col = static_cast<int>(position.x) / cellSizeX;
//
//    int nextCol = static_cast<int>((position.x + xObstacleSpeed) / cellSizeX);
//
//    if (nextCol < 0 || nextCol >= 10 || grid[row][nextCol] == 'X') {
//        xObstacleSpeed = -xObstacleSpeed; // Reverse direction for X-axis obstacle only
//    }
//
//    obstacleX.move(xObstacleSpeed, 0);
//}
