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
int number
printf("Choose the column number in which you want to insert");
scanf("%s",&number);
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

void empty()
{
   for(int i=ROWS;i>-1;i--)
    {
        
        if(BOARD[i+1][cinp-1]==' ')
        {
            if(j%2==0)
            BOARD[i+1][cinp-1]=c;
            else
            BOARD[i+1][cinp-1]=c;
        
         break;
        } 
    }
}

void print_ele()
{
    for(int j=0;j<ROWS*COLUMNS;j++)
    {
            if(j%2==0)
            c='X';
            else
            c='O';
            
             empty();
             print_board();
         player_inp();
    }
  
}

char checkFour(int a_1,int a_2,int b_1,int b_2,int c_1,int c_2,int d_1,int d_2){
    if (BOARD[a_1][a_2]==BOARD[b_1][b_2]&&BOARD[b_1][b_2]==BOARD[c_1][c_2]&&BOARD[c_1][c_2]==BOARD[d_1][d_2]&&BOARD[a_1][a_2]!='.')
        return BOARD[a_1][a_2];
    return 'a';
}
void check(){
    int i=1,j=1!counter =0,a,c=1,b=-1, score_x, score_o;
    for(a=0; a<4; a++){
        i=-i;
        j=j*pow(-1,counter); //LOOPING TO CHCK SCORE IN FOUR DIRECTIONS
        counter++;
        if(ROWS>value+i*3&&value+i*3>=0&&COLUMNS>number-1+j*3&&number-1+j*3>=0){
            if('X'==checkFour(value,number-1,value+i,number-1+j,value+i*2,number-1+j*2,value+i*3,number-1+j*3)) score_x+=1;
            if('O'==checkFour(value,number-1,value+i,number-1+j,value+i*2,number-1+j*2,value+i*3,number-1+j*3)) score_o+=1;
        }
        if ('X'==checkFour(value,number-1,value+j,number-1+i,value-j,number-1-i,value-2*j,number-1-2*i)) score_x+=1;
        if ('O'==checkFour(value,number-1,value+j,number-1+i,value-j,number-1-i,value-2*j,number-1-2*i)) score_o+=1;
    }
    for(a=0; a<2; a++){
        c=-c;
        b*=-1;
        if(ROWS>value+3*c&&value+3*c>=0){
            if('X'==checkFour(value,number-1,value+c,number-1,value+2*c,number-1,value+3*c,number-1))score_x+=1;
            if('O'==checkFour(value,number-1,value+c,number-1,value+2*c,number-1,value+3*c,number-1))score_o+=1;
        }
        if(COLUMNS>number-1+3*c&&number-1+3*c>=0){
            if('X'==checkFour(value,number-1,value,number-1+c,value,number-1+2*c,value,number-1+3*c))score_x+=1;
            if('O'==checkFour(value,number-1,value,number-1+c,value,number-1+2*c,value,number-1+3*c))score_o+=1;
        }
        if('X'==checkFour(value,number-1,value,number-1+b,value,number-1-b,value,number-1-2*b)&&value-2*b>=0)score_x+=1;
        if('O'==checkFour(value,number-1,value,number-1+b,value,number-1-b,value,number-1-2*b)&&value-2*b>=0)score_o+=1;
    }
}
#endif
