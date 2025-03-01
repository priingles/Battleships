#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "header.h"


/**
 * TO DO
 * 1. Bot random and automated ship placement on grid
 * 2. Undo and redo capability
 */

/**
 * BUGS
 * 1. When an axis value is entered other than 1,0
 * the exact value is printed to console as opposed to an error
 * and retry loop
 * 2. A ship cant be placed directly at the bottom in vertical orientation **CRUCIAL
 * 3. No error catching for when a player attacks a spot they already have in the past
 * 4. Tracking grid is not updated after hits or misses
 *
 *
 *
 *
 * CURRENTLY FIXING: 5
 */

int main(void) {

    srand(time(NULL));

    gameSetup();
    gameLoop();

    // Player player;
    // initGrid(&player);
    // botPlay(&player);



    return 0;
}