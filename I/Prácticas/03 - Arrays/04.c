#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a[1000]={0},b[1000]={0},i,j,cont=0,cont2=0,c[100000]={0},r=0,e;
    printf("ingrese elementos del primer arreglo, finalice con cero\n");
    i=0;
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
        if (a[i]!=0)
        {
        cont++;
        }
                i++;
    }while ((i<999)&&(a[i-1]!=0));
printf("ingrese elementos del segundo arreglo, finalice con cero\n");
    i=0;
    do
    {
        scanf("%d",&b[i]);
        if(b[i]!=0)
        {
            for(j=0;j<i;j++)
            {
                if(b[i]==b[j])
                {
                printf("el arreglo no puede tener numeros repetidos, ingrese el elemento otra vez");
                scanf("%d",&b[i]);
                j=-1;
                }
            }
        }
        if (b[i]!=0)
        {
        cont2++;
        }
        i++;
    }while ((i<999)&&(b[i-1]!=0));
printf("Elija una opcion:\n");
printf("1-Union\n2-Interseccion\n3-Diferencia\n4-Salir\n");
scanf("%d",&r);
switch (r)
{
    case 1:
    e=0;
    j=0;
     for (i=0;i<cont;i++)
        {

                if (a[i]==b[j])
                c[e]=a[i];
                else
                {
                    c[e]=a[i];
                    e++;
                    c[e]=b[j];
                }
                e++;
                j++;
            }
    break;
    case 2:
     while ((a[i]!=0)&&(b[j]!=0))
    {
        for (i=0;i<cont;i++)
        {
            for (j=0;j<cont2;j++)
            {
            if (a[i]==b[j])
                c[i]=a[i];
            }
        }
    }
    break;
    case 3:
    if (cont>cont2)
    for (i=0;i<cont;i++)
    {
        c[i]=a[i]-b[i];
    }
    else
        for (i=0;i<cont2;i++)
    {
        c[i]=a[i]-b[i];
    }
    break;
}
if (r!=4)
{
printf("el arreglo resultante es:\n");
for (i=0;c[i]!=0;i++)
printf("%d-",c[i]);
}
return 0;
}
