#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "header.h"


/**
 * TO DO
 * 1. Bot random and automated ship placement on grid
 * 2. Undo and redo capability
 * 3. Update display so different parts of the ui could be updated without having
 *    everything moving and going away
 *    . info log: keeps track of what's happening e.g. you missed, bot missed
 *    . some form of display persistence. as new lines are added to the info log
 *      other lines remain until the limit(5)
 */

/**
 * BUGS
 *
 * CURRENTLY FIXING: 0
 */

int main(void) {
    srand(time(NULL));

    gameSetup();
    gameLoop();

    // Player player = createPlayer("name");
    // Player bot;
    // initBot(&bot);
    // gridSetup(&player);


    return 0;
}
