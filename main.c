#include "header.h"

int main(void) {

    gridSetup();
    attack(10);
    attack(20);
    attack(31);
    attack(41);
    attack(51);
    attack(84);
    displayGrid();
    displayTrackingGrid();
    return 0;
}