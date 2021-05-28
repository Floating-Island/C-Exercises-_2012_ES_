#include <stdio.h>
#include <stdlib.h>

int main()
{
    int vmx,vmn,va;
    char a;
    double tvmx,tvmn;
    printf("ingrese una velocidad maxima\n");
    scanf("%d",&vmx);
    printf("ingrese la velocidad del vehiculo\n");
    scanf("%d",&va);
    printf("es un vehiculo de emergencia?\n");
    a= getche();
    vmn=vmx/2;
    tvmx=vmx*1.15;
    tvmn=vmn*0.85;

    if(a=='s'||a=='S')
    {
        if (va>=vmn)
        {
            printf("\n no recibe multa");
        }

    }

        if(a=='n'||a=='N')
        {
            if(va>=vmn&&va<=vmx)
            {
                printf("\n no recibe multa");
            }
            if (va>tvmx)
            {
                printf("\n recibe multa por exceso de velocidad");
            }
            if (va>=vmx&&va<=tvmx)
            {
                printf("\n recibe advertencia");
            }
        }
         if (va<tvmn)
        {
            printf("\n recibe multa por entorpecer al transito");
        }
     if (va>=tvmn&&va<vmn)
        {
            printf("\n recibe advertencia");
        }


    return 0;
}
