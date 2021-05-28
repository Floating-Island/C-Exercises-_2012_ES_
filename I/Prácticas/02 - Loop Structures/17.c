#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x,asteriscos=0,cr,espacios=0,renglon=1;
    printf("ingrese la base impar\n");
    scanf("%d",&x);
    while ((x<3)||(x%2==0))
    {
        printf("\nerror: ingrese la base impar\n");
    scanf("%d",&x);
    }
    cr=x/2+1;
    while (renglon<=cr)
    {
        while(espacios<(x/2-(renglon-1)))
        {
            printf(" ");
            espacios++;
        }
        espacios=0;
        while(asteriscos<(1+2*(renglon-1)))
              {
                  printf("*");
                  asteriscos++;
              }
              asteriscos=0;
        renglon++;
        printf("\n");
    }
        while(renglon<=x+2)
        {
            espacios=0;
            while(espacios<(renglon-(x/2)-1))
            {
                printf(" ");
                espacios++;
            }
            while(asteriscos<(x-espacios*2))
            {
                printf("*");
                asteriscos++;
            }

            asteriscos=0;
            renglon++;
            printf("\n");
        }
    return 0;
}
