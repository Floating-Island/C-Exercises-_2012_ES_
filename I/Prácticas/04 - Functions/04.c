#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int valor (int n)
{
    int a;
    do
    {
        scanf("%d",&a);
        if (a>n)
        printf("error, debe ser menor que el maximo");
    }while(a>n);
    return a;
}
int aleatorio (int a,int b)
{
    int r;
    r=rand()%(b-a+1)+a;
    return r;
}


int main()
{
    srand(time(NULL));
 int p,s,t,l;
 printf("ingrese un maximo:");
 scanf("%d",&p);
 printf("\ningrese un minimo");
 s=valor(p);
 printf("ingrese el valor de numeros que se van a mostrar:");
 t=valor(p);
 printf("los valores son: ");
 while (t>0)
 {
     l=aleatorio(s,p);
     printf("%d,",l);
     t--;
 }
    return 0;
}

