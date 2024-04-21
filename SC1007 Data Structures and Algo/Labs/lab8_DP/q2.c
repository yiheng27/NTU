#include <stdio.h>
#include <stdlib.h>

//memory
int *r;


int cr_bottom_up_dp_print(int *p, int n)
{
    if (n==0){
        return 0;
    }
    printf("n:%i\n",n);
    int cut[n+1];  //n = pos, size = cut[n]
    for (int i=0;i<=n;i++){
        cut[i]=0; //initialise to 0
    }
    int pos =0;
    r[0] = 0;
    for (int j=1; j<=n;j++){
        for (int k=1;k<=j;k++){
            int tmp = p[k] + r[j-k];
            if (tmp > r[j]){    //compare r[i] against different p[i] + r[j-i];
                r[j] = tmp;
                pos = k;
            }
        }
        cut[j]=pos;
    }
    return r[n];
}


void main ()
{
    int n;      //length of  rod
    int function;
    int i;
    int *p;     //price list

    int price_list[10] = {0,1,5,8,9,10,17,17,20,24,30}; //declare one more value to cover the index 0;

    n = sizeof(price_list) / sizeof(int) - 1;
    p = price_list;


    //allocate the memory array
    r = malloc(sizeof(int) * (n+1));


    //set all memory elements to -1
    for (i=0; i<=n; i++)
        r[i] = -1;

    printf("The maximun value is: %d \n", cr_bottom_up_dp_print(p,n));
}
