#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 10
#define EMPTY ' '

enum Direction{UP, RIGHT, DOWN, LEFT};

void emptyGrid(char grid[SIZE][SIZE]){
    int i, j; 
    for(i = 0; i < SIZE; i++){
        for(j = 0; j < SIZE; j++){
            grid[i][j] = EMPTY;
        }
    }
}
void alphabetSnake(char grid[SIZE][SIZE]){
    int flag = 0,count, direction;
    char letter = 'A';
    srand(time(NULL));
    int row = rand() % 10;
    int column = rand() % 10;
    grid[row][column] = letter;

    while(flag == 0){
        direction = rand() % 4;
        count = 0;
        while(count < 4 && flag == 0){
            if(direction == UP){
                if(0 < row && grid[row - 1][column] == EMPTY){
                    row--;
                    flag = 1; //empty space found
                    break;
                }
                else{
                    count++;
                    direction = (direction + 1) % 4;
                }
            }
            if(direction == RIGHT){
                if(column < 9 && grid[row][column + 1] == EMPTY){
                    column++;
                    flag = 1;
                    break;
                }
                else{
                    count++;
                    direction = (direction + 1) % 4;
                }
            }
            if(direction == DOWN){
                if(row < 9 && grid[row + 1][column] == ' '){
                    row++;
                    flag = 1;
                    break;
                }
                else{
                    count ++;
                    direction = (direction + 1) % 4;
                }
            }
            if(direction == LEFT){
                if(0 < column && grid[row][column - 1] == ' '){
                    column--;
                    flag = 1;
                    break;
                }
                else{
                    count++;
                    direction = (direction + 1) % 4;
                }
            }
        }
        if(flag == 1){ //empty space filled
            letter++;
            grid[row][column] = letter;
            flag = 0; //The loop must continue
        }
        else{
            flag = 1;
        }
        if(letter == 'Z'){
            break;
        }
    }
}
void printGrid(char grid[SIZE][SIZE]){
    int row, column;
    for(row = 0; row < SIZE; row++){
        for(column = 0; column < SIZE; column++){
            printf("[%c]",grid[row][column]);
        } 
        printf("\n");
    }
}

int main(void){
    char grid[SIZE][SIZE];
    emptyGrid(grid);
    alphabetSnake(grid);
    printGrid(grid);
    return 0;
}