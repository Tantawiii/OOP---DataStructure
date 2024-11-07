#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include "Position.h"

class Collectible {
public:
    Collectible();
    bool checkCollision(const sf::RectangleShape& snakeHead) const;
    void generateCollectible(const sf::RenderWindow& window, const std::vector<Position>& emptyPositions);
    void generateDownsizeCollectible(const std::vector<Position>& emptyPositions, int cellSizeX, int cellSizeY, bool immediateRespawn);
    void generateInvincibilityCollectible(const std::vector<Position>& emptyPositions, int cellSizeX, int cellSizeY, bool immediateRespawn);

    const sf::RectangleShape& getCollectibleShape() const { return collectible; }
    const sf::RectangleShape& getShrinkCollectibleShape() const { return shrinkCollectible; }
    const sf::RectangleShape& getInvincibilityCollectibleShape() const { return invincibilityCollectible; }

private:
    sf::RectangleShape collectible;
    sf::RectangleShape shrinkCollectible;
    sf::RectangleShape invincibilityCollectible;
};
