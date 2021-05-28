#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x2;
    double x,x1;
    printf("ingrese un numero real y pulse enter\n");
    scanf("%lf", &x);
    x1=0;
    while (x!=0)
    {
    x1=x/-x;

    x2=x;
    if (x1==-1)
    {
        printf("el numero es positivo");
    }
    if(x1==1)
    {
        printf(" el numero es negativo");
    }

    if(x2<x)
    {
        printf("\n el numero es real");
    }
    if (x2==x)
    {
        printf("\n el numero es entero y natural");
    }
    x=0;
    }
      if(x1==0)
    {
        printf("el numero es 0");
    }
return 0;
}
