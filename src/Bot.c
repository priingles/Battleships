#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "header.h"

int initBot(Player *bot) {

    strcpy(bot->name, "Bot");
    initGrid(bot);

    return 0;
}

int botPlay(Player *bot, Player *player) {

    const int random_cood = (rand() % 90) + 10;
    const int threshold = 100;
    const int random_val = rand() % threshold;

    if (random_val == 0) {
        attack(00, bot,player);
        printf("00");
    } else {
        attack(random_cood, bot, player);
        printf("%d", random_cood);
    }

    return 0;
}