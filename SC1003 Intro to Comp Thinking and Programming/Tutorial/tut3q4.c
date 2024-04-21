/*
4. A square matrix (2‐dimensional array of equal dimensions) can be reduced to upper‐
triangular form by setting each diagonal element to the sum of the original elements in
that column and setting to 0s all the elements below the diagonal.  For example, the 4‐
by‐4 matrix:
       4   3   8   6
       9   0   6   5
       5   1   2   4
       9   8   3   7
would be reduced to
       27   3   8   6
        0   9   6   5
        0   0   5   4
        0   0   0   7
Write a function reduceMatrix2D() to reduce a matrix with dimensions of rowSize and
colSize. The prototype of the function is:
void reduceMatrix2D(int ar[][SIZE], int rowSize, int colSize);
SIZE is a constant defined at the beginning of the program. For example, #define SIZE 10.
The parameters rowSize and colSize are used to specify the dimensions of the 2‐
dimensional array (e.g. 4x4) that the function should process.
Write a program to test the function
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define SIZE 4

void reduceMatrix2D(int ar[][SIZE], int rowSize, int colSize);

int main (void)
{
    int ar[SIZE][SIZE] = {4,3,8,6, 9,0,6,5, 5,1,2,4, 9,8,3,7};
    reduceMatrix2D(ar,SIZE,SIZE);
}

void reduceMatrix2D(int ar[][SIZE], int rowSize, int colSize)
{

    for (int c=0;c<colSize;c++) //traverse column,c
    {
        int sum = 0;
        for (int r=c+1;r<rowSize;r++) //process row,r
        {
            sum += ar[r][c];
            ar[r][c]=0;
        }
        ar[c][c] += sum;
    }

    for (int r=0; r<rowSize; r++)
    {
            for(int c=0;c<colSize; c++)
            {
                    printf("%d ", ar[r][c]);
            }
            printf("\n");
    }
}