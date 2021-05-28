#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x,x1,x2,x3,x4;
    printf("ingrese un numero positivo:\n ");
    scanf("%d",&x);
    printf("ingrese otro numero positivo:\n ");
    scanf("%d",&x1);
    if (x==0&&x1==0)
    {
        printf("los dos numeros son cero, su diferencia es cero.");
    }
    else
    {
    x2=x/-x;
    x3=x1/-x1;
    if(x2==-1&&x3==-1)
    {
        if (x>x1)
        {
            x4=x-x1;
            if (x4>=x1&&x4<=x)
            {
                printf("la diferencia de los dos numeros esta entre ellos\n");
            }
            else
            {
                printf("la diferencia de los dos numeros no se encuentra entre ellos\n");
            }
        }
        if (x1>x)
        {

            x4=x1-x;
            if (x4>=x&&x4<=x1)
            {
                printf("la diferencia de los dos numeros esta entre ellos\n");
            }
            else
            {
                printf("la diferencia de los dos numeros no se encuentra entre ellos\n");
            }
        }
    }
    }


    return 0;
}
