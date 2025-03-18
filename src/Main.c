#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Header.h"



/**
 * TO DO
 * 1. Game logic works competently, focus is now on UI and how info is displayed
 *
 */

/**
 * BUGS
 *
 * 1. Bot calls out hit like a player, instead bot go like 'your carrier has been hit'
 * 2. move all printed text from printf to info_msg
 *  . currently fixing up the hit call function in attack()
 *
 * CURRENTLY FIXING: 0
 */

/**
 * MISC
 * 1. Don't forget to undo grid msg comment and then move somewhere else
 *
 */

int main(void) {
    srand(time(NULL));
    gameSetup();
    gameLoop();

    
    return 0;
}
