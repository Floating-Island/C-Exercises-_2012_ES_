#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a;
    char c;
    printf("ingrese una letra minuscula\n");
    c=getche();
    while (c<'a'||c>'z')
    {
        printf("\ningrese una letra minuscula\n");
        c=getche();
    }
    printf("\nelija una opcion:\n1-convertir a mayuscula\n2-Obtener la siguiente\n3-Obtener la anterior\n");
    scanf("%d",&a);
    switch (a)
    {
        case 1:
        printf ("su mayscula es: %c",c-32);
        break;
        case 2:
        if (c!='z')
        {
            printf("Su siguiente es: %c",c+1);
        }
        else
        {
            printf("z es la ultima letra, no tiene siguiente");
        }
        break;
        case 3:
        if (c!='a')
        {
            printf("Su anterior es: %c",c-1);
        }
        else
            printf("a es la primer letra, no tiene anterior");
        break;

    }

    return 0;
}
