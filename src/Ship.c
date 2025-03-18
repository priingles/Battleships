#include <string.h>
#include "Header.h"



Ship newShip(char name[], const int size,const char type) {
    Ship newShip = {0, "", 'o'};
    strcpy(newShip.name, name);
    newShip.type = type;
    newShip.size = size;

    return newShip;
}

