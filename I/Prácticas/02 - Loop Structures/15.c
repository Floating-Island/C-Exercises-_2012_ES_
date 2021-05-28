#include <stdio.h>
#include <stdlib.h>

int main()
{
   int x,renglon=1,asteriscos=0;
   printf("ingrese la base del triangulo rectangulo: ");
   scanf("%d",&x);
   while(renglon<=x)
   {
       while(asteriscos<renglon)
       {
           printf("*");
           asteriscos++;
       }
       asteriscos=0;
       renglon++;
       printf("\n");
   }
}
