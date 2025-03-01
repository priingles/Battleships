
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

//Grid.c methods
void clear_terminal();
void displayGrid(char playingGrid[11][11], char trackingGrid[11][11]);
int gridSetup(Player *player);
bool validPosition(int coordinates, int size, char type, Player *player);
void gridUpdate(int cood, char type, char grid[][11]);

//Player.c methods
int createPlayer(char name[50]);
void initGrid(struct Player *player);

//Game.c methods
int gameSetup();
int gameStart();
int gameLoop();
void attack(int cood, Player *attacker, Player *target);

//Ship.c methods
Ship newShip(char name[], int size, char type);

//Bot.c methods
int botPlay();


int print(Player *player);


#endif // HEADER_H
