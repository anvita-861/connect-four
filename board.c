#ifndef BOARD_C
#define BOARD_C


#include "board.h"

#include <stdio.h>
#include <stdlib.h>


const int ROWS=6, COLUMNS=7;
char BOARD[ROWS][COLUMNS];

int IN_GAME = 1;

// To check if game in play
int game() {
    return IN_GAME;
}

// To clear screen
void clear() {
    #if defined(__linux__) || defined(__unix__) || defined(__APPLE__)
        system("clear");
    #endif

    #if defined(_WIN32) || defined(_WIN64)
        system("cls");
    #endif
}

// Reset the board to empty
void reset_board() {
    for (int i=0; i<ROWS; ++i) {
        for (int j=0; j<COLUMNS; ++j) {
            // ' ' represents empty
            BOARD[i][j] = ' ';
        }
    }

}

// Print the board
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

// Returns input validity
int inp_validity(int number) {
    if (number < 1 || number > COLUMNS) {
        return col_oob;
    }

    if (BOARD[0][number-1] != ' ') {
        return col_full;
    }     

    return valid;
}


// To accept player input
void player_inp(int p)  {
    int number;
    printf("Player #%d:\n", p);
    printf("Enter column number: ");
    scanf("%d", &number);

    int v;

    // Check validity of input
    while ((v = inp_validity(number)) != valid) {

        print_board();
        printf("Player #%d:\n", p);
        switch (v) {
            // Column entered is out of bounds
            case col_oob: {
                printf("Input out of bounds.\n");
                break;
            }

            // Column entered is full
            case col_full: {
                printf("Column full.\n");
                
                break;
            }

        }

        // Re-input
        printf("Enter column number: ");
        scanf("%d", &number);
        
    }


    update(p, number);

}

// Returns the first empty row of the column (not index)
int empty_row(int number) {
    for (int i=ROWS-1; i>=0; --i) {
        if (BOARD[i][number-1] == ' ') 
            return i;
    }
    return -1;
}


void update(int p, int number) {
    // Player 1 = O
    if (p == 1) {
        BOARD[empty_row(number)][number-1] = 'O';
    }
    // Player 2 = X
    else {
        BOARD[empty_row(number)][number-1] = 'X';
    }

}

// Check for 4
void check() {

    // Vertical lines of 4
    for (int i=ROWS-1; i>=3; --i) {
        for (int j=0; j<COLUMNS; ++j) {
            if (BOARD[i][j] == ' ') {
                continue;

            }

            if (BOARD[i][j] == BOARD[i-1][j] && 
            BOARD[i-1][j] == BOARD[i-2][j] && 
            BOARD[i-2][j] == BOARD[i-3][j]) {

                IN_GAME = 0;

                if (BOARD[i][j] == 'O') {
                    printf("Player 1 wins!!\n");
                }
                else {
                    printf("Player 2 wins!!\n");
                }
                return;
            }

        }
    } // End of vertical

    // Horizontal lines of 4
    for (int j=COLUMNS-1; j>=3; --j) {
        for (int i=0; i<ROWS; ++i) {
            if (BOARD[i][j] == ' ') {
                continue;

            }

            if (BOARD[i][j] == BOARD[i][j-1] && 
            BOARD[i][j-1] == BOARD[i][j-2] && 
            BOARD[i][j-2] == BOARD[i][j-3]) {

                IN_GAME = 0;

                if (BOARD[i][j] == 'O') {
                    printf("Player 1 wins!!\n");
                }
                else {
                    printf("Player 2 wins!!\n");
                }
                return;
            }

        }
    } // End of horizontal

    // Main diagonal lines of 4
    for (int i=0; i<=ROWS-4; ++i) {
        for (int j=0; j<=COLUMNS-4; ++j) {
            if (BOARD[i][j] == ' ') {
                continue;

            }

            if (BOARD[i][j] == BOARD[i+1][j+1] && 
            BOARD[i+1][j+1] == BOARD[i+2][j+2] && 
            BOARD[i+2][j+2] == BOARD[i+3][j+3]) {

                IN_GAME = 0;

                if (BOARD[i][j] == 'O') {
                    printf("Player 1 wins!!\n");
                }
                else {
                    printf("Player 2 wins!!\n");
                }
                return;
            }

        }
    } // End of main diagonal

    // Secondary diagonal lines of 4
    for (int i=0; i<=ROWS-4; ++i) {
        for (int j=COLUMNS-1; j>=3; --j) {
            if (BOARD[i][j] == ' ') {
                continue;

            }

            if (BOARD[i][j] == BOARD[i+1][j-1] && 
            BOARD[i+1][j-1] == BOARD[i+2][j-2] && 
            BOARD[i+2][j-2] == BOARD[i+3][j-3]) {

                IN_GAME = 0;

                if (BOARD[i][j] == 'O') {
                    printf("Player 1 wins!!\n");
                }
                else {
                    printf("Player 2 wins!!\n");
                }
                return;
            }

        }
    } // End of secondary diagonal


}


#endif