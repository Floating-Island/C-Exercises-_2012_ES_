#include <stdio.h>
#include <stdlib.h>
int maxarr(int*);
int main()
{
    int ar[6]={3,6,2,8,1,0},r;
    printf("el maximo es: %d\n",r=maxarr(ar));
    return 0;
}
int maxarr(int* arr)
{
    int max;
    if(*arr==0)
        return 0;
        else
        {
            max=maxarr(arr+1);
            if(max>*arr)
                return max;
            else
                return *arr;
        }
}
