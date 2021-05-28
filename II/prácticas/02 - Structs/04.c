#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#define  tam 5
struct equip
{
    char nombre[30];
    int datos[8];
};
void f_print(struct equip[]);
void f_cargadatos(struct equip[]);
void f_carganombre(struct equip[]);
void f_ordenar(struct equip[]);
void f_cambiar(struct equip[],int,int);
int main()
{
    struct equip eq[tam];
    f_cargadatos(eq);
    f_ordenar(eq);
    f_print(eq);
    return 0;
}
void f_cargadatos(struct equip e[tam])
{
    int pos1,pos2;
    char tipo[7][13]={{"p.ganados"},{"p.perdidos"},{"p.empatados"},{"p.jugados"},{"golesafavor"},{"golesencontra"},{"puntos"}};
    f_carganombre(e);
    for(pos1=0;pos1<tam;pos1++)
    {
        printf("\ningrese los datos para el %s",e[pos1].nombre);
        for(pos2=0;pos2<7;pos2++)
        {
            printf("\ningrese la cantidad de %s",tipo[pos2]);
            scanf("%d",&e[pos1].datos[pos2]);
        }
        e[pos1].datos[pos2]=e[pos1].datos[4]-e[pos1].datos[5];
    }
}
void f_carganombre(struct equip eq[tam])
{
    int y,x;
    for(x=0;x<tam;x++)
    {
        printf("\ningrese el nombre del %d° equipo: ",x+1);
         y=0;
        do
        {
            eq[x].nombre[y]=getche();
            if(eq[x].nombre[y]!='\r')
            y++;
        }while(y<28&&eq[x].nombre[y]!='\r');
        eq[x].nombre[y]='\0';
    }
    return;
}
void f_ordenar (struct equip eq[tam])
{
    int x,z;
    for(x=0;x<tam;x++)
    for(z=x+1;z<tam;z++)
    {
        if(eq[x].datos[0]<eq[z].datos[0])
                f_cambiar(eq,x,z);
            if(eq[x].datos[0]==eq[z].datos[0])
            {
              if (eq[x].datos[7]<eq[z].datos[7])
              f_cambiar(eq,x,z);
                if(eq[x].datos[7]==eq[z].datos[7])
                  if(eq[x].datos[5]<eq[z].datos[5])
                  f_cambiar(eq,x,z);
            }
    }
    return;
}
void f_cambiar(struct equip e[tam],int pos1,int pos2)
{
    int x,aux;
    for (x=0;x<30;x++)
    {
        aux=e[pos1].nombre[x];
        e[pos1].nombre[x]=e[pos2].nombre[x];
        e[pos2].nombre[x]=aux;
        aux=e[pos1].datos[x];
        e[pos1].datos[x]=e[pos2].datos[x];
        e[pos2].datos[x]=aux;
    }
    return;
}
void f_print(struct equip equ[tam])
{
    int x,y;
    printf("\nOrdenados, los equipos quedan:\n");
    for(x=0;x<tam;x++)
    {
        printf("%s : ",equ[x].nombre);
        for(y=0;y<8;y++)
        printf("%d-",equ[x].datos[y]);
        printf("\n");
    }
    return;
}
