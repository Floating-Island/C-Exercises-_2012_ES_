#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

typedef struct s_nodo
{
    int dato;
    struct s_nodo *izq,*der;
} *t_nodo;

void eliminanodo(t_nodo,int);
void carga (t_nodo*,int);
void imprimirIN(t_nodo);

int main()
{
    t_nodo lista=NULL;
    int dato;
    char op;
    do
    {
        printf("\ndesea crear un nodo? s/n\n");
        op=getche();
        if(op=='s')
        {
            printf("\ningrese el entero del nodo: ");
            scanf("%d",&dato);
            carga(&lista,dato);
        }
    }while(op!='n');
    imprimirIN(lista);
    printf("\ndesea eliminar un nodo?s/n\n");
    op=getche();
    if(op=='s')
    {
        printf("\ningrese el entero del nodo a eliminar: ");
        scanf("%d",&dato);
        eliminanodo(lista,dato);
        imprimirIN(lista);
    }
    return 0;
}
void eliminanodo(t_nodo ls,int d)
{
    if(ls!=NULL)
    {
        if(ls->dato==d)
        {
            free(ls);
            return;
        }
        if(ls->dato>d)
        {
            if(ls->izq->dato==d)
            {
            eliminanodo(ls->izq,d);
            ls->izq=NULL;
            }
            else
                eliminanodo(ls->izq,d);
        }
        if(ls->dato<d)
        {
            if(ls->der->dato==d)
            {
            eliminanodo(ls->der,d);
            ls->der=NULL;
            }
            else
                eliminanodo(ls->der,d);
        }
    }
}
void carga(t_nodo *ls,int dato)
{
    if(*ls==NULL)
    {
        *ls=malloc(sizeof(struct s_nodo));
        if(*ls==NULL)
            exit(0);
        (*ls)->dato=dato;
        (*ls)->izq=NULL;
        (*ls)->der=NULL;
        return;
    }
    else
    {
    if((*ls)->dato>=dato)
    {
        carga(&((*ls)->izq),dato);
    }
    if((*ls)->dato<dato)
    {
        carga(&((*ls)->der),dato);
    }
    }
}
void imprimirIN(t_nodo lista)
{
    if(lista!=NULL)
    {
        imprimirIN(lista->izq);
        printf(" %d ",lista->dato);
        imprimirIN(lista->der);
    }
}
