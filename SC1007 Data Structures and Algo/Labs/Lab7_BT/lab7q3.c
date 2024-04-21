#include <stdio.h>
#include <stdlib.h>

int nQueens(int** board, int N, int col);
int isSafe(int** board,int N, int row, int col);
void printSolution(int** board, int N);

int main()
{
    int **board;
    int BSize;

    int i,j;

    printf("Enter the size of chessBoard:\n");
    scanf("%d",&BSize);

    board = (int **)malloc(BSize*sizeof(int *));
    for(i=0;i<BSize;i++)
        board[i] = (int *)malloc(BSize*sizeof(int));

    for(i=0;i<BSize;i++)
       for(j=0;j<BSize;j++)
           board[i][j] = 0;

    nQueens(board, BSize, 0);

    return 0;
}

int nQueens(int** board, int BSize, int col) //not complete (seg)
{
    if (col>=BSize){ //if reach col outisde of bsize, soln found
        return 1;
    }
    else{
        for (int i=0; i<BSize; i++){ //iterate rows
            if (isSafe(board,BSize,i,col)){ //check safe
                for (int j=0; j<BSize; j++){ // if safe place queen in sqaure
                    board[i][col]=1;
                    board[i+j][col+j] = 1;
                    board[i+j][col-j] = 1;
                    board[i-j][col+j] = 1;
                    board[i-j][col-j] = 1;
                    board[j][i] = 1;
                    board[i][j] = 1;
                }
                if (nQueens(board,BSize,col+1)){ //iterate next col
                    return 1; //if true return true
                }
                for (int k=0; k<BSize; k++){ // delete queen
                    board[i][col]=0;
                    board[i+k][col+k] = 0;
                    board[i+k][col-k] = 0;
                    board[i-k][col+k] = 0;
                    board[i-k][col-k] = 0;
                    board[k][i] = 0;
                    board[i][k] = 0;
                }
            }
        }
    }
    return 0;
}

//Safe checking
int isSafe(int** board,int BSize, int row, int col)
{
    int i, j;

    // Horicatal check
    for (i = 0; i < col; i++)
        if (board[row][i])
            return 0;

    // Upper left diagonal check
    for (i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (board[i][j])
            return 0;

    // Lower left diagonal check
    for (i = row, j = col; j >= 0 && i < BSize; i++, j--)
        if (board[i][j])
            return 0;

    return 1;
}

void printSolution(int** board, int BSize)
{
    int i,j;
    for (i = 0; i < BSize; i++) {
        for (j = 0; j < BSize; j++){
            if(board[i][j]==1)
                printf(" Q ");
            else
                printf(" + ");
        }
        printf("\n");
    }
    printf("\n");
}
