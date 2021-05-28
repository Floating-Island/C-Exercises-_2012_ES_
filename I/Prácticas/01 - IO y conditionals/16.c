#include <stdio.h>
#include <stdlib.h>

int main()
{
    double x,x1;
    int x2;
    printf("ingrese un numero real: \n");
    scanf("%lf",&x);
       if(x>0)
       {
           x1=(x-(int)x)*100;
           if (x1>45)
           {
               x2=x+1;
           }
           else
           {
               x2=x;
           }
       printf("su techo es: %d\n",(int)x+1);
       printf("su piso es %d\n",(int)x);
       printf("redondeo: %d",x2);
       }
       if(x<0)
       {
           x1=(x-(int)x)*100;
           if (x1<-45)
           {
               x2=(int)x-1;
           }
           else
           {
               x2=x;
           }
       printf("su piso es: %d\n",(int)x-1);
       printf("su techo es %d\n",(int)x);
       printf("redondeo: %d",x2);
       }
    return 0;
}
