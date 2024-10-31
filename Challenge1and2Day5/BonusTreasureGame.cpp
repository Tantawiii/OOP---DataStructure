#include "BonusTreasureGame.h"
using namespace std;

BonusTreasureGame::BonusTreasureGame() : gameOver(false) {
    srand(static_cast<unsigned int>(time(0)));
    initializeBorder();
    placePlayerAndTarget();
}

BonusTreasureGame::~BonusTreasureGame() {
    cout << "Game Has Ended!" << endl;
}

void BonusTreasureGame::initializeBorder() {
    for (int i = 0; i < grid; i++) {
        for (int j = 0; j < grid; j++) {
            if (i == 0 || i == grid - 1 || j == 0 || j == grid - 1) {
                border[i][j] = ':';
            }
            else {
                border[i][j] = ' ';
            }
        }
    }
}

void BonusTreasureGame::placePlayerAndTarget() {
    playerX = rand() % (grid - 2) + 1;
    playerY = rand() % (grid - 2) + 1;
    border[playerX][playerY] = 'O';

    do {
        targetX = rand() % (grid - 2) + 1;
        targetY = rand() % (grid - 2) + 1;
    } while (targetX == playerX && targetY == playerY);

    border[targetX][targetY] = 'X';
}

void BonusTreasureGame::displayGrid() {
    system("cls");
    for (int i = 0; i < grid; i++) {
        for (int j = 0; j < grid; j++) {
            cout << border[i][j] << ' ';
        }
        cout << endl;
    }
}

bool BonusTreasureGame::checkGameOver() {
    if (playerX == targetX && playerY == targetY) {
        displayGrid();
        cout << "You Win!\n";
        return true;
    }
    return false;
}

void BonusTreasureGame::startGame() {
    while (!gameOver) {
        displayGrid();
        char movement = _getch();
        int tempX = playerX, tempY = playerY;

        if (movement == 'w') tempX--;
        else if (movement == 's') tempX++;
        else if (movement == 'a') tempY--;
        else if (movement == 'd') tempY++;
        else continue;

        if (border[tempX][tempY] != ':') {
            border[playerX][playerY] = ' ';
            playerX = tempX;
            playerY = tempY;
            border[playerX][playerY] = 'O';
        }

        gameOver = checkGameOver();
    }
}
