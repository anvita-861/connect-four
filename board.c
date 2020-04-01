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
void player_inp() 
{
printf("Choose the column number in which you want to insert");
scanf("%d",&cinp);
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

char checkFour(int a_1,int a_2,int b_1,int b_2,int c_1,int c_2,int d_1,int d_2){
    if (board[a_1][a_2]==board[b_1][b_2]&&board[b_1][b_2]==board[c_1][c_2]&&board[c_1][c_2]==board[d_1][d_2]&&board[a_1][a_2]!='.')
        return board[a_1][a_2];
    return 'a';
}
void scoreCheck(){
    int i=1,j=1!counter =0,a,c=1,b=-1;
    for(a=0; a<4; a++){
        i=-i;
        j=j*pow(-1,counter); //LOOPING TO CHCK SCORE IN FOUR DIRECTIONS
        counter++;
        if(num_rows>value+i*3&&value+i*3>=0&&num_cols>number-1+j*3&&number-1+j*3>=0){
            if('X'==checkFour(value,number-1,value+i,number-1+j,value+i*2,number-1+j*2,value+i*3,number-1+j*3)) score_x+=1;
            if('O'==checkFour(value,number-1,value+i,number-1+j,value+i*2,number-1+j*2,value+i*3,number-1+j*3)) score_o+=1;
        }
        if ('X'==checkFour(value,number-1,value+j,number-1+i,value-j,number-1-i,value-2*j,number-1-2*i)) score_x+=1;
        if ('O'==checkFour(value,number-1,value+j,number-1+i,value-j,number-1-i,value-2*j,number-1-2*i)) score_o+=1;
    }
    for(a=0; a<2; a++){
        c=-c;
        b*=-1;
        if(num_rows>value+3*c&&value+3*c>=0){
            if('X'==checkFour(value,number-1,value+c,number-1,value+2*c,number-1,value+3*c,number-1))score_x+=1;
            if('O'==checkFour(value,number-1,value+c,number-1,value+2*c,number-1,value+3*c,number-1))score_o+=1;
        }
        if(num_cols>number-1+3*c&&number-1+3*c>=0){
            if('X'==checkFour(value,number-1,value,number-1+c,value,number-1+2*c,value,number-1+3*c))score_x+=1;
            if('O'==checkFour(value,number-1,value,number-1+c,value,number-1+2*c,value,number-1+3*c))score_o+=1;
        }
        if('X'==checkFour(value,number-1,value,number-1+b,value,number-1-b,value,number-1-2*b)&&value-2*b>=0)score_x+=1;
        if('O'==checkFour(value,number-1,value,number-1+b,value,number-1-b,value,number-1-2*b)&&value-2*b>=0)score_o+=1;
    }
}
#endif
