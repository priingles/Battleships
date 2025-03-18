
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
int gridSetup(Player *player);
bool validPosition(int coordinates, int size, char type, Player *player);
void gridUpdate(int cood, char type, char grid[][11]);

//Player.c methods
Player createPlayer(char name[50]);
Player createBot();
void initGrid(struct Player *player);


//Game.c methods
int gameSetup();
int gameStart();
int gameLoop();
bool attack(int cood, Player *att, Player *target);

//Ship.c methods
Ship newShip(char name[], int size, char type);

//Bot.c methods
int botPlay();
int initBot(Player *bot);
int botGridSetup();

//Display.c methods
int display();
void displayGrids(char playingGrid[11][11], char trackingGrid[11][11]);
void info_msg(char msg[100]);
void setHdr_txt(char msg[300]);

//MACROS
#define PLAYER_TURN 0
#define BOT_TURN 1
#define SHIP_COUNT 5

#endif // HEADER_H
