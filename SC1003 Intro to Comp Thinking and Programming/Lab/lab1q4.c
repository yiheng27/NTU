/*4. Write a C program that computes the value of e^x
 according to the following formula:
e^x = 1 + x/1! + (x)^2/2! + (x)^3/3! + ... + (x)^10/10!  (to 2 dp)*/


float fact (float x);
float power (float x, int power);
float ex (float x);


#include <stdio.h>
int main()
{

   float x;
   printf("Enter x:\n");
   scanf("%f", &x);

   printf("Result = %.2f", ex(x));

   return 0;
}

float fact (float x)
{
    float fact = 1;
    for(int i=1; i<=x; i++)
    {
        fact *= i;
    }
    return fact;
}

float power (float x, int power)
{
    float result=1;
    for (int i=1; i<=power; i++)
    {
        result *= x;
    }
    return result;
}

float ex (float x)
{
    float ex = 1;
    for (int i=1; i<=10;i++)
    {
        ex = ex + ( ( power(x,i) ) / ( fact(i) ) );
    }
    return ex;
}