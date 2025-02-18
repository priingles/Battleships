
#ifndef HEADER_H
#define HEADER_H

#include <stdbool.h>



int main();
int gridSetup();
void displayGrid();
void displayTrackingGrid();
bool gridPosition(int coordinates, int size, char type);
void attack(int cood);
void gridUpdate(int cood, char type, char grid[][11]);
struct ship newShip(char name[], int size, char type);

struct ship {
    int size;
    char name[30];
    char type;
};

#endif // HEADER_H
