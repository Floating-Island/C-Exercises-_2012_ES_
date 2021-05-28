#include <stdio.h>
#include <stdlib.h>



int* cargaarreglo();
int es_creciente(int *);

int main()
{
    int* ar;
    ar=cargaarreglo();
    printf("el arreglo %s creciente\n",(es_creciente(ar))? "si es":"no es");
    return 0;
}

int* cargaarreglo()
{
    int* ai=NULL;
    int pos=0;
    ai=malloc(sizeof(int));
    if(ai!=NULL)
    {
        printf("\ningrese numeros:\n");
    do
    {
        ai=realloc(ai,sizeof(int)*(pos+1));
        if(ai==NULL)
        exit(0);
        scanf("%d",ai+pos);
    }while(*(ai+pos++)!=0);
    }
    return ai;
}

int es_creciente(int*p)
{
    int aux=1;
    if(*(p+1)!=0)
    {
        if(*p<*(p+1))
        return aux=es_creciente(p+1);
        else
            return aux=0;
    }
    else
        return 1;
}
