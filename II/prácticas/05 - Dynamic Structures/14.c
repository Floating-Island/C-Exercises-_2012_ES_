#include <stdio.h>
#include <stdlib.h>
typedef struct s_nodo
{
    int dato;
    struct s_nodo *izq,*der;
}*t_nodo;

void cargar(t_nodo*,int);
void inorder(t_nodo);

int main()
{
    t_nodo raiz=NULL;
    int entero;
    printf("ingrese numeros enteros:\n");
    do
    {
        scanf("%d",&entero);
            cargar(&raiz,entero);
    }while(entero!=0);
    printf("\nlos numeros en inorder son : ");
    inorder(raiz);
    return(0);
}

void cargar(t_nodo *r,int val)
{
    if(*r!=NULL)
    {
        if(val<=(*r)->dato)
            cargar(&((*r)->izq),val);
        if (val>(*r)->dato)
            cargar(&((*r)->der),val);
    }
    else
    {
        *r=malloc(sizeof(struct s_nodo));
        if(*r==NULL)
            exit(0);
        (*r)->dato=val;
        (*r)->izq=NULL;
        (*r)->der=NULL;
    }
}

void inorder(t_nodo a)
{
    if(a!=NULL)
    {
        inorder(a->izq);
        printf("%d ",a->dato);
        inorder(a->der);
    }
}
