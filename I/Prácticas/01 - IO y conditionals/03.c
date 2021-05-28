#include <stdio.h>
#include <stdlib.h>

int main()
{
    double numr, fraccionaria;
    int entero;
    printf("ingrese un número real\n");
    scanf("%lf", &numr);
    entero= (int)numr;
    fraccionaria= numr -entero;
    printf("su parte entera es %d\n", entero );
    printf("su parte fraccionaria es %0.2lf", fraccionaria);
    return 0;
}
