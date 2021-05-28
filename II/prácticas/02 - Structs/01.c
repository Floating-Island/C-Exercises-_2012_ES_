#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define tam 5
void f_ingresocoordenadas(int [][tam]);
void f_calculodistancia(int [][tam]);
int main()
{
    int plano[tam][tam]={{0},{0},{0},{0},{0}};
    f_ingresocoordenadas(plano);
    f_calculodistancia(plano);
    return 0;
}
void f_ingresocoordenadas(int p[tam][tam])
{
    int x,y,cont;
    for(cont=0;cont<2;cont++)
    {
    printf("Ingrese la coordenada positiva en x: \n");
    scanf("%d",&x);
    printf("Ingrese la coordenada positiva en y: \n");
    scanf("%d",&y);
    p[x-1][y-1]=1;
    }
    return;
}
void f_calculodistancia(int p[tam][tam])
{
    int fil,col,aux=0,t[2];
    for(fil=0;fil<tam;fil++)
    for(col=0;col<tam;col++)
    {
        if(p[fil][col]==1)
        if(aux<sqrt(fil*fil+col*col))
        {
            aux=sqrt(fil*fil+col*col);
            t[0]=fil;
            t[1]=col;
        }
    }
    printf("la coordenada mas lejana al origen es %d(x)-%d(y)",t[0]+1,t[1]+1);
    return;
}
