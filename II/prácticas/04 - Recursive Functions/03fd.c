#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int* cargaarreglo(int*);
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
    invertir(arr,longitud-1);

    printf("\nel arreglo queda:\n");
    for(x=0;x<longitud;x++)
    printf("%d.",*(arr+x));
    return 0;
}
void invertir(int *vec, unsigned int lon)
{
    int aux;
    if(lon==1)
    {
        aux=*vec;
        *vec=vec[lon];
        vec[lon]=aux;
    }
    else if(vec[lon]!=*vec)
    {
        invertir(vec+1,lon-2);
        aux=*vec;
        *vec=vec[lon];
        vec[lon]=aux;
    }
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
