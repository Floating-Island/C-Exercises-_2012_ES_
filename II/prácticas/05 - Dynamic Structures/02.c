#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
struct s_nodo
{
    int valor;
    struct s_nodo* sig;
};
typedef struct s_nodo* t_nodo;
void carga_ordenada(t_nodo*,int);
void imprime(t_nodo*);
int main()
{
    t_nodo lista=NULL;
    int v;
    char cargar;
    do
    {
        printf("\ndesea crear un nodo? s/n\n ");
        cargar=getche();
        if(cargar=='s')
        {
            printf("\ningrese el valor: ");
            scanf("%d",&v);
            carga_ordenada(&lista,v);
        }

    }while(cargar!='n');
    imprime(&lista);
    return 0;
}
void carga_ordenada(t_nodo*p,int val)
{
    t_nodo aux=*p,ant,nuevo=NULL;
    if(*p==NULL)
    {
        *p=malloc(sizeof(struct s_nodo));
        (*p)->sig=NULL;
        (*p)->valor=val;
    }
    else
    {
        for(aux=*p;aux->valor<val&&aux->sig!=NULL;aux=aux->sig)
            ant=aux;
        nuevo=malloc(sizeof(struct s_nodo));
        nuevo->valor=val;
        if(val>aux->valor) //caso 1: nuevo>que el ultimo
        {
            aux->sig=nuevo;
            nuevo->sig=NULL;
        }
        else
        {
            if(aux!=*p) //caso2: nuevo entre el primero y el último
            {
                nuevo->sig=aux;
                ant->sig=nuevo;
            }
            else //caso 3: nuevo < que el primero
            {
                nuevo->sig=*p;
                *p=nuevo;
            }
        }
    }
}
void imprime(t_nodo* lista)
{
     t_nodo aux=*lista;
    do
    {

        printf("%d.",aux->valor);
        aux=aux->sig;
    }while(aux->sig!=NULL);
    printf("%d.",aux->valor);
}
