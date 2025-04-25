#ifndef HEADER_H
#define HEADER_H

#include <stdbool.h>



typedef struct Ship {
    char name[30];
    int size;
    char type;
} Ship;

typedef struct Player {
    char name[50];
    Ship carrier;
    Ship battleship;
    Ship destroyer;
    Ship submarine;
    Ship patrolBoat;
    char playingGrid[11][11];
    char trackingGrid[11][11];
} Player;


typedef struct gameState {
    Player player;
    Player bot;
    struct gameStateNode *next, *prev;
} GameState;

typedef struct gameStateNode {
    struct gameState *gameState;
    struct gameStateNode *prev;
    struct gameStateNode *next;
} GameStateNode;

int main();

// Menu.c methods
int menu();
void rules();

// Grid.c methods
void clear_terminal();
int gridSetup(Player *player);
bool validPosition(int coordinates, int size, char type, Player *player);
void gridUpdate(int cood, char type, char grid[][11]);

// Player.c methods
Player createPlayer(char name[50]);
Player createBot();
void initGrid(struct Player *player);

// Game.c methods
int gameSetup();
int gameStart();
int gameLoop(const Player player, const Player player2);
bool attack(char input[10], Player *att, Player *target);
GameStateNode* get_current();

// Ship.c methods
Ship newShip(char name[], int size, char type);

// Bot.c methods
int botPlay();
int initBot(Player *bot);
int botGridSetup();

// Display.c methods
int display();
void displayGrids(char playingGrid[11][11], char trackingGrid[11][11]);
void info_msg(char msg[100]);
void setHdr_txt(char msg[300]);

// Records.c methods
int save();
int load();
int recordMove(GameState *gameState);

// MACROS
#define PLAYER_TURN 0
#define BOT_TURN 1
#define SHIP_COUNT 5

#endif // HEADER_H
