#include <string.h>
#include "header.h"


struct ship newShip(char name[], int size, char type) {
    struct ship newShip = { 0, "", 'o'};
    strcpy(newShip.name, name);
    newShip.type = type;
    newShip.size = size;

    return newShip;
}