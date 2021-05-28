#include <stdio.h>
#include <stdlib.h>
void carga_conjunto(int*);
void opcion(int*,int*,int*);
void imprimir(int*);
void unir(int*,int*,int*);
void interseccion(int*,int*,int*);
int main()
{
    int x[1000]={0},y[1000]={0},z[2001]={0};
    printf("ingrese elementos del primer arreglo, finalice con cero\n");
    carga_conjunto(x);
    printf("ingrese elementos del segundo arreglo, finalice con cero\n");
    carga_conjunto(y);
    opcion(x,y,z);
    imprimir(z);
    return 0;
}
void carga_conjunto(int a[1000])
{
    int i=0,j;
    do
    {
        scanf("%d",&a[i]);
        if(a[i]!=0)
        {
            for(j=0;j<i;j++)
            {
                if(a[i]==a[j])
                {
                printf("el arreglo no puede tener numeros repetidos, ingrese el elemento otra vez");
                scanf("%d",&a[i]);
                j=-1;
                }
            }
        }
        i++;
    }while (i<998&&a[i-1]!=0);
    a[i]=0;
    return;
}
void opcion(int a[1000],int b[1000],int c[2001])
{
    int r,i;
printf("Elija una opcion:\n");
printf("1-Union\n2-Interseccion\n3-Diferencia\n4-Salir\n");
scanf("%d",&r);
switch (r)
{
    case 1:
    unir(a,b,c);
    break;
    case 2:
    interseccion(a,b,c);
    break;
    case 3:
    for (i=0;b[i]!=0;i++)
        c[i]=a[i]-b[i];
    break;
}
return;
}
void imprimir(int c[2001])
{
    int i;
    printf("el arreglo resultante es:\n");
for (i=0;c[i]!=0;i++)
printf("%d-",c[i]);
}
void interseccion(int a[1000],int b[1000],int c[2001])
{
    int i,j;
         for (i=0;a[i]!=0;i++)
            for(j=0;b[j]!=0;j++)
                if(a[i]==b[j])
                c[i]=a[i];
                c[i]=0;
                return;
}
void unir(int a[1000],int b[1000],int c[2001])
{
    int i,j;
         for (i=0;a[i]!=0;i++)
            c[i]=a[i];
            for(j=0;b[j]!=0;j++)
            {
                c[i]=b[j];
                i++;
            }
            c[i]=0;
            return;
}
