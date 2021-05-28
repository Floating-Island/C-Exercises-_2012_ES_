#include <stdio.h>
#include <stdlib.h>

int main()
{
    int h,b;
    double superficie;

    printf("ingrese la base del triángulo\n");
    scanf("%d", &b);
    printf("ingrese la altura\n");
    scanf("%d", &h);
    superficie=b*h/2;
    printf("la superficie del triangulo es %lf", superficie);
    return 0;
}
