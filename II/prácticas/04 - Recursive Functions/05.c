#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int* cargaarreglo(int*);
void ordenar(int*,unsigned int);
void invertir(int*,unsigned int);

int main()
{
    int longitud,x;
    int* arr=NULL;
    arr=malloc(sizeof(int));
    arr=cargaarreglo(&longitud);
    printf("el arreglo es:\n");
    for(x=0;x<longitud;x++)
    printf("%d.",*(arr+x));
    ordenar(arr,longitud);
    printf("\nel arreglo ordenado queda:\n");
    for(x=0;x<longitud;x++)
    printf("%d.",*(arr+x));
    return 0;
}
void ordenar(int*p,unsigned int tam)
{
    if(tam>1)
    {
        invertir(p,tam--);
        ordenar(p,tam);
    }
}
void invertir(int*p,unsigned int tam)
{
    int aux;
    if(tam-->1)
    {
    if(*p>*(p+1))
    {
        aux=*p;
        *p=*(p+1);
        *(p+1)=aux;
        invertir(p+1,tam);
    }
    else
    invertir(p+1,tam);
    }
    return;
}
int* cargaarreglo(int* pos)
{
    int* ai=NULL;
    *pos=0;
    ai=malloc(sizeof(int));
    if(ai!=NULL)
    {
        printf("\ningrese numeros:\n");
    do
    {
        ai=realloc(ai,sizeof(int)*(*pos+1));
        if(ai==NULL)
        exit(0);
        scanf("%d",ai+*pos);
    }while(*(ai+(*pos)++)!=0);
    }
    return ai;
}
