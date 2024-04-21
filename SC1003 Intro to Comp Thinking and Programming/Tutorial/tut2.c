/*
(calDistance) Write a C program that accepts four decimal values representing the coordinates of two points,
i.e. (x1, y1) and (x2, y2), on a plane, and calculates and displays the distance between the points:

distance = root( (x2-x1)^2 + (y2-y1)^ )

Your program should be implemented using functions.
Provide two versions of the function for calculating the distance:
(a) one uses call by value only for passing parameters;
(b) the other uses call by reference to pass the result to the calling function.
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double CalDist (double*, double*, double*, double*);

int main (void)
{
    double dist, x1, y1, x2, y2;
    //ask for user input for x1 y1 x2 y2 (function) ****
    printf ("input x1 y1 x2 y2:");
    scanf ("%lf %lf %lf %lf", x1, y1, x2, y2);


    /*
    dist = CalDist(0,0,3,4); //call by value
    printf("%f\n",dist);
    */
    dist = CalDist(&x1, &y1 ,&x2, &y2); //call by reference
    printf("%f\n",dist);
    return 0;
}

/*
//call by value
double CalDist (double x1, double y1, double x2, double y2)
{
    double dist;
    dist = sqrt( (x2-x1)*(x2-x1) + (y2-y1)*(y2-y1) );
    return dist;
}
*/

//call by function
double CalDist (double* x1, double* y1, double* x2, double* y2)
{
    return sqrt( (*x2-*x1)*(*x2-*x1) + (*y2-*y1)*(*y2-*y1) );
}