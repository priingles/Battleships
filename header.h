
#ifndef HEADER_H
#define HEADER_H

#include <stdbool.h>



typedef struct Ship {

    char name[30];
    int size;
    char type;
}Ship;

typedef struct Player {

    char name[50];

    Ship carrier;
    Ship battleship;
    Ship destroyer;
    Ship submarine;
    Ship patrolBoat;

    char playingGrid[11][11];
    char trackingGrid[11][11];

}Player;

int main();
int gridSetup(struct Player player);
void displayGrid(char playingGrid[11][11], char trackingGrid[11][11]);
bool validPosition(int coordinates, int size, char type);
void attack(int cood, struct Player player);
void gridUpdate(int cood, char type, char grid[][11]);
Ship newShip(char name[], int size, char type);
int botPlay();
int gameSetup();
void clear_terminal();
void initGrid(struct Player *player);



#endif // HEADER_H
