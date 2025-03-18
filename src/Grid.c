#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "Header.h"
#include "Globals.h"




void clear_terminal() {
#ifdef _WIN32
    system("cls"); // Windows
#else
    system("clear");  // Linux/macOS
#endif
}

char playingGrid[11][11] = {
    // Grid with player ships present and everything
    {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '0'},
    {'1', '~', '~', '~', '~', '~', '~', '~', '~', '~', '~'},
    {'2', '~', '~', '~', '~', '~', '~', '~', '~', '~', '~'},
    {'3', '~', '~', '~', '~', '~', '~', '~', '~', '~', '~'},
    {'4', '~', '~', '~', '~', '~', '~', '~', '~', '~', '~'},
    {'5', '~', '~', '~', '~', '~', '~', '~', '~', '~', '~'},
    {'6', '~', '~', '~', '~', '~', '~', '~', '~', '~', '~'},
    {'7', '~', '~', '~', '~', '~', '~', '~', '~', '~', '~'},
    {'8', '~', '~', '~', '~', '~', '~', '~', '~', '~', '~'},
    {'9', '~', '~', '~', '~', '~', '~', '~', '~', '~', '~'},
    {'0', '~', '~', '~', '~', '~', '~', '~', '~', '~', '~'},
};

char trackingGrid[11][11] = {
    // grid for tracking hits, only commenting incase im high as shit when I read this next
    {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '0'},
    {'1', '~', '~', '~', '~', '~', '~', '~', '~', '~', '~'},
    {'2', '~', '~', '~', '~', '~', '~', '~', '~', '~', '~'},
    {'3', '~', '~', '~', '~', '~', '~', '~', '~', '~', '~'},
    {'4', '~', '~', '~', '~', '~', '~', '~', '~', '~', '~'},
    {'5', '~', '~', '~', '~', '~', '~', '~', '~', '~', '~'},
    {'6', '~', '~', '~', '~', '~', '~', '~', '~', '~', '~'},
    {'7', '~', '~', '~', '~', '~', '~', '~', '~', '~', '~'},
    {'8', '~', '~', '~', '~', '~', '~', '~', '~', '~', '~'},
    {'9', '~', '~', '~', '~', '~', '~', '~', '~', '~', '~'},
    {'0', '~', '~', '~', '~', '~', '~', '~', '~', '~', '~'},
};


// gridSetup - User inputs for ship placement(validPosition)

Ship playerShips[SHIP_COUNT] = {
    {"Carrier", 5, 'C'},
    {"Battleship", 4, 'B'},
    {"Destroyer", 3, 'D'},
    {"Submarine", 3, 'S'},
    {"Patrol Boat", 2, 'P'}
};

int gridSetup(Player *player) {

    // char msg[500];
    // snprintf(msg, sizeof(msg), "Hey %s!!\n"
    //     "You have 5 ship types you can set up on the grid, either horizontally or vertically\n"
    //     "Ships cannot overlap or be positioned outside of the grid.\n"
    //     "Where do you want to position your ships?\n"
    //     "{351} 3 being row, 5 being column and 1 being vertical(0-horizontal)\n"
    //     "On the grid a Carrier is represented as a 5, Battleships are 4s, Destroyers 3, Submarines 2 and Patrol boats 1\n",
    //     player->name);
    // setHdr_txt(msg);
    // display();

    // WILL BE MOVED SOMEWHERE ELSE



    for (int i = 0; i < (sizeof(playerShips) / sizeof(playerShips[0])); i++) {
        printf("Enter %s coordinates: ", playerShips[i].name);
        while (!validMove) {
            // scanf("%d",&coordinates);
            fgets(input, sizeof(input), stdin);
            cood = strtol(input, &endptr, 10);
            if (endptr == input) {
                printf("Please enter a valid coordinate.\n{351} 3 being row, 5 being column and 1 being vertical(0-horizontal)\n");
            } else if (*endptr == '\n') {
                validMove = validPosition(cood, playerShips[i].size, playerShips[i].type, player);
            }
        }
        validMove = false;
        clear_terminal();
        display();
    }

    printf("This is your playing and tracking grid\n");

    return 0;
}

// validPosition - Ship placement on user grid

bool validPosition(const int coordinates, const int size, const char type, Player *player) {
    // Coordinates deconstructor
    int row = (coordinates / 100);
    int col = ((coordinates % 100) / 10);
    const int axis = coordinates % 10;

    //changes 0s to 10s
    if (row == 0) {
        row = 10;
    }
    if (col == 0) {
        col = 10;
    }

    if (axis % 2 == 0) {
        // Horizontally aligned ships
        for (int i = 0; i < size; i++) {
            if (col + size >= 12) {
                printf("Ship placement out of bounds! Try again: \n");
                return false;
            }
            if (player->playingGrid[row][col + i] != '~') {
                printf("Grid position is occupied, Try again: ");
                return false;
            }
        }
        for (int i = 0; i < size; i++) {
            if (player->playingGrid[row][col + i] == '~') {
                player->playingGrid[row][col + i] = type;
                if (i == size - 1) {
                    return true;
                }
            }
        }
    } else if (axis % 2 == 1) {
        // Vertically aligned ships
        for (int i = 0; i < size; i++) {
            if (row + size >= 12) {
                printf("Ship placement out of bounds! Try again: \n");
                return false;
            }
            if (player->playingGrid[row + i][col] != '~') {
                printf("Grid position is occupied, Try again: ");
                return false;
            }
        }
        for (int i = 0; i < size; i++) {
            if (player->playingGrid[row + i][col] == '~') {
                player->playingGrid[row + i][col] = type;
                if (i == size - 1) {
                    return true;
                }
            }
        }
    }

    return false;
}

    // gridUpdate - Tracking grid updates
    void gridUpdate(const int cood, const char type, char grid[][11]) {
    int row = (cood / 10) % 10;
    int col = (cood % 10);

    //changes 0s(grid labelling for the 10th row/col) to 10s(actual position of row/col in 2d array
    if (row == 0) {
        row = 10;
    }
    if (col == 0) {
        col = 10;
    }

    grid[row][col] = type;
}


