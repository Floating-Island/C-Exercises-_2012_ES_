#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x,x1=1,x2=1,x3;
    printf("ingrese el valor del diferencial a calcular\n");
    scanf("%d",&x);
    while (x<0)
    {
       printf("ERROR, debe ser positivo\n ingrese el valor del diferencial a calcular\n");
    scanf("%d",&x);
    }
    x3=x;
    while(x>x1)
    {
        x2=x2*x3;
        x3=x3-1;
        x1++;
    }
    switch (x)
    {
        case 0:
        printf("la diferencial de 0 es 1");
        break;
        case 1:
        printf("la diferencial de 1 es 1");
        break;
    }
    if (x!=0&&x!=1)
    {
        printf("la diferencial de %d es: %d",x1,x2);
    }
    return 0;
}
