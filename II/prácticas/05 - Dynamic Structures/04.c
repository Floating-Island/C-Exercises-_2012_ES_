#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
struct s_nodo
{
    int valor;
    struct s_nodo* sig;
};
typedef struct s_nodo* t_nodo;
void eliminar_nodo(t_nodo*,t_nodo);
void carga_lista(t_nodo*,int);
void imprime(t_nodo*);

int main()
{
    char preg;
    int valcarga=0;
    t_nodo lista=NULL,elim=malloc(sizeof(t_nodo));
    do
    {
        printf("\ndesea crear un nodo? s/n\n");
        preg=getche();
        if(preg=='s')
        {
            printf("\n ingrese el vaor:");
            scanf("%d",&valcarga);
        carga_lista(&lista,valcarga);
        }

    }while(preg!='n');
    imprime(&lista);
    printf("desea eliminar un nodo? s/n\n");
    if((preg=getche())=='s')
    {
        printf("\ningrese la posicion del nodo a eliminar: ");
        scanf("%p",&elim);
        eliminar_nodo(&lista,elim);
        imprime(&lista);
    }

    return 0;
}
void eliminar_nodo(t_nodo* ptr,t_nodo val)
{
        t_nodo aux=*ptr,ant;
        if(aux!=val)
        for(aux=*ptr;aux->sig!=val&&aux->sig->sig!=NULL;aux=aux->sig);
        if(aux->sig==val)
        {
            ant=aux->sig;
            aux->sig=aux->sig->sig;
            free(ant);
        }
        if(aux==val)
        {
            ant=aux->sig;
            *ptr=ant;
            free(aux);
        }
        if(aux->sig!=val&&aux!=val)
            printf("\n no existe ese nodo...\n");
        return;
}
void carga_lista(t_nodo* lista,int val)
{
    t_nodo aux;
    if(*lista==NULL)
    {
        *lista=malloc(sizeof(t_nodo));
        if(*lista==NULL)
        exit(0);
        (*lista)->sig=NULL;
        (*lista)->valor=val;
        printf("pos: %p\n",*lista);
    }
    else
    {
        for(aux=*lista;aux->sig!=NULL;aux=aux->sig);
        aux->sig=malloc(sizeof(t_nodo));
        aux->sig->sig=NULL;
        aux->sig->valor=val;
        printf("pos: %p\n",aux->sig);
    }
}
void imprime(t_nodo*lista)
{
    t_nodo aux;
    printf("\n");
    if(*lista!=NULL)
    for(aux=*lista;aux!=NULL;aux=aux->sig)
        printf(" %d ",aux->valor);
    else
        printf("\n la lista esta vacia");
    printf("\n");
}
