// Connect four
#include <stdio.h>
#include <stdlib.h>

#include "board.h"



void print_board_small() {
    //int r=6, c=7;
    printf("\n");
    for (int i=0; i<ROWS; ++i) {
        for (int j=0; j<COLUMNS; ++j) {
            printf(" 0 ");
        }
        printf("\n");
    }
    printf("\n");
}

int main() {
    init_board();
    print_board();
    return 0;
}