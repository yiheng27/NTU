/*3. Write the function strncpy() that copies not more than n characters (characters that follow a
null character are not copied) from the array pointed to by s2 to the array pointed to by s1.
If the array pointed to by s2 is a string shorter than n characters, null characters are
appended to the copy in the array pointed to by s1, until n characters in all have been
written.  The strncpy returns the value of s1.
Write a C program to test the function.*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 50

char *strncpynew(char * s1, char * s2, int n);

int main (void)
{
    char str[MAX], *p, str1[MAX];
    int n;
    printf("Enter the string: \n");
    fgets(str,50,stdin);
    if ( p=strchr(str,'\n') )
    {
        *p = '\0';
    }
    printf("Enter number of characters:\n");
    scanf("%d", &n);
    printf("strncpy(): %s\n", strncpynew(str1,str,n));
}

char *strncpynew(char *s1, char *s2, int n)
{
    int i = 0;
    while (s2[i] != '\0' && i<n)
    {
        s1[i] = s2[i];
        i++;
    }
    s1[i] = '\0';       //**REMEMBER TO END WITH NULL**
    return s1;
}
