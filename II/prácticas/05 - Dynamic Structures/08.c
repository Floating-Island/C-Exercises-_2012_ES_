#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
typedef struct s_nodo
{
    struct s_nodo *sig,*ant;
    int dato;
}* t_nodo;

t_nodo crearnodo(int);
void crear_listao(t_nodo*,int);
void imprime(t_nodo);
int main()
{
    char op;
    int dato;
    t_nodo lista=NULL;
    do
    {
        printf("\ndesea crear un nodo? s/n\n");
        op=getche();
        if(op=='s')
        {
            printf("\ningrese un numero prar el nodo: ");
            scanf("%d",&dato);
            crear_listao(&lista,dato);
        }
    }while(op!='n');
    imprime(lista);
    return 0;
}
t_nodo crearnodo(int dato)
{
    t_nodo aux=(t_nodo)malloc(sizeof(struct s_nodo));
    aux->sig=NULL;
    aux->ant=NULL;
    aux->dato=dato;
    return aux;
}
void crear_listao(t_nodo* lista,int dato)
{
    t_nodo aux,nuevo=crearnodo(dato);
    if(*lista==NULL||(*lista)->dato>dato)
    {
        nuevo->sig=*lista;
        if(*lista!=NULL)
            (*lista)->ant=nuevo;
            *lista=nuevo;
    }
    else
    {
        for(aux=*lista;aux->dato<dato&&aux->sig!=NULL;aux=aux->sig);
        if(dato<aux->dato)
        {
            nuevo->sig=aux;
            nuevo->ant=aux->ant;
            aux->ant->sig=nuevo;
            aux->ant=nuevo;
        }
        else
        {
            nuevo->ant=aux;
            nuevo->sig=aux->sig;
            aux->sig=nuevo;
        }
    }


}
void imprime(t_nodo ls)
{
    if(ls!=NULL)
    {
        printf(" %d ",ls->dato);
        imprime(ls->sig);
    }
}
