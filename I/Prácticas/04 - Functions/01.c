#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double area(int,int,int);

int main()
{
    int a,b,c;
    printf("ingrese un lado\n");
   scanf("%d",&a);
   printf("ingrese un lado\n");
   scanf("%d",&b);
   printf("ingrese un lado\n");
   scanf("%d",&c);
   printf("el area del triangulo de lados %d,%d,%d es: %.2lf",a,b,c,area(a,b,c));
    return 0;
}
double area (int x,int y,int z)
{
    double e,p;
    p=(x+y+z)/2.0;
    e=sqrt(p*(p-x)*(p-y)*(p-z));
    return e;
}
