#include <stdio.h>
#include <string.h>

#include "Globals.h"
#include "Header.h"

char msg1[100];
char msg2[100];
char msg3[100];
char msg4[100];
char msg5[100];
char msg6[100];
char msg7[100];
char msg8[100];
char msg9[100];
char msg10[100];

int display() {
    clear_terminal();

    printf("%s\n", hdr);
    printf("%s\n", hdr_txt);

    // fka displayGrids
    printf("\n");
    for (int i = 0; i < 11; i++) {
        // PLAYING GRID
        for (int j = 0; j < 11; j++) {
            printf("%c ", mainPlayer.playingGrid[i][j]);
        }
        printf("        ");
        // TRACKING GRID
        for (int j = 0; j < 11; j++) {
            printf("%c ", mainPlayer.trackingGrid[i][j]);
        }

        // INFO LOG MESSAGES
        switch (i) {
            case 0:
                printf("        ");
                printf("INFO LOG.");
                break;
            case 1:
                printf("        ");
                printf("%s", msg10);
                break;
            case 2:
                printf("        ");
                printf("%s", msg9);
                break;
            case 3:
                printf("        ");
                printf("%s", msg8);
                break;
            case 4:
                printf("        ");
                printf("%s", msg7);
                break;
            case 5:
                printf("        ");
                printf("%s", msg6);
                break;
            case 6:
                printf("        ");
                printf("%s", msg5);
                break;
            case 7:
                printf("        ");
                printf("%s", msg4);
                break;
            case 8:
                printf("        ");
                printf("%s", msg3);
                break;
            case 9:
                printf("        ");
                printf("%s", msg2);
                break;
            case 10:
                printf("        ");
                printf("%s", msg1);
                break;
            default: // default cuz Clion won't give me the checkmark without it :(
                break;
        }
        printf("\n");
    }
    printf("\n");
    return 0;
}

void info_msg(char msg[100]) {
    strcpy(msg10, msg9);
    strcpy(msg9, msg8);
    strcpy(msg8, msg7);
    strcpy(msg7, msg6);
    strcpy(msg6, msg5);
    strcpy(msg5, msg4);
    strcpy(msg4, msg3);
    strcpy(msg3, msg2);
    strcpy(msg2, msg1);
    strcpy(msg1, msg);
}

void setHdr_txt(char msg[500]) {
    strcpy(hdr_txt, msg);
}
