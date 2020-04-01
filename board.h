#ifndef BOARD_H
#define BOARD_H

#include <stdio.h>
#include <stdlib.h>

const int ROWS=6, COLUMNS=7;

char BOARD[ROWS][COLUMNS];

void clear();
void init_board();
void print_board();

#endif