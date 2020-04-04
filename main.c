// Connect four
#include <stdio.h>
#include <stdlib.h>

#include "board.h"


int main() {
    reset_board();
    print_board();

    int player = 1;

    do {

        // Input coordinates of player
        player_inp(player);
        print_board();
        check();

        // Switch between players
        if (player == 1) {
            player = 2;
        }
        else {
            player = 1;
        }


    } while (game());

    

    return 0;
}
