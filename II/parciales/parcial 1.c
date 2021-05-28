#include <stdio.h>
#include <stdlib.h>

int VOF(int*);
void cargaarreglo(int*);
int main()
{
    int x,elim;int*arr=NULL;
    cargaarreglo(arr);
    for(x=0;*(arr+x)!=0;x++)
    printf("%d.",*(arr+x));
    printf(" \ningrese el dato a eliminar");
    scanf("%d",&elim);
    elim=VOF(arr);
    for(x=0;*(arr+x)!=0;x++)
    printf("%d.",*(arr+x));

    return 0;
}
 void cargaarreglo(int* ai)
{
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
    return ;
}
int VOF(int* arr)
{
    int aux=1;
    if(*arr%2==0&&arr!=0)
        return aux=VOF(arr+1);
    else if(*arr%2!=0)
    return 0;
    return 1;
}
