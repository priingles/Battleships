//
// Created by kleoa on 19/03/2025.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Globals.h"

int menu() {

    system("cls");
    char menu[300];
    snprintf(menu, sizeof(menu), "Blah blah\n"
        "1. New Game\n"
        "2. Load Game\n"
        "3. Replays\n"
        "4. Rules\n"
        ". Exit\n");

    printf("%s", menu);
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = '\0';

    int choice = atoi(input);

    switch (choice) {
        case 1:
            gameSetup();
            gameLoop(mainPlayer, bot);
        break;
        case 2:
            load();
        break;
        case 4:
            rules();
        break;
        default:
            printf("Invalid choice\n");
            break;
    }
    return 0;

}

void rules() {
    char rules[300];

    snprintf(rules, sizeof(rules), "Blah blah\n"
    "You have 5 ship types you can set up on the grid, either horizontally or vertically\n"
    "Ships cannot overlap or be positioned outside of the grid.\n"
    "{351} 3 being row, 5 being column and 1 being vertical(0-horizontal)\n"
    "On the grid a Carrier is represented as a 5, Battleships are 4s, Destroyers 3, Submarines 2 and Patrol boats 1\n"
    "\nCOORDINATES\n");

    printf("%s", rules);
}
