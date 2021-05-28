#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a,b,c,d=a;

    printf("ingrese el primer numero para calcular el MCD\n");
    scanf("%d",&a);
    printf("ingrese el segundo numero para calcular el MCD\n");
    scanf("%d",&b);

    if (a>b)
    {
        if (a%b==0)
        {
            printf("%d",&b);
        }
        while(a%b!=0)
        {
            c=a%b;
            a=b;
            b=c;


        }
        printf("el MCD es %d",b);
    }
    if (a<b)
    {
        if (b%a==0)
        {
            printf("%d",&a);
        }
        while(b%a!=0)
        {
            c=b%a;
            b=a;
            a=c;


        }
        printf("el MCD es %d",a);
    }
    return 0;
}
