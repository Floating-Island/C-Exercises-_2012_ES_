#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

typedef struct s_nodo
{
    struct s_nodo *ant,*sig;
    int dato;
} *t_nodo;
void carga(t_nodo*,int);
void elimina(t_nodo*,int);
void imprime(t_nodo);
int main()
{
    t_nodo lista=NULL;
    int dato;
    char op;
    do
    {
        printf("desea crear un nodo? s/n\n");
        op=getche();
        if(op=='s')
        {
            printf("ingresse un numero para el nodo: ");
            scanf("%d",&dato);
            carga(&lista,dato);
        }
    }while(op!='n');
    printf("\n");
    imprime(lista);
    do
    {
        printf("desea eliminar un nodo? s/n\n");
        op=getche();
        if(op=='s')
        {
            printf("ingresse numero correspondiente al nodo: ");
            scanf("%d",&dato);
            elimina(&lista,dato);
        }
    }while(op!='n');
    imprime(lista);

    return 0;
}
void carga(t_nodo* lista,int daton)
{
    if(*lista==NULL)
    {
        (*lista)=malloc(sizeof(struct s_nodo));
        (*lista)->ant=NULL;
        (*lista)->sig=NULL;
        (*lista)->dato=daton;
    }
    else
    {
        t_nodo aux=malloc(sizeof(struct s_nodo));
        aux->ant=NULL;
        aux->sig=*lista;
        aux->dato=daton;
        (*lista)->ant=aux;
        *lista=aux;
    }
}
void elimina(t_nodo* lista,int dato)
{
    t_nodo aux;
    if(*lista!=NULL&&(*lista)->dato!=dato)
        elimina(&(*lista)->sig,dato);
    else
    if((*lista)->dato==dato)
    {
        if((*lista)->ant==NULL)
        {
            aux=*lista;
            *lista=(*lista)->sig;
            (*lista)->ant=NULL;
            free(aux);
        }
        else
        {
        (*lista)->ant->sig=(*lista)->sig;
        (*lista)->sig->ant=(*lista)->ant;
        free(*lista);
        }

    }
}
void imprime(t_nodo lista)
{
    if(lista!=NULL)
    {
        printf(" %d ",lista->dato);
        imprime(lista->sig);
    }
}
