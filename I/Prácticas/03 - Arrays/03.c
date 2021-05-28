#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a[6]={0},b[6]={0},d[6]={0},c,j,x1=100000,cont,num;
    do
    {
    printf("elija una opcion:\n 1-AND\n2-OR\n3-NOT\n4-salir\n");
    scanf("%d",&c);
    if(c!=4)
    {
    printf("escriba los elementos del primer arreglo booleano\n");
      do
    {
        cont=0;
    if (cont==0)
    scanf("%d",&num);
        while (num>111111)
    {
        printf("ingrese booleans de 6 cifras\n");
        cont++;
    }
    if (cont==0)
        {
            for(j=0;j<6;j++)
            {
                if(x1>num)
                a[j]=0;
                if(x1<=num)
                {
                    a[j]=num/x1;
                    num=num-x1;
                }
                x1=x1/10;
            }
          }
          if (cont==0)
          {
              for (j=0;j<6;j++)
              if ((a[j]!=0)&&(a[j]!=1))
                  {
                    cont++;
                  }
                  if (cont!=0)
                  {
                       printf("no es boolean\n");
                       for (j=0;j<6;j++)
                       a[j]=0;
                  }
          }
    }while(cont!=0);
    printf("escriba los elementos del segundo arreglo booleano\n");
    x1=100000;
do
    {
    if (cont==0)
    scanf("%d",&num);
    cont=0;
    while (num>111111)
    {
        printf("ingrese booleans de 6 cifras\n");
        scanf("%d",&num);
        cont++;
    }
    if (cont==0)
        {
            for(j=0;j<6;j++)
            {
                if(x1>num)
                b[j]=0;
                if(x1<=num)
                {
                    b[j]=num/x1;
                    num=num-x1;
                }
                x1=x1/10;
            }
          }

    }while(cont!=0);
        printf("el arreglo resultante es: ");
    }
    switch (c)
    {
        case 1:
        for(j=0;j<=6;j++)
        {
            if ((a[j]==1)&&(b[j]==1))
            d[j]=1;
        }
        break;
        case 2:
            for (j=0;j<6;j++)
            d[j]=1;
        break;
        case 3:
        j=0;
        for (j=0;j<6;j++)
        {
            if (a[j]!=b[j])
            d[j]=1;
        }
        break;
    }
    if (c!=4)
    {
    for (j=0;j<6;j++)
    {
    printf("%d",d[j]);
    }
    printf("\n");
    }
    }while (c!=4);
    return 0;
}
