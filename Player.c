#include "header.h";
#include <string.h>;

int createPlayer(char name[50]) {

    Player player;
    strcpy(player.name, name);

    struct Ship carrier = newShip("Battleship", 4, 'C');
    struct Ship battleship = newShip("Battleship", 4, 'B');
    struct Ship destroyer = newShip("Destroyer", 3, 'D');
    struct Ship submarine = newShip("Submarine", 3, 'S');
    struct Ship patrolBoat = newShip("PatrolBoat", 2, 'P');

    player.carrier = carrier;
    player.battleship = battleship;
    player.destroyer = destroyer;
    player.submarine = submarine;
    player.patrolBoat = patrolBoat;

}