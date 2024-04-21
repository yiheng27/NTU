/*
1. Explain how the addition of 1 to every element of the two dimensional array ‘array’ is
done in the following program.  What if the for statement at ‘line a’ is replaced by this
statement:
add1(array[0], 3 * 4); //same
*/

#include <stdio.h>
void  add1(int ar[], int size);
int main()
{
int array[3][4];
int h,k;
//reads array
for (h = 0; h < 3; h++) //iterate row
    for (k = 0; k < 4; k++) //iterate column
        scanf("%d", &array[h][k]);

add1(array[0], 3 * 4); //new  --> is the same --> the elements are stored in the memory sequentially
//for (h = 0; h < 3; h++) /* line a */
//        add1(array[h], 4);       //calls add1 for each row, h

for (h = 0; h < 3; h++) {
     for (k = 0; k < 4; k++)
       printf("%10d", array[h][k]); //prints out new array
     putchar('\n');
}
return 0;

}
void add1(int ar[], int size)
{
int k;
for (k = 0; k < size; k++)
     ar[k]++;
}