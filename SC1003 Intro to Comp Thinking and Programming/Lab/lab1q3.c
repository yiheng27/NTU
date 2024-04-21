#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    //generate triangle
    int height, num;
    num = 0;

    //User input height
    printf("Enter the Height: \n");
    scanf("%d", &height);


    //Print Triangle
    printf("Pattern: \n");
    for (int row=0; row<height; row++)
    {
        for (int col=0; col<row+1; col++)
        {
            printf("%d", num+1);
        }
        num = (num+1)%3;
        printf("\n");
    }
    //printf("1)
}