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
#include "Extras.h"
#include "Grid.h"
#include "Snake.h"
#include "Obstacle.h"
#include "Collectible.h"

using namespace std;
using namespace sf;

class Game
{
private:
    Extras extra;
    GameState gameState;
    Position position;
    Snake snake;
    Obstacle obstacle;
    Collectible collectible;
    vector<Position> emptyPositions;

public:
    // Setters
    void setExtras(const Extras& e) { extra = e; }
    void setGameState(const GameState& state) { gameState = state; }
    void setPosition(const Position& pos) { position = pos; }
    void setSnake(const Snake& s) { snake = s; }
    void setObstacle(const Obstacle& o) { obstacle = o; }
    void setCollectible(const Collectible& c) { collectible = c; }
    void setEmptyPositions(const vector<Position>& positions) { emptyPositions = positions; }

    // Getters
    Extras getExtras() const { return extra; }
    GameState getGameState() const { return gameState; }
    Position getPosition() const { return position; }
    Snake getSnake() const { return snake; }
    Obstacle getObstacle() const { return obstacle; }
    Collectible getCollectible() const { return collectible; }
    vector<Position> getEmptyPositions() const { return emptyPositions; }
};
