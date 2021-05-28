#include <stdio.h>
#include <stdlib.h>
#define max 3
void f_tranposicion (int [][max]);
void f_carga(int [][max]);
void f_imprime(int [][max]);
int main()
{
    int m[max][max];
    f_carga(m);
    f_tranposicion(m);
    f_imprime(m);
    return 0;
}
void f_tranposicion (int matriz[max][max])
{
    int x=0,fila, columna,aux;
            for(fila=x;fila<max;fila++,x++)
                for(columna=x;columna<max;columna++)
            {
                    aux=matriz[fila][columna];
                    matriz[fila][columna]=matriz[columna][fila];
                    matriz[columna][fila]=aux;
            }
    return;
}
void f_carga(int m[max][max])
{
    int fila,col;
    for(fila=0;fila<max;fila++)
    for(col=0;col<max;col++)
    {
        printf("\ningrese el numero que va en la fila %d, columna %d:",fila+1,col+1);
        scanf("%d",&m[fila][col]);
    }
    return;
}
void f_imprime(int mat[max][max])
{
    int a, b;
    for(a=0;a<max;a++)
    {
        for(b=0;b<max;b++)
            printf("%d-",mat[a][b]);
        printf("\n");
    }
    return;
}
