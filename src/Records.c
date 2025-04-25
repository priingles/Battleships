#include <stdio.h>
#include <stdlib.h>

#include "Globals.h"
#include "Header.h"


int save() {
    const GameState game = {mainPlayer, bot};
    FILE *file = fopen("lastGame.bin", "wb");
    if (file == NULL) {
        perror("Error opening file\n");
    }
    fwrite(&game, sizeof(game), 1, file);
    fclose(file);
    return 0;
}

int load() {
    GameState gameState;
    FILE *file = fopen("lastGame.bin", "rb");
    fread(&gameState, sizeof(gameState), 1, file);
    fclose(file);
    gameLoop(gameState.player, gameState.bot);

    return 0;
}

int recordMove(GameState *gameState) {
    GameStateNode *newNode = (GameStateNode *) malloc(sizeof(GameStateNode));

    // Node traversal
    newNode->gameState = gameState;
    newNode->prev = current;
    newNode->next = NULL;

    if (current != NULL) {
        current->next = newNode;
    }

    current = newNode;
    return 0;
}

int undo() {
    if (current != NULL && current->next != NULL) {
        gameState = *current->prev->gameState;
    } else {
        printf("Undo failed\nNo previous game state\n");
    }
    display();
    return 0;
}

int redo() {
    if (current != NULL && current->next != NULL) {
        gameState = *current->next->gameState;
    }
    else {
        printf("Redo failed\nNo more game states\n");
    }
    return 0;
}
