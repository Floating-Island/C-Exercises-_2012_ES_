#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x=1,contador=0,contador2;
    printf("ingrese numeros enteros\n");
    while (x>=1)
    {
    while (contador<5)
    {
        contador2=0;
        scanf("%d",&x);
        if (x%2==0)
        {
            contador++;
        }
        while((x%4==0)&&(contador2==0))
        {
            printf("\n%d es multiplo de 4\n",x);
            contador2++;
        }
        printf("-");
    }

    }

    return 0;
}
