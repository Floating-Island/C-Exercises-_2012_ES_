#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a[1000],i=0,r;

    do
    {
        printf("ingrese numeros enteros positivos\n");
        scanf("%d",&a[i]);
        while (a[i]<0)
        {
           printf("error.ingrese numeros enteros positivos\n");
            scanf("%d",&a[i]);
        }
        for (r=0;r<i;r++)
        {

            if (a[r]==a[i])
            {
                printf("error.ingrese numeros enteros positivos\n");
                scanf("%d",&a[i]);
                r=-1;
            }
        }
        if (a[i]!=0)
        {
             i++;
        }
    }while ((a[i]!=0)&&(i<999));
    printf("los numeros son");
    while (i>=0)
    {
        if (a[i]!=0)
        printf(" %d,",a[i]);
        i--;
    }
    return 0;
}
