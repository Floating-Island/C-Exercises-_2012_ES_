#include <stdio.h>
#include <stdlib.h>

int main()
{
   int x,renglon=1,asteriscos=0,espacios=0,a=1;
   printf("ingrese la base del triangulo rectangulo: ");
   scanf("%d",&x);
   while(renglon<=x)
   {
       a++;
       while (espacios<=x-a)
       {
           printf(" ");
           espacios++;

       }
       while(asteriscos<renglon)
       {
           printf("*");
           asteriscos++;
       }
       asteriscos=0;
       renglon++;
       printf("\n");
       espacios=0;
   }
}
