//
// Created by kleoa on 18/02/2025.
//
#include <stdlib.h>
#include "header.h"


char botPlayingGrid[11][11] = { // Grid with player ships present and everything
    {'0','1','2','3','4','5','6','7','8','9','0'},
    {'1','~','~','~','~','~','~','~','~','~','~'},
    {'2','~','~','~','~','~','~','~','~','~','~'},
    {'3','~','~','~','~','~','~','~','~','~','~'},
    {'4','~','~','~','~','~','~','~','~','~','~'},
    {'5','~','~','~','~','~','~','~','~','~','~'},
    {'6','~','~','~','~','~','~','~','~','~','~'},
    {'7','~','~','~','~','~','~','~','~','~','~'},
    {'8','~','~','~','~','~','~','~','~','~','~'},
    {'9','~','~','~','~','~','~','~','~','~','~'},
    {'0','~','~','~','~','~','~','~','~','~','~'},
};

char botTrackingGrid[11][11] = { // grid for tracking hits, only commenting incase im high as shit when I read this next
    {'0','1','2','3','4','5','6','7','8','9','0'},
    {'1','~','~','~','~','~','~','~','~','~','~'},
    {'2','~','~','~','~','~','~','~','~','~','~'},
    {'3','~','~','~','~','~','~','~','~','~','~'},
    {'4','~','~','~','~','~','~','~','~','~','~'},
    {'5','~','~','~','~','~','~','~','~','~','~'},
    {'6','~','~','~','~','~','~','~','~','~','~'},
    {'7','~','~','~','~','~','~','~','~','~','~'},
    {'8','~','~','~','~','~','~','~','~','~','~'},
    {'9','~','~','~','~','~','~','~','~','~','~'},
    {'0','~','~','~','~','~','~','~','~','~','~'},
};

int botPlay() {

    const int random_cood = 11 + rand() % 99;
    const int threshold = 100;
    const int random_val = rand() % threshold;

    if (random_val == 0) {
        attack(00);
    } else {
        attack(random_cood);
    }

    return 0;
}