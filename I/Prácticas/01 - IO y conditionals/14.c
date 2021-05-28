#include <stdio.h>
#include <stdlib.h>

int main()
{
    double x,x1,x2,x4;

    int x3,x0;
    printf("ingrese el importe de la compra");
    scanf("%lf",&x);
    if (x>500.00)
    {
        x1=x*1.16;
        x2=x1-(int)x1;
        x3=x2*100;
        x0=x3%10;
        if (x0<5&&x0>0)
        {
        while (x3%5!=0)
            {
            x3=x3+1;
            }
        x4=x3*0.01;
        }
        if (x0>5&&x0<10)
        {
            while (x3%5!=0)
            {
            x3=x3+1;
            }
        x4=x3*0.01;
        }



        x2=x4+(int)x1;
        printf("valor de la compra: %.2lf \n",x);
        printf("subtotal de la compra: %.2lf \n",x1);
        printf("importe a abonar: %.2lf \n", x2);
       }


    else
    {


        x1=x*1.18;
        x2=x1-(int)x1;
        x3=x2*100;
        x0=x3%10;

        if (x0<5&&x0>0)
        {
        while (x3%5!=0)
        {
            x3=x3+1;
        }
        x4=x3*0.01;
        }
        if (x0<10&&x0>5)
        {
            while (x3%5!=0)
        {
            x3=x3+1;
        }
        x4=x3*0.01;
        }



        x2=x4+(int)x1;

        printf("valor de la compra: %.2lf \n",x);
        printf("subtotal de la compra: %.2lf \n",x1);
        printf("importe a abonar: %.2lf \n", x2);


    }
    return 0;
}
