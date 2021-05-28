#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#define N 5
typedef struct{
char nombre[30];
char pais[30];
int documento;
} datos;
void f_cargadatos(datos[]);
void f_cangaN(datos[],int);
void f_cargaP(datos[],int);
void f_cambio(datos[],int,int);
void f_ordenan(datos[]);
void f_ordenad(datos[]);
void f_ordenap(datos[]);
void f_opcion(datos[]);
int main()
{
    datos personas[N];
    f_opcion(personas);
    return 0;
}
void f_opcion(datos p[N])
{
    int op;
    do
    {
        printf("ingrese una opcion:\n1_Cargar personas.\n2_Ver listado por nombre.\n3_Ver listado por documento.\n4_Ver listado ordenado por pais.\n5_Salir del programa.\n");
        scanf("%d",&op);
        switch(op)
        {
            case 1:
            f_cargadatos(p);
            break;
            case 2:
            f_ordenan(p);
            break;
            case 3:
            f_ordenad(p);
            break;
            case 4:
            f_ordenap(p);
            break;
            default:
            exit (0);
        }
    }while(op>0&&op<5);
    return;
}
void f_cargadatos(datos pers[N])
{
    int pos;
    for(pos=0;pos <N;pos++)
    {
        printf("ingrese el nombre de una persona:\n");
        f_cangaN(pers,pos);
        printf("\nIngrese el pais:\n");
        f_cargaP(pers,pos);
        printf("\ningrese el numero de documento:\n");
        scanf("%d",&pers[pos].documento);
    }
    return;
}
void f_cangaN(datos a[N],int p)
{
    int x=0;
    do
    {
        a[p].nombre[x]=getche();
        if(a[p].nombre[x]!='\r')
        x++;
    }while(x<29&&a[p].nombre[x]!='\r');
    a[p].nombre[x]='\0';
    return;
}
void f_cargaP(datos a[N],int p)
{
    int x=0;
    do
    {
        a[p].pais[x]=getche();
        if(a[p].pais[x]!='\r')
        x++;
    }while(x<29&&a[p].pais[x]!='\r');
    a[p].pais[x]='\0';
    return;
}
void f_ordenan(datos pp[N])
{
    int x,y,z;
    for(x=0;x<N;x++)
        for(y=x+1;y<N;y++)
        {
            z=0;
            do{
                if(pp[x].nombre[z]>pp[y].nombre[z])
                f_cambio(pp,x,y);
                if(pp[x].nombre[z]<pp[y].nombre[z])
                break;
                if((pp[x].nombre[z]==pp[y].nombre[z])&&pp[x].nombre[z]!='\0')
                z++;
            }while(z<N&&pp[x].nombre[z]!='\0');
        }
    for(x=0;x<N;x++)
        printf("%-31s%-31s%-10d\n",pp[x].nombre,pp[x].pais,pp[x].documento);
    return;
}
void f_ordenap(datos pp[N])
{
    int x,y,z;
    for(x=0;x<N;x++)
        for(y=x+1;y<N;y++)
        {
            z=0;
            do{
                if(pp[x].pais[z]>pp[y].pais[z])
                f_cambio(pp,x,y);
                if(pp[x].pais[z]<pp[y].pais[z])
                break;
                if((pp[x].pais[z]==pp[y].pais[z])&&pp[x].pais[z]!='\0')
                z++;
            }while(z<N&&pp[x].pais[z]!='\0');
        }
    for(x=0;x<N;x++)
        printf("%-31s%-31s%-10d\n",pp[x].pais,pp[x].nombre,pp[x].documento);
    return;
}
void f_ordenad(datos pr[N])
{
    int x,y;
    for(x=0;x<N;x++)
        for(y=x+1;y<N;y++)
            if(pr[x].documento>pr[y].documento)
                f_cambio(pr,x,y);
    for(x=0;x<N;x++)
        printf("%-10d%-31s%-31s\n",pr[x].documento,pr[x].nombre,pr[x].pais);
    return;
}
void f_cambio(datos pr[N],int x,int z)
{
    int y,aux;
    aux=pr[x].documento;
    pr[x].documento=pr[z].documento;
    pr[z].documento=aux;
    for(y=0;y<30;y++)
    {
        aux=pr[x].nombre[y];
        pr[x].nombre[y]=pr[z].nombre[y];
        pr[z].nombre[y]=aux;
        aux=pr[x].pais[y];
        pr[x].pais[y]=pr[z].pais[y];
        pr[z].pais[y]=aux;
    }
    return;
}
