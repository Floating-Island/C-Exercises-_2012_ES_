#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
struct s_nodo
{
    int valor;
    struct s_nodo* sig;
};
typedef struct s_nodo* t_nodo;
void eliminar_nodo(t_nodo*,int);
void carga_lista(t_nodo*,int);
void imprime(t_nodo*);
int main()
{
    char preg;
    int eliminar=0;
    t_nodo lista=NULL;
    do
    {
        printf("\ndesea crear un nodo? s/n\n");
        preg=getche();
        if(preg=='s')
        {
            printf("\n ingrese el vaor:");
            scanf("%d",&eliminar);
        carga_lista(&lista,eliminar);
        }

    }while(preg!='n');
    imprime(&lista);
    printf("desea eliminar un nodo? s/n\n");
    if((preg=getche())=='s')
    {
        printf("\ningrese el valor del nodo a eliminar: ");
        scanf("%d",&eliminar);
        eliminar_nodo(&lista,eliminar);
        imprime(&lista);
    }

    return 0;
}
void eliminar_nodo(t_nodo* ptr,int val)
{
        t_nodo *aux;
        for(aux=ptr;*aux!=NULL;aux=&(*aux)->sig)
            if((*aux)->valor==val)
        {
            t_nodo reemplazo=NULL;
            reemplazo=*aux;
            *aux=(*aux)->sig;
            free(reemplazo);
            break;
        }
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
    }
    else
    {
        for(aux=*lista;aux->sig!=NULL;aux=aux->sig);
        aux->sig=malloc(sizeof(t_nodo));
        aux->sig->sig=NULL;
        aux->sig->valor=val;
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
