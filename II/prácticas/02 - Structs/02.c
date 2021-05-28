#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define tamano 4
typedef
struct plano
{
    int x,y;
} plano;
void f_cargadatos(plano[tamano]);
void f_comparacion_consec(plano[tamano]);
void f_comparacion_cualqui(plano[tamano]);
int main()
{
plano p[tamano];
f_cargadatos(p);
f_comparacion_consec(p);
f_comparacion_cualqui(p);
return 0;
}
void f_cargadatos(plano p[tamano])
{
    int x;
    for(x=0;x<tamano;x++)
    {
        printf("ingrese las coordenadas en x para el %dº punto: ",x+1);
        scanf("%d",&p[x].x);
        printf("ingrese las coordenadas en y para el %dº punto: ",x+1);
        scanf("%d",&p[x].y);
    }
    return;
}
void f_comparacion_consec(plano p[tamano])
{
    int p1, distmin,aux;
    for(p1=0;p1<tamano-1;p1++)
    {
        if(p1==0)
            distmin=(p[p1].x-p[p1+1].x)*(p[p1].x-p[p1+1].x)+(p[p1].y-p[p1+1].y)*(p[p1].y-p[p1+1].y);
        aux=(p[p1].x-p[p1+1].x)*(p[p1].x-p[p1+1].x)+(p[p1].y-p[p1+1].y)*(p[p1].y-p[p1+1].y);
        if(aux<distmin)
            distmin=aux;
    }
    printf("\n la distancia minima es: %.2lf",sqrt(distmin));
}

void f_comparacion_cualqui(plano p[tamano])
{
    int p1,p2, distmin,aux;

    for(p1=0;p1<tamano-1;p1++)
    for(p2=p1+1;p2<tamano;p2++)
    {
        if(p1==0&&p2==1)
            distmin=(p[p1].x-p[p2].x)*(p[p1].x-p[p2].x)+(p[p1].y-p[p2].y)*(p[p1].y-p[p2].y);
        aux=(p[p1].x-p[p2].x)*(p[p1].x-p[p2].x)+(p[p1].y-p[p2].y)*(p[p1].y-p[p2].y);
        if(aux<distmin)
            distmin=aux;
    }
    printf("\n la distancia minima es: %.2lf",sqrt(distmin));
}
