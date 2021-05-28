#include <stdio.h>
#include <stdlib.h>

int main()
{
    int contador=0;
    char a,b;
    printf("ingrese una letra a buscar\n");
    a=getche();
    printf("\ningrese un texto que finalice con un punto\n");
    do
    {
        b=getche();
        if (a==b)
        {
            contador++;
        }
    }while(b!='.');
    printf("\nLa letra %c aparece %d veces",a,contador);
    return 0;
}
