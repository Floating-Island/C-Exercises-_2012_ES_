#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x,max=0,min,cont=0;
    printf("ingrese numeros enteros positivos, pulse 0 para finalizar\n");
    scanf("%d",&x);
    while (x<=0)
    {
        printf("\ningrese numeros enteros positivos pulse 0 para finalizar\n");
        scanf("%d",&x);
    }
    while ((x!=0)&&(cont==0))
    {
        max=x;
        min=x;
        cont++;
    }
    while (x!=0)
    {
        if (x>max)
        {
            max=x;
        }
        if (x<min)
        {
            min=x;
        }
         printf("\ningrese numeros enteros positivos pulse 0 para finalizar\n");
        scanf("%d",&x);
    }
    printf("\nel maximo es %d y el minimo %d",max,min);
    return 0;
}
