#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "header.h"


char input2[100];
char* endptr2;

int difficulty;
Player player1;
Player bot;

int gameSetup(){

    // Creates a player and sets up ships on user-defined coordinates
    clear_terminal();
    printf("Enter player name: ");
    fgets(player1.name, sizeof(player1.name), stdin);
    player1.name[strcspn(player1.name, "\n")] = '\0'; //removes newline from fgets
    clear_terminal();

    initGrid(&player1);// initialises player playing&trackingGrid
    //gridSetup(&player1);
    initGrid(&bot);
    //gridSetup(&bot);
    displayGrid(player1.playingGrid, player1.trackingGrid);
    printf("Choose bot difficulty(1-5) [doesnt matter rn]: ");
    fgets(input2, sizeof(input2), stdin);
    difficulty = strtol(input2, &endptr2, 10);
    clear_terminal();

    return 0;
}

int gameStart(){

}
int gameLoop(){

    printf("Attack coordinates are similar to set-up coordinates, they make use of 2digit numbers as an axis is not required\n\n");

    int turn = 1;
    while(true) {
        //Turns and playing
        if (turn % 2 == 1) {
            printf("It's your turn\nEnter attack coordinates: \n");
            fgets(input2, sizeof(input2), stdin);
            const int attackCood = strtol(input2, &endptr2, 10);
            attack(attackCood, &player1,&bot);
            displayGrid(player1.playingGrid, player1.trackingGrid);
        }else {
            printf("Bots playing...\n");
            botPlay(&bot, &player1);
        }


    turn++;
    }

}

void attack(const int cood, Player *attacker, Player *target) {

    if (attacker == NULL) {
        printf("player is null");
    }
    int row = (cood / 10);
    int col = (cood % 10);

    //changes 0s to 10s
    if (row == 0) {
        row = 10;
    }
    if (col == 0) {
        col = 10;
    }


    switch (attacker->playingGrid[row][col]) {
        case '~':
            gridUpdate(cood, 'O', attacker->trackingGrid);
            displayGrid(player1.playingGrid, player1.trackingGrid);
            printf("You missed :(\n");
            break;
        case 'C':
            gridUpdate(cood, 'X', attacker->trackingGrid);
            gridUpdate(cood, 'X', target->playingGrid);
            printf("You hit enemy carrier!\n");
            attacker->carrier.size -= 1;
            if (attacker->carrier.size == 0) {
                printf("Enemy carrier has been sunk!\n");
            }
            break;
        case 'B':
            gridUpdate(cood, 'X', attacker->trackingGrid);
            gridUpdate(cood, 'X', target->playingGrid);
            printf("You hit enemy Battleship!\n");
            attacker->battleship.size -= 1;
            if (attacker->battleship.size == 0) {
                printf("Enemy battleship has been sunk!\n");
            }
            break;
        case 'D':
            gridUpdate(cood, 'X', attacker->trackingGrid);
            gridUpdate(cood, 'X', target->playingGrid);
            printf("You hit enemy Destroyer!\n");
            attacker->destroyer.size -= 1;
            if (attacker->destroyer.size == 0) {
                printf("Enemy destroyer has been sunk!\n");
            }
            break;
        case 'S':
            gridUpdate(cood, 'X', attacker->trackingGrid);
            gridUpdate(cood, 'X', target->playingGrid);
            printf("You hit enemy Submarine!\n");
            attacker->submarine.size -= 1;
            if (attacker->submarine.size== 0) {
                printf("Enemy submarine has been sunk!\n");
            }
            break;
        case 'P':
            gridUpdate(cood, 'X', attacker->trackingGrid);
            gridUpdate(cood, 'X', target->playingGrid);
            printf("You hit enemy Patrol Boat!\n");
            attacker->patrolBoat.size -= 1;
            if (attacker->patrolBoat.size == 0) {
                printf("Enemy patrol boat has been sunk!\n");
            }
            break;
        case 'X':
            case 'O':
                printf("This coordinate has already been targeted\n");
                break;
        default:
            printf("you're not even supposed to get here twin what the fuck did you break :(");
    }
}
