#include <stdio.h>
#include <stdlib.h>

int divr(int,int);
int main()
{
    int a,b;
    printf("ingrese\n");
    scanf("%d",&a);
    scanf("%d",&b);
    printf("\nresultado: %d",b=divr(a,b));
    return 0;
}
int divr(int a,int b)
{
    if(a<b)
        return 0;
    else
        return 1+divr(a-b,b);
}
