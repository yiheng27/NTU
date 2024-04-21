#include <stdio.h>
#include <stdlib.h>

int main()
{
    int id, score, grade;


    printf("Enter Student ID: ");
    scanf("%d", &id);

    while (id != -1)
    {
        printf("Input Student's Score: \n");
        scanf("%d", &score);
        if (score >= 75)
            grade = 1;
        else if (score >= 65)
            grade = 2;
        else if (score >= 55)
            grade = 3;
        else if (score >= 45)
            grade = 4;
        else
            grade = 5;


        switch(grade)
        {
            case 1:
                printf("Grade: A\n");
                break;
            case 2:
                printf("Grade: B\n");
                break;
            case 3:
                printf("Grade: C\n");
                break;
            case 4:
                printf("Grade: D\n");
                break;
            case 5:
                printf("Grade: F\n");
                break;
            default:
                printf("Wrong input!\n");
        }
        printf("Enter Student ID: ");
        scanf("%d", &id);

        if (id == -1)
        {
            break;
        }


    }
    return 0;
}
