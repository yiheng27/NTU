/*Write a C function that compares the string pointed to by s1 to the string pointed to by s2. If
the string pointed to by s1 is greater than, equal to, or less than the string pointed to by s2,
then it returns 1, 0 or –1 respectively. Write the code for the function without using the
standard C string library function strcmp().
Write a C program to test the function.*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define max 50

int stringcmp(char *s1, char *s2);

int main (void)
{
    char source[50], target[50],*p;
    int result;
    printf("Enter the source string: \n");
    fgets(source,50,stdin);
    if ( p=strchr(source,'\n') )
    {
        *p = '\0';
    }
    printf("Enter the target string: \n");
    fgets(target,50,stdin);
    if ( p=strchr(target,'\n') )
    {
        *p = '\0';
    }
    result = stringcmp(source, target);

    switch (result)
    {
        case 1:
            printf("stringcmp(): greater than\n");
            break;
        case 0:
            printf("stringcmp(): equal\n");
            break;
        case -1:
            printf("stringcmp(): less than\n");
            break;
        default:
            printf("error\n");

    }
}

int stringcmp(char *s1, char *s2)
{
    int i = 0;
    while (s2[i] != '\0')       //** need to account for if either is just \0 --> greate/less than other
    {
        if (s1[i]>s2[i])
        {
            return 1;
        }
        else if (s1[i]<s2[i])
        {
            return -1;
        }
        i++;
    }
    return 0;
}