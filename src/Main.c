#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Header.h"



/**
 * TO DO
 * 1. Game logic works competently, focus is now game flow
 *
 */

/**
 * BUGS
 * 1. attack breaks on the second attack
 * 1. Bot calls out hit like a player, instead bot go like 'your carrier has been hit'
 * 2. move all printed text from printf to info_msg
 *  . currently fixing up the hit call function in attack()
 *  3. When a ship is sunk, both hit and kill are announced. Only kill should be.
 *
 * CURRENTLY FIXING: 0
 */

/**
 * MISC
 * 1. Don't forget to undo grid msg comment and then move somewhere else
 * 2. Might change how coordinates work
 */

int main(void) {
    srand(time(NULL));
    menu();

    
    return 0;
}
