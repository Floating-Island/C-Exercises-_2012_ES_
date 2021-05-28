#include <stdio.h>
#include <stdlib.h>
void carga_arr(int*);
void transformador(int,int*);
int validar (int*);
void imprime(int*);
void opciones(int,int*,int*,int*);
int main ()
{
        int a[6]={0},b[6]={0},d[6]={0},c;
    do
    {
    printf("elija una opcion:\n 1-AND\n2-OR\n3-NOT\n4-salir\n");
    scanf("%d",&c);
    if(c!=4)
    {
        printf("escriba los elementos del primer arreglo booleano\n");
        carga_arr(a);
        printf("escriba los elementos del segundo arreglo booleano\n");
        carga_arr(b);
     printf("el arreglo resultante es: ");
     opciones (c,a,b,d);
     imprime(d);
}
}while(c!=4);
return 0;
}

void carga_arr(int p[6])
{
    int j,x1,cont,num;
    do
    {
        x1=100000;
        cont=0;
    scanf("%d",&num);
    if(num>111111)
    {
        printf("ingrese booleans de 6 cifras\n");
        cont++;
    }
    transformador(num,p);
    cont=validar(p);
        if (cont!=0)
        {
            printf("no es boolean\n");
            for (j=0;j<6;j++)
            p[j]=0;
        }
    }while(cont!=0);
    return;
}
void transformador(int num,int x[6])
{
    int j,x1=100000;
    for(j=0;j<6;j++)
    {
        if(x1>num)
        x[j]=0;
        if(x1<=num)
            {
                x[j]=num/x1;
                num=num-x1;
            }
        x1=x1/10;
    }
    return;
}
int validar(int y[6])
{
    int j,cont=0;
    for (j=0;j<6;j++)
        if ((y[j]!=0)&&(y[j]!=1))
            return 1;
            return cont;
}
void imprime (int d[6])
{
    int j;
for (j=0;j<6;j++)
    printf("%d",d[j]);
    printf("\n");
    return;
}
void opciones(int c,int x[6],int y[6],int z[6])
{
    int j;
    switch (c)
    {
        case 1:
        for(j=0;j<=6;j++)
            if ((x[j]==1)&&(y[j]==1))
            z[j]=1;
        break;
        case 2:
            for (j=0;j<6;j++)
            z[j]=1;
        break;
        case 3:
        for (j=0;j<6;j++)
            if (x[j]!=y[j])
            z[j]=1;
        break;
    }
    return;
}

