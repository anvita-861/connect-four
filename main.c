// Connect four
#include <stdio.h>

void print_board_big() {
    int r=6, c=7;
    printf("\n");
    for (int i=0; i<r; ++i) {
        for (int j=0; j<c; ++j) {
            printf("|     ");
        }
        printf("|\n");
        for (int j=0; j<c; ++j) {
            printf("|  0  ");
        }
        printf("|\n");
        for (int j=0; j<c; ++j) {
            printf("|_____");
        }
        printf("|\n");
    }
    printf("\n");
}


void print_board() {
    int r=6, c=7;
    printf("\n");
    for (int i=0; i<r; ++i) {
        for (int j=0; j<c; ++j) {
            printf(" 0 ");
        }
        printf("\n");
    }
    printf("\n");
}

int main() {
    print_board();
    return 0;
}