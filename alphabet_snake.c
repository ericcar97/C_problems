#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 10

int main(void){

    /* filling the matrix with empty cells */
    char grid[SIZE][SIZE], c;
    int i, j, l, m;
    int dir, count, flag = 0;
    for(i = 0; i < SIZE; i++){
        for(j = 0; j < SIZE; j++){
            grid[i][j] = ' ';
        }
    }

    /* generating random inital position */
    c = 'A';
    srand(time(NULL));  
    l = rand() % 10;
    m = rand() % 10;
    grid[l][m] = c;

    /*  North : 0
        East : 1
        South : 2
        West : 3   */

    while(flag == 0){
        dir = rand() % 4;
        count = 0;
        while(count < 3 && flag == 0){
            if(dir == 0){
                if(0 < l && grid[l-1][m] == ' '){
                    l--;
                    flag = 1; //empty space found
                    break;
                }
                else{
                    count++;
                    dir = (dir + 1) % 4;
                }
            }
            if(dir == 1){
                if(m < 9 && grid[l][m+1] == ' '){
                    m++;
                    flag = 1;
                    break;
                }
                else{
                    count++;
                    dir = (dir + 1) % 4;
                }
            }
            if(dir == 2){
                if(l < 9 && grid[l+1][m] == ' '){
                    l++;
                    flag = 1;
                    break;
                }
                else{
                    count ++;
                    dir = (dir + 1) % 4;
                }
            }
            if(dir == 3){
                if(0 < m && grid[l][m-1] == ' '){
                    m--;
                    flag = 1;
                    break;
                }
                else{
                    count++;
                    dir = (dir + 1) % 4;
                }
            }
        }
        if(flag == 1){ //empty space filled
            c++;
            grid[l][m] = c;
            flag = 0; //The loop must continue
        }
        else{
            flag = 1;
        }
        if(c == 'Z'){
            break;
        }
    }

    for(i = 0; i < SIZE; i++){
        for(j = 0; j < SIZE; j++){
            printf("[%c]",grid[i][j]);
        }
        printf("\n");
    }
    return 0;
}