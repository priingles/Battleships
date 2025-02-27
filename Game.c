#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "header.h"

/*
 * REQUIREMENTS
 * 1. Modular grids: All functions that require the grid need to be modified to accept one as param
*/

char input2[100];
char* endptr2;

int difficulty;

int gameSetup(){

    // Creates a player and sets up ships on user-defined coordinates
    Player player1;
    printf("Enter player name: ");
    fgets(player1.name, sizeof(player1.name), stdin);
    player1.name[strcspn(player1.name, "\n")] = '\0'; //removes newline from fgets

    initGrid(&player1);// initialises player playing&trackingGrid
    gridSetup(player1);

    printf("Choose bot difficulty(1-5) [doesnt matter rn]: ");
    fgets(input2, sizeof(input2), stdin);
    difficulty = strtol(input2, &endptr2, 10);

    return 0;
}

int gameStart() {

}
