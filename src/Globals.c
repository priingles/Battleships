#include "Globals.h"

#include <stddef.h>

bool validMove = false;
char input[100] = "";
char *endptr = NULL;
int cood = 0;
int turn = 0;

//SHIPS
// const Ship carrier = {"Carrier", 5, 'C'};
// const Ship battleship = {"Battleship", 4, 'B'};
// const Ship destroyer = {"Destroyer", 3, 'D'};
// const Ship submarine = {"Submarine", 3, 'S'};
// const Ship patrolBoat = {"PatrolBoat", 2, 'P'};
// Ship ships[] = {carrier, battleship, destroyer, submarine, patrolBoat};

//Game.c vars
Player mainPlayer = {0};
Player bot = {0};

//Display.c vars
char hdr[100] = "HEADER MESSAGE PLACEHOLDER\n";
char hdr_txt[500] = "";