#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
void equipos(char [5][20]);
void puntos(int [5][8], char [5][20]);
void cambiare (char [5][20],int,int);
void cambiarp (int [5][8],int,int);
void ordenar (char [5][20],int [5][8]);
void print (char [5][20],int [5][8]);
void validar(int [5][8],int,int);
int main()
{
    char equipo[10][20];
    int puntajes[5][8]={{0},{0},{0},{0},{0}};
    equipos(equipo);
    puntos(puntajes, equipo);
    ordenar (equipo,puntajes);
    print(equipo,puntajes);
    return 0;
}
void equipos (char x[5][20])
{
    int a,b;
    for (a=0;a<5;a++)
        {
            printf("\ningrese el nombre del equipo:\n");
            b=0;
            do
            {
                x[a][b]=getche ();
                if(x[a][b]!='\r')
                b++;
            }while (b<19&&x[a][b]!='\r');
            x[a][b]='\0';
        }
        return;
}
void puntos(int p[5][8], char e[5][20])
{
    int x,z,w,n;
    for (w=0;w<5;w++)
    {
        x=0;
        printf("\ncoloque la informacion para el equipo: ");
        for(z=0;e[w][z]!='\0';z++)
            printf("%c",e[w][z]);
        printf("\nPuntos: ");
        scanf("%d",&p[w][x]);
        x++;
        printf("\nPartidos jugados: ");
        scanf("%d",&p[w][x]);
        validar(p,w,x);
        x+=4;
        printf("\nGoles a favor: ");
        scanf("%d",&p[w][x]);
        x++;
        printf("\nGoles en contra: ");
        scanf("%d",&p[w][x]);
        x++;
        p[w][x]=p[w][x-2]-p[w][x-1];
        for(n=0;n<8;n++)
        printf("%d-",p[w][n]);
    }
    return;
}

void cambiarp (int a[5][8],int p1,int p2)
{
    int x,y;
    for (x=0;x<8;x++)
    {
        y=a[p1][x];
        a[p1][x]=a[p2][x];
        a[p2][x]=y;
    }
    return;
}
void cambiare (char a[5][20],int p1,int p2)
{
    int x;
    char aux;
    for(x=0;x<20;x++)
    {
        aux=a[p1][x];
        a[p1][x]=a[p2][x];
        a[p2][x]=aux;
    }
    return;
}
void ordenar (char e[5][20],int p[5][8])
{
    int x,z;
    for(x=0;x<5;x++)
    for(z=0;z<5;z++)
    {
        if(p[x][0]<p[z][0])
        {
            cambiarp(p,x,z);
            cambiare(e,x,z);
        }
        if(p[x][0]==p[z][0])
            {
              if (p[x][7]<p[z][7])
              {
                 cambiarp(p,x,z);
                 cambiare(e,x,z);
              }
                if(p[x][7]==p[z][7])
                  if(p[x][5]<p[z][5])
                  {
                      cambiarp(p,x,z);
                      cambiare(e,x,z);
                  }
            }
    }
    return;
}
void print(char e[5][20],int p[5][8])
{
    int x,y;
    printf("\nOrdenados, los equipos quedan:\n");
    for(x=4;x>=0;x--)
    {
        for(y=0;e[x][y]!='\0';y++)
            printf("%c",e[x][y]);
            printf("      ");
        for(y=0;y<8;y++)
        printf("%d-",p[x][y]);
        printf("\n");
    }
    return;
}
void validar(int x[5][8],int f,int c)
{
    int suma,y=c;
    do
        {
            suma=0;
            y++;
        printf("\nPartidos ganados: ");
        scanf("%d",&x[f][y]);
        suma+=x[f][y];
        y++;
        printf("\nPartidos perdidos: ");
        scanf("%d",&x[f][y]);
        suma+=x[f][y];
        y++;
        printf("\nPartidos empatados: ");
        scanf("%d",&x[f][y]);
        suma+=x[f][y];
        if(suma!=x[f][c])
        {
        y=c;
        printf("\nERROR, no coinciden los valores con los partidos jugados, ingrese los valores otra vez.\n");
        }
        }while (suma!=x[f][c]);
        return;
}
