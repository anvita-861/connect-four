#ifndef BOARD_C
#define BOARD_C


#include "board.h"

#include <stdio.h>
#include <stdlib.h>


const int ROWS=6, COLUMNS=7;
char BOARD[ROWS][COLUMNS];

void clear() {
    #if defined(__linux__) || defined(__unix__) || defined(__APPLE__)
        system("clear");
    #endif

    #if defined(_WIN32) || defined(_WIN64)
        system("cls");
    #endif
}


void init_board() {
    for (int i=0; i<ROWS; ++i) {
        for (int j=0; j<COLUMNS; ++j) {
            BOARD[i][j] = '0';
        }
    }

}

void print_board() {
    clear();
    printf("\n ");

    // Co-ordinates
    for (int j=0; j<COLUMNS; ++j) {
            printf("  %d   ", j+1);
    }

    printf("\n\n");

    for (int i=0; i<ROWS; ++i) {

        for (int j=0; j<COLUMNS; ++j) {
            printf("|     ");
        }
        printf("|\n");

        // TODO: change 0 to value
        for (int j=0; j<COLUMNS; ++j) {
            printf("|  %c  ", BOARD[i][j]);
        }
        printf("|\n");

        for (int j=0; j<COLUMNS; ++j) {
            printf("|_____");
        }
        printf("|\n");
    }
    printf("\n");
}

#endif