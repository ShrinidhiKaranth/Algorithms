/**
* Problem:
* Hi, here's your problem today. This problem was recently asked by Amazon:
* You are given a 2D array of integers. Print out the clockwise spiral traversal of the matrix.
*
* Example:
* 
* grid = [[1,  2,  3,  4,  5],
*        [6,  7,  8,  9,  10],
*        [11, 12, 13, 14, 15],
*        [16, 17, 18, 19, 20]]
*
*
* The clockwise spiral traversal of this array is:
*
* 1, 2, 3, 4, 5, 10, 15, 20, 19, 18, 17, 16, 11, 6, 7, 8, 9, 14, 13, 12
*
* Solution:
*/

#include <stdio.h>

#define ROW 5
#define COL 5
void printSpirally(int grid[ROW][COL]);

int main()
{
    int grid[ROW][COL] = 
                        //Input 1 - change matrix to [1][5]
                        //{  {1,  2,  3,  4,  5} };
                        
                        //Input 2 - change matrix to [5][5]
                        {  {1,  2,  3,  4,  5},
                        {6,  7,  8,  9,  10},
                        {11, 12, 13, 14, 15},
                        {16, 17, 18, 19, 20},
                        {21, 22, 23, 24, 25}};
                        
                        //Input 3 - change matrix to [5][1]
                        //{  {1}, {2}, {3}, {4}, {5} };
    printSpirally(grid);
    return 0;
}

void printSpirally(int grid[ROW][COL]) {
    printf("Printing Spirally:\n");
    int startRow = 0, startCol = 0, endRow = ROW, endCol = COL;
    
    while(1) {
        //Terminating condition - when there's no row or column to print
        if( startCol >= endCol || startRow >= endRow) {
            break;
        }
        
        //First print the top row
        for(int i = startCol; i < endCol; i++) {
            printf(" %d", grid[startRow][i]);
        }
        //Increment the row counter as we no longer need to print the first row
        startRow++;
        
        //Print the last column
        for(int i = startRow; i < endRow; i++) {
            printf(" %d", grid[i][endCol - 1]);
        }
        //Decrement the column counter as we already print the last column
        endCol--;
        
        //Print the last row in reverse
        if( startRow < endRow) {
            for(int i = endCol - 1; i >= startCol; i--) {
                printf(" %d", grid[endRow - 1][i]);
            }
        }
        //Decrement the last row counter as we just printed it
        endRow--;
        
        //Now, finally, print the first column in reverse
        if(startCol < endCol ) {
            for(int i = endRow - 1; i > startRow; i--) {
                printf(" %d", grid[i][startCol]);
            }
        }
        //Increment the first column pointer
        startCol++;
    }
}
