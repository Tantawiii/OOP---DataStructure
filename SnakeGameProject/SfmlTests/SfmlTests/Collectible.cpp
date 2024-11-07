#include "Collectible.h"
#include <cstdlib>

Collectible::Collectible()
    : collectible(sf::Vector2f(20, 20)), shrinkCollectible(sf::Vector2f(20, 20)), invincibilityCollectible(sf::Vector2f(20, 20)) {
    collectible.setFillColor(sf::Color::Green);
    shrinkCollectible.setFillColor(sf::Color::Cyan);
    invincibilityCollectible.setFillColor(sf::Color::Magenta);
}

bool Collectible::checkCollision(const sf::RectangleShape& snakeHead) const {
    return snakeHead.getGlobalBounds().intersects(collectible.getGlobalBounds()) ||
        snakeHead.getGlobalBounds().intersects(shrinkCollectible.getGlobalBounds()) ||
        snakeHead.getGlobalBounds().intersects(invincibilityCollectible.getGlobalBounds());
}

void Collectible::generateCollectible(const sf::RenderWindow& window, const std::vector<Position>& emptyPositions) {
    if (emptyPositions.empty()) return;
    Position pos = emptyPositions[rand() % emptyPositions.size()];
    collectible.setPosition(pos.col * collectible.getSize().x, pos.row * collectible.getSize().y);
}

void Collectible::generateDownsizeCollectible(const std::vector<Position>& emptyPositions, int cellSizeX, int cellSizeY, bool immediateRespawn) {
    if (!immediateRespawn) return;
    if (emptyPositions.empty()) return;
    Position pos = emptyPositions[rand() % emptyPositions.size()];
    shrinkCollectible.setPosition(pos.col * cellSizeX, pos.row * cellSizeY);
}

void Collectible::generateInvincibilityCollectible(const std::vector<Position>& emptyPositions, int cellSizeX, int cellSizeY, bool immediateRespawn) {
    if (!immediateRespawn) return;
    if (emptyPositions.empty()) return;
    Position pos = emptyPositions[rand() % emptyPositions.size()];
    invincibilityCollectible.setPosition(pos.col * cellSizeX, pos.row * cellSizeY);
}
