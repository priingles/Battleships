#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

#include "header.h"
#include "globals.h"


int difficulty;
Player player1;
Player bot;

int gameSetup() {
    clear_terminal();

    printf("Enter player name: ");
    fgets(input, sizeof(player1.name), stdin);
    input[strcspn(player1.name, "\n")] = '\0'; //removes newline from fgets

    player1 = createPlayer(input);
    bot = createPlayer("bot");

    clear_terminal();

    initGrid(&player1); // initialises player playing&trackingGrid
    // gridSetup(&player1);
    initGrid(&bot);
    //gridSetup(&bot);
    displayGrid(player1.playingGrid, player1.trackingGrid);
    printf("Choose bot difficulty(1-5) [doesnt matter rn]: ");
    fgets(input, sizeof(input), stdin);
    difficulty = strtol(input, &endptr, 10);
    clear_terminal();

    return 0;
}

int gameLoop() {
    printf("Attack coordinates are similar to set-up coordinates, they make use of 2digit numbers as an axis is not required\n\n");

    while (true) {
        //Turns and playing
        if (turn % 2 == 1) {
            printf("It's your turn\nEnter attack coordinates: \n");
            while (!validMove) {
                fgets(input, sizeof(input), stdin);
                const int attackCood = strtol(input, &endptr, 10);
                validMove = attack(attackCood, &player1, &bot);
            }
            displayGrid(player1.playingGrid, player1.trackingGrid);
            validMove = false;
        } else {
            printf("Bot is playing...\n\n");
            Sleep(1500);
            botPlay(&bot, &player1);
        }


        turn++;
    }
}

bool attack(const int cood, Player *att, Player *target) {
    if (target == NULL) {
        printf("player is null");
    } else {
        int row = (cood / 10);
        int col = (cood % 10);

        //changes 0s to 10s
        if (row == 0) {
            row = 10;
        }
        if (col == 0) {
            col = 10;
        }


        switch (target->playingGrid[row][col]) {
            case '~':
                if (att->trackingGrid[row][col] == 'O') {
                    printf("This coordinate has already been targeted. try again: \n");
                    return false;
                }
                gridUpdate(cood, 'O', att->trackingGrid);
                displayGrid(player1.playingGrid, player1.trackingGrid);
            if (turn % 2 == 1) {
                printf("you missed");
            }else {
                printf("%s missed\n", att->name);
            }

                return true;
            case 'C':
                gridUpdate(cood, 'X', att->trackingGrid);
                gridUpdate(cood, 'X', target->playingGrid);
                printf("%s carrier has been HIT!\n", target->name);
                target->carrier.size -= 1;
                if (target->carrier.size == 0) {
                    printf("%s carrier has been sunk!\n", target->name);
                }
                return true;
            case 'B':
                gridUpdate(cood, 'X', att->trackingGrid);
                gridUpdate(cood, 'X', target->playingGrid);
                printf("Enemy battleship HIT!\n");
                target->battleship.size -= 1;
                if (target->battleship.size == 0) {
                    printf("Enemy battleship has been sunk!\n");
                }
                return true;
            case 'D':
                gridUpdate(cood, 'X', att->trackingGrid);
                gridUpdate(cood, 'X', target->playingGrid);
                printf("Enemy destroyer HIT!\n");
                target->destroyer.size -= 1;
                if (target->destroyer.size == 0) {
                    printf("Enemy destroyer has been sunk!\n");
                }
                return true;
            case 'S':
                gridUpdate(cood, 'X', att->trackingGrid);
                gridUpdate(cood, 'X', target->playingGrid);
                printf("Enemy submarine HIT!!\n");
                target->submarine.size -= 1;
                if (target->submarine.size == 0) {
                    printf("Enemy submarine has been sunk!\n");
                }
                return true;
            case 'P':
                gridUpdate(cood, 'X', att->trackingGrid);
                gridUpdate(cood, 'X', target->playingGrid);
                printf("Enemy patrol boat HIT!\n");
                target->patrolBoat.size -= 1;
                if (target->patrolBoat.size == 0) {
                    printf("Enemy patrol boat has been sunk!\n");
                }
                return true;
            case 'X':
                printf("This coordinate has already been targeted\n");
                return false;
            default:
                printf("you're not even supposed to get here twin what the fuck did you break :(");
        }
    }
    return false;
}
