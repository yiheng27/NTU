/*
2. Write a program which will draw the histogram for n integers from 0 to 99.  N is input by
the user.  Each of the n numbers will be generated by calling rand() % 100.  The program
will consist of two functions
(i) to collect the frequency distribution of the numbers
(ii) to print the histogram.  An example histogram is shown here.
0 – 9   |*********************
10 – 19 |************
20 – 29 |*************
30 – 39 |**
…......
90 – 99 |***************
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 30

/*

void freq (int *ptr,int lowerlimit, int upperlimit, int rand);
void printhist (int *ptr, int lower, int upper);

int main (void)
{
    int N,r0,r10,r20,r30,r40,r50,r60,r70,r80,r90 = 0;
    int *p0,*p1,*p2,*p3,*p4,*p5,*p6,*p7,*p8,*p9;
    printf("How many intergers?: ");
    scanf("%d", &N); //N = number of integers

    for (int i=0; i<N; i++)
    {
        int randomint = rand() % 100;
        freq(&r0, 0, 9, randomint);
        freq(&r10, 10, 19, randomint);
        freq(&r20, 20, 29, randomint);
        freq(&r30, 30, 39, randomint);
        freq(&r40, 40, 49, randomint);
        freq(&r50, 50, 59, randomint);
        freq(&r60, 60, 69, randomint);
        freq(&r70, 70, 79, randomint);
        freq(&r80, 80, 89, randomint);
        freq(&r90, 90, 99, randomint);
    }
    printhist (&r0, 0, 9);
    printhist (&r10, 10, 19);
    printhist (&r20, 20, 29);
    printhist (&r30, 30, 39);
    printhist (&r40, 40, 49);
    printhist (&r50, 50, 59);
    printhist (&r60, 60, 69);
    printhist (&r70, 70, 79);
    printhist (&r80, 80, 89);
    printhist (&r90, 90, 99);

}

void freq (int *ptr,int lowerlimit, int upperlimit, int rand)
{
    if (lowerlimit <= rand && rand <= upperlimit)
    {
        (*ptr)++;
    }

}

void printhist (int *ptr, int lower, int upper)
{
    printf("%d - %d |", lower, upper);
    for (int i=0;i<*ptr;i++)
    {
        printf("*");
    }
    printf("\n");
}

*/

int main (void)
{
    printf("How many intergers? (<30): ");
    scanf("%d", &N); //N = number of integers
    srand(time(NULL));          //generate a seed number --> make sure that everytime rng is random, instead of always same

    int histogram[10];


    freq(histogram[0],N);
    prhist;
}

void freq (int freq)
{
    for (int i=0; i<freq; i++)
    {
        int randomint = rand() % 100;
        histogram[randomint/10]++;
    }
}

void prhist (void)
{
    return
}