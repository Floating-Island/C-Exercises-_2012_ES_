#include <stdio.h>
#include <stdlib.h>
#define N 5
int* f_dirmemo(int*,int);
int main()
{
    int x[N]={1,2,3,4,5},y;
    int* p=NULL;
    do
    {
    printf("ingrese una posicion del arreglo:\n");
    scanf("%d",&y);
    }while(y>N-1);
    p=f_dirmemo(x,y);
    printf("lo que hay ahì es: %d",*p);
    return 0;
}
int* f_dirmemo(int a[N],int b)
{
    return (&a[0]+b);
}
