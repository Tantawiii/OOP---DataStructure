//#include "Game.h"
//#include "Collectible.h"
//#include "Grid.h"
//#include <SFML/Graphics.hpp>
//
//int main() {
//    srand(static_cast<unsigned>(time(0)));
//    sf::RenderWindow window(sf::VideoMode(800, 800), "Snake Game", sf::Style::Titlebar | sf::Style::Close);
//    window.setFramerateLimit(60);
//
//    // Initialize game elements
//    Game game;
//    Extras extra;
//    sf::Font font;
//    sf::Texture backgroundTexture;
//    sf::Sprite background;
//    sf::SoundBuffer buffer;
//    sf::Sound sound;
//    sf::Text startText, exitText, gameOverText, healthText, speedText, scoreText;
//
//    // Load assets and setup texts
//    extra.loadFont(font);
//    extra.loadBackground(backgroundTexture, background, window);
//    extra.playBackgroundMusic(buffer, sound);
//    extra.setupText(startText, font, "Press Enter to Start", window.getSize().x / 2.0f, window.getSize().y / 2.0f - 30);
//    extra.setupText(exitText, font, "Press Escape to Exit", window.getSize().x / 2.0f, window.getSize().y / 2.0f + 30);
//    extra.setupText(gameOverText, font, "Game Over! Press Enter to Restart", window.getSize().x / 2.0f, window.getSize().y / 2.0f);
//    game.setExtras(extra);
//
//    // Set up game state and grid
//    GameState gameState = MENU;
//    int cellSizeX = window.getSize().x / 10;
//    int cellSizeY = window.getSize().y / 10;
//
//    // Initialize grid and empty positions
//    std::vector<Position> emptyPositions;
//    char grids[10][10];
//    Grid grid;
//    grid.getGrid("C:/Users/omart/OneDrive/Documents/GitHub/SnakeGame/SfmlTests/gridfile.txt", grids, emptyPositions);
//
//    // Initialize collectibles
//    Collectible collectible;
//    collectible.generateCollectible(window, emptyPositions);
//
//    // Game loop
//    while (window.isOpen()) {
//        sf::Event event;
//        while (window.pollEvent(event)) {
//            if (event.type == sf::Event::Closed) window.close();
//        }
//
//        window.clear();
//
//        // Draw collectibles
//        window.draw(collectible.getCollectibleShape());
//        window.draw(collectible.getShrinkCollectibleShape());
//        window.draw(collectible.getInvincibilityCollectibleShape());
//
//        window.display();
//    }
//
//    return 0;
//}
#include "Game.h"

int main() {
    Game game;
    game.run();  // Centralized game loop
    return 0;
}