#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x=1000,milena,centena,decena,unidad,impar=0,par=0;
    while (x>=1000&&x<=9999)
        {
           milena=x/1000;
           centena=(x-milena*1000)/100;
           decena=(x-milena*1000-centena*100)/10;
           unidad=x-milena*1000-centena*100-decena*10;
           if(milena%2==0)
           {
              par=par+milena;
           }
           else
           {
               impar=impar+milena;
           }
           if(centena%2==0)
           {
              par=par+centena;
           }
           else
           {
               impar=impar+centena;
           }
           if(decena%2==0)
           {
              par=par+decena;
           }
           else
           {
               impar=impar+decena;
           }
           if(unidad%2==0)
           {
              par=par+unidad;
           }
           else
           {
               impar=impar+unidad;
           }
            if(par==impar)
            {
                printf("%d\n",x);
            }
            x++;
            par=0;
            impar=0;
        }
    return 0;
}
