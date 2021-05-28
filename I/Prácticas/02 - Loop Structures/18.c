#include <stdio.h>
#include <stdlib.h>

int main()
{
    int b,a,renglon=1,asteriscos=0,espacios=0,cont=0;
    printf("ingrese la base\n");
    scanf("%d",&b);
    printf("ingrese la altura\n");
    scanf("%d",&a);
    while(renglon<=a)
    {
        asteriscos=0;
        if((renglon==1)||(renglon==a))
        {
            while(asteriscos<b)
            {
                printf("*");
                asteriscos++;
            }
        renglon++;
        printf("\n");
            }

        if((renglon!=1)&&(renglon!=a+1))
        {
            printf("*");
            while(cont<b-1)
            {
              while(espacios<(b-2))
              {
                  printf(" ");
                  espacios++;
                  cont++;
              }
              printf("*");
              cont++;
            }
            espacios=0;
            cont=0;
            renglon++;
        printf("\n");
        }
    }
    return 0;
}
