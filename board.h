#ifndef BOARD_H
#define BOARD_H

#include <stdio.h>
#include <stdlib.h>

enum validity {
    col_full,
    col_oob,
    valid
};


void clear();               // Clears screen
int inp_validity(int);      // Checks validity of input
void update(int, int);      // Updates board square to O or X
int empty_row(int);         // Returns the first empty row
void player_inp(int);       // Accepts player input
void reset_board();         // Resets board to empty
void print_board();         // Prints the board

void check();               // Checks for 4
int game();                 // Returns if game is still in play

#endif
