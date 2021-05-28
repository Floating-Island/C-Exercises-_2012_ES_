#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x,x2,x1=1,cont=0,cont2=0,cont1=0;
 do
 {
     cont1=0;
     x1=1;
 printf("ingrese numeros binarios positivos\n");
    scanf("%d",&x);
      while (x/x1>0)
        {
            x1=x1*10;
            cont++;
        }
        while(cont>0)
        {
            x2=x/x1;
            x=x-x2;
            x1=x1/10;
            cont--;
            if((x2!=1)&&(x2!=0))
            {
             cont1++;
            }
        }

    }while (cont1!=0);
   printf("correcto!");
    return 0;
}
