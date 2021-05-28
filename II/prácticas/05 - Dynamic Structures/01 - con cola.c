#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
struct s_nodo
{
    int valor;
    struct s_nodo* sig;
};
typedef struct s_nodo* t_cola;
void imprime_inversa(t_cola );
void crear_al_final(t_cola*,int);
void eliminar_al_final(t_cola*);
int main()
{
    t_cola lista=NULL;
    char crear,eliminar;
    int valor;
    do
    {
        printf("\ndesea crear un nodo? s/n\n");
        crear=getche();
        if(crear=='n')
            break;
        printf("\ningrese el valor del nodo: ");
        scanf("%d",&valor);
        crear_al_final(&lista,valor);
        printf("\n desea eliminar el nodo ingresado? s/n\n");
        eliminar=getche();
        if(eliminar=='s')
            eliminar_al_final(&lista);
    }while(crear!='n');
    imprime_inversa(lista);
    return 0;
}
void imprime_inversa(t_cola p)
{
    if(p->sig!=NULL)
        imprime_inversa(p->sig);
        printf(" %d ",p->valor);
}
void crear_al_final(t_cola *p,int val)
{
    t_cola nuevo=NULL;
    t_cola aux;
    if(*p==NULL)
    {
        *p=malloc(sizeof(struct s_nodo));
        (*p)->valor=val;
        (*p)->sig=NULL;
    }
    else
    {
        for(aux=*p;aux->sig!=NULL;aux=aux->sig);
        nuevo=malloc(sizeof(struct s_nodo));
        aux->sig=nuevo;
        nuevo->sig=NULL;
        nuevo->valor=val;

    }
}
void eliminar_al_final(t_cola* p)
{
    t_cola aux;
    if((*p)->sig!=NULL)
    {
    for(aux=*p;aux->sig->sig!=NULL;aux=aux->sig);
    free(aux->sig);
    aux->sig=NULL;
    }
    else
    {
    free(*p);
    *p=NULL;
    }
}
