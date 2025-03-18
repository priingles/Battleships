#ifndef GLOBALS_H
#define GLOBALS_H
#include <stdbool.h>

#include "Header.h"


extern bool validMove;
extern char input[100];
extern char *endptr;
extern int cood;
extern int turn; // determines play (odd no. = user, even no. = bot)

//SHIPS

extern const Ship carrier;
extern const Ship battleship;
extern const Ship destroyer;
extern const Ship submarine;
extern const Ship patrolBoat;

extern Ship ships[];

// Game.c vars
extern Player mainPlayer; // current user at any given time
extern Player bot;

//Display.c vars
extern char hdr[100];
extern char hdr_txt[500];

#endif //GLOBALS_H
