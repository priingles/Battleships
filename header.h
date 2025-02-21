
#ifndef HEADER_H
#define HEADER_H

#include <stdbool.h>



int main();
int gridSetup();
void displayGrid();
void displayTrackingGrid();
bool validPosition(int coordinates, int size, char type);
void attack(int cood);
void gridUpdate(int cood, char type, char grid[][11]);
struct Ship newShip(char name[], int size, char type);
int botPlay();

typedef struct Ship {

    char name[30];
    int size;
    char type;
}Ship;

typedef struct Player {

    char name[50];

    struct Ship carrier;
    struct Ship battleship;
    struct Ship destroyer;
    struct Ship submarine;
    struct Ship patrolBoat;



    char playingGrid[11][11] = { // Grid with player ships present and everything
        {'0','1','2','3','4','5','6','7','8','9','0'},
        {'1','~','~','~','~','~','~','~','~','~','~'},
        {'2','~','~','~','~','~','~','~','~','~','~'},
        {'3','~','~','~','~','~','~','~','~','~','~'},
        {'4','~','~','~','~','~','~','~','~','~','~'},
        {'5','~','~','~','~','~','~','~','~','~','~'},
        {'6','~','~','~','~','~','~','~','~','~','~'},
        {'7','~','~','~','~','~','~','~','~','~','~'},
        {'8','~','~','~','~','~','~','~','~','~','~'},
        {'9','~','~','~','~','~','~','~','~','~','~'},
        {'0','~','~','~','~','~','~','~','~','~','~'},
    };

    char trackingGrid[11][11] = { // grid for tracking hits, only commenting incase im high as shit when I read this next
        {'0','1','2','3','4','5','6','7','8','9','0'},
        {'1','~','~','~','~','~','~','~','~','~','~'},
        {'2','~','~','~','~','~','~','~','~','~','~'},
        {'3','~','~','~','~','~','~','~','~','~','~'},
        {'4','~','~','~','~','~','~','~','~','~','~'},
        {'5','~','~','~','~','~','~','~','~','~','~'},
        {'6','~','~','~','~','~','~','~','~','~','~'},
        {'7','~','~','~','~','~','~','~','~','~','~'},
        {'8','~','~','~','~','~','~','~','~','~','~'},
        {'9','~','~','~','~','~','~','~','~','~','~'},
        {'0','~','~','~','~','~','~','~','~','~','~'},
    };
}Player;

#endif // HEADER_H
