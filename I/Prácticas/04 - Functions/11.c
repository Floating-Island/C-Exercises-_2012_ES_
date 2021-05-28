#include <stdio.h>
#include <stdlib.h>
#include <math.h>
void carga_arreglo(double*);
double calc_prom(double*);
void desvio_estandar(double*,double);
int main()
{
    double a[10],b;
    printf("ingrese los valores, hasta 10 valores;para finalizar 0.\n");
    carga_arreglo(a);
    b=calc_prom(a);
    desvio_estandar(a,b);
    return 0;
}
void carga_arreglo(double x[10])
{
    int y=0;
    do
    {
        scanf("%lf",&x[y]);
        if(x[y]!=0)
        y++;
    }while(y<10&&x[y]!=0);
    return;
}
double calc_prom(double y[10])
{
    int x,a=0;
    for(x=0;y[x]!=0;x++)
    a+=y[x];
    return (double)a/(x);
}
void desvio_estandar(double x[10],double b)
{
    int a;
    double c=0,tita;
    for(a=0;x[a]!=0;a++)
    c+=(x[a]-b)*(x[a]-b);
    tita=sqrt((double)c/(a-1));
    printf("el desvio estandar es de %lf",tita);
    return;
}
