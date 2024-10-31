#include <iostream>
#include <string>
#include <conio.h>
#include <ctime>


class BonusTreasureGame {
private:
    static const int grid = 5;
    char border[grid][grid];
    int playerX, playerY;
    int targetX, targetY;
    bool gameOver;

    void initializeBorder();
    void placePlayerAndTarget();
    void displayGrid();
    bool checkGameOver();

public:
    BonusTreasureGame();
    void startGame();
    ~BonusTreasureGame();
};

