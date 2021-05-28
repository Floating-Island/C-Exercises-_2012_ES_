#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
struct s_nodo
{
    int valor;
    struct s_nodo* sig;
};
typedef struct s_nodo* t_nodo;
void invertir(t_nodo,t_nodo);
void carga(t_nodo*,int);
void imprime(t_nodo*);
int main()
{
    t_nodo lista=NULL;
    int valor;
    char op;
    do
    {
        printf("\ndesea crear un nodo? s/n\n");
        if((op=getche())=='s')
        {
            printf("\ningrese el valor del nodo: ");
            scanf("%d",&valor);
            carga(&lista,valor);
        }
    }while(op!='n');
    printf("\nla lista queda: ");
    imprime(&lista);
    printf("\ninvertida queda: ");
    invertir(lista,lista);
    imprime(&lista);
    return 0;
}
void invertir (t_nodo lista,t_nodo ant)
{
    t_nodo aux1,aux2,aux3;
    if(ant==lista)
    {
        for(aux1=ant;aux1->sig!=NULL;aux1=aux1->sig)
            aux3=aux1;
        aux1->sig=aux3;
        aux3->sig=NULL;
        aux2=lista->sig;
        lista->sig=NULL;
        invertir(aux2,lista);
        lista=aux1;
    }
    else
        {
                if(lista->sig!=NULL)
                invertir(lista->sig,ant);
                lista->sig=ant;
        }
}
void carga(t_nodo* ps,int val)
{
    t_nodo aux=NULL;
    if(*ps==NULL)
    {
        *ps=malloc(sizeof(struct s_nodo));
        if(*ps==NULL)
            exit(0);
        (*ps)->sig=NULL;
        (*ps)->valor=val;
    }
    else
    {
        aux=*ps;
        *ps=malloc(sizeof(struct s_nodo));
        if((*ps)==NULL)
            exit(0);
        (*ps)->sig=aux;
        (*ps)->valor=val;
    }
}
void imprime(t_nodo* lista)
{
    t_nodo aux;
    for(aux=*lista;aux!=NULL;aux=aux->sig)
        printf(" %d ",aux->valor);
}
