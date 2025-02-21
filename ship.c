#include <string.h>
#include "header.h"


Ship newShip(char name[], int size, char type) {
    Ship newShip = { 0, "", 'o'};
    strcpy(newShip.name, name);
    newShip.type = type;
    newShip.size = size;

    return newShip;
}