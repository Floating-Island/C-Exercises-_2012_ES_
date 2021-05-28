#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
struct s_nodo
{
    int valor;
    struct s_nodo* sig;
};
typedef struct s_nodo* t_pila;
void imprime_inversa(t_pila );
void crear_al_principio(t_pila*,int);
void eliminar_al_principio(t_pila*);
int main()
{
    t_pila lista=NULL;
    char crear,eliminar;
    int valor;
    do
    {
        printf("\ndesea crear un nodo? s/n\n");
        crear=getche();
        if(crear=='s')
        {
        printf("\ningrese el valor del nodo: ");
        scanf("%d",&valor);
        crear_al_principio(&lista,valor);
        }
        printf("\ndesea eliminar el primer nodo?s/n\n");
        eliminar=getche();
        if(eliminar=='s')
            eliminar_al_principio(&lista);
    }while(crear!='n');
    imprime_inversa(lista);
    return 0;
}
void imprime_inversa(t_pila p)
{
    if(p->sig!=NULL)
        imprime_inversa(p->sig);
        printf(" %d ",p->valor);
}
void crear_al_principio(t_pila *p,int val)
{
    t_pila strct=NULL;
    if(*p==NULL)
    {
        *p=malloc(sizeof(struct s_nodo));
        (*p)->valor=val;
        (*p)->sig=NULL;
    }
    else
    {
        strct=malloc(sizeof(struct s_nodo));
        strct->sig=*p;
        *p=strct;
        strct->valor=val;

    }
}
void eliminar_al_principio(t_pila* p)
{
    t_pila aux;
    aux=*p;
    *p=aux->sig;
    free(aux);
}
