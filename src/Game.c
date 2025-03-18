#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include "Header.h"
#include "Globals.h"


int difficulty;


int gameSetup() {
    clear_terminal();

    printf("Enter player name: ");
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = '\0'; //removes newline from fgets

    mainPlayer = createPlayer(input);
    bot = createPlayer("Bot");

    clear_terminal();

    gridSetup(&mainPlayer);
    initGrid(&bot);
    botGridSetup(&bot);
    display();
    printf("Choose bot difficulty(1-5) [doesnt matter rn]: ");
    fgets(input, sizeof(input), stdin);
    difficulty = strtol(input, &endptr, 10);
    clear_terminal();

    return 0;
}

int gameLoop() {
    printf(
        "Attack coordinates are similar to set-up coordinates, they make use of 2digit numbers as an axis is not required\n\n");

    while (true) {
        //turns and playing
        if (turn % 2 == PLAYER_TURN) {
            int attackCood = 0;
            printf("\nIt's your turn\nEnter attack coordinates: \n");
            while (!validMove) {
                fgets(input, sizeof(input), stdin);
                attackCood = strtol(input, &endptr, 10);
                validMove = attack(attackCood, &mainPlayer, &bot);
            }

            validMove = false;
            //win condition
            if (mainPlayer.carrier.size == 0 && mainPlayer.battleship.size == 0 && mainPlayer.destroyer.size == 0 &&
                mainPlayer.submarine.size == 0 && mainPlayer.patrolBoat.size == 0) {
                printf("You lose. You have no ships left\n\n");
                break;
            }
        } else {
            printf("Bot is playing...\n\n");
            Sleep(1500);
            botPlay(&bot, &mainPlayer);
            display();
            //loss condition
            if (bot.carrier.size == 0 && bot.battleship.size == 0 && bot.destroyer.size == 0 && bot.submarine.size == 0
                && bot.patrolBoat.size == 0) {
                printf("You lose. You have no ships left\n\n");
                break;
            }
        }
        turn++;
    }
    return 0;
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

        if (turn % 2 == PLAYER_TURN) {
            char message[100];
            sprintf(message, "You attacked %d", cood);
            info_msg(message);
        }

        switch (target->playingGrid[row][col]) {
            case '~':
                if (att->trackingGrid[row][col] == 'O') {
                    printf("This coordinate has already been targeted. try again: \n");
                    return false;
                }
                gridUpdate(cood, 'O', att->trackingGrid);
                display();
                if (turn % 2 == PLAYER_TURN) {
                    info_msg("you missed");
                    display();
                } else {
                    printf("%s missed\n", att->name);
                }
                return true;
            case 'C':
                gridUpdate(cood, 'X', att->trackingGrid);
                gridUpdate(cood, 'X', target->playingGrid);
                if (turn % 2 == PLAYER_TURN) {
                    info_msg("You hit enemy carrier!");
                } else {
                    info_msg("Your carrier has been hit!");
                }
                target->carrier.size -= 1;
                if (target->carrier.size == 0) {
                    if (turn % 2 == PLAYER_TURN) {
                        info_msg("You sunk enemy carrier!");
                    } else {
                        info_msg("Your carrier has been sunk");
                    }
                }
                return true;
            case 'B':
                gridUpdate(cood, 'X', att->trackingGrid);
                gridUpdate(cood, 'X', target->playingGrid);
                if (turn % 2 == PLAYER_TURN) {
                    info_msg("You hit enemy battleship!");
                } else {
                    info_msg("Your battleship has been hit!");
                }
                target->battleship.size -= 1;
                if (target->battleship.size == 0) {
                    if (turn % 2 == PLAYER_TURN) {
                        info_msg("You sunk enemy battleship!");
                    } else {
                        info_msg("Your battleship has been sunk");
                    }
                }
                return true;
            default:
                printf("you're not even supposed to get here twin what the fuck did you break :(");
        }
    }
    return false;
}
