#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x,a,c=0,x4,x1=10,x2=1,cont=1,cont2=0;
    printf("ingrese un numero\n");
    scanf("%d",&x);

        while (x/x1!=0)
        {
            x1=x1*10;
            cont++;


        }
        a=x;
        while (cont>cont2)
        {
x1=x1/10;
            x4=x/x1;
            c=c+x4*x2;
            x2=x2*10;
            x=x-x4*x1;

            cont2++;

        }
        if (c==a)
        {
            printf("%d es capicua",a);
        }
    return 0;
}
