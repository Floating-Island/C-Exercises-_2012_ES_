#include <stdio.h>
void dibujar_fila(int);
void dibujar_rectangulo(int,int);
int main()
{
   int alto, ancho;
   printf("ingrese ancho:");
   scanf("%d",&ancho);
   printf("ingrese la altura:");
   scanf("%d",&alto);
   dibujar_rectangulo(ancho,alto);
    return 0;
}
void dibujar_fila(int a)
{
    while(a>0)
    {
        printf("x");
        a--;
    }
    return;
}
void dibujar_rectangulo(int x,int y)
{
    while (y>0)
    {
        dibujar_fila(x);
        printf("\n");
        y--;
    }
    return;
}
