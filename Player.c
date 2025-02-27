#include "header.h"
#include <string.h>

int createPlayer(char name[50]) {

    Player player;
    strcpy(player.name, name);


    player.carrier = newShip("Carrier", 5, 'C');
    player.battleship = newShip("Battleship", 4, 'B');
    player.destroyer = newShip("Destroyer", 3, 'D');
    player.submarine = newShip("Submarine", 3, 'S');
    player.patrolBoat = newShip("PatrolBoat", 3, 'P');

}

void initGrid(Player *player) {
    const char tempGrid[11][11] = { // Temporary array
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
        {'0','~','~','~','~','~','~','~','~','~','~'}
    };

    memcpy(player->playingGrid, tempGrid, sizeof(tempGrid));
    memcpy(player->trackingGrid, tempGrid, sizeof(tempGrid));
}
