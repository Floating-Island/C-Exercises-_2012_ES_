#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
typedef struct s_nodo
{
    struct s_nodo *ant,*sig;
    int dato;
} *t_nodo;
void carga(t_nodo*,int);
t_nodo busca(t_nodo,int);
void elimina(t_nodo*, t_nodo);
void imprime(t_nodo);
int main()
{
    t_nodo lista=NULL;
    int dato;
    char op;
    do
    {
        printf("\n desea crear un nodo? s/n \n");
        op=getche();
        if(op=='s')
        {
            printf("\n ingrese un numero para el nodo: ");
            scanf("%d",&dato);
            carga(&lista,dato);
        }
    }while(op!='n');
    if(lista!=NULL)
    {
        imprime(lista);
        do
        {
            printf("\ndesea eliminar un nodo? s/n\n");
            op=getche();
            if(op=='s')
            {
                printf("\n ingrese el numero del nodo: ");
                scanf("%d",&dato);
                elimina(&lista,busca(lista,dato));
            }
        }while(op!='n');
        printf("\n");
        imprime(lista);
    }
    return 0;
}
void carga(t_nodo *lista,int dato)
{
   if(*lista==NULL)
        {
            (*lista)=malloc(sizeof(struct s_nodo));
            (*lista)->sig=NULL;
            (*lista)->dato=dato;
            (*lista)->ant=NULL;
        }
    else
    {
        t_nodo aux;
        for(aux=*lista;aux->sig!=NULL;aux=aux->sig);
        aux->sig=malloc(sizeof(struct s_nodo));
        aux->sig->ant=aux;
        aux->sig->dato=dato;
        aux->sig->sig=NULL;
    }
}
t_nodo busca(t_nodo lista,int dato)
{
    if(lista->dato!=dato&&lista!=NULL)
        return busca(lista->sig,dato);
    else
        {
            if(lista->dato==dato)
                return lista;
            else
                return NULL;
        }
}
void elimina(t_nodo* lista,t_nodo eliminar)
{
    if(eliminar!=NULL)
    {
        if(*lista==eliminar)
        {
            if((*lista)->ant==NULL)
            {
                t_nodo aux;
                aux=eliminar;
                *lista=(*lista)->sig;
                (*lista)->ant=NULL;
                free(aux);
            }
            else
            {
            (*lista)->sig=eliminar->sig;
            eliminar->sig->ant=*lista;
            }
        }
        else
            elimina(&((*lista)->sig),eliminar);
    }
    else
        printf("\n no existe esa direccion\n");
}
void imprime(t_nodo imp)
{
    if(imp!=NULL)
    {
        printf(" %d ",imp->dato);
        imprime(imp->sig);
    }
}
