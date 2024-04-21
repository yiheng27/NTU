//1. What does the following program print?

#include <stdio.h>
#include <string.h>
#define M1 "How are ya, sweetie?"
char M2[40] = "Beat the clock.";
char *M3 = "chat";
int main()
{
 char words[80],*p;
 printf(M1);                //prints "How are ya, sweetie?", no \n
 puts(M1);                  //no print, M1 has no \0
 puts(M2);                  //prints "Beat the clock."
 puts(M2+1);                //prints "eat the clock."
 fgets(words, 80, stdin);   // user inputs : win a toy.
 if (p=strchr(words,'\n')) *p = '\0';   //replace \n with \0
 puts(words);               //prints "win a toy."
 scanf("%s", words+6);      // user inputs : snoopy.
 puts(words);               //prints "win a snoopy"
 words[3] = '\0';
 puts(words);               //prints "win"
 while (*M3) puts(M3++);    //prints "chat" "hat" "at" "t" , pointer points at \0 in the end
 puts(--M3);                //prints "t", move back and point to "t" and print
 puts(--M3);                //prints "at"
 M3 = M1;                   //&M3=&M1
 puts(M3);                  //prints "How are ya, sweetie?"
 return 0;
}


/*2. The following unknown function receives a string argument and a character argument,
modifies the string argument and returns an integer value. Describe the purpose of the
function. Give an example to support your answer.*/

int unknown(char str[ ], char c)
{
int x, y=0, z=0;
for (x=0; str[x] != '\0'; x++)  //iterate through str w x
    if (str[x] != c)            //if particular element != input char c
    str[y++] = str[x];          //
    else
    z++;
str[y] = '\0';                  //function removes char from the string to form a new string
       return z;                //z = number of existing char c before change
}

