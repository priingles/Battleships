#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "header.h"


void clear_terminal() {
#ifdef _WIN32
    system("cls");  // Windows
#else
    system("clear");  // Linux/macOS
#endif
}

char playingGrid[11][11] = { // Grid with player ships present and everything
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

char trackingGrid[11][11] = { // grid for tracking hits, only commenting incase im high as shit when I read this next
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

bool validMove = false; // bool for rightful ship placement

char input[100];
char* endptr;
int cood;





int carrierHp = 5; // these have to go
int battleshipHp = 4; // implement them in the struct just later
int destroyerHp = 3;
int submarineHp = 3;
int patrolBoatHp = 2;



void displayGrid(char playingGrid[][11], char trackingGrid[][11]) {

    printf("\n");
    for (int i = 0; i < 11; i++) {
        for (int j = 0; j < 11; j++) {
            printf("%c ",playingGrid[i][j]);
        }
        printf("            ");
        for (int j = 0; j < 11; j++) {
            printf("%c ",trackingGrid[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}



int gridSetup(Player player) {

    const Ship carrier = newShip("Carrier", 5, 'C');
    const Ship battleship = newShip("Battleship", 4, 'B');
    const Ship destroyer = newShip("Destroyer", 3, 'D');
    const Ship submarine = newShip("Submarine", 3, 'S');
    const Ship patrolBoat = newShip("PatrolBoat", 2, 'P');

    Ship ships[] = {carrier, battleship, destroyer, submarine, patrolBoat};

    printf("Hey %s!!\n", player.name);
    printf("You have 5 ship types you can set up on the grid, either horizontally or vertically\nShips cannot overlap or be positioned outside of the grid.\nWhere do you want to position your ships?\n{351} 3 being row, 5 being column and 1 being vertical(0-horizontal)\n");
    printf("On the grid a Carrier is represented as a 5, Battleships are 4s, Destroyers 3, Submarines 2 and Patrol boats 1\n");

    displayGrid(player.playingGrid, player.trackingGrid);

    for (int i = 0; i < (sizeof(ships)/sizeof(ships[0])); i++) {
        printf("Enter %s coordinates: ", ships[i].name);
        while(!validMove) {

             // scanf("%d",&coordinates);
            fgets(input, sizeof(input), stdin);
            cood = strtol(input, &endptr, 10);
            if (endptr == input) {
                printf("Please enter a valid coordinate.\n{351} 3 being row, 5 being column and 1 being vertical(0-horizontal)\n");
            } else if (*endptr == '\n') {
                validMove = validPosition(cood, ships[i].size, ships[i].type); //
            }

        }
        validMove = false;
        clear_terminal();
        fflush(stdout);
        displayGrid(player.playingGrid, player.trackingGrid);
    }

    printf("This is your playing and tracking grid\n");

    return 0;
}

// Positions a ship on the playing grid
bool validPosition(const int coordinates, const int size, const char type) {

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



    if (axis == 0) { // Horizontally aligned ships
        for (int i = 0; i < size; i++) {
            if (col + size >= 11) {
                printf("Ship placement out of bounds! Try again: \n");
                break;
            }
            if (playingGrid[row][col + i] == '~') {
                playingGrid[row][col + i] = type;
                if (i == size - 1) {
                    return true;
                }
            } else {
                printf("Grid position is occupied, Try again: ");
                break;
            }
        }
    } else if (axis == 1) { // Vertically aligned ships
        for (int i = 0; i < size; i++) {
            if (row + size >= 11 ) {
                printf("Ship placement out of bounds! Try again: \n");
                break;
            }
            if (playingGrid[row + i][col] == '~') {
                playingGrid[row + i][col] = type;
                if (i == size - 1) {
                    return true;
                }
            } else {
                printf("Grid position is occupied! Try again: \n");
                break;
            }
        }
    }
    return false;
}

//updates the grid with markers for hits and misses of either player or bot
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

void attack(const int cood, struct Player player) {
    int row = (cood / 10);
    int col = (cood % 10);

    //changes 0s to 10s
    if (row == 0) {
        row = 10;
    }
    if (col == 0) {
        col = 10;
    }


    switch (player.playingGrid[row][col]) {
        case '~':
            gridUpdate(cood, 'O', player.trackingGrid);
            printf("You missed :(\n");
            break;
        case 'C':
            gridUpdate(cood, 'X', player.trackingGrid);
            gridUpdate(cood, 'X', player.playingGrid);
            printf("You hit enemy carrier!\n");
            player.carrier.size -= 1;
            if (carrierHp == 0) {
                printf("Enemy carrier has been sunk!\n");
            }
            break;
        case 'B':
            gridUpdate(cood, 'X', player.trackingGrid);
            gridUpdate(cood, 'X', player.playingGrid);
            printf("You hit enemy Battleship!\n");
            player.battleship.size -= 1;
            if (battleshipHp == 0) {
                printf("Enemy battleship has been sunk!\n");
            }
            break;
        case 'D':
            gridUpdate(cood, 'X', player.trackingGrid);
            gridUpdate(cood, 'X', player.playingGrid);
            printf("You hit enemy Destroyer!\n");
            player.destroyer.size -= 1;
            if (destroyerHp == 0) {
                printf("Enemy destroyer has been sunk!\n");
            }
            break;
        case 'S':
            gridUpdate(cood, 'X', player.trackingGrid);
            gridUpdate(cood, 'X', player.playingGrid);
            printf("You hit enemy Submarine!\n");
            player.submarine.size -= 1;
            if (submarineHp == 0) {
                printf("Enemy submarine has been sunk!\n");
            }
            break;
        case 'P':
            gridUpdate(cood, 'X', player.trackingGrid);
            gridUpdate(cood, 'X', player.playingGrid);
            printf("You hit enemy Patrol Boat!\n");
            player.patrolBoat.size -= 1;
            if (patrolBoatHp == 0) {
                printf("Enemy patrol boat has been sunk!\n");
            }
            break;
        default:
            printf("you're not even supposed to get here twin what the fuck did you break :(");
    }
}
