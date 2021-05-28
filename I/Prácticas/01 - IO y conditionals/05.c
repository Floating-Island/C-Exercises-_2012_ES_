#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int a,b,c,d;
    printf("ingrese cateto 1\n");
    scanf("%d", &a);
    printf("ingrese cateto 2\n");
    scanf("%d", &b);
    c= sqrt(a*a+b*b);
    d=c+a+b;
    printf("el perimetro es %d", d);
    return 0;
}
