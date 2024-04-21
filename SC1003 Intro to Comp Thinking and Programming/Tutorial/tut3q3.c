/*
3. Write a function that takes a square matrix ar, and the array sizes for the rows and
columns as parameters, and returns the transpose of the array via call by reference. For
example, if the rowSize is 4, colSize is 4, and the array ar is {1,2,3,4, 5,1,2,2, 6,3,4,4,
7,5,6,7}, then the resultant array will be {1,5,6,7, 2,1,3,5, 3,2,4,6, 4,2,4,7}. That is, for the
4‐by‐4 matrix:
       1   2   3   4
       5   1   2   2
       6   3   4   4
       7   5   6   7

the resultant array after performing the transpose2D function is:
       1   5   6   7
       2   1   3   5
       3   2   4   6
       4   2   4   7
The function prototype is given below:
void transpose2D(int ar[][SIZE], int rowSize, int colSize);
SIZE is a constant defined at the beginning of the program. For example, #define SIZE 10.
The parameters rowSize and colSize are used to specify the dimensions of the 2‐
dimensional array (e.g. 4x4) that the function should process.
Write a program to test the function.
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define SIZE 4

void transpose2D(int ar[][SIZE], int rowSize, int colSize);

int main (void)
{
       //ask for user input, rowsize,colsize & matrix

       int ar[SIZE][SIZE] = {1,2,3,4, 5,1,2,2, 6,3,4,4, 7,5,6,7};
       //int size = (sizeof(ar) / sizeof(ar[0])) ;
       transpose2D(ar,SIZE,SIZE);

}

void transpose2D(int ar[][SIZE], int rowSize, int colSize)
{
       int tmp[rowSize][colSize];
       for (int c=0; c<colSize; c++)      //r is row
       {
              for(int r=0;r<rowSize; r++)        //c is column
              {
                     tmp[c][r]=ar[r][c];         //swaps column w row into tmp
                     /*
                     or:
                     tmp = ar[r][c];
                     ar[r][c] = ar[c][r]
                     ar[c][r] = tmp;
                     */
              }
       }

       for (int r=0; r<rowSize; r++)
       {
              for(int c=0;c<colSize; c++)
              {
                     printf("%d ", tmp[r][c]);   //prints tmp
              }
              printf("\n");
       }
}