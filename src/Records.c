#include <stdio.h>

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

int recordMove() {
    const GameState gameState = {mainPlayer, bot};
    FILE *file = fopen("moves.bin", "wb");
    if (file == NULL) {
        perror("Error opening file\n");
    }
    fwrite(&gameState, sizeof(gameState), 1, file);
    fclose(file);
    return 0;
}

// int undo() {
//     struct gameStateNode *current = get_current();
//     if (current && current->next) {
//
//     }
//     return 0;
// }