#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

typedef struct s_nodo
{
    struct s_nodo *ant,*sig;
    int dato;
} *t_nodo;

void carga(t_nodo*,int);
void reversa(t_nodo*);
void reversamain(t_nodo*);
void imprime(t_nodo);
int main()
{
    t_nodo lista=NULL;
    int dt;
    char op;
    do
    {
        printf("\ndesea crear otro nodo? s/n\n");
        op=getche();
        if(op=='s')
        {
            printf("\ningrese un numero para el nodo: ");
            scanf("%d",&dt);
            carga(&lista,dt);
        }
    }while(op!='n');
    printf("\n");
    imprime(lista);
    printf("\ninvertido:\n");
    reversamain(&lista);
    imprime(lista);
    return 0;
}
void imprime(t_nodo list)
{
    if(list!=NULL)
    {
        printf(" %d ",list->dato);
        imprime(list->sig);
    }
}
void carga(t_nodo* lista,int dat)
{
    if(*lista==NULL)
    {
        *lista=malloc(sizeof(struct s_nodo));
        (*lista)->sig=NULL;
        (*lista)->ant=NULL;
        (*lista)->dato=dat;
    }
    else
    {
        t_nodo aux;
        for(aux=*lista;aux->sig!=NULL;aux=aux->sig);
        aux->sig=malloc(sizeof(struct s_nodo));
        aux->sig->sig=NULL;
        aux->sig->ant=aux;
        aux->sig->dato=dat;
    }
}
void reversa(t_nodo* lista)
{
    if(*lista!=NULL)
    {
        t_nodo aux;
        reversa(&((*lista)->sig));
        aux=(*lista)->sig;
        (*lista)->sig=(*lista)->ant;
        (*lista)->ant=aux;
    }
}
void reversamain(t_nodo* listageneral)
{
    t_nodo aux;
    reversa(listageneral);
    for(aux=*listageneral;aux->ant!=NULL;aux=aux->ant);
    *listageneral=aux;
}
