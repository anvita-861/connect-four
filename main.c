// Connect four
#include <stdio.h>
#include <stdlib.h>

#include "board.h"


int main() {
    init_board();
    print_board();
    player_inp();
    check();
    print_ele();
    return 0;
}
