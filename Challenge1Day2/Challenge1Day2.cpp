#include <iostream>
#include <string.h>
using namespace std;

struct Player {
    char represent;
    string name;
};
struct Map {
    char represent[3][3];
};
int main()
{
    Player player;
    player.name = "Khalied";
    player.represent = 'X';
    Player player2;
    player2.name = "Tanta";
    player2.represent = 'O';
    cout << sizeof(Player) << endl;
    cout << sizeof(player) << endl;
    cout << sizeof(player2) << endl;
    cout << sizeof(Map) << endl;
}

