#include <stdio.h>
#include <stdlib.h>
#include "Header.h"
#include "Globals.h"

Ship botShips[SHIP_COUNT] = {
    {"Carrier", 5, 'C'},
    {"Battleship", 4, 'B'},
    {"Destroyer", 3, 'D'},
    {"Submarine", 3, 'S'},
    {"Patrol Boat", 2, 'P'}
};

int botPlay(Player *bot, Player *player) {
    const int random_cood = (rand() % 90) + 10;
    const int threshold = 100;
    const int random_val = rand() % threshold;

    if (random_val == 0) {
        info_msg("Bot attacked 00\n");
        attack('00', bot, player);

    } else {
        char message[100];
        char coord[10];
        sprintf(message, "Bot attacked %d", random_cood);
        sprintf(coord, "%d", random_cood);
        info_msg(message);
        attack(coord, bot, player);
    }

    return 0;
}

// Employs same logic as gridSetup, randomises cood and removes user feedback where I can
int botGridSetup() {
    for (int i = 0; i < (sizeof(botShips) / sizeof(botShips[0])); i++) {
        while (!validMove) {
            const int random_cood = (rand() % 900) + 100;
            validMove = validPosition(random_cood, botShips[i].size, botShips[i].type, &bot);
        }
        validMove = false;
        clear_terminal();
    }

    return 0;
}
