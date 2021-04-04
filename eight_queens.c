#include <stdio.h>

#define SIZE 8
#define EMPTY ' '
#define QUEEN 'Q'
#define ATTACKED  '*'

void clearBoard(char board[SIZE][SIZE]){
    int i, j;
    for(i = 0; i < SIZE; i++){
        for(j = 0; j < SIZE; j++){
            board[i][j] = EMPTY;
        }
    }
}


//If you want to print the board
/*
void printBoard(char board[SIZE][SIZE]){
    int i, j;
    for(i = 0; i < SIZE; i++){
        for(j = 0; j < SIZE; j++){
            printf("[%c]",board[i][j]);
        }
        printf("\n");
    }

    printf("\n");
}
*/

void positionQueen(char board[SIZE][SIZE], int row, int column){
    int i, j, init; 
    
    /* init is the position of the first element 
    in the diagonal of the queen*/

    if(row <= column){
        init = column - row;
        for(i = 0 ; i < SIZE - init ; i++){
            board[i][i + init] = ATTACKED;
        }
    }
    else{
        init = row - column;
        for(i = 0; i < SIZE - init; i++){
            board[init + i][i] = ATTACKED;
        }

    }
    if(row + column > SIZE - 1 ){
        init = column + row - SIZE + 1;
        for(i = 0; i < SIZE - init; i++){
            board[SIZE - 1 - i][init + i] = ATTACKED;
        }
    }
    else{
        init = column + row ;
        for(i = 0; i < init + 1; i++){
            board[init - i][i] = ATTACKED;
        }
    }
    for(i = 0;i < SIZE; i++){
        board[row][i] = ATTACKED;
        board[i][column] = ATTACKED;
    }
    board[row][column] = QUEEN;
}

int countQueens(char board[SIZE][SIZE],int* count_queens){
    int row, column;
    for(row = 0; row < SIZE; row++){
        for(column = 0; column < SIZE; column++){
            if(board[row][column] == QUEEN){
                (*count_queens)++;
            }
        }
    } 
}

void getSolutions(int len, int index[SIZE], int* count_solutions){
    int i, row, column, temp, count_queens = 0;
    char board[SIZE][SIZE];
    clearBoard(board);
    if(len == 1){
        for(i = 0; i < SIZE; i++){
            row = i;
            column = index[i];
            positionQueen(board, row, column);
        }
        countQueens(board,&count_queens);
        if(count_queens == SIZE){
            (*count_solutions)++;
        //    printBoard(board);
        }
    }
    else{
        for(i = 0; i < len ; i++){
            getSolutions(len - 1, index, count_solutions);
            if(len % 2 == 1){
                temp = index[i];
                index[i] =  index[len -1];
                index[len - 1] = temp;
            }
            else{
                temp = index[0];
                index[0] =  index[len -1];
                index[len - 1] = temp;
            }
        }            
    }
}


int main(void){
    int i, solutions = 0, len = SIZE;
    int index[SIZE];
    for(i = 0; i < SIZE; i++){
        index[i] = i;
    }
    getSolutions(len, index, &solutions);
    printf("Numero de soluciones: %i",solutions);
    return 0;
}