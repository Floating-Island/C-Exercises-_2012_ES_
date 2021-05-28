#include <stdio.h>
#include <stdlib.h>

int main()
{
    int im;
    double TNA,TEM,inversion=0,intereses=0,montotal=0;
    printf("Ingrese TNA\n");
    scanf("%lf",&TNA);
    printf("ingrese importe mensual\n");
    scanf("%d",&im);
    TEM=(double)TNA*0.01/(double)12;
    while(im>0)
    {
        if(im!=0)
        {
        inversion=inversion+im;
        intereses=intereses+inversion*TEM;
        printf("ingrese importe mensual\n");
        scanf("%d",&im);
    }
    }
    montotal=intereses+inversion;
    printf("El monto final es %.2lf",montotal);
    return 0;
}
