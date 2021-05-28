#include <stdio.h>
#include <stdlib.h>
#include <math.h>
struct puntoplano
{
    int x,y;
};
int f_calculodistancia(struct puntoplano []);
void f_ingresocoordenadas();
int main()
{
    struct puntoplano plano[2];
    f_ingresocoordenadas(plano);
    return 0;
}
int f_calculodistancia(struct puntoplano plan[2])
{
    return ((sqrt(plan[0].x*plan[0].x+plan[0].y*plan[0].y)>(sqrt(plan[1].x*plan[1].x+plan[1].y*plan[1].y)))? 0:1);
}
void f_ingresocoordenadas(struct puntoplano p[2])
{
    int cont,aux;
    double dist=0;
    for(cont=0;cont<2;cont++)
    {
    printf("Ingrese la coordenada positiva en x: \n");
    scanf("%d",&p[cont].x);
    printf("Ingrese la coordenada positiva en y: \n");
    scanf("%d",&p[cont].y);
    dist=f_calculodistancia(p);
    }
    aux=f_calculodistancia(p);
    printf("\nLas coordenadas que se encuentran mas lejos son: %d,%d",p[aux].x,p[aux].y);
    return;
}
