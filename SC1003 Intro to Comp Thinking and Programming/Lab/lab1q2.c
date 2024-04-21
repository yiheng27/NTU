#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int lines, total, input, count;
    double avg;

    //Number of lines
    printf("Enter Number of lines: ");
    scanf("%d", &lines);


    //Enter Line
    for (int i=0; i<lines; i++)
    {
        total = 0;
        count = 0;
        printf("Enter Line %d (end with -1): \n", i+1);
        scanf("%d ", &input);
        while (input != -1)
        {
            total += input;
            count++;
            scanf("%d", &input);
        }
        avg = (double)total/count;
        printf("%.2lf\n", avg);
    }
    return 0;
}